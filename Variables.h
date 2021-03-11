#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED
#include <iostream>
#include <math.h>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstdlib>

using namespace std;

static int height = 0;

class records
{
	public:
		struct student
		{
			int id;
			char name[30];
			char fatherName[30];
			float cgpa;

			student *left;
			student *right;
		};

		public:
		student *root;
			records();
			void insert();
			void display(int);
			void showAscen (student *&);
			void showDescen (student *&);
			void search();
			void deleteRecords();
			int remove(int rn, student *&,int &found);
			void del (student *&nodeptr);
			void totalStudents();
			int findHeight(student *&);
			void showAllRecords(student *&);
			void modifyRecords();
			//void findDepthOfNode();
			void studentMenu();


};
COORD coord = {0,0};
void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition( GetStdHandle (STD_OUTPUT_HANDLE), coord );
}
void time()
{
	gotoxy(1,4);
		time_t now;
	time (&now);
	cout << "\n\n\t\t Current Date & Time is: "<<ctime(&now);

}
void loading()
{
	gotoxy(24,26);
	int i;
	for (i=0; i<5; i++)
	{
		cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
		Sleep(150);
	}
	Sleep(600);
	cout << endl << endl;
	gotoxy(24,28);
}


void mainEntrance()
{
cout << "    *******************************************************************" << endl;
gotoxy(3,2);
cout << "                   NORTH SOUTH UNIVERSITY                    " << endl;
gotoxy(4,5);
cout << "*******************************************************************" << endl;
}
void login()
{
	system("cls");

	string username = "";
	string password = "";
	char ch,ch2,retry;
	int i = 0, j = 0;
	mainEntrance();
	time();
	gotoxy(51,2);
	cout << "(LOGIN PAGE)";
	gotoxy(15,10);
	cout << "Enter Username: \n\t       Enter Password: ";
	gotoxy(31,10);

	ch2=getch();
	while(ch2 != 13){

		if(ch2 == '\b'){
			if(username.size() > 0 )  {
				username.erase(username.begin() + username.size() -1);
				cout << "\b \b";
				j--;
			}
			ch2 = getch();
		}
		else{
			if(j<10)
			{
				cout << ch2;
				username.push_back(ch2);
				ch2 = getch();
				j++;
			}
			else{
				ch2 = getch();
			}
		}
	}

	gotoxy(31,11);
	ch=getch();
	while(ch != 13){

		if(ch == '\b'){
			if(password.size() > 0){
				password.erase(password.begin() + password.size() -1);
				cout << "\b \b";
				i--;
			}
			ch = getch();
		}
		else{
			if(i<10)
			{
				password.push_back(ch);
				cout << "*";
				ch = getch();
				i++;
			}
			else{
				ch = getch();
			}
		}
	}
	if (username == "nsu" && password == "1234")
	{
		gotoxy(15,16);
		cout << "\n\n Username & Password Matched !! ";
		cout << "\n\n\t Access Granted...\n\n";
		cout << "\n\n\t\t Now Loading: ";
		loading();
		return;
	}
	else
	{
		system("cls");
		cout << "\n\n You entered Wrong UserName/Password ";
		cout << "\n\n Press 'R' or 'r' to Enter Again OR any other key to exit \n\n";
		cin >> retry;
			if(retry == 'r' || retry == 'R')
			{
				system("cls");
				login();
			}
			else
			{
				exit(0);
			}
	}
}

#endif // VARIABLES_H_INCLUDED
