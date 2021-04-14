#include"Encryption.h"
#include"format_conversion.h"
using namespace std;

int IFNUM = 0;	//旗帜
string FNTBEN;//待加密文件名
string ENFN;//加密文件名
string WDEFN;//待解密文件名
string DEFN;//解密文件名
fstream fnt, enf;//fnt待输入文件流，enf待输出文件流
string passwd;

//文件加
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
	cout << "请输入加密文件路径及名称：" << endl;
	ENFN = FNTBEN + ".DES";
	cout << "加密后文件名为：" << ENFN << endl;

	fnt.open(FNTBEN, std::ios::in | std::ios::binary);	//打开输入文件流（以二进制方式）
	enf.open(ENFN, std::ios::out | std::ios::binary);	//打开输出文件流（以二进制方式）

	fnt.seekg(0, ios::end);	//第一个参数：文件偏移字节数；第二个参数：文件位置
	std::streamoff size = fnt.tellg();	//待处理文件总长度
	fnt.seekg(0, ios::beg);	//ios::beg文件开头，ios::cur文件当前位置，ios::end文件末尾
	printf("文件大小为%lld字节\n", size);
	for (int i = 0; i < size; i++)
	{
		enf.put(fnt.get() ^ (int)u_atol(pswd));
		//enf.put(fnt.get() ^ 0x86);	//将读入的二级制字符进行位运算
	}

	//关闭文件
	fnt.close();
	enf.close();
	return 0;
}

//文件解密
int Decrypt(std::string filepath, char* pswd)
{
	passwd = pswd;
	cout << "passwd is " << passwd << endl;
	cout << "u_atol:" << u_atol(pswd) << endl;
	cout << "atol:" << atol(pswd) << endl;
	WDEFN = filepath;
	cout << "请输入待解密文件路径及名称：" << endl;
	//cin >> WDEFN;
	if (filepath.empty()|| passwd.empty())
	{
		return -2;
	}
	if (!(WDEFN.find(".DES") == string::npos))
		DEFN = WDEFN.substr(0, WDEFN.length() - 4);
	else
	{
		printf("解密失败！\n");
		return -1;
	}
	cout << "解密后文件名为：" << DEFN << endl;

	fnt.open(WDEFN, std::ios::in | std::ios::binary);
	enf.open(DEFN, std::ios::out | std::ios::binary);

	fnt.seekg(0, ios::end);
	std::streamoff size = fnt.tellg();
	fnt.seekg(0, ios::beg);
	printf("文件大小为%lld字节\n", size);

	for (int i = 0; i < size; i++)
	{
		enf.put(fnt.get() ^ (int)u_atol(pswd));
		//enf.put(fnt.get() ^ 0x86);
	}

	fnt.close();
	enf.close();
	return 0;
}