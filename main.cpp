#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>

using namespace std;


class Dictionary
{
    public:
    vector<wstring> list;
    string inputFile = "list.txt";
    wstring sampleWord;

    Dictionary();
    void chooseRandomWord();
    void addWordsFromInput();

};

void Dictionary::addWordsFromInput()
{
    
    wifstream input;
    input.open(inputFile);
    wstring word;
    
    while(!input.eof())
    {
        input >> word;    
        list.push_back(word);
    }
    cout<<list.size()<<endl;
}

void Dictionary::chooseRandomWord()
{
    int random;
    srand(time(NULL));
    random = rand() % list.size();
    cout<< random<<endl;
    sampleWord = list[random];
}

Dictionary::Dictionary()
{
    addWordsFromInput();
    chooseRandomWord();
}

class Menu  
{
    public: 
    Dictionary dictionary;
    
    Menu();
    void start();
    void getWeight();
    void goBack();
    void printList();
    int compareWords(wstring word1, wstring word2);
};

void Menu::start()
{
    cout<<"------------"<<endl;
    wcout<<dictionary.list[1]<<endl;
    getWeight();
}
Menu::Menu()
{
    cout<<"WELCOME"<<endl;
}

void Menu::getWeight()
{
    
    cout<<"PLEASE ENTER SAME LETTER NUMBER"<<endl;
    wcout<<"WORD:"<<dictionary.sampleWord<< endl;
    int weight;
    cin >> weight;

    for(int i=0; i<dictionary.list.size();i++ )
    {
        if(weight == compareWords(dictionary.sampleWord,dictionary.list[i]))
            wcout<<dictionary.list[i]<<endl;        
        else
            dictionary.list.erase(dictionary.list.begin()+i);
    }   
    cout<<dictionary.list.size()<<endl;


}

void Menu::goBack()
{
    cout<<"GO BACK[Y]"<<endl;
    string end;
    while(true){
        cin>>end;
        if((end=="y") || (end=="Y"))
            return getWeight();
    }
}

void Menu::printList()
{
    for(int i=0; i<dictionary.list.size();i++ )
    {
        wcout<<dictionary.list[i]<<endl;        
    }
}

int Menu::compareWords(wstring word1, wstring word2)
{   int weight=0;
    for(int i = 0; i<word1.length(); i++)
    {
        for(int j = 0; j<word2.length();j++)
        {
            if(word1[i]==word2[j])
            {
                weight+=1;
                word2[j]=0;
                break;
            }
        }
    }
    return weight;
}

int main()
{
    wcout.sync_with_stdio(false);
    wcout.imbue(std::locale("en_US.utf8"));
    locale::global( locale( "" ) );
    Menu system;
    system.start();


    return 0;
}
