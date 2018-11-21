// Changelog: 23/8/2016: Changed comparison operator from "<=" to "<" in constructor initialization loop
// This initialization module does a number of things
// 1: Initializes global/static variables appropriately
// 2: Zeros un-initialized global/static variables
// 3: Calls all global/static constructors
// 4: Sets clock speed to 80MHz
// 5: Turns on floating point unit
// 6: Provides dummy implementation of some C++
// system functions
// 7: Provides a dummy malloc function

#include "tilm4f120hqr.h"
#include <stddef.h>
void init(void);
void Default_Handler(void);
typedef void (*fptr)(void);
// The following are 'declared' in the linker script
extern unsigned char  INIT_DATA_VALUES;
extern unsigned char  INIT_DATA_START;
extern unsigned char  INIT_DATA_END;
extern unsigned char  BSS_START;
extern unsigned char  BSS_END;
extern fptr  __ctors_start__;
extern fptr  __ctors_end__;
extern void isr_uart(void);
int main(void);
// the section "vectors" is placed at the beginning of flash 
// by the linker script
const fptr Vectors[] __attribute__((section(".vectors"))) ={
	(fptr)0x20008000, 	/* Top of stack */ 
	init,   				/* Reset Handler */
        Default_Handler,	/* NMI */
	Default_Handler,		/* Hard Fault */
	0,	                	/* Reserved */
	0,                   	/* Reserved */
	0,                  	/* Reserved */
	0,                   	/* Reserved */
	0,                   	/* Reserved */
	0,                   	/* Reserved */
	0,                   	/* Reserved */
	Default_Handler,   		/* SVC */
	0,                   	/* Reserved */
	0,                   	/* Reserved */
	Default_Handler,   		/* PendSV */
	Default_Handler,   		/* SysTick */		
/* External interrupt handlers follow */
	Default_Handler, 	/* IRQ	0	*/
	Default_Handler, 	/* IRQ	1	*/
	Default_Handler, 	/* IRQ	2	*/
	Default_Handler, 	/* IRQ	3	*/
	Default_Handler, 	/* IRQ	4	*/
	isr_uart, 			/* IRQ	5	UART0 */
	Default_Handler, 	/* IRQ	6	*/
	Default_Handler, 	/* IRQ	7	*/
	Default_Handler, 	/* IRQ	8	*/
	Default_Handler, 	/* IRQ	9	*/
	Default_Handler, 	/* IRQ	10	*/
	Default_Handler, 	/* IRQ	11	*/
	Default_Handler, 	/* IRQ	12	*/
	Default_Handler, 	/* IRQ	13	*/
	Default_Handler, 	/* IRQ	14	*/
	Default_Handler, 	/* IRQ	15	*/
	Default_Handler, 	/* IRQ	16	*/
	Default_Handler, 	/* IRQ	17	*/
	Default_Handler, 	/* IRQ	18	*/
	Default_Handler, 	/* IRQ	19	*/
	Default_Handler, 	/* IRQ	20	*/
	Default_Handler, 	/* IRQ	21	*/
	Default_Handler, 	/* IRQ	22	*/
	Default_Handler, 	/* IRQ	23	*/
	Default_Handler, 	/* IRQ	24	*/
	Default_Handler, 	/* IRQ	25	*/
	Default_Handler, 	/* IRQ	26	*/
	Default_Handler, 	/* IRQ	27	*/
	Default_Handler, 	/* IRQ	28	*/
	Default_Handler, 	/* IRQ	29	*/
	Default_Handler, 	/* IRQ	30	*/
	Default_Handler, 	/* IRQ	31	*/
	Default_Handler, 	/* IRQ	32	*/
	Default_Handler, 	/* IRQ	33	*/
	Default_Handler, 	/* IRQ	34	*/
	Default_Handler, 	/* IRQ	35	*/
	Default_Handler, 	/* IRQ	36	*/
	Default_Handler, 	/* IRQ	37	*/
	Default_Handler, 	/* IRQ	38	*/
	Default_Handler, 	/* IRQ	39	*/
	Default_Handler, 	/* IRQ	40	*/
	Default_Handler, 	/* IRQ	41	*/
	Default_Handler, 	/* IRQ	42	*/
	Default_Handler, 	/* IRQ	43	*/
	Default_Handler, 	/* IRQ	44	*/
	Default_Handler, 	/* IRQ	45	*/
	Default_Handler, 	/* IRQ	46	*/
	Default_Handler, 	/* IRQ	47	*/
	Default_Handler, 	/* IRQ	48	*/
	Default_Handler, 	/* IRQ	49	*/
	Default_Handler, 	/* IRQ	50	*/
	Default_Handler, 	/* IRQ	51	*/
	Default_Handler, 	/* IRQ	52	*/
	Default_Handler, 	/* IRQ	53	*/
	Default_Handler, 	/* IRQ	54	*/
	Default_Handler, 	/* IRQ	55	*/
	Default_Handler, 	/* IRQ	56	*/
	Default_Handler, 	/* IRQ	57	*/
	Default_Handler, 	/* IRQ	58	*/
	Default_Handler, 	/* IRQ	59	*/
	Default_Handler, 	/* IRQ	60	*/
	Default_Handler, 	/* IRQ	61	*/
	Default_Handler, 	/* IRQ	62	*/
	Default_Handler, 	/* IRQ	63	*/
	Default_Handler, 	/* IRQ	64	*/
	Default_Handler, 	/* IRQ	65	*/
	Default_Handler, 	/* IRQ	66	*/
	Default_Handler, 	/* IRQ	67	*/
	Default_Handler, 	/* IRQ	68	*/
	Default_Handler, 	/* IRQ	69	*/
	Default_Handler, 	/* IRQ	70	*/
	Default_Handler, 	/* IRQ	71	*/
	Default_Handler, 	/* IRQ	72	*/
	Default_Handler, 	/* IRQ	73	*/
	Default_Handler, 	/* IRQ	74	*/
	Default_Handler, 	/* IRQ	75	*/
	Default_Handler, 	/* IRQ	76	*/
	Default_Handler, 	/* IRQ	77	*/
	Default_Handler, 	/* IRQ	78	*/
	Default_Handler, 	/* IRQ	79	*/
	Default_Handler, 	/* IRQ	80	*/
	Default_Handler, 	/* IRQ	81	*/
	Default_Handler, 	/* IRQ	82	*/
	Default_Handler, 	/* IRQ	83	*/
	Default_Handler, 	/* IRQ	84	*/
	Default_Handler, 	/* IRQ	85	*/
	Default_Handler, 	/* IRQ	86	*/
	Default_Handler, 	/* IRQ	87	*/
	Default_Handler, 	/* IRQ	88	*/
	Default_Handler, 	/* IRQ	89	*/
	Default_Handler, 	/* IRQ	90	*/
	Default_Handler, 	/* IRQ	91	*/
	Default_Handler, 	/* IRQ	92	*/
	Default_Handler, 	/* IRQ	93	*/
	Default_Handler, 	/* IRQ	94	*/
	Default_Handler, 	/* IRQ	95	*/
	Default_Handler, 	/* IRQ	96	*/
	Default_Handler, 	/* IRQ	97	*/
	Default_Handler, 	/* IRQ	98	*/
	Default_Handler, 	/* IRQ	99	*/
	Default_Handler, 	/* IRQ	100	*/
	Default_Handler, 	/* IRQ	101	*/
	Default_Handler, 	/* IRQ	102	*/
	Default_Handler, 	/* IRQ	103	*/
	Default_Handler, 	/* IRQ	104	*/
	Default_Handler, 	/* IRQ	105	*/
	Default_Handler, 	/* IRQ	106	*/
	Default_Handler, 	/* IRQ	107	*/
	Default_Handler, 	/* IRQ	108	*/
	Default_Handler, 	/* IRQ	109	*/
	Default_Handler, 	/* IRQ	110	*/
	Default_Handler, 	/* IRQ	111	*/
	Default_Handler, 	/* IRQ	112	*/
	Default_Handler, 	/* IRQ	113	*/
	Default_Handler, 	/* IRQ	114	*/
	Default_Handler, 	/* IRQ	115	*/
	Default_Handler, 	/* IRQ	116	*/
	Default_Handler, 	/* IRQ	117	*/
	Default_Handler, 	/* IRQ	118	*/
	Default_Handler, 	/* IRQ	119	*/
	Default_Handler, 	/* IRQ	120	*/
	Default_Handler, 	/* IRQ	121	*/
	Default_Handler, 	/* IRQ	122	*/
	Default_Handler, 	/* IRQ	123	*/
	Default_Handler, 	/* IRQ	124	*/
	Default_Handler, 	/* IRQ	125	*/
	Default_Handler, 	/* IRQ	126	*/
	Default_Handler, 	/* IRQ	127	*/
	Default_Handler, 	/* IRQ	128	*/
	Default_Handler, 	/* IRQ	129	*/
	Default_Handler, 	/* IRQ	130	*/
	Default_Handler 	/* IRQ	131	*/

};
void initFPU()
{
	// turn on FPU by setting bits 20 to 21 in CPACR
	SYS_CPAC |= BIT20 | BIT21 | BIT22 | BIT23;	
	asm(" DSB ");
	asm(" ISB ");
	
}
void initSysClock()
{
	/*
The PLL is configured using direct register writes to the RCC/RCC2 register. If the RCC2 register
is being used, the USERCC2 bit must be set and the appropriate RCC2 bit/field is used. The steps
required to successfully change the PLL-based system clock are:
1. Bypass the PLL and system clock divider by setting the BYPASS bit and clearing the USESYS
bit in the RCC register, thereby configuring the microcontroller to run off a "raw" clock source
and allowing for the new PLL configuration to be validated before switching the system clock
to the PLL.
2. Select the crystal value (XTAL) and oscillator source (OSCSRC), and clear the PWRDN bit in
RCC/RCC2. Setting the XTAL field automatically pulls valid PLL configuration data for the
appropriate crystal, and clearing the PWRDN bit powers and enables the PLL and its output.
3. Select the desired system divider (SYSDIV) in RCC/RCC2 and set the USESYS bit in RCC. The
SYSDIV field determines the system frequency for the microcontroller.
4. Wait for the PLL to lock by polling the PLLLRIS bit in the Raw Interrupt Status (RIS) register.
5. Enable use of the PLL by clearing the BYPASS bit in RCC/RCC2.
*/

	CLEAR_BIT(SYSCTL_RCC2,BIT13); // clear the power down bit
	SET_BIT(SYSCTL_RCC2,BIT31);   	// set the USERCC2 bit
	SET_BIT(SYSCTL_RCC2,BIT30);    // Append the SYSDIV2LSB bit to the SYSDIV2 field to create a 7 bit divisor
// DIVISOR SETUP  SYSDIV2 = 2, SYSDIV2LSB = 0
	CLEAR_BIT(SYSCTL_RCC2,(BIT28+BIT27+BIT26+BIT25+BIT23));
	SET_BIT(SYSCTL_RCC2,BIT24);
	CLEAR_BIT(SYSCTL_RCC2,BIT22);
// Wait for PLL to stabilize by polling the LOCK bit in PLLSTAT
	while((PLLSTAT & BIT0)!=0);

// Finally, when all has settled, clear the BYPASS bit connecting the system clock to the PLL
	CLEAR_BIT(SYSCTL_RCC2,BIT11);
}
void init()
{
// do global/static data initialization
	unsigned char *src;
	unsigned char *dest;
	unsigned len;
	initFPU();
	initSysClock();
	src= &INIT_DATA_VALUES;
	dest= &INIT_DATA_START;
	len= &INIT_DATA_END-&INIT_DATA_START;
	while (len--)
		*dest++ = *src++;
// zero out the uninitialized global/static variables
	dest = &BSS_START;
	len = &BSS_END - &BSS_START;
	while (len--)
		*dest++=0;
// Need to call on the constructors of any global/static C++ objects
	fptr  *ConstructorsStart;
	ConstructorsStart = &__ctors_start__;
	if (*ConstructorsStart != (fptr )-1)
	{
		while (ConstructorsStart < &__ctors_end__)
		{
			(*ConstructorsStart)();
			ConstructorsStart++;
		}
	}
	main();
}

void Default_Handler(void)
{
	while(1);
}
// The following functions are necessary or the linker will complain
// These functions should not normally be called.
extern "C" 
void __aeabi_unwind_cpp_pr0(void)
{
}
extern "C" 
void __aeabi_unwind_cpp_pr1(void)
{
}
extern "C" 
void __aeabi_unwind_cpp_pr2(void)
{
}
extern "C" 
void __gxx_personality_v0(void)
{
}
extern "C" 
void __cxa_end_cleanup(void)
{
}
// Reference for below:
// http://www.embedded.com/design/mcus-processors-and-socs/4007134/Building-Bare-Metal-ARM-Systems-with-GNU-Part-4
extern "C" void *malloc(size_t)
{
	return (void *)0;
}
extern "C" void free(void *)
{

}
void *operator new (size_t size) throw()
{
	return malloc(size);
}
void operator delete(void *p) throw()
{
	free(p);
}
extern "C" int __aeabi_atexit(void *object, void (*destructor)(void *), void *dso_handle)
{
	return 0;
}
