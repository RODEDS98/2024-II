.text
.globl __start
__start:
    # Mostrar el mensaje "Ingresar una cadena:"
    la $a0, prm1
    li $v0, 4
    syscall

    # Leer la cadena del usuario
    la $a0, orig          # Dirección donde guardar la cadena
    li $a1, 100           # Máximo tamaño de la cadena
    li $v0, 8             # Llamada de sistema para leer cadena
    syscall

    # Inicializar registros
    la $s0, orig          # Dirección de la cadena
    li $t0, 0             # Contador de la posición en la cadena
    li $t7, 0x61          # ASCII de 'a'
    li $t8, 0x7a          # ASCII de 'z'

# Bucle para recorrer la cadena y convertir letras
loop:
    lb $t1, 0($s0)         # Cargar el byte de la cadena
    beq $t1, $zero, endLoop # Si es un null terminator, fin del bucle

    # Verificar si el carácter está en el rango de letras minúsculas
    slt $t3, $t1, $t7      # $t3 = 1 si $t1 < 'a' (fuera de minúsculas por abajo)
    slt $t4, $t8, $t1      # $t4 = 1 si $t1 > 'z' (fuera de minúsculas por arriba)
    or $t3, $t3, $t4       # Si $t3 es 1, el carácter está fuera del rango de minúsculas
    bne $t3, $zero, skip   # Si el carácter no es una minúscula, saltar

    # Convertir de minúscula a mayúscula
    addi $t1, $t1, -32     # Restar 32 para convertir de minúscula a mayúscula
    sb $t1, 0($s0)         # Guardar el byte convertido

skip:
    addi $s0, $s0, 1       # Avanzar al siguiente carácter
    j loop                 # Repetir el ciclo

# Fin del bucle
endLoop:
    # Imprimir el mensaje "Upcased: "
    la $a0, prm2
    li $v0, 4
    syscall

    # Imprimir la cadena convertida
    la $a0, orig
    li $v0, 4
    syscall

    # Finalizar el programa
    li $v0, 10
    syscall

# SECCIÓN DE DATOS
.data
orig: .space 100              # Espacio reservado para la cadena ingresada por el usuario
prm1: .asciiz "Ingresar una cadena: "  # Mensaje para solicitar cadena
prm2: .asciiz "\nUpcased: "            # Mensaje para la cadena convertida
