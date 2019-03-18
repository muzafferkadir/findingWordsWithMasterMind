#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



int compareWords(string word1, string word2)
{
    int weight=0;
    for(int i = 0; i<word1.length(); i++)
    {
        for(int j = 0; j<word2.length();j++)
        {
            if(word1[i]==word2[j])
            weight+=1;
        }
    }
    return weight;
}

string searchInDictionary(string ){}

string takeFirstWord(string str) 
{ 
   string word = ""; 
   for (auto x : str) 
   { 
       if (x == ' ') 
       { 
           return word;
       } 
       else
       { 
           word = word + x; 
       } 
   }  
    return word;
} 

int main()
{
    string word;
    string line;
    string last;
    ofstream output;
    ifstream input;
    input.open("list.txt");

    vector<string> wordList;
    while(getline(input,line)){
        word = takeFirstWord(line);
        if(word != last)
        wordList.push_back(word);        
        last = wordList.back(); 
    }
    
    for(int i=0; i<wordList.size();i++ )
    {
        cout<<i<<wordList[i]<<endl;        
    }
        cout<<wordList.size()<<endl;
        cout<<wordList.back()<<endl;

    return 0;
}
