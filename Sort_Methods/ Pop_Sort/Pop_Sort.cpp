#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void Pop_Sort(T A[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (A[j] > A[j + 1])
                std::swap(A[j], A[j + 1]);
}

int main()
{
    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(A) / sizeof(*A);
    Pop_Sort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << '\t';
}