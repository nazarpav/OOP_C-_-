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
STRING_ STRING_::operator+(STRING_& other)
{
	int newlength = this->length + other.length + 1;
	char * tmp_str = new char[newlength];
	int j = 0;
	for (int i = 0; i < newlength-1; i++)
	{
		if (i <= this->length - 1)
		{
			tmp_str[i] = this->str[i];

		}
		else
		{
			tmp_str[i] = other.str[j];
			j++;
		}
	}
	this->length = newlength;
	tmp_str[newlength - 1] = '\0';
	delete[] this->str;
	this->str = tmp_str;
	//std::cout << "adres str-> " << str << std::endl;
	return *this;
}

int STRING_::operator=(STRING_& other)
{
	return (strcpy_s(this->str, other.length + 1, other.str));
}

STRING_ STRING_::operator*(STRING_& other)
{
	int j = 0;
	for (int i = 0; i < this->length; i++)
	{
		for (int g = 0; g < other.length; g++)
		{
			if (this->str[i] == other.str[g])
			{
				j++;
			}
		}
	}
	char *buf = new char[j+1];
	j = 0;
	for (int i = 0; i < this->length; i++)
	{
		for (int g = 0; g < other.length; g++)
		{
			if (this->str[i] == other.str[g])
			{
				buf[j] = str[i];
				j++;
			}
		}
	}
	buf[j] = '\0';
	j++;
	delete[] this->str;
	str = new char[j];
	str = buf;
	return *this;
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
		length = size-1;
		this->str = new char[length + 1];

		for (unsigned int i = 0; i < length; i++)
		{
			this->str[i] = _str[i];
		}

		this->str[length] = '\0';
	}
}

STRING_::STRING_(const STRING_& obj)
{
	this->length = obj.length;
	this->str = new char[obj.length + 1];
	for (int i = 0; i < obj.length; i++)
	{
		this->str[i] = obj.str[i];
	}
	this->str[length] = '\0';
}

STRING_::~STRING_()
{
	//std::cout << "adres str-> " << &str << std::endl;
	delete[] this->str;
}