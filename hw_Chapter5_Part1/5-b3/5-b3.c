/*2553149	卓01	谢怡萱*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isleap(int year)
{
	if (!(year % 4) && year % 100 || !(year % 400))
		return 1;
	else
		return 0;
}

int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int countdays(int year, int month, int day)
{
	int n = 0;
	int i;
	if (isleap(year))
		days[2] = 29;

	for (i = 1; i < month; i++)
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
	int leap;

	printf("请输入年，月，日\n");
	scanf("%d %d %d", &year, &month, &day);

	leap = isleap(year);

	if (month < 1 || month>12)
	{
		printf("输入错误-月份不正确\n");
	}
	else
	{
		if (leap)
			days[2] = 29;

		if (day < 1 || day > days[month])
		{
			printf("输入错误-日与月的关系非法\n");
		}
		else
		{
			n = countdays(year, month, day);
			printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, n);
		}
	}

	return 0;
}