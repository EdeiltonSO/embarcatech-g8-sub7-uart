# Controlando LEDs e buzzer via comunicação serial com o RP2040

Software escrito em C para controlar pinos GPIO do RP2040 na placa de desenvolvimento Raspberry Pi Pico W por meio de comunicação serial UART.

# Controle de LEDs e Buzzer - Raspberry Pi Pico

Este projeto foi desenvolvido para controlar LEDs e um buzzer utilizando o microcontrolador **Raspberry Pi Pico**. Através de comandos inseridos via terminal, o usuário pode acionar diferentes funcionalidades, como ligar e desligar LEDs e emitir sons com o buzzer.

## Funcionalidades

O programa oferece as seguintes funcionalidades, que podem ser acionadas pelo usuário:

1. **Acender o LED vermelho**
2. **Acender o LED verde**
3. **Acender o LED azul**
4. **Acender todos os LEDs**
5. **Desligar todos os LEDs**
6. **Emitir um som do buzzer**
7. **Entrar em modo BOOTSEL (reiniciar o Raspberry Pi Pico em modo de boot)**

## Requisitos

- **Raspberry Pi Pico** (ou qualquer placa baseada no RP2040)
- LEDs e resistores
- Buzzer
- Conexões adequadas para os pinos GPIO

## Pinos GPIO

Os pinos utilizados para o controle dos LEDs e do buzzer são:

- **LED verde**: GPIO 11
- **LED azul**: GPIO 12
- **LED vermelho**: GPIO 13
- **Buzzer**: GPIO 21

## Como Usar

### 1. Configuração do ambiente

Antes de começar, certifique-se de que você tenha o ambiente de desenvolvimento para o Raspberry Pi Pico configurado corretamente. Se não tiver, siga as instruções oficiais de configuração do [Raspberry Pi Pico](https://www.raspberrypi.org/documentation/microcontrollers/).

### 2. Conectar os componentes

Conecte os LEDs e o buzzer nos pinos GPIO conforme especificado anteriormente. Certifique-se de utilizar resistores adequados para os LEDs.

### 3. Compilação e upload do código

- Compile o código usando o compilador C/C++ (por exemplo, **gcc**);
- Carregue o arquivo `.uf2` no Raspberry Pi Pico em modo de boot, ou use o **Visual Studio Code** com a extensão para **Raspberry Pi Pico** para fazer o upload diretamente.

### 4. Interação com o programa

1. Conecte o Raspberry Pi Pico ao computador e abra um terminal;
2. Execute o programa;
3. No terminal, o programa irá pedir para o usuário inserir um número correspondente à operação desejada;
4. Insira um número entre 1 e 7 para acionar a funcionalidade correspondente;
5. O status dos LEDs e do buzzer será exibido no terminal.

### Exemplo de uso no terminal:

```bash
Digite a operação desejada:
1 - Acender o LED vermelho
2 - Acender o LED verde
3 - Acender o LED azul
4 - Acender todos os LEDs
5 - Apagar todos os LEDs
6 - Emite um som do buzzer
7 - Entrar em modo BOOTSEL

Digite o número da operação: 1
LED vermelho ligado
```
## Link do vídeo demonstrando o funcionamento:

Uma demonstração do funcionamento do projeto pode ser assistida no link abaixo:

https://drive.google.com/file/d/1_UH9SrjVV45fOKt4rFVr0kRUAEUjBnP1/view

## Colaboradores do projeto

Participantes do projeto por ordem alfabética e atividades desenvolvidas:

### Líder

#### Edeilton da Silva de Oliveira
- Responsável pelas revisões de pull requests e resolução de conflitos de branch

### Desenvolvedores

#### Cibelle Sousa Rodrigues
- Responsável pelo desenvolvimento do diagrama do circuito

#### Edemir de Carvalho Rodrigues
- Responsável pelas chamadas dos submenus e gravação do vídeo demonstrativo

#### Gustavo Oliveira Alves
- Responsável pela documentação do projeto

#### Joabis Oliveira dos Santos Júnior
- Responsável pelos testes de funcionamento

#### Rogério Silva Palafoz Júnior
- Responsável pelas configurações iniciais do projeto e menu de ações
