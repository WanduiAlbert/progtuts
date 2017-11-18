#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  char * filename = "basic.cpp";
  int fd = open(filename, O_RDONLY);

  printf("fd = %d\n", fd);
  size_t buflen = 30;
  char buffer[buflen];

  while(read(fd, buffer, buflen) != 0)
    write(STDOUT_FILENO, buffer, buflen);

  return 0;
}

