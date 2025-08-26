#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include "handleerror.h"

#define BUFFER_SIZE 256

int
main(int argc,
     char *argv[]) {
  
  if (argc != 3) {
    return 1;
  }

  int fdsrc = open(argv[1], O_RDONLY);

  handle_error(fdsrc, argv[1]);
			   
  int fddst = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);

  handle_error(fddst, argv[2]);
			   
  char buffer[BUFFER_SIZE + 1];
  ssize_t nc;
  
  while ((nc = read(fdsrc, buffer, BUFFER_SIZE)) > 0) {
    buffer[nc] = '\0';
    write(fddst, buffer, nc);
  }

  if (nc < 0) {
    fprintf(stderr, "Problems reading file: %d\n", errno);
    return 1;
  }

  close(fdsrc);
  close(fddst);

  return 0;

}
	   
