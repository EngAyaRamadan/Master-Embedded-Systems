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
void MemManage_Handler() __attribute__((weak,alias("defualt_handler")));
void BusFault_Handler() __attribute__((weak,alias("defualt_handler")));
void UsageFault_Handler() __attribute__((weak,alias("defualt_handler")));

extern unsigned int _stack_top;
/* deffnation vectors array that each element is address 
>>> attribute option to compiler to put this array in (.vector) section 
equal to  section (.vector in startup.s) 
 */
uint32_t  vectors[] __attribute__((section(".vector")))={
	
	(uint32_t) 0x20001000,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &HardFault_Handler,
	(uint32_t) &MemManage_Handler,
	(uint32_t) &BusFault_Handler,
	(uint32_t) &UsageFault_Handler
	
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



