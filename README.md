# TP3-SO
 Sockets

### Instalacion

Asegurarse previamente antes de poder ejecutar el programa tener instalado minisat. Para instalarlo:
    
         gcc make

### Compilacion

Para poder compilar los archivos utilizar el comando:
        
        user@linux:$ make

### Ejecucion:

Correr el ejecutable server

        user@linux:$ ./server

A continuación correr el ejecutable cliente en otra terminal

        user@linux:$ ./client

De esta manera ya está establecida la conexion entre el cliente y el servidor y puede intentar resolver los desafíos

### Analisis estatico con pvs-studio y cppcheck

Para realizar los checkeos con pvs-studio y cppcheck, primero debe instalarlos con los comandos:

        apt-get install pvs-studio
        apt-get install cppcheck

A continuacion puede realizar los chequeos con el comando:

        make check

Podra ver el analisis de cpp check y de pvs-studio en los archivos out.cppOut y report.tasks respectivamente.

Para eliminar dichos archivos una vez leidos utilice el comando:

        make cleanCheck 