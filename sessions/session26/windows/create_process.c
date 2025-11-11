#include <windows.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

char buffer[BUFFER_SIZE];
void fill_buffer(char *buffer, unsigned int size);

int main(int argc, char* argv[], char * env[]) {
  STARTUPINFO startup_info;
  PROCESS_INFORMATION pi_process_info;

  GetStartupInfo(&startup_info);
  HANDLE hReadPipe;
  HANDLE hWritePipe;
  SECURITY_ATTRIBUTES pipeSecurity;

  pipeSecurity.nLength = sizeof(pipeSecurity);
  pipeSecurity.lpSecurityDescriptor = NULL;
  pipeSecurity.bInheritHandle = TRUE;
  
  if (!CreatePipe(&hReadPipe,
		  &hWritePipe,
		  &pipeSecurity,
		  0)) {
    fprintf(stderr, "Error: Creating Pipe\n");
    ExitProcess(1);
  }

  startup_info.hStdInput = hReadPipe;

  if (CreateProcessA(NULL,
		     "./catw.exe",
		     NULL,
		     NULL,
		     TRUE,
		     0,
		     NULL,
		     NULL,
		     &startup_info,
		     &pi_process_info)) {

    for (int j = 0; j < 10; j++) {
      fill_buffer(buffer, BUFFER_SIZE);
      DWORD dwWrittenBytes;
      WriteFile(hWritePipe, buffer, BUFFER_SIZE, &dwWrittenBytes, NULL);
    }

    CloseHandle(hWritePipe);
    CloseHandle(hReadPipe);
    
  }
  else {
    fprintf(stderr, "catw.exe cannot be executed\n");
    ExitProcess(1);
  }

  ExitProcess(0);
}

void fill_buffer(char *buffer, unsigned int size) {
  char c = 'A';
  for (unsigned int i = 0; i < size; i++) {
    buffer[i] = c;
    c++;
    if (c > 'z') {
      c = 'A';
    }
  }
}
