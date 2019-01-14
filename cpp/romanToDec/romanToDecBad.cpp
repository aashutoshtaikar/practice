#include<iostream>
#include<map>
using namespace std;

/* 

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


    for(int i = 0; i<str.size()-1; ){
        auto it2 = roman.find(str[i]);
        auto it1 = roman.find(str[i+1]);
        
        if(it1!=roman.end() && it2!=roman.end()){
            if (it1->second > it2->second){
                num += it1->second + it2->second;
            }
            else if(it1->second < it2->second){
                num += it2->second - it1->second;
            }
            else if(it1->second == it2->second){
                num += it2->second + it1->second;
            }
        }
        i += 2;
       
    }
        if(str.size()%2!=0){
            auto it3 = roman.find(str[str.size()-1]);
            if(it3!=roman.end()) {
                num += it3->second;
            }
        } 
    return num; 
}


int main(){
    cout << romanToDec("CMXCI") << endl;
}