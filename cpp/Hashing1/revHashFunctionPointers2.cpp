

/* find a 9 letter string of characters that contains only letters from acdegilmnoprstuw such that the hash(the_string)
 is 910897038977002 if hash is defined by the following pseudo-code: Int64 hash (String s) { Int64 h = 7 String letters 
 = "acdegilmnoprstuw" for(Int32 i = 0; i < s.length; i++) { h = (h * 37 + letters.indexOf(s[i])) } return h } 
 For example, if we were trying to find the 7 letter string where hash(the_string) was 680131659347, 
 the answer would be "leepadg".

 680131659347 - leepadg
930846109532517 - ? */

//no recursion used
//revHash implementation using function pointer to getNextNum function 

#include<iostream>
#include<list>
//#include<string>
using namespace std;

uint64_t myHash (string s) {
    uint64_t h = 7;
    string letters = "acdegilmnoprstuw";

    for(uint32_t i = 0; i < s.size(); i++) {
        h = (h * 37 + letters.find(s[i])); 
    } 
    return h; 
} 

uint64_t revMyHash(uint64_t n){
    return n/37;
}

list<char> temp{0};
void pushElements(uint64_t numToStr){
    string letters = "acdegilmnoprstuw";
    temp.push_front(letters[numToStr]);
}



void combFunctRevHash (uint64_t n ,uint64_t (*pFunct1)(uint64_t n), void (*pFunct2)(uint64_t numToStr)  ){
    uint64_t num{n};

    while( pFunct1(num)>=7*37 ) {
        
        pFunct2(num % 37);
        num = pFunct1(num);
    }
    
    pFunct2(num % 37);
    
}


int main(){
    cout << myHash("leepadg") << endl;


    //revHash implementation using function pointer to getNextNum function
    combFunctRevHash( 680131659347, &revMyHash, &pushElements );

    for(auto& e: temp){
        cout << e;
    }
    cout << endl;
}


