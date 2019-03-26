#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string a ="kapıya";
    string b ="şaaaaansııııy";
    string c; 
    string d; 
    int result=0;
    for(int i=0; i<a.length();i++)
    {
        for(int j=0; j<c.length();j++)
        {
            if(a[i] == c[j])
                i++;
        }
        c += a[i];   
    }
    for(int i=0; i<b.length();i++)
    {
        for(int j=0; j<d.length();j++)
        {
            if(b[i] == d[j])
                i++;
        }
        d += b[i];   
    }

    for(int i=0; i<c.length();i++)
    {
        for(int j=0; j<d.length();j++)
        {
            if(c[i]==b[j])
            {
                result+=1;
                if(c[i]<0 ||d[j]<0||c[i]>255 ||d[j]>255 )
                {
                    result-=1;
                    j++;
                }
            }
        }
    }
    cout<<c<<"-"<<d<<" => "<<result<<endl;
    

    return 0;
}
