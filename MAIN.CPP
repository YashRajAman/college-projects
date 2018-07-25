#include <iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<ctype.h>
#include<dos.h>


class iodet
{
   public:
   int c, i;
   fstream sout;

   typedef struct student
   {
	long unsigned int roll, fee;
	char name[30];
   }student;

   typedef struct faculty
   {
	long unsigned int salary;
	unsigned int id;
	char name[30], post[20];
   }faculty;
};

class siodet:protected iodet
{
	public:
		student stud;
	void sidet()
	{
		sout.open("sdb.dat", ios::app|ios::binary);
		cout<<"Enter the Name of the student.. - ";
		fflush(stdin);
		gets(stud.name);
		sout<<stud.name<<"\t";
		cout<<"Enter the roll of student .. - ";
		cin>>stud.roll;
		sout<<stud.roll<<"\t";
		cout<<"Enter the fee of the student.. - ";
		cin>>stud.fee;
		sout<<stud.fee<<"\n";
		sout.close();
	}
	void sodet()
	{
		student s;
		c= 1;
		fstream rd;
		rd.open("sdb.dat", ios::in|ios::binary);
		while(!rd.eof())
		{
			rd>>s.name;
			rd>>s.roll;
			rd>>s.fee;
			if(rd.eof())
				break;
			cout<<c<<". "<<s.name<<"\t"<<s.roll<<"\t"<<s.fee;
			c++;
			fflush(stdout);
		}
		rd.close();
	}

	void sdelete()
	{
		int roll;
		cout<<endl<<"Enter roll to delete the record : ";
		cin>>roll;
		fstream temp;
		temp.open("temp.dat", ios::out|ios::binary);
		student s;
		fstream rd;
		rd.open("sdb.dat", ios::in|ios::binary);

		while(!rd.eof())
		{
			rd>>s.name;
			rd>>s.roll;
			rd>>s.fee;
			if(rd.eof())
				{
		   //	cout<<"Nothing to delete.\n ";
				break;
				}
			if(roll==s.roll && !rd.eof())
				{
				goto a;
				}
			temp<<s.name<<"\t";
			temp<<s.roll<<"\t";
			temp<<s.fee<<"\n";
			a:
			fflush(stdout);
		 }
		rd.close(); temp.close();
		remove("sdb.dat");
		rename("temp.dat", "sdb.dat");
		cout<<"Deletion done\n";
	}
};

class fiodet:protected iodet
{
	public:
	faculty fac;
	fstream fout;
	void fidet()
	{
		fout.open("fdb.dat", ios::app|ios::binary);
		cout<<"\nEnter the Name of the faculty.. - ";
		fflush(stdin);
		gets(fac.name);
		cout<<"Enter the id of faculty .. - ";
		cin>>fac.id;
		cout<<"Enter the post of the faculty..- ";
		fflush(stdin);
		cin>>fac.post;
		cout<<"Enter the salary of the faculty..- ";
		fflush(stdin);
		cin>>fac.salary;
		fout<<fac.id<<"\t";
		fout<<fac.name<<"\t";
		fout<<fac.post<<"\t";
		fout<<fac.salary<<"\n";
		fout.close();
	}
	void fodet()
	{
	 faculty f;
	 c=1;
	 fstream rd;
	 rd.open("fdb.dat", ios::in|ios::binary);
	 while(!rd.eof())
	 {
	   rd>>f.id;
	   fflush(stdin);
	   rd>>f.name;
	   rd>>f.post;
	   rd>>f.salary;
	   if(rd.eof())
			break;
	   cout<<endl<<c<<". "<<f.id<<"\t"<<f.name<<"\t"<<f.post<<"\t"<<f.salary;
	   c++;
	   fflush(stdout);
	 }
	rd.close();
	}

	void fdelete()
	{
		int id;
		cout<<endl<<"\nEnter id to delete the record : ";
		cin>>id;
		fstream temp, rd;
		temp.open("temp.dat", ios::out|ios::binary);
		faculty f;
		rd.open("fdb.dat", ios::in|ios::binary);

		while(!rd.eof())
		{
			rd>>f.id;
			rd>>f.name;
			rd>>f.post;
			rd>>f.salary;
			if(rd.eof())
				break;
			if(id==f.id && !rd.eof())
				{
				goto a;
				}
			temp<<f.id<<"\t";
			temp<<f.name<<"\t";
			temp<<f.post<<"\t";
			temp<<f.salary<<"\n";
			a:
			fflush(stdout);
		}
		rd.close(); temp.close();
		remove("fdb.dat");
		rename("temp.dat", "fdb.dat");
		rd.open("temp.dat", ios::in);
		if(rd)
		cout<<"\nError occured.!!!";
		else
		 cout<<"\nRecord deleted.";
		rd.close();
	}

};



int main()
{
	clrscr();
/*	cout<<"Program started."<<endl;
	siodet s1;    //object creation for students

	cout<<"Want to enter details y/n"; //entering details
	while(toupper(getch())=='Y')
	{
		s1.sidet();
		cout<<endl<<"Want to add another detail? y/n ";
	}
	s1.sodet();                        //show details
	cout<<"\nWant to delete record y/n";
	while(toupper(getch())=='Y')      //delete records
	{
	 s1.sdelete();
	 cout<<"Want to delete another record y/n";
	}
								//show details after deletion
	s1.sodet();  */

	fiodet f1;
	cout<<"Want to Enter the details of the faculty..y/n  ";
	while(toupper(getch())=='Y')
	{
	   f1.fidet();
	   cout<<"Add another details.. y/n  ";
	}
	f1.fodet();
	f1.fdelete();
	f1.fodet();
	getch();
	return 0;
}

