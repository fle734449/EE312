/*  plagiarismCatcher.cpp
  EE 312 Fall 2018

//Roger Priebe
//EE 312 12/3/18
*
* Replace <NAME> with your name.
*
* On my honor, Frank Le, this programming project is my own work
* and I have not provided this code to any other student.
*
* Name: Frank Le
* email address: frank.le@utexas.edu
        * UTEID: fpl227
        * Section 5 digit ID: 16190
* Date: 12/3/18
*
*/
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <ctime>
#include <queue>
#include <math.h>
#include <cmath>

using namespace std;

const int SIZE = 50021;

struct HashEntry {
    int fileNum;
    HashEntry * next;
};


struct RESULT{
    string docA;
    string docB;
    int collisions;
};

/*function... might want it in some class?*/
//function puts all files ina directory into a vector
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

//function determines wheteher a character is alphanumeric
//input: char
//output: bool
bool strip(char c){
    return !isalnum(c);
}

//function strips chunk string of any characters that are not alphanumeric
//input:string
//output: string
string stripStrange(string word){
    word.erase(remove_if(word.begin(), word.end(), strip), word.end());
    return word;
}


//function gets multiplier for hashing function
//input: int, int, int
//output: int
int getMul(int num, int pwr, int table_size){
    if(pwr == 0){                                                      // Base case if power = 0
        return 1;
    }
    if(pwr == 1){                                                      // Base case if power = 1
        return num%table_size;
    }else if(pwr%2 == 0){                                              // If our power is even, recurse, if odd, recurse but multiply by power again because of int variable
        return((getMul(num, pwr/2, table_size) * getMul(num, pwr/2, table_size)) % table_size);
    }else{
        return((getMul(num, pwr/2, table_size) * getMul(num, pwr/2, table_size) * pwr) % table_size);
    }
}

//function to get hashing index
//input: string
//output:int
int hashNum(const string& key){
    int hash = 0;
    for(int i=0; i < key.size(); i++){
        if(key[i] != ' '){
            hash += key[i]*getMul(7, i, SIZE);
        }
    }
    return hash % SIZE;
}

//function stores n sequence chunk into hashindex of hash table
//input: int, int, HashEntry
//output: none
void storechunk(int hashid, int i, HashEntry *hashTable[]) {
    HashEntry *temp = new HashEntry;
    temp->fileNum = i;
    temp->next = hashTable[hashid];
    hashTable[hashid] = temp;
}


//Main program starts here
int main(int argc, char *argv[])
{
    string dir = argv[1];
    //ifstream myfile;
    string filePath, words, chunk;
    queue<string> q;
    int chunkSize = atoi(argv[2]);
    int threshold = atoi(argv[3]);
    vector<string> files = vector<string>();
    HashEntry* hashTable[SIZE];

    for(int i = 0; i < SIZE; i++){
        hashTable[i] = NULL;
    }

    vector<RESULT*> results;

    getdir(dir,files); //getdir(argv[1],files);

    int grid[files.size()][files.size()];
    for(int i = 0; i < files.size(); i++){
        for(int j = 0; j < files.size(); j++){
            grid[i][j] = 0;
        }
    }

    //Uses queue to get n sequence chunks
    for (unsigned int i = 2;i < files.size();i++) {
        filePath = dir + "/" + files[i]; //filepath = argv[1] + ....
        ifstream myfile(filePath.c_str());
        if(myfile.is_open()) {
            //goes thorugh  all words from each text file
            while (myfile >> words) {
                q.push(words);
                if(q.size() >= chunkSize) {
                    queue<string> temp;
                    temp = q;
                    while (!temp.empty()) {
                        chunk = chunk + temp.front();
                        temp.pop();
                    }
                    chunk = stripStrange(chunk);
                    transform(chunk.begin(), chunk.end(), chunk.begin(), ::tolower); //turns all letters in string to lowercase
                    //cout << chunk << " ";
                    int hashid = hashNum(chunk);
                    storechunk(hashid, i, hashTable);
                    chunk.erase();
                    q.pop();
                }
            }
            while(!q.empty()){
                q.pop();
            }
            //cout << endl << endl;
            //myfile.close();
        }
    }

    //looks for collisions inside the hash table and counts collisions between files in 2-D array
    for(unsigned long int i = 0; i < SIZE; i++){
        HashEntry *bucket = hashTable[i];

        while(bucket != NULL){
            int f1 = bucket->fileNum;
            hashTable[i] = hashTable[i]->next;
            delete bucket;
            bucket = hashTable[i];
            while(bucket != NULL){
                int f2 = bucket->fileNum;
                if(f1 != f2){
                    grid[f1][f2] = grid[f1][f2] + 1;
                }
                bucket = bucket->next;
            }
            bucket = hashTable[i];
        }


    }

    //Pushes files with collisions more than threshold onto vector
    for(int i = 0; i < files.size(); i++){
        for(int j = 0; j < files.size(); j++){
            int collisions = grid[i][j];
            if(collisions > threshold){
                RESULT *result = new RESULT;
                result->docA = files[i];
                result->docB = files[j];
                result->collisions = collisions;
                results.push_back(result);
            }
        }
    }

    //Sorts collisions in descending order with selection sort
    for(unsigned long int i = 0; i < results.size(); i++){
        for(unsigned long int j = i+1; j < results.size(); j++){
            if(results[j]->collisions > results[i]->collisions){
                RESULT *temp = results[j];
                results[j] = results[i];
                results[i] = temp;
            }
        }
    }

    //Print out results
    cout << "Collisions:" << endl;
    for(unsigned long int i = 0; i < results.size(); i++){
        if(results[i]->collisions > threshold){
            cout << results[i]->collisions << ": " << results[i]->docA << ", " << results[i]->docB << endl;
        }
    }
    

    //free up dynamically allocated vector
    for(int i=0; i<results.size(); i++){
        delete results[i];
    }
    return 0;
}
