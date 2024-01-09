#include <iostream>
using namespace std;

int getAmount();
void times(double&, double&);
bool validTime(double);
void mealsAllowance(double&, double&, double&);

int getAmount(){
	int amt;
	
	do{
		cout << "Please enter the amount spent : ";
		cin >> amt;	
	
		if(amt <= 0){
			cout << "Amount must be greater than 0." << endl;
		}
		else if(amt > 0)
			break;
	
	}while((amt <= 0));

return amt;	
}

void times(double& PI, double& PO){
	cout << "Please enter the punch in time (HH.MM) : ";
	cin >> PI;
	
	while(validTime(PI) == 0){
		cout << "Punch in time must be between 00.00 and 23.59." << endl << endl;
		cout << "Please enter the punch in time (HH.MM) : ";
		cin >> PI;
	}
	
	cout << "Please enter the punch out time (HH.MM) : ";
	cin >> PO;

	while(validTime(PO) == 0){
		cout << "Punch out time must be between 00.00 and 23.59." << endl << endl;
		cout << "Please enter the punch out time (HH.MM) : ";
		cin >> PO;
	}
		
	while(PO < PI){
		cout << "Invalid inputs!!" << endl << endl;	
		cout << "Please enter the punch in time (HH.MM) : ";
		cin >> PI;
	
		while(validTime(PI) == 0){
			cout << "Punch in time must be between 00.00 and 23.59." << endl << endl;
			cout << "Please enter the punch in time (HH.MM) : ";
			cin >> PI;
		}
	
		cout << "Please enter the punch out time (HH.MM) : ";
		cin >> PO;

		while(validTime(PO) == 0){
			cout << "Punch out time must be between 00.00 and 23.59." << endl << endl;
			cout << "Please enter the punch out time (HH.MM) : ";
			cin >> PO;
		}
	}
}

bool validTime(double time){
	bool valid;
	int hour, mins;
	
	hour = time;
	mins = (time - hour) * 100;
	
	if((hour >= 0 && hour <=23) && (mins >= 0 && mins <= 59))
		valid = true;		
	else
		valid = false;	
		
return valid;		
}

void mealsAllowance(double& E, double& GA, double& AA){
	double PI,PO;
	double breakfast, lunch, dinner;
	
	times(PI,PO);
	
	if(PI <= 7.0){
		cout << endl;
		cout << ":: Breakfast ::" << endl;
		breakfast = getAmount();
		E += breakfast;
		GA += 5;
		if(breakfast <= 5)
			AA += breakfast;
		else
			AA += 5;
	}
	
	if(PO >= 12.0){
		cout << endl;
		cout << ":: Lunch ::" << endl;
		lunch = getAmount();
		E += lunch;
		GA += 7;
		if(lunch <= 7)
			AA += lunch;
		else
			AA += 7;	
	}
	
	if(PO >= 18.0){
		cout << endl;
		cout << ":: Dinner ::" << endl;
		dinner = getAmount();
		E += dinner;
		GA += 7;
		if(dinner <= 7)
			AA += dinner;
		else
			AA += 7;	
	}	
}




int main(){
	double E=0, GA=0, AA=0, PI,PO, extra, saved; 
	int day;
//	getAmount();
//	times(PI, PO);
//	mealsAllowance(E, GA, AA);
	
	cout << "Please enter the number of working days : ";
	cin >> day;
	
	for(int i=0; i < day; i++){
		cout << "\nDay " << (i+1) << ":" << endl;
		mealsAllowance(E, GA, AA);
	
	}
	
	if(E > AA)
		extra = E - AA;
	
	if(AA < GA)
		saved = GA - AA;	
	
	cout << "\nTotal expenses          : RM" << E << endl;
	cout << "Total given allowance     : RM" << GA << endl;
	cout << "Total allowable allowance : RM" << AA << endl << endl;
	cout << "Extra amount paid by employee   : RM" << extra << endl;
	
	if(AA < GA)
		cout << "Total save by employer           : RM" << saved << endl;

return 0;
}
