#ifndef HAL_TEMP_H
#define HAL_TEMP_H

#include <stdint.h>

float adc_to_celsius(uint16_t adc_val);
float hal_temp_get_celsius(void);

#endif