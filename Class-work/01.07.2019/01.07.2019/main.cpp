#include<iostream>
#include<vector>
//#include""
using namespace std;

class String_convert
{
protected:
	char *str;
	int size;
public:
	String_convert()
	{
		str = nullptr;
		size = 0;
	}
	~String_convert()
	{
		delete[] str;
	}
	void Set_string(char* str)
	{
		delete[] this->str;
		this->size=strlen(str);
		this->str = new char[size + 1];
		strcpy_s(this->str, strlen(str)+1,str);
	}
	void Show()
	{
		cout << "Str: " << str << endl;
	}
	virtual void Convert() = 0;
	virtual void Show_convert() = 0;
};
class AscII :public String_convert
{
public:
	vector<int>convert_result;
	void Set_string(char* str)
	{
		String_convert::Set_string(str);
	}
	AscII(char * str)
	{
		String_convert::Set_string(str);
	}
	void Convert()
	{
		for (size_t i = 0; i < String_convert::size; i++)
		{
			convert_result.push_back(String_convert::str[i]);
		}
	}
	void Show_convert()
	{
		cout << "Str convert: ";
		for (size_t i = 0; i < convert_result.size(); i++)
		{
		cout<< convert_result[i]<<" " ;
		}
		cout << endl;
	}
};
class Reflet_case_converter :public String_convert
{
public:
	char *convert_result;
	void Set_string(char* str)
	{
		String_convert::Set_string(str);
	}
	Reflet_case_converter(char * str)
	{
		String_convert::Set_string(str);
	}
	~Reflet_case_converter()
	{
		delete[] convert_result;
	}
	void Convert()
	{
			delete[] convert_result;
			this->convert_result = new char[size + 1];
		for (size_t i = 0; i < strlen(this->str); i++)
		{
			if(char(str[i])<=90&& char(str[i])>=65)
				convert_result[i] = char(str[i]) + 32;
			if (char(str[i]) <= 122 && char(str[i]) >= 97)
				convert_result[i] = char(str[i]) - 32;
			else 
				convert_result[i] = char(str[i]);
		}
		convert_result[size] = '\0';
	}
	void Show_convert()
	{
		cout << "Str convert: " << convert_result << endl;
	}
};
int main()
{
	char a[255];
	cin >> a;
	AscII obj(a);
	obj.Set_string(a);
	obj.Convert();
	obj.Show_convert();
	cin >> a;
	Reflet_case_converter obj2(a);
	obj2.Convert();
	obj2.Show_convert();
	system("pause");
	return 0;
}