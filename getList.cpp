#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main()
{   
    wstring temp;
    vector<wstring> list3;
    locale::global( locale( "" ) );
    wifstream infile("list.txt");
    while(infile>>temp){
       list3.push_back(temp);
    }
    wcout<<list3.size()<<endl;
    for(int i = 0; i<list3.size();i++)
    wcout<<list3[i]<<endl;    
    return 0;
}
