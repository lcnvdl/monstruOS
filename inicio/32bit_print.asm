[bits 32] ; usa mode de proteccion en 32-bits

; estas son constantes definidas
VIDEO_MEMORIA equ 0xb8000
WHITE_OB_BLACK equ 0x0f ; indica en byte, el color de cada carecter

print_string_pm:
    pusha
    mov edx, VIDEO_MEMORY

print_string_pm_loop:
    mov al, [ebx] ; [ebx] esta es la direccion del caracter 
    mov ah, WHITE_OB_BLACK

    cmp al, 0 ; verifica si es el final del string
    je print_string_pm_done

    mov [edx], ax ; almacena el caracter mas el atributo en la memoria de video
    add ebx, 1 ; siguiente caracter
    add edx, 2 ; siguiente posicion de memoria de video

    jmp print_string_pm_loop

print_string_pm_done:
    popa
    ret
