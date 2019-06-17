#pragma once
#include<queue>
//#include<ctime>
using namespace std;
class game
{
public:
	game();
	~game()=default;
	char get()
	{
		char tmp = _queue_.front();
		_queue_.pop();
		_queue_.push(tmp);
		return tmp;
	}
private:
	queue<char> _queue_;
};

game::game()
{
	this->_queue_.push('@');
	this->_queue_.push('#');
	this->_queue_.push('$');
	this->_queue_.push('%');
	this->_queue_.push('&');
	this->_queue_.push('*');
	/*srand(unsigned(time(NULL)));//////////////////////////HARD
	unsigned short choise = rand()%6+1;
	switch (choise)
	{
	case 1:
		this->_queue_.push('@');
		this->_queue_.push('#');
		this->_queue_.push('$');
		this->_queue_.push('%');
		this->_queue_.push('&');
		this->_queue_.push('*');
		break;
	case 2:
		this->_queue_.push('*');
		this->_queue_.push('@');
		this->_queue_.push('#');
		this->_queue_.push('$');
		this->_queue_.push('%');
		this->_queue_.push('&');
		break;				
	case 3:
		this->_queue_.push('&');
		this->_queue_.push('*');
		this->_queue_.push('@');
		this->_queue_.push('#');
		this->_queue_.push('$');
		this->_queue_.push('%');
		break;				
	case 4:					
		this->_queue_.push('%');
		this->_queue_.push('&');
		this->_queue_.push('*');
		this->_queue_.push('@');
		this->_queue_.push('#');
		this->_queue_.push('$');
		break;
	case 5:	
		this->_queue_.push('$');
		this->_queue_.push('%');
		this->_queue_.push('&');
		this->_queue_.push('*');
		this->_queue_.push('@');
		this->_queue_.push('#');
		break;
	case 6:
		this->_queue_.push('#');
		this->_queue_.push('$');
		this->_queue_.push('%');
		this->_queue_.push('&');
		this->_queue_.push('*');
		this->_queue_.push('@');
		break;
	default:
		break;
	}*/
}
