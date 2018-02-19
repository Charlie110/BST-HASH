#ifndef HASH_H
#define HASH_H
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
struct Node{
	string word;
	int count;
	int status;

	Node(){
		word="";
		count=0;
		status=1;
	}
	Node(string name){
		status=1;
		word=name;
		count=1;
	}
	
};

class Hash{
	private:
		Node **hashtable; 
		int size;
	public:
		Hash(){
			size=10;
			hashtable= new Node*[size];
			for(int i=0; i<size;i++){
				hashtable[i]=NULL;
			}
		}
		~Hash(){
			for(int i=0; i<size;i++){
				delete hashtable[i];
			}
			delete[] hashtable;
		}
		Hash(int n);
		
		int getsize(){return size;};

		int hash_func(const string& word);
		bool search(const string& word);
		void insert(const string& word);
		void deleteHelp(Node* node);
		void hashdelete(const string& word);
		void range(const string& word1, const string& word2);
	
		void sort(const string& path);
};


#endif


