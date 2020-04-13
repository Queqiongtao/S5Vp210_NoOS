
#define WTCON		0xE2700000

#define SVC_STACK	0xD0037D80

.globl _start

_start:
	//1. close watch dog (reset WTCON bit5)
	ldr r0, =WTCON
	ldr r1, =0x0
	ldr r1, [r0]

	//2. set sp of mode SVC
	ldr sp, =SVC_STACK

	//3. call C function
	bl led_blink

halt:
	b halt



