# Ejemplo de Problema Productor-Consumidor en C con Semáforos

Este repositorio contiene una implementación básica del problema del productor-consumidor en lenguaje C, utilizando semáforos y mutex para la sincronización entre los hilos productor y consumidor. Este código ha sido desarrollado con fines educativos y muestra cómo los semáforos y mutex pueden ser utilizados para coordinar el acceso a un buffer compartido en un entorno multihilo.

## Uso

Este código se proporciona únicamente con fines educativos y de aprendizaje. No se recomienda su uso en un entorno de producción sin una revisión y adaptación adecuada. Antes de utilizarlo, comprenda las implicaciones de la concurrencia y la sincronización en la programación multihilo.

### Requisitos previos

Asegúrese de tener un entorno de desarrollo C configurado y las siguientes bibliotecas instaladas:

- [stdio.h](https://en.cppreference.com/w/c/header)
- [stdlib.h](https://en.cppreference.com/w/c/header)
- [pthread.h](https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread.h.html)
- [semaphore.h](https://pubs.opengroup.org/onlinepubs/7908799/xsh/semaphore.h.html)
- [unistd.h](https://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html)

### Ejecución

1. Clone el repositorio en su máquina local.

```shell
git clone https://github.com/your-username/productor-consumidor.git
cd productor-consumidor
```
2. Compile y ejecute el programa.
```shell
gcc main.c -o main -pthread
./main
```
Al ejecutar el programa, debería ver una serie de mensajes en la consola que indican los elementos producidos y consumidos, así como las posiciones en el buffer en las que se produjeron y consumieron estos elementos.

### Explicación

El código crea dos hilos: un productor y un consumidor. El productor genera elementos y los coloca en un buffer compartido, mientras que el consumidor retira elementos del buffer y los procesa. Se utilizan semáforos y mutex para garantizar que el productor no agregue elementos a un buffer lleno y que el consumidor no retire elementos de un buffer vacío, proporcionando así una sincronización adecuada entre los hilos.
