//find 2 word's same letters numbers
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{ 
    int result=0;
    wstring a =L"makaaaşşi";
    wstring b =L"dakaaaaşıı";

/*
    wstring a (c.begin(),c.end());
    wstring b (d.begin(),d.end());
*/

    for(int i=0;i<a.length();i++)
    {
        for(int j=0;j<b.length();j++)
        {
            if(a[i]==b[j])
            {  
                result+=1;
                b[j]=0;
                break;
            }
            
        }
    }
    cout<<result<<endl;
    
    

    return 0;
}
