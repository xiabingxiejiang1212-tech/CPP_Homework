/*2553149    ×¿01    Ğ»âùİæ*/
#include <iostream>
#include <time.h>
using namespace std;
const int sum = 50;

int main()
{
	char map[12][28] = {0};
	srand((unsigned int)time(0));
	int count = 0;

	while (count < sum)
	{
		int r = (rand() % 10)+1;
		int c = (rand() % 26)+1;

		if (map[r][c] != '*')
		{
			map[r][c] = '*';
			count++;
		}
	}

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 26; j++)
		{
			if (map[i][j] == '*')
				continue;
			else
			{
				int tnt = 0;
				if (map[i - 1][j - 1] == '*')
					tnt++;
				if (map[i - 1][j] == '*')
					tnt++;
				if (map[i - 1][j + 1]=='*')
					tnt++;
				if (map[i][j - 1] == '*')
					tnt++;
				if (map[i][j + 1]=='*')
					tnt++;
				if (map[i + 1][j - 1] == '*')
					tnt++;
				if (map[i + 1][j] == '*')
					tnt++;
				if (map[i + 1][j + 1] == '*')
					tnt++;
				map[i][j] = tnt+'0';
			}
		}
	}
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 26; j++)
		{
			cout << map[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}