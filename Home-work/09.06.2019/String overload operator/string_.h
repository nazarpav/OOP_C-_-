#pragma once

class STRING_
{
private:
	unsigned int length;
public:
	char* str;

	 void Show();
	 STRING_ operator+(const STRING_ & other);
	 //int operator=(STRING_ & other);
	 STRING_ operator*(STRING_ & other);
	 void SetStringFromKeyboard();
	 void SetString(const char*);
	 char* GetString();
	 void ClearString();
	 void Append(const char*);
	 unsigned int GetLength();


	STRING_();
	STRING_(char ,unsigned int);
	STRING_(char *,unsigned int );

	STRING_(const STRING_ & obj);

	~STRING_();

};

