#pragma once
class STRING_
{
private:
	unsigned int length;
	char* str;
public:

	void Show();
	STRING_ operator+(const STRING_ & other);
	STRING_& operator=(STRING_ & other);
	STRING_ operator*(STRING_ & other);
	void SetStringFromKeyboard();
	void SetString(const char*);
	char* GetString();
	void ClearString();
	void Append(const char*);
	unsigned int GetLength();
	STRING_();
	STRING_(char, unsigned int);
	STRING_(char *, unsigned int);
	STRING_(const STRING_ & obj);
	~STRING_();
};