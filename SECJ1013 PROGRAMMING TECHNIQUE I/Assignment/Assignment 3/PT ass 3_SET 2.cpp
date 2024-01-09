//SABRINA HENG WEI QI  A23CS0265
//CHAU YING JIA  A23CS0213
#include<iostream>
using namespace std;
const int MAX_OPERATIONS = 100;	//constant variable

int operands1[MAX_OPERATIONS];
int results[MAX_OPERATIONS];

int multiplyUsingAddition(int,int);
void displayMainMenu();
void performMultiplication(int&);
void displayResults(int);

int main(){
	int operationCount = 0;
	int choice;
	do{
		displayMainMenu();
		cout << "Enter your choice :";
		cin >> choice;
		cout << endl << endl;
	
		switch(choice){
			case 1 : performMultiplication(operationCount);
						break;
					
			case 2 : displayResults(operationCount);
						break;
					
			case 3 : cout << "\nGoodbye ! \n";
						break;
						
			default : cout << "Invalid choice." << endl;
	
		}
	}while(choice != 3);
	return 0;
}


// function multiply using addition
int multiplyUsingAddition(int a,int b){
	int result = 0;
	for(int i=0;i<b;++i){
		result +=a;	
	}
	return result;
}

//function display main menu
void displayMainMenu(){
	cout << "<<<<< Main Menu >>>>>" << endl;
	cout << "=============================" << endl;
	cout << "1. Perform Multiplication" << endl;
	cout << "2. Display Results" << endl;
	cout << "3. Quit" << endl;
}

//function perform multiplication
void performMultiplication(int &count){
	int n ;
	cout << "Enter the number of operands for multiplication :";
	cin >> n;
	
	int operands[n];
	for(int i = 0;i<n;++i){
		cout << "Enter operand " << (i+1) << ": ";
		cin >> operands[i]; 
	}
	
	int result = operands[0];    
	for(int i = 1;i<n;++i){
		result = multiplyUsingAddition(result,operands[i]);
	}
	
	count++;
	operands1[count - 1] = n;
	results[count - 1] = result;
	cout << endl << "Multiplication performed successfully !" << endl << endl;
	
}

//function display results
void displayResults(int count){
	cout << "Results of Mathematical Operations :" << endl;
	cout << "========================================" << endl;
	for(int i=0;i<count;++i){
		cout << "Operation " << i+1 << ": " << results[i] <<"(Operands : " << operands1[i] << ")" << endl <<endl;
	}
}


