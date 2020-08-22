**std::list** are sequence containers that allow non-contiguous memory allocation.
 
### Syntax:
> `std::list< object_type > list_name;`

### Complexity
**TBD**

#### Element access:
Function      | Description
------------- | -------------
front | Returns the value of the first element in the list.
back | Returns the value of the last element in the list .

#### Modifiers:
Function      | Description
------------- | -------------
assign | Assign vector content
push_back | Add element at the end
pop_back | Delete last element
push_front | Add element at the front
push_back | Add element at the end
insert | Insert elements
erase | Erase elements
swap | Swap content
clear | Clear content
resize | change size of the list container
emplace | Construct and insert element
emplace_front | Construct and insert element at beginning
emplace_back | Construct and insert element at the end

#### Capacity:
Function      | Description
------------- | -------------
size | Return size
max_size | Return maximum size
empty | Test whether vector is empty

#### Operations:
Function      | Description
------------- | -------------
remove | Removes all elements fron list equal to given element
remove_if | Remove all values from list that correspond true to the predicate or condition given as parameter to the function
unique | Removes all duplicate consecutive elements
merge | Merges two sorted lists into one
sort | Sorts the list in increasing order
reverse | Reverses the list
splice | Used to transfer elements from one list to another

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

