#include <iostream>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include <string>

	using namespace std;
	int random();
	string dec2binary();
	string dec2hexadecimal();
	int bin2decimal();
	int hex2decimal();
	
	int decimalvalue,binarynumber,randominterger;
	string hexadecimalvalue;
		
int random(int randominterger)
{
	
	srand( time( NULL ) );
	randominterger = (rand()% (99-1+1))+1;
	
	return randominterger;
	}
	
	
string dec2binary(int decimalvalue)
{
	
	static string A[32];
	string binarycode;
	int i=0;
			
	while (decimalvalue > 0)
	{
	A[i] = to_string(decimalvalue%2);
	binarycode = A[i]+binarycode;
	decimalvalue = decimalvalue/2;
	i++;
	} 
	
	
	return binarycode;
}

int bin2decimal(int binarynumber)
{
	
	int total = 0,i=0,remainder;
	
	while (binarynumber!=0)
	{
		remainder = binarynumber % 10;
		binarynumber/=10;
		total+=remainder*pow(2,i);
		++i;
		}
	
	return total;
 }

string dec2hexadecimal(int decimalvalue)
{
	int remainder;
	char A;
	hexadecimalvalue ="";
	
	while (decimalvalue!=0)
	{
		remainder = 0;
		
		remainder = decimalvalue%16;
		if (remainder < 10)
		A = remainder =48;
		
		else A = remainder + 55;
		hexadecimalvalue= A;
		decimalvalue = decimalvalue/16;
		
	}
	reverse (hexadecimalvalue.begin(),hexadecimalvalue.end());
	return hexadecimalvalue;
	



	
}

int hex2decimal(string hex2decimalvalue)
{
	
	int total,remainder;
	int length=0;
	int size=0;
	total = 0;
	remainder=0;
	
	length = hex2decimalvalue.size()-1;
	while (length >=0)
	{
		remainder = hex2decimalvalue[length];
		
		if (remainder>=48 && remainder<=57)
		{
			remainder = remainder - 48;
		}				
		else if (remainder>=65 && remainder<=70)
		{
			remainder = remainder - 55;
		}
					
	total = total + remainder*pow(16,size);
	length --;
	size++;
		}
			
	return total;
}

int main()
{
int menuselection = 0;

cout << "PROGRAM MENU:" << endl;
printf("1.\tConvert DECIMAL to BINARY \n");
printf("2.\tConvert BINARY to DECIMAL \n");
printf("3.\tConvert hex2decimal to DECIMAL \n");
printf("4.\tConvert DECIMAL to hex2decimal \n");
printf("5.\tDEMO (Generate and convert random integers to binary \n");
printf("6.\tExit\n");

while (menuselection < 7)
{
cout << "Enter your selection (1-6): ";
cin >> menuselection;

if (menuselection == 1)
{
	 cout << "Give a decimal number: ";
	 cin >> decimalvalue; 
	 cout << "Binary representation: "<<dec2binary(decimalvalue)<<endl;
	 	
	}
else if (menuselection == 2)
{
	cout << "Give a binary number: "; 
	cin >> binarynumber;
	cout <<"Decimal representation: " << bin2decimal(binarynumber)<<endl;
	
	}
else if (menuselection == 3)
{
	cout << "Give a hex2decimal number: ";
	cin >> hexadecimalvalue;
	cout<<"Decimal representation: " << hex2decimal(hexadecimalvalue)<<endl;
	}
else if (menuselection == 4)
{
	cout << "Give a decimal number: ";
	cin >> decimalvalue;
	cout<<"hex2decimal representation: " <<dec2hexadecimal(decimalvalue)<<endl;
	}
else if (menuselection == 5)
{
	int randomnumber;
	randomnumber = random(randominterger);
	cout << "Generated random integer :" << randomnumber<<endl;
	cout <<"Binary representation: " << dec2binary(randomnumber)<<endl;
	
	}
else if (menuselection == 6)
{
	cout << "Exiting the program." <<endl;
	exit(0);
	
	}
}
return 0;
}
