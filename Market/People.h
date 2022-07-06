#include <string>
#include "Massive.h"

using namespace std;
class Human
{
	/*is work; input(-1;1)*/int work_with_id(int What) {
		static unsigned int Id = 0;
		unsigned int ids = 0;
		static int Free_ids = 0;
		static int* Free_id = new int[1000];
		switch (What)
		{
		case(-1):
			Free_id[Free_ids] = this->id;
			Free_ids += 1;
			return -1;
		case(1):
			if (Free_ids > 0) {
				ids = Free_id[0];
				for (int i = 1; i <= Free_ids; i++) {
					Free_id[i - 1] = Free_id[i];
				}
				Free_id[Free_ids] = 0;
				Free_ids--;
			}
			else {
				ids = Id;
				Id++;
			}
			return ids;
		default:
			return -1;
		}
	}
	string Name;
	int Age;
	float start_up_capital;
	float consumption_per_day;
	int id;
public:
	Human(float start_up_capital, string Name, int Age, float consumption_per_day)/*1e+19*/
	{
		this->Age = Age;
		this->Name = Name;
		this->start_up_capital = start_up_capital;
		this->consumption_per_day = consumption_per_day;
		id = work_with_id(1);
		
	}
	Human() {
		id = work_with_id(1);
		
	}
	~Human() {
		work_with_id(-1);
		
	}

	void Set_Name(string Name) {
		this->Name = Name;
	}
	void Set_Age(int Age) {
		this->Age = Age;
	}
	void Set_start_up_capital(float start_up_capital) {
		this->start_up_capital = start_up_capital;
	}
	void Set_consumption_per_day(float consumption_per_day) {
		this->consumption_per_day = consumption_per_day;
	}

	int Get_id() {
		return id;
	}
	float Get_capital() {
		return start_up_capital;
	}
	friend class Fermer;
};

class Sailer : public Human {
	int number_of_stores;
public:
	Sailer()
	{
		number_of_stores = rand()%20;
	}
	void Set_number_of_stores(int number_of_stores) {
		this->number_of_stores = number_of_stores;
	}
};



class Fermer : public Human
{
	int Raw_Matereal;
	//product production;
public:
	Fermer() {
		Raw_Matereal = 0;
	}
	int id() {
		return this->Get_id();
	}
};
