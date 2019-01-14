

/* find a 9 letter string of characters that contains only letters from acdegilmnoprstuw such that the hash(the_string)
 is 910897038977002 if hash is defined by the following pseudo-code: Int64 hash (String s) { Int64 h = 7 String letters 
 = "acdegilmnoprstuw" for(Int32 i = 0; i < s.length; i++) { h = (h * 37 + letters.indexOf(s[i])) } return h } 
 For example, if we were trying to find the 7 letter string where hash(the_string) was 680131659347, 
 the answer would be "leepadg".

 680131659347 - leepadg
930846109532517 - ? */

 //revHash implementation using function pointer to pushElements function

#include<iostream>
#include<list>
using namespace std;

uint64_t myHash (string s) { 
    uint64_t h = 7; 

    string letters = "acdegilmnoprstuw"; 

    for(uint32_t i = 0; i < s.size(); i++) {
        //cout << "position in letters=" << letters.find(s[i]) << " ; " << "string to num=" << (uint32_t)s[i] << endl;
        h = (h * 37 + letters.find(s[i])) ; 
        //cout << h << endl;
    } 
    
    return h; 
} 

list<char> outputStr{};

void pushElements(uint64_t numToStr){
    string letters = "acdegilmnoprstuw";
    outputStr.push_front(letters[numToStr]);    
}

uint64_t revMyHash (uint64_t n, void (*pPushElements)(uint64_t numToStr)){
    if(n >= 7*37){
        pPushElements(n%37);
       return revMyHash( (n/37) , pPushElements );  
    }    
}



int main(){
    cout << myHash("leepadg") << endl;

    //revHash implementation using function pointer
    revMyHash(680131659347,&pushElements);

    for(auto text:outputStr){
        cout << text ;
    }
    cout << endl;

}


