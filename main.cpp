#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>

using namespace std;

    int dict_number=0;

class Dictionary
{
    public:
    vector<wstring> list;
    string inputFile = "sozluk.txt";
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
    dict_number = list.size();
}

void Dictionary::chooseRandomWord()
{/*
    int random;
    srand(time(NULL));
    random = rand() % dict_number;
    for(int i =0;i<list.size();i++)
        if(list[i]==L"")
            i++;
        else if(random==i)
            sampleWord=list[i];
    wcout<<"random number: "<<random<<"sampleword: "<<sampleWord<<endl;*/
    for(int i = 0;i<list.size();i++)
        if(list[i]!=L"")
            sampleWord= list[i];
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
    wcout<<dictionary.list[5023]<<endl;
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
    int same;
    cin >> weight;

    dict_number=0;

    for(int i=0; i<dictionary.list.size();i++ )
    {
        same = compareWords(dictionary.sampleWord,dictionary.list[i]);
        if(weight != same)
            dictionary.list[i]=L"";     
        else
            dict_number+=1;
            wcout<<dictionary.list[i]<<endl;

    }   
    if(dict_number>2)
    {
        //printList();
        cout<<dictionary.list.size()<<endl;
        cout<<"Number:"<<dict_number<<endl;
        wcout<<dictionary.list[5023]<<endl;
        dictionary.chooseRandomWord();
        getWeight();
    }
    else
    {
        //printList();
        cout<<"BİTTİ"<<endl;
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
        if(dictionary.list[i]!=L"")
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
   // wcout<<weight<<endl;
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
