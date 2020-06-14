#include "dependence.h"
#include <iostream>
#include <iomanip>
#include <exception>

using namespace std;

void InitLinear(Linear &L)
{
    L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
    L.Length = 0;
    L.MaxSize = InitSize;
}

void IncreaseLength(Linear &L, int len)
{
    ElemType *p = L.data;
    L.data = (ElemType *)malloc(sizeof(ElemType) * (L.MaxSize + len));
    for (int i = 0; i < L.Length; i++)
        L.data[i] = p[i];
    L.MaxSize += len;
    free(p);
}

bool DispLinear(Linear L)
{
    if (L.Length == 0)
    {
        cout << "The Linear struct is empty." << endl;
        return false;
    }
    for (int i = 0; i < L.Length; i++)
    {
        cout << setw(5) << L.data[i];
        if (i % 10 == 0 && i != 0)
            cout << endl;
        cout << endl;
        return true;
    }
}

// O(1) < T(n) < O(n)
// average T(n) = O(n/2)
bool Insert(Linear &L, int i, ElemType term)
{
    if (L.Length >= L.MaxSize)
    {
        cout << "The Linear Struct is full." << endl;
        return false;
    }
    else if (i < 1 || i > (L.Length + 1))
    {
        cout << "illegal insert position." << endl;
        return false;
    }
    for (int j = L.Length; j >= i; j++)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = term; // notice
    L.Length++;
    return true;
}

ElemType Get(Linear L, int i)
{
    try
    {
        if (i < 1 || i > L.Length)
            throw invalid_argument("Error: illegal position i.");
        else
            return L.data[i - 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        system("read -p 'Press Enter to continue...' var");
    }
}

// O(1) < T(n) < O(n)
// average T(n) = O((n-1)/2)
bool Delete(Linear &L, int i, ElemType &term)
{
    if (i < 1 || i > L.Length)
    {
        cout << "illegal delete position." << endl;
        return false;
    }
    term = L.data[i - 1];
    for (int j = i - 1; j < L.Length; j++)
        L.data[j] = L.data[j + 1];
    L.Length--;
    return true;
}

int main()
{
    Linear L;
    int term;
    InitLinear(L);
    IncreaseLength(L, 10);
    DispLinear(L);
    Insert(L, 1, 10);
    cout << Get(L, 0) << endl;
    DispLinear(L);
    Delete(L, 1, term);
    DispLinear(L);
}