//File that reads input and compares the running times of BST and Hash Tables
//Benson Chu
#include "BST.h"
#include "Hash.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <experimental/filesystem>
using namespace std;
namespace fs = std::experimental::filesystem;
int main(){
    vector<string> stopwords = {"i", "me", "my", "myself", "we", "our", "ours", "ourselves", "you", "your", "yours", "yourself", "yourselves", "he", "him", "his", "himself", "she", "her", "hers", "herself", "it", "its", "itself", "they", "them", "their", "theirs", "themselves", "what", "which", "who", "whom", "this", "that", "these", "those", "am", "is", "are", "was", "were", "be", "been", "being", "have", "has", "had", "having", "do", "does", "did", "doing", "a", "an", "the", "and", "but", "if", "or", "because", "as", "until", "while", "of", "at", "by", "for", "with", "about", "against", "between", "into", "through", "during", "before", "after", "above", "below", "to", "from", "up", "down", "in", "out", "on", "off", "over", "under", "again", "further", "then", "once", "here", "there", "when", "where", "why", "how", "all", "any", "both", "each", "few", "more", "most", "other", "some", "such", "no", "nor", "not", "only", "own", "same", "so", "than", "too", "very", "s", "t", "can", "will", "just", "don", "should", "now"};
    vector <string> store;
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
                    unsigned int strCount = 0;
                    if(word.length() > 1){
                    	for(unsigned int i = 0; i < word.length(); i++){
                        	if(isalpha(word.at(i)) || (ispunct(word.at(i)) &&
                            	(word.at(i) == '_' ||
                            	word.at(i) == ',' ||
                            	word.at(i) == '.' ||
                            	word.at(i) == '-'))){
                                	strCount++;
                        	}
                    	}
                    }
                    if(strCount == word.length()){
                        store.push_back(word);
                    }
                }
            }
            inFile.close();
        }
    }

    //Begin construction of BST and HTable
    BST testBST;
    unsigned int x = store.size() * 3 / 2;
    string input = "";
    Hash testHTable(x);
    //Inserting each word into both BST and HTable
    for(unsigned int i = 0; i < store.size(); i++){
        testBST.insert(store[i]);
        testHTable.insert(store[i]);
	
    }
    do{
        getline(cin, input);
        stringstream store(input);
        int command = 0;
        store >> command;
        switch(command){
            //perform search function
    case 1: 
    {       
	   // cout<<testHTable.getsize()<<"check size"<<endl;
	    string input = "";
            cin >> input;
            int start_b = clock();
            testBST.search(input);
            int stop_b = clock();
            int start_h = clock();
            testHTable.search(input);
            int stop_h = clock();
            if(testHTable.search(input) == testBST.search(input)){
            	cout << boolalpha << testHTable.search(input) << endl;
            	cout << "BST: " << (stop_b - start_b)/double(CLOCKS_PER_SEC) << "s" << endl;
            	cout << "Hash: " << (stop_h - start_h)/double(CLOCKS_PER_SEC) << "s" << endl;
            	cout << endl;
            }
    }
            break;
            //perform insert function
    case 2: 
    {       string input2;
            cin >> input2;
            int start2_b = clock();
            testBST.insert(input2);
            int stop2_b = clock();
            int start2_h = clock();
            testHTable.insert(input2);
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
            testBST.Delete(input3);
            int stop3_b = clock();
            int start3_h = clock();
            testHTable.hashdelete(input3);
            int stop3_h = clock();
            cout << "BST: " << (stop3_b - start3_b)/double(CLOCKS_PER_SEC) << "s" << endl;
            cout << "Hash: " << (stop3_h - start3_h)/double(CLOCKS_PER_SEC) << "s" << endl;
            cout << endl;
            break;
    }
            //perform sort function, reads in file to be written to
    case 4: 
    {       string input4 = "";
            cin >> input4;
            int start4_b = clock();
            testBST.sort(input4);
            int stop4_b = clock();
            int start4_h = clock();
            testHTable.sort(input4);
            int stop4_h = clock();

            cout << "BST: " << (stop4_b - start4_b)/double(CLOCKS_PER_SEC) << "s" << endl;
            cout << "Hash: " << (stop4_h - start4_h)/double(CLOCKS_PER_SEC) << "s" << endl;
            cout << endl;
            break;
    }
            //perform range search function, requires 2 string inputs
    case 5: 
    {       string rangeMin = "", rangeMax = "";
            cin >> rangeMin >> rangeMax;
            int start5_b = clock();
            testBST.range(rangeMin, rangeMax);
            int stop5_b = clock();
            cout << endl;
            int start5_h = clock();
            testHTable.range(rangeMin, rangeMax);
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
