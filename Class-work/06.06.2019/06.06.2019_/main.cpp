#include <iostream>
using namespace std;

class INT
{
public:
	INT(int num) :num(num) {};
	~INT();
	INT() = default;
	/*exsplisit*/ostream&operator<< (ostream& out)
	{
		out << num<<endl;
		return out;
	}
	/*INT operator=(const INT&other)
	{
		if (this != &other)
		{
			this->num = other.num;
		}
		return*this;
	}*/
	INT operator=(const INT&other) = delete;
private:
	int num;
};

INT::~INT()
{
}


int main()
{
	INT a(12);
	INT b=10;
	b = a;
	system("pause");
	return 0;
}