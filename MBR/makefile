.PHONY : all build clear

BUILD_PATH = ./Builds/
OBJ = $(BUILD_PATH)kernel.obj
IMG = $(BUILD_PATH)system.img

compiler_path = /usr/local/i386elfgcc/bin/
gcc = i386-elf-gcc
ld = i386-elf-ld

all: clear build output.img

build:
	make -C Bootsect
	cp Bootsect/bootsect.img ./Builds/bootsect.img
	make -C Kernel
	cp ./Kernel/*.obj ./Builds/

clear:
	rm -rf $(OBJ)
	rm -rf output.img

./Builds/system.img:
	$(compiler_path)$(ld) $(OBJ) -m elf_i386 --oformat binary -e kernel_main -Ttext-seg=0x9000 -o $@

output.img: ./Builds/Bootsect.img ./Builds/system.img
	cat $^ > $@
