# Sesion 02

## Ejemplos:

* [`index.c`](./index.c): Ejemplo de como funciona los apuntadores en C.
* [`loop.c`](./loop.c): Un programa que cuando es ejecutado se queda en
  un ciclo (loop) infinito. Este programa en un sistema operativo con
  multiprogramación se toma la máquina.
* [`prueba.c`](./prueba.c): Muestra como se solicita memoria al montículo (heap).

## Compilación

Para compilar:

```shell
$ make -k
```

Una vez termina la compilación, los programas se puede ejecutar así:

```shell
$ ./index # Ejecutar index
$ ./loop  # Ejecutar loop, para terminarlo hay que presiona Ctr-C
$ ./prueba # No muestra salida alguna
```
