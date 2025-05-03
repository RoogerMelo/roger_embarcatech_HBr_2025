#include "unity.h"
#include "hal_temp.h"

void setUp(void) {}
void tearDown(void) {}

void test_adc_to_celsius_simulado(void) {
    uint16_t adc_simulado = (uint16_t)((0.706f / 3.3f) * 4095.0f);
    float temp = adc_to_celsius(adc_simulado);
    TEST_ASSERT_FLOAT_WITHIN(0.5f, 27.0f, temp);
}