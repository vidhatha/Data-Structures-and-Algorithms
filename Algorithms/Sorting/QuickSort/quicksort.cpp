#include <iostream>
#include <vector>

using namespace std;

class QuickSort
{
public:
    /* Partition sort for some j
    *   - entry a[j] is in place
    *   - no larger element to the left of j
    *   - no smaller element to the right of j
    */
    int partition(vector<int>& a, int low, int high)
    {
        int i = low, j = high + 1;
        int pivot = low;

        while (true)
        {
            while (a[++i] < a[pivot])
                if (i == high) break;

            while (a[--j] > a[pivot])
                if (j == low) break;   //redundant as pivot is a[low]

            if (i >= j) break;
            swap(a[i], a[j]);
        }
        swap(a[pivot], a[j]);

        return j;
    }

    void sort(vector<int>& a)
    {
        //perform random shuffle

        //then sort
        sort(a, 0, a.size() - 1);
    }

    void sort(vector<int>& a, int low, int high)
    {
        if (high <= low) return;
        int pivot = partition(a, low, high);

        sort(a, low, pivot - 1);
        sort(a, pivot + 1, high);
    }
};

int main()
{
    vector<int> a{ 10, 80, 30, 30, 90, 40, 50, 70 };
    QuickSort qs;

    for (int x : a)
        cout << x << " ";
    cout << endl;

    qs.sort(a);

    for (int x : a)
        cout << x << " ";
    cout << endl;

    return 0;
}
