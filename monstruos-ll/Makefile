C_SOURCES = $(wildcard kernel/*.c drivers/*.c cpu/*.c libc/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h cpu/*.h libc/*.h)
# Nice syntax for file extension replacement
OBJ = ${C_SOURCES:.c=.o cpu/interrupt.o} 

# Change this if your cross-compiler is somewhere else
#CC = /usr/local/i386elfgcc/bin/i386-elf-gcc
CC = g++
GDB = gdb
LD = i386-elf-ld
CAT = type
RM = del /S /F
#RM = rm -rf
# LD = i386-elf-ld
#GDB = /usr/local/i386elfgcc/bin/i386-elf-gdb
# -g: Use debugging symbols in gcc
#CFLAGS = -g -ffreestanding -Wall -Wextra -fno-exceptions -m32 -Iinclude -Dfix_asm_fns
CFLAGS = -m32 -Iinclude -Iinclude-os -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
#CFLAGS = -g -ffreestanding -nostdlib -lgcc -nodefaultlibs

#CFLAGS = -Xlinker -zmuldefs

# First rule is run by default
#os-image.bin: boot/bootsect.bin kernel.bin
#	${CAT} $^ > os-image.bin

os-image.bin: boot/bootsect.bin kernel.bin
	copy /b /y boot\bootsect.bin+kernel.bin os-image.bin

# '--oformat binary' deletes all symbols as a collateral, so we don't need
# to 'strip' them manually on this case
kernel.bin: boot/kernel_entry.o ${OBJ}
	${LD} -o $@ -Ttext 0x1000 $^ --oformat binary

# Used for debugging purposes
kernel.elf: boot/kernel_entry.o ${OBJ}
	${LD} -o $@ -Ttext 0x1000 $^ 

run: os-image.bin
	qemu-system-i386 -fda os-image.bin
	
run2: os-image.bin
	qemu-system-i386 -drive format=raw,file=os-image.bin

# Open the connection to qemu and load our kernel-object file with symbols
debug: os-image.bin kernel.elf
	qemu-system-i386 -s -fda os-image.bin -d guest_errors,int &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

# Generic rules for wildcards
# To make an object, always compile from its .c
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	${RM} *.bin *.dis *.o os-image.bin *.elf
	${RM} kernel/*.o boot/*.bin drivers/*.o boot/*.o cpu/*.o libc/*.o
