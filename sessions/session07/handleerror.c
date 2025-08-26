#include <unistd.h>
#include <errno.h>
#include <stdio.h>

void
handle_error(int fd, char* path) {
  if (fd < 0) {
    fprintf(stderr, "File %s has problems: %d\n", path, errno);
    _exit(1);
  }
}
