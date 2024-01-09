//CHAU YING JIA			A23CS0213
//SABRINA HENG WEI QI	A23CS0265

#include <iostream>
using namespace std;


const double DEP = 500.00;
const double WITHD = 200.00;
const double withD = 200.00;

double displayAccountInfo(double& bal){

	cout << "Account Holder Name : User 1" << endl;
	cout << "Account Number : 1013202341" <<endl;
	cout << "Balance : RM " << bal << endl;
	
	return bal;
}

double deposit(double& bal, double dep){
	bal = bal + dep;
	cout << "deposit of RM " << dep << " succesful." << endl;
 	
 	return bal;
}

double withdraw(double withD, double& bal){
	if(withD <= bal){					//withD = withdraw amount
		bal = bal - withD;
		cout << "Withdrawal of RM " << withD << " succesful." << endl;
	}else{
		cout << "Insufficient funds for withdrawal" << endl;
	}
	return withD;
}


int main(){
	
	char userInput;
	double BAL=200;
	do{
	
	cout << "<<<<< My Accounts Overview >>>>>" << endl;
	displayAccountInfo(BAL);
	cout << endl << endl;
	
	cout << "<<<<< Deposit Transaction >>>>>" << endl;
	deposit(BAL, DEP);
	cout << endl << endl;
	
	cout << "<<<<< Withdrawal Transaction >>>>>>" << endl;
	withdraw(WITHD, BAL);
	cout << endl << endl;
	
	cout << "<<<<< My Accounts Overview >>>>>" << endl;
	displayAccountInfo(BAL);
	cout << endl << endl;
	
	cout << "Do you want to perform another transaction? (Y/N) : ";
	cin >> userInput;
	cout << endl << endl;
	
	}while(userInput == 'Y'||userInput == 'y');
	
return 0;
}
