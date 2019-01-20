#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* GIven an array A or N integers, return the smallest positive integer that does not occur in A */


int smallestPositive(vector<int> inputArr){
    sort(inputArr.begin(),inputArr.end());
    int num{0};
    for(vector<int>::iterator it = inputArr.begin(); it!=inputArr.end(); it++){
        if ((*it != *(it+1)) && *it+1 != *(it+1)){
            num = *it + 1;
            break;
        }
    }
    return num;
}

//OR
/* sort; div by 2; if()?+1: */


int main(){
    vector<int> x{1,3,6,4,1,2};


    //cout << int(str[1]) << endl; 
    //cout << smallestPositive(x);


    return 0;
}