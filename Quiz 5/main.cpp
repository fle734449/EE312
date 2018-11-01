#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void quiz(){
    int N =10;
    vector<char> example(N);

    for(int i = 0; i < N; i++){
        cin >> example[i];
    }
    sort(example.begin(), example.end());
    for(int i = 0; i < N; i++){
        cout << example[i];
    }


};

int main() {
    quiz();
    return 0;
}

