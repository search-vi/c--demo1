#include <iostream>
#include <algorithm>
using namespace std;

// S(n) = O(1)
// T(n) = O(n^2)
// unstable
template <typename T>
void Select_Sort(T A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (A[j] < A[min])
                min = j;
        if (min != i)
            std::swap(A[i], A[min]);
    }
}

int main()
{
    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(A) / sizeof(*A);
    Select_Sort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << '\t';
}