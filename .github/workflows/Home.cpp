/*
	Name: Home Expance Management
	Copyright: Resurved 
	Author: Samir Kumar Dubey
	Date: 07-10-18 18:07
	Output Size: 1.89968967437744 MiB
	Compilation Time: 2.84s
	Description: Home expance management is best choice to save expance of home parmamently.
*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
using namespace std;
class expance
{
	private:
		//variable
		char d[14];
		int r;
		int mr;
		int u;
		long int a;
		long int b;
		int ebill;
		int milk;
		int kirana;
		int study;
		int veg;
		int other;
		long int total;
	public:
		//Function
		void input();
		void output();
		void entry();
		void display();
};
//Entry Home Expance to define class function-structure
void expance::entry()
{
	cout<<"Enter Date :";
	cin>>d;
	cout<<"Enter Kirana Expance :";
	cin>>kirana;
	cout<<"Enter Milk Expance :";
	cin>>milk;
	cout<<"Enter Vegitable Expance :";
	cin>>veg;
	cout<<"Enter Study Expance :";
	cin>>study;
	cout<<"Enter Other Expance :";
	cin>>other;
	total=kirana+milk+veg+study+other;
}
//Display Home Expance to define class function-structure
void expance::display()
{
	cout<<"\t"<<d<<"\t| "<<kirana<<"\t "<<milk<<"\t  "<<veg<<"\t\t"<<study<<"\t"<<other<<"\t| "<<total<<endl;
}
//Entry Home Rante to define class function-structure
void expance:: input()
{
	cout<<"Enter Date :";
	cin>>d;
	cout<<"Enter Home Rante :";
	cin>>r;
	cout<<"Enter 1st Meter Reading :";
	cin>>a;
	cout<<"Enter Current Meter Reading :";
	cin>>b;
	cout<<"Enter Rupees/Unit of E-Bill :";
	cin>>u;
	mr=b-a;
	ebill=mr*u;
	total=r+ebill;
}
//Display Home Rante to define class function-structure
void expance::output()
{
	cout<<"\t"<<d<<" |\t"<<r<<"\t     "<<b<<"-U\t\t"<<mr<<"-U\t "<<ebill<<"\t| "<<total<<"\n";
}
int main()
{
	int n;
	fstream file;
	expance e;
	while(1)
	{
		system("cls");
		cout<<"******************************************\n";
		cout<<"\t|| HOME EXPANCE MANAGEMENT ||\n";
		cout<<"******************************************\n";
		cout<<"\t     /*MAIN MENU*/\n";
		cout<<"------------------------------------------\n";
		cout<<"\t1. Enter Home Rante Expance\n";
		cout<<"\t2. Display Home Rante Expance\n";
		cout<<"\t3. Enter Home Expance\n";
		cout<<"\t4. Display Home Expance\n";
		cout<<"\t5. Exit\n";
		cout<<"\tEnter Choice(1-3):";
		cin>>n;
		switch(n)
		{
			//Entry Home Rante Wizard
			case 1:
				system("cls");
				file.open("Homeex.db",ios::app| ios::binary);
				cout<<"--------------------------------\n";
				printf("\t|| ENTRY WIZARD ||\n");
				cout<<"--------------------------------\n";
				e.input();
				file.write((char *)&e,sizeof(e));
				cout<<"Record successfuly saved...\n";
				getch();
				file.close();
				break;
				//Display Home Rante Wizard
			case 2:
				system("cls");
				file.open("Homeex.db",ios::in| ios::binary);
				cout<<"**********************************************************************************\n";
				cout<<"\t\t\t\t||DISPLAY WIZARD||\n";
				cout<<"**********************************************************************************\n";
				cout<<"\t  DATE\t\tRANTE\t  METER READING\t     BILL-UNIT\tE-BILL\t  TOTAL\n";
				cout<<"----------------------------------------------------------------------------------\n";
				while(file.read((char *)&e,sizeof(e)))
				{
					e.output();
				}
				cout<<"----------------------------------------------------------------------------------\n";
				cout<<"-------------------------Developed by: SAMIR KUMAR DUBEY--------------------------\n";
				file.close();
				getch();
				break;
				//Enctry Home Expance Wizard
			case 3:
				system("cls");
				file.open("House.db",ios::app| ios::binary);
				cout<<"--------------------------------\n";
				printf("\t|| ENTRY WIZARD ||\n");
				cout<<"--------------------------------\n";
				e.entry();
				file.write((char *)&e,sizeof(e));
				cout<<"Record successfuly saved...\n";
				getch();
				file.close();
				break;
				//Display Home Expance Wizard
			case 4:
				system("cls");
				file.open("House.db",ios::in| ios::binary);
				cout<<"**********************************************************************************\n";
				cout<<"\t\t\t\t||DISPLAY WIZARD||\n";
				cout<<"**********************************************************************************\n";
				cout<<"\t   DATE\t\t KIRANA\t MILK\tVEGITABLE\tSTUDY\tOTHER\t  TOTAL\n";
				cout<<"----------------------------------------------------------------------------------\n";
				while(file.read((char *)&e,sizeof(e)))
				{
					e.display();
				}
				cout<<"----------------------------------------------------------------------------------\n";
				cout<<"-------------------------Developed by: SAMIR KUMAR DUBEY--------------------------\n";
				file.close();
				getch();
				break;
			case 5:
				exit(0);
				break;
			default:
				cout<<"\nInvalied choice...";
		}
	}
	getch();
	return(0);
}
