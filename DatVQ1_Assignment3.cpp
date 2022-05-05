#include <iostream>

using namespace std;

bool isLeapYear(int y)
{
	if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
		return true;
	}
	return false;
}

bool isMonth(int m)
{
	if ((12 >= m) && (m > 0))
	{
		return true;
	}
	return false;
}

int FindNumDayOfMonth (int m,int y)
{
	switch (m)
	{	
		case 2:
		{
			if (isLeapYear(y) == true)
				return 29;
			else return 28;
		}
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		default:
			return 30;
	}
	return 0;
}

bool isDay(int d, int m, int y)
{
	if (d <= FindNumDayOfMonth(m, y))
	{
		return true;
	}
	return false;
}

int ConvertToDayInYear(int d, int m, int y)
{
	int DIY = 0;
	int i = 0;
	do
	{
		i++;
		if (i == m)
		{
			DIY = DIY + d;
		}
		else
		{
			DIY = DIY + FindNumDayOfMonth(i, y);
		}
	} while (i < m);
	return DIY;
}

int ConvertFromDayInYear(int d, int &m, int &y)
{
	int DIM = 0;
	m = 0;
	while (d<=0)
	{
		if (isLeapYear(y))
		{
			d = d + 366;
		}
		else
		{
			d = d + 365;
		}
		y--;
	}
	do
	{
		if (m == 12)
		{
			m = 1;
			y++;
		}
		else
		{
			m++;
		}
		DIM = FindNumDayOfMonth(m, y);
		d = d - DIM;
	} while (d > 0);
	d = d + DIM;
	return d;
}

int main()
{
	int d, m, y, SelectNum;
	cout << "CALENDAR\n\n";
	cout << "dd/mm/yyyy\n";	
	cout << "date:";
	cin >> d;
	cout << "month:";
	cin >> m;
	cout << "year:";
	cin >> y;
	cout << "\n*==================*MENU*==================*\n";
	cout << "1. Find the number of month\n";
	cout << "2. Show next day (dd/mm/yyyy)\n";
	cout << "3. Show previous day (dd/mm/yyyy)\n";
	cout << "Input number: ";
	cin >> SelectNum ;
	switch (SelectNum)
	{
		case 1: 
		{
			if (isMonth(m) == true) 
			{
				cout << "\nDay of month: ";
				int day = FindNumDayOfMonth(m, y);
				cout << day;
			}
			else
			{
				cout << "\nThe month input is not valid";
			}
			break;
		}
		case 2:
		{
			if (isDay(d,m,y) == true && isMonth(m) == true)
			{
				int DIY = ConvertToDayInYear(d, m, y);
				int nextD = ConvertFromDayInYear(DIY+1, m, y);
				cout << "\nNext day: " << nextD << "/" << m << "/" << y;
			}
			else
			{
				cout << "\nYour input is not valid";
			}
			break;
		}
		case 3:
		{
			if (isDay(d, m, y) == true && isMonth(m) == true)
			{
				int DIY = ConvertToDayInYear(d, m, y);
				int preD = ConvertFromDayInYear(DIY - 1, m, y);
				cout << "\nNext day: " << preD << "/" << m << "/" << y;
			}
			else
			{
				cout << "\nYour input is not valid";
			}
			break;
		}
		default:
			break;
	}
}
