//SABRINA HENG WEI QI   A23CS0265
//CHAU YING JIA         A23CS0213
#include<iostream>
using namespace std;

int main(){
	int num , price;
	cout << "Welcome to the Food Ordering System" << endl;
	cout << "1. Pizza - $10" << endl;
	cout << "2. Burger - $5" << endl;
	cout << "3. Sandwich - $7" << endl;
	
	cout << "Enter the number of the item you want to order :";
	cin >> num;
	
	switch (num){
		case 1 : price = 10;
				 break;
				 
		case 2 : price = 5;
				 break;
				 
		case 3 : price = 7;
				 break;
				 		 
	}
	
	cout << "Your total bill is : $" << price;
	
return 0;	
}
