#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

struct Node{
	string hotel;
	int counter;
	Node* left;
	Node* right;

	~Node(){
		delete left;
		delete right;
	}
	Node(){
		this->left=null;
		this->right=null;
	}

	Node(string name, int num){
		this->hotel = name;
		this->counter = num;
	}

	Node(string name,int num, Node* left, Node* right ){
		this->hotel = name;
		this->counter=num;
		this->left=left;
		this->right=right;
	}

};


class BST{
	private:
		Node *root;
		void destory(Node* root){
			if(root){
				destory(root->left);
				destory(root->right);
				delete root;
			}
		
		}
	public:
		~BST(){
			desoty(root);
		
		}

		BST(){
			root = null;
		
		}
	








}
