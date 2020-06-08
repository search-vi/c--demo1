#include "Dependences/Methods.h"
#include "Dependences/Respontises.h"
#include <iostream>

// without sentinel
// S(n) = O(1)
// best T(n) = O(n)
// Avergae T(n) = O(n^2)
// stable
void Insert_Sort(int A[], int n)
{
    int j;
    for (int i = 1; i < n; i++)
    {
        if (A[i] < A[i - 1])
        {
            int temp = A[i];
            for (j = i - 1; j >= 0 && A[j] > temp; j--) //stable
                A[j + 1] = A[j];
            A[j + 1] = temp;
        }
    }
}

// with sentinel
// Array start from 2
void Insert_Sort_with_sentinel(int A[], int n)
{
    int j;
    for (int i = 2; i < n; i++)
    {
        if (A[i] < A[i - 1])
        {
            A[0] = A[i];
            for (j = i - 1; A[j] > A[0]; j++)
                A[j + 1] = A[j];
            A[j + 1] = A[0];
        }
    }
}

// with half-search
// T(n) = O(n^2)
void Insert_Sort_with_half_search(int A[], int n)
{
    int low, high, mid, j;
    for (int i = 2; i < n; i++)
    {
        if (A[i] < A[i - 1])
        {
            A[0] = A[i];
            low = 1;
            high = i - 1;
            while (low <= high)
            {
                mid = (low + high) / 2;
                if (A[mid] > A[0])
                    high = mid - 1;
                else
                    low = mid + 1; //stay stable
            }
            for (j = i - 1; j >= low; --j)
                A[j + 1] = A[j];
            A[low] = A[0];
        }
    }
}

int main()
{
    int i = 0;
    int A[] = {25, 40, 16, 38, 77, 64, 53, 88, 9, 48, 98};
    Insert_Sort(A, 11);
    while (i < 11)
        std::cout << A[i++] << '\t';
}