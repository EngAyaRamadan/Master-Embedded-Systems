#@copyright : Keroles
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LEBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
Project_name=unit3_lab4_cortex-m4

all: $(Project_name).bin 
	@echo "----------Build is Done----------"
	

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) -mthumb $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe  -T linker_script.ld $(LEBS) $(OBJ) $(AsOBJ) -o $@  -Map=Map_file.map
    

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe  -O binary $<  $@

clean_all:
	rm *.o *.elf *.bin *.map
	
clean:
	rm *.elf *.bin