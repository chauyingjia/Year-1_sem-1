//Chau Ying Jia A23CS0213
//Sabrina Heng Wei Qi A23CS0265
#include <iostream>
#include <string>
using namespace std;

#define MAX_BOOKS 50
string title [MAX_BOOKS];
string authors [MAX_BOOKS];
int public_y [MAX_BOOKS];
int bookCount = 0;

void displayMainMenu();
void addBook();
void displayLibrary();
void searchByTitle();

int main(){
	string title, name;
	int choice, year;
	
	do{
		
		displayMainMenu();
		cout << "Enter your choice: ";
		cin >> choice;	
		
			switch(choice){
				case 1 : addBook();
					break;
				case 2 : displayLibrary();
					break;
				case 3 : searchByTitle();
					break;
				case 4 : cout << "\n\nGoodbye !\n";
					break;	
				default : cout << "Invalid number. Enter again.";
					break;	
			}
	}while(choice != 4);
	
return 0;
}

void displayMainMenu(){
	cout << "<<<<<Library Management System>>>>>" << endl;
	cout << "=========================================" << endl;
	cout << "1. Add a Book" << endl;
	cout << "2. Display Library" << endl;
	cout << "3. Search by Title" << endl;
	cout << "4. Quit" << endl;
		
}

void addBook(){

	if(bookCount < MAX_BOOKS){

		cout << "\nEnter book title: ";
		cin.ignore();
		getline(cin, title[bookCount]);
		
		cout << "Enter author name: ";
		getline(cin, authors[bookCount]);
	
		cout << "Enter publication year: ";
		cin >> public_y[bookCount];

		bookCount++;
		
		cout << "\n\nBook added succesfully!" << endl << endl;

	}else
		cout << "Library is full." << endl;
}

void displayLibrary(){
	
	cout << "\nLibrary Contents: " << endl;
	cout <<"=========================" << endl;
	
	for(int i = 0; i < bookCount; i++){
		
		cout << "Title: " << title[i] << endl;
		cout << "Author: " << authors[i] << endl;
		cout << "Year: " << public_y[i] << endl << endl;
	}
	
	
}

void searchByTitle(){
	string t;
	bool found = false;
	
	cout << "\nEnter the title to search: ";
	cin.ignore();
	getline(cin, t);
	
	for(int i = 0; i < bookCount; i++){
		if(title[i] == t){
			found = true;
			if(found==1){
				cout << "Book found: " << endl;
				cout << "==================" << endl;
				cout << "Title: " << title[i] << endl;
				cout << "Author: " << authors[i] << endl;
				cout << "Year: " << public_y[i] << endl << endl;
				break;
			} 
				
		}
	}		
	
	if(!found){
		cout << "Book is not found." << endl << endl;
			
	}
}
	





