#include <stdio.h> 
#include "pico/stdlib.h"

// Definição dos GPIOs dos LEDs e do buzzer
#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13
#define BUZZER_PIN 21

const int LED_VERMELHO_CMD = 1, LED_VERDE_CMD = 2, LED_AZUL_CMD = 3, LED_LIGAR_TODOS_CMD = 4, LED_DESLIGAR_TODOS_CMD = 5, EMITIR_SOM_CMD = 6, MODO_BOOTSEL_CMD = 7;

// Protótipo da função para executar as ações
void acoesDoUsuario(int *input);

// Inicializa os periféricos
void init_peripherals() {
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);

    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    // Desliga todos os LEDs e o buzzer inicialmente
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
    gpio_put(BUZZER_PIN, 0);
}

int main() {
    stdio_init_all();
    init_peripherals();

    while (true) {
        puts("Digite a operação desejada:\n1 - Acender o led vermelho\n2 - Acender o led verde\n3 - Acender o led azul\n4 - Acender todos os leds\n5 - Apagar todos os leds\n6 - Emite um som do buzzer\n7 - Entrar em modo bootsel\r");
        int input = 0;
        if (scanf("%d", &input) != 0) {
            acoesDoUsuario(&input);
        }
    }
}

void acoesDoUsuario(int *input) {
    switch (*input) {
    case LED_VERMELHO_CMD:
        // Liga o LED vermelho
        gpio_put(LED_VERDE, 0);
        gpio_put(LED_AZUL, 0);
        gpio_put(LED_VERMELHO, 1);
        puts("\nON: Vermelho\n");
        break;

    case LED_VERDE_CMD:
        // Liga o LED verde
        gpio_put(LED_VERDE, 1);
        gpio_put(LED_AZUL, 0);
        gpio_put(LED_VERMELHO, 0);
        puts("\nON: Verde\n");
        break;

    case LED_AZUL_CMD:
        // Liga o LED azul
        gpio_put(LED_VERDE, 0);
        gpio_put(LED_AZUL, 1);
        gpio_put(LED_VERMELHO, 0);
        puts("\nON: Azul\n");
        break;

    case LED_LIGAR_TODOS_CMD:
        // Liga todos os LEDs (branco)
        gpio_put(LED_VERDE, 1);
        gpio_put(LED_AZUL, 1);
        gpio_put(LED_VERMELHO, 1);
        puts("\nON: Branco\n");
        break;

    case LED_DESLIGAR_TODOS_CMD:
        // Desliga todos os LEDs
        gpio_put(LED_VERDE, 0);
        gpio_put(LED_AZUL, 0);
        gpio_put(LED_VERMELHO, 0);
        puts("\nSYSTEM: OFF\n");
        break;

    case EMITIR_SOM_CMD:
        // Aciona o buzzer por 2 segundos
        gpio_put(BUZZER_PIN, 1);
        sleep_ms(2000);
        gpio_put(BUZZER_PIN, 0);
        puts("\nON: BUZZER\n");
        break;

    case MODO_BOOTSEL_CMD:
        // Reinicia para modo bootsel
        puts("\nReiniciando para modo bootsel...\n");
        sleep_ms(1000);
        watchdog_reboot(0, 0, 0); // Reinicia o microcontrolador
        break;

    default:
        puts("\nERROR: Por favor, escolha uma das funcionalidades apresentadas acima\n");
        break;
    }
}
