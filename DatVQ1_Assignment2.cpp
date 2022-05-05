#include <iostream>

using namespace std;

int main()
{
	int khoangTrang = 4;
	int dauSao = 1;
	do {
		for (int i = 0; i < khoangTrang; i++) {
			cout << " ";
		}
		for (int i = 0; i < dauSao; i++) {
			cout << "*";
		}
		cout << "\n";
		dauSao += 2;
		khoangTrang--;
	} while (khoangTrang > 0);
	do {
		for (int i = 0; i < khoangTrang; i++) {
			cout << " ";
		}
		for (int i = 0; i < dauSao; i++) {
			cout << "*";
		}
		dauSao -= 2;
		khoangTrang++;
		cout << "\n";
	} while (dauSao > 0);
}

