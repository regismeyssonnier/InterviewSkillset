#pragma once
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

namespace conteneur{

	class ExceptionSize {};

	template<typename T> class Item {
	public:
		T GetValue();
		void SetValue(T value);
		Item operator+(Item& it);
		Item(T value);
		Item() : value(0) {}
	protected:
		T value;
	};

	template<typename T> class ItemSet : public Item<T> {
	private :
		string name;
	public:
		ItemSet(string name);
		ItemSet(T value);
		ItemSet operator+(ItemSet& it);
		void Define(T arg);
		string GetName();
	};

	template <typename T>class SharedConteneur {
	public:
		int size=0;
	private:
		int index = 0;
		vector<shared_ptr<ItemSet<T>>> shared_conteneur;
	public:
		SharedConteneur(int size);
		void Display();
		void Add(string name, T value);
		vector<weak_ptr<ItemSet<T>>> GetAllWeakReference();
	};

	template<typename T>
	SharedConteneur<T>::SharedConteneur(int size) {
		this->size = size;
		this->shared_conteneur.resize(size);
		this->index = 0;
	}

	template<typename T>
	void SharedConteneur<T>::Display() {
		cout << "size: " << this->size << endl;


		for (int i = 0; i < this->index; ++i) {
			cout << this->shared_conteneur[i]->GetName() << " " <<
				this->shared_conteneur[i]->GetValue() << endl;;
		}


	}

	template<typename T>
	void SharedConteneur<T>::Add(const string name, T value) {
		
		if (this->index < this->size) {
			auto item = make_shared<ItemSet<T>>(name);
			item->SetValue(value);
			this->shared_conteneur[this->index] = item;
			++this->index;
		}
		else
		{
			throw runtime_error("Index too large");
		}
	}

	template<typename T>
	vector<weak_ptr<ItemSet<T>>> SharedConteneur<T>::GetAllWeakReference() {
		vector<weak_ptr<ItemSet<T>>> weak_conteneur;
		for (int i = 0; i < this->index; ++i) {
			weak_conteneur.push_back(weak_ptr<ItemSet<T>>(this->shared_conteneur[i]));
		}
		
		return weak_conteneur;
	}

	/*************/
	template<typename T>
	ItemSet<T>::ItemSet(string name) {
		this->name = name;
	}

	template<typename T>
	void ItemSet<T>::Define(T arg) {
		this->value = arg;
	}

	template<typename T>
	string ItemSet<T>::GetName() {
		return this->name;
	}

	template<typename T>
	ItemSet<T>::ItemSet(T value) {
		this->value = value;
	}

	template<typename T>
	ItemSet<T> ItemSet<T>::operator+(ItemSet<T>& it) {
		return ItemSet(it.value + this->value);
	}

	/*************/

	template<typename T>
	T Item<T>::GetValue() {
		return this->value;
	}

	template<typename T>
	void Item<T>::SetValue(T value) {
		this->value = value;
	}
	
	template<typename T>
	Item<T>::Item(T value) {
		this->value = value;
	}

	template<typename T>
	Item<T> Item<T>::operator+(Item<T>& it) {
		return Item(it.value + this->value);
	}

	


}