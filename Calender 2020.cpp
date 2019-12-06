// SEARCH  FESTIVAL IN 2020 CALENDER
#include <iostream>
#include <fstream>
using namespace std ;

class Date
{
	private:
		unsigned int day ;
		int month ;
		static unsigned int year ;
	public :
		int give_day()
		{
			return day ;
		}
		int give_month()
		{
			return month ;
		}
		void input	() ;
		void print	() ;
} ; // class Date
unsigned int Date::year = 2020 ;
void Date :: input()
{
	cout << "enter day : " ;
	cin >> day ;
	cout << "enter month(IN NUMBER) : " ;
	cin >> month ;
}// input
void Date :: print()
{
	if ( month <= 12 && month > 0 )
	{
		if ( month == 2 )
		{
			if(day > 29 || day <= 0 )
			{
				cout << "\nDate enter by you is not correct.\n" ;
				cout << "Re-enter it . \n" ;
				Date::input() ;
			}
		}
		else if ( month%2 == 0 )
		{
			if(day>30 || day <= 0 )
			{
				cout << "\nDate enter by you is not correct.\n" ;
				cout << "Re-enter it . \n" ;
				Date::input() ;
			}
		}
		else 
		{
			if(day>31 || day <= 0)
			{
				cout << "\nDate enter by you is not correct.\n" ;
				cout << "Re-enter it . \n" ;
				Date::input() ;
			}
		}
	}
	else
	{
		cout << "\nDate enter by you is not correct.\n" ;
		cout << "Re-enter it . \n" ;
		Date::input() ;
	}
	cout << "Date : " << day << "/" << month << "/" << year << endl  ;
}//print

void jan_April_july(Date d2) ;
void feb_august(Date d2) ;
void march_nov(Date d2) ;
void may(Date d2)  ;
void june(Date d2)  ;
void sept_dec(Date d2) ;
void oct(Date d2) ;

class Calender
{
	private :
		Date d1;
		char weekday[255] ;
		char festival[255] ;
	public :
		int dayc()
		{
			return d1.give_day();
		}
		int monthc()
		{
			return d1.give_month() ;
		}
		void input() ;
		void print() ;		
} ;
void Calender::input()
{
	d1.input() ;
	cin.ignore() ;
	cout << "enter day : " ;
	cin.getline(weekday,255) ;
	cout << "enter festival : " ;
	cin.getline(festival,255) ;
}
void Calender::print()
{
	d1.print() ;
	cout << "Day : " << weekday << endl ;
	cout << "Festival : " << festival << endl << endl ;
}
void inputDate()
{
	Calender c1 ;
	ofstream send ;
	send.open("Calender2020Festival.dat",ios::app|ios::binary) ;
	c1.input() ;
	send.write((char*)&c1,sizeof(Calender)) ;
	send.close() ;
}
void searchDate()
{
	Calender c1 ;
	int found = 0 ;
	Date d2 ;
	cout << "Write date then press <enter> and Write month press <enter> : \n" ;
	d2.input() ;
	ifstream readf ;
	readf.open("Calender2020Festival.dat",ios::binary) ;
	while(readf.read((char*)&c1, sizeof(Calender)) && found==0)
	{
		if(c1.dayc()==d2.give_day()&&c1.monthc()==d2.give_month())
		{
			cout << "\nDETAILS of DATE : \n" ;
			c1.print() ;
			found = 1 ;
		}
	}
	if(found==0)
	{
		cout << "\nDETAILS of DATE : \n" ;
		d2.print() ;
		if(d2.give_month()==1||d2.give_month()==4||d2.give_month()==7)
		{
			jan_April_july(d2) ; 
		}
		else if (d2.give_month()==2||d2.give_month()==8)
		{
			feb_august(d2) ;
		}
		else if (d2.give_month()==3||d2.give_month()==11)
		{
			march_nov(d2) ;
		}
		else if (d2.give_month()==5)
		{
			may(d2) ;
		}
		else if (d2.give_month()==6)
		{
			june(d2) ;
		}
		else if (d2.give_month()==9||d2.give_month()==12)
		{
			sept_dec(d2) ;
		}
		else if (d2.give_month()==10)
		{
			oct(d2) ;
		}
		cout << "Festival : NONE\n\n" ;
	}
}
int main()
{
	while(1)
	{
		cout << "SEARCH DETAILS OF DATE IN CALENDER OF 2020 ....\n" ;
		searchDate();
		system("pause") ;
		system("cls") ;
	}

	//outDate() ;
	return 0 ;
}
void jan_April_july(Date d2) 
{
	int l , m = d2.give_day() ;
	string s[7]	; 
	s[0] = "wednesday" ;		
	s[1] = "thursday" ;
	s[2] = "friday" ;
	s[3] = "saturday" ;
	s[4] = "sunday" ;
	s[5] = "monday" ;
	s[6] = "tuesday" ;
	if(d2.give_day()<=7)
	{
		for(int i = 0 ; i < 7 ; i++)
		{
			if(d2.give_day()==(i+1))
			{
				cout <<"Day : " << s[i] << endl ;;
				break ;
			}
		}
	}
	else
	{
		do
		{
			m-=7 ;
			l=m ;
		}while(m>8) ;
		for(int i = 0 ; i < 7 ; i++)
		{
			if(l==(i+1))
			{
				cout <<"Day : " << s[i] << endl ;
				break ;	
			}
		}
	}
}
void feb_august(Date d2)
{
	int l , m = d2.give_day() ;
	string s[7]	; 
	s[4] = "wednesday" ;		
	s[5] = "thursday" ;
	s[6] = "friday" ;
	s[0] = "saturday" ;
	s[1] = "sunday" ;
	s[2] = "monday" ;
	s[3] = "tuesday" ;
	if(d2.give_day()<=7)
	{
		for(int i = 0 ; i < 7 ; i++)
		{
			if(d2.give_day()==(i+1))
			{
				cout <<"Day : " << s[i] << endl ;;
				break ;
			}
		}
	}
	else
	{
		do
		{
			m-=7 ;
			l=m ;
		}while(m>8) ;
		for(int i = 0 ; i < 7 ; i++)
		{
			if(l==(i+1))
			{
				cout <<"Day : " << s[i] << endl ;
				break ;	
			}
		}
	}	
} 
void march_nov(Date d2)
{
	int l , m = d2.give_day() ;
	string s[7]	; 
	s[3] = "wednesday" ;		
	s[4] = "thursday" ;
	s[5] = "friday" ;
	s[6] = "saturday" ;
	s[0] = "sunday" ;
	s[1] = "monday" ;
	s[2] = "tuesday" ;
	if(d2.give_day()<=7)
	{
		for(int i = 0 ; i < 7 ; i++)
		{
			if(d2.give_day()==(i+1))
			{
				cout <<"Day : " << s[i] << endl ;;
				break ;
			}
		}
	}
	else
	{
		do
		{
			m-=7 ;
			l=m ;
		}while(m>8) ;
		for(int i = 0 ; i < 7 ; i++)
		{
			if(l==(i+1))
			{
				cout <<"Day : " << s[i] << endl ;
				break ;	
			}
		}
	}	
} 
void may(Date d2) 
{
	int l , m = d2.give_day() ;
	string s[7]	; 
	s[5] = "wednesday" ;		
	s[6] = "thursday" ;
	s[0] = "friday" ;
	s[1] = "saturday" ;
	s[2] = "sunday" ;
	s[3] = "monday" ;
	s[4] = "tuesday" ;
	if(d2.give_day()<=7)
	{
		for(int i = 0 ; i < 7 ; i++)
		{
			if(d2.give_day()==(i+1))
			{
				cout <<"Day : " << s[i] << endl ;;
				break ;
			}
		}
	}
	else
	{
		do
		{
			m-=7 ;
			l=m ;
		}while(m>8) ;
		for(int i = 0 ; i < 7 ; i++)
		{
			if(l==(i+1))
			{
				cout <<"Day : " << s[i] << endl ;
				break ;	
			}
		}
	}	
}
void june(Date d2) 
{
	int l , m = d2.give_day() ;
	string s[7]	; 
	s[2] = "wednesday" ;		
	s[3] = "thursday" ;
	s[4] = "friday" ;
	s[5] = "saturday" ;
	s[6] = "sunday" ;
	s[0] = "monday" ;
	s[1] = "tuesday" ;
	if(d2.give_day()<=7)
	{
		for(int i = 0 ; i < 7 ; i++)
		{
			if(d2.give_day()==(i+1))
			{
				cout <<"Day : " << s[i] << endl ;;
				break ;
			}
		}
	}
	else
	{
		do
		{
			m-=7 ;
			l=m ;
		}while(m>8) ;
		for(int i = 0 ; i < 7 ; i++)
		{
			if(l==(i+1))
			{
				cout <<"Day : " << s[i] << endl ;
				break ;	
			}
		}
	}
}
void sept_dec(Date d2)
{
	int l , m = d2.give_day() ;
	string s[7]	; 
	s[1] = "wednesday" ;		
	s[2] = "thursday" ;
	s[3] = "friday" ;
	s[4] = "saturday" ;
	s[5] = "sunday" ;
	s[6] = "monday" ;
	s[0] = "tuesday" ;
	if(d2.give_day()<=7)
	{
		for(int i = 0 ; i < 7 ; i++)
		{
			if(d2.give_day()==(i+1))
			{
				cout <<"Day : " << s[i] << endl ;;
				break ;
			}
		}
	}
	else
	{
		do
		{
			m-=7 ;
			l=m ;
		}while(m>8) ;
		for(int i = 0 ; i < 7 ; i++)
		{
			if(l==(i+1))
			{
				cout <<"Day : " << s[i] << endl ;
				break ;	
			}
		}
	}	
} 
void oct(Date d2)
{
	int l , m = d2.give_day() ;
	string s[7]	; 
	s[0] = "wednesday" ;		
	s[1] = "thursday" ;
	s[2] = "friday" ;
	s[3] = "saturday" ;
	s[4] = "sunday" ;
	s[5] = "monday" ;
	s[6] = "tuesday" ;
	if(d2.give_day()<=7)
	{
		for(int i = 0 ; i < 7 ; i++)
		{
			if(d2.give_day()==(i+1))
			{
				cout <<"Day : " << s[i] << endl ;;
				break ;
			}
		}
	}
	else
	{
		do
		{
			m-=7 ;
			l=m ;
		}while(m>8) ;
		for(int i = 0 ; i < 7 ; i++)
		{
			if(l==(i+1))
			{
				cout <<"Day : " << s[i] << endl ;
				break ;	
			}
		}
	}
} 
