#include <stdio.h> ///for input output functions like printf, scanf
#include <stdlib.h>
#include <conio.h>
#include <string.h>  ///string operations
#include <dos.h>


/** Main function started */

void main()
{
    FILE *fp, *ft; /// file pointers
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
	    exit(0); /// exit from the program
	}
    }
    getch();
}
