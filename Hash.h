#ifndef HASH_H
#define HASH_H
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
struct HNode{
	string word;
	int count;
	int status;

	HNode(){
		word="";
		count=0;
		status=1;
	}
	HNode(string name){
		status=1;
		word=name;
		count=1;
	}
	
};

class Hash{
	private:
		HNode **hashtable; 
		int size;
	public:
		Hash(){
			size=10;
			hashtable= new HNode*[size];
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
		void deleteHelp(HNode* node);
		void hashdelete(const string& word);
		void range(const string& word1, const string& word2);
	
		void sort(const string& path);
};


#endif


