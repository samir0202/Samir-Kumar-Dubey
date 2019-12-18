				//TYPING MASTER
#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>

void typ(void);
void tim(void);
void main()
{
	char d[10];
	int n;
	printf("Enter your name :");
	gets(d);
	system("cls");
	while(1)
	{
		printf("***************************************\n");
		printf("\t|| SAMIR'TYPING MASTER ||\n");
		printf("***************************************\n");
		printf("\t     /*MAIN MENU*/\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf(" 1. START TYPING\n");
		printf(" 2. EXIT\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\n==> PLEASE ENTER YOUR CHOICE(1-2):");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				typ();
				printf("\t\t\t\t\t\t\t\t\tThank You Mr.");
				printf("%s...",d);
				printf("\n*************************************************************************************");
				printf("**********************************************************************************\n");			
				getch();
				system("cls");
				break;
			case 2:
				exit(0);
				break;
			default :
				printf("   Invalied choice...MR %s",d);
				getch();
    			system("cls");
		}
	}
		system("cls");
}
//Function to typing
void typ(void)
{
	char a[1000];
	int i,alpha=0,digit=0,space=0,other=0;
	system("cls");
	printf("\n******************************************************************************");
	printf("*****************************************************************************************\n");
	printf("\t\t\t\t\t\t\t\t\t|| SAMIR'S TYPING MASTER ||\n ");
	printf("WELCOME TO THE TYPING MASTER...\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	tim();
	printf("\n*********************************************************************************");
	printf("**************************************************************************************\n");
	printf("\t\t\t\t\t\t\t  Enter multi string word and # press to end the typing\n");
	printf("*************************************************************************************");
	printf("**********************************************************************************\n");
	printf(" Start typing here...\n~~~~~~~~~~~~~~~~~~~~~\n");
	while(1)
	{
		 printf(" ");
		gets(a);
		for(i=0;a[i]!='\0';i++)
		{
			if(isalpha(a[i]))
			alpha++;
			else if(isdigit(a[i]))
			digit++;
	 		else if(isspace(a[i]))
			space++;
			else
			other++;
		}
		if(a[0]=='#')
		break;
	}
	printf("************************************************************************************");
	printf("***********************************************************************************\n");
	printf("\n Total length of string=%d",alpha+digit+space+other-1);
	printf("\n Total alphabet=%d\n",alpha);
	printf(" Total digit=%d\n",digit);
	printf(" Total space=%d\n",space);
	printf(" Total other charecter=%d\n",other-1);
	printf("\n************************************************************************************");
	printf("***********************************************************************************\n");
}
// function to system time
void tim(void)
{
    time_t s, val = 1;
    struct tm* current_time;
    s = time(NULL);
    current_time = localtime(&s);
    printf("TIME: ");
    printf("%02d:%02d:%02d",
           current_time->tm_hour,
           current_time->tm_min,
           current_time->tm_sec);
}
