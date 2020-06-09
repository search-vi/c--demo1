#include <iostream>
#include <algorithm>
#include <iomanip>
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

template <typename T>
void shell_sortSp(T array[], int length)
{
    int h = 1;
    while (h < length / 3)
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (int i = h; i < length; i++)
        {
            for (int j = i; j >= h && array[j] < array[j - h]; j -= h)
            {
                std::swap(array[j], array[j - h]);
            }
        }
        h = h / 3;
    }
}

//定义测试时间的函数。
#include <stdlib.h>
#include <time.h>

template <class Func, typename T>
double calc_time(Func f, T R[], int n)
{
    clock_t start = clock();
    f(R, n);
    clock_t finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    return duration;
}

//按照下列方式提供三种不同序列的数据进行测试。

template <class Func, typename T>
void test_different_sequence(Func f, T R[], int n)
{
    sort(R, R + n); //Ascending
    double d1 = calc_time(f, R, n);

    reverse(R, R + n); //Descending
    double d2 = calc_time(f, R, n);

    random_shuffle(R, R + n); //Random
    double d3 = calc_time(f, R, n);

    cout << setw(10) << d1 << setw(10) << d2 << " " << setw(10) << d3 << endl;
}

//获取初始数据。

int *get_n_data(int n)
{
    int *R = new int[n];

    srand((unsigned)time(NULL));
    generate_n(R, n, rand);
    return R;
}

//用不同的数据量进行测试。

template <class Func>
void test(Func f)
{
    static int m[] = {1, 2, 5, 10, 20, 30};
    int mn = sizeof(m) / sizeof(*m);
    int N = 1000;

    cout << setw(13) << "\tAscending" << setw(10) << "\tDescending" << setw(8) << "Random" << endl;
    for (int i = 0; i < mn; ++i)
    {
        cout << m[i] << "\t";
        int n = N * m[i];
        int *R = get_n_data(n);
        test_different_sequence(f, R, n);
        delete[] R;
    }
}

//在main进行测试。

int main()
{
    test(shell_sortSp<int>);
    cout << endl
         << endl
         << endl;
    test(Shell_Sort<int>);
}