/* linker_script_cortexm3.ld
Eng.Aya Ramadan
*/


MEMORY
{
 Flash(RX):ORIGIN = 0x08000000 , LENGTH = 128K
 SRAM(RWX):ORIGIN = 0x20000000 , LENGTH = 20K

}

SECTIONS
{
   .text :{
            *(.vector*)
			*(.text*)
			*(.rodata)
    }> Flash
	
	 .data :{
	         *(.data)
            
    }> Flash

      .bss :{
	         *(.bss)
            
    }> SRAM



}