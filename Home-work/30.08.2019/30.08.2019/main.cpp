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
	Box* Box_;
	Processor* Processor_;
	Main_board* Main_board_;
	Hdd* Hdd_;
	Memory* Memory_;
public:
	Box* Get_box()
	{
		return  Box_;
	}
	Processor* Get_processor()
	{
		return Processor_;
	}
	Main_board* Get_main_board()
	{
		return Main_board_;
	}
	Hdd* Get_Hdd()
	{
		return Hdd_;
	}
	Memory* Get_memory()
	{
		return Memory_;
	}

	void Set_box(Box* b)
	{
		this->Box_ = b;
	}
	void Set_processor(Processor* p)
	{
		this->Processor_ = p;
	}
	void Set_main_board(Main_board* m)
	{
		Main_board_ = m;
	}
	void Set_Hdd(Hdd* h)
	{
		Hdd_ = h;
	}
	void Set_memory(Memory*m)
	{
		Memory_=m;
	}
};
class PC_factory
{
public:
	virtual Box* Create_box() = 0;
	virtual Processor* Create_Processor() = 0;
	virtual Main_board* Create_Main_board() = 0;
	virtual Hdd* Create_Hdd() = 0;
	virtual Memory* Create_Memory() = 0;
};
class PC_configuration
{
	PC_factory *pc= nullptr;
public:
	PC_configuration(PC_factory *pc)
	{
		this->pc = pc;
	}
	void PC_factory(PC*pc_)
	{
		pc_->Set_box(pc->Create_box());
		pc_->Set_processor(pc->Create_Processor());
		pc_->Set_main_board(pc->Create_Main_board());
		pc_->Set_Hdd(pc->Create_Hdd());
		pc_->Set_memory(pc->Create_Memory());
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
	PC p;
	PC_configuration office_pc(new Office_PC_factory);
	office_pc.PC_factory(&p);
	p.Get_box()->Get_type();
	p.Get_Hdd()->Get_type();
	p.Get_main_board()->Get_type();
	p.Get_memory()->Get_type();
	p.Get_processor()->Get_type();
	cout << endl;
	PC p_;
	PC_configuration home_pc(new Home_PC_factory);
	home_pc.PC_factory(&p_);
	p_.Get_box()->Get_type();
	p_.Get_Hdd()->Get_type();
	p_.Get_main_board()->Get_type();
	p_.Get_memory()->Get_type();
	p_.Get_processor()->Get_type();
	cout << endl;
	system("pause");
	return 0;
}