#include<iostream>
#include<string>
#include<algorithm>
#include"BinaryTree.h"
using namespace std;
namespace MyEnum
{
	enum mtCodes{
		A = 59,
		B = 37,
		C = 38,
		D = 51,
		E = 61,
		F = 34,
		G = 52,
		H = 33,
		I = 57,
		J = 44,
		K = 55,
		L = 35,
		M = 60,
		N = 58,
		O = 56,
		P = 36,
		Q = 47,
		R = 50,
		S = 49,
		T = 62,
		U = 53,
		V = 41,
		X = 45,
		Y = 46,
		Z = 39
	};
	static const mtCodes All[]={A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,X,Y,Z};
}
static BTree x;
void fun(const MyEnum::mtCodes e)
{
		x.insert(e); 
}

int main(){
	//BTree x;

	for(const auto e:MyEnum::All){
		fun(e);
	}

	
	return 0;
}