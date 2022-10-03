#include "HeshTable.h"
#include <string>
#include <fstream>
#include <iostream>
#include <set>
using namespace std;
int const Ner = 10;
int getRandomNumber()
{
	return rand() % ::Ner;
}        // количество имен в массиве
const char* names[::Ner] = { "Jhon", "Alex", "Georg", "Sidny", "Angelina",
								"Kollin", "Mary", "Sun", "Robert", "Garry"
};
const char* snames[::Ner] = { "Abram", "Dauny", "Jhukof", "Jolly", "Umbrella",
								"Mishel", "Ackles", "Potter", "North", "Sikker"
};
set <string> typN{ "Single", "Double", "Triple", "Extra", "Presidential" };
set <char> ss{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; 
void HeshTable::In() { //создаю файл на 11111 записей
	std::ofstream out;          // поток для записи
	out.open("C:\\T.txt"); // окрываем файл для записи
	if (out.is_open())
	{
		for (int i = 0; i < n; ++i) {
			switch (i % 5) {
			case 0:
				out << names[getRandomNumber()] << ' ' << snames[getRandomNumber()];
				out << ' ';
				out << "Single ";
				break;
			case 1:
				out << names[getRandomNumber()] << ' ' << snames[getRandomNumber()];
				out << ' ';
				out << "Double ";
				break;
			case 2:
				out << names[getRandomNumber()] << ' ' << snames[getRandomNumber()];
				out << ' ';
				out << "Triple ";
				break;
			case 3:
				out << names[getRandomNumber()] << ' ' << snames[getRandomNumber()];
				out << ' ';
				out << "Extra ";
				break;
			case 4:
				out << names[getRandomNumber()] << ' ' << snames[getRandomNumber()];
				out << ' ';
				out << "Presidential ";
				break;
			}
			if (i == n - 1) {
				out << rand() % 3 << rand() % 9 + 1 << '.' << rand() % 1 << rand() % 9 + 1 << '.' << rand() % 5000 << ' ' << rand() % 10000 << " +" << rand() % 1000000;
			}
			else {
				out << rand() % 3 << rand() % 9 + 1 << '.' << rand() % 1 << rand() % 9 + 1 << '.' << rand() % 5000 << ' ' << rand() % 10000 << " +" << rand() % 1000000 << endl;
			}
		}
		out.close();
	}
}
void HeshTable::Read() {
	In(); //создаю файл на 11111 записей
	int g;  //темповая переменная для свапа массива
	char w = ' '; //темповая переменная чтобы файл читать
	int i = 0;
	int j = 0;
	ifstream s("C:\\T.txt");
	string r;
	int d[4];
	//getline(s, r);
	while (!s.eof()) {  //читаю файл, формирую массив для сортировки
		int fio = 0; //читаю фио (2 words, first and second name)	
		s.get(w);
		wow[j].name = w;
		while (fio <= 1) {
			s.get(w);
			if (w == ' ') {
				fio++;
				if (fio == 1) {
					wow[j].name += w;
				}
			}
			else wow[j].name += w;
		}
		fio = 0;
		i = 0;			//читаю тип номера
		s.get(w);
		while (w != ' ') {
			wow[j].type += w;
			s.get(w);
			i++;
		}
		while (!ss.count(w)) {        //читаю дату
			s.get(w);
		}
		wow[j].day = (w - '0') * 10;
		s.get(w);
		wow[j].day += w - '0';
		s.get(w); s.get(w);
		wow[j].mou = (w - '0') * 10;
		s.get(w);
		wow[j].mou = (w - '0');
		s.get(w); s.get(w);
		wow[j].year = (w - '0') * 1000;
		s.get(w);
		wow[j].year += (w - '0') * 100;
		s.get(w);
		wow[j].year += (w - '0') * 10;
		s.get(w);
wow[j].year += (w - '0');
s.get(w);
while (!ss.count(w)) {
	s.get(w);
}
i = 0;
d[i] = w - '0';
while (ss.count(w)) {  //доп массив для кол-ва дней
	s.get(w);
	if (!ss.count(w)) break;
	i++;
	d[i] = w - '0';
}
if (i == 3) {  //читаю дни
	g = d[0];
	d[0] = d[3];
	d[3] = g;
	g = d[1];
	d[1] = d[2];
	d[2] = g;
}
else if (i == 2) {
	g = d[0];
	d[0] = d[2];
	d[2] = g;
}
else if (i == 1) {
	g = d[0];
	d[0] = d[1];
	d[1] = g;
}
wow[j].per = 0;
while (i != -1) {  //сколько дней 
	if (i == 0)  wow[j].per += d[i];
	else wow[j].per += d[i] * Ten(i);
	i--;
}
while (w != '+') {
	s.get(w);
}
wow[j].numb = w;  //в этом блоке номер телефона
getline(s, r);
wow[j].numb += r;
j++;
	}
}
HeshTable::HeshTable() {
	Read();
	for (int i = 0; i < n; i++) {
		tabl[i].status = 0;
	}
}
int HeshTable::Svertka(int s) {
	int t;
	int key = 0;
	while (s > 0) {
		t = s % 100;
		key += t;
		s /= 100;
	}
	while (key > n) {
		key %= n;
	}
	return key;
}
int HeshTable::Helper(str s) {
	if (s.day > s.mou) {
		s.day *= 100;
		s.day += s.mou;
		s.year *= 10000;
		s.year += s.day;
		return s.year;
	}
	else {
		s.mou *= 100;
		s.mou += s.mou;
		s.year *= 10000;
		s.year += s.mou;
		return s.year;
	}
}


void HeshTable::Add(str v) {
	int k = Svertka(Helper(v));
	int s = k;
	int q = 0;
	while (tabl[k].status) {
		k++;
		k %= n;
		q++;
		if (q > n) {
			cout << "table is full\n";
			return;
		}
	}
	tabl[k].index = s;
	tabl[k].value = v;
	tabl[k].status = 1;
}

int HeshTable::reInd(int t) {
	for (int i = 0; i < n; i++) {
		if (tabl[i].index == t && tabl[i].status) return i;
	}
	return t;
}

bool operator == (HeshTable::str x, HeshTable::str y) {
	return (y.year == x.year && y.day == x.day && y.name == x.name && y.mou == x.mou && y.numb == x.numb && y.per == x.per && y.type == x.type);
}
void HeshTable::Delete(str s) {
	int k = Find(s);
	if (k == -1) {
		cout << "There isn't this line\n"; return;
	}
	else {
		tabl[k].status = 0;
		swap(tabl[k], tabl[reInd(k)]);
	}
}

int HeshTable::Find(str s) {
	int max = Size();
	int i = 0;
	int k = Svertka(Helper(s));
	while (tabl[k].status != 0 && i < max) {
		if (tabl[k].value == s && tabl[k].status) return k;
		else {
			k++;
			k %= n;     
			i++;
		}
	}
	return -1;
}


HeshTable::~HeshTable() {
	for (int i = 0; i < n; i++) {
		tabl[i].status = 0;
	}
}