#include<iostream>
#include<map>
using namespace std;

/* https://www.knowtheromans.co.uk/Categories/SubCatagories/RomanNumerals/RomanNumerals1-1000/
    roman['I']= 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M']= 1000;
 */
int findStr(char c){
    switch(c){
        case 'I': return 1;
        break;
        case 'V' : return 5;
        break;
        case 'X' : return 10;
        break;
        case 'L' : return 50;
        break;
        case 'C' : return 100;
        break;
        case 'D' : return 500;
        break;
        case 'M' : return 1000;
        break;
        default:
        return 0;
    }
}

int romanToDec(string str){
 /* problem fixed as it checks the past element - goes one by one*/
    int num{0};

    for(int i = 0; i<=str.size() - 1 ;i++) {
        int curr = findStr(str[i]);
        int prev = findStr(str[i-1]);

        if(curr > prev){
            num += curr - prev - prev;
        }
        else if (prev > curr){
            num += curr;
        }
        else if (curr == prev){
            num +=curr;
        }
    }
    
    return num; 
}



int main(){
    cout << romanToDec("LXXXVII") << endl;
}