#include <stdio.h>
#include "funciones.h"

f() {
  load("f.o", funcion);
  funcion();
}

g() {
  load("g.o", funcion);
  funcion();
}

h() {
  load("h.o", funcion);
  funcion();
}

int
main() {
  f();
  g();
  h();
  return 0;
}

funcion:
