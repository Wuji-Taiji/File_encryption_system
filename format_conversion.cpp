#include"format_conversion.h"
#include <ctype.h>
#include<Windows.h>
#include <graphics.h>
long  u_atol(const char* nptr)
{
    int c;              /* ��ǰҪת�����ַ�(һ��һ���ַ�ת��������) */
    long total;         /* ��ǰת����� */
    int sign;           /* ��־ת������Ƿ������*/

    /*�����ո񣬿ո񲻽���ת��*/
    while (isspace((int)(unsigned char)*nptr))
        ++nptr;

    c = (int)(unsigned char)*nptr++;//��ȡһ���ַ�׼��ת�� 
    sign = c;           /*������ű�ʾ*/
    if (c == '-' || c == '+')
        c = (int)(unsigned char)*nptr++;    /*����'+'��'-'�ţ�������ת��*/

    total = 0;//����ת�����Ϊ0 

   // while (isdigit(c)) {//����ַ������� 
    while (*nptr!='\0') {
        //total = 10 * total + (c - '0');     /* ����ASCII�뽫�ַ�ת��Ϊ��Ӧ�����֣����ҳ�10�ۻ������ */
        total = total*2 + (c - '0');
        c = (int)(unsigned char)*nptr++;    /* ȡ��һ���ַ� */
    }

    //���ݷ���ָʾ�����Ƿ�����ŵĽ�� 
    if (sign == '-')
        return -total;
    else
        return total;
}

//���ھ���
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