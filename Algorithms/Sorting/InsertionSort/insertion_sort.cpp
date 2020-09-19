/*
* Time Complexity - O(n2)
* Space complexity - O(1)
*/
#include <iostream>
#include <vector>

using namespace std;

void insertionsort(vector<int>& a)
{
    for(auto i=1;i<a.size(); ++i)
        for(auto j=i; j>0; --j)
            if(a[j]<a[j-1])
                swap(a[j],a[j-1]);
}

int main()
{
    vector<int> a{12, 8, 3, 7, 10, 8, 23, 5, 17};
    insertionsort(a);
    for(auto x:a)
        cout<<x<<" ";
    return 0;
}
