#include <iostream>
#include <string>

using namespace std;
/*****************************
* Name:         findsubstr
* Description:  Find string
* Arguments:
    const char *str: main string
    char *sub: String to search
* Return: int
    Returns the position of the first sub string in the main string.
    If sub does not appear in main string, return -1.
*****************************/
int findsubstr(const char *str, char *sub)
{
    int result = 0;
    int nCount;
    while (*str != '\0')
    {
        result++;
        nCount = 0;
        while (*str == *sub && *sub != '\0')
        {
            str++;
            sub++;
            nCount++;
        }
        if (*sub == '\0') break;
        sub= sub - nCount;
        str= str - nCount;
        str++;
        if (*str == '\0') result = -1;
    }
    return result;
}

int main()
{
    string strInput;
    string strFind;
    // Nhap chuoi chinh
    cout << "Input string: ";
    getline(cin,strInput);
    // Nhap chuoi can tim
    do{
        cout << "Input string find: ";
        getline(cin,strFind);
    } while (strFind.length() > strInput.length());

    // Chuyen 2 chuoi vao sang mang char
    int str_size = strInput.length() + 1;
    char* str = new char[str_size];
    str[str_size-1] = '\0';
    for(int i = 0; i<str_size;i++)
    {
        str[i] = strInput[i];
    }
    
    int sub_size = strFind.length() + 1;
    char* sub = new char[sub_size];
    sub[sub_size - 1] = '\0';
    for (int i = 0; i< sub_size; i++)
    {
        sub[i] = strFind[i];
    }
    // Tim chuoi can tim trong chuoi chinh
    cout << "Result: " << findsubstr(str,sub);
}


