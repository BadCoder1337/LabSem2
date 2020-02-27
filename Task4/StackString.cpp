#include "StackString.h"

/*
4.7.	Создать класс StackString для работы со стеком, содержащим строки текста.
В качестве членов-данных рекомендуется брать два элемента (определяющие начало и конец стека)
самоссылочного класса (должен быть другом основному классу) следующего вида:
class Node   {  char* data;  Node *next; };
Класс должен содержать конструктор по умолчанию, основной конструктор и конструктор копирования.
Определить в этом классе функции-члены класса, обеспечивающие:
добавление элементов в стек, удаление элемента из стека.
Кроме того, определить операторные функции для ввода и вывода стека.
Дополнительно перегрузить операторную функцию для операции ! (логическое отрицание),
которая возвращает максимальный элемент стека.
Данные для проверки работы класса считывать из файла.

*/

void StackString::init() {

}

StackString::StackString() {
	_begin = NULL;
	_end = NULL;
}

StackString& StackString::push(string str) {
	auto *temp = new Node;
	temp->data = str;
	if (size() == 0) {
		temp->next = NULL;
		_begin = temp;
		_end = temp;
	} else {
		temp->next = _begin;
		_begin = temp;
	}
	return *this;
}

string StackString::pop() {
	auto s = size();
	if (s > 1) {
		auto temp = _begin;
		auto str = temp->data;
		_begin = temp->next;
		delete temp;
		return str;
	} else if (s = 1) {
		auto str = _begin->data;
		delete _begin;
		delete _end;
		_begin = NULL;
		_end = NULL;
		return str;
	} else {
		return NULL;
	}
}

string StackString::top() {
	return _begin->data;
}

int StackString::size() {
	if (_begin == NULL && _end == NULL) return 0;
	auto temp = _begin;
	auto i = 1;
	while (temp != _end) {
		temp = temp->next;
		i++;
	};
	return i;
}

string StackString::operator!() {
	if (size() > 0) {
		string str;
		auto temp = _begin;
		while (temp != _end) {
			if (temp->data.length() > str.length()) str = temp->data;
			temp = temp->next;
		}
		return str;
	} else return NULL;
}

StackString & StackString::operator<<(string str) {
	push(str);
	return *this;
}
