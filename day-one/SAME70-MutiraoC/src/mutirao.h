/*
 * mutirao.h
 *
 * Created: 31/01/2018 19:29:44
 *  Author: Embarcados
 */ 


#ifndef MUTIRAO_H_
#define MUTIRAO_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * LEDs
 */
#define LED_PIO_ID		ID_PIOC
#define LED_PIO       PIOC
#define LED_PIN		    8
#define LED_PIN_MASK  (1<<LED_PIN)

/**
 * Botão
 */
#define BUT_PIO_ID      ID_PIOA
#define BUT_PIO         PIOA
#define BUT_PIN		    11
#define BUT_PIN_MASK    (1 << BUT_PIN)
#define BUT_DEBOUNCING_VALUE  79


/**
 * timer
 */

#define TICK_US	   0.031f // us per tic


//extern volatile uint8_t imageSelect;
extern volatile uint8_t buttonFlag;

/* Ticks in 1ms */
extern volatile uint32_t gs_ul_ms_ticks;

typedef uint8_t ili9488_color_t;

void initBoardMutirao();
void imgShow(ili9488_color_t image[320][320], uint32_t time);
uint32_t tic(void);
uint32_t toc(uint32_t t0);

#endif /* MUTIRAO_H_ */