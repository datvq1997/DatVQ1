#include <iostream>

using namespace std;

bool importData(int*** pArr, int szRow, int szCol)
{
    *pArr = new int*[szCol];

    for (int i=0;i < szCol;i++)
    {
        (*pArr)[i] = new int[szRow];
    }

    for (int i=0; i<szCol; i++)
    {
        for (int j=0; j<szRow; j++)
        {
            cin >> (*pArr)[i][j];
        }
    }

    return true;
}

int** add2Matrix(int** pArr1, int** pArr2, int szRow, int szCol)
{
    int** pArrAdd = new int*[szCol];
    for (int i=0;i < szCol;i++)
    {
        pArrAdd[i] = new int[szRow];
    }

    for (int i=0; i<szCol; i++)
    {
        for (int j=0; j<szRow; j++)
        {
            pArrAdd[i][j] = pArr1[i][j] + pArr2[i][j];
        }
    }
    return pArrAdd;
}

void printMatrix(int** pArr, int szRow, int szCol)
{
    for (int i=0; i<szCol; i++)
    {
        for (int j=0; j<szRow; j++)
        {
            cout << pArr[i][j] <<" ";
        }
        cout << endl;
    }
}

void freeMem(int** pArr, int szRow, int szCol)
{
    for (int i=0; i<szCol; i++)
    {
        delete[] pArr[i];
    }
    delete[] pArr;
}

int main()
{
    int row,col;
    cout << " Row: ";
    cin >> row;
    cout << " Col: ";
    cin >> col;

    int** pArr1;
    int** pArr2;
    //Nhap 2 ma tran
    importData(&pArr1,row,col);
    importData(&pArr2,row,col);
    // Cong 2 matran
    int** pArrResult = add2Matrix(pArr1,pArr2,row,col);
    // In mang sau khi cong
    printMatrix(pArrResult,row,col);
    // Giai phong memory
    freeMem(pArr1,row,col);
    freeMem(pArr2,row,col);
    freeMem(pArrResult,row,col);
}
