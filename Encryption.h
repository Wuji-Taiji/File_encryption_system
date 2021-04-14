#pragma once
#ifndef __ENCRYPTION_H__
#define __ENCRYPTION_H__

#include<iostream>
#include<fstream>
#include<conio.h>
#include<Windows.h>
#include<tchar.h>

int Encrypt(std::string filepath, char* pswd);
int Decrypt(std::string filepath, char* pswd);

#endif /*  __ENCRYPTION_H__  */