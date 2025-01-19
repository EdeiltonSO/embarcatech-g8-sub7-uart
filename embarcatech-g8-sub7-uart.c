#include <stdio.h> 
#include "pico/stdlib.h"

// Diretivas para pinos GPIO dos LEDs e do buzzer
#define GPIO_LED_VERDE 11
#define GPIO_LED_AZUL 12
#define GPIO_LED_VERMELHO 13
#define GPIO_BUZZER 21

// Constantes para a entrada do usuário
const int LED_VERMELHO_CMD = 1, 
          LED_VERDE_CMD = 2, 
          LED_AZUL_CMD = 3,
          LED_LIGAR_TODOS_CMD = 4,
          LED_DESLIGAR_TODOS_CMD = 5,
          BUZZER_CMD = 6,
          MODO_BOOTSEL_CMD = 7;

// Protótipos das funções
void actions(int *input);
void init_peripherals();

int main() {
    stdio_init_all();
    init_peripherals();

    while (true) {
        puts("Digite a operação desejada:\n1 - Acender o LED vermelho\n2 - Acender o LED verde\n3 - Acender o LED azul\n4 - Acender todos os LEDs\n5 - Apagar todos os LEDs\n6 - Emite um som do buzzer\n7 - Entrar em modo BOOTSEL\r");
        int input = 0;
        if (scanf("%d", &input) != 0) {
            actions(&input);
        }
    }
}

// Inicializa (e seta pra off) pinos dos LEDs e do buzzer
void init_peripherals() {
    gpio_init(GPIO_LED_VERDE);
    gpio_set_dir(GPIO_LED_VERDE, GPIO_OUT);

    gpio_init(GPIO_LED_AZUL);
    gpio_set_dir(GPIO_LED_AZUL, GPIO_OUT);

    gpio_init(GPIO_LED_VERMELHO);
    gpio_set_dir(GPIO_LED_VERMELHO, GPIO_OUT);

    gpio_init(GPIO_BUZZER);
    gpio_set_dir(GPIO_BUZZER, GPIO_OUT);

    gpio_put(GPIO_LED_VERDE, 0);
    gpio_put(GPIO_LED_AZUL, 0);
    gpio_put(GPIO_LED_VERMELHO, 0);
    gpio_put(GPIO_BUZZER, 0);
}

void actions(int *input) {
    switch (*input) {
    case LED_VERMELHO_CMD:
        // Liga o LED vermelho e desliga os demais
        gpio_put(GPIO_LED_VERDE, 0);
        gpio_put(GPIO_LED_AZUL, 0);
        gpio_put(GPIO_LED_VERMELHO, 1);
        puts("\nLED vermelho ligado\n");
        break;

    case LED_VERDE_CMD:
        // Liga o LED verde e desliga os demais
        gpio_put(GPIO_LED_VERDE, 1);
        gpio_put(GPIO_LED_AZUL, 0);
        gpio_put(GPIO_LED_VERMELHO, 0);
        puts("\nLED verde ligado\n");
        break;

    case LED_AZUL_CMD:
        // Liga o LED azul e desliga os demais
        gpio_put(GPIO_LED_VERDE, 0);
        gpio_put(GPIO_LED_AZUL, 1);
        gpio_put(GPIO_LED_VERMELHO, 0);
        puts("\nLED azul ligado\n");
        break;

    case LED_LIGAR_TODOS_CMD:
        // Liga todos os LEDs
        gpio_put(GPIO_LED_VERDE, 1);
        gpio_put(GPIO_LED_AZUL, 1);
        gpio_put(GPIO_LED_VERMELHO, 1);
        puts("\nTodos os LEDs ligados\n");
        break;

    case LED_DESLIGAR_TODOS_CMD:
        // Desliga todos os LEDs
        gpio_put(GPIO_LED_VERDE, 0);
        gpio_put(GPIO_LED_AZUL, 0);
        gpio_put(GPIO_LED_VERMELHO, 0);
        puts("\nTodos os LEDs desligados\n");
        break;

    case BUZZER_CMD:
        // Aciona o buzzer por 2 segundos
        gpio_put(GPIO_BUZZER, 1);
        sleep_ms(2000);
        gpio_put(GPIO_BUZZER, 0);
        puts("\nBuzzer ligado\n");
        break;

    case MODO_BOOTSEL_CMD:
        // Reinicia em modo BOOTSEL
        puts("\nReiniciando em modo BOOTSEL em 1 segundo\n");
        sleep_ms(1000);
        watchdog_reboot(0, 0, 0); // Reinicia o microcontrolador
        break;

    default:
        puts("\nERRO: Por favor, escolha uma das funcionalidades apresentadas acima\n");
        break;
    }
}