#pragma once
//#include<queue>
#include"queue_.h"
using namespace std;
class game
{
public:
	game();
	~game() = default;
	char get()
	{
		char tmp = _queue_.pop();
		_queue_.push(tmp);
		return tmp;
	}
private:
	queue_  _queue_;
};
game::game()
{
	this->_queue_.push('@');
	this->_queue_.push('#');
	this->_queue_.push('$');
	/*this->_queue_.push('%');
	this->_queue_.push('&');
	this->_queue_.push('*');*/
}