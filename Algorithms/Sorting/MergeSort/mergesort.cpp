//Mergesort
//Robert sedgewick algorithm course

#include<iostream>
#include <vector>

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

    void sort(vector<int>& a, vector<int>& aux, int lo, int hi)
    {
        if (hi <= lo) return;
        int mid = (lo + hi) / 2;
        sort(a, aux, lo, mid);
        sort(a, aux, mid + 1, hi);
        merge(a, aux, lo, mid, hi);
    }

    void sort(vector<int>& a)
    {
        vector<int> aux(a.size());
        sort(a, aux, 0, a.size() - 1);
    }
};

int main()
{
    vector<int> a{ 8, 4, 9, 2, 5, 14, 7, 5, 12, 2 };
    MergeSort ms;
    ms.sort(a);
    for (auto i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    return 0;
}
