/*
Вариант 4
Тип списка:
	Двусвязный нециклический, хранит вещественные числа
Исходный Файл:
	Текстовый; данные представлены в виде строк,
	содержащих по два вещественных числа, записанных через пробел
Действия над списком:
	Вставка элемента в список – новые элементы  добавляются в конец списка
	Удаление элементов – всех превышающих задаваемое значение.
	Поиск элемента - по вводимому значению.
	Сортировка списка по убыванию. 
	Распечатка всех элементов списка (на экран)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

struct LIST {
	double val;
	LIST * pnext;
	LIST * prev;
};

void printList(LIST *ph);
void menu(LIST *ph);
void cont();
void findValue(LIST * ph, double temp);
void sortList(LIST * ph);
void deleteList(LIST * ph, double value);
LIST * addList(LIST * ph, double v);

int main(int argc, char * argv[]) {
	setlocale(0, "Rus");

	ifstream fin("input.txt");

	LIST * ph = NULL;
	double temp;

	while (fin >> temp) {
		ph = addList(ph, temp);
	}
	fin.close();

	menu(ph);
	return 0;
}

//инициализация списка
LIST * init(double v) {
	LIST * pnew = new LIST;
	pnew->val = v;
	pnew->pnext = pnew->prev = NULL;
	return pnew;
}

//добавление элемента в список
LIST * addList(LIST * ph, double v) {
	if (ph == NULL) {
		ph = init(v);
		return ph;
	}

	LIST * cur;
	for (cur = ph; (cur->pnext != NULL); cur = cur->pnext);
	
	if (cur->pnext == NULL) {    //вставка в конец списка
		LIST *pnew = init(v);
		cur->pnext = pnew;
		pnew->prev = cur;
		return ph;
	}
	return ph;
}

//вывод списка в стандартный поток
void printList(LIST * ph) {
	system("cls");
	cout << "Значения в списке:" << endl;
	for (LIST*cur = ph; cur != NULL; cur = cur->pnext)
		cout << cur->val << endl;
}

//Процедура вывода меню
void menu(LIST * ph) {
	short unsigned int m;
	double temp;

	string s;

	system("cls");
	for (int i = 0; i < 70; i++) {
		cout << "-";
	}

	cout << endl << "\t\tМеню действий над списком:" << endl;
	cout << "\t1. Вставка элемента в конец списка." << endl;
	cout << "\t2. Удалить все элементы, которые больше зачения." << endl;
	cout << "\t3. Поиск элемента." << endl;
	cout << "\t4. Сортировка списка по убыванию." << endl;
	cout << "\t5. Вывод списка на экран." << endl;
	cout << "\t6. Выйти из программы." << endl;
	cin >> m;

	switch (m) {
	case(1): cout << "Введите значение: "; cin >> temp; addList(ph, temp);  break;
	case(2): cout << "Введите значение: " << endl; cin >> temp; deleteList(ph, temp); break;
	case(3): cout << "Введите значение: " << endl; cin >> temp; findValue(ph, temp); break;
	case(4): sortList(ph); cout << "Сортировка выполнена успешно." << endl; break;
	case(5): printList(ph); break;
	case(6):
		cout << "Вы действительно хотите выйти из программы? (y/n)" << endl;
		cin >> s;
		if (s == "y")
			return;
		break;
	default:
		cout << "Введено некорректное значеие, повторите попытку." << endl;
		break;
	}
	cont();
	menu(ph);
}

//Поиск заданного значения в списке
void findValue(LIST * ph, double value) {
	unsigned int counter = 1;
	LIST * cur = ph;
	for (cur = ph; (cur->val != value) && (cur->pnext != NULL); cur = cur->pnext)
		counter++;
	if (cur->val == value) {
		cout << "Найденное значние: " << cur->val << endl;
		cout << "В списке под номером: " << counter << endl;
	} else if (cur->pnext == NULL) {
		cout << "Значение не найдено." << endl;
	}
}

//Сортировка списка по убыванию
void sortList(LIST * ph) {
	double temp;
	LIST *cur;
	
	bool exit = false; 

	while (!exit) {
		exit = true;
		for (cur = ph; cur->pnext->pnext != NULL; cur = cur->pnext)
			if (cur->val < cur->pnext->val) {
				temp = cur->val;
				cur->val = cur->pnext->val;
				cur->pnext->val = temp;
				exit = false; 
			}
		if (cur->val < cur->pnext->val) {
			temp = cur->val;
			cur->val = cur->pnext->val;
			cur->pnext->val = temp;
			exit = false;
		}
	}
}

//удаление элементов, превышающих данное значение
void deleteList(LIST * ph, double value) {
	LIST * cur = ph;
	for (cur = cur->pnext; cur->pnext != NULL; cur = cur->pnext) {
		if (cur->val > value) {
			LIST * temp = cur;
			cur->pnext->prev = temp->prev;
			cur->prev->pnext = temp->pnext;
			cur = cur->prev;
			delete temp;
		}
	}
	if (ph->prev == NULL && ph->val > value) {
		LIST * temp = ph;
		ph = ph->pnext;
		delete temp;
		ph->prev = NULL;
	}
	if (cur->pnext == NULL && cur->val > value) {
		LIST * temp = cur;
		cur = cur->prev;
		delete temp;
		cur->pnext = NULL;
	}
}

//"Для продолжения намите любую клавишу . . ."
void cont() {
	cout << "Для продолжения намите любую клавишу . . . ";
	_getch();
}