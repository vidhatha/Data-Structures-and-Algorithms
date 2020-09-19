### Syntax:
> `std::priority_queue<object_type> priority_queue_name;`

#### Member functions:
Function      | Description
------------- | -------------
(constructor) | Construct priority_queue.
empty |  Returns whether the priority_queue is empty
size  | Returns the size of the priority_queue
top | Returns a reference to the topmost element of the priority_queue
push(x) | Add an element to the end of the priority_queue
pop() | Delete the topmost element of the priority_queue
swap | Swap elements of priority_queues
emplace | This function is used to insert a new element into the priority queue container, the new element is added to the top of the priority queue.

```cpp
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> pq;

    pq.push(30);
    pq.push(20);
    pq.push(10);
    pq.push(50);
    pq.push(40);

    cout<<"Priority Q Size: "<<pq.size()<<endl;
    cout<<"Max Element: "<<pq.top()<<endl;
    cout<<"Popping max element" <<endl;
    pq.pop();
    cout<<"Priority Q Size: "<<pq.size()<<endl;
    cout<<"Max Element: "<<pq.top()<<endl;
    int new_elem = 60;
    cout<<"Pushing new element: " <<new_elem<<endl;
    pq.push(new_elem);
    cout<<"Priority Q Size: "<<pq.size()<<endl;
    cout<<"Max Element: "<<pq.top()<<endl;
}
```
