/* startup_cortexm3.s
Eng.Aya Ramadan
*/

/*SRAM 0x20000000*/

/* vector_table interrupt */
.section .vectors

.word 0x20001000  /*intialize stack_pointer top*/
.word _reset      /* reset */
.word Vector_handler    /* NMI */
.word Vector_handler    /* HardFault */
.word Vector_handler    /* MemManage */
.word Vector_handler    /* BusFault  */
.word Vector_handler    /* UsageFault*/
.word Vector_handler    /* Reserved */
.word Vector_handler    /* SVCall   */
.word Vector_handler    /* Debug Mointor */
.word Vector_handler    /* Reserved */
.word Vector_handler    /* PendSV */
.word Vector_handler    /* SysTick */
.word Vector_handler    /* WWDG */
.word Vector_handler    /* PVD */
.word Vector_handler    /* TAMPER*/
.word Vector_handler    /* RTC */
.word Vector_handler    /* FLASH */
.word Vector_handler    /* RCC */
.word Vector_handler    /* EXTi0 */
.word Vector_handler    /* EXTi1 */
.word Vector_handler    /* EXTi2 */

.section .text
_reset:
     bl main
     b .
/* to enable 16 bit instraction */
.thump_func :

Vector_handler:
    b _reset