//Realizar o include do dispostivo em questão.
#include "stm32f0xx_hal.h"

void lcd_init (void); //Inicializa o LCD;

void lcd_send_cmd (char cmd); //Envia comando para o LDC;

void lcd_send_data (char data); //Envia dados para LCD;

void lcd_send_string (char *str);  //Envia String para LCD;

void lcd_put_cur(int row, int col); //Posiciona cursor na posição desejada;

void lcd_clear (void); //Limpa LCD;
