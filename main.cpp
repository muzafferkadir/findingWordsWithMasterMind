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

int main()
{
    cout<<"asdasdasd"<<endl;
    string word;
    string word1 = "Kadir";
    string word2 = "Muzaffe";

    ofstream output;
    ifstream input;
    input.open("list.txt");
    input>> word;
    cout<<compareWords(word1,word2)<<endl;

    vector<string> wordList;
    while(!input.eof()){
        input>>word;
        wordList.push_back(word);
    }
    
    for(int i=0; i<wordList.size();i++ )
    {
        cout<<wordList[i]<<endl;        
    }
        cout<<wordList.size()<<endl;        
 
    

    return 0;
}
