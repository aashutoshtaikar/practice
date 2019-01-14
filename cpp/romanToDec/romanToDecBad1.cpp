#include<iostream>
#include<map>
using namespace std;

/* 
    roman['I']= 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M']= 1000;
 */
int findStr(char c){
    switch(c){
        case 'I': return 1;
        break;
        case 'V' : return 5;
        break;
        case 'X' : return 10;
        break;
        case 'L' : return 50;
        break;
        case 'C' : return 100;
        break;
        case 'D' : return 500;
        break;
        case 'M' : return 1000;
        break;
        default:
        return 0;
    }
}

int romanToDec(string str){
    /* problem in the loop as it checks the future element - i jumps by 2
     hinders the running as roman numerals are read by comparing the elements 
    while comparing the comparision needs to be consistent with the numerals count(even/odd)
    */
    
    int num{0};
    int sz = str.size() - 1;
   

    for(int i = 0; i<sz; ) {
        if(findStr(str[i]) > findStr(str[i+1])){
            num += findStr(str[i]) + findStr(str[i+1]);
        }
        else if (findStr(str[i]) < findStr(str[i+1])){
            num +=findStr(str[i+1]) - findStr(str[i]);
        }
        else if (findStr(str[i]) == findStr(str[i+1])){
            num +=findStr(str[i]) + findStr(str[i+1]);
        }

        i = i + 2;  
    }

    if(str.size()%2 != 0){
        num += findStr(str[sz]);
    }
    
    return num; 
}


int main(){
    cout << romanToDec("XIV") << endl;
   //cout << findStr('I');
}