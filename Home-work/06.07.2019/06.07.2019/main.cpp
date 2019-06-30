#include<iostream>
#include"Cat.h"
#include"Dog.h"
#include"Frog.h"
#include"Parrot.h"
using namespace std;

int main()
{
	Cat cat("Barsik",5);
	cat.Show();
	cat.Sound();
	cat.Type();
	Dog dog("kuzma", 5);
	dog.Show();
	dog.Sound();
	dog.Type();
	Frog frog("Bob", 5);
	frog.Show();
	frog.Sound();
	frog.Type();
	Parrot Parrot("andrey", 5);
	Parrot.Show();
	Parrot.Sound();
	Parrot.Type();
	system("pause");
	return 0;
}