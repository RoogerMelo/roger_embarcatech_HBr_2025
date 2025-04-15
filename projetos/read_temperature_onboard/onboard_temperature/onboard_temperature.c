#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/clocks.h"

float converter(uint16_t leitura_adc) {
    const float conversao = 3.3f / (1 << 12);  // 12 bits -> 4096 níveis
    float voltagem = leitura_adc * conversao; // em volts
    float temperatura = 27.0f - (voltagem - 0.706f) / 0.001721f;
    return temperatura;
}

int main() {
    stdio_init_all();

    // Inicializa o ADC e ativa o sensor de temperatura
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4); // Canal 4 = sensor interno

    printf("Leitura da Temperatura Interna (RP2040)\n");

    while (true) {
        uint16_t leitura = adc_read();
        float temp_c = converter(leitura);

        printf("Temperatura: %.2f °C\n", temp_c);
        sleep_ms(1000); // Atualiza a cada 1 segundo
    }

    return 0;
}
