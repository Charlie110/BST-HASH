#ifndef BST_H
#define BST_H

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Node{
 public:
  int count;
  string word;
  Node *left;
  Node *right;
  Node(const string& s){
    word=s;
    count=1;
  }
  ~Node(){
    delete left;
    delete right;
  }
};

class BST{
 public:
  //constructor and destructor
  BST();
  BST(const string& s);
  ~BST();
  //member functions
  bool search(const string& s);
  void insert(const string& s);
  void Delete(const string& s);
  void sort(ofstream& out);
  void range(const string& word1, const string& word2);

 private:
  Node *root;
  bool helpsearch(Node *n, const string& word);
  void helpinsert(Node *n, const string& word);
  Node* getmin(Node *n);
  void helpdelete(Node *n, const string& word);
  void helpsort(Node *n, ofstream& out);
  void helprange(Node *n, const string& start, const string& end);
};

#endif
