#include <windows.h>

#define BUFFER_SIZE 256

char buffer[BUFFER_SIZE];

int main(int argc, char *argv[]) {
  DWORD dwReadBytes;

  HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
  HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  
  while (ReadFile(hInput, buffer, BUFFER_SIZE, &dwReadBytes, NULL)) {
    if (dwReadBytes == 0) {
      break;
    }

    DWORD dwWrittenBytes;
    
    WriteFile(hOutput, buffer, dwReadBytes, &dwWrittenBytes, NULL);
  }

  return 0;
}
			      
