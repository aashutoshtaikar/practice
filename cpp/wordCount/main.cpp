#include<iostream>
#include<string>
#include<cstring>
#include"AIfunctions.h"
using namespace std;

int main(int argc, char const *argv[])
{
    while(1){
        AIfunctions aix;
        string str;
        getline(cin,str);
        aix.evalInput(str);   
    }
    return 0;
}
