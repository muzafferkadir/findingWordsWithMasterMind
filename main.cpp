#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Dictionary
{
    public:
    vector<string> list;
    string inputFile = "list.txt";
    
    Dictionary();
    void addWordsFromInput();

};

void Dictionary::addWordsFromInput()
{
    ifstream input;
    input.open(inputFile);
    string word;
    
    while(!input.eof())
    {
        input >> word;    
        list.push_back(word);
    }
    cout<<list.size()<<endl;
}

Dictionary::Dictionary()
{
    addWordsFromInput();
}

class Menu  
{
    public: 
    Dictionary dictionary;
    
    Menu();
    void start();
};

void Menu::start()
{
    cout<<"\n------------\n";
    cout<<dictionary.list[1]<<endl;
}
Menu::Menu()
{
    cout<<"HOŞGELDİNİZ";
}


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

int main()
{
    Menu system;
    system.start();


    return 0;
}
