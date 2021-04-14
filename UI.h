#pragma once
#ifndef __UI_H__
#define __UI_H__

#include<graphics.h>
#include"main.h"
#include"Encryption.h"
int UI(void);
int mouse();
int pfliepath();
int getpasswd();
void passwd_button_draw();

struct BUTTON_C
{
	int w;
	int h;
	int b;
	int t;
};
struct BUTTONLR
{
	int l;
	int r;
	int t;
	int b;
};

enum button_num{JIAM,JIEM,QUIT,CHOICE,FPATHP,PASSWD_B,RANDPASSWD};

void draw_button(BUTTONLR button, char* title);
void setstyle(BUTTONLR button, int style_flag, char* title);
void button_reset(int *button_set, int bt_num);
void ABOUT();

#endif /*  __UI_H__  */