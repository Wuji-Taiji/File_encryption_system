/*
ofn.c
OPENFILENAME
*/

#include"ofn.h"
using namespace std;
WNDPROC g_Edit;
const static char* s_defaultFilters =
{
	"�����ļ�(*.*)\0*.*\0"
	"DES�ļ�(*.DES)\0*.DES\0"
	"ͼƬ�ļ�(*.jpg;*.png;*.bmp;*.gif)\0*.jpg;*.jpeg;*.png;*.bmp;*.gif\0"
	"�ı��ļ�(*.txt)\0*.txt\0"
	"��Ƶ�ļ�(*.mp3;*.wav;*.wma;*.3ga)\0*.mp3;*.wav;*.wma;*.3ga\0"
	"��Ƶ�ļ�(*.mp4;*.avi;*.flv;*.rmvb)\0*.mp4;*.avi;*.flv;*.rmvb\0"
	"��ִ���ļ�(*.exe;*.bat;*.sh)\0*.exe;*.bat;*.sh\0\0"
};

string getfilepath()
{
	string path;
	OPENFILENAME open;// �����Ի���ṹ��
	//wchar_t file[MAX_PATH];// ���������ȡ�ļ����ƵĻ������� 
	char file[MAX_PATH];
	ZeroMemory(&open, sizeof(OPENFILENAME)); // ��ʼ��ѡ���ļ��Ի���
	open.lStructSize = sizeof(OPENFILENAME);//ָ������ṹ�Ĵ�С�����ֽ�Ϊ��λ��
	open.lpstrFile = file;//�򿪵��ļ���ȫ·��
	open.lpstrFile[0] = '\0'; //��һ���ַ����ǹ�������������ʾ�ַ���
	open.nMaxFile = MAX_PATH;  //ָ��lpstrFile����Ĵ�С����TCHARsΪ��λ
	//open.lpstrFilter = "�ı��ļ�(*.txt)\0*.txt\0�����ļ�(*.*)\0*.*\0\0";  //���ļ�����
	open.lpstrFilter = s_defaultFilters;
	open.nFilterIndex = 1;  //ָ�����ļ����Ϳؼ��е�ǰѡ��Ĺ�����������
	open.lpstrFileTitle = NULL; // ָ�����ѡ����ļ����ļ�������չ���Ļ��壨����·����Ϣ���������Ա������NULL��
	open.nMaxFileTitle = 0;  //ָ��lpstrFileTitle����Ĵ�С����TCHARsΪ��λ
	open.lpstrInitialDir = NULL;  //ָ���Կ��ַ��������ַ���������������ַ�����ָ����ʼĿ¼��
	open.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;//λ��ǵ����ã������ʹ������ʼ���Ի���
	//GetOpenFileName (&open) ;//���ļ��Ի���
	//GetSaveFileName(&open);//�����ļ��Ի���
	if (GetOpenFileName(&open))  // ��ʾ��ѡ���ļ��Ի���  
	{
		path = file;
		//Wchar_tToString(path, file);
		//cout << path << endl;
	}
	//cout << path<<endl;
	return path;
}
