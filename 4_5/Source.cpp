/*
Вариант 4
Тип списка:
	Двусвязный нециклический, хранит вещественные числа
Исходный Файл:
	Текстовый;данные представлены в виде строк,
	содержащих по два вещественных числа, записанных через пробел
Действия над списком:
	Вставка элемента в список – новые элементы  добавляются в конец списка
	Удаление элементов – всех превышающих задаваемое значение.
	Поиск элемента - по вводимому значению.
	Сортировка списка  по убыванию. 
	Распечатка  всех элементов списка (на экран)
*/

/*
Разработать программу для:

1.	Создания элементов линейного списка заданного типа в динамической памяти,
	ввода значений списка из файла, установки связей между элементами.
2. Выполнения заданных действий над списком (в любое время и в
	любой последовательности, т.е выбор действий - по меню).

*/

#include <iostream>
#include <fstream>

using namespace std;

struct LIST {
	double val;
	LIST* pnext;
	LIST* prev;
};

void printList(LIST * ph);
LIST* addList(LIST * ph, double v);

int main(int argc, char* argv[]) {
	setlocale(0, "Rus");

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	LIST *ph = NULL;
	double temp;
	while (fin >> temp) {
		ph = addList(ph, temp);
	}

	/*for (int i = 0; i <= 10; i++) {
		int k = rand() % 100;
		ph = addList(ph, k);
	}*/

	printList(ph);
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
	// 1)список пуст?
	// 2) единственный элемент - голова
	// 3) список частично заполнен
	if (ph == NULL) {
		ph = init(v);
		return ph;
	}
	LIST* cur;
	for (cur = ph; (cur->pnext != NULL) && (v>cur->val); cur = cur->pnext);

	
	if (cur->pnext == NULL)    //вставка в конец списка
	{
		LIST * pnew = init(v);
		cur->pnext = pnew;
		pnew->prev = cur;
		return ph;
	}

	return ph;
}

//вывод в стандартный поток списка
void printList(LIST *ph) {
	for (LIST*cur = ph; cur != NULL; cur = cur->pnext)
		cout << cur->val << endl;
}

//Процедура вывода меню
void menu() {
	short unsigned int m;
	double temp;

	system("cls");
	for (int i = 0; i < 15; i++) {
		cout << "-";
	}
	cout << endl << "Меню действий над списком:" << endl;
	cout << "1. Вставка элемента в конец списка." << endl;
	cout << "2. Удалить все элементы, которые больше, чем введеное число." << endl;
	cout << "3. Поиск элемента." << endl;
	cout << "4. Сортировка списка по убыванию." << endl;
	cout << "5. Вывод списка на экран." << endl;
	cout << "6. Выйти из программы." << endl;
	cin >> m;
	switch (m) {
	case(1): cout << "Введите число, которое хотите добавить в конец списка:" << endl;  break;
	default:
		cout << "Введено некорректное значеие, повторите попытку." << endl;
		break;
	}
	menu();
}