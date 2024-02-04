
#ifndef TWI_H_
#define TWI_H_

#include "STD_TYPES.h"

#define TWI_START         0x08 
#define TWI_REP_START     0x10 
#define TWI_MT_SLA_W_ACK  0x18 
#define TWI_MT_SLA_R_ACK  0x40 
#define TWI_MT_DATA_ACK   0x28 
#define TWI_MR_DATA_ACK   0x50 
#define TWI_MR_DATA_NACK  0x58

void TWI_init(void);
void TWI_start(void);
void TWI_stop(void);
void TWI_writeByte(u8 data);
u8 TWI_readByteWithACK(void);
u8 TWI_readByteWithNACK(void);
u8 TWI_getStatus(void);


#endif /* TWI_H_ */
