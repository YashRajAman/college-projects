#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
union REGS in,out;
int gd=DETECT, gm;
int x,y,x1,y1,b;
   FILE *fp, *ft;

 //char another, choice;
void main1(void);
void show(void);
 void welcome(void);
void stud(void);
void fac(void);


	void main()
{

initgraph(&gd,&gm,"c:\\tc\\bgi");

main1();
getch();
closegraph();

getch();
}

    void terminate()
{
exit(0);
}
void show()
{
//int x,y,x1,y1,b;
in.x.ax=1;
int86(51,&in,&out);
}
void move(int *x,int *y,int *b)
{
in.x.ax=3;
int86(51,&in,&out);
*x=out.x.cx;
*y=out.x.dx;
*b=out.x.bx;
}
void main1()
{
char unm[20],user[20]="cimage";
char str[20],p[20]="vandana";
char str1[10] ;

int i=0;


//setcolor(CYAN);
rectangle(100,36,600,400);
setcolor(YELLOW);
rectangle(230,100,500,75);
rectangle(275,143,500,165);
rectangle(275,190,500,210);
rectangle(250,350,350,390); //login
outtextxy(280,370,"Login");
rectangle(400,350,500,390);    //exit
outtextxy(430,370,"Exit");
gotoxy(40,6);
printf("-:Login Screen:-");
gotoxy(23,10);
printf("Username:");
gotoxy(23,13);
printf("Password:");
gotoxy(36,10);
gets(unm);
if(unm==user)
clrscr();
gotoxy(36,10);
puts(unm);
gotoxy(36,13);
while(i<=6) {
str[i]=getch();
printf("*");
i++;
}
str[i]='\0' ;
i=0;

printf("\n");

rectangle(400,350,500,390);
show();
while(!kbhit())
{
move(&x,&y,&b);
if(b==1)
{
for(x1=250;x1<=350;x1++)
for(y1=350;y1<=390;y1++)
if(x==x1&&y==y1)
{

if(p[i]==str[i])

clrscr();
  welcome();


}
delay(100);
for(x1=400;x1<=500;x1++)
for(y1=350;y1<=390;y1++)
if(x==x1&&y==y1) {
terminate();      }

  }

}
}



    void welcome()
    {

int ch;
gotoxy(15,2);
 
printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\ WELCOME \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n\n\t\tSCHOOL MANAGEMENT SYSTEM ");

printf("\n\t\t1. SCHOOL\n\t\t2. FACULTY\n\t\t3. OTHERS\n\t\t4. EXIT");
printf("\n\t\t Enter your choice");
	fflush(stdin); /// flush the input buffer
	ch = getche(); /// get the input from keyboard

	switch(ch)
	{
	case '1':  /// if user press 1
	clrscr();
		 stud();
		break;
		case '2':  /// if user press 2
		clrscr();
			fac();

		break;
		case '3':  /// if user press 3
		printf("code not found for others");
		break;
		case '4':
			terminate();
			break;
		}

}

		void fac(void)
	{
		char another, choice;
		/** structure that represent a faculty */
    struct faculty
    {
	char name[40]; //name of faculty
       char post[20]; // post of faculty
	float salary; // salary of faculty
    };

    struct faculty f; /// structure variable creation

    char fname[40]; /// string to store name of the faculty

    long int recsize; /// size of each record of  faculty

    /** open the file in binary read and write mode
    * if the file faculty.DAT already exists then it open that file in read write mode
    * if the file doesn't exit it simply create a new copy
    */
    fp = fopen("faculty.DAT","rb+");
    if(fp == NULL)
    {
	fp = fopen("faculty.DAT","wb+");
	if(fp == NULL)
	{
	    printf("Connot open file");
	    exit(1);
	}
    }

    /// sizeo of each record i.e. size of structure variable s
    recsize = sizeof(f);

    /// infinite loop continues untile the break statement encounter
    while(1)
    {
       clrscr();
	gotoxy(30,8); /// move the cursor to postion 30, 10 from top-left corner
	printf("1. Add Record"); /// option for add record
	gotoxy(30,10);
	printf("2. List Records"); /// option for showing existing record
	gotoxy(30,12);
	printf("3. Modify Records"); /// option for editing record
	gotoxy(30,14);
	printf("4. delete record"); /// exit from the program
	gotoxy(30,16);
	printf("5 : EXIT");
	gotoxy(30,18);
	printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
	fflush(stdin); /// flush the input buffer
	choice  = getche(); /// get the input from keyboard
	switch(choice)
	{
	case '1':  /// if user press 1
	   clrscr();
	    fseek(fp,0,SEEK_END); /// search the file and move cursor to end of the file
	    /// here 0 indicates moving 0 distance from the end of the file

	    another = 'y';
	    while(another == 'y')  /// if user want to add another record
	    {
		printf("\nEnter name: ");
		scanf("%s",f.name);
		printf("\nEnter post: ");
		scanf("%s", f.post);
		printf("\nEnter salary: ");
		scanf("%f", &f.salary);

		fwrite(&f,recsize,1,fp); /// write the record in the file

		printf("\nAdd another record(y/n) ");
		fflush(stdin);
		another = getche();
	    }
	    break;
	case '2':
	    clrscr();;
	    rewind(fp); ///this moves file cursor to start of the file
	    while(fread(&f,recsize,1,fp)==1)  /// read the file and fetch the record one record per fetch
	    {
		printf("\n%s %s %.2f",f.name,f.post,f.salary); /// print the name ,post and salary
	   } getch();
	    break;

	case '3':  /// if user press 3 then do editing existing record
	    clrscr();
	    another = 'y';
	    while(another == 'y')
	    {
		printf("Enter the faculty name to modify: ");
		scanf("%s", fname);
		rewind(fp);
		while(fread(&f,recsize,1,fp)==1)  /// fetch all record from file
		{
		    if(strcmp(f.name,fname) == 0)  ///if entered name matches with that in file
		    {
			printf("\nEnter new name,post and salary: ");
			scanf("%s%s%f",f.name,f.post,&f.salary);
			fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
			fwrite(&f,recsize,1,fp); /// override the record
			break;
		    }
		}
		printf("\nModify another record(y/n)");
		fflush(stdin);
		another = getche();
	    }
	    break;
	case '4':
	    clrscr();
	    another = 'y';
	    while(another == 'y')
	    {
		printf("\nEnter name of faculty to delete: ");
		scanf("%s",fname);
		ft = fopen("Temp.dat","wb");  /// create a intermediate file for temporary storage
		rewind(fp); /// move record to starting of file
		while(fread(&f,recsize,1,fp) == 1)  /// read all records from file
		{
		    if(strcmp(f.name,fname) != 0)  /// if the entered record match
		    {
			fwrite(&f,recsize,1,ft); /// move all records except the one that is to be deleted to temp file
		    }
		}
		fclose(fp);
		fclose(ft);
		remove("faculty.DAT"); /// remove the orginal file
		rename("Temp.dat","faculty.DAT"); /// rename the temp file to original file name
		fp = fopen("facultty.DAT", "rb+");
		printf("Delete another record(y/n)");
		fflush(stdin);
		another = getche();
	    }
	    break;
	case '5':
	    fclose(fp);  /// close the file
	    clrscr();
	    welcome();
	    //exit(0); /// exit from the program
	}
    }
  }


	void stud()
	{

		struct student
    {
	char name[40]; //name of student
	int roll; // roll of student
	float fee; // fee of student
    };

      struct student s;
    char sname[40]; /// string to store name of the student
 char another,choice;
    long int recsize; /// size of each record of  student

    /** open the file in binary read and write mode
    * if the file student.DAT already exists then it open that file in read write mode
    * if the file doesn't exit it simply create a new copy **/

    fp = fopen("student1.DAT","rb+");
    if(fp == NULL)
    {
	fp = fopen("student1.DAT","wb+");
	if(fp == NULL)
	{
	    printf("Connot open file");
	    exit(1);
	}
    }

    /// sizeo of each record i.e. size of structure variable s
    recsize = sizeof(s);

    /// infinite loop continues untile the break statement encounter
    while(1)
    {
       clrscr();
	gotoxy(30,10); /// move the cursor to postion 30, 10 from top-left corner
	printf("1. Add Record"); /// option for add record
	gotoxy(30,12);
	printf("2. List Records"); /// option for showing existing record
	gotoxy(30,14);
	printf("3. Modify Records"); /// option for editing record
	gotoxy(30,16);
	printf("4. Delete Records"); /// option for deleting record
	gotoxy(30,18);
	printf("5. Exit"); /// exit from the program
	gotoxy(30,20);
	printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
	fflush(stdin); /// flush the input buffer
	choice  = getche(); /// get the input from keyboard
	switch(choice)
	{
	case '1':  /// if user press 1
	   clrscr();
	    fseek(fp,0,SEEK_END); /// search the file and move cursor to end of the file
	    /// here 0 indicates moving 0 distance from the end of the file

	    another = 'y';
	    while(another == 'y')  /// if user want to add another record
	    {
		printf("\nEnter name: ");
		scanf("%s",s.name);
		printf("\nEnter roll: ");
		scanf("%d", &s.roll);
		printf("\nEnter fee: ");
		scanf("%f", &s.fee);

		fwrite(&s,recsize,1,fp); /// write the record in the file

		printf("\nAdd another record(y/n) ");
		fflush(stdin);
		another = getche();
	    }
	    break;
	case '2':
		clrscr();
	    fseek(fp,0,SEEK_SET); ///this moves file cursor to start of the file
//	    printf("%d",ftell(fp));
	    while(fread(&s,recsize,1,fp)==1)  /// read the file and fetch the record one record per fetch
	    {
		printf("\n %s %d %.2f",s.name,s.roll,s.fee); /// print the name, roll,and fee
	    }
	    getch();
	    break;

	case '3':  /// if user press 3 then do editing existing record
	    clrscr();
	    another = 'y';
	    while(another == 'y')
	    {
		printf("Enter the student name to modify: ");
		scanf("%s", sname);
		rewind(fp);
		while(fread(&s,recsize,1,fp)==1)  /// fetch all record from file
		{
		    if(strcmp(s.name,sname) == 0)  ///if entered name matches with that in file
		    {
			printf("\nEnter new name,roll and fee: ");
			scanf("%s %d %f",s.name,&s.roll,&s.fee);
			fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
			fwrite(&s,recsize,1,fp); /// override the record
			break;
		    }
		}
		printf("\nModify another record(y/n)");
		fflush(stdin);
		another = getche();
	    }
	    break;
	case '4':
	    clrscr();
	    another = 'y';
	    while(another == 'y')
	    {
		printf("\nEnter name of student to delete: ");
		scanf("%s",sname);
		ft = fopen("Temp.dat","wb");  /// create a intermediate file for temporary storage
		rewind(fp); /// move record to starting of file
		while(fread(&s,recsize,1,fp) == 1)  /// read all records from file
		{
		    if(strcmp(s.name,sname) != 0)  /// if the entered record match
		    {
			fwrite(&s,recsize,1,ft); /// move all records except the one that is to be deleted to temp file
		    }
		}
		fclose(fp);
		fclose(ft);
		remove("student1.DAT"); /// remove the orginal file
		rename("Temp.dat","student1.DAT"); /// rename the temp file to original file name
		fp = fopen("student1.DAT", "rb+");
		printf("Delete another record(y/n)");
		fflush(stdin);
		another = getche();
	    }
	    break;
	case '5':
	    fclose(fp);  /// close the file
	    clrscr();
	    welcome();
	    //exit(0); /// exit from the program
	    break;
	}
	}
 }


