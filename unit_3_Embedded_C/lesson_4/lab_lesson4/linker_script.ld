/* linker_script_cortexm3.ld
Eng.Aya Ramadan
*/


MEMORY
{
 Flash(RX):ORIGIN = 0x00000000 , LENGTH = 512M
 SRAM(RWX):ORIGIN = 0x20000000 , LENGTH = 512M

}

SECTIONS
{
   .text :{
            *(.vector*)
			*(.text)
			*(.rodata)
			_E_text = .;
    }> Flash
	
	.data :{
	 _S_DATA = .;
	   *(.data)
	   . = ALIGN(4);
	 _E_DATA = .;  
    }> SRAM AT> Flash

    .bss :{
	  	 _S_bss = .;
	       *(.bss)
		 _E_bss = .; 
    }> SRAM



}