/*******************************************************
* ����ʱ�䣺2021��4��1��
* �� �� �ߣ�wzzlyzdn
* ����������VS2019 + EasyX_20200902
* �� �� �������ֽ��ַ���
* ��    �䣺wzzlyzdn@163.com
* ��Ŀ���ƣ�����GUI(�ļ�����ϵͳ)
*********************************************************/

#include"main.h"
#include"ofn.h"
#include"UI.h"
#include "resource.h"
#include "format_conversion.h"
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
int graph_width = 360;//355
int graph_height = 180;//170

using namespace std;
string filepath_s;

int main()
// This is winmain, the main entry point for Windows applications
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//initgraph(graph_width, graph_height, EW_SHOWCONSOLE | EW_DBLCLKS);
	
	initgraph(graph_width, graph_height, EW_DBLCLKS);
	HWND hwnd = GetHWnd();		//��ȡ���ھ��
	//SetWindowPos(hwnd, HWND_TOP,)
	SetWindowText(hwnd, _T("DES"));	//���ô��ڱ�������
	//setCenterShow();
	UI();
	mouse();
	closegraph();
	return 0;
}