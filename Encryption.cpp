#include"Encryption.h"
#include"format_conversion.h"
using namespace std;

int IFNUM = 0;	//����
string FNTBEN;//�������ļ���
string ENFN;//�����ļ���
string WDEFN;//�������ļ���
string DEFN;//�����ļ���
fstream fnt, enf;//fnt�������ļ�����enf������ļ���
string passwd;

//�ļ���
int Encrypt(std::string filepath, char* pswd)
{
	passwd = pswd;
	cout << "passwd is " << passwd << endl;
	cout << "u_atol:" << u_atol(pswd) << endl;
	cout << "atol:" << atol(pswd) << endl;
	FNTBEN = filepath;
	if (filepath.empty() || passwd.empty())
	{
		return -2;
	}
	cout << "����������ļ�·�������ƣ�" << endl;
	ENFN = FNTBEN + ".DES";
	cout << "���ܺ��ļ���Ϊ��" << ENFN << endl;

	fnt.open(FNTBEN, std::ios::in | std::ios::binary);	//�������ļ������Զ����Ʒ�ʽ��
	enf.open(ENFN, std::ios::out | std::ios::binary);	//������ļ������Զ����Ʒ�ʽ��

	fnt.seekg(0, ios::end);	//��һ���������ļ�ƫ���ֽ������ڶ����������ļ�λ��
	std::streamoff size = fnt.tellg();	//�������ļ��ܳ���
	fnt.seekg(0, ios::beg);	//ios::beg�ļ���ͷ��ios::cur�ļ���ǰλ�ã�ios::end�ļ�ĩβ
	printf("�ļ���СΪ%lld�ֽ�\n", size);
	for (int i = 0; i < size; i++)
	{
		enf.put(fnt.get() ^ (int)u_atol(pswd));
		//enf.put(fnt.get() ^ 0x86);	//������Ķ������ַ�����λ����
	}

	//�ر��ļ�
	fnt.close();
	enf.close();
	return 0;
}

//�ļ�����
int Decrypt(std::string filepath, char* pswd)
{
	passwd = pswd;
	cout << "passwd is " << passwd << endl;
	cout << "u_atol:" << u_atol(pswd) << endl;
	cout << "atol:" << atol(pswd) << endl;
	WDEFN = filepath;
	cout << "������������ļ�·�������ƣ�" << endl;
	//cin >> WDEFN;
	if (filepath.empty()|| passwd.empty())
	{
		return -2;
	}
	if (!(WDEFN.find(".DES") == string::npos))
		DEFN = WDEFN.substr(0, WDEFN.length() - 4);
	else
	{
		printf("����ʧ�ܣ�\n");
		return -1;
	}
	cout << "���ܺ��ļ���Ϊ��" << DEFN << endl;

	fnt.open(WDEFN, std::ios::in | std::ios::binary);
	enf.open(DEFN, std::ios::out | std::ios::binary);

	fnt.seekg(0, ios::end);
	std::streamoff size = fnt.tellg();
	fnt.seekg(0, ios::beg);
	printf("�ļ���СΪ%lld�ֽ�\n", size);

	for (int i = 0; i < size; i++)
	{
		enf.put(fnt.get() ^ (int)u_atol(pswd));
		//enf.put(fnt.get() ^ 0x86);
	}

	fnt.close();
	enf.close();
	return 0;
}