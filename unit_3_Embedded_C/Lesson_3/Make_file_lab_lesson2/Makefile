#@copyright : Keroles

#tool chain name
CC=arm-none-eabi-
# cpu name and debuge option
CFLAGS=-g -mcpu=arm926ej-s
#to include folders location 
INCS=-I .
#library i need to link
LEBS=
#any dot c store in source
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)

Project_name=learn-in-depth

all: $(Project_name).bin 
	@echo "----------Build is Done----------"
	
startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@
%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -c $(INCS)  $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe  -T linker_script.ld $(LEBS) $(OBJ) $(AsOBJ) -o $@

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe  -O binary $<  $@

clean_all:
	rm *.o *.elf *.bin
	
clean:
	rm *.elf *.bin