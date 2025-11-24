/*2553149	卓01	谢怡萱*/
#include <iostream>
using namespace std;

bool isleap(int year)
{
	if (!(year % 4) && year % 100 || !(year % 400))
		return 1;
	else
		return 0;
}

int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int countdays(int year, int month, int day)
{
	if (isleap(year))
		days[2] = 29;
	int n = 0;
	for (int i = 1; i < month; i++)
	{
		n += days[i];
	}
	n += day;
	return n;
}

int main()
{
	int year, month, day;
	int n = 0;
	

	cout << "请输入年，月，日" << endl;
	cin >> year >> month >> day;
	bool leap = isleap(year);

	if (month < 1 || month>12)
	{
		cout << "输入错误-月份不正确" << endl;
	}
	else
	{
		if (leap) 
			days[2] = 29;
		
		if (day<1 || day>days[month])
		{
			cout << "输入错误-日与月的关系非法" << endl;
		}
		else
		{
			n = countdays(year, month, day);
			cout << year << "-" << month << "-" << day << "是" << year << "年的第" << n << "天" << endl;

		}


	}

	return 0;

}