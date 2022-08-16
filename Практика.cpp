#pragma warning(disable : 4996)


#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <stdlib.h>

using namespace std;
struct Produkt {
	string name;
	string manufacturer;
	float price;
	int quantity;
	float percent;
};
void output(vector<Produkt>& Stock) {
	for (int i = 0; i < Stock.size(); i++) {
		cout << "\n" << (i + 1) << "." << Stock[i].name << " " << Stock[i].manufacturer << " " << Stock[i].price << " " << Stock[i].quantity << " " << Stock[i].percent;
	}
}
void inputConcole(vector<Produkt> &Stock)
{
	cout << "������� ������� ����� ������?";
	int plusSize = 0;
	cin >> plusSize;
	cout << "����:";
	string name;
	string manufacturer;
	float price;
	int quantity;
	float percent;
	for (int i = 0; i < plusSize; i++) {
		cout << "���:"; cin >> name;
		cout << "�������������:"; cin >> manufacturer;
		cout << "����:"; cin >> price;
		cout << "����������:"; cin >> quantity;
		cout << "������� �������� ��������:"; cin >> percent;
		Stock.push_back(Produkt{ name ,manufacturer, price, quantity, percent });
	}
}
void inputFile(vector<Produkt> &Stock,ifstream &Text) {
	string produkt;
	string name;
	string manufacturer;
	float price;
	int quantity;
	float percent;
	while (!Text.eof()) {

		getline(Text, produkt);

		name = produkt.substr(0,produkt.find(" "));
		produkt.erase(0, produkt.find(" ") + 1);

		manufacturer = produkt.substr(0, produkt.find(" "));
		produkt.erase(0, produkt.find(" ") + 1);

		price =stof(produkt.substr(0, produkt.find(" ")));
		produkt.erase(0, produkt.find(" ") + 1);

		quantity = stoi(produkt.substr(0, produkt.find(" ")));
		produkt.erase(0, produkt.find(" ") + 1);

		percent = stof(produkt.substr(0, produkt.find(" ")));
		produkt.erase(0, produkt.find(" ") + 1);
		
        Stock.push_back(Produkt{ name ,manufacturer, price, quantity, percent });
	}

}


void sort(vector<Produkt> &a,int begin,int end) {
	
	cout << begin << ":" << end << "\n";
	int i = begin, j = end - 1;
	Produkt temp, p;

	p = a[(end+ begin )>> 1];

	
	do {
		while (strcmp(a[i].name.c_str() , p.name.c_str())<0) i++;
		while (strcmp(a[j].name.c_str(), p.name.c_str())>0)  j--;

		if (i <= j) {
			//output(a);
			//cout << i << ":" << j << "\n";
			temp = a[i]; a[i] = a[j]; a[j] = temp;
			//output(a);
			//cout << 1;
			i++; j--;
		}
	} while (i <= j);


	
	if (j > begin) sort(a, begin,j);
	if (end > i) sort(a , i, end);
}

void sort(vector<Produkt>& a) {
	Produkt x;
	for (int i = 0; i < a.size(); i++) {            // i - ����� �������
		for (int j = a.size() - 1; j > i; j--) {     // ���������� ���� �������
			if (a[j - 1].name > a[j].name) {
				x = a[j - 1]; a[j - 1] = a[j]; a[j] = x;
			}
		}
	}
}
void sort1(vector<Produkt>& a) {
	Produkt x;
	for (int i = 1; i < a.size(); i++)
		for (int j = i; j > 0 && a[j - 1].name > a[j].name; j--) // ���� j>0 � ������� j-1 > j, x-������ int
			swap(a[j - 1], a[j]);        // ������ ������� �������� j � j-1
}
void search(vector<Produkt>& Stock) {
	cout << "\n����� �� ������ �������?";
	cout << "\n1)���";
	cout << "\n2)�������������";
	cout << "\n3)����"; 
	cout << "\n4)����������"; 
	cout << "\n5)������� �������� ��������\n";
	int in = getche() - '0';
	cout << "\n����� ���?";
	string fin;
	cin >> fin;
	if (in == 1) {
		for (int i = 0; i < Stock.size(); i++) {
			if (Stock[i].name.find(fin) != -1) {
				cout << "\n" << (i + 1) << "." << Stock[i].name << " " << Stock[i].manufacturer << " " << Stock[i].price << " " << Stock[i].quantity << " " << Stock[i].percent;
			}
		}
	}
	else if (in == 2) {
		for (int i = 0; i < Stock.size(); i++) {
			if (Stock[i].manufacturer.find(fin) != -1) {
				cout << "\n" << (i + 1) << "." << Stock[i].name << " " << Stock[i].manufacturer << " " << Stock[i].price << " " << Stock[i].quantity << " " << Stock[i].percent;
			}
		}
	}
	else if (in == 3) {
		for (int i = 0; i < Stock.size(); i++) {
			if (to_string(Stock[i].price).find(fin) != -1) {
				cout << "\n" << (i + 1) << "." << Stock[i].name << " " << Stock[i].manufacturer << " " << Stock[i].price << " " << Stock[i].quantity << " " << Stock[i].percent;
			}
		}
	}
	else if (in == 4) {
		for (int i = 0; i < Stock.size(); i++) {
			if (to_string(Stock[i].quantity).find(fin) != -1) {
				cout << "\n" << (i + 1) << "." << Stock[i].name << " " << Stock[i].manufacturer << " " << Stock[i].price << " " << Stock[i].quantity << " " << Stock[i].percent;
			}
		}
	}
	else if (in == 5) {
		for (int i = 0; i < Stock.size(); i++) {
			if (to_string(Stock[i].percent).find(fin) != -1) {
				cout << "\n" << (i + 1) << "." << Stock[i].name << " " << Stock[i].manufacturer << " " << Stock[i].price << " " << Stock[i].quantity << " " << Stock[i].percent;
			}
		}
	}
	else cout << "\n����� �������� �� 1 �� 5,a �� " << in;
}
void edit(vector<Produkt>& Stock) {
	string name;
	string manufacturer;
	float price;
	int quantity;
	float percent;

	cout << "\n�������� ������� �";
	int i = getche() - '0';

	cout << "\n���:"; cin >> name;
	cout << "�������������:"; cin >> manufacturer;
	cout << "����:"; cin >> price;
	cout << "����������:"; cin >> quantity;
	cout << "������� �������� ��������:"; cin >> percent;
	
	Produkt temp{ name ,manufacturer, price, quantity, percent };
	Stock[i] = temp;
	
}
void remove(vector<Produkt>& Stock) {
	cout << "������� ������� �";
	int i = getche() - '0';
	Stock.erase(Stock.begin()+(i-1));
}
void exitAndSave(vector<Produkt>& Stock, ifstream& Text) {
	Text.close();
	ofstream oText("Text.txt");
	
	for (int i = 0; i < Stock.size(); i++) {
		oText <<  Stock[i].name << " " << Stock[i].manufacturer << " " << Stock[i].price << " " << Stock[i].quantity << " " << Stock[i].percent;
		if (i < Stock.size() - 1) oText << "\n";
	}
	oText.close();
	exit(0);
}

int main() {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Produkt> Stock;
	int in;
	ifstream Text("Text.txt");
	
	cout << "1.����\n2.����������\n3.�����\n4.���������\n5.��������\n6.�����\n7.�����";
	while (true) {
		cout << "\n������� �:";
		in = getche() - '0';
		if (in == 1) {
			cout << "C ����������(1) ��� �����(2)?";
			int in1 = getche() - '0';
			if (in1 == 1)inputConcole(Stock);
			else if (in1 == 2)inputFile(Stock, Text);
			else cout << "\n����� �������� �� 1 �� 2,a �� " << in;
		}
		else if (in == 2) {
			
			cout << "�����������(1) ��� ���������(2)?";
			int in1 = getche() - '0';
			if (in1 == 1)sort(Stock);
			else if (in1 == 2)sort1(Stock);
			else cout << "\n����� �������� �� 1 �� 2,a �� " << in;
		}
		else if (in == 3)search(Stock);
		else if (in == 4)edit(Stock);
		else if (in == 5)remove(Stock);
		else if (in == 6)output(Stock);
		else if (in == 7)exitAndSave(Stock,Text);
		else cout << "\n����� �������� �� 1 � � 6,a �� " << in;
		cout << "\n";
	}
}