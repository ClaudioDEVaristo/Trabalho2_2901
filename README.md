# Controle de LEDs com Temporizador de um Disparo (One Shot) e Botão no Raspberry Pi Pico

## Descrição
Este projeto implementa o controle de três LEDs utilizando um temporizador e um botão no Raspberry Pi Pico. O objetivo é garantir a sequência correta de acionamento e desligamento dos LEDs conforme os requisitos estabelecidos.

## Requisitos
1. Ao pressionar o botão (pushbutton), os três LEDs serão ligados (estado alto). Em seguida, a cada 3 segundos, um LED será desligado até que todos estejam apagados.
2. O temporizador do alarme deve ser ajustado para um atraso de 3 segundos (3000ms) entre as mudanças de estado dos LEDs.
3. A alteração de estado dos LEDs deve ser implementada em funções de callback do temporizador, similar à rotina `turn_off_callback()` apresentada em aula.
4. O botão só pode iniciar uma nova sequência quando o último LED for desligado. Durante a execução da temporização, o botão não pode ativar a função callback novamente.
5. Utilizar a Ferramenta Educacional BitDogLab para testar o código com o LED RGB nos GPIOs 11, 12 e 13, e o Botão A no GPIO 05.
6. **Opcional**: Implementar uma rotina de debounce em software para minimizar o efeito bouncing do botão.

- Raspberry Pi Pico
- Três LEDs (vermelho, azul e verde)
- PushButton
- Três resistores (330Ω)
- Ambiente de desenvolvimento configurado para o Pico (SDK do Raspberry Pi) e simulador Wokwi integrado ao VScode

## Conexões dos LEDs

| Cor do LED | Pino do Pico|
|------------|-------------|
| Vermelho   | GPIO 11     |
| Amarelo    | GPIO 12     |
| Verde      | GPIO 13     |
| PushButton | GPIO 5      |




