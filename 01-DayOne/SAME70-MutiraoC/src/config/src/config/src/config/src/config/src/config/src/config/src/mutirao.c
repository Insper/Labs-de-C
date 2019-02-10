/*
 * mutirao.c
 *
 * Created: 31/01/2018 19:29:58
 *  Author: Embarcados
 */ 

#include "mutirao.h"

#include "asf.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ioport.h"

// From module: SDRAMC configuration for IS42S16100E
#include <is42s16100e.h>


/************************************************************************/
/* Handlers                                                              */
/************************************************************************/

/**
 *  Handle Interrupcao botao 1
 */
static void Button1_Handler(uint32_t id, uint32_t mask)
{
	buttonFlag = 1;
	//pin_toggle(LED_PIO, LED_PIN_MASK);
}


/************************************************************************/
/* funcs                                                                 */
/************************************************************************/

uint32_t tic(void)
{
    printf("%d \n" , rtt_read_timer_value(RTT));
    return (rtt_read_timer_value(RTT));
}

uint32_t toc(uint32_t t0)
{
  uint32_t tick, time;
  tick = rtt_read_timer_value(RTT);
  time = (int) (1000*((float) (tick - t0)) / 32768.0); //validado! resultado em ms
  return(time);
}

// contagem com TC, tem o problema que estoura
void TCtic(void)
{
	tc_start(TC0, 1);
} 

// contagem com TC, tem o problema que estoura
uint32_t TCtoc(void)
{
	uint32_t tick, time;
	tick = tc_read_cv(TC0, 1);
	tc_stop(TC0, 1);

	time = (int) (1000*((float) tick) * TICK_US);	
	return(time);
}                 
                   
				   
/**
 * Configura TimerCounter (TC0) para tick de 10us (0.1MHz)
 */
void TC1_init(uint32_t freq){   
    uint32_t ul_div;
    uint32_t ul_tcclks = 1;
    uint32_t ul_sysclk = sysclk_get_cpu_hz();
	  uint32_t ul_perclk = sysclk_get_peripheral_hz();
        
    /* Configura o PMC */
    pmc_enable_periph_clk(ID_TC1);    
	  tc_init(TC0, 1, TC_CMR_TCCLKS_TIMER_CLOCK5);
}	                              

/**
 * \brief RTT configuration function.
 *
 * Configure the RTT to generate a one second tick, which triggers the RTTINC
 * interrupt.
 */
static void RTT_init(void)
{
	uint32_t ul_previous_time;

	/* Configure RTT for a 1 second tick interrupt */
  pmc_enable_periph_clk(ID_RTT);
	rtt_sel_source(RTT, false);
	rtt_init(RTT, 1);
}

/**
 * \brief Configure UART console.
 */
static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = {
		.baudrate =		CONF_UART_BAUDRATE,
		.charlength =	CONF_UART_CHAR_LENGTH,
		.paritytype =	CONF_UART_PARITY,
		.stopbits =		CONF_UART_STOP_BITS,
	};

	/* Configure UART console. */
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &uart_serial_options);
}

/**
 * @Brief Inicializa o pino do BUT
 */
void BUT_init(void){
    /* config. pino botao em modo de entrada */
    pmc_enable_periph_clk(BUT_PIO_ID);
    pio_set_input(BUT_PIO, BUT_PIN_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_set_debounce_filter(BUT_PIO, BUT_PIN_MASK, 250);
    
    /* config. interrupcao em borda de descida no botao do kit */
    /* indica funcao (but_Handler) a ser chamada quando houver uma interrupção */
    pio_enable_interrupt(BUT_PIO, BUT_PIN_MASK);
    pio_handler_set(BUT_PIO, BUT_PIO_ID, BUT_PIN_MASK, PIO_IT_FALL_EDGE, Button1_Handler);
    
    /* habilita interrupçcão do PIO que controla o botao */
    /* e configura sua prioridade                        */
    NVIC_EnableIRQ(BUT_PIO_ID);
    NVIC_SetPriority(BUT_PIO_ID, 1);
};

/**
 * @Brief Inicializa o pino do LED
 */
void LED_init(int estado){
    pmc_enable_periph_clk(LED_PIO_ID);
    pio_set_output(LED_PIO, LED_PIN_MASK, estado, 0, 0 );
};

/**
 * Configura o LCD
 */
static void LCD_init(void) {

  struct ili9488_opt_t g_ili9488_display_opt;

  /* Set direction and pullup on the given button IOPORT */
	ioport_set_pin_dir(GPIO_PUSH_BUTTON_1, IOPORT_DIR_INPUT);
	ioport_set_pin_mode(GPIO_PUSH_BUTTON_1, IOPORT_MODE_PULLUP);

	/* Initialize display parameter */
	g_ili9488_display_opt.ul_width = ILI9488_LCD_WIDTH;
	g_ili9488_display_opt.ul_height = ILI9488_LCD_HEIGHT;
	g_ili9488_display_opt.foreground_color = COLOR_CONVERT(COLOR_WHITE);
	g_ili9488_display_opt.background_color = COLOR_CONVERT(COLOR_WHITE);

	/* Initialize LCD */
	ili9488_init(&g_ili9488_display_opt);
  
  /* preenche backgrounf de branco */
	ili9488_draw_filled_rectangle(0, 0, ILI9488_LCD_WIDTH-1, ILI9488_LCD_HEIGHT-1);
	
  /* Header */
	ili9488_set_foreground_color(COLOR_CONVERT(COLOR_TOMATO));
	ili9488_draw_string(90, 30, "Mutirao C");
}


/************************************************************************/
/*                                                                      */
/************************************************************************/

void initBoardMutirao(){
		/* Initialize the board. */
		sysclk_init();
		board_init();
		ioport_init();
		
		BUT_init();
		LED_init(0);
		configure_console();
		LCD_init();
		//TC1_init(0);
    RTT_init();
				
		/* Enable SDRAMC peripheral clock */
		pmc_enable_periph_clk(ID_SDRAMC);

		/* Complete SDRAM configuration */
		sdramc_init((sdramc_memory_dev_t *)&SDRAM_ISSI_IS42S16100E,	sysclk_get_cpu_hz());
		sdram_enable_unaligned_support();
		SCB_CleanInvalidateDCache();

		/* delay para evitar primeira interrupcao do botao 
			que acontece quando é ativado*/
		delay_ms(100);
		buttonFlag = false;

}

void matrixToLCD(ili9488_color_t imgIn[320][320], ili9488_color_t *imgOut,  int imgW, int imgH){
	int x,y;
	int cntPx = 0;
	int cntCp = 0;
	
	for (x=0;x<imgH;x++){
		for (y=0;y<imgW;y++){
			*(imgOut + cntPx)   = imgIn[x][y];
			*(imgOut + cntPx+1) = imgIn[x][y];
			*(imgOut + cntPx+2) = imgIn[x][y];
			cntPx = cntPx + 3;
		}
	}
}

void imgShow(ili9488_color_t image[320][320], uint32_t time){
	ili9488_color_t *imgOutLCD = (ili9488_color_t *) BOARD_SDRAM_ADDR;

	matrixToLCD(image, imgOutLCD, 320, 320);
	ili9488_draw_pixmap(0, 320/4, 320, 320, imgOutLCD);
	
	ili9488_set_foreground_color(COLOR_CONVERT(COLOR_WHITE));
	ili9488_draw_filled_rectangle(0, 400, ILI9488_LCD_WIDTH-1, 450);
	
	if(time > 0){
		ili9488_set_foreground_color(COLOR_CONVERT(COLOR_TOMATO));
		char str[128];
		sprintf(str,"Processado em: %d ms", time);
		ili9488_draw_string(5, 410, str);
	}

}

