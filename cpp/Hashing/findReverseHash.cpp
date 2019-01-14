/* find a 9 letter string of characters that contains only letters from acdegilmnoprstuw such that the hash(the_string)
 is 910897038977002 if hash is defined by the following pseudo-code: Int64 hash (String s) { Int64 h = 7 String letters 
 = "acdegilmnoprstuw" for(Int32 i = 0; i < s.length; i++) { h = (h * 37 + letters.indexOf(s[i])) } return h } 
 For example, if we were trying to find the 7 letter string where hash(the_string) was 680131659347, 
 the answer would be "leepadg".

680131659347 - leepadg
930846109532517 - ? */

#include <iostream>
#include<string>
#include<list>
using namespace std;

const string letters = "acdegilmnoprstuw";
list<char> tmp;

int64_t myHash (string s) { 
    int64_t h = 7;
    
    for(int32_t i = 0; i < s.length(); i++) {
        cout << i << " : "<< s[i] << " : " << letters.find(s[i]);
         h = (h * 37 + letters.find(s[i]));
         cout << " h: " << h << endl; 
    } 
    return h; 
}


int64_t reverseHash (int64_t h) { 
    
    if(h>=7*37){
        tmp.push_front(letters[h%37]);
    
        return reverseHash(h/37);
    }
}


int main(){
    reverseHash(930846109532517);

    for(auto& e: tmp){
        cout << e;
    }
    cout << endl;
}
