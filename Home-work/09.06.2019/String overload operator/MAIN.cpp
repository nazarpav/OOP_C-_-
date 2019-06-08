#include <iostream>
#include "string_.h"
using namespace std;
int main()
{
	const int size_ = 4;
	char arr_[size_] = "123";
	STRING_ obj(arr_, size_);
	STRING_ obj2(arr_, size_);
	obj2 = obj;
	cout << &obj <<endl<< &obj2<<endl;
	STRING_ obj3(arr_, size_);
	//std::cout << "adres str-> " << &obj.str << std::endl;
	//std::cout << "adres str-> " << &obj2.str << std::endl;
	//STRING_ obj7(arr_,size_);
	//STRING_ obj4(arr_,size_);
	//STRING_ obj('t',12);
	//STRING_ obj;
	obj.Show();
	cout << "\n____________________________________>\n";
	cout << "length string-> " << obj.GetLength();
	cout << "\n____________________________________>\n";
	obj.Append("22222");
	obj.Show();
	cout << "\n____________________________________>\n";
	obj.ClearString();
	obj.Show();
	cout << "\n____________________________________>\n";
	obj.SetString("11111");
	obj.Show();
	cout << "\n____________________________________>\n";
	obj2.SetStringFromKeyboard();
	cout << "length string-> " << obj.GetLength() << std::endl;
	obj.Show();
	cout << "\n____________________________________>\n";

	cout << obj.GetString();
	cout << "\n";
	obj.Show();
	cout << "\n____________________________________>\n";
	obj.Show();
	cout << "\n____________________________________>\n";

	//obj * obj2;//<<<<============================================
	STRING_ operatorplus(obj2+obj3);//<<<<============================================
	STRING_ operatormult(obj2*obj3);//<<<<============================================
	cout << "\n____________________________________ plusV>\n";
	operatorplus.Show();
	cout << "\n____________________________________multV\n";
	operatormult.Show();
	cout << "\n____________________________________>\n";
	obj2.Show();
	obj3.Show();
	cout << "\n____________________________________>\n";
	cout << "length string-> " << obj.GetLength();
	cout << "\n____________________________________>\n";
	system("pause");
	return 0;
}