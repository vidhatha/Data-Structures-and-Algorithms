/*
 * Time complexity = O(n2)
 * Space complexity = O(1)
*/
#include <iostream>
#include <vector>

using namespace std;

void SelectionSort(vector<int>& a)
{
    int min_index;
    int n = a.size();

    for(auto i=0;i<n-1;++i)
    {
        min_index = i;
        for(auto j =i; j<n;++j)
        {
            if(a[j]<a[min_index])
                min_index = j;
        }
        swap(a[i],a[min_index]);
    }
}

int main()
{
    vector<int> a{12, 8, 3, 7, 10, 8, 23, 5, 17};
    SelectionSort(a);
    for(auto x:a)
        cout<<x<<" ";
    return 0;
}
