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
