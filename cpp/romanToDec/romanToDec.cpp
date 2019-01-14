#include<iostream>
#include<map>
using namespace std;

/* 
https://www.knowtheromans.co.uk/Categories/SubCatagories/RomanNumerals/RomanNumerals1-1000/
 */

int romanToDec(string str){
    map<char,int> roman;
    roman['I']= 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M']= 1000;
    
    int num{0};
    int i = str.size() - 1;


    for(int i = 0; i<=str.size()-1;i++){
        auto curr = roman.find(str[i]);
        auto prev = roman.find(str[i-1]);
        
        if(curr!=roman.end() || prev!=roman.end()){
            if (curr->second > prev->second){
                num += curr->second - prev->second - prev->second;
            }
            else if(prev->second > curr->second){
                num +=  curr->second;
            }
            else if(curr->second == prev->second){
                num += curr->second;
            }
        }
    }
 
    return num; 
}


int main(){
    cout << romanToDec("XXXIX") << endl;
}