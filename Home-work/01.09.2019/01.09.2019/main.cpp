#include<iostream>

using namespace std;

class Auto_tehnology
{
public:
	virtual void Build_body() = 0;
	virtual void Install_engine() = 0;
	virtual void Install_wheels() = 0;
	virtual void Paint() = 0;
	virtual void Prepare_salon() = 0;
};
class Mini_auto_tehnology:public Auto_tehnology
{
	virtual void Build_body() override
	{
		cout << "mini car body\n";
	}
	virtual void Install_engine()override
	{
		cout << "mini car engine\n";
	}
	virtual void Install_wheels()override
	{
		cout << "mini car wheels\n";
	}
	virtual void Paint() override
	{
		cout << "mini car Paint\n";
	}
	virtual void Prepare_salon() override
	{
		cout << "mini car salon\n";
	}
};
class Sport_auto_tehnology :public Auto_tehnology
{
	virtual void Build_body() override
	{
		cout << "Sport car body\n";
	}
	virtual void Install_engine()override
	{
		cout << "Sport car engine\n";
	}
	virtual void Install_wheels()override
	{
		cout << "Sport car wheels\n";
	}
	virtual void Paint() override
	{
		cout << "Sport car Paint\n";
	}
	virtual void Prepare_salon() override
	{
		cout << "Sport car salon\n";
	}
};
class SUV_auto_tehnology :public Auto_tehnology
{
	virtual void Build_body() override
	{
		cout << "SUV car body\n";
	}
	virtual void Install_engine()override
	{
		cout << "SUV car engine\n";
	}
	virtual void Install_wheels()override
	{
		cout << "SUV car wheels\n";
	}
	virtual void Paint() override
	{
		cout << "SUV car Paint\n";
	}
	virtual void Prepare_salon() override
	{
		cout << "SUV car salon\n";
	}
};
class Conveyor
{

	/*Auto_tehnology* tehnology;
	public:
	void Set_tehnology(Auto_tehnology* tehnology)
	{
		this->tehnology= tehnology;
	}*/
public:
	void Build(Auto_tehnology* tehnology)
	{
		tehnology->Build_body();
		tehnology->Install_engine();
		tehnology->Install_wheels();
		tehnology->Paint();
		tehnology->Prepare_salon();
	}
};
int main()
{
	Conveyor conveyor;
	conveyor.Build(new Mini_auto_tehnology);
	conveyor.Build(new Sport_auto_tehnology);
	conveyor.Build(new SUV_auto_tehnology);


	system("pause");
	return 0;
}