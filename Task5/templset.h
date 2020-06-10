#include <iostream>
#include <stdlib.h>
using namespace std; 
#define DEFSET 200 // Размер множества по умолчанию

template <class Stype> class Set 
// Stype – условное название типа элементов
{
    
	public:
	Stype *SetPtr; //  Указатель на члены множества
	int MemSize;   //  Размер памяти, выделенный множеству
	int NumMembers; // Количество элементов множества

// операторы ввода – вывода:
	template<typename Stype> friend istream& operator>> (istream& stream, Set &ob);
	template<typename Stype> friend ostream& operator<< (ostream& stream, Set &ob);

	// закрытые функции:
	void insert(Stype member);  // добавление элемента
	void remove(Stype member);  // удаление элемента
	int find (Stype member);    // возвращение индекса элемента
	int ismember (Stype member);
//проверка, является ли элемент членом множества

	//конструкторы и деструктор:
	Set();
	Set (int size);
	Set (const Set& ob);
	~Set() { delete SetPtr;}

	//Операторные функции:
	Set<Stype>& operator= (const Set<Stype> &ob); // присваивание
	Set<Stype>& operator+ (Stype member); //Добавление нового элемента
    Set<Stype> operator+ (Set &ob); //Создание объединения
	Set<Stype> operator- (Stype member); //Удаление элемента
	Set<Stype> operator- (Set<Stype> &ob); //Разность множеств
	int operator== (Set<Stype> &ob); // сравнение на равенство
	int operator!= (Set<Stype> &ob); // сравнение на неравенство
	int operator< (Set<Stype> &ob); //1 - если подмножество
	operator int () {return NumMembers;} 

    Set<Stype> operator>> (const int &shift); // сдвиг вправо shift элементов
//операция преобразования к типу int
};

//определение функций:

// сдвиг вправо shift элементов
template <class Stype>
Set<Stype> Set<Stype>::operator>> (const int &shift)
{
    Set<Stype> temp(*this);
    for(int i = 0; temp.NumMembers > 0 && i < shift; i++) {
        temp.SetPtr[temp.NumMembers - i] = NULL; // удаляем элемент
        temp.NumMembers--;
    }
	return temp;
}

template <class Stype> Set<Stype>::Set() // конструктор по умолчанию
{
	SetPtr = new Stype[DEFSET]; // используем размер по умолчанию
	if (!SetPtr)
	{
		cout <<"Ошибка при размещении объекта в памяти.\n";
		_getch(); exit(1);
	}
	NumMembers = 0; // множество пока пустое
	MemSize = DEFSET;
}

/* основной конструктор (создает пустое множество c областью памяти заданного размера): */
template <class Stype> Set<Stype>::Set(int size) 
{
	SetPtr = new Stype[size]; 
	if (!SetPtr)
	{
		cout <<"Ошибка при размещении объекта в памяти.\n";
		_getch(); exit(1); 
	}
	NumMembers = 0;
	MemSize = size;
}

// конструктор копирования:
template <class Stype> Set<Stype>::Set(const Set<Stype> &ob)
{
	MemSize = ob.MemSize;
	SetPtr = new Stype[MemSize]; // выделяем память для копии
	if (!SetPtr)
	{
		cout<<"Ошибка выделения памяти \n";
		_getch(); exit(1);
	}
	NumMembers = ob.NumMembers;
	for (int  i=0; i<NumMembers; i++) // копируем элементы множества
		SetPtr[i] = ob.SetPtr[i];
}

/* функция осуществляет поиск элемента во множестве и возвращает номер этого элемента; если элемент не найден, функция возвращает –1: */
template <class Stype> int Set <Stype>::find (Stype member)
{
	for (int i=0; i< NumMembers; i++)
		if (SetPtr[i] == member) return i;
	return -1;
}

// функция проверяет, входит ли элемент во множество:
template <class Stype> 
int Set <Stype>::ismember(Stype member)
{
	if (find(member) != -1) return 1;
	else return 0;
}

// Основная функция, которая добавляет элемент во множество:
template <class Stype> void Set <Stype>::insert(Stype member)
{
	if (NumMembers == MemSize) // если множество заполнено
	{
		Stype* tmp = new Stype[MemSize+10]; 
// выделяем новую память большего размера
// и копируем туда элементы:
		for (int i =0; i< NumMembers; i++)
			tmp[i] = SetPtr[i];
		delete []SetPtr; // освобождаем ранее выделенную память
		SetPtr = tmp; // настраиваем указатель на новую область памяти
	}
	if (! ismember(member)) // если элемент еще не входит во множество
	{
		int i=0;
// находим для него место:
		while (i<NumMembers && SetPtr[i]<member) i++;
// сдвигаем элементы от этого места вправо:
		for (int j = NumMembers-1; j>=i; j--)
			SetPtr[j+1] = SetPtr[j];
		SetPtr[i] = member; // вставляем элемент
		NumMembers++;
	}
}

// функция удаляет заданный элемент:
template <class Stype> 
void Set<Stype>::remove(Stype member)
{
	int loc = find(member); // определяеи номер этого элемента
	if ( loc != -1) // эсли элемент входит во множество
	{ //
		for(; loc<NumMembers-1; loc++)
			SetPtr[loc] = SetPtr[loc+1]; // сдвигаем элементы влево
		NumMembers--;
	}
}

// функция ввода элементов:
template <class Stype>
 istream& operator >> (istream& stream, Set<Stype> &ob)
{
	Stype member;
	int k;
	cout << "Сколько элементов определить? ";
	cin >> k;
	cout << "Задайте элементы множества \n";
	for (int i=0; i< k; i++)
	{
		cout << i+1 << " --> ";
		stream >> member;
		ob = ob + member;
 // используем нижеследующую операторную функцию +
	}
	return stream;
}

// функция вывода:
template <class Stype> 
ostream& operator << (ostream& stream, Set<Stype> &ob)
{
	stream << "{ ";
	for (int i=0; i<ob.NumMembers; i++)
		stream << ob.SetPtr[i] << " ";
	stream << " }" << endl;
	return stream;
}

// Оператор присваивания:
template <class Stype>
Set<Stype>& Set<Stype>:: operator = (const Set<Stype>& ob)
{
// если выполняется самоприсваивание, функция завершает свою работу:
	if (SetPtr == ob.SetPtr) return *this; 
//  в противном случае выполнчется копирование объекта ob:
	MemSize = ob.MemSize;
	delete []SetPtr;
	SetPtr = new Stype[MemSize];
	NumMembers = ob.NumMembers;
	for (int i=0; i<NumMembers; i++)
		SetPtr[i] = ob.SetPtr[i]; // копирование элементов
	return *this  ;
}

// операция добавления элемента к множеству:
template <class Stype>
Set<Stype>& Set<Stype>:: operator + (Stype member)
{
	insert(member);
	return *this;
}

template <class Stype>
Set<Stype> Set<Stype>::operator + (Set<Stype> &ob) //Объединение множеств
{
	// создаем временный объект с достаточным объемом памяти:
Set<Stype>	temp(MemSize + ob.MemSize);
	for (int i=0; i<NumMembers; i++) 
// копируем элементы первого множества
		 temp.insert(SetPtr[i]);
	for (int i=0; i<ob.NumMembers; i++) 
// копируем элементы второго множества
		temp.insert(ob.SetPtr[i]); 
	return temp;
}

// Оператор, который удаляет заданный элемент из множества:
template <class Stype>
Set<Stype> Set<Stype>:: operator - (Stype member)
{
	Set<Stype> temp(*this);
	temp.remove(member);
	return temp;
}

/* Функция удаляет из первого множества те элементы, которые есть во втором:  */
template <class Stype>
Set<Stype> Set<Stype>:: operator - (Set<Stype>& ob)
{
	Set<Stype> temp(*this);
	for (int i=0; i < ob.NumMembers; i++)
		if (ismember(ob.SetPtr[i]))
	temp.remove(ob.SetPtr[i]);
	return temp;
}

// функция определяет, является ли левое множество подмножеством правого:
template <class Stype>
int Set<Stype>:: operator < (Set<Stype> &ob)
{
	for(int i=0; i<NumMembers; i++)
		if (!ob.ismember(SetPtr[i])) return 0;
	return 1;
}

// сравнение на равенство:
template <class Stype>
int Set<Stype>:: operator == (Set<Stype> &ob)
{
	if (NumMembers != ob.NumMembers) return 0;
	return *this < ob; /* Если размеры множеств равны и одно из множеств является подмножеством другого, то множества равны */
}

// операция !=
template <class Stype>
int Set<Stype>:: operator != (Set<Stype> &ob)
{
	return !(*this == ob); // Используем ранее определенную операцию ==
}
