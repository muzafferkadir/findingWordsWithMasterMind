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
    wcout<<dictionary.list[5060]<<endl;
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
        if(weight != compareWords(dictionary.sampleWord,dictionary.list[i]))
            dictionary.list.erase(dictionary.list.begin()+i);
    
        else
            wcout<<dictionary.list[i]<<endl;        
    
    }   
    cout<<dictionary.list.size()<<endl;
    if(dictionary.list.size()>2)
    {
        dictionary.chooseRandomWord();
        getWeight();

    }
        

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
    wstring w1 = word1;
    wstring w2 = word2;
    for(int i = 0; i<w1.length(); i++)
    {
        for(int j = 0; j<w2.length();j++)
        {
            if(w1[i]==w2[j])
            {
                weight+=1;
                w2[j]=0;
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
