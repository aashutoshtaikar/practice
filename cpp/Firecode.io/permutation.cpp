/* Implement a method that checks if two strings are permutations of each other. 


permutation("CAT","ACT") --> true

permutation("hello","aloha") --> false
 */
#include <iostream> 
#include<map>
#include <unordered_map>
#include<algorithm>
using namespace std; 

bool permutation1(string input1, string input2)
{
    unordered_map<char, int> hm;
    for (auto x : input1)
        ++hm[x];
    for (auto x : input2)
        --hm[x];
    for (auto x : hm)
        if (x.second)
            return false;
    return true;
}

bool permutation2(string input1, string input2)
{
    sort(input1.begin(),input1.end());
    sort(input2.begin(),input2.end());
    return input1==input2;
    
}

//my solution 
bool perm(string input1, string input2)
{
    unordered_map<char,int> CharCount;
    bool state{true};
    
    for(int i=0 ; i<input1.length(); i++){
        CharCount[input1[i]] = 0;
    }
    
    for(int i=0 ; i<input2.length(); i++){
        if (CharCount.find(input2[i]) == CharCount.end()) {
            state = state & false;
        }
        else state = state & true;
    }
    
    return state;
    
}

// Add any helper functions(if needed) above.
bool permutation(string input1, string input2)
{
    return (perm(input1,input2) && perm(input2,input1));
    
}