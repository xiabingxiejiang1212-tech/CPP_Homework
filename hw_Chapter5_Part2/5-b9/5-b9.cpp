/*2553149    谢怡萱    卓01*/
#include <iostream>
using namespace std;

int main()
{
	int map[9][9];
	bool issudoku;

	cout << "请输入9*9的矩阵，值为1-9之间" << endl;

	for (int i = 0; i < 9; i++)
	{
		for(int j=0;j<9;j++)
			while (true)
			{
				int tmp;
				cin >> tmp;

				if (cin.fail())
				{
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					cin.clear();
					cin.ignore(10000,'\n');
					continue;
				}
				if (tmp >= 1 && tmp <= 9)
				{
					map[i][j] = tmp;
					break;
				}
				else
				{
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}
			}
	}

	for (int i = 0; i < 9; i++)
	{
		int check[10] = { 0 };
		for (int j = 0; j < 9; j++)
		{
			int num = map[i][j];
			if (check[num] == 1)
			{
				issudoku = false;
				break;
			}
			check[num] = 1;
		}
		if (!issudoku)
			break;
	}

	for (int i = 0; i < 9; i++)
	{
		int check[10] = { 0 };
		for (int j = 0; j < 9; j++)
		{
			int num = map[j][i];
			if (check[num] == 1)
			{
				issudoku = false;
				break;
			}
			check[num] = 1;
		}
		if (!issudoku)
			break;
	}

	if (issudoku)
	{
		for (int r = 0; r < 3; r++)
		{
			for(int c=0;c<3;c++)
			{
				int check[10] = { 0 };

				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						int num = map[r * 3 + i][c * 3 + j];
						if (check[num] == 1)
						{
							issudoku = false;
							break;
						}
						check[num] = 1;
					}
					if (!issudoku)
						break;
				}
				if (!issudoku)
					break;
			}
			if (!issudoku)
				break;
		}
		
	}
	if (issudoku)
		cout << "是数独的解" << endl;
	else
		cout << "不是数独的解" << endl;
	return 0;
}