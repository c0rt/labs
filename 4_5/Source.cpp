/*
������� 4
��� ������:
	���������� �������������, ������ ������������ �����
�������� ����:
	���������;������ ������������ � ���� �����,
	���������� �� ��� ������������ �����, ���������� ����� ������
�������� ��� �������:
	������� �������� � ������ � ����� ��������  ����������� � ����� ������
	�������� ��������� � ���� ����������� ���������� ��������.
	����� �������� - �� ��������� ��������.
	���������� ������  �� ��������. 
	����������  ���� ��������� ������ (�� �����)
*/

/*
����������� ��������� ���:

1.	�������� ��������� ��������� ������ ��������� ���� � ������������ ������,
	����� �������� ������ �� �����, ��������� ������ ����� ����������.
2. ���������� �������� �������� ��� ������� (� ����� ����� � �
	����� ������������������, �.� ����� �������� - �� ����).

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct LIST {
	double val;
	LIST *pnext;
	LIST *prev;
};

void printList(LIST *ph);
void menu(LIST *ph);
void findValue(LIST * ph, double temp);
void sortList(LIST * ph);
LIST* addList(LIST *ph, double v);

int main(int argc, char *argv[]) {
	setlocale(0, "Rus");

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	LIST *ph = NULL;
	double temp;
	while (fin >> temp) {
		ph = addList(ph, temp);
	}
	cout << "������ ������� ������ �� �����:" << endl;
	printList(ph);

	menu(ph);
	return 0;
}

//������������� ������
LIST *init(double v) {
	LIST *pnew = new LIST;
	pnew->val = v;
	pnew->pnext = pnew->prev = NULL;
	return pnew;
}

//���������� �������� � ������
LIST *addList(LIST *ph, double v) {
	// 1)������ ����?
	// 2) ������������ ������� - ������
	// 3) ������ �������� ��������
	if (ph == NULL) {
		ph = init(v);
		return ph;
	}
	LIST *cur;
	for (cur = ph; (cur->pnext != NULL) && (v>cur->val); cur = cur->pnext);
	
	if (cur->pnext == NULL){    //������� � ����� ������
		LIST *pnew = init(v);
		cur->pnext = pnew;
		pnew->prev = cur;
		return ph;
	}

	return ph;
}

//����� ������ � ����������� �����
void printList(LIST *ph) {
	for (LIST*cur = ph; cur != NULL; cur = cur->pnext)
		cout << cur->val << endl;
}

//��������� ������ ����
void menu(LIST *ph) {
	short unsigned int m;
	double temp;

	string s;

	system("cls");
	for (int i = 0; i < 15; i++) {
		cout << "-";
	}
	cout << endl << "���� �������� ��� �������:" << endl;
	cout << "1. ������� �������� � ����� ������." << endl;
	cout << "2. ������� ��� ��������, ������� ������ �������." << endl;
	cout << "3. ����� ��������." << endl;
	cout << "4. ���������� ������ �� ��������." << endl;
	cout << "5. ����� ������ �� �����." << endl;
	cout << "6. ����� �� ���������." << endl;
	cin >> m;
	switch (m) {
	case(1): cout << "������� ��������, ������� ������ �������� � ����� ������:" << endl;  break;
	case(2): cout << "������� ��������:" << endl; cin >> temp;  break;
	case(3): cout << "������� ��������:" << endl; cin >> temp; findValue(ph, temp); break;
	case(4): sortList(ph); break;
	case(5): system("cls"); printList(ph); break;
	case(6):
		cout << "�� ������������� ������ ������� ���������? (y/n)" << endl;
		cin >> s;
		if (s == "y" || s == "�" || s == "�")
			return;
		break;
	default:
		cout << "������� ������������ �������, ��������� �������." << endl;
		break;
	}
	menu(ph);
}

//����� ��������� �������� � ������
void findValue(LIST *ph, double temp) {
	
}

//���������� ������ �� ��������
void sortList(LIST *ph) {

}