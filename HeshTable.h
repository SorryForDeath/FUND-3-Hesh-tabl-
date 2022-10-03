#pragma once
#include <string>
#include <iostream>
using namespace std;
int const n = 100;
class HeshTable
{
public:
	struct str {
		string type;
		string name;
		int day;
		int mou;
		int year;
		int per;
		string numb;
	};
	struct tab {
		int index;
		str value;
	    bool status; // 0 или 1
	};   
	
	
	str wow[n]; //Вспомогательный, читаю в него строки из файла
	tab tabl[n];      //Основной, это моя таблица
	void Read();      //Чтение из файла
	void In();        //Создание файла 
	int Ten(int a) {
		int b = 1;
		for (int i = a; i != 0; i--) {
			b *= 10;
		}
		return(b);
	}
	int Size() {
		int k = 0;
		for (int i = 0; i < n; i++) {
			if (tabl[i].status) k++;
		}
		return k;
	}
	int Svertka(int s);
	int Helper(str s);
	void Add(str s);
	void Delete(str s);
	int Find(str s);
	HeshTable();
	~HeshTable();
	void Print() {
		for (int i = 0; i < n; i++) {
			if (tabl[i].status) {
				cout << tabl[i].value.name << ' ';
				cout << tabl[i].value.type << ' ';
				if (tabl[i].value.day < 10) cout << '0' << tabl[i].value.day << '.';
				else cout << tabl[i].value.day << '.';
				if (tabl[i].value.mou < 10) cout << '0' << tabl[i].value.mou;
				else cout << tabl[i].value.mou;
				cout << '.' << tabl[i].value.year << ' ' << tabl[i].value.per << ' ' << tabl[i].value.numb << endl;
			}
			else cout << i << " line is empty\n";
		}
	}
	str Ent() {
		string fname, fhelp, roomT, numbPS, numbP;
		int d1, m1, y1, perR;
		str t;
		cout << "Enter name\n";
		cin >> fname;
		getline(cin, fhelp);
		fname += fhelp;
		t.name = fname;
		cout << "Enter date\nDay ";
		cin >> d1;
		cout << "\nMonth ";
		cin >> m1;
		cout << "\nYear ";
		cin >> y1;
		t.day = d1;
		t.mou = m1;
		t.year = y1;
		cout << "\nEnter room type ";
		cin >> roomT;
		t.type = roomT;
		cout << "\nEnter period of residence ";
		cin >> perR;
		t.per = perR;
		cout << "\nEnter number of phone ";
		cin >> numbP;
		numbPS = "+" + numbP;
		t.numb = numbPS;
		return t;
	}
	int reInd(int t);
};

