# function_pointers
Learning function pointers

# What is a function pointer in C?
- It's just a variable that stores a memory address.
- char * is just a variable that stores a memory address of type char.
- int (*fp)(int,int) is just a variable that stores a memory address of type function returning type x with x number of parameters of type x
- The name of the variable is "*fp" and it's a pointer just like for example char "*fp" but this is storing a memory address of type function.
- So we need to declare the variable of type function and to do that you have to use the syntax of "(*fp)" instead of "char *fp" or "int *fp".
- We also have to include the return type at the start like this "int (*fp)" meaning this function variable or function pointer returns an int.
- This makes sense since when a function returns for example "return 0" well 0 is an int. Now what if the function that you're storing in "*fp" 
- contains parameters. Then if function x is being stored in "*fp" and function x has two parameters like "int x(int y, int z)" then "*fp" would
- be like a copy and paste but without the variable names being defined like this: "int (*fp)(int,int) = &x; // we just store the **memory** addr"
- To use the function stored inside of "*fp* we just do this: fp(5,10);
- Hope this helps understand function pointers

# Install
This code is just for learning purposes and contains a buffer overflow vulnerablity. Can you fix it?
```
git clone https://github.com/mr-n30/function_pointers.git
cd function_pointers
make
./a.out "John Wick"
```

# Code below
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calc(int x, int y) {
  return x*y;
}

void *greeting_message(char*, char[32]);

typedef struct {
  int legs;
  int eyes;
  char *name;
} animal;

int main(int argc, char *argv[]) {
  int (*fp)(int,int) = &calc;
  printf("%d\n", fp(5,5));

  animal dog;
  dog.name = argv[1];

  char buf[32];
  char *message = (char *) greeting_message(dog.name, buf);

  printf("%s\n", message);

  return 0;
}

// This function is vulnerable to a buffer overflow
// Use malloc instead and strncat to length check the
// user input. Don't forget to "free"!
void *greeting_message(char *name, char buf[32]) {
  int len = strlen(name);
  strcat(buf, "Hello, ");
  strcat(buf, name);
  strcat(buf, "! yoooooo");

  return buf;
}
```
