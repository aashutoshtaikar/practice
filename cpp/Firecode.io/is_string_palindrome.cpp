/* A palindrome is a string or sequence of characters that reads the same backward as forward. For example, "MADAM" is a palindrome.
Write a function that takes in an input string: str and returns true if the input string is a palindrome, false otherwise.
An empty string is considered a palindrome. You also need to account for the space character - i.e. "race car" should return false as read backward it is "rac ecar".

Examples: 

is_string_palindrome("madam") -> true
is_string_palindrome("aabb") -> false
is_string_palindrome("") -> true
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

bool is_string_palindrome(string str)
{
    for(int i = 0; i<=str.size()/2 ; i++){
        return str[i] == str[str.size()-1-i];
    }
    return true;
}



int main(){

    int arr[] = {1,2,3,4,1,2,4,3,5};

    return 0;
}