#include<iostream>
#include"CardDeck.h"
using namespace std;

int main()
{
	CardDeck obj;
	obj.Print_Deck();
	obj.Sort_Deck();
	obj.Print_Deck();
	system("pause");
	return 0;
}