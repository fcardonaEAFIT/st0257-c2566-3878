
int a = 10;
int b = 20;

f(int a) {
  int x =a;
  printf("%d\n", x);
}

main() {
  int *p = malloc(sizeof(int) * 17);
  f(3);
  f(4);
  free(p);
}
