#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<string,string> PhoneBook;



int main() {
    int count;
    cin >> count;
    
    for(int i = 0 ; i<count ; i++){
        string temp,first,second;
        cin >> temp;
        size_t found = temp.find(" ");
        for(int i = 0; i<found; i++){
            first += i;
        }
        for(int i = found; i<temp.length(); i++){
            second += i;
        }

        PhoneBook[first] = second;
    }

    string temp1;
    cin >> temp1;

    if(PhoneBook.find(temp1)!=PhoneBook.end()) cout << PhoneBook[temp1];


    return 0;
}