Today we'll learn about how to write a function in C. A function is a block of code that performs a specific type of task. It is a collection of statements that are grouped together to perform a specific task. A function is a set of statements that together perform a task. Every C program has at least one function, which is main(), and all the most trivial programs can define additional functions. You can divide up your code into separate functions. Here is a simple example of a function that adds two numbers and returns the result:

```c
int add(int a, int b) { return a + b; }
```

The function add() takes two parameters, a and b, and returns the result of a + b. The return statement is used to return a value from a function.

## Function Declaration

A function declaration tells the compiler about a function name and how to call the function. The actual body of the function can be defined separately. A function declaration has the following parts:

- Return type - The return type is the data type of the value the function returns. Some functions perform the desired operations without returning a value. In this case, the return type is the keyword void.

- Function name - This is the actual name of the function. The function name and the parameter list together constitute the function signature.

- Parameters - A parameter is like a placeholder. When a function is invoked, you pass a value to the parameter. This value is referred to as actual parameter or argument. The parameter list refers to the type, order, and number of the parameters of a function. Parameters are optional; that is, a function may contain no parameters.

- Function body - The function body contains a collection of statements that define what the function does.

Here is the function declaration for the function add() that we defined above:

```c
int add(int a, int b);
```

here int is the return type, add is the function name, and int a, int b are the parameters.

## Parameter types

There are two ways to pass parameters to a function in C:

- Call by value (also known as value passing) - In this method, the actual value of an argument is passed to the function. In this case, changes made to the parameter inside the function have no effect on the argument.

- Call by reference (also known as reference passing) - In this method, the address of an argument is passed to the function. Inside the function, the address is used to access the actual argument used in the call. This means that changes made to the parameter affect the argument.

For example, the following program uses call by value to swap the values of two variables:

```c
#include <stdio.h>
void swap(int x, int y);
int main() {
    int a = 100;
    int b = 200;
    printf("Before swap, value of a : %d\n", a);
    printf("Before swap, value of b : %d\n", b);
    /* calling a function to swap the values */
    swap(a, b);
    printf("After swap, value of a : %d\n", a);
    printf("After swap, value of b : %d\n", b);
    return 0;
}
void swap(int x, int y) {
    int temp;
    temp = x; /* save the value of x */
    x = y;    /* put y into x */
    y = temp; /* put temp into y */
    return;
}
```

When the above code is compiled and executed, it produces the following result:

```bash
Before swap, value of a : 100
Before swap, value of b : 200
After swap, value of a : 100
After swap, value of b : 200
```

Now, let's see how to pass parameters by reference. The following program uses call by reference to swap the values of two variables:

```c
#include <stdio.h>
void swap(int *x, int *y);
int main() {
    int a = 100;
    int b = 200;
    printf("Before swap, value of a : %d\n", a);
    printf("Before swap, value of b : %d\n", b);
    /* calling a function to swap the values using variable reference.*/
    swap(&a, &b);
    printf("After swap, value of a : %d\n", a);
    printf("After swap, value of b : %d\n", b);
    return 0;
}
void swap(int *x, int *y) {
    int temp;
    temp = *x; /* save the value at address x */
    *x = *y;   /* put y into x */
    *y = temp; /* put temp into y */
    return;
}
```

When the above code is compiled and executed, it produces the following result:

```bash
Before swap, value of a : 100
Before swap, value of b : 200
After swap, value of a : 200
After swap, value of b : 100
```

When we pass array in C to a function, the function receives the address of the first element of the array. This is because arrays are passed to functions by reference. For example, the following program uses call by reference to swap the values of two arrays:

```c
#include <stdio.h>
void swap(int *x, int *y);
int main() {
    int a[] = {10, 20, 30, 40, 50};
    int b[] = {100, 200, 300, 400, 500};
    int i;
    printf("Before swap, value of a : \n");
    for (i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\nBefore swap, value of b : \n");
    for (i = 0; i < 5; i++) {
        printf("%d ", b[i]);
    }
    /* calling a function to swap the values using variable reference.*/
    swap(a, b);
    printf("\nAfter swap, value of a : \n");
    for (i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\nAfter swap, value of b : \n");
    for (i = 0; i < 5; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}
void swap(int *x, int *y) {
    int temp[5];
    int i;
    for (i = 0; i < 5; i++) {
        temp[i] = x[i];
        x[i] = y[i];
        y[i] = temp[i];
    }
    return;
}
```

When the above code is compiled and executed, it produces the following result:

```bash
Before swap, value of a :
10 20 30 40 50
Before swap, value of b :
100 200 300 400 500
After swap, value of a :
100 200 300 400 500
After swap, value of b :
10 20 30 40 50
```

## Function Prototypes

A function prototype is like a function declaration, except that it does not include the function body. It is used to tell the compiler about the number of arguments a function takes and the types of the arguments. The prototype is required when you define a function above the main() function, or when you call the function before the function definition. For example, the following program uses a function prototype to call the function add() before the function definition:

```c
#include <stdio.h>
int add(int a, int b); /* function prototype */
int main() {
    int a = 10;
    int b = 20;
    int c = add(a, b);
    printf("The sum of a and b is %d\n", c);
    return 0;
}
int add(int a, int b) {
    return a + b;
}
```

When the above code is compiled and executed, it produces the following result:

```bash
The sum of a and b is 30
```

## Default Arguments

C allows you to specify default values for function parameters. If you call a function with fewer arguments than there are parameters, the compiler assigns default values to the missing arguments. For example, the following program uses default arguments to calculate the area of a rectangle:

```c
#include <stdio.h>
int area(int length, int width=10);
int main() {
    int a = area(5);
    int b = area(5, 6);
    printf("Area of rectangle with length 5 and width 10 is %d\n", a);
    printf("Area of rectangle with length 5 and width 6 is %d\n", b);
    return 0;
}
int area(int length, int width) {
    return length * width;
}
```

When the above code is compiled and executed, it produces the following result:

```bash
Area of rectangle with length 5 and width 10 is 50
Area of rectangle with length 5 and width 6 is 30
```

This code will not run in C compiler.
it will give error as

```bash
 error: expected ‘;’, ‘,’ or ‘)’ before ‘=’ toke
```

## Recursion

A recursive function is a function that calls itself. For example, the following program uses recursion to calculate the factorial of a number:

```c
#include <stdio.h>
int factorial(int n);
int main() {
    int n = 5;
    int f = factorial(n);
    printf("Factorial of %d is %d\n", n, f);
    return 0;
}
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
```

When the above code is compiled and executed, it produces the following result:

```bash
Factorial of 5 is 120
```

## Inline Functions

An inline function is a function that is expanded in line when it is called. This means that the compiler replaces the function call with the actual body of the function at the point where the function is called. For example, the following program uses an inline function to calculate the square of a number:

```c
#include <stdio.h>
static inline int square(int x) {
    return x * x;
}
int main() {
    int a = 5;
    int b = square(a);
    printf("The square of %d is %d\n", a, b);
    return 0;
}
```

When the above code is compiled and executed, it produces the following result:

```bash
The square of 5 is 25
```

## Function Overloading

Function overloading is a feature that allows you to have more than one function with the same name, as long as the functions have different parameters. For example, the following program uses function overloading to calculate the area of a rectangle and a circle:

```c
#include <iostream>
float area(float length, float width);
float area(float radius);
int main() {
    float a = area(5.0, 6.0);
    float b = area(5.0);
    cout<<"Area of rectangle with length 5 and width 6 is "<<a<<endl;
    cout<<"Area of circle with radius 5 is "<<b<<endl;

    return 0;
}
float area(float length, float width) {
    return length * width;
}
float area(float radius) {
    return 3.14 * radius * radius;
}
```

When the above code is compiled and executed, it produces the following result:

```bash
Area of rectangle with length 5 and width 6 is 30.000000
Area of circle with radius 5 is 78.500000
```

But this code will not work on C. Because C does not support function overloading. It will give you an error like this:

```bash
error: conflicting types for ‘area’
```

## Function Pointers

A function pointer is a pointer to a function. For example, the following program uses a function pointer to call a function:

```c
#include <stdio.h>
void printMessage(char *message);
int main() {
    void (*p)(char *) = printMessage;
    (*p)("Hello World");
    return 0;
}
void printMessage(char *message) {
    printf("%s\n", message);
}
```

When the above code is compiled and executed, it produces the following result:

```bash
Hello World
```

The syntax for declaring a function pointer is:

```c
return_type (*pointer_name)(parameter list);
```

## Function Templates

Function templates are used to generate functions for different data types. For example, the following program uses a function template to swap two values:

```cpp
#include <iostream>
using namespace std;
template <class T>
void swap(T &x, T &y) {
    T temp;
    temp = x;
    x = y;
    y = temp;
    return;
}
int main() {
    int a = 10;
    int b = 20;
    cout << "Before swap, value of a :" << endl;
    cout << a << endl;
    cout << "Before swap, value of b :" << endl;
    cout << b << endl;
    swap(a, b);
    cout << "After swap, value of a :" << endl;
    cout << a << endl;
    cout << "After swap, value of b :" << endl;
    cout << b << endl;
    return 0;
}
```

When the above code is compiled and executed, it produces the following result:

```bash
Before swap, value of a :
10
Before swap, value of b :
20
After swap, value of a :
20
After swap, value of b :
10
```

## Lambda Expressions

Lambda expressions are used to create anonymous functions. For example, the following program uses a lambda expression to calculate the sum of two numbers:

```cpp
#include <iostream>
using namespace std;
int main() {
    auto sum = [](int x, int y) {
        return x + y;
    };
    cout << sum(5, 6) << endl;
    return 0;
}
```

The return type of the lambda expression is automatically deduced by the compiler. You can also explicitly specify the return type of the lambda expression as follows:

```cpp
auto sum = [](int x, int y) -> int {
    return x + y;
};
```

basic syntax of lambda expression is:

```cpp
[capture list](parameter list) -> return type { function body }
```

here capture list is optional. It is used to capture variables from the enclosing scope. The parameter list and the return type are optional. If the return type is not specified, the compiler automatically deduces the return type. The function body is required.

for example:

```cpp
#include <iostream>
using namespace std;
int main() {
    int x = 5;
    auto f = [x](int y) {
        return x + y;
    };
    cout << f(6) << endl;
    return 0;
}
```

When the above code is compiled and executed, it produces the following result:

```bash
11
```

The importance of lambda expressions is that they can be used to pass functions as arguments to other functions. For example, the following program uses a lambda expression to pass a function as an argument to another function:

```cpp
#include <iostream>
using namespace std;
void callFunction(int x, int y, int (*f)(int, int)) {
    int z = f(x, y);
    cout << z << endl;
}
int main() {
    callFunction(5, 6, [](int x, int y) {
        return x + y;
    });
    return 0;
}
```

When the above code is compiled and executed, it produces the following result:

```bash
11
```
