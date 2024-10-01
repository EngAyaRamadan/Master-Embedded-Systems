/* startup.c
Aya ramadan
*/

#include <stdint.h>

void Reset_Handler();
void defualt_handler()
{
	Reset_Handler();
}

void NMI_Handler() __attribute__((weak,alias("defualt_handler")));
void HardFault_Handler() __attribute__((weak,alias("defualt_handler")));
/* bocking 1024 byte by .bss through unintialized array of int 256 element */
 static  unsigned long Stack_top[256];

/* deffenation vectors array that each element is pointr to function 
>>> attribute option to compiler to put this array in (.vector) section 
equal to  section (.vector in startup.s) 
 */

void (*const g_p_fn_vectors[])()__attribute__((section(".vector")))={
	
	( void (*)() ) ((unsigned long )Stack_top + sizeof(Stack_top)),
	 &Reset_Handler, /* address of reset handler function */
     &NMI_Handler,
	 &HardFault_Handler
	
};
extern unsigned int _E_text;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_Handler()
{
	/*copy data section from flash to ram */
	unsigned int DATA_size=(unsigned char* ) &_E_DATA - (unsigned char* ) &_S_DATA;
	unsigned char* P_src=(unsigned char* ) &_E_text;
	unsigned char* P_dst=(unsigned char* ) &_S_DATA;
	int i;
	for( i=0; i<DATA_size;i++)
	{
		*((unsigned char* )P_dst++) = *((unsigned char* )P_src++);
	}
	/* initialize bss in sram */
	unsigned int bss_size=(unsigned char* ) &_E_bss - (unsigned char* ) &_S_bss;
	P_dst=(unsigned char* ) &_S_bss;
	for(i=0; i<bss_size;i++)
	{
		*((unsigned char* )P_dst++) = (unsigned char)0;
	}
	
	/*jump to main */
	main();
}



