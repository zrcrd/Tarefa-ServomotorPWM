#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define LED_PIN 13    // GPIO do LED vermelho
#define SERVO_PIN 22  // GPIO do servomotor

// Inicializa o PWM para um pino específico
void configurar_pwm(uint pino) {
    gpio_set_function(pino, GPIO_FUNC_PWM);
    uint canal = pwm_gpio_to_slice_num(pino);
    pwm_set_clkdiv(canal, 80);
    pwm_set_wrap(canal, 31250);
    pwm_set_enabled(canal, true);
}

// Define o ângulo do servomotor através do sinal PWM
void definir_angulo(uint pino, float largura_pulso) {
    uint nivel = (largura_pulso / 20000.0) * 31250;
    pwm_set_gpio_level(pino, nivel);
}

// Movimenta o servo suavemente entre dois ângulos
void movimento_suave(uint pino, float inicio, float fim) {
    float incremento = 5.0;
    float tempo_espera = 10.0;
    uint nivel;

    for (float i = inicio; i <= fim; i += incremento) {
        nivel = (i / 20000.0) * 31250;
        pwm_set_gpio_level(pino, nivel);
        sleep_ms(tempo_espera);
    }
    for (float i = fim; i >= inicio; i -= incremento) {
        nivel = (i / 20000.0) * 31250;
        pwm_set_gpio_level(pino, nivel);
        sleep_ms(tempo_espera);
    }
}

int main() {
    stdio_init_all();
    configurar_pwm(SERVO_PIN);
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Define posições iniciais do servo e LED
    definir_angulo(SERVO_PIN, 2400);
    gpio_put(LED_PIN, 0);
    printf("Posição: 180 graus\n");
    sleep_ms(5000);

    definir_angulo(SERVO_PIN, 1470);
    gpio_put(LED_PIN, 1);
    printf("Posição: 90 graus\n");
    sleep_ms(5000);

    definir_angulo(SERVO_PIN, 500);
    gpio_put(LED_PIN, 0);
    printf("Posição: 0 graus\n");
    sleep_ms(5000);

    printf("Iniciando movimento oscilatório\n");

    // Loop contínuo alternando entre os extremos
    while (true) {
        gpio_put(LED_PIN, 0);
        movimento_suave(SERVO_PIN, 500, 2400);
        gpio_put(LED_PIN, 1);
        sleep_ms(1000);
    }
}
