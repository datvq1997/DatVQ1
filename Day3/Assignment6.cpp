#include <iostream>

using namespace std;

/*****************************
* Name:         importData
* Description:  Import data matrix
* Arguments:
    pArr: pointer to memory allocated in importData() function
    szRow: Row of matrix
    szCol: Col of matrix
* Return:
    true: success
    false: fail
*****************************/
bool importData(int*** pArr, int szRow, int szCol)
{
    *pArr = new int*[szRow];

    for (int i=0;i < szRow;i++)
    {
        (*pArr)[i] = new int[szCol];
    }

    for (int i=0; i<szRow; i++)
    {
        for (int j=0; j<szCol; j++)
        {
            cout << endl << "[" << i << "]" << "[" << j << "]";
                cin >> (*pArr)[i][j];
        }
    }

    return true;
}

/*****************************
* Name:         add2Matrix
* Description:  Add 2 Matrix
* Arguments:
    pArr1, pArr2: pointer to memory allocated in importData() function
    szRow: Row of matrix
    szCol: Col of matrix
* Return:
    A pointer to the memory area containing the result of matrix addition.
*****************************/
int** add2Matrix(int** pArr1, int** pArr2, int szRow, int szCol)
{
    int** pArrAdd = new int*[szRow];
    for (int i=0;i < szRow;i++)
    {
        pArrAdd[i] = new int[szCol];
    }

    for (int i=0; i<szRow; i++)
    {
        for (int j=0; j<szCol; j++)
        {
                pArrAdd[i][j] = pArr1[i][j] + pArr2[i][j];
        }
    }
    return pArrAdd;
}

/*****************************
* Name:         printMatrix
* Description:  Print Matrix to console
* Arguments:
    pArr: pointer to memory allocated in importData() function
    szRow: Row of matrix
    szCol: Col of matrix
* Return: void
*****************************/
void printMatrix(int** pArr, int szRow, int szCol)
{
    for (int i=0; i<szRow; i++)
    {
        for (int j=0; j<szCol; j++)
        {
                cout << pArr[i][j] <<" ";
        }
        cout << endl;
    }
}

/*****************************
* Name:         freeMem
* Description:  Free memmory
* Arguments:
    pArr: pointer to memory allocated in importData() function
    szRow: Row of matrix
    szCol: Col of matrix
* Return: void
*****************************/
void freeMem(int** pArr, int szRow, int szCol)
{
    for (int i=0; i<szRow; i++)
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
    cout << "Input matrix 1 ";
    importData(&pArr1,row,col);
    cout << "Input matrix 2 ";
    importData(&pArr2,row,col);
    // Cong 2 matran
    int** pArrResult = add2Matrix(pArr1,pArr2,row,col);
    // In mang sau khi
    cout << "Matrix result " << endl;
    printMatrix(pArrResult,row,col);
    // Giai phong memory
    freeMem(pArr1,row,col);
    freeMem(pArr2,row,col);
    freeMem(pArrResult,row,col);
}
