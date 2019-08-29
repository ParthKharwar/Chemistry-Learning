/*

Title: Chemistry Project

Authors:
Vedant Gurav
Parth J. Kharwar
Muhanned Parkar

About:
This program performs the basic chemistry
functions required by first year engineering
students.
It calculates:
	1. Gross Calorific Value
	2. Net Calorific Value
	3. Atom Economy
	4. Acid Value
	5. Saponification Value
	6. Hardness of Water
	7. Basic arithmetic values

This program also contains a hidden snake game.
This game was build with it in mind that not
every student studies all the time.

It uses coding language C++ and compiler
Turbo C emulated in a DOS environment to
perform complex graphical and arithmetic
operations.

*/

/*

Inclusion of header files
iostream header for input and output
stdio header for accepting and displaying strings
conio header for graphic handling
string header for character handling
time header to insert time delays
math header to perform maths functions

*/

#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <constream.h>
#include <iostream.h>
#include <string.h>

//Declaration of global variables and arrays

int c,q,z=1,w,crz,eqlr=0,lhsLen=0,rhsLen=0;
float a[9] = {0};
float b[9] = {0};
float lub[9] = {0};
float temp[9] = {0};
float perm[9] = {0};
char lhs[100] = {0},rhs[100] = {0};

char beqn[200];
char eleL[100];
char eleR[100];
char desp[50];
int valL[100] = {0};
int valR[100] = {0};
int mL[100];

static int snake[300][2], food[30][2], screen[80][25];
static int headx, heady, foodx, foody, level, tailx, taily, tail;
char dir, key;

//Declaration of funtions used in program

void credits();
float srch(char st[]);
void elsep();
void atm();
void eqnr();
void sap();
void acd();
void eqnin();
void reset(int k);
void inv(int inv);
void home();
void cent();
void dispMenu();
void wate();
void watec();
void gncv();
void disp(int k);
void welcome();
void game(int x);
void snakeGame();
void tempf();
void permf();
void dispCalc();
void calculator();

//Control funtion for program

void home()
{
	_setcursortype(_NORMALCURSOR);
	int l;
	char in;
	welcome();
	while(l)
	{
		dispMenu();
		in=getch();
		if(in==27)
		{
			l=0;
			break;
		}
		switch(in)
		{
			case '1': cent(); break;
			case '2': wate(); break;
			case '3': eqnin(); break;
			case '4': acd(); break;
			case '5': sap(); break;
			case '6': tempf(); break;
			//case '7': calculator(); break;
			case '7': credits(); break;
			case 'f':
			case 'F': game(0);break;
			case 'r':
			case 'R': reset(0);break;
			case 'w':
			case 'W': char w; w=getch();
							if(w==27)
									welcome();
								break;
			case 'q':
			case 'Q': l=0;break;
			default: inv(0);
		}
	}
}

//Funtion to display welcome screen

void welcome()
{
	_setcursortype(_NOCURSOR);
	for(int i = 1; i > 0; i++)
	{
		if(i==15)
			i=1;
		textcolor(i);
		clrscr();

		gotoxy(27,22); cout<<"PRESS ANY KEY TO CONTINUE!";
		for(long k = 0; k <= 200000; k++)
		{
			k++; k--;
			if(kbhit())
			{
				getch(); i=-1; break;
			}
		}

		gotoxy(17,7); cout<<"          ___        ___   ___		   ___	";
		gotoxy(17,8); cout<<"|      | |    |     /	  /   \\  |\\    /| |	";
		gotoxy(17,9); cout<<"|      | |___ |    |	 |     | |  \\/  | |___";
		gotoxy(17,10); cout<<"|  /\\  | |    |    |     |     | |	| |	";
		gotoxy(17,11); cout<<"|/    \\| |___ |___  \\___  \\___/  |	| |___	";

		gotoxy(16,13); cout<<"___  __     __       __         __  ___  _  ";
		gotoxy(16,14); cout<<" |  |  |   |   |__| |_  |\\/| | |__   |  |_| |__|";
		gotoxy(16,15); cout<<" |  |__|   |__ |  | |__ |  | |  __|  |  | \\  __|";
		for(long j = 0; j <= 400000; j++)
		{
			j++; j--;
			if(kbhit())
			{
				getch(); i=-1; break;
			}
		}
	}
	textcolor(7);
	clrscr();
	gotoxy(24, 10); cout<<"__________ WARNING!!!! __________";
	gotoxy(21, 13); cout<<"This Program is subject to DosBox Error";
	gotoxy(21, 15); cout<<"Please Read All Instructions Carefully!";
	gotoxy(28, 23); cout<<"PRESS ANY KEY TO CONTINUE";
	getch();
	_setcursortype(_NORMALCURSOR);
}

//Function to display main menu

void dispMenu()
{
	clrscr();
	cout<<"\n\n      What would you like to do?\n\n";
	cout<<"            1. GCV & NCV by Percentages\n";
	cout<<"            2. GCV & NCV by Weights\n";
	cout<<"            3. Atom Economy\n";
	cout<<"            4. Acid Value\n";
	cout<<"            5. Saponification Value\n";
	cout<<"            6. Water Hardness\n";
     //	cout<<"            7. Calculator\n";
	cout<<"            7. Credits\n";
	cout<<"\n\n\n\n\n\n\n\n\n\n"<<"    Enter Choice by pressing Corresponding Number.\n    Press F for Fun.\n    Press Esc to Quit.";
	gotoxy(7, 13);
}

//Funtion to display appropriate funtion screen

void disp(int k)
{
  clrscr();

  if(k==1)
    {
      printf("j");printf("j");
      clrscr();
      printf("j");printf("j");
      clrscr();
      printf("\n\n");
      printf("\n       %C      =   ");              if(a[1])  cout<<a[1]<<"\t%";
      printf("\n       %H      =   ");              if(a[2])  cout<<a[2]<<" \t%";
      printf("\n       %N      =   ");              if(a[3])  cout<<a[3]<<"\t%";
      printf("\n       %S      =   ");              if(a[4])  cout<<a[4]<<"\t%";
      printf("\n       %O      =   ");              if(a[5])  if(a[5]<100 && a[5]>0.000001) cout<<a[5]<<"\t%";
      printf("\n       %Ash    =   ");              if(a[6])  if(a[6]>0.000001) cout<<a[6]<<"\t%";
      printf("\n       GCV     =   ");              if(a[7])   cout<<a[7]<<"\tkcal/kg";
      printf("\n       NCV     =   ");              if(a[8])   cout<<a[8]<<"\tkcal/kg";

      printf("\n\n\n\n\n\n");
      if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>100 || a[1]<0 || a[2]<0 || a[3]<0 || a[4]<0 || a[5]<0 || a[6]<0 /*&& a[5]<0.000001*/)
	       printf("    Incorrect Input.");
      printf("\n\n\n\n    Input Values.\n    Enter Weight in g. Enter Volume in ml.");
      printf("\n    Press R to Reset Data.\n    Press Esc to Return.");
    }


  else if (k==0)
    {
      printf("\n\n\n      Wt. of Coal Sample      =   "); 	           if(b[0]) cout<<b[0]<<"\tg.";
      printf(    "\n   Inc. in wt. of KOH Bulb    =   ");              if(b[1])  cout<<b[1]<<"\tg.";
      printf(    "\n  Inc. in wt. of CaCl2 Tube   =   ");              if(b[2])  cout<<b[2]<<"\tg.";
      printf(    "\n     Volume of Acid used      =   ");              if(b[3])  cout<<b[3]<<"\tml.";
      printf(    "\n      Normality of Acid       =   ");              if(b[4])  cout<<b[4]<<"\tN";
      printf(    "\n      Wt. of BaSO4 ppt.       =   ");              if(b[5])  cout<<b[5]<<"\tg.";
      printf(    "\n       Wt. of Residue         =   ");              if(b[6])  cout<<b[6]<<"\tg.";

      printf("\n\n\n\n\n\n");
      printf("\n\n\n\n    Input Values.\n    Enter Weight in g. Enter Volume in ml.");
      printf("\n    Press R to Reset Data.\n    Press N to Continue.\n    Press Esc to Return.");
    }

  else if (k==2)
    {
      cout<<"\n    Enter an Equation: ";
      gotoxy(1, 20);
			cout<<     "    Press / to Proceed.\n";
			cout<<     "    Enter the Reactants as Case Sensitive.\n";
			cout<<     "    Enter only desired products in RHS.\n";
      cout<<     "    Press ~ to Reset Data.\n";
			cout<<     "    Press Esc to Return.";
    }

  else if (k==3)
    {
      printf("\n\n\n         Wt. of Oil         =   "); 	       if(lub[0]) cout<<lub[0]<<"\tg.";
      printf(    "\n      Vol. of KOH used      =   "); 	       if(lub[1]) cout<<lub[1]<<"\tml.";
      printf(    "\n      Normality of KOH      =   "); 	       if(lub[2]) cout<<lub[2]<<"\tN";
      printf(    "\n         Acid Value         =   ");          if(lub[3]) cout<<lub[3]<<"\tmg/g of KOH";

			if(lub[3]<0.100001 && lub[3]!=0) printf("\n\n    Oil is Suitable for Lubrication.");
			else cout<<"\n\n";
			printf("\n\n\n\n\n\n\n");
      printf("\n\n\n\n    Input Values.\n    Enter Weight in g. Enter Volume in ml.");
      printf(      "\n    Press R to Reset Data.\n    Press N to switch to Sap Value.\n    Press Esc to Return.");
    }

 else if (k==4)
    {
      printf("\n\n\n         Wt. of Oil         =   "); 	       if(lub[4]) cout<<lub[4]<<"\tg.";
      printf(    "\n       Blank Titration      =   "); 	       if(lub[5]) cout<<lub[5]<<"\tml.";
      printf(    "\n       Back  Titration      =   "); 	       if(lub[6]) cout<<lub[6]<<"\tml.";
      printf(    "\n      Normality of KOH      =   "); 	       if(lub[7]) cout<<lub[7]<<"\tN";
      printf(    "\n    Saponification Value    =   ");          if(lub[8]) cout<<lub[8]<<"\tmg/g of KOH";

      printf("\n\n\n\n\n\n\n\n");
      printf("\n\n\n\n    Input Values.\n    Enter Weight in g. Enter Volume in ml.");
      printf("\n    Press R to Reset data.\n    Press N to switch to Acid Value.\n    Press Esc to Return.");
    }

 else if (k==5)
 		{
			printf("\n\n\n          Ca(HCO3)2         =   "); 	       if(temp[0]) cout<<temp[0]<<"\tmg/l.";
      printf(    "\n          Mg(HCO3)2         =   "); 	       if(temp[1]) cout<<temp[1]<<"\tmg/l.";
      printf(    "\n            CaCO3           =   "); 	       if(temp[2]) cout<<temp[2]<<"\tmg/l.";
      printf(    "\n            MgCO3           =   ");          if(temp[3]) cout<<temp[3]<<"\tmg/l.";
			printf(    "\n            Other           =   ");          if(temp[4]) cout<<temp[4]<<"\tppm.";
			printf(    "\n     Temporary Hardness     =   ");          if(temp[5]) cout<<temp[5]<<"\tppm.";
			printf(    "\n       Total Hardness       =   ");          if(temp[6]) cout<<temp[6]<<"\tppm.";

			printf("\n\n\n\n\n\n");
      printf("\n\n\n\n    Input Values.\n    Enter Quantity of Salts in mg/l.");
      printf(      "\n    Press R to Reset Data.\n    Press N to switch to Permanent Hardness.\n    Press Esc to Return.");
		}

	else if (k==6)
			 {
				 printf("\n\n\n            CaSO4           =   "); 	       if(perm[0]) cout<<perm[0]<<"\tmg/l.";
				 printf(    "\n            MgSO4           =   "); 	       if(perm[1]) cout<<perm[1]<<"\tmg/l.";
				 printf(    "\n            CaCl2           =   "); 	       if(perm[2]) cout<<perm[2]<<"\tmg/l.";
				 printf(    "\n            MgCl2           =   ");         if(perm[3]) cout<<perm[3]<<"\tmg/l.";
				 printf(    "\n            FeCl2           =   ");         if(perm[4]) cout<<perm[4]<<"\tmg/l.";
				 printf(    "\n           Mg(N0)3          =   ");         if(perm[5]) cout<<perm[5]<<"\tmg/l.";
				 printf(    "\n            Other           =   ");         if(perm[6]) cout<<perm[6]<<"\tppm.";
				 printf(    "\n     Permanent Hardness     =   ");         if(perm[7]) cout<<perm[7]<<"\tppm.";
				 printf(    "\n       Total Hardness       =   ");         if(temp[6]) cout<<temp[6]<<"\tppm.";

				 printf("\n\n\n\n");
				 printf("\n\n\n\n    Input Values.\n    Enter Quantity of Salts in mg/l.");
				 printf(      "\n    Press R to Reset Data.\n    Press N to switch to Permanent Hardness.\n    Press Esc to Return.");
			 }
}
//Graphic funtion and control director

void wate()
{
	int v=1,l=1,y=4,x=35;
	char in;
	disp(0);
	while(l)
	{
		gotoxy(x,y);
		in=getch();
		if(in==0)
		{
			x=wherex();y=wherey();
			in=getch();

			switch(in)
			{
			 case 80:  if (y==10) y -=6; else y++; break;
			 case 72:  if (y==4)  y +=6; else y--; break;
			}
		    clrscr();
		    disp(0);
		    gotoxy(x,y);
		  }
		 else if(in>='0' && in<='9' || in=='.')
		   {
				 int r=1,c,m,n;
			   char inl,*st;
			   char inlc[30];
		     y=wherey();
				 cout<<in;
				 inlc[0]=in;
				 for(c=1;r!=0;)
			   {
			     inl=getch();
					 if(inl>='0' && inl<='9' || inl=='.') cout<<inl;
			     if(inl==13 || inl==0)
			       {inlc[c]='\0';r=0;if(inl==0)getch();}
			     else if(inl==8)
			 			{
			 	  		c--;
			 	  		inlc[c]='\0';
			 	  		cout<<"\b \b";
			 			}
			     else {inlc[c]=inl;c++;}
			   }
		     b[y-4]=strtod(inlc,&st);
		     clrscr();
		     disp(0);
		     if(y!=10) y++;
		     else y-=6;
		     gotoxy(x,y);
		   }
		 else if(in==78 || in==110)
		   {
		     l=0;
		   }
		 else if(in == 'r' || in == 'R')
		   {
		     reset(0);
		     disp(0);
		   }
		 else if(in=='q' || in=='Q' || in==27)
		   {
		     l=0;
		     v=0;
		   }
		 else inv(2);
	}
  a[0]=b[0];
  clrscr();
  if(v)
  watec();
}

//Graphic funtion and control director

void cent()
{
  int l=1,y=4,x=20;
  char in;
  disp(1);
  while(l)
	{
		 gotoxy(x,y);
		 in=getch();
		 if(in==0)
		  {
		    y=wherey();
		    in=getch();

		    switch(in)
		    {
		      case 80:  if (y==11) y -=7; else y++; break;
		      case 72:  if (y==4)  y +=7; else y--; break;
		    }
		    clrscr();
		    disp(1);
		    gotoxy(x,y);
		  }
		 else if(in>='0' && in<='9' || in=='.')
		   {
				 int r=1,c,m,n;
			   char inl,*st;
			   char inlc[30];
		     y=wherey();
				 cout<<in;
				 inlc[0]=in;
				 for(c=1;r!=0;)
			   {
			     inl=getch();
					 if(inl>='0' && inl<='9' || inl=='.') cout<<inl;
			     if(inl==13 || inl==0)
			       {inlc[c]='\0';r=0;if(inl==0)getch();}
			     else if(inl==8)
			 			{
			 	  		c--;
			 	  		inlc[c]='\0';
			 	  		cout<<"\b \b";
			 			}
			     else {inlc[c]=inl;c++;}
			   }
		     a[y-3]=strtod(inlc,&st);
		     if (y==8)
			 z=0;
		     if (y==10 || y==11)
			 q=0;
		     clrscr();
		     disp(1);
		     if(y!=11) y++;
		     else y-=7;
		     gotoxy(20,y);
		   }
		 else if(in=='q' || in=='Q' || in==27)
			   {
			      y=11;
			      gotoxy(x,y);
			      l=0;
			   }
     else if(in=='n' || in=='N')
	 {
	   l=0;
	   wate();
	 }
		 else if(in == 'r' || in == 'R')
			   {
			      reset(0);
			      disp(0);
			   }
		 else inv(1);
		 gncv();
		 z=1;
	}
}

//Funtion to calculate percentages from weight

void watec()
{
	a[1] = (b[1] * 12 * 100) / (b[0] * 44);
	a[2] = (b[2] * 2 * 100) / (b[0] * 18);
	a[3] = (b[3] * 1.4 * b[4]) / (b[0]);
	a[4] = (b[5] * 32 * 100) / (b[0] * 233);
	a[6] = (b[6] * 100) / b[0];
	clrscr();
	cent();
}

//Funtion to calculate GCV and NCV

void gncv()
{


  if(a[1]!=0 && a[2]==0 && a[3]!=0 && a[4]!=0 && a[5]!=0 && a[6]!=0)
     a[2] = 100-a[1]-a[6]-a[3]-a[4]-a[5];            //Hydrogen

  if(a[1]==0 && a[2]!=0 && a[3]!=0 && a[4]!=0 && a[5]!=0 && a[6]!=0)
     a[1] = 100-a[2]-a[6]-a[3]-a[4]-a[5];            //Carbon

  if(a[1]!=0 && a[2]!=0 && a[3]==0 && a[4]!=0 && a[5]!=0 && a[6]!=0)
     a[3] = 100-a[1]-a[6]-a[2]-a[4]-a[5];            //Nitrogen

  if(a[1]!=0 && a[2]!=0 && a[3]!=0 && a[4]==0 && a[5]!=0 && a[6]!=0)
     a[4] = 100-a[1]-a[6]-a[3]-a[2]-a[5];            //Sulphur

  if(z) a[5] = 100-a[1]-a[2]-a[3]-a[4]-a[6];                 //Oxygen Update

  if(a[6]<0)
    {
      a[6]+=a[5];
      a[5]=0;
    }
  else if(a[1]!=0 && a[2]!=0 && a[3]!=0 && a[4]!=0)
     a[6] = 100-a[1]-a[2]-a[3]-a[4]-a[5];                   //Ash Update


  if(a[2]!=0 && a[1]!=0)                                                           //GCV NCV
    {
     a[7] = (8080 * a[1] + 34500 * (a[2] - a[5] / 8) + 2240 * a[4]) / 100;
     a[8] = a[7] - 0.09 * a[2] * 587;
    }
  else if(a[7]!=a[8] && a[7]!=0 && a[8]!=0)
	  a[2] = (a[7] - a[8]) / 0.09 / 587;

  q=1;
  clrscr();
  disp(1);
}

//Function to accept an equation for Atom Economy

void eqnin()
{
	reset(1);
  int l=1,x,y,xl,xr,yl,yr;
  char in;
	eqlr=0;
  disp(2);
  gotoxy(5,4);
  for(int i=0;l;i++)
  {
    x=wherex();y=wherey();
    in=getch();
    if(in==27)
      l=0;
    else if(in==0)
      {
	       getch();
      }
    else if(in==8)
      {
	       if(eqlr)
		{if(i-lhsLen)
		   {
		     gotoxy(x-1,y);
		     i--;
		     rhs[i-lhsLen]=0;
		     cout<<" ";
		     gotoxy(x-1,y);
		   }
	       else
				{
				eqlr=0;
				gotoxy(x-4,y);
				cout<<" ";
				gotoxy(x-3,y);
				cout<<" ";
				gotoxy(x-7,y);
				i-=2;
				lhs[i]=0;
				cout<<" ";
				gotoxy(x-7,y);
			}
				}
			else
			{
			gotoxy(x-1,y);
			i--;
			lhs[i]=0;
			cout<<" ";
			gotoxy(x-1,y);
			}
			i--;

      }
    else if(in=='~' || in=='`')
		 {
	     eqlr=0;
	     reset(1);
	     reset(2);
	     clrscr();
	     disp(2);
	     gotoxy(5,4);
	     i=-1;
	   }
    else if(in=='/' && eqlr<2)
	   {
	     if(eqlr)
	       {
		      //cout<<endl<<"   "<<lhs<<"  ->  "<<rhs;
		eqlr++;
		rhsLen=i-lhsLen;
		lhsLen--;
		eqnr();
	       }
	     else
				{
				eqlr++;
				cout<<"  ->  ";
				lhsLen=i+1;
				}
	   }
    else if(in>='A' && in<= 'Z' || in>='a' && in<='z' || in>='0' && in<='9' || in=='+' || in=='(' || in==')' || in==' ' || in==32)
	   {
	     if(eqlr)
			rhs[i-lhsLen]=in;
       else lhs[i]=in;
       cout<<in;
	   }
    else inv(5);
  }
}

/*Funtion to separate elements of lhs and rhs of
equation and store the number of atoms*/

void eqnr()
{
	lhs[lhsLen] = ' ';
	lhsLen++;
	rhs[rhsLen] = ' ';
	rhsLen++;

	int al = 0, bl = 0, tl = 1, cl = -1, dc = 0, m = 0, pm = 1;

	for(int il  = 0; il <= lhsLen; il++)
	{
		if(il == cl - 1 || il == cl)
		{
			il++; continue;
		}
		if((int)lhs[il]-48  >= 1 && (int)lhs[il]-48 <= 9 && (il == 0 || lhs[il-1] == ' ' || lhs[il-1] == '+'))
		{
			pm = tl = (int)lhs[il]-48; m++;
			continue;
		}
		if(lhs[il] == '+')
		{
			eleL[al] = '|';
			eleL[al+1] = eleL[al+2] = '_';
			al+=3;
			bl+=3;
		}
		if(lhs[il] >= 65 && lhs[il] <= 90)
		{
			eleL[al] = lhs[il];
			eleL[al+1] = eleL[al+2] = '_';
			if(lhs[il+1] >= 65 && lhs[il+1] <= 90 || (lhs[il+1] == ' ' || lhs[il+1] == '+' || lhs[il+1] == '('))
			{
				valL[bl] = tl;
				bl += 3;
			}
			if(lhs[il+1] >= 97 && lhs[il+1] <= 122)
			{
				eleL[al+1] = lhs[il+1];
				if(lhs[il+2] == ' ' || lhs[il+2] == '+' || lhs[il+2] == '(')
				{
					valL[bl] = tl;
					bl += 3;
				}
				if(lhs[il+2] >= 65 && lhs[il+2] <= 90)
				{
					valL[bl] = tl;
					bl += 3;
				}
				il++;
			}
			al+=3;
		}
		if(((int)lhs[il]-48) >= 1 && ((int)lhs[il]-48) <= 9)
		{
			tl = tl * ((int)lhs[il]-48);
			il++;
			valL[bl] = tl;
			if(((int)lhs[il]-48) >= 1 && ((int)lhs[il]-48) <= 9)
			{
				tl*=10;
				if(m == 0)
					valL[bl] = ((int)lhs[il] - 48) + tl;
				else
					valL[bl] = pm * ((int)lhs[il] - 48) + tl;
				lhs[il] = '0';
			}
			bl+=3;
			il--;
			if(dc == 0 && m == 0)
				tl = 1;
			else if(dc != 0)
			{
				tl = ((int)lhs[cl]-48); dc = 0;
			}
			else if(m != 0)
			{
				tl = pm;
			}
		}
		if(lhs[il] == '(')
		{
			cl = il;
			while(lhs[cl] != ')')
				cl++;
			cl++;
			if((int)lhs[cl]-48 >= 1 && (int)lhs[cl]-48 <= 9)
			{
				tl *= (int)lhs[cl]-48;
				dc++;
				cl++;
				if(((int)lhs[cl] - 48) >= 1 && ((int)lhs[cl] - 48) <= 9 && dc == 0)
					lhs[cl] = '0';
				cl--;
			}
		}
		if(lhs[il + 1] == ' ' || lhs[il + 1] == '+')
		{
			tl = 1; m = 0;
		}
	}

	int ar = 0, br = 0, tr = 1, cr = -1;
	dc = 0; m = 0; pm = 0;

	for(int ir  = 0; ir <= rhsLen; ir++)
	{
		if(ir == cr - 1 || ir == cr)
		{
			ir++; continue;
		}
		if((int)rhs[ir]-48  >= 1 && (int)rhs[ir]-48 <= 9 && (ir == 0 || rhs[ir-1] == ' ' || rhs[ir-1] == '+'))
		{
			pm = tr = (int)rhs[ir]-48; m++;
			continue;
		}
		if(rhs[ir] == '+')
		{
			eleR[ar] = '|';
			eleR[ar+1] = eleR[ar+2] = '_';
			ar+=3;
			br+=3;
		}
		if(rhs[ir] >= 65 && rhs[ir] <= 90)
		{
			eleR[ar] = rhs[ir];
			eleR[ar+1] = eleR[ar+2] = '_';
			if(rhs[ir+1] >= 65 && rhs[ir+1] <= 90 || (rhs[ir+1] == ' ' || rhs[ir+1] == '+' || rhs[ir+1] == '('))
			{
				valR[br] = tr;
				br += 3;
			}
			if(rhs[ir+1] >= 97 && rhs[ir+1] <= 122)
			{
				eleR[ar+1] = rhs[ir+1];
				if(rhs[ir+2] == ' ' || rhs[ir+2] == '+' || rhs[ir+2] == '(')
				{
					valR[br] = tr;
					br += 3;
				}
				if(rhs[ir+2] >= 65 && rhs[ir+2] <= 90)
				{
					valR[br] = tr;
					br += 3;
				}
				ir++;
			}
			ar+=3;
		}
		if(((int)rhs[ir]-48) >= 1 && ((int)rhs[ir]-48) <= 9)
		{
			tr = tr * ((int)rhs[ir]-48);
			ir++;
			valR[br] = tr;
			if(((int)rhs[ir]-48) >= 1 && ((int)rhs[ir]-48) <= 9)
			{
				tr*=10;
				if(m == 0)
					valR[br] = ((int)rhs[ir] - 48) + tr;
				else
					valR[br] = pm * ((int)rhs[ir] - 48) + tr;
				rhs[ir] = '0';
			}
			br+=3;
			ir--;
			if(dc == 0 && m == 0)
				tr = 1;
			else if(dc != 0)
			{
				tr = ((int)rhs[cr]-48); dc = 0;
			}
			else if(m != 0)
			{
				tr = pm;
			}
		}
		if(rhs[ir] == '(')
		{
			cr = ir;
			while(rhs[cr] != ')')
				cr++;
			cr++;
			if((int)rhs[cr]-48 >= 1 && (int)rhs[cr]-48 <= 9)
			{
				tr *= (int)rhs[cr]-48;
				dc++;
				cr++;
				if(((int)rhs[cr] - 48) >= 1 && ((int)rhs[cr] - 48) <= 9 && dc == 0)
					rhs[cr] = '0';
				cr--;
			}
		}
		if(rhs[ir + 1] == ' ' || rhs[ir + 1] == '+')
		{
			tr = 1; m = 0;
		}
	}
	atm();
}

//Function to calculate and display Atom Economy

void atm()
{
  int i=0,l;
  float lwt=0,rwt=0,wt;
  char el[3]={0};
  l=strlen(eleL);
  for(i=0;i<l;i+=3)
  {
      if(eleL[i] >= 'A' && eleL[i]<='Z')
      {
				if(eleL[i+1] >= 'a' && eleL[i+1]<='z')
				{
				el[1]=eleL[i+1];
				el[0]=eleL[i];
				wt=srch(el);
				}
				else
				{
				el[0]=eleL[i];
				el[1]=0;
				wt=srch(el);
				}
				lwt = lwt + wt * valL[i];
     }
  }

  l=strlen(eleR);
  for(i=0;i<=l;i+=3)
  {
    if(eleR[i] >= 'A' && eleR[i]<='Z')
    {
      if(eleR[i+1] >= 'a' && eleR[i+1]<='z')
      {
			el[1]=eleR[i+1];
			el[0]=eleR[i];
			wt=srch(el);
      }
      else
      {
			el[0]=eleR[i];
			el[1]=0;
			wt=srch(el);
      }
      rwt += wt * valR[i];
    }
  }
  if(rwt/lwt > 1)
  {
	cout<<"\n\n    Invalid Input.\n\n    Press any key to reset.";
	getch();
	clrscr();
	eqnin();
  }
  else
	cout<<"\n\n    Atom Economy = "<<rwt*100.0/lwt<<" %";
}

//Function to store and return atomic weights

float srch(char st[3])
{
       float m;

       if(strcmpi(st,"H")==0)
       m=1;
       else
       if(strcmpi(st,"He")==0)
       m=4;
       else
       if(strcmpi(st,"Li")==0)
       m=7;
       else
       if(strcmpi(st,"Be")==0)
       m=9;
       else
       if(strcmpi(st,"B")==0)
       m=11;
       else
       if(strcmpi(st,"C")==0)
       m=12;
       else
       if(strcmpi(st,"N")==0)
       m=14;
       else
       if(strcmpi(st,"O")==0)
       m=16;
       else
       if(strcmpi(st,"F")==0)
       m=19;
       else
       if(strcmpi(st,"Ne")==0)
       m=20;
       else
       if(strcmpi(st,"Na")==0)
       m=23;
       else
       if(strcmpi(st,"Mg")==0)
       m=24;
       else
       if(strcmpi(st,"Al")==0)
       m=27;
       else
       if(strcmpi(st,"Si")==0)
       m=28;
       else
       if(strcmpi(st,"P")==0)
       m=30;
       else
       if(strcmpi(st,"S")==0)
       m=32;
       else
       if(strcmpi(st,"Cl")==0)
       m=35.5;
       else
       if(strcmpi(st,"Ar")==0)
       m=40;
       else
       if(strcmpi(st,"K")==0)
       m=39;
       else
       if(strcmpi(st,"Ca")==0)
       m=40;
       else
       if(strcmpi(st,"Sc")==0)
       m=45;
       else
       if(strcmpi(st,"Ti")==0)
       m=48;
       else
       if(strcmpi(st,"V")==0)
       m=51;
       else
       if(strcmpi(st,"Cr")==0)
       m=52;
       else
       if(strcmpi(st,"Mn")==0)
       m=55;
       else
       if(strcmpi(st,"Fe")==0)
       m=56;
       else
       if(strcmpi(st,"Co")==0)
       m=59;
       else
       if(strcmpi(st,"Ni")==0)
       m=58.5;
       else
       if(strcmpi(st,"Cu")==0)
       m=63.5;
       else
       if(strcmpi(st,"Zn")==0)
       m=65.5;
       else
       if(strcmpi(st,"Ga")==0)
       m=69.5;
       else
       if(strcmpi(st,"Ge")==0)
       m=72.5;
       else
       if(strcmpi(st,"As")==0)
       m=75;
       else
       if(strcmpi(st,"Se")==0)
       m=79;
       else
       if(strcmpi(st,"Br")==0)
       m=80;
       else
       if(strcmpi(st,"Kr")==0)
       m=84;
       else
       if(strcmpi(st,"Rb")==0)
       m=85.5;
       else
       if(strcmpi(st,"Sr")==0)
       m=87.5;
       else
       if(strcmpi(st,"Y")==0)
       m=89;
       else
       if(strcmpi(st,"Zr")==0)
       m=91;
       else
       if(strcmpi(st,"Nb")==0)
       m=93;
       else
       if(strcmpi(st,"Mo")==0)
       m=96;
       else
       if(strcmpi(st,"Te")==0)
       m=98;
       else
       if(strcmpi(st,"Ru")==0)
       m=101;
       else
       if(strcmpi(st,"Rh")==0)
       m=103;
       else
       if(strcmpi(st,"Pd")==0)
       m=106.5;
       else
       if(strcmpi(st,"Ag")==0)
       m=108;
       else
       if(strcmpi(st,"Cd")==0)
       m=112.5;
       else
       if(strcmpi(st,"In")==0)
       m=115;
       else
       if(strcmpi(st,"Sn")==0)
       m=118.5;
       else
       m=0;
       return m;
}

//Function to calculate and display Acid Value

void acd()
{
  int l,y=4,x=33;
  char in;
  disp(3);
  while(l)
  {
    if (lub[0] && lub[1] && lub[2])
	lub[3] = lub[1] * lub[2] * 56.1 / lub[0];
    disp(3);
    gotoxy(x,y);
    in=getch();
    if(in==0)
     {
       x=wherex();y=wherey();
       in=getch();
       switch(in)
       {
	 case 80: if (y==7) y-=3; else y++; break;
	 case 72: if (y==4) y+=3; else y--; break;
       }
       clrscr();
       disp(3);
       gotoxy(x,y);
     }
    else if(in>='0' && in<='9' || in=='.')
     {
			 int r=1,c,m,n;
			 char inl,*st;
			 char inlc[30];
       y=wherey();
			 cout<<in;
			 inlc[0]=in;
			 for(c=1;r!=0;)
			 {
				 inl=getch();
				 if(inl>='0' && inl<='9' || inl=='.') cout<<inl;
				 if(inl==13 || inl==0)
					 {inlc[c]='\0';r=0;if(inl==0)getch();}
				 else if(inl==8)
					{
						c--;
						inlc[c]='\0';
						cout<<"\b \b";
					}
				 else {inlc[c]=inl;c++;}
			 }
			 lub[y-4]=strtod(inlc,&st);
       clrscr();
       disp(3);
       if(y!=7) y++;
       else y-=3;
       gotoxy(x,y);
     }
    else if(in=='r' || in=='R')
     {
       reset(0);
       disp(3);
     }
    else if(in=='q' || in=='Q' || in==27)
     {
       l=0;
     }
    else if(in=='n'|| in=='N')
     {
       l=0;
       lub[4]=lub[0];
       sap();
     }
    else inv(3);
  }
 clrscr();
}

//Funtion to calculate and display Saponification Value

void sap()
{
  int l=1,y=4,x=33;
  char in;
  disp(4);
  while(l)
  {
    if (lub[4] && lub[5] && lub[7])
	lub[8] = (lub[5] - lub[6]) * lub[7] * 56 / lub[4];
    disp(4);
    gotoxy(x,y);
    in=getch();
    if(in==0)
     {
       x=wherex();y=wherey();
       in=getch();
       switch(in)
       {
	 case 80: if (y==8) y-=4; else y++; break;
	 case 72: if (y==4) y+=4; else y--; break;
       }
       clrscr();
       disp(4);
       gotoxy(x,y);
     }
    else if(in>='0' && in<='9' || in=='.')
     {
			 int r=1,c,m,n;
			 char inl,*st;
			 char inlc[30];
       y=wherey();
			 cout<<in;
				 inlc[0]=in;
				 for(c=1;r!=0;)
			   {
			     inl=getch();
					 if(inl>='0' && inl<='9' || inl=='.') cout<<inl;
			     if(inl==13 || inl==0)
			       {inlc[c]='\0';r=0;if(inl==0)getch();}
			     else if(inl==8)
			 			{
			 	  		c--;
			 	  		inlc[c]='\0';
			 	  		cout<<"\b \b";
			 			}
			     else {inlc[c]=inl;c++;}
			   }
		   lub[y]=strtod(inlc,&st);
       clrscr();
       disp(4);
       if(y!=8) y++;
       else y-=4;
       gotoxy(x,y);
     }
    else if(in=='r' || in=='R')
     {
       reset(0);
       disp(4);
     }
    else if(in=='q' || in=='Q' || in==27)
     {
       l=0;
     }
    else if(in=='n')
     {
       l=0;
       lub[0]=lub[4];
       acd();
     }
    else inv(4);
  }
 clrscr();
}

//Funtion to display credits

void credits()
{
  for(int i = 1; i > 0; i++)
  {
   	clrscr();
		gotoxy(1,25);
		int j;
		for(j = 1; j <= 8; j++)
		{
	  	gotoxy(1,25);
	    cout<<"\n";
	    switch(j)
	    {
				case 1: cout<<"\t\t       Vidyalankar Institute of Technology "; 	break;
				case 2: cout<<"\t\t                     CMPN - B              "; 	break;
				case 3: cout<<"\t\t                    FE  SEM II             "; 	break;
				case 4: cout<<"\t\t                CHEMISTRY  PROJECT          "; 	break;
				case 5: cout<<"\t\t     _______________________________________ \n"; 	break;
				case 6: cout<<"\t\t                 Muhanned  Parkar"; 			break;
				case 7: cout<<"\t\t                 Parth J. Kharwar"; 			break;
				case 8: cout<<"\t\t                   Vedant Gurav             "; 	break;
	    }
	    gotoxy(1,25);

			for(long k = 0; k <= 200000; k++)
	    {
				k++; k--;
				if(kbhit())
				{
					getch(); i=-1; j=100; break;
				}
	   	}
	 	}

		for(j=1;j<=25;j++)
		{
			cout<<"\n";
			for(long k = 0; k <= 200000; k++)
			{
				k++; k--;
				if(kbhit())
				{
					getch(); i=-1; j=26; break;
				}
			}
		}
  }
}

//Funtion to throw error if invalid input has been provided

void inv(int inv)
{
	if(inv==1 || inv==2 || inv==3 || inv==4)
  {
		int x,y,i=0;
	  for(;i<2;i++)
	  {
	  	x=15;y=15;
      switch(inv)
      {
	 		 		case 1: disp(1); break;
	 				case 2: disp(0); break;
	 				case 3: disp(3); break;
	 				case 4: disp(4); break;
	 				case 5: disp(2); break;
					case 6: disp(5); break;
					case 7: disp(6); break;
      }
	    gotoxy(x,y);
	    cout<<"Incorrect Input.\n";
	    for(long j=0;j<=2000000;j++)
		 	{
		  		j++;j--;
		 	}
	    clrscr();
	    switch(inv)
      {
	 		 		case 1: disp(1); break;
	 				case 2: disp(0); break;
	 				case 3: disp(3); break;
	 				case 4: disp(4); break;
	 				case 5: disp(2); break;
					case 6: disp(5); break;
					case 7: disp(6); break;
      }
	    for(j=0;j<=65000/*2500000*/;j++)
		 	{
		  	j++;j--;
		   	if(kbhit()) getch();
		 	}
	  }
  }

  else if(inv==0)
  {
		int x,y,i=0;
		for(;i<2;i++)
	  {
	  	x=15;y=15;
	    dispMenu();
	    gotoxy(x,y);
	    cout<<"Invalid Input.\n";
	    y++;
	    gotoxy(x,y);
	    cout<<"Enter number.";
	    for(long j=0;j<=2000000;j++)
		 	{
		  	j++;j--;
		 	}
	    clrscr();
	    dispMenu();
	    for(j=0;j<=65000;j++)
		 	{
		  	j++;j--;
		    if(kbhit()) getch();
		 	}
	   }
  }
}

//Function to reset all values throughout program

void reset(int k)
{
	int r,i;
  	switch(k)
  	{
    		case 0: for(r=0;r<10;r++)
	      		{
	       			a[r]=0;
	       			b[r]=0;
	       			lub[r]=0;
							temp[r]=0;
							perm[r]=0;
	      		}
    		case 1: lhsLen=0;
	   		for(i=0;i<100;i++)
	      		{
				lhs[i]=0;
				valL[i]=0;
				eleL[i]=0;
			}
    		case 2: rhsLen=0;
	   		for(i=0;i<100;i++)
	      		{
				rhs[i]=0;
				valR[i]=0;
				eleR[i]=0;
			}
  	}

}

//Funtion to begin calculating hardness of r

void tempf()
{
	int l,y=4,x=33;
  char in;
  disp(5);
  while(l)
  {
    temp[5] = temp[0]/162.0*100 + temp[1]/146.0*100 + temp[2] + temp[3]/84.0*100 + temp[4];
		temp[6] = temp[5] + perm[7];
    disp(5);
    gotoxy(x,y);
    in=getch();
    if(in==0)
     {
       x=wherex();y=wherey();
       in=getch();
       switch(in)
       {
	 case 80: if (y==8) y-=4; else y++; break;
	 case 72: if (y==4) y+=4; else y--; break;
       }
       clrscr();
       disp(5);
       gotoxy(x,y);
     }
    else if(in>='0' && in<='9' || in=='.')
     {
			 int r=1,c;
			 char inl,*st;
			 char inlc[30];
       y=wherey();
			 cout<<in;
			 inlc[0]=in;
			 for(c=1;r!=0;)
			 {
				 inl=getch();
				 if(inl>='0' && inl<='9' || inl=='.') cout<<inl;
				 if(inl==13 || inl==0)
					 {inlc[c]='\0';r=0;if(inl==0)getch();}
				 else if(inl==8)
					{
						c--;
						inlc[c]='\0';
						cout<<"\b \b";
					}
				 else {inlc[c]=inl;c++;}
			 }
			 temp[y-4]=strtod(inlc,&st);
       clrscr();
       disp(5);
       if(y!=8) y++;
       else y-=4;
       gotoxy(x,y);
     }
    else if(in=='r' || in=='R')
     {
       reset(0);
       disp(5);
     }
    else if(in=='q' || in=='Q' || in==27)
     {
       l=0;
     }
    else if(in=='n'|| in=='N')
     {
       l=0;
       permf();
     }
    else inv(6);
  }
 	clrscr();
}


void permf()
{
	int l,y=4,x=33;
  char in;
  disp(6);
  while(l)
  {

		perm[7] = perm[0]/136.0*100 + perm[1]/120.0*100 + perm[2]/111.0*100 + perm[3]/95.0*100 + perm[4]/124.0*100 + perm[5] + perm[6];
		temp[6] = temp[5] + perm[7];
    disp(6);
    gotoxy(x,y);
    in=getch();
    if(in==0)
     {
       x=wherex();y=wherey();
       in=getch();
       switch(in)
       {
	 		 		case 80: if (y==10) y-=6; else y++; break;
	 	 			case 72: if (y==4) y+=6; else y--; break;
       }
       clrscr();
       disp(6);
       gotoxy(x,y);
     }
    else if(in>='0' && in<='9' || in=='.')
     {
			 int r=1,c;
			 char inl,*st;
			 char inlc[30];
       y=wherey();
			 cout<<in;
			 inlc[0]=in;
			 for(c=1;r!=0;)
			 {
				 inl=getch();
				 if(inl>='0' && inl<='9' || inl=='.') cout<<inl;
				 if(inl==13 || inl==0)
					 {inlc[c]='\0';r=0;if(inl==0)getch();}
				 else if(inl==8)
					{
						c--;
						inlc[c]='\0';
						cout<<"\b \b";
					}
				 else {inlc[c]=inl;c++;}
			 }
			 perm[y-4]=strtod(inlc,&st);
       clrscr();
       disp(6);
       if(y!=10) y++;
       else y-=6;
       gotoxy(x,y);
     }
    else if(in=='r' || in=='R')
     {
       reset(0);
       disp(6);
     }
    else if(in=='q' || in=='Q' || in==27)
     {
       l=0;
     }
    else if(in=='n'|| in=='N')
     {
       l=0;
       tempf();
     }
    else inv(7);
  }
 	clrscr();
}

//Funtion to begin game

void game(int x)
{
	textcolor(15);
	clrscr();
	gotoxy(25, 9); cout<<"         INSTRUCTIONS:";
	gotoxy(25, 11); cout<<"Arrow keys to move snake around.	";
	gotoxy(25, 12); cout<<"       Press P to Pause.		";
	gotoxy(25, 13); cout<<"     Press Escape to Quit	";
	gotoxy(25, 15); cout<<" Press S to Return to Studies.	";
	gotoxy(24, 22); cout<<"PRESS ENTER TO CONTINUE TO GAME!";
	if(x == 0)
	{
		int c = getch();
		switch (c)
		{
			case 13: snakeGame(); break;
			case 's':
			case 'S': break;
			case 27: home(); exit(0);
			default: gotoxy(33, 17); cout<<"INVALID INPUT!"; getch(); fflush(stdin); game(0);
		}
	}
	_setcursortype(_NORMALCURSOR);
}

void snakeGame()
{
	int i, j, k = 0;
	clrscr();
	randomize();
	_setcursortype(_NOCURSOR);

	crash:
	textcolor(2);
	clrscr();
	tail=0;
	dir= 'r';

	{
		headx=random(79 - 2 + 1) + 2;
		heady=random(23 - 2 + 1) + 2;
		snake[0][0]=headx;
		snake[0][1]=heady;
	}

	textcolor(2);
	clrscr();
	for(int xy = 1; xy <= 80; xy++)
	{
		textcolor(2);
		gotoxy(xy, 1); cprintf("X"); gotoxy(1, 1);
		gotoxy(xy, 24); cprintf("X"); gotoxy(1, 1);
	}
	for(int yx = 1; yx <= 24; yx++)
	{
		textcolor(2);
		gotoxy(1, yx); cprintf("X"); gotoxy(1, 1);
		gotoxy(80, yx); cprintf("X"); gotoxy(1, 1);
	}

	food:
	for(i=0; i < 1; i++)
	do
	{
		foodx=random(79 - 2 + 1) + 2;
		foody=random(23 - 2 + 1) + 2;
		food[i][0]=foodx;
		food[i][1]=foody;
	}while(foodx == 0 && foody == 0);

	for(i=0; i < 1; i++)
	{
		foodx=food[i][0];
		foody=food[i][1];
		gotoxy(foodx, foody);
		if(food[i][0]!=0)
		cout<<"*";
	}

	main_loop:
	if(headx == 1 || headx == 80 || heady == 1 || heady == 24)
		goto damn;

	{
		tailx=snake[tail][0];
		taily=snake[tail][1];
		headx=snake[0][0];
		heady=snake[0][1];
	}

	if(tail!=0)
	{
		for(i = tail; i > 0; i--)
		{
			snake[i][0]=snake[i-1][0];
			snake[i][1]=snake[i-1][1];
		}
	}

	if(tailx != 0 && taily != 0)
	{
		gotoxy(tailx, taily);
		cout<<" ";
	}

	chdir:
	switch(dir)
	{
		case 'u': if(heady>0)
			  heady-=1;
			  snake[0][1]=heady;
			  break;
		case 'd': if(heady<24)
			  heady+=1;
			  snake[0][1]=heady;
			  break;
		case 'l': if(headx>1)
			  headx-=1;
			  snake[0][0]=headx;
			  break;
		case 'r': if(headx<80)
			  headx+=1;
			  snake[0][0]=headx;
			  break;
		case 'p': dir='p';
			  getch();
			  break;
	}

	for(i=1; i < tail; i++)
	{
		if(headx == 1 || headx == 80 || heady == 1 || heady == 24)
			goto damn;

		if(headx == snake[i][0] && heady == snake[i][1])
		{
			damn:
			textcolor(4); clrscr();
			gotoxy(34, 12); cout<<"GAME OVER!!!";
			if(tail > 9)
			{
				gotoxy(34, 13); cout<<" SCORE = "<<tail;
			}
			else
			{
				gotoxy(34, 13); cout<<" SCORE = 0"<<tail;
			}
			gotoxy(24, 22); cout<<"   Press Enter to Play Again!	";
			gotoxy(24, 23); cout<<" Press Esc to Quit to Main Menu	";
			char go = getch();
			if(go == 13)
				goto crash;
			else if(go == 27)
			{
				textcolor(15); home(); k++; exit(0);
			}
		}
	}

	if(snake[0][0]!=0 && snake[0][1]!=0)
	{
		gotoxy(snake[0][0], snake[0][1]);
		cout<<"#";
	}

	for(i=0; i<1; i++)
	{
		foodx=food[i][0];
		foody=food[i][1];
		if(headx==foodx && heady==foody && food[i][0]!=0)
		{
			food[i][0]=0;
			tail++;
			for(i=0; i < 1; i++)
			do
			{
				foodx=random(78 - 1 + 1) + 2;
				foody=random(23 - 3 + 1) + 3;
				food[i][0]=foodx;
				food[i][1]=foody;
			}while(foodx == 0 && foody == 0);

			for(i=0; i < 1; i++)
			{
				foodx=food[i][0];
				foody=food[i][1];
				gotoxy(foodx, foody);
				if(food[i][0]!=0)
				cout<<"*";
			}
		}
	}

	delay(100);
	if(kbhit())
	{
		asd:key=getch();
		switch(key)
		{
			case 72: if(dir!='d')
					dir='u';
				 break;
			case 80: if(dir!='u')
					dir='d';
				 break;
			case 75: if(dir!='r')
					dir='l';
				 break;
			case 77: if(dir!='l')
					dir='r';
				break;
			case 'p': dir='p';
				  break;
			case 27: game(1); k++;
				 break;
			case 0: goto asd;
		}
	}
	if(k == 0)
		goto main_loop;
}


//Funtion to open calculator

void dispCalc()
{
	gotoxy(4,20); printf("Enter Operands with the Operator");
	gotoxy(4,22); printf("Press M for Memory");
	gotoxy(4,23); printf("Press R to Reset");
	gotoxy(4,24); printf("Press Esc to Return");
	gotoxy(4, 2); printf("Calculate: ");
}

void calculator()
{
	clrscr();
	float a, b, mem = 0, res = 0, in;
	char op;
	dispCalc();
	gotoxy(4, 21); cout<<"Memory = "<<mem; gotoxy(15,2);

	run:
	in = getch();

	if(in == ' ' || in == 13)
	{
		cout<<" ";
		goto run;
	}
	else if(in == 27)
	{
		exit(0);
	}
	else if(in == 'M' || in == 'm')
	{
		a = mem; cout<<mem;
		op = getche();
		b = (int)getche() - 48;
		switch(op)
		{
			case '+': res = a + b; break;
			case '-': res = a - b; break;
			case '*': res = a * b; break;
			case '/': res = a / b; break;
		}
		mem = res;
	}
	else
	{
		a  = (int)in - 48; cout<<a;
		op = getche();
		b  = (int)getche() - 48;
		switch(op)
		{
			case '+': res = a + b; break;
			case '-': res = a - b; break;
			case '*': res = a * b; break;
			case '/': res = a / b; break;
		}
		mem = res;
	}

	gotoxy(4, 4); cout<<" = "<<res;
	getch();
}

//Main funtion to start program

void main()
{
	home();
}
