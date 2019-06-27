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
	void Set_string(char* str,int size)
	{
		strcpy(this->str, str);
		this->size = size;
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
	vector<int>convert_result;
	void Convert() 
	{
	for (size_t i = 0; i < String_convert::size; i++)
	{
		convert_result[i] = String_convert::str[i];
	}
	}
	void Show_convert_result()
	{
		cout<<"Str convert: " << str << endl;
	}
};
int main()
{
	String_convert * = AscII;

	system("pause");
	return 0;
}