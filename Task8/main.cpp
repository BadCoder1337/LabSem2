/* 
8.7.  Разработать шаблонный класс SparseArray для работы с разреженным массивом.
Класс должен содержать конструктор по умолчанию,
основной конструктор и конструктор копирования.
Кроме того, класс должен содержать функции для ввода и вывода элементов массива.
Определить операторную функцию (знак операции выбрать самостоятельно), которая позволяет найти количество отрицательных элементов массива.
В главной программе проверить работу всех функций класса.
*/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <assert.h>
using namespace std;

// Класс, определяющий один элемент, хранящийся в разреженном массиве:
template <class Type> class SparseList;
template <class Type> class SparseOb {
	friend class SparseList<Type>;
public:
	// Обратите внимание на то, что класс SparseList предварительно объявлен
	long index; // индекс элемента массива
	SparseOb<Type>* next; // указатель на следующий узел
	SparseOb<Type>* prior; // указатель на предыдущий объект
	SparseOb() { info = 0; index = -1; next = prior = NULL; }
	// конструктор
	Type info; // элемент данных
};

// Класс  списка:
template <class Type>
class SparseList {
public:
	SparseOb<Type>* start, * end; // указатели на начало и конец списка
	SparseList() { start = end = NULL; }
	~SparseList();
	SparseOb<Type>* storeEl(long ix, Type c); // добавление элемента
	void remove(long ix); // удаление элемента
	// возвращение указателя на элемент по заданному индексу:
	SparseOb<Type>* findPtr(long ix);
};

// Параметризованный класс разреженного массива:
template <class Type>
class SparseArray : public SparseList<Type> {
	long length; // размер массива
public:
	SparseArray(long size = 0) : length(size) {} // конструктор
	Type& operator [](long i); // операция [ ]
    int operator <(const int x); // сравнение
};

// Определение функций:
template <class Type> int SparseArray<Type>::
operator < (const int x) {
	SparseOb<Type>* p;
    int i = 0;
	p = this->start;
	while (p) {
		if (p->info < x) i++;
		p = p->next;
	}
    return i;
}

// Деструктор:
template <class Type> SparseList<Type>::
~SparseList() {
	SparseOb<Type>* p, * p1;
	// удаление всех элементов списка:
	p = start;
	while (p) {
		p1 = p->next;
		delete p;
		p = p1;
	}
}

// Добавление элемента в список:
template <class Type> SparseOb<Type>* SparseList<Type>::
storeEl(long ix, Type c) {
	SparseOb<Type>* p = new SparseOb<Type>;
	assert(p); // проверяем, выделена ли память
	p->info = c;
	p->index = ix;
	if (start == NULL) start = end = p;
	// если добавляется первый элемент списка
	else // добавление элемента в конец списка
	{
		p->prior = end;  end->next = p;  end = p;
	}
	return p;
}

// нахождение элемента массива по индексу:
template <class Type> SparseOb<Type>* SparseList<Type>::
findPtr(long ix) {
	SparseOb<Type>* temp;
	temp = start;
	while (temp) {
		if (ix == temp->index) return temp;
		// если найдено вхождение элемента, возвращается указатель на него
		temp = temp->next;
	}
	return NULL; // если нет в списке
}

/* Удаление из списка элемента с указанным индексом и
 обновление указателей на начало и конец списка: */
template <class Type> void SparseList<Type>::
remove(long ix) {
	SparseOb<Type>* ob = findPtr(ix); // получаем указатель на элемент
	if (!ob) return; // если элемент не существует
	if (ob->prior) // если удаляется не первый элемент
	{
		ob->prior->next = ob->next;
		if (ob->next)  // если удаляется не последний элемент
			ob->next->prior = ob->prior;
		else // последний
			end = ob->prior;
		delete ob;
	} else // удаляется первый
		if (ob->next) // если элемент - не единственный
		{
			ob->next->prior = NULL;
			start = ob->next;
			delete ob;
		} else start = end = NULL; // теперь список пуст
}

// Индексация в массиве:
template <class Type> Type& SparseArray<Type>::
operator [] (long ix) {
	if (ix<0 || ix > length - 1) {
		cout << "Индекс выходит за пределы области определения\n\n\n";
		exit(1);
	}
	SparseOb<Type>* p;
	p = this->findPtr(ix); // получаем указатель на элемент
	if (!p) // эсли это новый элемент
	{
		p = this->storeEl(ix, 0); // добавляем его в массив со значением 0
	}
	return p->info;
	/* функция возвращает ссылку на эту ячейку, поэтому значение элемента можно изменять */
}

// пример использования разреженного массива:
int main() {
	//Настройки шрифтов и региональных стандартов: 
	if (SetConsoleCP(1251) == 0)
		//проверка правильности установки кодировки символов для ввода
	{
		cerr << "Fialed to set codepage!" << endl;
		/* если не удалось установить кодовую страницу, вывод сообщения об ошибке */
	}
	if (SetConsoleOutputCP(1251) == 0)//тоже самое для вывода
	{
		cerr << "Failed to set OUTPUT page!" << endl;
	}
	SparseArray <int> iob(100000); // Объявляем массив целых чисел
	// поместим в массив некоторые значения:
	for (int i = 0; i < 5; i++)
		iob[i] = i + 1;
	iob[2] = iob[3];
	iob[1000] = 9345;
	iob[2000] = iob[1000] + 100;
	// выведем значения элементов на экран:
	cout << "Значения элементов массива:\n";
	for (int i = 0; i < 5; i++)  cout << iob[i] << " ";
	cout << iob[1000] << " " << iob[2000] << endl;
    cout << "Элементов меньше 5: ";
    cout << (iob < 5) << endl;
    cout << "Элементов меньше 0 (отрицательные): ";
    cout << (iob < 0) << endl;
	cout << "Удалили элемент с номером 0: ";
	iob.remove(0);
	for (int i = 0; i < 5; i++)  cout << iob[i] << " ";
	cout << endl;
	// попробуем обратиться к элементу, которому не присваивалось значение:
	cout << "Неприсвоенное значение: " << iob[3000] << " " << endl;
	// попробуем обратиться к элементу с недопустимым номером:
	cout << iob[100001] << endl;
	cout << endl;
	_getch();
	return 0;
}
