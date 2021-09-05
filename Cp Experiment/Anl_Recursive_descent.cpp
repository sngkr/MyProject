#pragma once
#include<iostream>
#include<fstream>
using namespace std;

/*递归向下分析法*/
//全局变量loc，标识当前“地址”
int Anal_str_loc = 0;
//存放所需要判断的字符
char Analyze_str[50];

//文法
void E();
void A();
void B();
void C();

//日志记录
bool Record_char();

//全局变量outfile 
ofstream outfile;



/*
文法G[E]:
	E -> eBaA
	A -> a | bAcb
	B -> dEd | ac
	C -> e | dC
*/
int main()
{

	ifstream infile;

	infile.open("待分析字符串.txt");
	outfile.open("info_递归下降分析法.txt");

	if (infile.is_open() )
	{
		while (infile >> Analyze_str)
		{
			//测试
			Anal_str_loc = 0;
			outfile << "\n所分析的字符串：" << Analyze_str << endl;
			cout<< "\n所分析的字符串：" << Analyze_str << endl;
			//cout << Anal_str_loc << endl;
			//cout << Analyze_str << endl;
			cout << "*****************************" << endl;
			cout << "*递归下降分析程序*编制人：宋可 学号：116132019141 班级：计算机科学与技术3班" << endl;
			E();
		
			if (Analyze_str[Anal_str_loc] == '#')
				cout << Analyze_str << "为合法符号串" << endl;
			else
				cout << Analyze_str << "为非法符号串" << endl;
			cout << "*****************************" << endl;
		}
	}

	infile.close();
	outfile.close();
	return 0;
}


void E()
{

	if (Analyze_str[Anal_str_loc] == 'e'  )
	{
		Record_char();
		Anal_str_loc++;
		cout << "用到的产生式： E -> eBaA" << endl;
		B();
		if (Analyze_str[Anal_str_loc] == 'a' )
		{
			Record_char();
			Anal_str_loc++;
			cout << "用到的产生式： E -> eBaA" << endl;
			A();
		}
		else
		{
			Record_char();
			cout << "产生式 E -> eBaA中 a不能匹配" << endl;
		}
	}
	else
	{
		Record_char();
		cout << "产生式 E -> eBaA中 e不能匹配" << endl;
	}

}

void A()
{
	
	if (Analyze_str[Anal_str_loc] == 'a' )
	{
		Record_char();
		Anal_str_loc++;
		cout << "用到的产生式： A -> a" << endl;
	}
	else if (Analyze_str[Anal_str_loc] == 'b' )
	{
		Record_char();
		Anal_str_loc++;
		cout << "用到的产生式： A -> bAcB" << endl;

		A();
		if (Analyze_str[Anal_str_loc] == 'c')
		{
			Record_char();
			Anal_str_loc++;
			cout << "用到的产生式： A -> bAcB" << endl;
			B();
		}
		else
		{
			Record_char();
			cout << "产生式 A -> bAcB 中 c不能匹配" << endl;
		}
	}
	else
	{
		Record_char();
		cout << "产生式 A ->a | bAcB 中 a、b不能匹配" << endl;
	}
}

void B()
{
	
	if (Analyze_str[Anal_str_loc] == 'd')
	{
		Record_char();
		Anal_str_loc++;
		cout << "用到的产生式：B -> dEd" << endl;
		E();
		if (Analyze_str[Anal_str_loc] == 'd' )
		{
			Record_char();
			Anal_str_loc++;
			cout << "用到的产生式：B -> dEd" << endl;
		}
		else
		{
			Record_char();
			cout << "产生式 A -> dEd 中 d不能匹配" << endl;
		}
	}
	else if (Analyze_str[Anal_str_loc] == 'a' )
	{
		Record_char();
		Anal_str_loc++;
		cout << "用到的产生式： B -> aC" << endl;
		C();
	}
	else
	{
		Record_char();
		cout << "产生式 A ->aC | dEd 中 a、d不能匹配" << endl;
	}
}

void  C()
{
	
	//Record_char();
	if (Analyze_str[Anal_str_loc] == 'e')
	{
		Record_char();
		Anal_str_loc++;
		cout << "用到的产生式： C -> e" << endl;
	}
	else if (Analyze_str[Anal_str_loc] == 'd' )
	{
		Record_char();
		Anal_str_loc++;
		cout << "用到的产生式： C -> dC" << endl;
		C();
	}
	else
	{
		Record_char();
		cout << "产生式 C -> e | dC 中 e、d不能匹配" << endl;
	}
}

bool Record_char()
{
	if (outfile.is_open())
	{
		int i = 0;
		outfile << "当前正在分析的字符：" << endl;
		while (Analyze_str[i] != '\0')
		{
			if (Anal_str_loc == i)
			{
				outfile << "(" << Analyze_str[i] << ")";
			}
			else
			{
				outfile << Analyze_str[i];
			}
			i++;
		}
		outfile << endl;
	}
	return true;
}
