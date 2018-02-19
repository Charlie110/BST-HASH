//Fuheng Zhao, Runyu Gao

#include "BST.h"
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

BST::BST(){
    root = NULL;
}

void BST::Clear(Node*& root){
    if(root != NULL){
        Clear(root->left);
        Clear(root->right);
        delete root;
    }
}
BST::~BST(){
    Clear(root);
}

bool BST::search(string &s){
  return helpsearch(root, s);
}

bool BST::helpsearch(Node*& root, string &s){
    if(root == NULL){
        return false;
    }
    else if(root->word == s){
        return true;
    }
    else if(s <= root->word){
        return helpsearch(root->left, s);
    }
    else{
        return helpsearch(root->right, s);
    }
}

void BST::insert(string &s){
  helpinsert(root, s);
}


void BST::helpinsert(Node*& root, string &s){
    if(root == NULL){
        root = new Node();
        root->left = NULL;
        root->right = NULL;
        root->word = s;
        root->counter = 1;
    }
    else if(s == root->word){
        root->counter++;
        return;
    }
    else if(s < root->word) {
        helpinsert(root->left, s);
    }
    else{
        helpinsert(root->right, s);
    }
}

void BST::Delete(string &str){
  removeHelper(root, str);
}

void BST::removeHelper(Node*& root, string &value){
    if(root == NULL){
        return;
    }
    else if(root->word > value){
        removeHelper(root->left, value);
    }
    else if(root->word < value){
        removeHelper(root->right, value);
    }
    else{
        if(root->counter > 1){
            root->counter--;
        }
        else{
	    string value;
	    Node* temp = root;
	    if(root->left == NULL){
	      root = root->right;
              delete temp;
	    }
	    else if(root->right == NULL){
	      root = root->left;
	      delete temp;
	    }
	    else{
	      getmin(root->right, value);
	      root->word = value;
              removeHelper(root->right, value);
	    }
        }
    }
}

void BST::getmin(Node* root, string &str){
    while(root->left != NULL){
        root = root->left;
    }
        str = root->word;
}

void BST::sort(const string& path){
    ofstream myfile;
    myfile.open(path, fstream::app);
    helpsort(root, myfile);
    myfile << endl;
    myfile.close();
}

void BST::helpsort(Node* root, ofstream &out){
    if(root != NULL){
    helpsort(root->left, out);
    out << root->word << endl;
    helpsort(root->right, out);
    }
}

void BST::helprange(Node* root, string &str1, string &str2){
    if(root == NULL){
        return;
    }
    if(str1 < root->word){
        helprange(root->left, str1, str2);
    }
    if(str1 < root->word && str2 > root->word){
        cout << root->word << endl;
    }
    if(str2 > root->word){
        helprange(root->right, str1, str2);
    }
}

void BST::range(string &str1, string &str2){
	helprange(root, str1, str2);
}


