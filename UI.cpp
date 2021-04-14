#include"UI.h"
#include "ofn.h"
#include<windows.h>
using namespace std;

extern int graph_height;
extern int graph_width;
extern string filepath_s;

char passwd[17] = { '\0' };
char passwdku[] = { '0','1','2','3','4','5','6','7','8','9',
'a','b','c','d','e','f','g','h','i','j', 'k','l','m',
'n','o','p','q','r','s','t','u','v','w','x','y','z',
'A','B','C','D','E','F','G','H','I','J','K','L','M',
'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
'.','@','$','!','%','#','_','~','?'
};
bool kbhit_flag = false;
//char button_name[][5] = { "����","����","�˳�","ѡ��","\0","\0","���" };
char button_name[][5] = { "����","����","����","ѡ��","\0","\0","���" };
char About_me[] = 
"* \n"
"* \n"
"* ����ʱ�䣺2021��4��1��\n"
"* ��  ��  �ߣ�wzzlyzdn\n"
"* ����������VS2019 + EasyX_20200902\n"
"* ��  ��  �������ֽ��ַ���\n"
"* ��        �䣺wzzlyzdn@163.com\n"
"* ��Ŀ���ƣ�����GUI(�ļ�����ϵͳ)\n"
"* Data Encryption System(DES)\n"
"* \n"
"* \n";

//int COLOR_7[16] = { BLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,LIGHTGRAY,DARKGRAY,LIGHTBLUE,LIGHTGREEN,LIGHTCYAN,LIGHTRED,LIGHTMAGENTA,YELLOW,WHITE };
int COLOR_7[7] = { 0x000000,0x00E500,0xff2121,0x801dae,0x3eede7,0xfaff72,0xFFFFFF, };
MOUSEMSG m;		// ���������Ϣ
button_num bt_n;
BUTTON_C button_c =
{
	button_c.w = int(graph_width * 0.2),
	button_c.h = int(graph_height * 0.15),
	button_c.b = graph_height - int(graph_height * 0.11),
	button_c.t = button_c.b - button_c.h,
};

BUTTONLR jiam = { int(graph_width * 0.1),jiam.l + button_c.w,button_c.t,button_c.b };
BUTTONLR jiem = { jiam.r + jiam.l,jiem.l + button_c.w,button_c.t,button_c.b };
BUTTONLR quit = { jiem.r + jiam.l,quit.l + button_c.w,button_c.t,button_c.b };
BUTTONLR choice = { quit.r - int(graph_width * 0.11),quit.r, graph_height - button_c.b,choice.t + button_c.h };
BUTTONLR fpathp = { jiam.l,quit.l,choice.t,choice.b };
BUTTONLR passwd_b = { jiam.l,quit.l,choice.b + int(graph_width * 0.11) ,passwd_b.t + button_c.h };
BUTTONLR randpasswd = { choice.l,choice.r,passwd_b.t,passwd_b.b };

//BUTTONLR buttonlr[] = { jiam,jiem,quit,choice,fpathp,passwd_b };
BUTTONLR buttonlr[] = { jiam,jiem,quit,choice,fpathp,passwd_b,randpasswd };

int UI(void)
{
	// ���ñ���ɫΪ��ɫ
	setbkcolor(RGB(140, 165, 230));
	//setbkcolor(MY_COLOR1);
	// �ñ���ɫ�����Ļ
	cleardevice();
	settextcolor(WHITE);
	//settextcolor(0x4b5cc4);
	//setlinecolor(0x4b5cc4);
	setlinestyle(PS_SOLID, 1, NULL, 1);
	setfillcolor(RGB(140, 165, 230));
	//setfillcolor(MY_COLOR1);

	for (int i = JIAM; i <= RANDPASSWD; i++)
	{
		draw_button(buttonlr[i], button_name[i]);
	}
	return 0;
}

int mouse()
{//x�����y������
	/*************************************************/
	int button_set = -1;
	srand((unsigned)time(NULL));
	while (true)
	{
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();

		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			// ����ƶ���ʱ�򻭺�ɫ��С��

			//putpixel(m.x, m.y, RED);
			putpixel(m.x, m.y, COLOR_7[rand() % 7]);
			break;
		}

		//ѡ��ť
		if (m.x <= choice.r && m.x >= choice.l && m.y <= choice.b && m.y >= choice.t)
		{
			button_reset(&button_set, CHOICE);
			if (m.mkLButton)
			{
				filepath_s = getfilepath();
				FlushMouseMsgBuffer();
				pfliepath();
			}
			//Sleep(5);
		}

		//�˳���ť�����ڴ���������ڰ�ť���˳���ϵͳ�˳���ť
		if (m.x <= quit.r && m.x >= quit.l && m.y <= quit.b && m.y >= quit.t)
		{
			button_reset(&button_set, QUIT);
			if (m.mkLButton)
			{
				//return 0;
				ABOUT();
				continue;
			}
		}

		//������
		if (m.x <= passwd_b.r && m.x >= passwd_b.l && m.y <= passwd_b.b && m.y >= passwd_b.t)
		{
			//button_reset(button_set, PASSWD_B);
			if (m.mkLButton)
			{
				kbhit_flag = true;
				FlushMouseMsgBuffer();
				getpasswd();
			}
			//Sleep(5);
		}

		//������밴ť
		if (m.x <= randpasswd.r && m.x >= randpasswd.l && m.y <= randpasswd.b && m.y >= randpasswd.t)
		{
			button_reset(&button_set, RANDPASSWD);
			if (m.mkLButton)
			{
				for (int i = 0; i < 16; i++)
				{
					passwd[i] = '\0';
				}
				int pass_flag = rand() % 11 + 6;
				for (int i = 0; i < pass_flag; i++)
				{
					passwd[i] = passwdku[rand() % 71];
				}
				passwd_button_draw();
				//Sleep(5);
				cout << "passwd:" << passwd << endl;
				//MessageBox(NULL, "����", "����", MB_OK);
			}
		}

		//���ܰ�ť
		if (m.x <= jiam.r && m.x >= jiam.l && m.y <= jiam.b && m.y >= jiam.t)
		{
			button_reset(&button_set, JIAM);
			if (m.mkLButton)
			{
				//outtextxy(0, 0, "����");
				//Encrypt(filepath_s, passwd);
				int ret_Encrypt = Encrypt(filepath_s, passwd);
				FlushMouseMsgBuffer();
				if (-2 == ret_Encrypt)
				{
					ret_Encrypt = 1;
					MessageBeep(16);
					MessageBox(NULL, "·��������δָ����", "����", MB_OK);
					continue;
				}
				if (0 == ret_Encrypt)
				{
					ret_Encrypt = 1;
					MessageBeep(0);
					MessageBox(NULL, "���ܳɹ���", "�ɹ�", MB_OK);
					continue;
				}
			}
		}

		//���ܰ�ť
		if (m.x <= jiem.r && m.x >= jiem.l && m.y <= jiem.b && m.y >= jiem.t)
		{
			button_reset(&button_set, JIEM);
			if (m.mkLButton)
			{
				//outtextxy(10, 10, "��1��");
				int ret_Decrypt = Decrypt(filepath_s, passwd);
				Sleep(5);
				FlushMouseMsgBuffer();
				if (0 == ret_Decrypt)
				{
					ret_Decrypt = 1;
					MessageBeep(0);
					MessageBox(NULL, "���ܳɹ���", "�ɹ�", MB_OK);
					continue;;
				}
				if (-1 == ret_Decrypt)
				{
					ret_Decrypt = 1;
					MessageBeep(16);
					MessageBox(NULL, "����ʧ�ܣ�\n��֧�ֵ��ļ���", "����", MB_OK);
					continue;
				}
				if (-2 == ret_Decrypt)
				{
					ret_Decrypt = 1;
					MessageBeep(16);
					MessageBox(NULL, "·��������δָ����", "����", MB_OK);
					continue;
				}
				//Sleep(5);
			}
		}
	}
	//x�����y������
	/*************************************************************/
	return 0;
}

int pfliepath()
{
	clearrectangle(fpathp.l, fpathp.t, fpathp.r, fpathp.b);
	fillrectangle(fpathp.l, fpathp.t, fpathp.r, fpathp.b);
	char* filepath_w = (char*)filepath_s.c_str();
	RECT r = { fpathp.l + 2, fpathp.t, fpathp.r, fpathp.b };
	cout << filepath_w << endl;
	drawtext(filepath_w, &r, DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_WORD_ELLIPSIS);
	return 0;
}

int getpasswd()
{
	passwd_button_draw();
	int j = 0; //ѭ������
	char flag;
	cout << "kbhit_flag:" << kbhit_flag << endl;
	/*��������*/
	while (kbhit_flag)
	{
		//passwd_button_draw();
		if (MouseHit())
		{
			m = GetMouseMsg();
		}

		while (passwd[j] != '\0')
		{
			if (j <= 16)
				j++;
			continue;
		}
		//cout << endl << j << ",";

		if (_kbhit())
		{
			flag = _getch();
			if (flag > 127)
				continue;
			if (j <= 16)
			{
				passwd[j] = flag;
				if (j == 16 && passwd[j] != 8)
					passwd[j] = '\0';

				passwd_button_draw();
				if (passwd[j] == 8)
				{ //ʵ���˸��ɾ�����ݵĹ���
					if (j == 0)
					{
						passwd[j] = 0;
						passwd_button_draw();
						continue;
					}
					else
					{
						passwd[j] = 0;
						passwd[j - 1] = 0;
						passwd_button_draw();
						if (j == 1)
							j = 0;
						else
							j -= 2;
						continue;
					}
				}
			}
		}

		if (m.x > passwd_b.r || m.x < passwd_b.l || m.y > passwd_b.b || m.y < passwd_b.t)
		{
			if (m.mkLButton)
			{
				passwd_button_draw();
				kbhit_flag = false;
				FlushMouseMsgBuffer();
				break;
			}
		}
		//Sleep(50);
	}

	cout << "passwd:" << passwd << endl;
	return 0;
}

void passwd_button_draw()
{
	//draw_button(passwd_b, passwd);
	clearrectangle(passwd_b.l, passwd_b.t, passwd_b.r, passwd_b.b);
	fillrectangle(passwd_b.l, passwd_b.t, passwd_b.r, passwd_b.b);
	RECT passwd_r = { passwd_b.l + 2, passwd_b.t,passwd_b.r, passwd_b.b };
	drawtext(passwd, &passwd_r, DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_WORD_ELLIPSIS);
}

void draw_button(BUTTONLR button, char* title)
{
	fillrectangle(button.l, button.t, button.r, button.b);
	RECT button_r = { button.l, button.t, button.r, button.b };
	if (title != "\0")
		drawtext(title, &button_r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void setstyle(BUTTONLR button, int style_flag, char* title)
{
	if (0 == style_flag)
	{
		settextcolor(WHITE);
		//settextcolor(0x4b5cc4);
		setlinestyle(PS_SOLID, 1, NULL, 1);
		setfillcolor(RGB(140, 165, 230));
		//setfillcolor(MY_COLOR1);
	}
	if (1 == style_flag)
	{
		settextcolor(BLACK);
		setlinestyle(PS_DASH, 1, NULL, 1);
		setfillcolor(RGB(130, 155, 220));
		//setfillcolor(MY_COLOR2);
	}
	clearrectangle(button.l, button.t, button.r, button.b);
	draw_button(button, title);
}

void button_reset(int* button_set, int bt_num)
{
	if (*button_set != bt_num)
	{
		*button_set = bt_num;
		for (int i = JIAM; i <= RANDPASSWD; i++)
		{
			if (i != FPATHP && i != PASSWD_B)
				setstyle(buttonlr[i], 0, button_name[i]);
		}
		setstyle(buttonlr[bt_num], 1, button_name[bt_num]);
	}
	else
		return;
}

void ABOUT()
{
	setbkcolor(RGB(140, 165, 230));
	cleardevice();
	settextcolor(BLACK);
	setlinestyle(PS_SOLID, 1, NULL, 1);
	setfillcolor(RGB(140, 165, 230));
	RECT About_me_r = { 0, 0, graph_width, graph_height };
	drawtext(About_me, &About_me_r, DT_LEFT);
	draw_button(quit, (char*)"����");
	MOUSEMSG m_;
	while (true)
	{
		m_ = GetMouseMsg();
		if (m_.x <= quit.r && m_.x >= quit.l && m_.y <= quit.b && m_.y >= quit.t)
		{
			if (m_.mkLButton)
			{
				UI();
				passwd_button_draw();
				pfliepath();
				return;
			}

		}
	}
}