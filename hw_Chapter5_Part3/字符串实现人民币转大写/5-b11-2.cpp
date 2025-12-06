/*卓01    2553149    谢怡萱*/
#include <iostream>
#include <string>        //本程序允许使用string，不违规 
//可按需增加需要的头文件
using namespace std;
const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
const char block[] = "亿万仟佰拾圆整角分";
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
void daxie(int num, int flag_of_zero)
{
    switch (num) {
        case 0:
            if (flag_of_zero)
                result += string(&chnstr[0], 2);
            break;
        case 1:
            result += string(&chnstr[2], 2);
            break;
        case 2:
            result += string(&chnstr[4], 2);
            break;
        case 3:
            result += string(&chnstr[6], 2);
            break;
        case 4:
            result += string(&chnstr[8], 2);
            break;
        case 5:
            result += string(&chnstr[10], 2);
            break;
        case 6:
            result += string(&chnstr[12], 2);
            break;
        case 7:
            result += string(&chnstr[14], 2);
            break;
        case 8:
            result += string(&chnstr[16], 2);
            break;
        case 9:
            result += string(&chnstr[18], 2);
            break;
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    cout << "请输入[0-100亿)之间的数字:" << endl;

    double a = 0;
    cin >> a;

    cout << "大写结果是:" << endl;

    if (a >= 0 && a < 0.01)
    {
        daxie(0, 1);
        result += string(&block[10], 4);
        cout << result << endl;
        return 0;
    }

    int b = (int)(a / 10.0);
    int shiyi = b / 100000000;
    int yi = (b / 10000000) % 10;
    int qianwan = (b / 1000000) % 10;
    int baiwan = (b / 100000) % 10;
    int shiwan = (b / 10000) % 10;
    int wan = (b / 1000) % 10;
    int qian = (b / 100) % 10;
    int bai = (b / 10) % 10;
    int shi = b % 10;

    double c = (a / 10.0) - b;
    const double eps = 1e-7;
    double d = c + eps;
    int yuan = (int)(d * 10) % 10;
    int jiao = (int)(d * 100) % 10;
    int fen = (int)(d * 1000) % 10;

    bool zero = false;
    bool alreadyzero = false;
    int yuanblock = qian * 1000 + bai * 100 + shi * 10 + yuan;

    if (shiyi > 0)
    {
        daxie(shiyi, 0);
        result += string(&block[8], 2);
        alreadyzero = true;
    }
    if (yi > 0)
    {
        daxie(yi, 0);
        alreadyzero = true;
    }

    if (alreadyzero)
    {
        result += string(&block[0], 2);
    }

    int wanblock = qianwan * 1000 + baiwan * 100 + shiwan * 10 + wan;
    if (wanblock > 0)
    {
        if (alreadyzero && qianwan == 0)
        {
            daxie(0, 1);
            zero = true;
        }

        if (qianwan > 0)
        {
            daxie(qianwan, 0);
            result += string(&block[4], 2);
            zero = false;
        }
        if (baiwan > 0)
        {
            daxie(baiwan, 0);
            result += string(&block[6], 2);
            zero = false;
        }
        else if (qianwan > 0 && (shiwan > 0 || wan > 0) && zero == false)
        {
            daxie(0, 1);
            zero = true;
        }
        if (shiwan > 0)
        {
            daxie(shiwan, 0);
            result += string(&block[8], 2);
            zero = false;
        }
        else if ((qianwan > 0 || baiwan > 0) && wan > 0 && zero == false)
        {
            daxie(0, 1);
            zero = true;
        }
        if (wan > 0)
        {
            daxie(wan, 0);
        }
        result += string(&block[2], 2);
        alreadyzero = true;
    }

    if (yuanblock > 0)
    {
        if (alreadyzero && qian == 0)
        {
            daxie(0, 1);
            zero = true;
        }

        if (qian > 0)
        {
            daxie(qian, 0);
            result += string(&block[4], 2);
            zero = false;
        }
        if (bai > 0)
        {
            daxie(bai, 0);
            result += string(&block[6], 2);
            zero = false;
        }
        else if (qian > 0 && (shi > 0 || yuan > 0) && zero == false)
        {
            daxie(0, 1);
            zero = true;
        }
        if (shi > 0)
        {
            daxie(shi, 0);
            result += string(&block[8], 2);
            zero = false;
        }
        else if ((qian > 0 || bai > 0) && yuan > 0 && zero == false)
        {
            daxie(0, 1);
            zero = true;
        }
        if (yuan > 0)
        {
            daxie(yuan, 0);
        }
        alreadyzero = true;
    }
    if (alreadyzero)
        result += string(&block[10], 2);

    if (jiao == 0 && fen == 0)
    {
        if (alreadyzero)
        {
            result += string(&block[12], 2);
        }
    }
    else
    {
        if ((alreadyzero || wanblock > 0 || yuanblock > 0) && jiao == 0 && fen > 0)
        {
            daxie(0, 1);
        }
        if (jiao > 0)
        {
            daxie(jiao, 0);
            result += string(&block[14], 2);
        }
        if (fen > 0)
        {
            daxie(fen, 0);
            result += string(&block[16], 2);
        }
        else if (jiao > 0)
        {
            result += string(&block[12], 2);
        }
    }

    cout << result << endl;
    return 0;
}