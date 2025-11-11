#include <windows.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

char buffer[BUFFER_SIZE];

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

  if (CreateProcessA(NULL, "./catw.exe", NULL, NULL,
		     TRUE, 0, NULL, NULL, &startup_info, &pi_process_info)) {

    char c = 'A';
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < BUFFER_SIZE; k++) {
	buffer[k] = c;
	c = (c + 1) % ('z' - 'A');
      }
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
			      
