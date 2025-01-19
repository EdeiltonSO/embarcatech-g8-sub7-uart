#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/watchdog.h"
#include "pico/bootrom.h" // Biblioteca necessária para reset_usb_boot
#include <string.h>

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
void reset_peripherals();

int main() {
    stdio_init_all(); // Inicializa a comunicação serial
    init_peripherals(); // Configura os pinos GPIO dos LEDs e do buzzer

    while (true) {
        puts("Digite a operação desejada:\n"
             "1 - Acender o LED vermelho\n"
             "2 - Acender o LED verde\n"
             "3 - Acender o LED azul\n"
             "4 - Acender todos os LEDs\n"
             "5 - Apagar todos os LEDs\n"
             "6 - Emitir um som do buzzer\n"
             "7 - Entrar em modo BOOTSEL\n");
        int input = 0;
        if (scanf("%d", &input) == 1) {
            actions(&input); // Executa a ação correspondente
        } else {
            puts("\nERRO: Entrada inválida. Por favor, insira um número válido.\n");
        }
    }
}

// Inicializa os pinos GPIO dos LEDs e do buzzer
void init_peripherals() {
    gpio_init(GPIO_LED_VERDE);
    gpio_set_dir(GPIO_LED_VERDE, GPIO_OUT);

    gpio_init(GPIO_LED_AZUL);
    gpio_set_dir(GPIO_LED_AZUL, GPIO_OUT);

    gpio_init(GPIO_LED_VERMELHO);
    gpio_set_dir(GPIO_LED_VERMELHO, GPIO_OUT);

    gpio_init(GPIO_BUZZER);
    gpio_set_dir(GPIO_BUZZER, GPIO_OUT);

    reset_peripherals(); // Garante que todos os periféricos começam desligados
}

// Reseta os periféricos (desliga todos os LEDs e o buzzer)
void reset_peripherals() {
    gpio_put(GPIO_LED_VERDE, 0);
    gpio_put(GPIO_LED_AZUL, 0);
    gpio_put(GPIO_LED_VERMELHO, 0);
    gpio_put(GPIO_BUZZER, 0);
    sleep_ms(100); // Aguardando estado estável antes do próximo comando
}

// Executa a ação correspondente ao comando do usuário
void actions(int *input) {
    switch (*input) {
    case LED_VERMELHO_CMD:
        reset_peripherals(); // Desliga outros LEDs
        gpio_put(GPIO_LED_VERMELHO, 1); // Liga o LED vermelho
        puts("\nLED vermelho ligado\n");
        break;

    case LED_VERDE_CMD:
        reset_peripherals(); // Desliga outros LEDs
        gpio_put(GPIO_LED_VERDE, 1); // Liga o LED verde
        puts("\nLED verde ligado\n");
        break;

    case LED_AZUL_CMD:
        reset_peripherals(); // Desliga outros LEDs
        gpio_put(GPIO_LED_AZUL, 1); // Liga o LED azul
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
        reset_peripherals(); // Desliga todos os LEDs
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
        // Desativa todos os periféricos antes de reiniciar
        reset_peripherals();
        puts("\nTodos os periféricos desativados. Entrando em modo BOOTSEL...\n");
        
        // Reinicia no modo BOOTSEL
        sleep_ms(500); // Aguarda estado estável antes do reset
        reset_usb_boot(0, 0); // Reinicia diretamente no modo BOOTSEL
        break;

    default:
        puts("\nERRO: Por favor, escolha uma das funcionalidades apresentadas acima\n");
        break;
    }
}
