CC = arm-none-eabi-gcc
MARC = -mcpu=cortex-m4
CFLAGS = -c  -std=gnu11  -mthumb  $(MARC) 
LFLAGS = -nostdlib -T linker.ld -Wl,-Map=final.map 
all: main.o startup.o
link: final.elf
main.o: main.c
	$(CC)  $(CFLAGS) -o $@  $^
startup.o: startup.c	
	$(CC)  $(CFLAGS) -o $@  $^
final.elf: main.o startup.o
	$(CC)  $(LFLAGS) -o $@  $^	

	
clean: 
	rm -rf *.elf *.o *.map
		
		
	
