#include <stdio.h>

int
main(int argc, char *argv) {
  unsigned int direccion = 0x49176189;
  unsigned int m = 32;
  unsigned int n = 9;
  unsigned int diff = m -n;

  unsigned int desp = (direccion << diff) >> diff;
  unsigned int npag = (direccion >> n) ;

  printf("nro pagina: %x desplazamiento: %x\n", npag, desp);

  desp = direccion % 512;
  npag = direccion / 512;

  printf("nro pagina: %x desplazamiento: %x\n", npag, desp);

  unsigned int ALL_ONES = ~((unsigned int) 0);
  unsigned int MASCARA_NROPAGINA = (ALL_ONES >> n) << n;
  unsigned int MASCARA_DESP = ~MASCARA_NROPAGINA;

  desp = direccion & MASCARA_DESP;
  npag = (direccion & MASCARA_NROPAGINA) >> n;

  printf("nro pagina: %x desplazamiento: %x\n", npag, desp);

  return 0;
}
