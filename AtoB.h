#pragma once
#ifndef __A_TO_B_H__
#define __A_TO_B_H__

#include <iostream>
#include <windows.h>
#include <string>
#include <atlbase.h>

void Wchar_tToString(std::string& szDst, wchar_t* wchar);
void StringToWchar_t(wchar_t* wchar, const std::string& szDst);
void StringToWstring(std::wstring& szDst, std::string str);
void StringToTchar(std::string& src, TCHAR* buf);


char* Wchar_tToString(wchar_t* pWCStrKey);
wchar_t* StringToWchar_t(const std::string& pKey);

LPCWSTR stringToLPCWSTR(std::string orig);

void CharToTchar(const char* _char, TCHAR* tchar);
void TcharToChar(const TCHAR* tchar, char* _char);

#endif /*  __A_TO_B_H__  */