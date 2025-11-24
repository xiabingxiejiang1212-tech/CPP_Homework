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

		count	[temp]++;
	}
	if (n == 0) {
		cout << "无有效输入" << endl;
		return 0;
	}

	cout << "输入的数组为:" << endl;

	for (int i = 0; i < n ; i++)
	{
		cout << score[i] << " ";
		if (!((i + 1) % 10))
			cout << endl;
	}

	if (n % 10 != 0)
	cout << endl;

	cout << "分数与人数的对应关系为:" << endl;
	
	for (int j = 100; j >= 0; j--)
	{
		if (count[j] > 0)
		{
			cout << j << " " << count[j] << endl;
		}
	}
	return 0;
}