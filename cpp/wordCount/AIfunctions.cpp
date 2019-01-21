#include"AIfunctions.h"

// AIfunctions::AIfunctions(){
//     cout<<"AI created"<<endl; 
// }

// AIfunctions::~AIfunctions(){
//     cout<<"AI destroyed"<<endl;
// }

//count words
int AIfunctions::countWords(string s){
    int state = 0; //OUT
    int wc = 0;

    //copy string to char
    char cstr[s.length()+1];
    strcpy(cstr,s.c_str());
    char *ch = cstr;

    while(*ch){
        if(*ch==' '||*ch=='\n'|| *ch=='\t'){
            state=0;
        }
        else if(state==0){
            state = 1;
            ++wc;
        }
        ++ch;
    }
    return wc;
}

int AIfunctions::countWordString(string s){
    int wc=0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i]==' '||s[i]=='\t'||s[i]=='\n'){
            wc++;
        }
    }
    return wc;
}

//seperate words and return to a vector
vector<string> AIfunctions::wordSeperator(string s){
    string tmpWord;              //tmpWord to fill one word
    vector<string> sepWords;    //sepWords 
    int state = 0;

    //copy string to char
    char cstr[s.length()+1];
    strcpy(cstr,s.c_str());
    char *ch = cstr;

    while(*ch){
        if(*ch==' '||*ch=='\n'||*ch=='\t'){
            sepWords.push_back(tmpWord);
            tmpWord.erase();
        }
        else {
            //state = 1;
            tmpWord += *ch;              
        }
        ++ch;   
    }
    sepWords.push_back(tmpWord);
    return sepWords;
}


//evaluate input
char* AIfunctions::evalInput(string input){

    //check if DefaultText matches aiInput
    string defaultText = "hi hey how are you doing";
    
    vector<string> aiInputSep = wordSeperator(input);
    vector<string> testSep = wordSeperator(defaultText); 

    int wordsMatched=0;
    //O(n2)
    for(int i=0;i<countWords(input);i++){
        for(int j=0;j<countWords(defaultText);j++){
            if(aiInputSep[i]==testSep[j]){
                wordsMatched++;
            }
        }
    }
    
    cout<<countWordString(defaultText)<<endl;
    
    //check for the match percentage if >50% execute task else print error
    double percent=(double)wordsMatched/countWords(defaultText);
    if( percent >= 0.5){
        cout<<"I am good. How are you doing?"<<endl;
    }

}