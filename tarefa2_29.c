// Inclusão de Bibliotecas
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Define os pinos dos LEDs e botão
#define BOTAO 5
#define LED_AZUL 11
#define LED_VERM 12
#define LED_VERD 13

//Declaração de variáveis globais
bool estado_led = false;
static uint contador = 0;

// Inicia os LEDs como saída, o botão como entrada e ativa o resistor de pull up
void setup() {
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_put(LED_AZUL, 0);

    gpio_init(LED_VERM);
    gpio_set_dir(LED_VERM, GPIO_OUT);
    gpio_put(LED_VERM, 0);

    gpio_init(LED_VERD);
    gpio_set_dir(LED_VERD, GPIO_OUT);
    gpio_put(LED_VERD, 0);

    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);
}

//Cria a rotina de callback do alarme
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    
    //contador para lógica do desligamento dos leds
    contador++;

    //Lógica do desligamento após 3 segundos de cada led 
    if (contador == 1) { 
        printf("3 segundos, desliga led azul\n");
        gpio_put(LED_AZUL, 0);
        gpio_put(LED_VERM, 1);
        gpio_put(LED_VERD, 1);
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    } else if (contador == 2) { 
        printf("3 segundos, desliga led vermelho\n");
        gpio_put(LED_AZUL, 0);
        gpio_put(LED_VERM, 0);
        gpio_put(LED_VERD, 1);
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    } else if (contador == 3) { 
        printf("3 segundos, desliga led verde\n");
        gpio_put(LED_AZUL, 0);
        gpio_put(LED_VERM, 0);
        gpio_put(LED_VERD, 0);
        contador = 0; //reinicia o contador ao final do último led
    }
    return 0;
}

// Função principal
int main() {
    stdio_init_all(); // Inicia a comunicação serial
    setup(); // Configura os pinos

    while (true) {
        if (!gpio_get(BOTAO) && !gpio_get(LED_VERD)) { //Verifica o último estado do botão e verifica se o último led já foi apagado
            sleep_ms(50); // Debounce
            if (!gpio_get(BOTAO)) { //verifica o estado do botão
                estado_led = true;
                //inicia todos os leds ligados
                gpio_put(LED_AZUL, 1);
                gpio_put(LED_VERM, 1);
                gpio_put(LED_VERD, 1);
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);//Chama a rotina de callback do alarme 
            }
            sleep_ms(10);//10ms para evitar o travamento no wokwi
        }
        sleep_ms(10);
    }
    sleep_ms(10);
    return 0;
}
