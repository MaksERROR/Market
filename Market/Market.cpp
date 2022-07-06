#include <iostream>
#include <string>
#include "People.h"
#include "Massive.h"
using namespace std;
//const int limit_Production;
//static int Free_ids = 0;


class Market
{

private:
	void Print_part(int part) {
		switch (part)
		{
		case(1):
			cout << "Срабатывание конструктора для id: " << this->Get_id() << "в рынке" << endl;
			break;
		case(2):
			cout << "Срабатывание конструктора копирования для id: " << this->Get_id() << "в рынке" << endl;
			break;
		case(3):
			cout << "Срабатывание деструктора для id: " << this->Get_id() << "в рынке" << endl;
			break;
		case(4):
			cout << "Срабатывание пустого конструктора для id: " << this->Get_id() << "в рынке" << endl;
			break;
		case(5):
			cout << "" << endl;
			break;
		default:
			break;
		}
	}
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
	int32_t Market_size;
	int Market_products;
	int Market_sailers;
	int id;


public:

	Market(int Market_sailers) {
		this->id = work_with_id(1);
		this->Market_sailers = Market_sailers;
		Print_part(1);
	}
	Market() {
		this->id = work_with_id(1);
		Print_part(4);
	}
	~Market() {
		work_with_id(-1);
		Print_part(3);
	}

	void Set_MarketSailers(int Market_sailers) {
		this->Market_sailers = Market_sailers;
	}
	int Get_id() {
		return this->id;
	}

};


class Product {

private:
	unsigned int id;
	string Name;
	float Weight;
	float Coast;
	/*is work; input(-1;1)*/int work_with_id(int What) {
		static unsigned int Id = 0;
		unsigned int ids = 0;
		static int Free_ids = 0;
		static int* Free_id = new int[1000];
		switch (What)
		{
		case(-1):
			Free_id[Free_ids] = this->Get_id();
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
	void Print_part(int part){
		switch (part)
		{
		case(1):
			cout<<"Срабатывание конструктора для id: " << this->Get_id() << "в продукте" << endl;
			break;
		case(2):
			cout << "Срабатывание конструктора копирования для id: " << this->Get_id() << "в продукте" << endl;
			break;
		case(3):
			cout << "Срабатывание деструктора для id: " << this->Get_id() << "в продукте" << endl;
			break;
		case(4):
			cout << "Срабатывание пустого конструктора для id : " << this->Get_id() << "в продукте" << endl;
			break;
		case(5):
			cout << "" << endl;
			break;
		default:
			break;
		}
	}
public:
	Product(const Product& other) {
		
		this->Coast = other.Coast;
		this->id = work_with_id(1);
		this->Name = other.Name;
		this->Weight = other.Weight;
		Print_part(2);
	}//*/
	Product(string Name, float Weight, float coast) {
		id = work_with_id(1);
		this->Name = Name;
		this->Weight = Weight;
		this->Coast = coast;
		Print_part(1);
	}
	Product() {
		id = work_with_id(1);
		Print_part(4);
	}
	~Product() {
		
		work_with_id(-1);
		Print_part(3);
	}


	void SetName(string Name) {
		this->Name = Name;
	}
	void Set_Weight(float Weight) {
		this->Weight = Weight;
	}
	void Set_Coast(float Coast) {
		this->Coast = Coast;
	}


	int Get_id() {
		return id;
	}
	string Get_Name() {
		return this->Name;
	}
	float Get_Weight() {
		return this->Weight;
	}
	float Get_Coast() {
		return this->Coast;
	}


};

template<typename T>
class Massive
{
public:
	Massive() { Size = 0; head = nullptr; }

	~Massive() { Clear(); }
	void Puch_back(T data) {
		if (head == nullptr) {
			head = new Node<T>(data);
		}
		else
		{
			Node<T>* curent = this->head;
			while (curent->Next != nullptr)
			{
				curent = curent->Next;
			}
			curent->Next = new Node<T>(data);
		}
		Size++;
	}
	void Pop_front() {
		Node<T>* temp = head;
		head = head->Next;
		delete temp;
		Size--;
	}
	void Clear() { while (Size) { Pop_front(); } }
	int Get_Size() { return this->Size; }
	T& operator[](const int index) {
		int counter = 0;
		Node<T>* curent = this->head;
		while (curent != nullptr) {
			if (counter == index) {
				return curent->data;
			}
			curent = curent->Next;
			counter++;
		}


	}
private:
	template<typename T>
	class Node
	{
	public:
		Node* Next;
		T data;

		Node(T data, Node* Next = nullptr) {
			this->data = data;
		}
	};
	int Size;
	Node<T>* head;
};

int main()
{
	
	setlocale(LC_ALL, "Russian");
	Massive<int> Arr();
	Arr().Puch_back(2);
	Fermer a;
	int size = Arr().Get_Size();
	cout << size;
	return 0;
}