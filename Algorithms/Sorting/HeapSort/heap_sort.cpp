/*
* Time Complexity - O(nlog n)
* Space complexity - O(1)
*/
#include <iostream>
#include <vector>

using namespace std;

void max_heapify(vector<int>& a, int heapsize, int parent)
{
    int largest = parent;
    int left_child = 2*parent + 1;
    int right_child = 2*parent + 2;

    //Check if left_child is greater than parent
    if(left_child<heapsize && a[left_child]>a[largest])
        largest = left_child;
    
    //Check if left_child is greater than parent
    if(right_child<heapsize && a[right_child]>a[largest])
        largest = right_child;

    if(largest != parent)
    {
        swap(a[parent], a[largest]);
        max_heapify(a, heapsize, largest);
    }
}

void heapsort(vector<int>& a)
{
    int heapsize = a.size();
    for(auto i=heapsize/2-1; i>=0; --i)
        max_heapify(a, heapsize, i);

    for(auto i=heapsize-1; i>0; --i)
    {
        swap(a[0], a[i]);
        max_heapify(a, i-1, 0);
    }
}

int main()
{
    vector<int> a{12, 8, 3, 7, 10, 8, 23, 5, 17};
    heapsort(a);
    for(auto x:a)
        cout<<x<<" ";
    return 0;
}
