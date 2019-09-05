#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

enum stay_time { One_hour_pleasure = 1, One_evening_pleasure, One_night_pleasure, Holidays_pleasure };
enum stay_time_cost { One_hour_pleasure_cost = 500, One_evening_pleasure_cost=750, One_night_pleasure_cost=1000, Holidays_pleasure_cost=2500};
enum entertainment {pool,bar,restaurant,billiard, excursion, museum,hotel};
enum bonus {none=0,sale_10=1,sale_30,sale_50=50, Free_service=100};
const short sale_for_woman = 5;
map<entertainment, string>entertainment_map = 
{
	{pool,"pool"},
	{bar,"bar"},
	{restaurant,"restaurant"},
	{billiard,"billiard"},
	{excursion,"excursion"},
	{museum,"museum"},
	{hotel,"hotel"}
};

struct People
{
private:
	short age;
	bool  is_male;
	bool  need_alcohol;
	bonus bonus_;
public:
	People(short age, bool is_male, bool need_alcohol, bonus bonus_)
	{
		this->age=age;
		this->is_male=is_male;
		this->need_alcohol= need_alcohol;
		this->bonus_= bonus_;
	}
	short Get_age()
	{
		return age;
	}
	bool Get_is_male()
	{
		return is_male;
	}
	bool Get_need_alcohol()
	{
		return need_alcohol;
	}
	bonus Get_bonus()
	{
		return bonus_;
	}

	void Set_age(short age)
	{
		this->age=age;
	}
	void Set_is_male(bool is_male)
	{
		this->is_male= is_male;
	}
	void Set_need_alcohol(bool need_alchohol)
	{
		this->need_alcohol= need_alcohol;
	}
	void Set_bonus(bonus bonus_)
	{
		this->bonus_= bonus_;
	}
};
class Stay_time_class
{
public:
	static int One_hour_pleasure()
	{
		return One_hour_pleasure_cost;
	}
	static int One_evening_pleasure()
	{
		return One_evening_pleasure_cost;
	}
	static int One_night_pleasure()
	{
		return One_night_pleasure_cost;
	}
	static int Holidays_pleasure()
	{
		return Holidays_pleasure_cost;
	}

	static string One_hour_pleasure_get_component()
	{
		return entertainment_map[bar] + "\n" + entertainment_map[billiard] + "\n";
	}
	static string One_evening_pleasure_get_component()
	{
		return entertainment_map[bar] + "\n" + entertainment_map[billiard] + "\n" + entertainment_map[restaurant] + "\n";
	}
	static string One_night_pleasure_get_component()
	{
		return entertainment_map[bar] + "\n" + entertainment_map[billiard] + "\n" + entertainment_map[restaurant] + "\n" + entertainment_map[pool] + "\n" + entertainment_map[hotel] + "\n";
	}
	static string Holidays_pleasure_get_component()
	{
		return entertainment_map[bar] + "\n" + entertainment_map[billiard] + "\n" + entertainment_map[restaurant] + "\n" + entertainment_map[pool] + "\n" + entertainment_map[hotel] + "\n" + entertainment_map[excursion] + "\n" + entertainment_map[museum] + "\n";
	}
};
class ObarivResort
{
		short quantity_alcohol;
		short quantity_woman;
		short sale_with_all_bonuses;
		short quantity_child;
		int all_cost;
		string Types_of_entertainment;
public:
	ObarivResort()
	{
		quantity_alcohol=0;
		quantity_woman = 0;
		sale_with_all_bonuses = 0;
		quantity_child = 0;
		all_cost = 0;
	}
	string Get_check(vector<People>pupil, stay_time stay_time_)
	{
		Get_entertainment(stay_time_);
		for (short i = 0; i < pupil.size(); i++)
		{
			Get_check_per_pupil(pupil[i], stay_time_);
		}
		return "Entertainment ->\n"+Types_of_entertainment + "\n\n" + "Quantity alcohol = " + to_string(quantity_alcohol) + 
			"\n" + "Sale with all bonuses = " + to_string(sale_with_all_bonuses) + "\n"
			+ "\n" + "Quantity child = " + to_string(quantity_child) + "\n" + "\n" + "All cost = " + to_string(all_cost) + "\n";
	}
private:
	void Get_entertainment(stay_time stay_time_)
	{
		switch (stay_time_)
		{
		case One_hour_pleasure:
			Types_of_entertainment = Stay_time_class::One_hour_pleasure_get_component();
			break;
		case One_evening_pleasure:
			Types_of_entertainment = Stay_time_class::One_evening_pleasure_get_component();
			break;
		case One_night_pleasure:
			Types_of_entertainment = Stay_time_class::One_night_pleasure_get_component();
			break;
		case Holidays_pleasure:
			Types_of_entertainment = Stay_time_class::Holidays_pleasure_get_component();
			break;
		}
	}
	void Get_check_per_pupil(People& people, stay_time stay_time_)
	{
		int cost;
		int tmp_for_bonus=0;
		short sale_for_woman_ = 0;
		if (people.Get_age() < 14)
			quantity_child++;
		if (people.Get_is_male() == false)
		{
			quantity_woman++;
			sale_for_woman_ += sale_for_woman;
		}
		if (people.Get_age() > 21 && people.Get_need_alcohol() == true)
			quantity_alcohol++;
		switch (stay_time_)
		{
		case One_hour_pleasure:
			cost = Stay_time_class::One_hour_pleasure();
			break;
		case One_evening_pleasure:
			cost = Stay_time_class::One_evening_pleasure();
			break;
		case One_night_pleasure:
			cost = Stay_time_class::One_night_pleasure();
			break;
		case Holidays_pleasure:
			cost = Stay_time_class::Holidays_pleasure();
			break;
		}
		tmp_for_bonus = (cost / 100 * (people.Get_bonus() + sale_for_woman_));
		sale_with_all_bonuses += tmp_for_bonus;
		all_cost += cost - tmp_for_bonus;
	}
};
//enum stay_time { One_hour_pleasure = 1, One_evening_pleasure, One_night_pleasure, Holidays_pleasure };
int main()
{
	vector<People> pupils;
	ObarivResort obar_res;
	pupils.push_back(People(12, false, false, Free_service));
	pupils.push_back(People(22, true, false, sale_10));
	pupils.push_back(People(123, false, true, sale_30));
	cout<<obar_res.Get_check(pupils, Holidays_pleasure);
	system("pause");
	return 0;
}