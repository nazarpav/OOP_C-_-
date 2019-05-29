#pragma once

class STRING
{
public:
	static int counter;
	STRING(const STRING&);
	STRING();
	~STRING();
	void SetStringFromKeyboard();
	void Show();
private:
	char*str;
	int len;
};

