### Syntax:
> `std::stack<object_type> stack_name;`

### Complexity
All operations take time complexity of O(1)

#### Member functions:
Function      | Description
------------- | -------------
(constructor) | Construct stack.
empty |  Returns whether the stack is empty
size  | Returns the size of the stack
top | Returns a reference to the topmost element of the stack
push(x) | Add an element to the top of the stack
pop() | Delete the topmost element of the stack
swap | Swap elements of stacks
emplace | Adds a new element at the top of the stack, above its current top element
