#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void clearScreen()
{	
COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

int main()
{
	int h,m,s,a,b,c,t;//Declaring variables to use in the program
	
	char *Des[5]={"1st","2nd","3rd","4th","5th"};//Array of string to be used in the program
	
	a=h=m=s=0;//assigning starting value to variables
	
	cout<<"Enter the active session duration in minutes: ";//asking for user to enter data
	cin>>b;
	cout<<"Enter the rest session duration in seconds: ";
	cin>>c;
	cout<<"Enter the number of time you would like to alternate the Reps: ";
	cin>>t;
	system("cls");
	
	for(int i=0;i<t;i++)//looping the process to repeat as many times as needed
	{
		while(a==0)
		{
			clearScreen();//system ("cls");//clears execute window
			cout<<Des[i]<<" Active session in progress."<<endl;//displays message
			cout<<h<<":"<<m<<":"<<s<<endl;
			Sleep(100);//resting duration of system to create a second
			s++;//Increases the value of s by 1
			if(s>59)//condition to reset the second mark
			{
				s=0;
				m++;//increases the value of minute by 1 every time s reaches 60.
				if(m==b)//condition for when the minute mark meets what the user has entered as desired minute
				{
					h=m=s=0;//resets timer for resting period
					do
					{	
						clearScreen();//system("cls");
						cout<<Des[i]<<" Rest session in progress."<<endl;
						cout<<h<<":"<<m<<":"<<s<<endl;
						Sleep(100);
						s++;
					}while(s!=c);//Loop untill the second increases to what the user as entered as desired resting period
					a++;//increase the value of a to get out of loop
					h=m=s=0;
				}
			}
		}
		cout<<Des[i]<<" Rep is complete."<<endl;//Marker for which session is complete
		getch();
		a=0;//Re-enter the while loop
	}
	system("cls");
	cout<<"Congratulations on your wokrout."<<endl;
	getch();
	return 0;
}
