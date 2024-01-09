#include <iostream>
using namespace std;

void readQty(int&, int&, int&);
void displayHighProd(double, double, double);
double calAvrg(int, double);
void summaryCom(double, double, double, double);

void readQty(int& proA, int& proB, int& proC){
	
	do{
		cout << "Product A: ";
		cin >> proA;

	}while(proA<0 || proA>100);
	
	do{
		cout << "Product B: ";
		cin >> proB;
 
	}while(proB<0 || proB>100);
	
	do{
		cout << "Product C: ";
		cin >> proC;

	}while(proC<0 || proC>100);		
	
}

void displayHighProd(double cmsA, double cmsB, double cmsC){
	
	cout << "Highest commision - ";
	if((cmsA > cmsB) && (cmsA > cmsC)){
		cout << "Product A: RM" << cmsA << endl;
	}else if((cmsB > cmsA) && (cmsB > cmsC)){
		cout << "Product B: RM" << cmsB << endl;
	}else if((cmsC > cmsA) && (cmsC > cmsB)){
		cout << "Product C: RM" << cmsC << endl;
	}	
}

double calAvrg(int numOfAgents, double total){
	return total / numOfAgents;
}

void summaryCom(double cmsA, double cmsB, double cmsC, double tot_cms){
	cout << "Total of commision for three products: RM" << tot_cms << endl;
	displayHighProd(cmsA, cmsB, cmsC);
}

int main(){
	string name, highestTotName, lowestTotName, highestAName, highestBName,highestCName ;
	double total = 0, tot_cms;
	double cmsA, cmsB, cmsC;
	double highestTot = 0, lowestTot = 1000000, highestA = 0, highestB = 0, highestC = 0;
	int numOfAgents = 0, proA, proB, proC;
	
	do{
		cout << "\n---------------------- AGENT -----------------------" << endl;
		cout << "Agent Name: ";
		getline(cin, name);
		
		if(name == "\0")
			break;	
			
		readQty(proA, proB, proC);
		cout << endl;	
		
		cmsA = proA * ((150*0.025));
		cmsB = proB * ((300*0.05));
		cmsC = proC * ((450*0.1));
		tot_cms = cmsA + cmsB + cmsC;
		
		cout << "-------------------SALES SUMMARY------------------" << endl;
		summaryCom(cmsA, cmsB, cmsC, tot_cms);
		
		if(tot_cms > highestTot){
			highestTot = tot_cms;
			highestTotName = name;
		}
		
		if(tot_cms < lowestTot){
			lowestTot = tot_cms;
			lowestTotName = name;
		}		
		
		if(cmsA > highestA){
			highestA = cmsA;
			highestAName = name;
		}
		
		if(cmsB > highestB){
			highestB = cmsB;
			highestBName = name;
		}
		
		if(cmsC > highestC){
			highestC = cmsC;
			highestCName = name;
		}		
			
		numOfAgents++;			
		total += tot_cms;
        cin.ignore();
	
	}while(name != "\0");
	
	cout << "------------------SALES ANALYSIS------------------" << endl;
	cout << "Lowest commission for three products: " << lowestTot << " (" << lowestTotName <<  ")" << endl;	
	cout << "Highest commission for three products: " << highestTot <<  " (" <<highestTotName << ")" << endl;
	cout << "HIghest commission for Product A: RM " << highestA << " (" << highestAName << ")" << endl;
	cout << "HIghest commission for Product B: RM " << highestB << " (" << highestBName << ")" << endl;
	cout << "HIghest commission for Product C: RM " << highestC << " (" << highestCName << ")" << endl;	
	cout << "Total of commission for " << numOfAgents << "agents: RM " << total << endl;
	cout << "Average commission for " << numOfAgents << "`agents: RM " << calAvrg(numOfAgents, total);
	
return 0;	
}
