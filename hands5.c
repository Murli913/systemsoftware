#include<stdio.h>
#include<fcntl.h>
#include<stdbool.h>

void main() {
  int a = 0;
  FILE* file1;
  while (true) {
    if(a<5) {
      char buffer[32];
      snprintf(buffer, sizeof(char) * 32, "file1%i.txt", a);
      file1 = fopen(buffer, "wb");
      fclose(file1);
      a++;
    }
  }
}
