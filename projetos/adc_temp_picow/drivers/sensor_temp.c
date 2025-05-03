#include "sensor_temp.h"

// Exemplo: retorna valor simulado para 0.706V
uint16_t sensor_temp_read_adc(void) {
    float v = 0.706f;
    float vref = 3.3f;
    return (uint16_t)((v / vref) * 4095);
}
