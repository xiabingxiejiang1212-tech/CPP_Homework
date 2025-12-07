/*卓01    2553149    谢怡萱*/#include <iostream>
#include <conio.h>   //本源程序允许使用，因为要_getch()
#include "hanoi_const_value.h"
#include <iomanip>
using namespace std;
void perform_move_logic(int mode, char src, char dst, int* step, int towers[3][MAX_LAYER], int heights[3]);

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
void hanoi_universal(int n, char src, char aux, char dst,
    int mode, int* step, int towers[3][MAX_LAYER], int heights[3])
{
    if (n == 0) 
        return;

    hanoi_universal(n - 1, src, dst, aux, mode, step, towers, heights);

    perform_move_logic(mode, src, dst, step, towers, heights);

    hanoi_universal(n - 1, aux, src, dst, mode, step, towers, heights);
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

int char_to_index(char c) {
    if (c == 'A') 
        return 0;
    if (c == 'B') 
        return 1;
    else
        return 2;
}

void move_disk_data(int towers[3][MAX_LAYER], int heights[3], char src, char dst) {
    int s = char_to_index(src);
    int d = char_to_index(dst);
    if (heights[s] <= 0) 
        return;

    int disk = towers[s][heights[s] - 1];
    heights[s]--;

    towers[d][heights[d]] = disk;
    heights[d]++;
}

void print_horizontal(int towers[3][MAX_LAYER], int heights[3]) 
{
    char names[] = { 'A', 'B', 'C' };

    for (int i = 0; i < 3; i++) 
    {
        cout << names[i] << ": ";

        for (int j = 0; j < heights[i]; j++) 
        {

            cout << towers[i][j] << " ";
        }

        cout << endl;
    }
    cout << "--------------------------------" << endl;
}

void print_vertical(int towers[3][MAX_LAYER], int heights[3], int max_h) {
    // [逻辑来自 5-b7-main.cpp] 从高到低遍历
    for (int i = max_h - 1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (i < heights[j]) {
                // [逻辑来自 5-b7-main.cpp] 打印盘子数字
                cout << setw(4) << towers[j][i] << "   ";
            }
            else {
                // [逻辑来自 5-b7-main.cpp] 打印柱子杆
                cout << "   |   ";
            }
        }
        cout << endl;
    }
    // [逻辑来自 5-b7-main.cpp] 底部基座
    cout << "=======A=======B=======C=======" << endl;
    cout << "--------------------------------" << endl;
}

void perform_move_logic(int mode, char src, char dst, int* step, int towers[3][MAX_LAYER], int heights[3])
{
    //4-b13-1.cpp]
    if (mode == 1) 
    {
        cout << src << " -> " << dst << endl;
    }
    else if (mode == 2) 
    {
        if (step) (*step)++;
        cout << "[" << (step ? *step : 0) << "] " << src << " -> " << dst << endl;
    }
    // [5-b6-2.cpp 和 5-b7-main.cpp]
    else if (mode >= 3) 
    {
        // 先移动数据
        move_disk_data(towers, heights, src, dst);

        // 再根据模式选择打印函数
        if (mode == 3) print_horizontal(towers, heights);
        else print_vertical(towers, heights, MAX_LAYER);
    }
}



void hanoi_solution_1() 
{
    int n; char src, aux, dst;
    get_hanoi_params(&n, &src, &aux, &dst); 
    system("cls");
    
    hanoi_universal(n, src, aux, dst, 1, nullptr, nullptr, nullptr);
    cout << "按回车键继续" << endl;
    while (_getch() != 13);
}

void hanoi_solution_2() 
{
    int n; char src, aux, dst;
    get_hanoi_params(&n, &src, &aux, &dst);

    int steps = 0;
    system("cls");

    hanoi_universal(n, src, aux, dst, 2, &steps, nullptr, nullptr);

    cout << "按回车键继续" << endl;
    while (_getch() != 13);
}

void hanoi_solution_3() 
{
    int n; char src, aux, dst;
    get_hanoi_params(&n, &src, &aux, &dst);

    int towers[3][MAX_LAYER] = { 0 };
    int heights[3] = { 0 };
    int s_idx = char_to_index(src);
    for (int i = 0; i < n; i++) 
        towers[s_idx][i] = n - i;
    heights[s_idx] = n;

    system("cls");

    print_horizontal(towers, heights);
    hanoi_universal(n, src, aux, dst, 3, nullptr, towers, heights);

    cout << "按回车键继续" << endl;
    while (_getch() != 13);
}

void hanoi_solution_4() 
{
    int n; char src, aux, dst;
    get_hanoi_params(&n, &src, &aux, &dst);

    int towers[3][MAX_LAYER] = { 0 };
    int heights[3] = { 0 };
    int s_idx = char_to_index(src);
    for (int i = 0; i < n; i++) towers[s_idx][i] = n - i;
    heights[s_idx] = n;

    system("cls");
 
    print_vertical(towers, heights, MAX_LAYER);
    _getch(); 

    hanoi_universal(n, src, aux, dst, 4, nullptr, towers, heights);

    cout << "按回车键继续" << endl;
    while (_getch() != 13);
}