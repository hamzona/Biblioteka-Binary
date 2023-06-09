#include<iostream>
#include<stack>
#include<string>
#include<cmath>
#include<stdexcept>
using namespace std;



/*PROVJERE ISPRAVNOSTI BROJEVA*/
/**/
void isBinar(long long int number) {
	while(number!=0) {
		if(number%10!=0&&number%10!=1) {
			throw range_error("Binarni broj nije ispravan     ");
		}
		number/=10;
	}

}

/***/
void isDecimal(long long int number) {
	while(number!=0) {
		int p=number%10;
		if(!(p>=0&&p<=9)) {
			throw range_error("Decimalni broj nije ispravan    ");
		}
		number/=10;
	}
}

/**/
void isOctal(long long int number) {
	while(number!=0) {
		if(!(number%10>=0&&number%10<=7)) {
			throw range_error("Oktalni broj nije ispravan    ");
		}
		number/=10;
	}
}

/**/
void isHexaDecimal(string number) {
	int l=number.length();
	for(int i=0; i<l; i++) {
		if(!((number[i]>='0'&&number[i]<='9')||(number[i]>='A'&&number[i]<='F'))) {
			throw range_error("Heksdecimalni broj nije ispravan      ");
		}
	}
}

/**/
void isType() {
	throw range_error("tip ne postoji");
}



/*DECIMALNI*/
/**/
void dec_hex(long long int number,stack<char> &numberType2) {

	while(number>0) {
		int ostatak;
		if(number>=16) {
			ostatak=number%16;
		} else {
			ostatak=number;
		}
		if(ostatak>=0&&ostatak<=9) {
			numberType2.push(char(ostatak+48));

		} else {
			switch(ostatak) {
				case 10:
					numberType2.push('A');
					break;
				case 11:
					numberType2.push('B');
					break;
				case 12:
					numberType2.push('C');

					break;
				case 13:
					numberType2.push('D');

					break;
				case 14:
					numberType2.push('E');

					break;
				case 15:
					numberType2.push('F');
					break;
			}
		}
		number=number/16;
	}
}

/**/
void dec_bin(long long int number,stack<char> &numberType2) {
	while(number>0) {
		if(number<2) {
			numberType2.push(char(number+48));
		} else {
			numberType2.push(char(number%2+48));
		}
		number=number/2;
	}
}
/**/
void dec_oct(long long int number,stack<char> &numberType2) {
	while(number>0) {
		if(number<8) {
			numberType2.push(char(number+48));
		} else {
			numberType2.push(char(number%8+48));
		}
		number=number/8;
	}
}
/**/
void decimal(int type2,long long int number,stack<char> &numberType2) {

	switch(type2) {
		case 16:
			dec_hex(number,numberType2);
			break;
		case 2:
			dec_bin(number,numberType2);
			break;
		case 8:
			dec_oct(number,numberType2);
			break;
		default:
			isType();
			break;
	}
}

/*BINARNI*/

/**/
void bin_dec(long long int number,stack<char> &numberType2) {

	stack <int> binarNumberConverted;
	int helpV=1;
	long long int copy=number;
	while(copy/10>0) {
		helpV=helpV+helpV;
		copy=copy/10;
	}
	copy=number;
	while(copy>0) {
		binarNumberConverted.push(helpV);
		helpV=helpV/2;
		copy=copy/10;
	}



	long long int sum=0;
	while(!binarNumberConverted.empty()) {
		if(number%10) {
			sum=sum+binarNumberConverted.top();
		}
		binarNumberConverted.pop();
		number=number/10;
	}
	while(sum>0) {
		numberType2.push((sum%10)+48);
		sum=sum/10;
	}
}
/**/
void bin_oct(long long int number,stack<char> &numberType2) {

	stack<int> binarNumber;
	while(number!=0) {
		for(int i=0; i<3; i++) {
			binarNumber.push(number%10);
			number=number/10;
		}
	}
	stack <int> copy;
	while(!binarNumber.empty()) {
		int conv[3]= {4,2,1};
		int sum=0;
		for(int i=0; i<3; i++) {
			if(binarNumber.top()) {
				sum+=conv[i];
			}
			binarNumber.pop();
		}
		copy.push(sum);
	}
	while(!copy.empty()) {
		numberType2.push(char(copy.top()+48));
		copy.pop();
	}
}
/**/
void bin_hex(long long int number,stack<char> &numberType2) {
	stack<int> binarNumber;
	while(number!=0) {
		for(int i=0; i<4; i++) {
			binarNumber.push(number%10);
			number=number/10;
		}
	}
	stack <int> copy;
	while(!binarNumber.empty()) {
		int conv[4]= {8,4,2,1};
		int sum=0;
		for(int i=0; i<4; i++) {
			if(binarNumber.top()) {
				sum+=conv[i];
			}
			binarNumber.pop();
		}
		copy.push(sum);
	}
	while(!copy.empty()) {
		if(copy.top()>=0&&copy.top()<=9) {
			numberType2.push(char(copy.top()+48));

		} else {
			switch(copy.top()) {
				case 10:
					numberType2.push('A');
					break;
				case 11:
					numberType2.push('B');
					break;
				case 12:
					numberType2.push('C');

					break;
				case 13:
					numberType2.push('D');

					break;
				case 14:
					numberType2.push('E');

					break;
				case 15:
					numberType2.push('F');
					break;
			}
		}
		copy.pop();
	}
}
/**/
void binar(int type2,long long int number,stack<char> &numberType2) {

	switch(type2) {
		case 16:
			bin_hex(number,numberType2);
			break;
		case 10:
			bin_dec(number,numberType2);
			break;
		case 8:
			bin_oct(number,numberType2);
			break;
		default:
			isType();
			break;
	}
}

/*OCTAL*/
/**/
void oct_bin(long long int number,stack<char> &numberType2) {
	while(number!=0) {
		switch(number%10) {
			case 0:
				numberType2.push(char(0+48));
				numberType2.push(char(0+48));
				numberType2.push(char(0+48));
				break;
			case 1:
				numberType2.push(char(1+48));
				numberType2.push(char(0+48));
				numberType2.push(char(0+48));
				break;
			case 2:
				numberType2.push(char(0+48));
				numberType2.push(char(1+48));
				numberType2.push(char(0+48));
				break;
			case 3:
				numberType2.push(char(1+48));
				numberType2.push(char(1+48));
				numberType2.push(char(0+48));
				break;
			case 4:
				numberType2.push(char(0+48));
				numberType2.push(char(0+48));
				numberType2.push(char(1+48));
				break;
			case 5:
				numberType2.push(char(1+48));
				numberType2.push(char(0+48));
				numberType2.push(char(1+48));
				break;
			case 6:
				numberType2.push(char(0+48));
				numberType2.push(char(1+48));
				numberType2.push(char(1+48));
				break;
			case 7:
				numberType2.push(char(1+48));
				numberType2.push(char(1+48));
				numberType2.push(char(1+48));
				break;
		}
		number/=10;
	}
}

/**/
void oct_hex(long long int number,stack<char> &numberType2) {
	oct_bin(number,numberType2);
	number=0;
	while(!numberType2.empty()) {
		number=number*10;
		number=number+int(numberType2.top()-48);
		numberType2.pop();
	}
	bin_hex(number,numberType2);
}
/**/
void oct_dec(long long int number,stack<char> &numberType2) {
	int sum=0;
	int i=0;
	while(number!=0) {

		sum=sum+((number%10)*(pow(8,i)));

		number/=10;
		i++;
	}
	while(sum!=0) {
		numberType2.push(char(sum%10)+48);
		sum/=10;
	}

}
/**/
void octal(int type2,long long int number,stack<char> &numberType2) {

	switch(type2) {
		case 16:
			oct_hex(number,numberType2);
			break;
		case 10:
			oct_dec(number,numberType2);
			break;
		case 2:
			oct_bin(number,numberType2);
			break;
		default:
			isType();
			break;
	}
}
/*HEXADECIMAL*/

/**/
void hex_dec(string number,stack<char> &numberType2) {
	stack<int>hexToNumber;
	for(int i=0; i<number.length(); i++) {
		int realNumber=int(number[i]-48);
		if(realNumber>=0&&realNumber<=9) {
			hexToNumber.push(realNumber);

		} else {
			switch(number[i]) {
				case 'A':
					hexToNumber.push(10);
					break;
				case 'B':
					hexToNumber.push(11);
					break;
				case 'C':
					hexToNumber.push(12);

					break;
				case 'D':
					hexToNumber.push(13);

					break;
				case 'E':
					hexToNumber.push(14);

					break;
				case 'F':
					hexToNumber.push(15);
					break;
			}
		}
	}

	int sum=0;
	int i=0;
	while(!hexToNumber.empty()) {

		sum=sum+((hexToNumber.top())*(pow(16,i)));

		hexToNumber.pop();
		i++;
	}
	while(sum!=0) {
		numberType2.push(char(sum%10)+48);
		sum/=10;
	}

}
/**/
void hex_bin(string number,stack<char> &numberType2) {

	hex_dec(number,numberType2);

	long long int intNumber=0;

	while(!numberType2.empty()) {
		intNumber=intNumber*10;
		intNumber=intNumber+int(numberType2.top()-48);
		numberType2.pop();
	}
	dec_bin(intNumber,numberType2);
}


/**/
void hex_oct(string number,stack<char> &numberType2) {
	hex_dec(number,numberType2);
	long long int intNumber=0;

	while(!numberType2.empty()) {
		intNumber=intNumber*10;
		intNumber=intNumber+int(numberType2.top()-48);
		cout<<int(numberType2.top()-48)<<endl;
		cout<<intNumber<<endl;
		numberType2.pop();
	}
	cout<<intNumber<<endl;
	dec_oct(intNumber,numberType2);
}
/*hexDeximal*/

/**/
string convert(int type1,int type2,string number) {
	if(type1!=16){
		throw range_error("Tip nije ispravan");
	}
	stack<char> numberType2;

		isHexaDecimal(number);
		switch(type2) {
			case 8:
				hex_oct(number,numberType2);
				break;
			case 10:
				hex_dec(number,numberType2);
				break;
			case 2:
				hex_bin(number,numberType2);
				break;
			default:
				isType();
				break;
		}

		string result;
		while(!numberType2.empty()) {
			result=result+numberType2.top();
			numberType2.pop();
		}
		return result;

}

/**/
string convert(int type1,int type2,long long int number) {
	stack<char> numberType2;

		switch(type1) {
			case 10:
				isDecimal(number);
				decimal(type2,number,numberType2);
				break;
			case 2:
				isBinar(number);
				binar(type2,number,numberType2);
				break;
			case 8:
				isOctal(number);
				octal(type2,number,numberType2);
				break;
			default:
				isType();
				break;
		}

	
	
					string result;
				while(!numberType2.empty()) {
					result=result+numberType2.top();
					numberType2.pop();
				}
				return result;

}



/*CONVERT STRING TO INTEGER*/
long long int stringToIntegerDec(string sDec) {
	int l=sDec.length();
	long long int p=0;
	for(int i=0; i<l; i++) {
		p=p*10;
		p=p+int(sDec[i]-48);
	}
	return p;
}

/**/
string binarySum(string number1,string number2,int type) {
	if(type!=16) {
		throw range_error("Neispravan unos");
	}
	string dec1=convert(type,10,number1);
	cout<<dec1<<endl;
	long long int decInt1=stringToIntegerDec(dec1);
	cout<<decInt1<<endl;
	string dec2=convert(type,10,number2);
	cout<<dec2<<endl;
	long long int decInt2=stringToIntegerDec(dec2);
	cout<<decInt2<<endl;
	
	long long int result=decInt1+decInt2;
	cout<<result<<endl;
	string r=convert(10,type,result);
	return r;
}




string binarySum(long long int number1,long long int number2,int type) {
	if(type==16||type==10) {
		throw range_error("Neispravan unos");
	}
	string dec1=convert(type,10,number1);
	long long int decInt1=stringToIntegerDec(dec1);
	string dec2=convert(type,10,number2);
	long long int decInt2=stringToIntegerDec(dec2);
	
	long long int result=decInt1+decInt2;
	string r=convert(10,type,result);
	return r;
}



/*ODUZIMANJE*/


string binarySubtracting (string number1,string number2,int type) {
	if(type!=16) {
		throw range_error("Neispravan unos");
	}
	string dec1=convert(type,10,number1);
	cout<<dec1<<endl;
	long long int decInt1=stringToIntegerDec(dec1);
	cout<<decInt1<<endl;
	string dec2=convert(type,10,number2);
	cout<<dec2<<endl;
	long long int decInt2=stringToIntegerDec(dec2);
	cout<<decInt2<<endl;
	
	long long int result=decInt1-decInt2;
	cout<<result<<endl;
	string r=convert(10,type,result);
	return r;
}




string binarySubtracting(long long int number1,long long int number2,int type) {
	if(type==16||type==10) {
		throw range_error("Neispravan unos");
	}
	string dec1=convert(type,10,number1);
	long long int decInt1=stringToIntegerDec(dec1);
	string dec2=convert(type,10,number2);
	long long int decInt2=stringToIntegerDec(dec2);
	
	long long int result=decInt1-decInt2;
	string r=convert(10,type,result);
	return r;
}

/*MULTIPLYING*/
/**/
string binaryMultipy(string number1,string number2,int type) {
	if(type!=16) {
		throw range_error("Neispravan unos");
	}
	string dec1=convert(type,10,number1);
	long long int decInt1=stringToIntegerDec(dec1);
	string dec2=convert(type,10,number2);
	long long int decInt2=stringToIntegerDec(dec2);
	
	long long int result=decInt1*decInt2;
	string r=convert(10,type,result);
	return r;
}

/**/

string binaryMultipy(long long int number1,long long int number2,int type) {
	if(type==16||type==10) {
		throw range_error("Neispravan unos");
	}
	string dec1=convert(type,10,number1);
	long long int decInt1=stringToIntegerDec(dec1);
	string dec2=convert(type,10,number2);
	long long int decInt2=stringToIntegerDec(dec2);
	
	long long int result=decInt1*decInt2;
	string r=convert(10,type,result);
	return r;
}




/*DEVIDE*/

/**/
string binaryDevide(string number1,string number2,int type) {
	if(type!=16) {
		throw range_error("Neispravan unos");
	}
	string dec1=convert(type,10,number1);
	long long int decInt1=stringToIntegerDec(dec1);
	string dec2=convert(type,10,number2);
	long long int decInt2=stringToIntegerDec(dec2);
	long long int result=decInt1/decInt2;
	string r=convert(10,type,result);
	return r;
}



string binaryDevide(long long int number1,long long int number2,int type) {
	if(type==16||type==10) {
		throw range_error("Neispravan unos");
	}
	string dec1=convert(type,10,number1);
	long long int decInt1=stringToIntegerDec(dec1);
	string dec2=convert(type,10,number2);
	long long int decInt2=stringToIntegerDec(dec2);
	
	long long int result=decInt1/decInt2;
	string r=convert(10,type,result);
	return r;
}






