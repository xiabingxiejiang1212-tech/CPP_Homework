/*2553149    卓01    谢怡萱*/
#include <iostream>
using namespace std;

int main()
{
	int score[1000];
	int count[101] = { 0 };
	int n = 0;

	cout << "请输入成绩（最多1000个），负数结束输入" << endl;

	for (n = 0; n < 1000; n++)
	{
		int temp;
		cin >> temp;
		if (temp < 0)
		{
			break;
		}
		score[n] = temp;

		count[temp]++;
	}
	if (n == 0) {
		cout << "无有效输入" << endl;
		return 0;
	}

	cout << "输入的数组为:" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << score[i] << " ";
		if (!((i + 1) % 10))
			cout << endl;
	}

	if (n % 10 != 0)
		cout << endl;

	cout << "分数与名次的对应关系为:" << endl;

	int current_rank = 1; 

	for (int j = 100; j >= 0; j--)
	{
		// 如果这个分数有人考
		if (count[j] > 0)
		{
			for (int k = 0; k < count[j]; k++)
			{
				cout << j << " " << current_rank << endl;
			}

			current_rank += count[j];
		}
	}

	return 0;
}