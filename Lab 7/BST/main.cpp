// Sample driver
// EE 312 Fall 2018
//
// The BST should work for any data type or object.
// Other user created objects must have the << operator overloaded for 
// output.
//

#include <iostream>
#include <fstream>
#include "BST312.h"

using namespace std;

template <typename T>
void print(vector<T> vec){
    for(int i = 0 ; i < vec.size() ; i++){
        cout << vec[i] << endl;;
    }
}

int main() {

    ifstream inFile;
    inFile.open("test.txt");

    BST_312<string> bst;

    string s;
    inFile >> s;
    while (inFile) {;
        cout << "inserting ... " << s << endl;
        bst.insertItem(s);
        inFile >> s;
    }

    cout << "postorder traversal is " << endl;
    print(bst.postOrderTraversal());
    cout << endl;

    cout << "preorder traversal is " << endl;
    print(bst.preOrderTraversal());
    cout << endl;

    cout << "inorder traversal is " << endl;
    print(bst.inOrderTraversal());
    cout << endl;

    s ="as";
    if(bst.isItemInTree(s)){
        cout << "Item " << s << " is in tree." << endl << endl;
    } else {
        cout << "Item " << s << " is not in tree." << endl << endl;
    }

    cout << "inorder traversal is " << endl;
    print(bst.inOrderTraversal());
    cout << endl;

    cout << "Remove items " << endl;
    cout << "number of nodes in tree before delete is " << bst.countNodes() << endl;
    s = "tree";
    bst.deleteItem(s);
    print(bst.postOrderTraversal());
    cout << endl;
    cout << "number of nodes in tree after delete is " << bst.countNodes() << endl;
    cout << endl;
    bst.makeEmpty();
    print(bst.postOrderTraversal());
    cout << "number of nodes in tree after delete is " << bst.countNodes() << endl;
    cout << endl;

    s ="words";
    if(bst.isItemInTree(s)){
        cout << "Item " << s << " is in tree." << endl << endl;
    } else {
        cout << "Item " << s << " is not in tree." << endl << endl;
    }

    bst.insertItem("words");
    if(bst.isItemInTree(s)){
        cout << "Item " << s << " is in tree." << endl << endl;
    } else {
        cout << "Item " << s << " is not in tree." << endl << endl;
    }

    BST_312<char> bst2;
    bst2.insertItem('F');
    bst2.insertItem('B');
    bst2.insertItem('G');
    bst2.insertItem('A');
    bst2.insertItem('D');
    bst2.insertItem('I');
    bst2.insertItem('C');
    bst2.insertItem('E');
    bst2.insertItem('H');

    cout << "number of nodes in tree before delete is " << bst2.countNodes() << endl;

    cout << "postorder traversal is " << endl;
    print(bst2.postOrderTraversal());
    cout << endl;

    cout << "preorder traversal is " << endl;
    print(bst2.preOrderTraversal());
    cout << endl;

    cout << "inorder traversal is " << endl;
    print(bst2.inOrderTraversal());
    cout << endl;

    bst2.insertItem('B');
    cout << "inorder traversal is " << endl;
    print(bst2.inOrderTraversal());
    cout << endl;


    bst2.deleteItem('D');
    cout << "postorder traversal is " << endl;
    print(bst2.postOrderTraversal());
    cout << endl;
    cout << "preorder traversal is " << endl;
    print(bst2.preOrderTraversal());
    cout << endl;
    cout << "inorder traversal is " << endl;
    print(bst2.inOrderTraversal());
    cout << endl;

    cout << "number of nodes in tree after delete is " << bst2.countNodes() << endl;

    BST_312<int> bst3;
    bst3.insertItem(69);
    bst3.insertItem(100);
    bst3.insertItem(5);
    bst3.insertItem(3);
    bst3.insertItem(90);
    bst3.insertItem(25);
    bst3.insertItem(50);
    bst3.insertItem(99);
    bst3.insertItem(14);
    bst3.insertItem(-1);
    bst3.insertItem(0);
    bst3.insertItem(-100);
    bst3.insertItem(1000);

    cout << "number of nodes in tree before delete is " << bst3.countNodes() << endl;

    cout << "postorder traversal is " << endl;
    print(bst3.postOrderTraversal());
    cout << endl;

    cout << "preorder traversal is " << endl;
    print(bst3.preOrderTraversal());
    cout << endl;

    cout << "inorder traversal is " << endl;
    print(bst3.inOrderTraversal());
    cout << endl;

    bst3.insertItem(2);
    cout << "inorder traversal is " << endl;
    print(bst3.inOrderTraversal());
    cout << endl;


    bst3.deleteItem(2);

    bst3.deleteItem(69);
    bst3.deleteItem(100);
    bst3.deleteItem(5);
    bst3.deleteItem(3);
    bst3.deleteItem(90);
    bst3.deleteItem(25);
    bst3.deleteItem(50);
    bst3.deleteItem(99);
    bst3.deleteItem(14);
    bst3.deleteItem(-1);
    bst3.deleteItem(0);
    bst3.deleteItem(-100);
    bst3.deleteItem(1000);
    cout << "postorder traversal is " << endl;
    print(bst3.postOrderTraversal());
    cout << endl;
    cout << "preorder traversal is " << endl;
    print(bst3.preOrderTraversal());
    cout << endl;
    cout << "inorder traversal is " << endl;
    print(bst3.inOrderTraversal());
    cout << endl;

    cout << "number of nodes in tree after delete is " << bst3.countNodes() << endl;

    bst3.makeEmpty();

    cout << "number of nodes in tree after delete is " << bst3.countNodes() << endl;


}

