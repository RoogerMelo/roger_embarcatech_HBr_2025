#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/i2c.h"
#include "inc/ssd1306.h"

#define SDA_PIN 14
#define SCL_PIN 15

#define VRX 26         // GPIO ADC0
#define VRY 27         // GPIO ADC1
#define ADC_CH_X 0
#define ADC_CH_Y 1

#define BOTAO_JS 22    // Pino do botão do joystick

struct render_area area_display = {
    .start_column = 0,
    .end_column = ssd1306_width - 1,
    .start_page = 0,
    .end_page = ssd1306_n_pages - 1
};

uint8_t buffer[ssd1306_buffer_length];

void atualizar_display(uint16_t x, uint16_t y, bool botao) {
    char texto[32];
    ssd1306_clear(buffer);

    sprintf(texto, "X: %d", x);
    ssd1306_draw_string(buffer, 0, 0, texto);

    sprintf(texto, "Y: %d", y);
    ssd1306_draw_string(buffer, 0, 12, texto);

    sprintf(texto, "Botao: %s", botao ? "ON" : "OFF");
    ssd1306_draw_string(buffer, 0, 24, texto);

    render_on_display(buffer, &area_display);
}

void configurar_display() {
    i2c_init(i2c1, ssd1306_i2c_clock * 1000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);
    ssd1306_init();
    calculate_render_area_buffer_length(&area_display);
    render_on_display(buffer, &area_display);
}

void configurar_joystick() {
    adc_init();
    adc_gpio_init(VRX);
    adc_gpio_init(VRY);
    gpio_init(BOTAO_JS);
    gpio_set_dir(BOTAO_JS, GPIO_IN);
    gpio_pull_up(BOTAO_JS);
}

int main() {
    stdio_init_all();
    configurar_display();
    configurar_joystick();

    uint16_t x = 0, y = 0;

    while (true) {
        adc_select_input(ADC_CH_X);
        sleep_us(2);
        x = adc_read();

        adc_select_input(ADC_CH_Y);
        sleep_us(2);
        y = adc_read();

        bool botao_pressionado = gpio_get(BOTAO_JS) == 0;

        atualizar_display(x, y, botao_pressionado);
        sleep_ms(300);
    }
}
