
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>

using namespace std;


string kelime;
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

}

class Menu
{
    public:
    Dictionary dictionary;

    Menu();
    void start();
    void getWeight();
    void getCartesian();
    void getTogether();
    void pcgetWeight(wstring tahmin);
    void pcgetKartezyen(wstring kelimem);
    void goBack();
    void printList();
    int compareWords(wstring word1, wstring word2);
    int comWords(wstring word1, wstring word2);
    void pcnormal();
    void pckartezyen();
    void kullanicidan_al();

};

void Menu::start()
{
    cout<<"Lütfen Oynamak istediðiniz Oyunu Seçiniz.."<<endl;
    cout<<"Ýnsan-bilgisayar Normali için '1' "<<endl;
    cout<<"Ýnsan-bilgisayar Kartezyen için '2' "<<endl;
    cout<<"Ýnsan-bilgisayar hem Kartezyen hem Normali için '3' "<<endl;
    cout<<"Bilgisayar-Ýnsan Normali Ýçin '4' "<<endl;
    cout<<"Bilgisayar-Ýnsan Kartezyen Ýçin '5' "<<endl;
    cout<<"Bilgisayar-Ýnsan Hem Kartezyen Hem Normali Ýçin '6' "<<endl;
    cout<<"Oyundan Çýkmak  için '0' Giriniz"<<endl;
    dictionary.addWordsFromInput();
    int a;
    cin>>a;
    switch (a){
        case 1:

            dictionary.chooseRandomWord();
            cout<<"insan-pc normal"<<endl;
            cout<<"Toplam Kelime Sayisi : "<<dictionary.list.size()<<endl;
            wcout<<dictionary.list[5]<<endl;
            getWeight();
            dictionary.list.clear();

            //start();
        case 2:
            cout<<"insan-pc kartezyen"<<endl;
            dictionary.chooseRandomWord();
            cout<<"Toplam Kelime Sayisi : "<<dictionary.list.size()<<endl;
            wcout<<dictionary.list[5]<<endl;
            getCartesian();
            dictionary.list.clear();
            //start();
        case 3:
            cout<<"insan-pc Normal ve Kartezyen"<<endl;
            dictionary.chooseRandomWord();
            cout<<"Toplam Kelime Sayisi : "<<dictionary.list.size()<<endl;
            wcout<<dictionary.list[5]<<endl;
            getTogether();
            dictionary.list.clear();
            //start();
        case 4 :
            cout<<"Bilgisayar-insan normal"<<endl;
            dictionary.chooseRandomWord();
            //cout<<"tahmin edilecek kelime : ";
            wcout<<dictionary.sampleWord<<endl;
            pcnormal();
            //dictionary.list.clear();
            //start();
        case 5 :
            cout<<"Bilgisayar -insan kartezyen"<<endl;
            dictionary.chooseRandomWord();
           // cout<<"tahmin edilecek kelime : "<<endl;
            wcout<<dictionary.sampleWord<<endl;
            pckartezyen();
            dictionary.list.clear();
            //start();

        case 0:
            cout<<"Oyun sonu"<<endl;
            return;
        default :
            cout<<"gecersiz giris"<<endl;
            //start() ;

    }
}

void Menu:: pcnormal()
{
    kullanicidan_al();
    wstring kelimem(kelime.length(),L' ');
    copy(kelime.begin(),kelime.end(),kelimem.begin());
    pcgetWeight(kelimem);

}

void Menu:: pckartezyen()
{
    kullanicidan_al();
    wstring kelimem(kelime.length(),L' ');
    copy(kelime.begin(),kelime.end(),kelimem.begin());
    pcgetKartezyen(kelimem);
}

void Menu::kullanicidan_al()
{
    cout<<"kelime gir: ";
    cin>>kelime;
    cout<<kelime;
}

void Menu::pcgetWeight(wstring tahmin)
{

    for(int i=0; i<dictionary.list.size();i++ )
    {
        if(tahmin==dictionary.sampleWord)
        {
            wcout<<"Kelimem bu: "<<tahmin<<endl;
            dictionary.list.clear();
            start();
        }


        if(compareWords(dictionary.sampleWord,tahmin)==compareWords(dictionary.sampleWord,dictionary.list[i]))
        {
            wcout<<dictionary.list[i]<<endl;
            cout<<"weight"<<compareWords(dictionary.sampleWord,tahmin)<<endl;

        }
        else
        {
            dictionary.list.erase(dictionary.list.begin()+i);
            i--;
        }

    }

    cout<<dictionary.list.size()<<endl;

    if(dictionary.list.size()>1)
    {
        pcnormal();
    }

}

void Menu::pcgetKartezyen(wstring tahmin)
{
    if(tahmin==dictionary.sampleWord)
        {
            wcout<<"Kelimem bu: "<<tahmin<<endl;
            start();
        }

    for(int i=0; i<dictionary.list.size();i++ )
    {
        if(comWords(dictionary.sampleWord,tahmin)==comWords(dictionary.sampleWord,dictionary.list[i]))
        {
            wcout<<dictionary.list[i]<<endl;
            cout<<"cartesian"<<comWords(dictionary.sampleWord,dictionary.list[i])<<endl;
        }
        else
        {
            dictionary.list.erase(dictionary.list.begin()+i);
            i--;
        }
    }
    cout<<dictionary.list.size()<<endl;
    if(dictionary.list.size()>1)
    {
        pckartezyen();
    }
}


Menu::Menu()
{

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
        {
            //wcout<<dictionary.list[i]<<endl;
            //cout<<"weight"<<compareWords(dictionary.sampleWord,dictionary.list[i])<<endl;

        }

        else
        {
            dictionary.list.erase(dictionary.list.begin()+i);
            i--;
        }

    }

    cout<<dictionary.list.size()<<endl;
    if(dictionary.list.size()>1)
    {
        dictionary.chooseRandomWord();
        getWeight();
    }



}

void Menu::getCartesian()
{
    cout<<"PLEASE ENTER SAME LETTER NUMBER"<<endl;
    wcout<<"WORD:"<<dictionary.sampleWord<< endl;
    int cartesiann;
    cin >> cartesiann;


    for(int i=0; i<dictionary.list.size();i++ )
    {
        if(cartesiann == comWords(dictionary.sampleWord,dictionary.list[i]))
        {
            wcout<<dictionary.list[i]<<endl;
            cout<<"cartesian"<<comWords(dictionary.sampleWord,dictionary.list[i])<<endl;
        }
        else
        {
            dictionary.list.erase(dictionary.list.begin()+i);
            i--;
        }
    }
    cout<<dictionary.list.size()<<endl;
    if(dictionary.list.size()>1)
    {
        dictionary.chooseRandomWord();
        getCartesian();

    }
}

void Menu::getTogether()
{
    cout<<"PLEASE ENTER SAME LETTER NUMBER"<<endl;
    wcout<<"WORD:"<<dictionary.sampleWord<< endl;
    int normal;
    cin>>normal;

    int cartesiann;
    cin >> cartesiann;

    for(int i=0; i<dictionary.list.size();i++ )
    {
        if(cartesiann == comWords(dictionary.sampleWord,dictionary.list[i])&&normal==compareWords(dictionary.sampleWord,dictionary.list[i]))
        {
            wcout<<dictionary.list[i]<<endl;
            cout<<"Normal"<<compareWords(dictionary.sampleWord,dictionary.list[i])<<endl;
            cout<<"cartesian"<<comWords(dictionary.sampleWord,dictionary.list[i])<<endl;
        }
        else
        {
            dictionary.list.erase(dictionary.list.begin()+i);
            i--;
        }
    }
    cout<<dictionary.list.size()<<endl;
    if(dictionary.list.size()>1)
    {
        dictionary.chooseRandomWord();
        getTogether();

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
{
    int weight=0;
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

int Menu::comWords(wstring word1, wstring word2)
{
    int sirali=0;
    wstring w1 = word1;
    wstring w2 = word2;
    for(int i = 0;i<w1.length(); i++)
    {
        for(int j = 0; j<w2.length();j++)
        {
            if(w1[i]==w2[j])
            {
                sirali=sirali+1;
            }
        }
    }

    return sirali;
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
