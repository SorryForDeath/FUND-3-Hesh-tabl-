#include <iostream>
#include "HeshTable.h"
#include <string>
using namespace std;
int main()
{
	HeshTable qwe;
	/*for (int i = 0; i < n; i++) {
		qwe.Add(qwe.wow[i]);
	}*/
	qwe.Add(qwe.wow[1]);
	qwe.Add(qwe.wow[1]);
	qwe.Add(qwe.wow[1]);
	qwe.Add(qwe.wow[1]);
	qwe.Add(qwe.wow[1]);
	qwe.Delete(qwe.wow[1]);
	qwe.Print();
}

