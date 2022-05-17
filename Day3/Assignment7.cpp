#include <iostream>

using namespace std;

float add(float a, float b)
{
    return a+b;
}

float sub(float a, float b)
{
    return a-b;
}

float multiply(float a, float b)
{
    return a*b;
}

float divide(float a, float b)
{
    return a/b;
}

void operation(float a, float b, float (*p2Func)(float, float))
{
    cout << p2Func(a,b);
}

int main()
{
    // Nhap 2 so a va b
    int a,b,choice;
    cout << "Num a: ";
    cin >> a;
    cout << "Num b: ";
    cin >> b;
    // Menu lua chon thuc hien phep tinh
    cout << endl;
    cout << "1. Add" << endl;
    cout << "2. Sub" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "5. All" << endl;
    cout << "0. Exit" << endl;

    while (1)
    {
        cout <<endl<< "Input number: ";
        cin >> choice;
        switch (choice)
        {
            case 1://Cong
                cout << " Result: ";
                operation(a,b,add);
                break;
            case 2://Tru
                cout << " Result: ";
                operation(a,b,sub);
                break;
            case 3://Nhan
                cout << " Result: ";
                operation(a,b,multiply);
                break;
            case 4://Chia
                cout << " Result: ";
                if (0 == b)
                {
                    cout << "Error divide 0";
                    break;
                }
                operation(a,b,divide);
                break;
            case 5://Thuc hien tat ca phep tinh
                cout << " Result add: ";
                operation(a,b,add);
                cout << endl << " Result sub: ";
                operation(a,b,sub);
                cout << endl << " Result multiply: ";
                operation(a,b,multiply);
                cout << endl << " Result divide: ";
                operation(a,b,divide);
                break;
            case 0://Thoat chuong trinh
                exit(0);
        }
    }

}
