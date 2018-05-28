# ========================================
# 	Archivos
# ========================================

C_SOURCES = $(wildcard kernel/*.c drivers/*.c cpu/*.c libc/*.c)
CPP_SOURCES = $(wildcard kernel/*.cpp drivers/*.cpp cpu/*.cpp oslib/*.cpp)
HEADERS = $(wildcard kernel/*.h drivers/*.h cpu/*.h libc/*.h)

OBJ = ${C_SOURCES:.c=.o cpu/interrupt.o} 
OBJ_CPP = ${CPP_SOURCES:.cpp=.o} 

# ========================================
# 	Herramientas / comandos
# ========================================
CC = g++
#CC = i386-elf-g++
#CC = i386-elf-c++
#CC = i686-elf-g++
GDB = gdb
LD = i386-elf-ld
#LD = i686-elf-ld
CAT = type
RM = del /S /F

# ========================================
# 	Parámetros
# ========================================

# C/C++
# -ffreestanding: indica que se está compilando el kernel y no un programa en userspace.
# -fno-builtin: desactiva algunas optimizaciones.
# -nostdlib: desactiva librerías estándar.
# -nostdinc: desactiva headers de librería estándar. Esto permite incluir una custom.
# -fno-leading-underscore: desactiva los _ en funciones exportadas.
# -Wno(...): desactiva warnings.

# Solo C++
# -fno-rtti: desactiva dynamic_cast y type_id.
# -nostdinc++: desactiva headers de librería estándar (C++).

WARNING_FLAGS = -Wall -Wextra
INCLUDES = -Iinclude -Iinclude-os
CPP_FLAGS = -m32 -nostdlib -fno-builtin -fno-rtti -fno-use-cxa-atexit -fno-exceptions -fno-leading-underscore -Wno-write-strings -ffreestanding
C_FLAGS = -m32 -nostdlib -fno-builtin -fno-rtti -fno-use-cxa-atexit -fno-exceptions -fno-leading-underscore -Wno-write-strings -ffreestanding
LD_FLAGS = -melf_i386 --oformat binary

# ========================================
# 	Proceso de compilación y comandos
# ========================================

os-image.bin: boot/bootsect.bin kernel.bin
	copy /b /y boot\bootsect.bin+kernel.bin os-image.bin

kernel.bin: boot/kernel_entry.o ${OBJ} ${OBJ_CPP}
	${LD} $(LD_FLAGS) -o $@ -Ttext 0x1000 $^

kernel.elf: boot/kernel_entry.o ${OBJ} ${OBJ_CPP}
	${LD} -o $@ -Ttext 0x1000 $^ 

run: os-image.bin
	qemu-system-i386 -fda os-image.bin

debug: os-image.bin kernel.elf
	qemu-system-i386 -s -fda os-image.bin -d guest_errors,int &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

%.o: %.c ${HEADERS}
	${CC} ${INCLUDES} ${C_FLAGS} -c $< -o $@

%.o: %.cpp ${HEADERS}
	${CC} ${INCLUDES} ${CPP_FLAGS} -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	${RM} *.bin *.dis *.o os-image.bin *.elf
	${RM} kernel/*.o boot/*.bin drivers/*.o boot/*.o cpu/*.o libc/*.o
