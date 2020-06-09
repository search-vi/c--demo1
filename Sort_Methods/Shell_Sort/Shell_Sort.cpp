#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void Shell_Sort(T A[], int n)
{
    int D = n / 2;
    int i, j;
    while (D >= 1)
    {
        for (i = D; i < n; i++)
        {
            if (A[i] < A[i - D])
            {
                T temp = A[i];
                for (j = i - D; j >= 0 && A[j] > temp; j -= D)
                    A[j + D] = A[j];
                A[j + D] = temp;
                //for (j = i; j >= D && A[j - D] > temp; j -= D)
                //A[j] = A[j - D];
                //A[j] = temp;
            }
        }
        D /= 2;
    }
}

int main()
{
    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(A) / sizeof(*A);
    Shell_Sort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << '\t';
}