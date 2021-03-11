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
#include <graphics.h>

using namespace std;

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
	cout << "\n\n\t\t Current Date & Time is: "<<ctime(&now);;

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

	ch2=_getch();
	while(ch2 != 13){

		if(ch2 == '\b'){
			if(username.size() > 0 )  {
				username.erase(username.begin() + username.size() -1);
				cout << "\b \b";
				j--;
			}
			ch2 = _getch();
		}
		else{
			if(j<10)
			{
				cout << ch2;
				username.push_back(ch2);
				ch2 = _getch();
				j++;
			}
			else{
				ch2 = _getch();
			}
		}
	}

	gotoxy(31,11);
	ch=_getch();
	while(ch != 13){

		if(ch == '\b'){
			if(password.size() > 0){
				password.erase(password.begin() + password.size() -1);
				cout << "\b \b";
				i--;
			}
			ch = _getch();
		}
		else{
			if(i<10)
			{
				password.push_back(ch);
				cout << "*";
				ch = _getch();
				i++;
			}
			else{
				ch = _getch();
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


//STUDENT CLASS

								            //

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

records r;

records :: records()
	{
		root = NULL;
	}

void records :: insert()
{
	system("cls");

	label:
	student *newnode, *nodeptr;
	char ch;

	cout << "\n\n _________________________RECORDS INSERTION_________________________";
	do
	{
		system ("cls");
		newnode = new student;

	cout << "\n\n Enter I.D Number of Student: ";
	while(1)
	{
		cin >> newnode->id;
		if (cin.fail() || newnode->id < 1 )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\n\n Invalid Input........\n\n Please Enter a I.D No. greater than or equal to 1: ";
		}
		else
			break;
	}

	student *temp = new student;
	temp = root;
	while (temp != NULL)
	{
		if(newnode->id == temp->id)
			{
				cout << "\n\n This I.D No. has already been used";
				cout << "\n\n Please Enter a unique I.D NO. \n\n";
				system("pause");
				goto label;
				break;
			}
		else if(newnode->id > temp->id)
			{
				temp = temp->right;
			}
			else if(newnode->id < temp->id)
			{
				temp = temp->left;
			}
	}

		label1:
	cout << "\n\n Enter Name of Student: ";
	cin.ignore();
	cin.getline (newnode->name,30);

	int check1 = 0;
for(int i = 0; i < strlen(newnode->name); i++){
        if(isalpha(newnode->name[i]) == 0){
        	if (newnode->name[i] == ' ')
        	{
        		check1 = 0;
			}
			else
			{
            cout << "\n\n Invalid Input........\n\n Please Enter alphabets only:";
            check1 = 1;
            break;
        	}
        }
    }
    if (check1 == 1)
    {
    	goto label1;
	}

	label2:
	cout << "\n\n Enter Father Name of Student: ";
	cin.getline(newnode->fatherName,30);

	int check2 = 0;
for(int j = 0; j < strlen(newnode->fatherName); j++){
        if(isalpha(newnode->fatherName[j]) == 0 ){
        	if (newnode->fatherName[j] == ' ')
        	{
        		check2 = 0;
			}
			else
			{
            cout << "\n\n Invalid Input........\n\n Please Enter alphabets only:";
            check2 = 1;
            break;
        	}
        }
    }
    if (check2 == 1)
    {
    	goto label2;
	}

	cout << "\n\n Enter CGPA of Student (out of 4.0): ";

	while(1)
	{
		cin >> newnode->cgpa;
		if (cin.fail() || (newnode->cgpa < 0.0) || (newnode->cgpa > 4.0) )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\n\n Invalid Input........\n\n Please Enter CGPA ranging from 0.0 to 4.0: ";
		}
		else
			break;
	}

	newnode->left = NULL;
	newnode->right = NULL;

	if (root == NULL)
	{
		root = newnode;
		height++;
	}

	else
	{
		nodeptr = root;
		while (nodeptr != NULL)
		{
			if (newnode->id < nodeptr->id)
			{
				if (nodeptr->left != NULL)
				{
					nodeptr = nodeptr->left;
				}
				else
				{
					nodeptr->left = newnode;
					height++;
					break;
				}
			}

			else if (newnode->id > nodeptr->id)
			{
				if(nodeptr->right != NULL)
				{
					nodeptr = nodeptr->right;
				}
				else
				{
					nodeptr->right = newnode;
					height++;
					break;
				}
			}
		}
	}

			cout << "\n\n Want to enter more records (Y/N): ";
			cin >> ch;
				} while(ch == 'y' || ch == 'Y');
	}

void records:: showAllRecords(student *&temp)
{
    if(temp != NULL)
	{
		showAllRecords(temp->left);
		cout << "\n\n\n I.D-No: " << temp->id;
		cout << "\n Name: " << temp->name;
		cout << "\n Father's Name: " << temp->fatherName;
		cout << "\n CGPA: " << temp->cgpa;
		showAllRecords(temp->right);
    }
}

void records :: showAscen(student *&temp)
{
	if(temp != NULL)
	{
		showAscen(temp->left);
		cout << "\n\n\n I.D-No: " << temp->id;
		cout << "\n Name: " << temp->name;
		cout << "\n Father's Name: " << temp->fatherName;
		cout << "\n CGPA: " << temp->cgpa;
		showAscen(temp->right);
	}
}

void records :: showDescen(student *&temp)
{
	if(temp != NULL)
	{
		showDescen(temp->right);
		cout << "\n\n\n I.D-No: " << temp->id;
		cout << "\n Name: " << temp->name;
		cout << "\n Father's Name: " << temp->fatherName;
		cout << "\n CGPA: " << temp->cgpa;
		showDescen(temp->left);
	}
}


void records :: display(int choice)
{
	system("cls");
	if(root == NULL)
	{
		cout << "\n\n Please Enter some Record First...\n\n";
		return;
	}
	cout << "\n\n _________________________RECORDS DISPLAY_________________________";
	if (choice == 1)
	{
		records :: showAscen(root);
	}
	else if (choice == 2)
	{
		records :: showDescen(root);
	}
	else
    {
        records::showAllRecords(root);
    }

}

void records :: search()
{
	system("cls");
	if (root == NULL)
	{
		cout << "\n\n Please Enter Some Record First...\n\n";
		return;
	}
	int idNumber,check = 0;
	student *temp;
	cout << "\n\n _________________________RECORDS SEARCH_________________________";
	cout << "\n\n Please Enter I.D No. of Student to Search: ";
	while(1)
	{
		cin >> idNumber;
		if (cin.fail() || idNumber < 1 )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\n Invalid Input......\n\n Please Enter a I.D No. greater than or equal to 1: ";
		}
		else
			break;
	}

	temp = root;
	while(temp != NULL)
	{
		if (temp->id == idNumber)
		{
		    cout << "\n\n RECORDS FOUND ";
			cout << "\n\n I.D-No: " << temp->id;
			cout << "\n Name: " << temp->name;
			cout << "\n Father's Name: " << temp->fatherName;
			cout << "\n CGPA: " << temp->cgpa;
			check = 1;
			break;
		}

		else if(idNumber < temp->id)
		{
			temp = temp->left;
		}

		else if(idNumber > temp->id)
		{
			temp = temp->right;
		}
	}
		if (check == 0)
		{
			cout << "\n\n Record of Student with I.D NO. " << idNumber << " not Found...!\n";
			return;
		}
}

int records :: remove (int idNumber, student *&nodeptr,int &found)
{
	if (nodeptr == NULL)
	{
		return found;
	}

	else if(idNumber < nodeptr->id)
	{
		records :: remove(idNumber,nodeptr->left,found);
	}

	else if (idNumber > nodeptr->id)
	{
		records :: remove (idNumber,nodeptr->right,found);
	}
	else if (idNumber == nodeptr->id)
	{
		found = 1;
		records :: del(nodeptr);
	}

		return found;
}

void records :: del (student *&nodeptr)
{
		student *temp;

		if(nodeptr->left == NULL && nodeptr->right == NULL)
			{
				delete nodeptr;
				nodeptr = NULL;
			}
		else if (nodeptr->right == NULL)
			{
				temp = nodeptr;
				nodeptr = nodeptr->left;
				delete temp;
				height--;
				cout << "\n\n RECORD DELETED SUCCESSFULLY.\n";
			}
		else if (nodeptr->left == NULL)
			{
				temp = nodeptr;
				nodeptr = nodeptr->right;
				delete temp;
				height--;
				cout << "\n\n RECORD DELETED SUCCESSFULLY.\n";
			}
		else if (nodeptr->right != NULL && nodeptr->left != NULL)
		{
			temp = nodeptr->right;

			while (temp->left != NULL)
			{
				temp = temp->left;
			}
				temp->left = nodeptr->left;

				temp = nodeptr;
				nodeptr = nodeptr->right;
				delete temp;

				height--;
				cout << "\n\n RECORD DELETED SUCCESSFULLY.\n";
		}
			return;
	}


void records :: deleteRecords()
{
	system("cls");
	int idNumber,f=0,found=0;

	if(r.root == NULL)
	{
		cout << " Please Enter some Record First.";
		return;
	}

	cout << "\n\n _________________________RECORDS DELETION_________________________";
	cout << "\n\n Please Enter I.D No. of Student to Delete: ";

	while(1)
	{
		cin >> idNumber;
		if (cin.fail() || idNumber < 1 )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\n Invalid Input.\n Please Enter a I.D No. greater than or equal to 1: ";
		}
		else
			break;
	}

	f=r.remove(idNumber,r.root,found);

	if( f== 0)
		{
		cout << "\n\n Record of Student with I.D NO. " << idNumber << " not Found...!\n\n";
		return;
		}

}

void records :: totalStudents()
{
	system("cls");
	if (height == 0)
	{
		cout << "\n\n Please Insert Some Records First...";
		return;
	}
	else
	{
		cout << "\n\n Total Number of Students are: " << height;
	}
}

void records::modifyRecords()
{
int f=0,found=0;
	system("cls");
	if (root == NULL)
	{
		cout << "\n\n Please Enter Some Record First...\n\n";
		return;
	}
int idNumber,check = 0;
	student *temp;
	cout << "\n\n _________________________RECORDS MODIFY_________________________";
	cout << "\n\n Please Enter I.D No. of Student to MODIFY: ";
	while(1)
	{
		cin >> idNumber;
		if (cin.fail() || idNumber < 1 )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\n Invalid Input......\n\n Please Enter a I.D No. greater than or equal to 1: ";
		}
		else
			break;
	}

	temp = root;
	while(temp != NULL)
	{
		if (temp->id == idNumber)
		{
		    f=r.remove(idNumber,r.root,found);
		    cout << "\n\n _________________________RECORDS MODIFY_________________________";
		    cout << "\n\n Enter New Details: \n";
		    insert();
			check = 1;
			break;
		}

		else if(idNumber < temp->id)
		{
			temp = temp->left;
		}

		else if(idNumber > temp->id)
		{
			temp = temp->right;
		}
	}
		if (check == 0)
		{
			cout << "\n\n Record of Student with I.D NO. " << idNumber << " not Found...!\n";
			return;
		}
}

/*void records :: findDepthOfNode()
{
	system("cls");
	int rn;
	int count = 0;
	int check = 0;
	student *temp;

	if (height == 0)
	{
		cout << "Please Enter some Record First....";
		return;
	}
	else
	{
		cout << "\n _________________________DEPTH OF NODE_________________________";
		cout << "\n\n Enter I.D No. of Student to Find the Depth of Node: ";

		while(1)
	{
		cin >> rn;
		if (cin.fail() || rn < 1 )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter a I.D No. greater than or equal to 1: ";
		}
		else
			break;
	}

		temp = root;
		while (temp != NULL)
		{
			if (temp->id == rn)
			{
				cout << "\n\n Depth of Node you Entered starting From Zero is: " << count;
				check = 1;
				break;
			}
			else if (rn < temp->id)
			{
				temp = temp->left;
				count++;
			}
			else if (rn > temp->id)
			{
				temp = temp->right;
				count++;
			}
		}
			if(check == 0)
			{
				cout << "\n\nThe Student with I.D No. " << rn << " was not FOUND...\n\n";
			}
	}
}*/

void records :: studentMenu()
{
	system("cls");
    system("color 0F");
	int choice;
	while(true)
	{
		system("cls");
	cout << "\n\n  _________________________STUDENT RECORD DATABASE_________________________";
	cout << "\n\n 1: Enter Record ";
	cout << "\n\n 2: Display Records in Ascending I.D No.";
	cout << "\n\n 3: Display Records in Descending I.D No.";
	cout << "\n\n 4: Show all Records ";
	cout << "\n\n 5: Modify Records ";
	cout << "\n\n 6: Delete Record";
	cout << "\n\n 7: Search Record";
	cout << "\n\n 8: Check Total No. of Students ";
	cout << "\n\n 9: To Log Out and Exit ";
	cout << "\n\n Enter your Choice: ";
    cin>>choice;

	switch(choice)
	{
		case 1:
		    loading();
			r.insert();
			cout << "\n\n\t";
			system("pause");
			break;
		case 2:
		    loading();
			r.display(1);
			cout << "\n\n\t";
			system("pause");
			break;
		case 3:
		    loading();
			r.display(2);
			cout << "\n\n\t";
			system("pause");
			break;
		case 4:
            display(3);
			cout << "\n\n\t";
			system("pause");
			break;
		case 5:
		    modifyRecords();
			cout << "\n\n\t";
			system("pause");
			break;
		case 6:
		    loading();
			r.deleteRecords();
			cout << "\n\n\t";
			system("pause");
			break;
		case 7:
		    loading();
			r.search();
			cout << "\n\n\t";
			system("pause");
			break;
        case 8:
		    loading();
			r.totalStudents();
			cout << "\n\n\t";
			system("pause");
			break;
		case 9:
			exit(0);
			break;
		default:
			cout << "\n\n Please Enter a valid Choice: \n\n";
			system ("pause");
			break;
		}
	}
}
