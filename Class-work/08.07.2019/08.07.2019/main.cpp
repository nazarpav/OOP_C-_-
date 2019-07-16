#include <string>
#include <iostream>
#include <fstream>
using namespace std;

ostream& operator<<(ostream& out, const char data[255])
{
	out.write((char*)&data, sizeof(data));
	return out;
}
istream& operator>>(istream& in, char data[255])
{
	for (size_t i = 0; i < strlen(data); i++)
	{
	data[i]=in.get();
	}
	return in;
}
int main()
{
	char data[255] = "qwer";
	char data2[255] = " ";
	ofstream ofile("data.txt", ios_base::out | ios_base::binary);
	ifstream ifile("data.txt", ios_base::in | ios_base::binary);
	ofile << data;
	ifile >> data2;
	cout << data2<<endl;
	ifile.close();
	system("pause");
	return 0;
}