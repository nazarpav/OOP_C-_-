#include<iostream>
#include<vector>
#include<stack>
#include<Windows.h>
#include<ctime>
#include<conio.h>
using namespace std;

static const HANDLE consoleWndHandle = GetStdHandle(STD_OUTPUT_HANDLE);

enum ConsoleColors
{
	BLACK = 0,
	DARKBLUE = FOREGROUND_BLUE,
	DARKGREEN = FOREGROUND_GREEN,
	DARKCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
	DARKRED = FOREGROUND_RED,
	DARKMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
	DARKYELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
	DARKGRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	GRAY = FOREGROUND_INTENSITY,
	BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
	GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
	CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
	RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
	YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
	WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
};

void HideConsoleCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
class Figure;
struct State
{
	int xCoord;
	int yCoord;
	int width;
	int height;
	ConsoleColors color;
	State()
	{

	}
	State(int x, int y, int w, int h, ConsoleColors color)
	{
		xCoord = x;
		yCoord = y;
		width = w;
		height = h;
		this->color = color;
	}
};
class Memento
{
	State state;

public:
	Memento(int x, int y, int w, int h, ConsoleColors color)
	{
		state = State(x, y, w, h,color);
	}
	State GetState()
	{
		return state;
	}
};

class Figure
{
	void SetCursor(short x, short y) {
		COORD pos = { x, y };
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(output, pos);
	}
	short Rand(short num,short num2=0)
	{
		return rand() % num+num2;
	}
	short x, y;
	short size_w;
	short size_h;
	ConsoleColors color;
	void Rondom_move()
	{
		short tmp = Rand(30, Rand(10, -25));
		while (!(x+tmp >= 0))
		{
			tmp = Rand(30, Rand(10, -25));
		}
		x += tmp;
		tmp = Rand(30, Rand(10, -25));
		while (!(y+tmp >= 0))
		{
			tmp = Rand(30, Rand(10, -25));
		}
		y +=tmp ;
	}
	void Random_change_size()
	{
		size_h = Rand(15);
		size_w = size_h*2;
	}
	void Change_size(short size_w,short size_h)
	{
		this->size_h = size_h;
		this->size_w = size_w;
	}
	void Change_color(ConsoleColors color)
	{
		SetConsoleTextAttribute(consoleWndHandle, this->color=color);
	}
	void Change_color_rand()
	{
		SetConsoleTextAttribute(consoleWndHandle, this->color = ConsoleColors(Rand(15,1)));
	}
	void Render()
	{
		system("cls");
		SetCursor(x, y);
		for (short i = 0; i < size_h; i++)
		{
			for (short j = 0; j < size_w; j++)
			{
				cout << char(219);
			}
			SetCursor(x, ++y);
		}
		y -= size_h;
	}
public:
	void Round()
	{
		Rondom_move();
		Random_change_size();
		Change_color_rand();
		Render();
		Sleep(100);
	}
	Figure()
	{
		x = 0;
		y = 0;
		Random_change_size();
	}
	void LoadMemento(Memento m)
	{
		x = m.GetState().xCoord;
		y = m.GetState().yCoord;
		size_w = m.GetState().width;
		size_h = m.GetState().height;
	}

	Memento CreateMemento()
	{
		Memento m(x, y, size_w, size_h,color);
		return m;
	}
};
class Caretaker
{
	stack<Memento> savePoints;
	Figure f;

public:
	void SavePoint()
	{
		savePoints.push(f.CreateMemento());
	}

	void Undo()
	{
		if (savePoints.size() > 0)
		{
			f.LoadMemento(savePoints.pop());
		}

	}

	void Round()
	{
		f.Round();
	}
};
int main()
{
	srand(unsigned(time(NULL)));
	Figure f;
	for (;true;)
	{
		switch (_getch())
		{
		case ' ':
			HideConsoleCursor();
			f.Round();
			break;
		case char(27) :
				return 0;
			break;
		case 's':
				return 0;
			break;
		case 'z':
				return 0;
			break;
		}
		

		
		

	}

	system("pause");
	return 0;
}
