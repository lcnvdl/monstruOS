cd ..\monstruos
copy /Y makefiles\Makefile.windows Makefile
cls
@%comspec% /K "path %PROGRAMFILES%\NASM;%PROGRAMFILES%\qemu;%USERPROFILE%\.monstruos\tools\i386-elf-gcc\bin;%USERPROFILE%\.monstruos\tools\i386-elf-binutils\bin;%PATH% && cls && @echo MONSTRUOS BUILD ENVIRONMENT"