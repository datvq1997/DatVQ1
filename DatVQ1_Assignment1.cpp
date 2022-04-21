#include <iostream>

using namespace std;
bool IsPalindrome(int x)
{
	int buf = 0;
	int ReX = 0;
	int temp = x;
 	do {
		buf = temp % 10;
		temp = temp / 10;
		ReX = ReX * 10 + buf;
	} while (temp != 0);

	if (ReX == x) {
		return true;
	}
	return false;
}

int main()
{
	int x; 

	cout << "Number : ";
	cin >> x;
	if (IsPalindrome(x) == true) {
		cout << "\n" << x << " is Palindrome \n";
	}
	else {
		cout << "\n" << x << " isn't Palindrome \n";
	}
}


