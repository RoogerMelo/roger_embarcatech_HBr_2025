#include <stdio.h>
#include "pico/stdlib.h"
#include "hal_temp.h"

int main() {
    stdio_init_all();

    while (true) {
        float temp = hal_temp_get_celsius();
        printf("Temperatura: %.2f C\n", temp);
        sleep_ms(1000);
    }
}