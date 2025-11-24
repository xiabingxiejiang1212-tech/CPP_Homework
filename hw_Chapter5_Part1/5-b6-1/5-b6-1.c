/*2553149	卓01	谢怡萱*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void showtowers();
void init(int n, char src);
void move(int n, char from, char to);
void hanoi(int n, char src, char tmp, char dst);

int top_A = 0, top_B = 0, top_C = 0;
int a[11], b[11], c[11];
int steps = 0;

void init(int n, char src)
{
	int i;
	if (src == 'A')
	{
		top_A = n;
		for (i = 0; i < n; i++)
			a[i] = n - i;
	}
	else if (src == 'B')
	{
		top_B = n;
		for (i = 0; i < n; i++)
			b[i] = n - i;
	}
	else
	{
		top_C = n;
		for (i = 0; i < n; i++)
			c[i] = n - i;
	}

	printf("初始:                ");
	showtowers();
}

void move(int n, char from, char to)
{
	int disk;

	if (from == 'A')
		disk = a[--top_A];
	else if (from == 'B')
		disk = b[--top_B];
	else
		disk = c[--top_C];

	if (to == 'A')
		a[top_A++] = disk;
	else if (to == 'B')
		b[top_B++] = disk;
	else
		c[top_C++] = disk;

	steps++;

	printf("第%4d 步(%2d):", steps, disk);
	printf(" %c-->%c ", from, to);

	showtowers();
}

void showtowers()
{
	int i;
	printf("A:");
	for (i = 0; i < top_A; i++)
	{
		if (i == 0)
			printf("%2d", a[i]);
		else
			printf(" %d", a[i]);
	}

	for (i = 0; i < (10 - top_A); i++)
	{
		printf("  ");
	}

	printf(" ");

	printf("B:");
	for (i = 0; i < top_B; i++)
	{
		if (i == 0)
			printf("%2d", b[i]);
		else
			printf(" %d", b[i]);
	}

	for (i = 0; i < (10 - top_B); i++)
	{
		printf("  ");
	}

	printf(" ");

	printf("C:");
	for (i = 0; i < top_C; i++)
	{
		if (i == 0)
			printf("%2d", c[i]);
		else
			printf(" %d", c[i]);
	}
	for (i = 0; i < (10 - top_C); i++)
	{
		printf("  ");
	}
	printf("\n");
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
	char src, dst, tmp;

	while (1)
	{
		printf("请输入汉诺塔的层数(1-10)\n");
		if (scanf("%d", &n) != 1)
		{
			while (getchar() != '\n');
			continue;
		}
		if (n < 1 || n > 16)
		{
			while (getchar() != '\n');
			continue;
		}

		while (getchar() != '\n');
		break;
	}

	while (1)
	{
		printf("请输入起始柱(A-C)\n");
		scanf(" %c", &src);

		while (getchar() != '\n');

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
	while (1)
	{
		printf("请输入目标柱(A-C)\n");
		scanf(" %c", &dst);

		while (getchar() != '\n');

		if (dst == 'a' || dst == 'b' || dst == 'c')
		{
			dst = dst - 32;
		}
		if (dst == 'A' || dst == 'B' || dst == 'C')
		{
			if (dst == src)
			{
				printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
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