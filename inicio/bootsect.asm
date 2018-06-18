; Identical to lesson 13's boot sector, but the %included files have new paths
[org 0x7c00]
KERNEL_OFFSET equ 0x1000 ; el mismo que se usa para vincular el kernel

    mov [BOOT_DRIVE], dl ; el bios es configurado al inicio 
    mov bp, 0x9000
    mov sp, bp

    mov bx, MSG_REAL_MODE 
    call print
    call print_nl

    call load_kernel ; lee el kernel desde el disco
    call switch_to_pm ; desabilita las interrupciones, carga el GDT, etc. Finalmente salta a 'BEGIN_PM'
    jmp $ ; nunca se ejecuta

%include "boot/print.asm"
%include "boot/print_hex.asm"
%include "boot/disk.asm"
%include "boot/gdt.asm"
%include "boot/32bit_print.asm"
%include "boot/switch_pm.asm"

[bits 16]
load_kernel:
    mov bx, MSG_LOAD_KERNEL
    call print
    call print_nl

    mov bx, KERNEL_OFFSET ; Lee desde el disco y guarda en la posicion de memoria 0x1000
    mov dh, 31 ;  el futuro kernel sera mas grandre. Hacerlo mas grande
    mov dl, [BOOT_DRIVE]
    call disk_load

    mov bx, MSG_DISC_OK
    call print
    call print_nl

    ret

[bits 32]
BEGIN_PM:
    mov ebx, MSG_PROT_MODE
    call print_string_pm
    call KERNEL_OFFSET ; dar control a el kernel
    jmp $ ;  estaremos aqui cuando el kernel nos devuelva el control (si es que lo hace)


BOOT_DRIVE db 0 ; una buena idea es almacenar en la memoria porque, 'dl' puede sobreescribirlo
MSG_REAL_MODE db "Comienza en mode real de 16-bits", 0
MSG_PROT_MODE db "Alcanza modo de proteccion en 32-bits", 0
MSG_LOAD_KERNEL db "Cargando el kernel en memoria", 0
MSG_DISC_OK db "Disco cargado", 0
MSG_RETURNED_KERNEL db "Regresa desde el kernel. Error?", 0

; padding
times 510 - ($-$$) db 0
dw 0xaa55
