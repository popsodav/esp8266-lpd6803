#include "user_config.h"
#include "ets_sys.h"
#include "osapi.h"
#include "gpio.h"
#include "os_type.h"
#include "driver/uart.h"
#include "lpd6803.h"

#define user_procTaskPrio        0
#define user_procTaskQueueLen    1

os_event_t user_procTaskQueue[user_procTaskQueueLen];
static void user_procTask(os_event_t *events);
static volatile os_timer_t some_timer;
static volatile os_timer_t lpd6803_timer;

static void ICACHE_FLASH_ATTR
user_procTask(os_event_t *events) {
	os_delay_us(40);
}

//Init function 
void ICACHE_FLASH_ATTR
user_init() {
	system_timer_reinit();
	uart_init(BIT_RATE_115200, BIT_RATE_115200);
	os_delay_us(1000);
	uart0_sendStr("Loading LPD6803...\r\n");

	lpd6803_init();
	lpd6803_show();

	lpd6803_startRainbow();

	//Start os task
	system_os_task(user_procTask, user_procTaskPrio, user_procTaskQueue,
			user_procTaskQueueLen);
}
