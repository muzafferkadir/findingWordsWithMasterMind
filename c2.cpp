//find 2 word's same letters numbers
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{ 
    int result=0;
    wstring a =L"makaş";
    wstring b =L"dakaaaş";

    for(int i=0;i<a.length();i++)
    {
        for(int j=0;j<b.length();j++)
        {
            if(float(a[i])==float(b[j]))
            {  
                result+=1;
                break;
            }
            
        }
    }
    cout<<result<<endl;
    
    

    return 0;
}
