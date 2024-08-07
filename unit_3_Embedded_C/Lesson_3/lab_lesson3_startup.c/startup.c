/* startup.c
Aya ramadan
*/

#include <stdint.h>


void defualt_handler()
{
	Reset_Handler();
}
void Reset_Handler()
{
	main();
}
void NMI_Handler() __attribute__((weak,alias("defualt_handler")));
void HardFault_Handler() __attribute__((weak,alias("defualt_handler")));
void MemManage_Handler() __attribute__((weak,alias("defualt_handler")));
void BusFault_Handler() __attribute__((weak,alias("defualt_handler")));
void UsageFault_Handler() __attribute__((weak,alias("defualt_handler")));

/* diffination vectors array that each element is address 
>>> attribute option to compiler to put this array in (.vector) section 
equal to  section (.vector in startup.s) 
 */
uint32_t  vectors[] __attribute__((section(".vector")))={
	
	(uint32_t)0x20001000,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &HardFault_Handler,
	(uint32_t) &MemManage_Handler,
	(uint32_t) &BusFault_Handler,
	(uint32_t) &UsageFault_Handler
	
};




