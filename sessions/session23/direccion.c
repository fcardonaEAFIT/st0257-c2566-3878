#include <stdio.h>

void
imprimir(unsigned int npag,
	 unsigned int desp);

int
main(int argc, char *argv) {
  unsigned int direccion = 0x49176189;
  unsigned int m = 32;
  unsigned int n = 9;
  unsigned int diff = m - n;

  unsigned int desp = (direccion << diff) >> diff;
  unsigned int npag = (direccion >> n);

  imprimir(npag, desp);

  desp = direccion % 512;
  npag = direccion / 512;

  imprimir(npag, desp);

  unsigned int ALL_ONES = ~((unsigned int) 0);
  unsigned int MASCARA_NROPAGINA = (ALL_ONES >> n) << n;
  unsigned int MASCARA_DESP = ~MASCARA_NROPAGINA;

  desp = direccion & MASCARA_DESP;
  npag = (direccion & MASCARA_NROPAGINA) >> n;

  imprimir(npag, desp);

  return 0;
}

void
imprimir(unsigned int npag,
	 unsigned int desp) {
  
  printf("nro pagina: 0x%X desplazamiento: 0%X\n", npag, desp);
}
