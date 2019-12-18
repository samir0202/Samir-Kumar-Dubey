/*
	Name: Expance Manage of Home
	Copyright: Resurved
	Author: Samir Kumar Dubey
	Date: 09-10-18 18:09
	Description: This Software makes provide to maintain expance of home and house.
	Output Size: 156.453125 KiB
*/

#include<stdio.h>
#include<stdlib.h>
struct home
{
	int rante;
	int ebill;
	int milk;
	int kirana;
	int medisin;
	int study;
	int veg;
	int other;
	char date[14];
	long int total;
};
void input(void);
void total(void);
void output(void);
void main()
{
	int n;
	while(1)
{
printf("************************************\n");
printf("    || HOME EXPENSE MANAGMENT ||\n");
printf("************************************\n");
printf("------------------------------------\n");
printf("          |* MAIN MENU *|\n");
printf("------------------------------------\n");
printf("  1. HOME EXPENSE ENTRY\n");
printf("  2. DISPLAY HOME EXPENSE\n");
printf("  3. DISPLAY TOAL EXPENCE\n");
printf("  4. EXIT\n");
printf("------------------------------------\n");
printf("\n  PLEASE ENTER YOUR CHOICE(1-3):");
scanf("%d",&n);
switch(n)
{
		case 1:
		input();
		break;
		case 2:
		output();
		break;
		case 3:
		total();
		break;
		case 4:
		exit(0);
		break;
		default :
		printf("  INVALIED CHOICE...");
		printf("\n------------------------------------\n");
		getch();
		system("cls");
}
}
}
void input(void)
{
	FILE *fp;
	struct home s;
	fp=fopen("Hexpance.db","ab");
	if(fp==NULL)
	{
		printf("Unable to open/creat student database");
		getch();
		return;
	}
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("   || HOME EXPENSE MANAGMENT ||\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("----------------------------------\n");
	printf("\t|* ENTRY WIZARZ *|\n");
	printf("----------------------------------\n");
	printf("\n ENTER DATE(DD-MM-YY) :");
	scanf("%s",&s.date);
	printf("\n ENTER HOUSE RANTE EXPENSE:");
	scanf("%d",&s.rante);
	printf("\n ENTER E-BILL EXPENSE:");
	scanf("%d",&s.ebill);
	printf("\n ENTER MILK EXPENSE:");
	scanf("%d",&s.milk);
	printf("\n ENTER KIRANA EXPENSE:");
	scanf("%d",&s.kirana);
	printf("\n ENTER VEGITABLE EXPENSE:");
	scanf("%d",&s.veg);
	printf("\n ENTER TEACHING EXPENSE:");
	scanf("%d",&s.study);
	printf("\n ENTER MEDICINE EXPENSE:");
	scanf("%d",&s.medisin);
	printf("\n ENTER OTHER EXPENSE:");
	scanf("%d",&s.other);
	fwrite(&s,sizeof(s),1,fp);
	printf("\n RECORD SUCCESSFULLY SAVED...");
	printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	getch();
	system("cls");
	fclose(fp);
}
void output()
{
	FILE *fp;
	struct home s;
	fp=fopen("Hexpance.db","rb");
	if(fp==NULL)
	{
		printf("Unable to open/creat student database");
		getch();
		return;
	}
	system("cls");
	printf("***********************************************************************************************************************************************************************\n");
	printf("\t\t\t\t\t\t\t\t   || HOME EXPENSE MANAGMENT ||\n");
	printf("***********************************************************************************************************************************************************************\n");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("     	  DATE		!    HOME RANTE         E-BILL        MILK        KIRANA       MEDICINE	     VEGITABLE		TEACHING	OTHER     !      TOTAL\n");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		s.total=s.rante+s.ebill+s.milk+s.kirana+s.medisin+s.other+s.study+s.veg;
		printf("    	%s	!	%d             %d          %d         %d      	  %d		   %d		  %d		 %d	  !	 %ld   \n",s.date,s.rante,s.ebill,s.milk,s.kirana,s.medisin,s.veg,s.study,s.other,s.total);
	}
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("-------------------------------------------------------------------Programmer Name :SAMIR DUBEY------------------------------------------------------------------------\n");
	getch();
	system("cls");
	fclose(fp);
}

void total(void)
{
	long int r=0,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;
	FILE *fp;
	struct home s;
	fp=fopen("Hexpance.db","rb");
	while(fread(&s,sizeof(s),1,fp)==1)
	{
	
	r=r+s.rante;
	a=a+s.ebill;
	b=b+s.kirana;
	c=c+s.medisin;
	d=d+s.study;
	e=e+s.veg;
	f=f+s.milk;
	g=g+s.other;
	h=r+a+b+c+d+e+f+g;
	}
		system("cls");
		printf("***************************************\n");
		printf("     || HOME EXPENSE MANAGMENT ||\n");
		printf("***************************************\n");
		sleep(1);
		printf(" ==> TOTAL HOME EXPENCE : %ld\n",r);
		printf("---------------------------------------\n");
		sleep(1);
		printf(" ==> TOTAL E-BILL EXPENCE : %ld\n",a);
		printf("---------------------------------------\n");
		sleep(1);
		printf(" ==> TOTAL MEDISIN EXPENCE : %ld\n",c);
		printf("---------------------------------------\n");
		sleep(1);
		printf(" ==> TOTAL MILK EXPENCE : %ld\n",f);
		printf("---------------------------------------\n");
		sleep(1);
		printf(" ==> TOTAL KIRANA EXPENCE : %ld\n",b);
		printf("---------------------------------------\n");
		sleep(1);
		printf(" ==> TOTAL STUDY EXPENCE : %ld\n",d);
		printf("---------------------------------------\n");
		sleep(1);
		printf(" ==> TOTAL VEG EXPENCE : %ld\n",e);
		printf("---------------------------------------\n");
		sleep(1);
		printf(" ==> TOTAL OTHER EXPENCE : %ld\n",g);
		sleep(2);
		printf("+++++++++++++++++++++++++++++++++++++++\n\n");
		printf(" ==) [NET EXPENCE NOW A DAY :%ld]\n\n",h);
		printf("+++++++++++++++++++++++++++++++++++++++\n\n");
		sleep(1);
		printf("---------PR.Name :SAMIR DUBEY----------\n");
		getch();
		system("cls");
		fclose(fp);
}
