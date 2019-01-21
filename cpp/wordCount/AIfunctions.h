#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

class AIfunctions{
private:
    int inputSize;
    int wordCount;

    int countWords(string s);
    int countWordString(string s);
    vector<string> wordSeperator(string s);
public:
    // AIfunctions();
    // ~AIfunctions();
    char* evalInput(string input);


};

