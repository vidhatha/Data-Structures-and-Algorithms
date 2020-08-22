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

### Elemental Access Usage
```cpp
int main()
{
   	vector<int> vv;

    	for(auto i=0; i<10; i++)
        	vv.push_back(i);

   	 cout<<"Reference operator [] : v[2] = "<<vv[2]<<endl; 	// vv[2] = 2

    	cout<<"at() : vv.at(3) = " << vv[3]<<endl;		//vv.at(3) = 3

	cout<<"front(): vv.front() = "<<vv.front()<<endl; 	//vv.front() = 0

	cout<<"back(): vv.back() = "<<vv.back()<<endl;		//vv.back() = 9
}
```
### Modifiers Usage
```cpp
int main()
{
	vector<int> vv;
	
	//fill the array with number 10, five times
	vv.assign(5,10);
	
	//insert 15 to last position
	vv.push_back(15);

	//removes last element
	vv.pop_back();

	// insert operations
	vector<int> vect_ins(3,100); //vect_ins = 100 100 100
	vector<int>::iterator it;
	
	it= vect_ins.begin();
	it = vect_ins.insert(it, 200); //vect_ins = 200 100 100 100
	
	vect_ins.insert(it,2,300); //vect_ins = 300 300 200 100 100 100
	
	//"it" no longer valid, get a new one.
	it = vect_ins.begin();

	vector<int> vec_ins2(2, 400); //vec_ins2 = 400 400
	vect_ins.insert(it+2, vect_ins2.begin(), vect_ins2.end()); //vec_ins = 300 300 400 400 100 100 100

	//erase operations
	vector<int> vect_er;
	for(auto i=0;i<10;++i) vect_er.push_back(i);
	//erase 6th element
	vect_er(vect_er.begin()+5);
	//erase the first 3 elements
	vect_er(vect_er.begin(), vect_er.begin()+3);
	
	//swap operations
	v1.swap(v2);
	//clear
	vect_er.clear();
}
```
