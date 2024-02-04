
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"

void TWI_init(void)
{
    	TWBR = 0x02;
	TWSR = 0x00;
    	TWAR = 0b00000010;//master address
    	TWCR = (1<<TWCR_TWEN); /* enable TWI */
}

void TWI_start(void)
{
    TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWSTA) | (1 << TWCR_TWEN);
    while(BIT_IS_CLEAR(TWCR,TWCR_TWINT));
}

void TWI_stop(void)
{
    TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWSTO) | (1 << TWCR_TWEN);
}


void TWI_writeByte(u8 data)
{
    TWDR = data;
    TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEN);
    while(BIT_IS_CLEAR(TWCR,TWCR_TWINT));
}

u8 TWI_readByteWithACK(void)
{
    TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEN) | (1 << TWCR_TWEA);
    while(BIT_IS_CLEAR(TWCR,TWCR_TWINT));
    return TWDR;
}

u8 TWI_readByteWithNACK(void)
{
    TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEN);
    while(BIT_IS_CLEAR(TWCR,TWCR_TWINT));
    return TWDR;
}

u8 TWI_getStatus(void)
{
    u8 status;
    status = TWSR & 0xF8;
    return status;
}
