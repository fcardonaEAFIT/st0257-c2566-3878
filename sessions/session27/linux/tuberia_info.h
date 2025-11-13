#ifndef TUBERIA_INFO
#define TUBERIA_INFO
#include <unistd.h>

struct Tuberia_Info {
  pid_t hijo;
  int   escribir;
};

typedef struct Tuberia_Info TUBERIA_INFO;
typedef struct Tuberia_Info *PTUBERIA_INFO;

PTUBERIA_INFO lanzar_catl(void);
#endif
