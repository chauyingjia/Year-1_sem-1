#include <iostream>
#include <string>
using namespace std;

#define WASH 10.0 // the price of WASH service charge
#define VACUUM 7.0 // the price of VACUUM service charge
#define POLISH 15.0 // the price of POLISH service charge

//task 6
void setType(string&);
void setPackage(int&);
float wash(string);
float vacuum(string);
float polish(string);

//task 7
int main() {
    string carType; 				
	int wsPkg;
	float totalCharge = 0;
	
    setType(carType); // Call the setType function passing the carType variable
	setPackage(wsPkg);
	
	switch(wsPkg){
		case 1 : totalCharge += wash(carType);
			break;
		case 2 : totalCharge += vacuum(carType);	
			break;
		case 3 : totalCharge += polish(carType);
			break;	
		}
	
	if(wsPkg == 1){
		cout << "Wash service charge is "<< totalCharge  << endl;

	}else if(wsPkg == 2){
		cout << "Vacuum service charge is " << totalCharge << endl;
		
	}else if(wsPkg == 3){
		cout << "Polish service charge is " << totalCharge << endl;
	}
		                   
	cout << endl;
	cout << "Total service charge is " << totalCharge;
}


//task 1
void setType(string &type) {
    do {
        cout << "Enter car type (sedan/mpv): ";
        cin >> type;
    } while ((type != "sedan") && (type != "mpv"));
    cout << endl;
}

//task 2
void setPackage(int &pkg){
	cout << "1. Basic" << endl;
	cout << "2. Deluxe" << endl;
	cout << "3. Premium" << endl;
	cout << "Choose wash service package (1/2/3): ";
	cin >> pkg;
	cout << endl;
}

//task 3
float wash(string type){
	double w_charge;
	
	if(type == "mpv"){
		w_charge = 1.2 * WASH;
		
	}else
		w_charge = WASH;

return w_charge;		
}

//task 4
float vacuum(string type){
	double v_charge;
	
	if(type == "mpv"){
		v_charge = 1.05 * VACUUM;
		
	}else
		v_charge = VACUUM;

return v_charge;		
}

//task 5
float polish(string type){
	double p_charge;
	
	if(type == "mpv"){
		p_charge = 1.2 * POLISH;
		
	}else
		p_charge = POLISH;

return p_charge;		
}

