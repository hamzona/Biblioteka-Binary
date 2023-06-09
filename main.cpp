#include <iostream>
#include "binary.h"
using namespace std;

int main(){

//konverzija heksadecimalnog broja
/*	int type1,type2;
    
	cin>>type1>>type2;
	string a;

	cin>>a;
	cout<<convert(type1,type2,a);*/
	
	
	
	int type1,type2;
	cin>>type1>>type2;
    long long int a;
	cin>>a;
	cout<<convert(type1,type2,a);
	
/*
	int type1:
	cin>>type1;
	long long int a,b;
	cin>>a>>b;
	cout<<binaryDevide(a,b,type1)<<endl;
*/	
	return 0;
}