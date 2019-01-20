#include <iostream>
#include <unordered_map>

using namespace std;

#include<unordered_map>

bool iso(string input1,string input2){
    unordered_map<char,char> re_map;

    for(size_t i = 0; i<input1.length(); i++){
        // if(re_map.find(input1[i])->first == input1[i]) re_map[input1[i]] = input2[i];
        if(re_map.find(input1[i]) == re_map.end()) re_map[input1[i]] = input2[i];
        else if(re_map.find(input1[i])->second != input2[i]) return false;
    }
    return true;
}
// Add any helper functions(if needed) above.
bool is_isomorphic(string input1, string input2)
{
    if(input1.size() != input2.size()) return false;
    if(iso(input1, input2) && iso(input2, input1)) return true;
    return false;

}


int main()
{
   cout << is_isomorphic("abcd","xxbb");
}

/* modified a bit from Russell N.'s code , my original code failed on my own custom testcase : is_isomorphic("abcd","xxbb") however the runtime complexity here is still O(n^2) as we call the iso function twice */