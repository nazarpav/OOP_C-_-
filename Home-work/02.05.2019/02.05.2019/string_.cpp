#include "string_.h"
#include <iostream>
#include <string>
void STRING_::Show()
{
	if (str == nullptr)
	{
		return;
	}
	std::cout << str;
}

void STRING_::SetStringFromKeyboard()
{
	if (str != nullptr)
	{
		delete[]str;
	}
	char buf[255];
	std::cin.getline(buf, 255);
	length = strlen(buf);
	this->str = new char[length + 1];
	strcpy_s(str, length + 1, buf);
}

void STRING_::SetString(const char *new_str)
{
	if (new_str == nullptr)
	{
		return;
	}
	delete[]str;

	length = (strlen(new_str));
	this->str = new char[length+1];

	for (unsigned int i = 0; i < length; i++)
	{
		this->str[i] = new_str[i];
	}

	this->str[length] = '\0';
}

char* STRING_::GetString()
{
	if (str == nullptr)
	{
		return '\0';
	}
	else
	{
		static char buf_str[255];
		for (unsigned int i = 0; i < length; i++)
		{
			buf_str[i] = this->str[i];
		}

		buf_str[length] = '\0';
		return buf_str;
	}
}

void STRING_::ClearString()
{
	length = 0;
	str = nullptr;
}

void STRING_::Append(const char *add_str)
{
	if (add_str == nullptr)
	{
		return;
	}

	char *buf_str = new char[length];

	for (unsigned int i = 0; i < length; i++)
	{
		buf_str[i] = str[i];
	}

	delete[]str;
	
	unsigned int length_add_str = strlen(add_str);
	length += length_add_str;
	this->str = new char[length+1];

	for (unsigned int i = 0; i < length-length_add_str; i++)
	{
		str[i] = buf_str[i];
	}

	unsigned int j = 0;
	for (unsigned int i = length - length_add_str; i < length; i++)
	{
		str[i] = add_str[j];
		j++;
	}
	delete[]buf_str;
	this->str[length] = '\0';
}

unsigned int STRING_::GetLength()
{
	if (str == nullptr)
	{
		return 0;
	}
	return strlen(str);
}

STRING_::STRING_()
{
	length = 0;
	str = nullptr;
}

STRING_::STRING_(char symbol, unsigned int size)
{
	length = size;
	this->str = new char[length+1];

	for (unsigned int i = 0; i < length; i++)
	{
		this->str[i] = symbol;
	}

	this->str[length] = '\0';
}

STRING_::STRING_(char * _str, unsigned int size)
{
	if (strlen(_str) != size - 1)
	{
		str = nullptr;
		length = 0;
	}
	else
	{
		length = size;
		this->str = new char[length + 1];

		for (unsigned int i = 0; i < length; i++)
		{
			this->str[i] = _str[i];
		}

		this->str[length] = '\0';
	}
}

STRING_::~STRING_()
{
	delete[] str;
}