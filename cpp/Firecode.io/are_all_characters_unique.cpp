/* Write a function that takes an input string - str and returns true if all the characters in the string are unique, false if there is even a single repeated character.

For an empty string, return true.

Examples:

are_all_characters_unique("abcde") -> true
are_all_characters_unique("aa") -> false
are_all_characters_unique("") -> true
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

bool are_all_characters_unique(string str)
{
    int arr[256]{0};
    
    for(int i = 0; i<str.size();i++){
        arr[int(str[i])]++;
        if(arr[int(str[i])]>1) return false;
    }
    return true;    
}

bool are_all_characters_unique1(string str)
{
    sort(str.begin(),str.end());
    auto it = unique(str.begin(),str.end());
    return it == str.end();    
}

bool are_all_characters_unique2(string str)
{
    map<char,int> uniqueChar;
    
    for(int i = 0; i<str.length(); i++){
        uniqueChar[str[i]]++;
    }
    
    for(auto it = uniqueChar.begin(); it!=uniqueChar.end() ;it++ ) {
        if(it->second > 1){
            return false;
        }    
    }
    
    return true;
    
}

int main(){

    int arr[] = {1,2,3,4,1,2,4,3,5};

    return 0;
}