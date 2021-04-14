#include"format_conversion.h"
#include <ctype.h>
#include<Windows.h>
#include <graphics.h>
long  u_atol(const char* nptr)
{
    int c;              /* 当前要转换的字符(一个一个字符转换成数字) */
    long total;         /* 当前转换结果 */
    int sign;           /* 标志转换结果是否带负号*/

    /*跳过空格，空格不进行转换*/
    while (isspace((int)(unsigned char)*nptr))
        ++nptr;

    c = (int)(unsigned char)*nptr++;//获取一个字符准备转换 
    sign = c;           /*保存符号标示*/
    if (c == '-' || c == '+')
        c = (int)(unsigned char)*nptr++;    /*跳过'+'、'-'号，不进行转换*/

    total = 0;//设置转换结果为0 

   // while (isdigit(c)) {//如果字符是数字 
    while (*nptr!='\0') {
        //total = 10 * total + (c - '0');     /* 根据ASCII码将字符转换为对应的数字，并且乘10累积到结果 */
        total = total*2 + (c - '0');
        c = (int)(unsigned char)*nptr++;    /* 取下一个字符 */
    }

    //根据符号指示返回是否带负号的结果 
    if (sign == '-')
        return -total;
    else
        return total;
}

//窗口居中
void  setCenterShow()
{
    HWND hWnd = GetHWnd();
    long scrWidth, scrHeight;
    RECT rect;
    scrWidth = GetSystemMetrics(SM_CXSCREEN);
    scrHeight = GetSystemMetrics(SM_CYSCREEN);
    GetWindowRect(hWnd, &rect);
    SetWindowPos(hWnd, HWND_NOTOPMOST, (scrWidth - rect.right) / 2, (scrHeight - rect.bottom) / 2, rect.right - rect.left, rect.bottom - rect.top, SWP_SHOWWINDOW);
}