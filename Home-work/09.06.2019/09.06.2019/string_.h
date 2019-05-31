#pragma once

class STRING_
{
private:
	unsigned int length;
	char* str;
public:

	 void Show();
	 void SetStringFromKeyboard();
	 void SetString(const char*);
	 char* GetString();
	 void ClearString();
	 void Append(const char*);
	 unsigned int GetLength();


	STRING_();
	STRING_(char ,unsigned int);
	STRING_(char *,unsigned int );

	~STRING_();

};

