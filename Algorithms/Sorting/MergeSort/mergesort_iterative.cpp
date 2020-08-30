//Mergesort bottom-up (iterative)
//Robert Sedgewick algorithm course

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MergeSort
{
public:
    void merge(vector<int>& a, vector<int>& aux, int lo, int mid, int hi)
    {
        //Assert check if {a[lo],a[mid]} is sorted
        //Assert check if {a[mid+1],a[hi]} is sorted

        for (int k = lo; k <= hi; k++)
            aux[k] = a[k];

        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++)
        {
            if (i > mid)                a[k] = aux[j++];
            else if (j > hi)            a[k] = aux[i++];
            else if (aux[i] < aux[j])   a[k] = aux[i++];
            else                        a[k] = aux[j++];
        }
    }

    void sort_iterative(vector<int>& a)
    {
        int N = a.size();
        vector<int> aux(N);

        for (int sz = 1; sz < N; sz = sz + sz)
            for (int lo = 0; lo < N - sz; lo += sz + sz)
                merge(a, aux, lo, lo + sz - 1, std::min(lo + sz + sz - 1, N - 1));
    }
};

int main()
{
    vector<int> a{ 8, 4, 9, 2, 5, 14, 7, 5, 12, 2 };
    MergeSort ms;
    ms.sort_iterative(a);
    for (auto i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    return 0;
}
