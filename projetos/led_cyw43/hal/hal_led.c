#include "hal_led.h"
#include "led_embutido.h"
#include "pico/stdlib.h"

static bool estado = false;

void hal_led_init(void) {
    led_embutido_init();
}

void hal_led_toggle(void) {
    if (estado) {
        led_embutido_off();
    } else {
        led_embutido_on();
    }
    estado = !estado;
}
