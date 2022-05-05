#include <iostream>

using namespace std;

bool isEvenNum(int num)
{
	if (num % 2 == 0)
	{
		return true;
	} 
	return false;
}

int* get_even_num(int* arr, int* sz)
{
	int i = 0;
	int j = 0;
	int* p_arEvenNum;
	// Kiem tra co bao nhieu so chan
	do
	{
		if (isEvenNum(arr[i]))
		{
			j++;
		}
		i++;
	} while (i < *sz);
	
	// Them cac so chan vao mang moi
	*sz = j;
	p_arEvenNum = new int[*sz];
	do
	{
		i--;
		if (isEvenNum(arr[i]))
		{
			j--;
			p_arEvenNum[j] = arr[i];
		}
	} while (j > 0);
	
	return p_arEvenNum;
}

/*int main()
{
	int sz_arNum;
	int sz_arEvenNum;
	int* p_arNum;
	int* p_arResult;
	int i;
	
	cout << "Size of array number: ";
	cin >> sz_arNum;
	cout << "Input your array: ";
	p_arNum = new int[sz_arNum];
	i = 0;
	do
	{
		cin >> p_arNum[i];
		i++;
	} while (i < sz_arNum);

	sz_arEvenNum = sz_arNum;
	p_arResult = get_even_num(p_arNum, &sz_arEvenNum);
	
	cout << "\nArray of even number: ";
	i = 0;
	do
	{
		cout << p_arResult[i] <<" ";
		i++;
	} while (i < sz_arEvenNum);
}*/
