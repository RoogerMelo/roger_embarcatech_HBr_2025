#include "hal_temp.h"
#include "sensor_temp.h"

float adc_to_celsius(uint16_t adc_val) {
    const float Vref = 3.3f;
    const float adc_resolution = 4095.0f;
    float voltage = (adc_val * Vref) / adc_resolution;
    return 27.0f - (voltage - 0.706f) / 0.001721f;
}

float hal_temp_get_celsius(void) {
    return adc_to_celsius(sensor_temp_read_adc());
}