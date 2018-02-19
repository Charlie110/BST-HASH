#include "BST.h"
using namespace std;

BST::BST(){
  root=nullptr;
}

BST::BST(const string&s){
  Node *root = new Node(s);  
}

BST::~BST(){
  delete root;
}

bool BST::search(const string& s){
  if (root==nullptr){
    return false;
  }
  else{
    return helpsearch(root, s);
  }
}

bool BST::helpsearch(Node* n, const string& s){
  if (s == n->word){
    return true;
  }
  if (s < n->word){
    if (n->left != nullptr){
      return helpsearch(n->left, s);
    }
    else{
      return false;
    }
  }
  else{
    if (n->right != nullptr){
      return helpsearch(n->right, s);
    }
    else{
      return false;
    }

  }
}

void BST::insert(const string& s){
  if (root==nullptr){
    Node *root = new Node(s);
    return;
  }
  else{
    helpinsert(root, s);
  }
}

void BST::helpinsert(Node* n, const string& s){
  if (s == n->word){
    n->count ++;
    return;
  }
  if (s < n->word){
    if (n->left != nullptr){
      helpinsert(n->left, s);
    }
    else{
      n->left = new Node(s);
      return;
    }
  }
  else{
    if (n->right != nullptr){
      helpinsert(n->right, s);
    }
    else{
      n->right = new Node(s);
      return;
    }
  }
}

void BST::Delete(const string& s){
  helpdelete(root, s);
}

Node* BST::getmin(Node *n){
  Node* current = n;
  while (current->left != NULL){
        current = current->left;
  }
  return current;
}

void BST::helpdelete(Node *n,const string& s){
  if(s< n->word){
    if (n->left != NULL){
      helpdelete(n->left,s);
    }
    else{
      return;
    }
  }else if(s > n->word){
    if (n->left != NULL){
      helpdelete(n->left,s);
    }
    else{
      return;
    }
  }
  else{
    if (n->count >1){
      n->count--;
      return;
    }
    else{
      if (n->left == NULL){
            delete n;
            return;
      }
      else if (n->right == NULL){
            delete n;
            return;
      }
      else{
	Node* temp=getmin(n->right);
	n->word=temp->word;
	helpdelete(n->right, temp->word);
      }
    }
  }
  return;
}

void BST::sort(const string& path){
  ofstream out;
  out.open(path,fstream::app);
  helpsort(root,out);
  out<<endl;
  out.close();
}

void BST::helpsort(Node *n,ofstream& out){
  if (n) {
    helpsort(n->left,out);
    out << n->word << "\n";
    helpsort(n->right,out);
  }
}

void BST::range(const string& word1, const string& word2){
  helprange(root,word1,word2);
}

void BST::helprange(Node *n, const string& start, const string& end){
  if(n == nullptr){
    return;
  }
  if(start<n->word){
    helprange(n->left,start,end);
  }
  if (start<=n->word&&end>=n->word){
    cout << n->word << "\n";
  }
  if(start>n->word){
    helprange(n->right,start,end);
  }
}
