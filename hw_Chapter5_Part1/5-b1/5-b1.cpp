/*2553149     卓01    谢怡萱*/
#include <iostream>
using namespace std;

int main()
{
  
    int inorder[21];
    int n = 0;       // 记录实际输入了多少个数
    int temp;        // 临时存输入的变量

    cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl; 
    for (n = 0; n < 20; n++) // 最多读20个 
    {
        cin >> temp;
        if (temp <= 0) 
        {
            break; // 碰到0或负数，立刻停止读取，n此时的值就是有效个数
        }
        inorder[n] = temp;
    }

    if (n == 0||cin.fail())
    {
        cout << "无有效输入" << endl;
        return 0; // 直接结束程序
    }

    // 如果读满了20个，缓冲区里可能还有剩下的数和回车，必须吃掉，否则会影响后面读取插入数
    if (n == 20) {
        cin.ignore(10000, '\n');
    }

    cout << "原数组为：" << endl;
    for (int i = 0; i < n; i++) {
        cout << inorder[i] << " ";
    }
    cout << endl;

    
    int insert_num;
    cout << "请输入要插入的正整数" << endl;
    cin >> insert_num;

    // 从“最后一个数”开始，倒着往前检查

    int i; 

    for (i = n - 1; i >= 0; i--)
    {
        // 如果当前这个数(inorder[i]) 比 要插入的数(insert_num) 大
        if (inorder[i] > insert_num)
        {
            inorder[i+1] = inorder[i]; 
        }
        else
        {
            break;
        }
    }

    inorder[i + 1] = insert_num;

    n++;

    // ====================================================

   cout << "插入后的数组为：" << endl;
    for (int j = 0; j < n; j++) {
        cout << inorder[j] << " ";
    }
    cout << endl;

    return 0;
}