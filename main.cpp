/*******************************************************
* 开发时间：2021年4月1日
* 开 发 者：wzzlyzdn
* 开发环境：VS2019 + EasyX_20200902
* 字 符 集：多字节字符集
* 邮    箱：wzzlyzdn@163.com
* 项目名称：加密GUI(文件加密系统)
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
	HWND hwnd = GetHWnd();		//获取窗口句柄
	//SetWindowPos(hwnd, HWND_TOP,)
	SetWindowText(hwnd, _T("DES"));	//设置窗口标题文字
	//setCenterShow();
	UI();
	mouse();
	closegraph();
	return 0;
}