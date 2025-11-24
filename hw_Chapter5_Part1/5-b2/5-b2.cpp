/*2553149	卓01	谢怡萱*/
#include <iostream>
using namespace std;

int main()
{
	int lamps[101];
	int i;
	for (i = 0; i <= 100; i++)
	{
		lamps[i] = 0;    //0代表灭灯（遗憾离场）；1代表亮灯（已心动）
	}

	int lighters;
	int n;
	for (lighters = 1; lighters <= 100; lighters++)
	{
		for (n = lighters; n <= 100; n+=lighters)
		{
				lamps[n] = !(lamps[n]);
		}
	}

	bool first = 1;
	for (i = 1; i <= 100; i++)   
	{
		if (lamps[i])
		{
			if (!first)
				cout << " ";
			cout << i;
			first = 0;
		}
	}

	cout << endl;
	return 0;
}