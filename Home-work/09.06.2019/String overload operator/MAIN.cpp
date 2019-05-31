#include <iostream>
#include "string_.h"

int main()
{
	const int size_ = 7;
	char arr_[size_]="qwerty";
	STRING_ obj(arr_,size_);
	//STRING_ obj('t',12);
	//STRING_ obj;
	obj.Show();
	std::cout << "\n____________________________________>\n";

	std::cout <<"length string-> "<< obj.GetLength();
	std::cout << "\n____________________________________>\n";

	obj.Append("22222");
	obj.Show();
	std::cout << "\n____________________________________>\n";

	obj.ClearString();
	obj.Show();
	std::cout << "\n____________________________________>\n";

	obj.SetString("11111");
	obj.Show();
	std::cout << "\n____________________________________>\n";

	obj.SetStringFromKeyboard();
	std::cout << "length string-> " << obj.GetLength()<<std::endl;
	obj.Show();
	std::cout << "\n____________________________________>\n";

	std::cout << obj.GetString();
	std::cout << "\n";
	obj.Show();
	std::cout << "\n____________________________________>\n";

	std::cout << "length string-> " <<obj.GetLength();
	std::cout << "\n____________________________________>\n";

	system("pause");
	return 0;
}