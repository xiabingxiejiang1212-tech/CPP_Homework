/*2553149    卓01    谢怡萱*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int score[1000];
	int count[101] = { 0 };
	int n = 0;
	int temp;
	int i, j;

	printf("请输入成绩（最多1000个），负数结束输入\n");

	for (n = 0; n < 1000; n++)
	{
		scanf("%d", &temp);
		if (temp < 0)
		{
			break;
		}
		score[n] = temp;

		count[temp]++;
	}
	if (n == 0) {
		printf("无有效输入\n");
		return 0;
	}

	printf("输入的数组为:\n");

	for (i = 0; i < n; i++)
	{
		printf("%d ", score[i]);
		if (!((i + 1) % 10))
			printf("\n");
	}

	if (n % 10 != 0)
		printf("\n");

	printf("分数与人数的对应关系为:\n");

	for (j = 100; j >= 0; j--)
	{
		if (count[j] > 0)
		{
			printf("%d %d\n", j, count[j]);
		}
	}
	return 0;
}