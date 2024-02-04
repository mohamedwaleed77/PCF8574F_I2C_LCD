
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LCDI2C_Interface.h"



int main (void)
{
	LCD_init();
	while(1)
	{
		LCD_clearScreen();
		LCD_displayString(" HELLO WORLD");
		_delay_ms(1000);

	}
}
