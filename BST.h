//Fuheng Zhao, Runyu Gao

#ifndef BST_H
#define BST_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class BST{
private:
struct Node{
    Node *left;
    Node *right;
    int counter;
    std::string word;
};
public:
//constructor and destructor
BST();
~BST();

//member functions
bool search(string &s);
void insert(string &s);
void Delete(string &str);
void sort(const string &path);
void range(string &str1, string &str2);



private:
Node* root;
void Clear(Node*& root);
bool helpsearch(Node*& root, string &s);
void helpinsert(Node*& root, string &s);
void removeHelper(Node*& root, string &value);
void getmin(Node* root, string &value);
void helpsort(Node* root, ofstream &myfile);
void helprange(Node* root, string &str1, string &str2);
};
#endif
