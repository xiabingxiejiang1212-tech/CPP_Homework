/*2553149    谢怡萱    卓01*/
#include<iostream>
#include<iomanip>
using namespace std;
const int month_width = 28;
const int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

bool is_leap(int year)
{
	if (!(year % 4) && year % 100 || !(year % 400))
		return true;
	else
		return false;
}

int countdays(int year, int month)
{
	if (month == 2 && is_leap(year))
		return 29;
	else
		return days[month];
}

int get_weekday(int y, int m, int d)
{
	if (m == 1 || m == 2)
	{
		y = y - 1;
		m = m + 12;
	}

	int c = y / 100;
	y = y % 100;

	int w = y + (y / 4) + (c / 4) - (2 * c) + (13 * (m + 1) / 5) + d - 1;

	w = (w % 7 + 7) % 7;
	return w;
}

void print_monthtitle(int start_month, int month_per_row)
{
	for (int m = 0; m < month_per_row; m++)
	{
		int month = start_month + m;
		if (month > 12)
			break;

		int width = (month >= 10 ? 2 : 1) + 2;
		int left_spaces = (month_width - width-1) / 2;
		int right_spaces = month_width - left_spaces - width;

		for (int i = 0; i < left_spaces; i++)
			cout << " ";

		cout << month << "月";

		for (int i = 0; i < right_spaces; i++)
			cout << " ";

		if (m < month_per_row)
			cout << "    ";
	}
	cout << endl;
}

void print_weektitle(int start_month, int month_per_row)
{
	for (int m = 0; m < month_per_row; m++)
	{
		if (start_month + m > 12)
			break;

		cout << "Sun Mon Tue Wed Thu Fri Sat ";

		if (m < month_per_row - 1)
			cout << "    ";
	}
	cout << endl;
}

void print_daysline(int start_month, int month_per_row, int row, const int month_days[], const int month_start_weekday[])
{
	for (int m = 0; m < month_per_row; m++)
	{
		int month = start_month + m;
		if (month > 12)
			break;
		int totaldays = month_days[month];
		int first_weekday = month_start_weekday[month];

		for (int w = 0; w < 7; w++)
		{
			int day = row * 7 + w - first_weekday + 1;

			if (day <= 0 || day > totaldays)
				cout << "    ";
			else
				cout<<setiosflags(ios::left)<< setw(3) << day << " ";
		}
		if (m < month_per_row - 1)
			cout << "    ";
	}
	cout << endl;
}

int get_rows(int total_days, int first_weekday)
{
	int days_in_firstrow = 7 - first_weekday;
	if (total_days <= days_in_firstrow) return 1; // 只有1行的情况

	int remaining_days = total_days - days_in_firstrow;
	
	return 1 + (remaining_days + 6) / 7;

}

int main()
{
	int year, month_per_row;
	cout << "请输入年份[1900-2100]" << endl;
	cin >> year;
	cout << "请输入每行打印的月份数[1/2/3/4/6/12]" << endl;
	cin >> month_per_row;

	int month_days[13];
	int month_start_weekday[13];

	for (int m = 1; m <= 12; m++)
	{
		if (m == 2 && is_leap(year))
			month_days[m] = 29;
		else
			month_days[m] = days[m];

		month_start_weekday[m] = get_weekday(year, m, 1);
	}
	cout << year << "年的日历:" << endl;
	cout << endl;

	for (int start_m = 1; start_m <= 12; start_m += month_per_row)
	{
		print_monthtitle(start_m, month_per_row);
		print_weektitle(start_m, month_per_row);

		int max_rows = 0;
		for (int k = 0; k < month_per_row; k++)
		{
			int m = start_m + k;
			if (m > 12) break;

			// 计算当前月行数
			int lines = get_rows(month_days[m], month_start_weekday[m]);
			if (lines > max_rows) 
				max_rows = lines;
		}

		for (int r = 0; r < max_rows; r++)
			print_daysline(start_m, month_per_row, r, month_days, month_start_weekday);
		cout << endl;
	}
	return 0;
}