//File that reads input and compares the running times of BST and Hash Tables
//Benson Chu
#include "BST.h"
#include "Hash.h"
#include <string>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <experimental/filesystem>
using namespace std;
namespace fs = std::experimental::filesystem;
bool find(const string& word, vector<string> str){
	for(std::vector<string>::iterator it=str.begin(); it != str.end();it++){
		if(*it == word){
			return 1;
		}
	}
return 0;
}
void replace(string& str, string const& find, string const& replace)
{
    for(string::size_type i = 0; (i = str.find(find, i)) != string::npos;)
    {
        str.replace(i, find.length(), replace);
        i += replace.length();
    }
}

int main(){
    vector<string> stopwords = {"i", "me", "my", "myself", "we", "our", "ours", "ourselves", "you", "your", "yours", "yourself", "yourselves", "he", "him", "his", "himself", "she", "her", "hers", "herself", "it", "its", "itself", "they", "them", "their", "theirs", "themselves", "what", "which", "who", "whom", "this", "that", "these", "those", "am", "is", "are", "was", "were", "be", "been", "being", "have", "has", "had", "having", "do", "does", "did", "doing", "a", "an", "the", "and", "but", "if", "or", "because", "as", "until", "while", "of", "at", "by", "for", "with", "about", "against", "between", "into", "through", "during", "before", "after", "above", "below", "to", "from", "up", "down", "in", "out", "on", "off", "over", "under", "again", "further", "then", "once", "here", "there", "when", "where", "why", "how", "all", "any", "both", "each", "few", "more", "most", "other", "some", "such", "no", "nor", "not", "only", "own", "same", "so", "than", "too", "very", "s", "t", "can", "will", "just", "don", "should", "now"};
    vector <string> temp;
    string str;
    for(auto& p: fs::recursive_directory_iterator("hotels-small")){
        if(is_regular_file(status(p))){
            ifstream inFile(p.path());
            if(!inFile){
                cerr << "Unable to open file";
                exit(1);
            }
            while(getline(inFile, str)){
                istringstream stream(str);
                string word;
                while(stream >> word){
                    unsigned int a = 0;
                    if(word.length() > 1){
                    	for(unsigned int i = 0; i < word.length(); i++){
                        	if(isalpha(word.at(i)) || (ispunct(word.at(i)) &&
                            	(word.at(i) == '_' ||
                            	word.at(i) == ',' ||
                            	word.at(i) == '.' ||
                            	word.at(i) == '-'))){
                                	a++;
                        	}
                    	}
                    }
		transform(word.begin(), word.end(), word.begin(), ::tolower);
	        replace(word,".","");
                replace(word,",","");
                replace(word,"!","");
                replace(word,"(","");
                replace(word,")","");
                replace(word,"?","");
                replace(word,"&","");
                replace(word,";","");
                replace(word,"*","");
                replace(word,":","");
                replace(word,"-","");


	
                if(a == word.length() && !find(word, stopwords)){
			
			temp.push_back(word);

                    }
                }
            }
            inFile.close();
        }
    }

    
    BST BST_T;
    unsigned int x = temp.size() * 3 / 2;
    string input = "";
    Hash h(x);
    for(unsigned int i = 0; i < temp.size(); i++){
        BST_T.insert(temp[i]);
        h.insert(temp[i]);
	
    }
    //h.print();
    do{
        getline(cin, input);
        stringstream temp(input);
        int command = 0;
        temp >> command;
        switch(command){
    //search
    case 1: 
    {       
	    //h.print();
	    string input = "";
            cin >> input;
            int start_b = clock();
            BST_T.search(input);
            int stop_b = clock();
            int start_h = clock();
            h.search(input);
            int stop_h = clock();
            if(h.search(input) == BST_T.search(input)){
            	cout << boolalpha << h.search(input) << endl;
            	cout << "BST: " << (stop_b - start_b)/double(CLOCKS_PER_SEC) << "s" << endl;
            	cout << "Hash: " << (stop_h - start_h)/double(CLOCKS_PER_SEC) << "s" << endl;
            	cout << endl;
            }
    
            break;
    }
    //insert 
    case 2: 
    {       string input2;
            cin >> input2;
            int start2_b = clock();
            BST_T.insert(input2);
            int stop2_b = clock();
            int start2_h = clock();
            h.insert(input2);
            int stop2_h = clock();
            cout << "BST: " << (stop2_b - start2_b)/double(CLOCKS_PER_SEC) << "s" << endl;
            cout << "Hash: " << (stop2_h - start2_h)/double(CLOCKS_PER_SEC) << "s" << endl;
            cout << endl;
            break;
    }
    //perform delete function
    case 3: 
    {       string input3 = "";
            cin >> input3;
            int start3_b = clock();
            BST_T.Delete(input3);
            int stop3_b = clock();
            int start3_h = clock();
            h.hashdelete(input3);
            int stop3_h = clock();
            cout << "BST: " << (stop3_b - start3_b)/double(CLOCKS_PER_SEC) << "s" << endl;
            cout << "Hash: " << (stop3_h - start3_h)/double(CLOCKS_PER_SEC) << "s" << endl;
            cout << endl;
            break;
    }
    //sort need a file name
    case 4: 
    {       string input4 = "";
            cin >> input4;
            int start4_b = clock();
            BST_T.sort(input4);
            int stop4_b = clock();
            int start4_h = clock();
            h.sort(input4);
            int stop4_h = clock();

            cout << "BST: " << (stop4_b - start4_b)/double(CLOCKS_PER_SEC) << "s" << endl;
            cout << "Hash: " << (stop4_h - start4_h)/double(CLOCKS_PER_SEC) << "s" << endl;
            cout << endl;
            break;
    }
    //range search requires 2 string inputs
    case 5: 
    {       string small = "", large = "";
            cin >> small >> large;
            int start5_b = clock();
            BST_T.range(small, large);
            int stop5_b = clock();
            cout << endl;
            int start5_h = clock();
            h.range(small, large);
            int stop5_h = clock();

            cout << "BST: " << (stop5_b - start5_b)/double(CLOCKS_PER_SEC) << "s" << endl;
            cout << "Hash: " << (stop5_h - start5_h)/double(CLOCKS_PER_SEC) << "s" << endl;
            cout << endl;
            break;
    }
        }
    }
    while(true);
    
}
