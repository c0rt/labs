/*
������� 4
��� ������:
	���������� �������������, ������ ������������ �����
�������� ����:
	���������; ������ ������������ � ���� �����,
	���������� �� ��� ������������ �����, ���������� ����� ������
�������� ��� �������:
	������� �������� � ������ � ����� ��������  ����������� � ����� ������
	�������� ��������� � ���� ����������� ���������� ��������.
	����� �������� - �� ��������� ��������.
	���������� ������ �� ��������. 
	���������� ���� ��������� ������ (�� �����)
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

//������������� ������
LIST * init(double v) {
	LIST * pnew = new LIST;
	pnew->val = v;
	pnew->pnext = pnew->prev = NULL;
	return pnew;
}

//���������� �������� � ������
LIST * addList(LIST * ph, double v) {
	if (ph == NULL) {
		ph = init(v);
		return ph;
	}

	LIST * cur;
	for (cur = ph; (cur->pnext != NULL); cur = cur->pnext);
	
	if (cur->pnext == NULL) {    //������� � ����� ������
		LIST *pnew = init(v);
		cur->pnext = pnew;
		pnew->prev = cur;
		return ph;
	}
	return ph;
}

//����� ������ � ����������� �����
void printList(LIST * ph) {
	system("cls");
	cout << "�������� � ������:" << endl;
	for (LIST*cur = ph; cur != NULL; cur = cur->pnext)
		cout << cur->val << endl;
}

//��������� ������ ����
void menu(LIST * ph) {
	short unsigned int m;
	double temp;

	string s;

	system("cls");
	for (int i = 0; i < 70; i++) {
		cout << "-";
	}

	cout << endl << "\t\t���� �������� ��� �������:" << endl;
	cout << "\t1. ������� �������� � ����� ������." << endl;
	cout << "\t2. ������� ��� ��������, ������� ������ �������." << endl;
	cout << "\t3. ����� ��������." << endl;
	cout << "\t4. ���������� ������ �� ��������." << endl;
	cout << "\t5. ����� ������ �� �����." << endl;
	cout << "\t6. ����� �� ���������." << endl;
	cin >> m;

	switch (m) {
	case(1): cout << "������� ��������: "; cin >> temp; addList(ph, temp);  break;
	case(2): cout << "������� ��������: " << endl; cin >> temp; deleteList(ph, temp); break;
	case(3): cout << "������� ��������: " << endl; cin >> temp; findValue(ph, temp); break;
	case(4): sortList(ph); cout << "���������� ��������� �������." << endl; break;
	case(5): printList(ph); break;
	case(6):
		cout << "�� ������������� ������ ����� �� ���������? (y/n)" << endl;
		cin >> s;
		if (s == "y")
			return;
		break;
	default:
		cout << "������� ������������ �������, ��������� �������." << endl;
		break;
	}
	cont();
	menu(ph);
}

//����� ��������� �������� � ������
void findValue(LIST * ph, double value) {
	unsigned int counter = 1;
	LIST * cur = ph;
	for (cur = ph; (cur->val != value) && (cur->pnext != NULL); cur = cur->pnext)
		counter++;
	if (cur->val == value) {
		cout << "��������� �������: " << cur->val << endl;
		cout << "� ������ ��� �������: " << counter << endl;
	} else if (cur->pnext == NULL) {
		cout << "�������� �� �������." << endl;
	}
}

//���������� ������ �� ��������
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

//�������� ���������, ����������� ������ ��������
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

//"��� ����������� ������ ����� ������� . . ."
void cont() {
	cout << "��� ����������� ������ ����� ������� . . . ";
	_getch();
}