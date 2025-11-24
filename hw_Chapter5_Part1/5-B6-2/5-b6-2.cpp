/*2553149    卓01    谢怡萱*/
#include <iostream>
#include <iomanip>
using namespace std;

void showtowers();
void init(int n, char src);
void move(int n, char from, char to);
void hanoi(int n, char src, char tmp, char dst);


int tops[3];
int towers[3][11];
int steps = 0;



void init(int n, char src)
{
    // 找到起始柱对应的下标 
    int row = src - 'A';

    tops[row] = n;

    for (int i = 0; i < n; i++)
    {
        towers[row][i] = n - i;
    }

    cout << "初始:                ";
    showtowers();
}

void move(int n, char from, char to)
{
    int disk;

    //算出源柱子(from)和目标柱子(to)的下标
    int f = from - 'A';
    int t = to - 'A';

    tops[f]--;
    disk = towers[f][tops[f]];

    towers[t][tops[t]] = disk;
    tops[t]++;

    steps++;
    cout << "第" << setw(4) << steps << " 步(" << setw(2) << disk << "):";
    cout << " " << from << "-->" << to << " ";

    showtowers();
}

void showtowers()
{
  
    for (int col = 0; col < 3; col++)
    {
        char name = 'A' + col;
        cout << name << ":";

        for (int i = 0; i < tops[col]; i++)
        {
            if (i == 0) 
				cout << setw(2) << towers[col][i];
            else        
				cout << " " << towers[col][i];
        }

		for (int i = 0; i < (10 - tops[col]); i++)
			cout << "  ";

        if (col < 2) // 如果是 A 或 B
           cout << " ";
        
    }
    cout << endl;
}

void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1)
	{
		move(n, src, dst);
	}
	else
	{
		hanoi(n - 1, src, dst, tmp);


		move(n, src, dst);

		hanoi(n - 1, tmp, src, dst);
	}
}

int main()
{
	int n;
	while (true)
	{
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> n;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		if (n < 1 || n > 16)
		{
			cin.ignore(10000, '\n');
			continue;
		}

		cin.ignore(10000, '\n');
		break;
	}

	char src, dst, tmp;
	while (true)
	{
		cout << "请输入起始柱(A-C)" << endl;
		cin >> src;

		cin.ignore(10000, '\n');

		if (src == 'a' || src == 'b' || src == 'c')
		{
			src = src - 32;
		}
		if (src == 'A' || src == 'B' || src == 'C')
		{
			break;
		}
		else
		{

			continue;
		}

	}
	while (true)
	{
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dst;

		cin.ignore(10000, '\n');

		if (dst == 'a' || dst == 'b' || dst == 'c')
		{
			dst = dst - 32;
		}
		if (dst == 'A' || dst == 'B' || dst == 'C')
		{
			if (dst == src)
			{
				cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
				continue;
			}

			break;
		}
		else
		{

			continue;
		}
	}


	if (src != 'A' && dst != 'A')
	{
		tmp = 'A';
	}
	else if (src != 'B' && dst != 'B')
	{
		tmp = 'B';
	}
	else
	{
		tmp = 'C';
	}

	init(n, src);

	hanoi(n, src, tmp, dst);

	return 0;
}