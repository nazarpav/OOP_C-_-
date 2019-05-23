#pragma once
#pragma once
#include <string>

struct Player
{
	std::string name;
	std::string surname;
	unsigned short age;
	unsigned short games;
	unsigned int points;
	float avgPointPerGame;
};
unsigned short template_menu(const std::string menu[], const unsigned short size_menu);
float AveragePoint(Player *&player_arr, const unsigned short &index_);
void fill_player_arr(Player *player_arr, const unsigned short size, unsigned short i);
void Save_in_file(Player *&player_arr, const unsigned short &size);
void Load_from_file(Player *&player_arr, unsigned short &size);
void SaveInFileBinary(Player *& player, unsigned short &size);
void LoadFromFileBinary(Player *& player, unsigned short &size);