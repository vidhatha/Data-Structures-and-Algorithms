 **std::vector** is a sequence container that encapsulates dynamic size arrays.
 
### Syntax:
> `vector< object_type > vector_name;`

### Complexity
The complexity (efficiency) of common operations on vectors is as follows:
- Random access - constant O(1)
- Insertion or removal of elements at the end - amortized constant O(1)
- Insertion or removal of elements - linear in the distance to the end of the vector O(n)

#### Element access:
Function      | Description
------------- | -------------
operator[] | Access element
at | Access element
front | Access first element
back | Access last element
data | Access data

#### Modifiers:
Function      | Description
------------- | -------------
assign | Assign vector content
push_back | Add element at the end
pop_back | Delete last element
insert | Insert elements
erase | Erase elements
swap | Swap content
clear | Clear content
emplace | Construct and insert element
emplace_back | Construct and insert element at the end

#### Capacity:
Function      | Description
------------- | -------------
size | Return size
max_size | Return maximum size
resize | Change size
capacity | Return size of allocated storage capacity
empty | Test whether vector is empty
reserve | Request a change in capacity
shrink_to_fit | Shrink to fit

#### Iterators:
Function      | Description
------------- | -------------
begin | Return iterator to beginning
end | Return iterator to end
rbegin | Return reverse iterator to reverse beginning
rend | Return reverse iterator to reverse end
cbegin | Return const_iterator to beginning
cend | Return const_iterator to end
crbegin | Return const_reverse_iterator to reverse beginning
crend | Return const_reverse_iterator to reverse end

### Initialization
```cpp
int main()
{
	vector<string> v0;

	//1. array-like initialization
	vector<string> v1{"Testing", "vector", "initialization"};

	//2. using push_back
	vector<string> v2;
	v2.push_back("Testing");
	v2.push_back("vector");
	v2.push_back("init using push_back");

	//3. Initializing from another vector
	vector<string> v3(v1.begin(), v1.end());

	//4. Initialize a vector with one element a certain # of times
	vector<string> v4(5, "init element 5 times");

	//5. Initializing from an array
	string arr[] = {"Init" , "using" , "array"};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<string> v5(arr, arr+n);

	for(auto v: v5)
	{
	cout<<v<<endl;
	}
}
```
