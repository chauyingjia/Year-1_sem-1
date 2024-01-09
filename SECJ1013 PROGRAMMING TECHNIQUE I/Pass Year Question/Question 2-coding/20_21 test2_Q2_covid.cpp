#include <iostream>
using namespace std;

void dispStatus(int cases){
	
	if(cases > 40)
		cout << "Red zone";	
	else if((cases >= 21) && (cases <= 40))
		cout << "Orange zone";		
	else if	((cases >= 1) && (cases <= 20))
		cout << "Yellow zone";		
	else
		cout << "Green zone";			
}

void getInput(int& tot_cases, int& new_cases, int& tot_death, int& tot_recovered){
	cout << "Total cases    : ";
	cin >> tot_cases;
	cout << "New cases      : ";
	cin >> new_cases;
	cout << "Total death    : ";
	cin >> tot_death;
	cout << "Total recovered: ";
	cin >> tot_recovered;
	
}

void dispOutput(int act_cases){
	
	cout << "Active cases   : " << act_cases << endl;
	cout << "Status         : ";
	dispStatus(act_cases);
	cout << endl << endl;
}

int calcAverage(int num_states, int tot_act_cases){
	return (tot_act_cases / num_states);
}

int main(){
	bool loop;
	string state, enter;
	int highest = 0;
	string highest_state;
	int tot_cases, new_cases, tot_death, tot_recovered, act_cases = 0;
	int tot_act_cases = 0, num_states = 0;
	
	do{
		cout << endl;
		cout << "<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>>" << endl;
		cout << "State name     : ";
		getline(cin, state);
		
		getInput(tot_cases, new_cases, tot_death, tot_recovered);
		
		cout << endl;
		cout << "<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>>>" << endl;
		act_cases = tot_cases + new_cases - tot_death - tot_recovered;
		dispOutput(act_cases);
		
		if(act_cases > highest){
			highest = act_cases;
			highest_state = state;
		}
		
		num_states ++; 
		tot_act_cases += act_cases;
		
		cin.ignore();
		cout << "Press <ENTER> to continue...";
		getline(cin,enter);
		
		if(enter == "\0")
			loop = true;
		else
			loop = false;	
	}while( loop );
	
	cout << endl;
	cout << "<<<<<<<<< ACTIVE CASES >>>>>>>>>>" << endl;
	cout << "Total  : " << tot_act_cases << endl;
	cout << "Highest: " << highest << " (" << highest_state << ")" << endl;
	cout << "Average for 5 states: " << calcAverage(num_states, tot_act_cases) << endl;
}



























