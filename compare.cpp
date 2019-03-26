//find 2 word's same letters numbers
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string a ="kapı";
    string b ="abajurı"; 
    char *c;
    char *d;
    c=&a[0];
    d=&b[0];
    int result=0;

    unsigned int count[1024] = {0};

    while(*c){
        count[*c]++;
        cout<<int(*c)<<c<<endl;
        c++;
    }
    while(*d){
        if (count[*d]>0)
        {
            result++;
            count[*d]=0;
        }
        d++;
    }
    cout<<result<<endl;
    
    

    return 0;
}
