.PHONY : all clear

all: clear $(bin) bootsect.img

clear:
	rm -rf bootsect.img

boot.bin: boot.asm
	nasm -fbin $< -o $@

bootsect.img: boot.bin
	cat boot.bin > bootsect.img
