// C++ program to find the array 
// element that appears only once 

#include <iostream> 
#include<map>
using namespace std; 

//using array for hashing
int single_number(int arr[], int sz)
{
    int arrCount[sz]{0};
    
    for(int i = 0; i<sz; i++){
        arrCount[arr[i]]++;
    }

    for (int i=0; i<sz; i++){
        if (arrCount[i]==1) return i;
    }
    return 0;
    
}

//using stl map for hashing
int single_number1(int arr[], int sz)
{
    map<int, int> uniqueNum;
    for(int i=0;i<sz;i++){
        uniqueNum[arr[i]] = uniqueNum.count(arr[i]);
    }

    for(auto it=uniqueNum.begin();it!=uniqueNum.end();it++){
        cout <<"printing map" << it->first << "," << it->second << endl;
    }


    for(auto it=uniqueNum.begin();it!=uniqueNum.end();it++){
        if(it->second==0){
            return it->first;
        }
    }

}

int single_number2(int arr[], int sz)
{
    map<int,int> numCount;

    for(int i=0; i<sz; i++){
        numCount[arr[i]] += 1;  //this - adds the key as arr[i] and value as {0}+1
        //numCount[arr[i]]++;   //OR this works as well
    }

    for(auto e:numCount){
        cout << e.first << "," << e.second << endl; 
    }

    for(map<int,int>::iterator it = numCount.begin(); it!=numCount.end(); it++){
        if(it->second == 1) return it->first; 
    }

    
    return 0;
}


/* 
XOR method source: https://www.geeksforgeeks.org/find-element-appears-array-every-element-appears-twice/
a) XOR of a number with itself is 0.
b) XOR of a number with 0 is number itself. 

res = 7 ^ 3 ^ 5 ^ 4 ^ 5 ^ 3 ^ 4

Since XOR is associative and commutative, above 
expression can be written as:
res = 7 ^ (3 ^ 3) ^ (4 ^ 4) ^ (5 ^ 5)  
    = 7 ^ 0 ^ 0 ^ 0
    = 7 ^ 0
    = 7
*/

int findSingle(int ar[], int ar_size) 
	{ 
		// Do XOR of all elements and return 
		int res = ar[0];
        //cout << endl; 
		for (int i = 1; i < ar_size; i++){
            // cout << res << " XOR " << ar[i] << "=";
            res = res ^ ar[i];
            // cout << res <<endl;
        } 
			
		return res; 
	} 
    
    // int findSingle(string ar) 
	// { 
	// 	// Do XOR of all elements and return 
	// 	int res = ar[0];
    //     cout << endl; 
	// 	for (int i = 1; i < ar.size(); i++){
    //         cout << res << " XOR " << int(ar[i]) << "=";
    //         res = res ^ int(ar[i]);
    //         cout << res <<endl;
    //     } 
			
	// 	return res; 
	// } 

int main() { 
	int ar[] = {2, 3, 5, 4, 5, 3, 4}; 
	int sz = sizeof(ar) / sizeof(ar[0]); 
	
    string str = "abcde";
    
    //by hashing - stl map
    //cout << single_number2(ar,sz) << endl;

    //by XOR
    cout << findSingle(ar, sz) << endl;
    //cout << findSingle(str);


	return 0; 
} 
