#include <stdio.h>
#include "pico/stdlib.h"

const int LED_VERMELHO = 1, LED_VERDE = 2, LED_AZUL = 3, LED_LIGAR_TODOS = 4, LED_DESLIGAR_TODOS = 5, EMITIR_SOM = 6, MODO_BOOTSEL = 7;

void acoesDoUsuario(int *input);

int main()
{
    stdio_init_all();

    while(true){
        puts("Digite a operação desejada:\n1 - Acender o led vermelho\n2 - Acender o led verde\n3 - Acender o led azul\n4 - Acender todos os leds\n5 - Apagar todos os leds\n6 - Emite um som do buzzer\n7 - Entrar em modo bootsel\r");
        int input = 0;
        if(scanf("%d",&input) != 0){
            acoesDoUsuario(&input);
        }
    }
}

void acoesDoUsuario(int *input)
{

    switch (*input)
    {
    case LED_VERMELHO:
        // Função responsável por ligar o led vermelho
        puts("\nON: Vermelho\n");
        break;

    case LED_VERDE:
        // Função responsável por ligar o led verde
        puts("\nON: Verde\n");
        break;

    case LED_AZUL:
        // Função responsável por ligar o led azul
        puts("\nON: Azul\n");
        break;

    case LED_LIGAR_TODOS:
        // Função responsável por ligar TODOS os leds
        puts("\nON: Branco\n");
        break;

    case LED_DESLIGAR_TODOS:
        // Função responsável por desligar TODOS os leds
        puts("\nSYSTEM: OFF\n");
        break;

    case EMITIR_SOM:
        // Função responsável por emitir um som do buzzer
        puts("\nON: BUZZER\n");
        break;

    case MODO_BOOTSEL:
        // Função responsável por fazer a placa entrar em modo bootsel
        puts("\nModo bootsel\n");
        break;
    default:
        puts("\nERROR: Por favor, escolha uma das funcionalidades apresentadas acima\n");
    break;
    }
}
