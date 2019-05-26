.PHONY : all clear

obj = kernel.obj

compiler_path = /usr/local/i386elfgcc/bin/
gcc_flag = -ffreestanding -c
gcc = i386-elf-gcc
ld = i386-elf-ld

all: clear $(obj)

clear:
	rm -rf $(obj)

kernel.obj: kernel.c
	$(compiler_path)$(gcc) $(gcc_flag) $< -o $@
