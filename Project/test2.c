#include <stdio.h>
#include <conio.h>
#include <process.h>

int sa_ac_number;		//For reading and writing account number for saving account from file
int fd_ac_number;		//For reading and writing account number for fixed deposit from file
int bal;		//For modifying value of available balance in saving account
int d,m,y;	//For inputing date

struct saving_account
{
	char name[30];
	int acc_no;
	long int balance;
}sa;	//data structure for saving account record

struct fixed_deposit
{
	char name[30];
	int acc_no;
	long int pa,ma;
	int term;
	int dd,mm,yy;
	float rate;
}fd;	//data structure for fixed deposit record

void sa_write();		//Function to add new saving account
void sa_read();			//Function to display saving account records from file
void sa_modify(int acc);	//Function to modify balance for saving account
void sa_delete();		//Function to delete saving account
void sa_cd();			//Function to deposit cash in saving account
void sa_cw();			//Function to withdraw cash in saving account

void fd_write();					//function to add new fixed deposit
void fd_read();						//function to display fixed deposit record from file
void fd_delete();					//function to delete fixed deposit
int fd_interest(long int a,int t);	//Function to calculate interest of fixed deposit

void new_customer();		//function for creating new customer
void existing_customer();	//function for existing customer
void read_ac();			//function to read account number from file
void write_ac();		//function to write account number in file
void saving_account();	//function to choose options for saving account
void fixed_deposit();	//function to choose option from fixed deposit
void password();	//function for checking password

int fdacc,saacc;               //to delete fd records
long int fdsize= sizeof(fd);  //to get size of fixed deposit structure
long int sasize= sizeof(sa);	////to get size of saving account structure
char an='y';                         //for get a choice in Yes or No format

int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	int i,ch;	//For validation and choice
	FILE *fp,*ft;
	system("cls");
		d=m=32;
	i= 0;
	password();
	while(d>31)
	{
		if(i==1)
			printf("You entered invalid date\n");
		printf("Enter date: ");
		scanf("%d",&d);
		i++;
	}
	i= 0;
	while(m>12)
	{
		if(i==1)
			printf("You entered invalid month\n");
		printf("Enter month: ");
		scanf("%d",&m);
		i++;
	}
	printf("Enter year: ");
	scanf("%d",&y);
	ft= fopen("sa.dat","rb+");	//open sa.dat file in read write (binary) mode if file exists
	fp= fopen("fd.dat","rb+");  //open fd.dat file in read write (binary) mode if file exists

	if(fp==NULL)
	{
		printf("\nFile Can't Open for Fixed Deposit");
		printf("\nDo you want to create file for fixed deposit (Y/N): ");
		fflush(stdin); //To empty buffer to have fresh entry
		an=getche();
		if(an=='y' || an=='Y')
		{
			fp=fopen("fd.dat","wb+"); //file created in write read (binary) mode
			printf("\nFile Created Successfully...\n");
		}
		else
		{
			printf("\nYour choice is No so file is not created... ");
			printf("\nIf you want to create file press enter and run your program again.........");
			exit (0);
		}
	}

	if(ft==NULL)
	{
		printf("\nFile Can't Open for Saving account");
		printf("\nDou you want to create file for saving account (Y/N) ");
		fflush(stdin);
		an=getche();
		if(an=='y' || an=='Y')
		{
			fp=fopen("sa.dat","wb+");
			printf("\nFile Created Successfully...\n");
		}
		else
		{
			printf("\nYour choice is No so file is not created... ");
			printf("\nIf you want to create file press enter and run your program again.........");
			exit (0);
		}
	}
	fclose(fp);
	fclose(ft);

	while(1)
	{
		system("cls");
		printf("\nEnter 1 for New Customer");
		printf("\nEnter 2 for Existing Customer");
		printf("\nEnter 0 to Exit");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		read_ac();
		switch(ch)
		{
			case 1:
				new_customer();
				write_ac();
				break;
			case 2:
				existing_customer();
				break;
			case 0:
				exit(0);
			default:
				printf("Wrong choice\n");
		}
	}
	return 0;
}

void password()
{
	char usr1[25]= {'a','d','m','i','n'};
	char pwd1[25]= {'a','d','m','i','n'};
	char usr2[25]= {'c','a','s','e'};
	char pwd2[25]= {'c','a','s','e'};
	char usr[25],pwd[25],ch;
	int i;
	while(1)
	{
		printf("Login name: ");
		fflush(stdin);
		gets(usr);
		printf("Password: ");
		i= 0;
		while(1)
		{
			ch= getch();
			if(ch==13)
				break;
			else
			{
				printf("*");
				pwd[i]= ch;
				i++;
			}
		}
		pwd[i]= '\0';

		if(strcmp(usr,usr1)==0)
		{
			if(strcmp(pwd,pwd1)==0)
			{
				printf("\nWELCOME TO BANK MANAGEMENT SYSTEM\n");
				break;
			}
			else
				printf("\nLogin name or password is incorrect. Try again\n");
		}
		else if(strcmp(usr,usr2)==0)
		{
			if(strcmp(pwd,pwd2)==0)
			{
				printf("\nWELCOME TO BANK MANAGEMENT SYSTEM\n");
				break;
			}
			else
				printf("\nLogin name or password is incorrect\n");
		}
		else
			printf("\nLogin name or password is incorrect. Tray again\n");
	}
}

void new_customer()
{
	int ch;
	system("cls");
	printf("---***NEW CUSTOMER***---\n");
	do
	{
		printf("\nEnter 1 for Saving Account");
		printf("\nEnter 2 for Fixed Deposit");
		printf("\nEnter 0 for main menu");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				sa_write();
				break;
			case 2:
				fd_write();
				break;
			case 0:
				break;
			default:
				printf("\nWrong choice");
		}
	}while(ch>2&&ch<0);
	system("cls");
}

void existing_customer()
{
	int ch;
	system("cls");
	printf("---***EXISTING CUSTOMER***---\n");
	do
	{
		printf("\nEnter 1 for Saving Account");
		printf("\nEnter 2 for Fixed Deposit");
		printf("\nEnter 0 for main menu");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				saving_account();
				break;
			case 2:
				fixed_deposit();
				break;
			case 0:
				break;
			default:
				("\nWrong Choice");
		}
	}while(ch>2&&ch<0);
	system("cls");
}

void fd_write()
{
	FILE *fp;
	system("cls");
	printf("---***NEW FIXED DEPOSIT***---\n");
	fp= fopen("fd.dat","rb+");
	fd.dd= d;
	fd.mm= m;
	fd.yy= y;
	printf("\nDate: %d-%d-%d\n",fd.dd,fd.mm,fd.yy);
	printf("Enter Name: ");
	fflush(stdin);
	gets(fd.name);
	fd_ac_number++;
	fd.acc_no= fd_ac_number;
	printf("Account number: %d\n",fd.acc_no);
	printf("Enter Principal Amount: ");
	scanf("%ld",&fd.pa);
	printf("Enter Time Period in year: ");
	scanf("%d",&fd.term);
	//Check Rate of Interest
	if(fd.term<=1)
		fd.rate= 0.000000;
	else if(fd.term>=2 && fd.term<=5)
		fd.rate= 5.000000;
	else if(fd.term>=6 && fd.term<=10)
		fd.rate= 6.500000;
	else if(fd.term>=11 && fd.term<=15)
		fd.rate= 7.500000;
	else
		fd.rate= 8.250000;
	fd.ma= fd_interest(fd.pa,fd.term);
	fseek(fp,0,SEEK_END);          //locate file pointer to end of file (EOF)
	fwrite(&fd,fdsize,1,fp);          //write one sturcture data into file
	fclose(fp);
	printf("Account created Successfully\n");
	printf("Press any key to continue");
	getch();
	system("cls");
}

void fd_read()
{
	FILE *ft;
	system("cls");
	printf("---***FIXED DEPOSIT RECORDS***---\n");
	ft= fopen("fd.dat","rb+");
	rewind(ft);                            //locate file pointer beginning of file (BOF)
	while(fread(&fd,fdsize,1,ft)==1)     //read one structure data form file
	{
		printf("\nDate: %d-%d-%d\n",fd.dd,fd.mm,fd.yy);
		printf("Account number: %d\n",fd.acc_no);
		printf("Name: %s\n",fd.name);
		printf("Principal Amount: %ld\n",fd.pa);
		printf("Time Period: %d\n",fd.term);
		printf("Rate of Interest: %.2f\n",fd.rate);
		printf("Maturity Amount: %ld\n\n",fd.ma);
	}
	fclose(ft);
	printf("Press any key to continue");
	getch();
	system("cls");
}

void fd_delete()
{
	FILE *tmp1;
	FILE *fp;
	int i; //For validation
	system("cls");
	printf("---***CLOSE FIXED DEPOSIT***---\n\n");
	tmp1= fopen("temp1.dat","w");          //open a temporary file in write mode
	fp= fopen("fd.dat","rb+");
	i= 0;
	do
	{
		if(i==1)
		{
			printf("You entered invalid account number\n");
			i= 0;
		}
		i++;
		printf("Enter Account number: ");
		scanf("%d",&fdacc);
	}while(fdacc>fd_ac_number);
	rewind(fp);
	while(fread(&fd,fdsize,1,fp)==1)              //read record by record
	{
		if(fdacc!=fd.acc_no)
		{
			fwrite(&fd,fdsize,1,tmp1);        //write all data except match record
		}
	}
	fclose(fp);
	fclose(tmp1);
	remove("fd.dat");		//delete the original file
	rename("temp1.dat","fd.dat");	//rename temp1 file to original file
	printf("\nRecord Deleted Successfully");
	printf("\nPress any key to continue");
	getch();
	system("cls");
}

int fd_interest(long int a,int t)
{
	if(t<=1)
		return a;
	else if(t>=2 && t<=5)
		return (a+((a*t*5.00)/100));	//5.00%
	else if(t>=6 && t<=10)
		return (a+((a*t*6.50)/100));	//6.50%
	else if(t>=11 && t<=15)
		return (a+((a*t*7.50)/100));	//7.50%
	else
		return (a+((a*t*8.25)/100));	//8.25%
}

void read_ac()
{
	FILE *ft,*fy,*fs,*fx;
	fs= fopen("sa_acc_no.txt","r");
	ft= fopen("fd_acc_no.txt","r");

	if(fs==NULL)
	{
		fclose(fs);
		fx= fopen("sa_acc_no.txt","w+");
		fprintf(fx,"0");
		fclose(fx);
	}
	else
	{
		fscanf(fs,"%d",&sa_ac_number);
		fclose(fs);
	}

	if(ft==NULL)
	{
		fclose(ft);
		fy= fopen("fd_acc_no.txt","w+");
		fprintf(fy,"0");
		fclose(fy);
	}
	else
	{
		fscanf(ft,"%d",&fd_ac_number);
		fclose(ft);
	}
}

void write_ac()
{
	FILE *fp,*ft;
	fp= fopen("fd_acc_no.txt","w");
	ft= fopen("sa_acc_no.txt","w");
	fprintf(fp,"%d",fd_ac_number);
	fprintf(ft,"%d",sa_ac_number);
	fclose(fp);
	fclose(ft);
}

void sa_write()
{
	FILE *fp;
	system("cls");
	printf("---***NEW SAVING ACCOUNT***---\n\n");
	fp= fopen("sa.dat","rb+");
	printf("Enter Name: ");
	fflush(stdin);		//to clear input buffer's to get a fresh value for the next input
	gets(sa.name);
	sa_ac_number++;
	sa.acc_no= sa_ac_number;
	printf("Account number: %d\n",sa.acc_no);
	sa.balance= 0;
	bal= sa.balance;
	fseek(fp,0,SEEK_END);		//locate file pointer to end of file (EOF)
	fwrite(&sa,sasize,1,fp);	//write one structure data into file
	fclose(fp);
	printf("Account created Successfully\n");
	printf("Press any key to continue");
	getch();
	system("cls");
}

void sa_read()
{
	FILE *ft;
	system("cls");
	printf("---***SAVING ACCOUNT RECORDS***---\n");
	ft= fopen("sa.dat","rb+");
	rewind(ft);                            //locate file pointer beginning of file (BOF)
	while(fread(&sa,sasize,1,ft)==1)     //read one structure data form file
	{
		printf("\nAccount number: %d\n",sa.acc_no);
		printf("Name: %s\n",sa.name);
		printf("Current Balance: %d\n",sa.balance);
	}
	fclose(ft);
	printf("Press any key to continue");
	getch();
	system("cls");
}

void sa_modify(int acc)
{
	FILE *fp;
	fp= fopen("sa.dat","rb+");
	rewind(fp);
	while(fread(&sa,sasize,1,fp)==1)
	{
		if(acc==sa.acc_no)
		{
			sa.balance= sa.balance+bal;
			fseek(fp,-sasize,SEEK_CUR);        //locate file pointer to the current location in file
			fwrite(&sa,sizeof(sa),1,fp);            //write one sturcture data into file
			break;
		}
	}
	fclose(fp);
}

void sa_delete()
{
	FILE *fp,*tmp2;
	int i;
	system("cls");
	printf("---***CLOSING SAVING ACCOUNT***---\n\n");
	fp= fopen("sa.dat","rb+");
	tmp2= fopen("temp2.dat","w");          //open a temporary file in write mode
	i= 0;
	do
	{
		if(i==1)
		{
			printf("You entered invalid account number\n");
			i= 0;
		}
		i++;
		printf("Enter Account number: ");
		scanf("%d",&saacc);
	}while(saacc>sa_ac_number);
	rewind(fp);
	while(fread(&sa,sasize,1,fp)==1)
	{
		if(saacc!=sa.acc_no)
		{
			fwrite(&sa,sasize,1,tmp2);
		}
	}
	fclose(fp);
	fclose(tmp2);
	remove("sa.dat");
	rename("temp2.dat","sa.dat");
	printf("\nRecord Deleted Successfully");
	printf("\nPress any key to continue");
	getch();
	system("cls");
}

void saving_account()
{
	int ch;
	system("cls");
	printf("---***SAVING ACCOUNT***---\n");
	do
	{
		printf("\nEnter 1 for Cash Deposit");
		printf("\nEnter 2 for Cash Withdrawal");
		printf("\nEnter 3 for Display");
		printf("\nEnter 4 to Delete an account");
		printf("\nEnter 0 for main menu");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				sa_cd();
				break;
			case 2:
				sa_cw();
				break;
			case 3:
				sa_read();
				break;
			case 4:
				sa_delete();
				break;
			case 0:
				break;
		}
	}while(ch>3&&ch<0);
}

void fixed_deposit()
{
	int ch;
	system("cls");
	printf("---***FIXED DEPOSIT***---\n");
	do
	{
		printf("\nEnter 1 for Delete");
		printf("\nEnter 2 for Display");
		printf("\nEnter 0 for main menu");
		printf("\nEnter choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				fd_delete();
				break;
			case 2:
				fd_read();
				break;
			case 0:
				break;
		}
	}while(ch>1&&ch<0);
}

void sa_cd()
{
	int i;
	system("cls");
	printf("---***SAVING ACCOUNT CASH DEPOSIT***---\n\n");
	i= 0;
	do
	{
		if(i==1)
		{
			printf("You entered invalid account number\n");
			i= 0;
		}
		i++;
		printf("Enter account number: ");
		scanf("%d",&saacc);
	}while(saacc>sa_ac_number);
	printf("Enter amount to be deposited: ");
	scanf("%ld",&bal);
	sa_modify(saacc);
	printf("Cash Deposited Successfully\n");
	printf("Press any key to continue");
	getch();
	system("cls");
}

void sa_cw()
{
	int i;
	system("cls");
	printf("---***SAVING ACCOUNT CASH WITHDRAWAL***---\n\n");
	i= 0;
	do
	{
		if(i==1)
		{
			printf("You entered invalid account number\n");
			i= 0;
		}
		i++;
		printf("Enter account number: ");
		scanf("%d",&saacc);
	}while(saacc>sa_ac_number);
	printf("Enter amount to withdrawal: ");
	scanf("%d",&bal);
	if(bal>sa.balance)
	{
		printf("You don't have sufficient balance\n");
	}
	else
	{
	bal= bal*(-1);
	sa_modify(saacc);
	printf("Cash Withdrawaled Successfully\n");
	}
	printf("Press any key to continue");
	getch();
	//system("cls");
}

