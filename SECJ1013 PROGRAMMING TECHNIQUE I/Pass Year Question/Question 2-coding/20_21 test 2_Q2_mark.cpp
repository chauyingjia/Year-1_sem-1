#include <iostream>
#include <iomanip>
using namespace std;

void getInput(int& score1, int& score2, int& score3){
	
	cout << "Q1 mark: " ;
	cin >> score1 ;
	
	cout << "Q2 mark: " ;
	cin >> score2;
	
	cout << "Q3 mark: " ;
	cin >> score3;	
	

}


void dispTier(int total){
	
	if(total<40)
		cout << "Tier 3" << endl;
	
	else if (total>=40 && total<75)
		cout << "Tier 2" << endl;
		
	else 
		cout << "Tier 3" << endl;
	
}

int calcAverage(int students, int tot_marks){
	return tot_marks / students;
}

void dispSummary(int tot){
	cout << setw(11) << "Total marks: " << tot << endl;
	cout << "Tier       : ";
	dispTier(tot);
}

int main(){
	
	string name, loweststudent, higheststudent;
	int score1, score2, score3;
	int highest = 0, lowest = 999;
	int average, total, students = 0, tot_marks = 0;
	
	do{
		cout << endl << endl;
		cout << "<<<<<<<<<<<<< DATA >>>>>>>>>>>>>" << endl;
		cout << "Name   : ";
		getline(cin, name);
		
		if(name == "\0")
			break;
		
		getInput(score1, score2, score3);
		cout << endl;
		cout<<"<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>"<<endl;
		total=(score1*35/100) + (score2*25/100) + (score3*40/100);
		
//        if(total < lowest){					//try highest xian
//            lowest = total;
//            loweststudent = name;
//        }
        if(total>highest){
            highest = total;
            higheststudent = name;
        }
        
        if(total < lowest){					//try highest xian
            lowest = total;
            loweststudent = name;
        }
		
		students ++;
		tot_marks += total;
		dispSummary(total);
		average = calcAverage(students, tot_marks);
        cin.ignore();
				

	}while(name != "\0");
	
	cout << "<<<<<<<< RESULT ANALYSIS >>>>>>>>" << endl;
	cout << "Lowest mark : " << lowest << " (" << loweststudent << ")" << endl;
	cout << "Highest mark: " << highest << " (" << higheststudent << ")" << endl;
	cout << "Average for 4 students: " << average ;
	cout << endl;
	
return 0;	
}












