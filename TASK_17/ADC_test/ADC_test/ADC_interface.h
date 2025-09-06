/*
 * ADC_interface.h
 *
 * Created: 8/17/2025 1:58:30 AM
 *  Author: pc
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_CHANNEL_0       0
#define ADC_CHANNEL_1       1
#define ADC_CHANNEL_2       2
#define ADC_CHANNEL_3       3
#define ADC_CHANNEL_4       4
#define ADC_CHANNEL_5       5
#define ADC_CHANNEL_6       6
#define ADC_CHANNEL_7       7






void ADC_init(void);
void ADC_getDigitalValue(u8 channelNum, u16* digitalValue);



#endif /* ADC_INTERFACE_H_ */