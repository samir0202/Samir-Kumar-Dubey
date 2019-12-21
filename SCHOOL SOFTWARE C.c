#include<stdio.h>
#include<stdlib.h>
struct student
{
	int roll;
	char name[30];
	char cs[30];
	int fee;
};
struct payment
{
	int roll;
	char idate[30];
	int amt;
};
void admin(void);
void payentry(void);
void dispall(void);
void dispone(void);
void paydisp(void);
void main()
{
	int n;
	while(1)
{
printf("\t\t\tMAIN MENU\n\n");
printf("\t\t1.Admission entry\n");
printf("\t\t2.Fee payment entry\n");
printf("\t\t3.Display all enrolled student\n");
printf("\t\t4.Display record of a student by roll\n");
printf("\t\t5.Display payment history\n");
printf("\t\t6.Exit\n");
printf("\n\t\tEnter choice(1-6):");
scanf("%d",&n);
switch(n)
{
		case 1:
		admin();
		break;
		case 2:
		payentry();
		break;
		case 3:
		dispall();
		break;
		case 4:
		dispone();
		break ;	
		case 5:
		paydisp();	
		break;
		case 6:
		exit(0);
		break;
		default :
			printf("invalied choice...");
}
}
}
void admin(void)
{
	FILE *fp;
	struct student s;
	fp=fopen("Student.db","ab");
	if(fp==NULL)
	{
		printf("Unable to open/creat student database");
		getch();
		return;
	}
	printf("\n\t\tEnter Roll,Name,Course and Fee:");
	scanf("%d%s%s%d",&s.roll,s.name,s.cs,&s.fee);
	fwrite(&s,sizeof(s),1,fp);
	printf("\t\tRecord successfully saved...");
	getch();
	system("cls");
	fclose(fp);
}
void dispall()
{
		FILE *fp;
	struct student s;
	fp=fopen("Student.db","rb");
	if(fp==NULL)
	{
		printf("Unable to open/creat student database");
		getch();
		return;
	}
	printf("\n\t\tRoll\tName\tCourse\tFee\n");
	printf("\t\t---------------------------------------\n");
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		printf("\t\t%d\t%s\t%s\t%d\n",s.roll,s.name,s.cs,s.fee);
	}
	getch();
	system("cls");
	fclose(fp);
}
void payentry(void)
{
	FILE *fp;
	struct payment p;
	fp=fopen("Payment.db","ab");
	if(fp==NULL)
	{
		printf("Unable to open/creat student database");
		getch();
		return;
	}
	printf("\n\t\tEnter Roll,Date,Amount:");
	scanf("%d%s%d",&p.roll,p.idate,&p.amt);
	fwrite(&p,sizeof(p),1,fp);
	printf("\t\tRecord successfully saved...");
	
	getch();
	system("cls");
	fclose(fp);
}
void paydisp(void)
{
		FILE *fp;
	struct payment p;
	fp=fopen("Payment.db","rb");
	if(fp==NULL)
	{
		printf("Unable to open/creat student database");
		getch();
		return;
	}
	printf("\t\tRoll  \tDate\t\tAmount\n");
	printf("\t\t---------------------------------\n");
	while(fread(&p,sizeof(p),1,fp)==1)
	{
	printf("\t\t%d\t%s\t%d\n",p.roll,p.idate,p.amt);
	}
	
	getch();
	system("cls");
	fclose(fp);
}
void dispone(void)
{
	FILE *fp;
	struct student s;
	int r,found=0;
	fp=fopen("Student.db","rb");
	if(fp==NULL)
	{
		printf("Unable to open student database... ");
		getch();
		return;
	}
	printf("\n\t\tEnter roll:");
	scanf("%d",&r);
	printf("\n\t\tRoll\tName\tCourse\tFee\n");
	printf("\t\t------------------------------\n");
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		if(r==s.roll)
		{
		printf("\t\t%d\t%s\t%s\t%d\n",s.roll,s.name,s.cs,s.fee);	
		found=1;
		}
	}
	if(found==0)
	{
	printf("\t\tRoll does not exit....");
	}
		getch();
	system("cls");
	fclose(fp);
}
