/*卓01    2553149    谢怡萱*/#include <iostream>
#include <conio.h>   //本源程序允许使用，因为要_getch()
#include "hanoi_const_value.h"
#include <iomanip>
using namespace std;



/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst,int *step)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp, step);

    if (step != NULL)
    {
        (*step)++;
        cout << "第" << setw(4) << step << " 步( " << n << "#: " << src << "-->" << dst << ")" << endl;
    }
    else
    {
        cout << n << "# " << src << "--->" << dst << endl;

    }
    hanoi(n - 1, tmp, src, dst,step);
}

void get_hanoi_params(int* n, char* src, char* tmp, char* dst)
{
    while (true)
    {
        cout << "请输入汉诺塔的层数(1-" << MAX_LAYER << ")：" << endl;
        cin >> *n;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if (*n < 1 || *n > MAX_LAYER)
        {
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore(10000, '\n');
        break;
    }
    while(true)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> *src;
        cin.ignore(10000, '\n');

        if (*src == 'a' || *src == 'b' || *src == 'c')
        {
            *src = *src - 32;
        }
        if (*src == 'A' || *src == 'B' || *src == 'C')
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
        cin >> *dst;
        cin.ignore(10000, '\n');

        if (*dst == 'a' || *dst == 'b' || *dst == 'c')
        {
            *dst = *dst - 32;
        }
        if (*dst == 'A' || *dst == 'B' || *dst == 'C')
        {
            if (*dst == *src)
            {
                cout << "目标柱(" << *dst << ")不能与起始柱(" << *src << ")相同" << endl;
                continue;
            }

            break;
        }
        else
        {

            continue;
        }
    }


    if (*src != 'A' && *dst != 'A')
    {
        *tmp = 'A';
    }
    else if (*src != 'B' && *dst != 'B')
    {
        *tmp = 'B';
    }
    else
    {
        *tmp = 'C';
    }
    }

void hanoi_option1()
{
    int n;
    char src, tmp, dst;

    get_hanoi_params(&n, &src, &tmp, &dst);
    hanoi(n, src, tmp, dst,NULL);
}

void hanoi_option2()
{
    int n;
    char src, tmp, dst;
    int total_steps = 0;

    get_hanoi_params(&n, &src, &tmp, &dst);
    hanoi(n, src, tmp, dst, &total_steps);
}