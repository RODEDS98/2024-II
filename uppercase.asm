## Uppercase.asm
# SECCION DE INSTRUCCIONES (.text)
.text
.globl __start
__start:

    # Imprimir el mensaje para solicitar la cadena de texto
    la $a0, prompt           # Cargar la dirección del mensaje "prompt"
    li $v0, 4                # Llamada al sistema para imprimir string
    syscall

    # Leer la cadena de texto del usuario
    li $v0, 8                # Llamada al sistema para leer cadena
    la $a0, buffer           # Cargar la dirección del buffer donde almacenar la cadena
    li $a1, 80               # Leer hasta 80 caracteres
    syscall

    # Convertir cada letra a mayúscula
    la $t0, buffer           # Cargar la dirección del buffer en $t0

convertir:
    lb $t1, 0($t0)           # Cargar el carácter actual
    beq $t1, $zero, fin      # Si es el byte nulo (fin de cadena), termina

    # Verificar si es una letra minúscula ('a' = 97, 'z' = 122)
    li $t2, 97               # Cargar el valor ASCII de 'a'
    li $t3, 122              # Cargar el valor ASCII de 'z'
    blt $t1, $t2, siguiente  # Si es menor que 'a', saltar
    bgt $t1, $t3, siguiente  # Si es mayor que 'z', saltar

    # Convertir a mayúscula restando 32 al valor ASCII
    li $t4, 32
    sub $t1, $t1, $t4

    # Guardar el carácter convertido en el buffer
    sb $t1, 0($t0)

siguiente:
    addi $t0, $t0, 1         # Mover al siguiente carácter
    j convertir              # Repetir para el siguiente carácter

fin:
    # Imprimir el mensaje de resultado
    la $a0, result           # Cargar la dirección del mensaje "result"
    li $v0, 4                # Llamada al sistema para imprimir string
    syscall

    # Imprimir la cadena convertida a mayúsculas
    la $a0, buffer           # Cargar la dirección del buffer con el texto convertido
    li $v0, 4                # Llamada al sistema para imprimir string
    syscall

    # Salir del programa
    li $v0, 10               # Llamada al sistema para salir
    syscall

# SECCION DE VARIABLES EN MEMORIA (.data)
.data
prompt:    .asciiz "Ingrese una cadena de texto: "
result:    .asciiz "\nEl texto en mayúsculas es: "
buffer:    .space 80         # Reservar 80 bytes para almacenar la cadena
endl:      .asciiz "\n
