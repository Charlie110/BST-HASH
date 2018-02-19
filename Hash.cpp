#include "Hash.h" 
using namespace std;
Hash::Hash(int n){
	size=n;
	hashtable= new HNode*[size];
	for(int i=0; i<size;i++){
		hashtable[i]=NULL;
	}
}

int Hash::hash_func(const string& word){
	unsigned long num=17;
	unsigned long sum=0;
	for(int j=0; j<word.length();j++){
		sum = (sum*num)+int(word[j]);
	}
	return sum  % getsize();
	
}
bool Hash::search(const string& word){
	int index=hash_func(word);
	HNode*entry = hashtable[index];
	while(entry!=NULL){
		if(entry->word == word && entry->status==1){
			return true;
		}
	}

	return false;
}

void Hash::insert(const string& word){
	int index= hash_func(word);
	HNode* entry = hashtable[index];
	while(entry!=NULL){
		if(entry->status==1 && entry->word == word){
			entry->count++;
			return;
		}
		else if(entry->status==-1){
			break;	
		}
		else{
			entry=hashtable[index+1];
		}
	}

	if(entry == NULL){
		entry = new HNode (word);
		
	}

}
void Hash::deleteHelp(HNode* node){
	node->count=node->count - 1;
	if(node->count == 0){
		node->status=-1;
	}
	
}
void Hash::hashdelete(const string& word){
	int index = hash_func(word);
	HNode* entry = hashtable[index];
	while(entry!=NULL){
		if(entry->word == word){
			if(entry->status == -1){
				return;}
			deleteHelp(entry);
		}
		entry = hashtable[index+1];
	
	}

}

void Hash::range(const string& word1, const string& word2){
	for(int i=0; i<size;i++){
		if(hashtable[i]!=NULL && hashtable[i]->word > word1 && hashtable[i]->word < word2){
			cout<<hashtable[i]->word<<endl;	
		}
	}


}


void Hash::sort(const string& path){
	vector<string> arr;
	for(int i =0 ; i<size; i++){
		if(hashtable[i]!=NULL && hashtable[i]->status!=-1){
			arr.push_back(hashtable[i]->word);
		}
	}
	ofstream file;
	file.open(path,fstream::app);
	std::sort(arr.begin(),arr.end());
	for(int i=0; i<arr.size();i++){
		file<<arr[i]<<endl;
	}
	file.close();

}



