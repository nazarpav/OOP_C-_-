#include<iostream>

using namespace std;
class Processor
{
public:
	virtual void Get_type()
	{
	}
};
class Main_board
{
public:
	virtual void Get_type()
	{
	}
};
class Hdd
{
public:
	virtual void Get_type()
	{
	}
};
class Memory
{
public:
	virtual void Get_type()
	{
	}
};
class Box
{
public:
	virtual void Get_type()
	{
	}
};

/////////////////////////////////////////////////////////////////////

class Amd_Processor:public Processor
{
protected:
	virtual void Get_type()
	{
		cout << "amd processor\n";
	}
};
class Asus_main_board :public Main_board
{
protected:
	virtual void Get_type()
	{
		cout << "asus main board\n";
	}
};
class LG_hdd :public Hdd
{
protected:
	virtual void Get_type()
	{
		cout << "Lg hdd\n";
	}
};
class Ddr_memory :public Memory
{
protected:
	virtual void Get_type()
	{
		cout << "ddr memory\n";
	}
};
class Black_box :public Box
{
protected:
	virtual void Get_type()
	{
		cout << "black box\n";
	}
};

/////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////

class Intel_Processor :public Processor
{
protected:
	virtual void Get_type()
	{
		cout << "intel processor\n";
	}
};
class Msi_main_board :public Main_board
{
protected:
	virtual void Get_type()
	{
		cout << "msi main board\n";
	}
};
class Samsung_hdd :public Hdd
{
protected:
	virtual void Get_type()
	{
		cout << "samsung hddd\n";
	}
};
class Ddr2_memory :public Memory
{
protected:
	virtual void Get_type()
	{
		cout << "Ddr2 memory\n";
	}
};
class Silver_box :public Box
{
protected:
	virtual void Get_type()
	{
		cout << "silver box\n";
	}
};

/////////////////////////////////////////////////////////////////////

class PC
{
	Box Box()
	{

	}
	Processor Processor()
	{

	}
	Main_board Main_board()
	{

	}
	Hdd Hdd()
	{

	}
	Memory Memory()
	{

	}
};
class PC_factory
{
public:
	virtual Box* Create_box()
	{
		return nullptr;
	}
	virtual Processor* Create_Processor()
	{
		return nullptr;
	}
	virtual Main_board* Create_Main_board()
	{
		return nullptr;
	}
	virtual Hdd* Create_Hdd()
	{
		return nullptr;
	}
	virtual Memory* Create_Memory()
	{
		return nullptr;
	}
};
class PC_configuration:public PC
{
	PC_factory *pc= nullptr;
public:
	PC_configuration(PC_factory *pc)
	{
		this->pc = pc;
	}
	PC_factory* PC_factory()
	{
		pc->Create_box()->Get_type();
		pc->Create_Processor()->Get_type();
		pc->Create_Main_board()->Get_type();
		pc->Create_Hdd()->Get_type();
		pc->Create_Memory()->Get_type();
		return pc;
	}
};

class Office_PC_factory: public PC_factory
{
public:
	virtual Box* Create_box()override
	{
		return new Black_box;
	}
	virtual Processor* Create_Processor()override
	{
		return new Amd_Processor;
	}
	virtual Main_board* Create_Main_board()override
	{
		return new Asus_main_board;
	}
	virtual Hdd* Create_Hdd()override
	{
		return new LG_hdd;
	}
	virtual Memory* Create_Memory()override
	{
		return new Ddr_memory;
	}
};

class Home_PC_factory : public PC_factory
{
public:
	virtual Box* Create_box()override
	{
		return new Silver_box;
	}
	virtual Processor* Create_Processor()override
	{
		return new Intel_Processor;
	}
	virtual Main_board* Create_Main_board()override
	{
		return new Msi_main_board;
	}
	virtual Hdd* Create_Hdd()override
	{
		return new Samsung_hdd;
	}
	virtual Memory* Create_Memory()override
	{
		return new Ddr2_memory;
	}
};


int main()
{
	PC_configuration office_pc(new Office_PC_factory);
	office_pc.PC_factory();
	cout << endl;
	PC_configuration Home_pc(new Home_PC_factory);
	Home_pc.PC_factory();
	system("pause");
	return 0;
}