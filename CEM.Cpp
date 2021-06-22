#include <iostream>
using namespace std;

template<typename T>
struct Set { //Множество
	T* data = nullptr;
	int size = 0;
	void add(T item) {
		if (size == 0) {
			data = new T[1]{ item };
			size = 1;
		}
		else {
			bool flag = 0; //Проверка на повторяющиеся элементы
			for (size_t i = 0; i < size; i++)
			{
				if (data[i] == item){
					flag = 1;
					break;
				}
			}
			if (!flag) {
				data = (T*)realloc(data, (size + 1) * sizeof(T));
				data[size] = item;
				size++;
			}
		}
	}
	T remove(int index) {
		T a = data[index];
		T* newdata = new T[size - 1];
		for (size_t i = 0; i < index; i++)
		{
			newdata[i] = data[i];
		}
		for (size_t i = index + 1; i < size; i++)
		{
			newdata[i - 1] = data[i];
		}
		delete[] data;
		data = newdata;
		size--;
		return a;
	}
	T get(int index) {
		return data[index];
	}
	void insert(int position, T item) {
		bool flag = 0; //Проверка на повторяющиеся элементы
		for (size_t i = 0; i < size; i++)
		{
			if (data[i] == item) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			T* ndata = new T[size + 1];
				for (int i = 0; i < position; i++)
				{
					ndata[i] = data[i];
				}
				ndata[position] = item;
				for (int i = position + 1; i < size + 1; i++)
				{
					ndata[i] = data[i - 1];
				}
			size++;
			delete[] data;
			data = ndata;
		}
	}
	void set(int position, T item) {
		bool flag = 0; //Проверка на повторяющиеся элементы
		for (size_t i = 0; i < size; i++)
		{
			if (data[i] == item) {
				flag = 1; break;
			}
		}
		if (!flag) {
			data[position] = item;
		}
	}
	int find(T item) {
		for (int i = 0; i < size; i++)
		{
			if (data[i] == item)return i;
		}
		return -1;
	}
	bool is_empty() {
		return size == 0;
	}
};

template<typename T>
struct Stack { //Стэк
	T* data = nullptr;
	int size = 0;
	void push(T item) {
		if (size == 0) {
			data = new T[1]{ item };
			size = 1;
		}
		else {
			size++;
			data = (T*)realloc(data, size * sizeof(T));
			data[size - 1] = item;
		}
	}
	T pop() {
		T a = data[size - 1];
		size--;
		data = (T*)realloc(data, size * sizeof(T));
		return a;
	}
	bool is_empty() {
		return size == 0;
	}
};

template<typename T>
struct queue { //Очередь
	T* data = nullptr;
	int size = 0;
	void push(T item) {
		if (size == 0) {
			data = new T[1]{ item };
			size = 1;
		}
		else {
			size++;
			data = (T*)realloc(data, size * sizeof(T));
			data[size - 1] = item;
		}
	}
	T pop() {
		T A = data[0];
		T* ndata = new T[size - 1];
		for (int i = 0; i < size - 1; i++)
		{
			ndata[i] = data[i + 1];
		}
		delete[] data;
		data = ndata;
		size--;
		return A;
	}
	bool is_empty() {
		return size == 0;
	}
};

template<typename T>
struct List { //Список
	T* data = nullptr;
	int size = 0;
	void add(T item) {
		if (size == 0) {
			data = new T[1]{ item };
			size = 1;
		}
		else {
			size++;
			data = (T*)realloc(data, size * sizeof(T));
			data[size - 1] = item;
		}
	}
	T remove(int index) {
		T a = data[index];
		T* newdata = new T[size - 1];
		for (size_t i = 0; i < index; i++)
		{
			newdata[i] = data[i];
		}
		for (size_t i = index + 1; i < size; i++)
		{
			newdata[i - 1] = data[i];
		}
		delete[] data;
		data = newdata;
		size--;
		return a;
	}
	T get(int index) {
		return data[index];
	}
	void insert(int position, T item) {
		T* ndata = new T[size + 1];
		for (int i = 0; i < position; i++)
		{
			ndata[i] = data[i];
		}
		ndata[position] = item;
		for (int i = position + 1; i < size + 1; i++)
		{
			ndata[i] = data[i - 1];
		}
		size++;
		delete[] data;
		data = ndata;
	}
	void set(int position, T item) {
		data[position] = item;
	}
	int find(T item) {
		for (int i = 0; i < size; i++)
		{
			if (data[i] == item)return i;
		}
		return -1;
	}
	bool is_empty() {
		return size == 0;
	}
};

template<typename TYPE>
struct ListItem { //Элемент связного списка
	ListItem* pNext;
	TYPE data;
};

template<typename T>
struct LinkedList  //Связный список
{
	ListItem<T>* pFirst = nullptr;
	int size = 0;
	void add(T item) {
		if (size == 0) {
			ListItem<T>* A = new ListItem<T>;
			A->pNext = nullptr;
			A->data = item;
			pFirst = A;
			size = 1;
		}
		else {
			auto* pos = pFirst;
			while (pos->pNext != nullptr) {
				pos = pos->pNext;
			}
			ListItem<T>* A = new ListItem<T>;
			A->pNext = nullptr;
			A->data = item;
			pos->pNext = A;
			size++;
		}
	}
	T remove(int index) {
		if (index == 0) {
			T A = pFirst->data;
			pFirst = pFirst->pNext;
			size--;
			return A;
		}
		else if (index == (size - 1)) {
			auto& pos = pFirst;
			for (int i = 0; i < index - 1; i++)
			{
				pos = pos->pNext;
			}
			T A = pos->pNext->data;
			pos->pNext = nullptr;
			size -= 1;
			return A;
		}
		else {
			auto& pos = pFirst;
			for (int i = 0; i < index - 1; i++)
			{
				pos = pos->pNext;
			}
			T A = pos->pNext->data;
			pos->pNext = pos->pNext->pNext;
			size -= 1;
			return A;
		}
	}
	T get(int index) {
		auto* pos = pFirst;
		for (int i = 0; i < index; i++)
		{
			pos = pos->pNext;
		}
		return (*pos).data;
	}
	void insert(int position, T item) {
		if (position == 0) {
			ListItem<T>* newItem = new ListItem<T>;
			newItem->data = item;
			newItem->pNext = pFirst;
			pFirst = newItem;
			size++;
		}
		else {
			auto* pos = pFirst;
			for (int i = 0; i < position - 1; i++)
			{
				pos = pos->pNext;
			}
			ListItem<T>* p = pos->pNext;
			ListItem<T>* newItem = new ListItem<T>;
			newItem->data = item;
			newItem->pNext = p;
			pos->pNext = newItem;
			size += 1;
		}
	}
	void set(int position, T item) {
		if (position == 0) {
			ListItem<T>* newItem = new ListItem<T>;
			newItem->data = item;
			newItem->pNext = pFirst->pNext;
			pFirst = newItem;
		}
		else {
			auto* pos = pFirst;
			for (int i = 0; i < position - 1; i++)
			{
				pos = pos->pNext;
			}
			ListItem<T>* p = pos->pNext->pNext;
			ListItem<T>* newItem = new ListItem<T>;
			newItem->data = item;
			newItem->pNext = p;
			pos->pNext = newItem;
		}
	}
	bool is_empty() {
		return size == 0;
	}
};

template<typename T>
ostream& operator<<(ostream& out, LinkedList<T> l) {
	auto& pos = l.pFirst;
	for (size_t i = 0; i < l.size; i++)
	{
		cout << pos->data << endl;
		pos = pos->pNext;
	}
	return out;
}

int main()
{
	Set<const char*> l;
	l.size = 0;

	l.add("Artem");
	l.add ("Max");

	for (int i = 0; i < l.size; i++)
	{
		cout << l.data[i] << endl;
	}
}
