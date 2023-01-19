#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>

   void pdata();
   void admin();
   void pput();
   void user();
   void box();
   void writedata();
   void sbox();
   void book();
   int pnr,nop;
   long unsigned pno;
   char pnm[50];
   char psrc[50];
   char pdest[50];
   char pcls[50];

   class flight
   {
     int   fno;
     char  fnm[40];
     char  src[40];
     char  dest[40];
     int   nbc;
     int   nec;
     float fbc;
     float fec;
	 public:
	 void check();

	 void moddata();

	 void deldata();

	  void getdata()
       {    gotoxy(35,3);
	    cout<<"ADD FLIGHT";
	    gotoxy(10,6);
	    cout<<"Flight no. :";
	    gotoxy(10,8);
	    cout<<"Flight name :";
	    gotoxy(10,10);
	    cout<<"Source:";
	    gotoxy(10,12);
	    cout<<"Destination:";
	    gotoxy(35,16);
	    cout<<"Business";
	    gotoxy(48,16);
	    cout<<"|";
	    gotoxy(55,16);
	    cout<<"Economy";
	    gotoxy(15,18);
	    cout<<"No. of seats:";
	    gotoxy(15,20);
	    cout<<"Fare (INR):";

	    gotoxy(30,6);
	    cin>>fno;
	    flushall();
	    gotoxy(30,8);
	    gets(fnm);
	    gotoxy(30,10);
	    gets(src);
	    gotoxy(30,12);
	    gets(dest);
	    gotoxy(35,18);
	    cin>>nbc;
	    gotoxy(55,18);
	    cin>>nec;
	    gotoxy(35,20);
	    cin>>fbc;
	    gotoxy(55,20);
	    cin>>fec;






	}
	void putdata(int r)
	{
	  gotoxy(5,r);
	  cout<<fno;
	  gotoxy(12,r);
	  cout<<fnm;
	  gotoxy(21,r);
	  cout<<src;
	  gotoxy(32,r);
	  cout<<dest;
	  gotoxy(46,r);
	  cout<<nbc;
	  gotoxy(54,r);
	  cout<<fbc;
	  gotoxy(62,r);
	  cout<<nec;
	  gotoxy(70,r);
	  cout<<fec;
	 }


	}f;

     void flight::deldata()
     {    int no;
	  char ch;
	  fstream file,file1;
	  cout<<"Enter flight number to be deleted:";
	  cin>>no;
	    file.open("flights.dat",ios::in|ios::binary);
	      file1.open("Temp.dat",ios::out|ios::binary);
	     while(file.read((char*)&f,sizeof(f)))
	       { if(no==fno)
		 { cout<<"Flight number        :"<<fno<<endl;
		   cout<<"Flight name          :"<<fnm<<endl;
		   cout<<"Source               :"<<src<<endl;
		   cout<<"Destination          :"<<dest<<endl;
		   cout<<"No. of Business seats:"<<nbc<<endl;
		   cout<<"Fare		       :"<<fbc<<endl;
		   cout<<"No. of Economy seats :"<<nec<<endl;
		   cout<<"Fare		       :"<<fec<<endl;

		   cout<<"Do you want to delete this record(y/n):";
		   ch=getchar();

		  if(ch=='y'||ch=='Y')
		      continue;
		  else
		    file1.write((char*)&f,sizeof(f));
		 }
		 else
		    file1.write((char*)&f,sizeof(f));
	       }
	       file.close();
	       file1.close();

	      remove("flights.dat");
		rename("Temp.dat","flights.dat");
		admin();
	}
	      void flight::moddata()
	       { int flag=0;
		 int pos,fn;
		 char a,b;
		 fstream file;
		 file.open("flights.dat", ios::in|ios::out|ios::binary);
		 cout<<"Enter the flight no. you want to modify:";
		 cin>>fn;
		 pos=file.tellg();
		 while(!file.eof())
		 {  file.read((char*)&f,sizeof(f));
		    if(fn==fno)
		    { flag=1;
		      cout<<"Flight no.            :"<<fno<<endl;
		  cout<<"Flight name           :"<<fnm<<endl;
		  cout<<"Source                :"<<src<<endl;
		  cout<<"Destination           :"<<dest<<endl;
		  cout<<"No. of Buisness seats :"<<nbc<<endl;
		  cout<<"Fare                  :"<<fbc<<endl;
		  cout<<"No. of Economy seats  :"<<nec<<endl;
		  cout<<"Fare                  :"<<fec<<endl;
		  cout<<"Do you want to modify this record?(y/n)";
		  a=getchar();
		  if(a=='y'||a=='Y')
		  { clrscr();
		    box();
		    getdata();
		    gotoxy(10,23);
		    cout<<"Do you want to save the record?(y/n)";
		    cin>>b;
		    if(b=='y'||b=='Y')
			 {
			 file.seekg(pos);
			 file.write((char*)&f,sizeof(f));
			 break;

			 }//fn condition for writing into file and start of else
		    }
		    }
			 pos=file.tellg();
			}//while function close
		    if(flag==0)
		       cout<<"Record not found";
		       getch();
		       admin();
	} //function bracket
	 void table()
	{
	   int i=0;

	//FIRST CHAR LEFT
	gotoxy(4,3);
	cout<<char(218);

	//TOP LINE
	for(i=0;i<70;i++)
	cout<<char(196);

	//FIRST CHAR RIGHT
	cout<<char(191);

	//LEFT LINE
	for(i=3;i<22;i++)
	{
	gotoxy(4,i+1);
	cout<<char(179);
	}

	//RIGHT LINE
	for(i=3;i<22;i++)
	{
	gotoxy(75,i+1);
	cout<<char(179);
	}

	//LAST CHAR LEFT
	gotoxy(4,23);
	cout<<char(192);

	//LAST CHAR RIGHT
	gotoxy(75,23);
	cout<<char(217);

	//LAST LINE
	for(i=4;i<74;i++)
	{
	gotoxy(i+1,23);
	cout<<char(196);
	}

	//LINES START SEPERATORS
	//SEPERATOR 1
	gotoxy(11,23);
	cout<<char(193);
	for(i=5;i<22;i++)
	{
	gotoxy(11,i+1);
	cout<<char(179);
	}

	//SEPERATOR 2
	gotoxy(17,23);
	cout<<char(193);
	gotoxy(17,3);
	cout<<char(194);
	for(i=3;i<22;i++)
	{
	gotoxy(17,i+1);
	cout<<char(179);
	}

	//SEPERATOR 3
	gotoxy(30,23);
	cout<<char(193);
	gotoxy(30,3);
	cout<<char(194);
	for(i=3;i<22;i++)
	{
	gotoxy(30,i+1);
	cout<<char(179);
	}

	//SEPERATOR 4
	gotoxy(44,23);
	cout<<char(193);
	gotoxy(44,3);
	cout<<char(194);
	for(i=3;i<22;i++)
	{
	gotoxy(44,i+1);
	cout<<char(179);
	}


	//SEPERATOR 5
	gotoxy(52,23);
	cout<<char(193);
	for(i=5;i<22;i++)
	{
	gotoxy(52,i+1);
	cout<<char(179);
	}

	//SEPERATOR 6
	gotoxy(60,23);
	cout<<char(193);
	gotoxy(60,3);
	cout<<char(194);
	for(i=3;i<22;i++)
	{
	gotoxy(60,i+1);
	cout<<char(179);
	}

	//SEPERATOR 7
	gotoxy(68,23);
	cout<<char(193);
	for(i=5;i<22;i++)
	{
	gotoxy(68,i+1);
	cout<<char(179);
	}

	//HR 1
	for(i=4;i<74;i++)
	{
	gotoxy(i+1,6);
	cout<<char(196);
	}

	//HR 2
	for(i=4;i<74;i++)
	{
	gotoxy(i+1,8);
	cout<<char(196);
	}

	//DOWN JOINTS
	gotoxy(11,6);
	cout<<char(194);
	gotoxy(52,6);
	cout<<char(194);
	gotoxy(68,6);
	cout<<char(194);

	//RIGHT JOINTS
	gotoxy(4,6);
	cout<<char(195);
	gotoxy(4,8);
	cout<<char(195);

	//LEFT JOINTS
	gotoxy(75,6);
	cout<<char(180);
	gotoxy(75,8);
	cout<<char(180);

	//PLUS JOINTS PRIMARY
	gotoxy(17,6);
	cout<<char(197);
	gotoxy(30,6);
	cout<<char(197);
	gotoxy(44,6);
	cout<<char(197);
	gotoxy(60,6);
	cout<<char(197);

	//PLUS JOINTS SECONDARY
	gotoxy(17,8);
	cout<<char(197);
	gotoxy(30,8);
	cout<<char(197);
	gotoxy(44,8);
	cout<<char(197);
	gotoxy(60,8);
	cout<<char(197);
	gotoxy(11,8);
	cout<<char(197);
	gotoxy(52,8);
	cout<<char(197);
	gotoxy(68,8);
	cout<<char(197);
	}

void dispdata()
	{
	  fstream file;
	  file.open("flights.dat", ios::in|ios::binary);

	  table();
	  gotoxy(8,4);
	  cout<<"Flight";
	  gotoxy(7,7);
	  cout<<"No.";
	  gotoxy(13,7);
	  cout<<"Name";
	  gotoxy(21,5);
	  cout<<"Source";
	  gotoxy(32,5);
	  cout<<"Destination";
	  gotoxy(49,4);
	  cout<<"Business";
	  gotoxy(64,4);
	  cout<<"Economy";
	  gotoxy(46,7);
	  cout<<"Seats";
	  gotoxy(54,7);
	  cout<<"Fare";
	  gotoxy(62,7);
	  cout<<"Seats";
	  gotoxy(70,7);
	  cout<<"Fare";
	   int r=9;
	   while(file.read((char*)&f,sizeof(f)))
	 {	   f.putdata(r);
		   r++;
	  }
	   file.close();
	  getch();
	  admin();

	  }


	void admin()
	{ int c;

		clrscr();
		sbox();
		gotoxy(30,5);
		cout<<"-  WELCOME  ADMIN  -" ;
		gotoxy(28,10);
		cout<<"1. Enter flight details";
		gotoxy(28,12);
		cout<<"2. Modify details";
		gotoxy(28,14);
		cout<<"3. Delete details";
		gotoxy(28,16);
		cout<<"4. Display details";
		gotoxy(28,18);
		cout<<"5. Exit";
		gotoxy(50,24);
		cout<<"Enter your choice:";
		cin>>c;
		    switch(c)
			     { case 1: clrscr();
				       box();
				       writedata();
				       break;

			       case 2: f.moddata();

				       break;

			       case 3: box();
				       f.deldata();
				       break;
			       case 4: clrscr();

				       dispdata();
				       break;
			       case 5:

				       break;

			      }
	 }

//
void writedata()
{
       char ch;
       fstream file;
       file.open("flights.dat",ios::app|ios::binary);
  do
  { int a;
    f.getdata();
    gotoxy(8,23);
    cout<<"Do you want to save?";
    a=getchar();
    if(a=='y'||a=='Y')
    { file.write((char*)&f,sizeof(f));
    }
    flushall();
    gotoxy(50,23);
    cout<<"Want to enter more? (Y/N)";
    ch=getchar();
    clrscr();
  }
  while(ch=='y'||ch=='Y');
  admin();
  }

	void box()
	{
		int i=0;
		gotoxy(1,1);

		cout<<char(201);
		for(i=0;i<78;i++)
		cout<<char(205);
		cout<<char(187);
		for(i=1;i<24;i++)
	       {
		  cout<<char(186);
		  gotoxy(1,i+1);
	       }
		for(i=1;i<24;i++)
	       {  cout<<char(186);
		  gotoxy(80,i+1);
	       }
		gotoxy(1,24);
		cout<<char(200);
		for(i=0;i<78;i++)
		cout<<char(205);
		cout<<char(188);
	}
	void sbox()
	{
		int i=0;
		gotoxy(14,3);
		cout<<char(201);
		for(i=15;i<64;i++)
		cout<<char(205);
		gotoxy(64,3);
		cout<<char(187);
		for(i=3;i<20;i++)
	       {
		  gotoxy(14,i+1);
		  cout<<char(186);
	       }
		for(i=3;i<21;i++)
	       {  gotoxy(64,i+1);
		  cout<<char(186);
	       }
		gotoxy(14,21);
		cout<<char(200);
		for(i=15;i<64;i++)
		{
			gotoxy(i,21);
		cout<<char(205);
		}
		gotoxy(64,21);
		cout<<char(188);
	}
class pass
{
int pnr,nop;
long unsigned pno;
char pnm[50];
char psrc[50];
char pdest[50];
char pcls[50];
public:

    }p;



void flight::check()
{
 int i=21,j=10;
 gotoxy(i+7,j-1);
 cout<<"Enter Passenger Details";
 gotoxy(i,j+2);
 cout<<"Enter source";
 gotoxy(i+20,j+2);
 cout<<":";
 gotoxy(i,j+5);
 cout<<"Enter destination";
 gotoxy(i+20,j+5);
 cout<<":";
 gotoxy(i,j+8);

 gotoxy(i+30,j+2);
 flushall();
 gets(psrc);
 gotoxy(i+30,j+5);
 gets(pdest);
 clrscr();

 char ch;
 fstream file;
 file.open("flights.dat",ios::in|ios::out|ios::binary);
 int flag=0;

 while(file.read((char*)&f,sizeof(f)))
 {

  if((strcmpi(src,psrc)==0)&&(strcmpi(dest,pdest)==0))
  { flag=1;
    i=15,j=7;
    gotoxy(i-4,j-3);
    cout<<"These are the flights available according to the entered places:";
    gotoxy(i,j+1);
    cout<<"Flight no.";
    gotoxy(i+23,j+1);
    cout<<":";
    cout<<fno<<endl;
    gotoxy(i,j+3);
    cout<<"Flight name";
    gotoxy(i+23,j+3);
    cout<<":";
    cout<<fnm<<endl;
    gotoxy(i,j+5);
    cout<<"Source";
    gotoxy(i+23,j+5);
    cout<<":";
    cout<<src<<endl;
    gotoxy(i,j+7);
    cout<<"Destination";
    gotoxy(i+23,j+7);
    cout<<":";
    cout<<dest<<endl;
   gotoxy(i,j+9);
   cout<<"Enter class";
   gotoxy(i,j+9);
   cout<<"Business/Economy(B/E)";
   gotoxy(i+23,j+9);
   cout<<":";
   gotoxy(i+24,j+9);
   gets(pcls);


   if(strcmpi(pcls,"e")==0)
   {     gotoxy(i,j+11);
	 cout<<"No. of seats";
	 gotoxy(i+23,j+11);
	 cout<<":";
	 gotoxy(i+24,j+11);
	 cin>>nop;
       if(nop<=f.nec)
	 {

	 gotoxy(i-14,j+14);
	 cout<<"There are sufficient seats available in this class";

	 gotoxy(10,25);
	 cout<<"Do you want to move ahead with booking?? (Y/N)";
	 cin>>ch;
	 if(ch=='Y'||ch=='y')
	 {
	 clrscr();
	 pdata();
	 }
	 }
       else
	{ gotoxy(30,24);
	  cout<<"Insufficient seats";
	  getch();
	  user();

	}
     }
    else if(strcmpi(pcls,"b")==0)
    {   gotoxy(i,j+11);
	cout<<"No. of seats";
	gotoxy(i+23,j+11);
	cout<<":";
	gotoxy(i+24,j+11);
	cin>>nop;
	if(nop<=f.nbc)
	  { gotoxy(i-10,j+15);
	    cout<<"There are sufficient seats available in this class";

	    gotoxy(i-10,24);
	    cout<<"Do you want to move ahead for booking?? (Y/N)";
	    cin>>ch;
	    if(ch=='y'||ch=='Y')
	     {  clrscr();
		pdata();
	     }
	  }
	else
	{ gotoxy(30,24);
	  cout<<"Insufficient seats";
	  getch();
	  user();

	}
     }

   }
  }
  if(flag==0)
   { gotoxy(15,11);
     cout<<"No flights available on this route";
   }



//pdata();

}


void book()
{
 int i=21,j=8;
 sbox();
 gotoxy(i+7,j-2);
 cout<<"Enter Passenger Details";
 gotoxy(i,j+2);
 cout<<"Enter source";
 gotoxy(i+20,j+2);
 cout<<":";
 gotoxy(i,j+4);
 cout<<"Enter destination";
 gotoxy(i+20,j+4);
 cout<<":";
 gotoxy(i,j+6);
 cout<<"Enter class";
 gotoxy(i,j+7);
 cout<<"Buisness/Economy(B/E)";
 gotoxy(i+20,j+6);
 cout<<":";
 gotoxy(i,j+9);
 cout<<"Passenger name";
 gotoxy(i+20,j+9);
 cout<<":";
 gotoxy(i,j+11);
 cout<<"Phone no.";
 gotoxy(i+20,j+11);
 cout<<":";
 gotoxy(i+30,j+2);
 flushall();
 gets(psrc);
 gotoxy(i+30,j+4);
 gets(pdest);
 gotoxy(i+30,j+6);
 gets(pcls);
 gotoxy(i+30,j+9);
 gets(pnm);
 gotoxy(i+30,j+11);
 cin>>pno;
 fstream file;
file.open("pass.dat",ios::app|ios::binary);


    }                //book

  void pput(int r)
	{
	  gotoxy(15,r);
	  cout<<psrc;
	  gotoxy(23,r);
	  cout<<pdest;
	  gotoxy(35,r);
	  cout<<pcls;
	  gotoxy(45,r);
	  cout<<pnm;
	  gotoxy(65,r);
	  cout<<pno;
	 }       //pput




    void pdata()
{
       char ch;
       fstream file;
       file.open("pass.dat",ios::app|ios::binary);
  do
  { int a;
    book();
    gotoxy(8,23);
    cout<<"Do you want to save?";
    a=getchar();
    if(a=='y'||a=='Y')
    { file.write((char*)&p,sizeof(p));
    }
    flushall();
    gotoxy(50,23);
    cout<<"Want to enter more? (Y/N)";
    ch=getchar();
    clrscr();
  }
  while(ch=='y'||ch=='Y');
	user();
  } 	//pdata


  void pdisp()
	{
	  fstream file;
	  file.open("pass.dat", ios::in|ios::binary);

	  gotoxy(15,7);
	  cout<<"Source";
	  gotoxy(23,7);
	  cout<<"Destination";
	  gotoxy(35,7);
	  cout<<"Class";
	  gotoxy(45,7);
	  cout<<"Passengers Name";
	  gotoxy(65,7);
	  cout<<"Phone no.";
	   int r=9;
	   while(file.read((char*)&f,sizeof(f)))
	 {	   pput(r);
		   r++;
	  }
	   file.close();
	  getch();
	  user();

	  }	//pdisp

	void user()
	{
		int c;
		clrscr();
		sbox();
		gotoxy(30,8);
		cout<<"-   WELCOME  USER   -" ;
		gotoxy(28,12);
		cout<<"1. Book flights";
		gotoxy(28,14);
		cout<<"2. Booking history";
		gotoxy(28,16);
		cout<<"3. Exit";
		gotoxy(50,24);
		cout<<"Enter your choice:";
		cin>>c;
		    switch(c)
			     { case 1: clrscr();
				       f.check();
				       break;

			       case 2: clrscr();
				       box();
				       pdisp();
				       break;

			       case 3: clrscr();
				       exit(0);
				       break;
			     } 		//switch
	}                //user

void main()

   {   clrscr();
       int ch;
	clrscr();
	box();
	gotoxy(28,3);
	cout<<"WELCOME TO ALPHA A!RWAYS";
	gotoxy(60,23);
	cout<<"Enter your choice:";
	gotoxy(38,9);
	cout<<"1. Admin";
	gotoxy(38,12);
	cout<<"2. User ";
	gotoxy(38,15);
	cout<<"3. Quit ";
	gotoxy(79,23);
	cin>>ch;
	switch(ch)
	   {
	    case 1 :
		     admin();
		     break;
	    case 2 : clrscr();
		     user();
		     break;
	    case 3 : clrscr();
		     gotoxy(37,12);
		     cout<<"Good Bbye!";
		     break;
	    default: cout<<"Invalid Entry!!";
		     break;

	   }  //switch
	 getch();


    }






		//main