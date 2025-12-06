/*2553149    谢怡萱    卓01*/
/* */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char map[12][28] = { 0 };
	int count = 0;
	int i, j;
    int tnt = 0;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 26; j++)
		{
			scanf("%c", &map[i][j]);
			if (map[i][j] == '*')
				count++;
		}
	}
	if (count != 50)
	{
		printf("错误1\n");
		return 0;
	}
    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= 26; j++)
        {
            // 如果是雷，跳过不检查
            if (map[i][j] == '*')
                continue;

            // 重算周围的雷数（逻辑同 5-b13）
            tnt = 0;
            if (map[i - 1][j - 1] == '*') tnt++;
            if (map[i - 1][j] == '*') tnt++;
            if (map[i - 1][j + 1] == '*') tnt++;
            if (map[i][j - 1] == '*') tnt++;
            if (map[i][j + 1] == '*') tnt++;
            if (map[i + 1][j - 1] == '*') tnt++;
            if (map[i + 1][j] == '*') tnt++;
            if (map[i + 1][j + 1] == '*') tnt++;

            if (map[i][j] != (tnt + '0'))
            {
                printf("错误 2\n");
                return 0;
            }
        }
    }
    printf("正确\n");
    return 0;
}