#include <unistd.h>

#define BUFFER_SIZE 256

char buffer[BUFFER_SIZE];

int main(int argc, char *argv[]) {
  size_t read_bytes;

  while ((read_bytes = read(0, buffer, BUFFER_SIZE)) > 0) {
    
    write(1, buffer, read_bytes);
  }

  return 0;
}
			      
