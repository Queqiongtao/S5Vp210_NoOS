#define GPJ0CON			0xE0200240
#define GPJ0DAT			0xE0200244


static void delay(void);

void led_blink(void)
{
	*(unsigned int*)(GPJ0CON) = 0x11111111;
	unsigned int * p_led = (unsigned int*)(GPJ0DAT);
 
	while(1)
	{
		// turn on led
		*p_led = (0 << 3) | (0 << 4) | (0 << 5);
		delay();

		// turn off led
		*p_led = (1 << 3) | (1 << 4) | (1 << 5);
		delay();

	}

}

static void delay(void)
{
	unsigned int i = 2000000;
	while(i--);

}



