#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class People
{
private:
	int count_id;
	char* full_name;

public:
	People();
	People(int _countid, const char* _fio);

	People(const People& obj);

	~People();

	inline void ShowPeople(int count_people, People* people);

};

People::People()
{
	count_id = 0;
	full_name = new char[7] {" "};
}

People::People(int _count_id, const char* _full_name)
{
	int count_fio;
	count_fio = strlen(_full_name);

	full_name = new char[count_fio + 1];

	count_id = _count_id;
	strcpy(full_name, _full_name);
}

People::People(const People& obj)
{
	int count_fio, countid;
	count_fio = strlen(obj.full_name);

	countid = obj.count_id;

	full_name = new char[count_fio + 1];
	strcpy(full_name, obj.full_name);
}

People::~People()
{
	delete[] full_name;
}

inline void People::ShowPeople(int count_people, People* people)
{

	cout << "Full name of people: \n\n";

	for (size_t i = 0; i < count_people; i++)
	{
		cout << people[i].full_name << endl;
	}

}

class Flat
{
private:

	int* flat_number;
	People* PeopleFlat;

public:

	Flat();
	Flat(int _flat, int flat_count, People* people);

	void initFlat(int flat_count, People* people);
	void ShowFlat(int flat_count, int people_count, People* people);

	Flat(const Flat& obj);
	~Flat();

};

Flat::Flat()
{
	flat_number = 0;
	PeopleFlat = 0;
}

Flat::Flat(int _flat, int flat_count, People* people)
{
	flat_number[flat_count] = _flat;
	PeopleFlat = people;
}

void Flat::initFlat(int flat_count, People* people)
{
	flat_number = new int[flat_count] { 12, 23, 24, 99 };
	PeopleFlat = people;
}

void Flat::ShowFlat(int flat_count, int people_count, People* people)
{
	cout << "Number of flats: ";
	for (size_t i = 0; i < flat_count; i++)
	{
		cout << Flat::flat_number[i] << " ";
	}
	cout << endl << endl;
	PeopleFlat->ShowPeople(people_count, people);
}

Flat::Flat(const Flat& obj)
{
	flat_number = obj.flat_number;
	PeopleFlat = obj.PeopleFlat;
}

Flat::~Flat()
{
	delete[] flat_number;
	delete[] PeopleFlat;
}


class House
{
private:

	int house_number;
	Flat* HouseFlat;

public:

	House();
	House(int _house_num, Flat* _flats);

	void init(int _house_num, int couflat_countntflat, Flat* flat);
	void ShowHouse(int flat_count, int people_count, People* people);

	House(const House& obj);

	~House();
};

House::House()
{
	house_number = 0;
	HouseFlat = 0;
}

House::House(int _house_num, Flat* _flats)
{
	house_number = _house_num;
	HouseFlat = _flats;
}

void House::init(int _house_num, int flat_count, Flat* flat)
{
	this->house_number = _house_num;
	HouseFlat = flat;
}

void House::ShowHouse(int flat_count, int people_count, People* people)
{
	cout << "House number: " << house_number << endl << endl;

	HouseFlat->ShowFlat(flat_count, people_count, people);
}

House::House(const House& obj)
{
	house_number = obj.house_number;
	HouseFlat = obj.HouseFlat;
}

House::~House()
{
	delete[] HouseFlat;
}

int main()
{
	int count_id = 1;
	int people_count = 6;
	int flat_count = 4;

	People* people = new People[people_count]
	{
		{count_id++, "Joseph Tribiani"},
		{count_id++, "Fibi Buffe"},
		{count_id++, "Ross Geller"},
		{count_id++, "Monika Geller"},
		{count_id++, "Rachel Grin"},
		{count_id++, "Chandler Bing"}
	};

	Flat flat;

	flat.initFlat(flat_count, people);

	House house;

	house.init(23, flat_count, &flat);
	house.ShowHouse(flat_count, people_count, people);

}
