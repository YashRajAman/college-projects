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

    /** structure that represent a student */
    struct student
    {
        char name[40]; //name of student
        int roll; // roll of student
        float fee; // fee of student
    };

    struct student s; /// structure variable creation

    char sname[40]; /// string to store name of the student

    long int recsize; /// size of each record of  student

    /** open the file in binary read and write mode
    * if the file student.DAT already exists then it open that file in read write mode
    * if the file doesn't exit it simply create a new copy
    */
    fp = fopen("student.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("student.DAT","wb+");
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
        gotoxy(30,8); /// move the cursor to postion 30, 10 from top-left corner
        printf("1. Add Record"); /// option for add record
        gotoxy(30,10);
        printf("2. List Records"); /// option for showing existing record
        gotoxy(30,12);
        printf("3. Modify Records"); /// option for editing record
        gotoxy(30,14);
        printf("4. list by roll"); /// option for deleting record
        gotoxy(30,16);
        printf("5. delete record"); /// exit from the program
	gotoxy(30,18);
        printf("5 : EXIT");
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
            clrscr();;
            rewind(fp); ///this moves file cursor to start of the file
            while(fread(&s,recsize,1,fp)==1)  /// read the file and fetch the record one record per fetch
            {
                printf("\n%s %d %.2f",s.name,s.roll,s.fee); /// print the name, roll,and fee
            getch();
            break;
			}
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
                        scanf("%s%d%f",s.name,&s.roll,&s.fee);
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
                remove("student.DAT"); /// remove the orginal file
                rename("Temp.dat","student.DAT"); /// rename the temp file to original file name
                fp = fopen("student.DAT", "rb+");
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
