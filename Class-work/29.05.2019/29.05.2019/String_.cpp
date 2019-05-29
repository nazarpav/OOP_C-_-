#include"String_.h"
#include <iostream>
#include <string>

using namespace std;
void STRING::Show()
{
	if (str == nullptr)
	{
		return;
	}
	cout << str<<endl;
}

void STRING::SetStringFromKeyboard()
{
	if (str != nullptr)
	{
		delete[]str;
	}
	char buf[255];
	std::cin.getline(buf,255);
	len=strlen(buf);
	this->str = new char[len+1];
	strcpy_s(str, len + 1, buf);
}

STRING::STRING()
{
	counter++;
	str = nullptr;
	len = 0;
}
STRING::STRING(const STRING& obj)
{
	this->len = obj.len;
	this->str = new char[len+1];
	strcpy_s(str, len+1, obj.str);
}
STRING::~STRING()
{
	counter--;
	if (str != nullptr || str != NULL)
	{
	delete[] str;
	}
}