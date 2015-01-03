#define numLEDs 5
#define LPD6803_START 0
#define LPD6803_HEADER 1
#define LPD6803_DATA 2
#define LPD6803_DONE 3

#define LPD6803_MODE_NONE 0
#define LPD6803_MODE_RUNNING_PIXEL 1
#define LPD6803_MODE_RUNNING_LINE 2
#define LPD6803_MODE_RAINBOW 3
#define LPD6803_MODE_RAINBOW2 4
#define LPD6803_MODE_SNOW 5
#define LPD6803_MODE_RGB 6

#define sleepms(x) os_delay_us(x*1000);

void ICACHE_FLASH_ATTR lpd6803_LedOut();
void ICACHE_FLASH_ATTR lpd6803_setPixelColor(uint16_t n, uint8_t b, uint8_t r, uint8_t g);
void ICACHE_FLASH_ATTR lpd6803_setPixelColorByColor(uint16_t n, uint16_t c);
void ICACHE_FLASH_ATTR lpd6803_setAllPixelColor(uint8_t r, uint8_t g, uint8_t b);
void ICACHE_FLASH_ATTR lpd6803_init();
unsigned int ICACHE_FLASH_ATTR lpd6803_Color(uint8_t b, uint8_t r, uint8_t g);
unsigned int ICACHE_FLASH_ATTR lpd6803_Wheel(uint8_t WheelPos);
void ICACHE_FLASH_ATTR lpd6803_loop();
void ICACHE_FLASH_ATTR lpd6803_show(void);
uint16_t ICACHE_FLASH_ATTR lpd6803_getPixelColorR(uint16_t n);
uint16_t ICACHE_FLASH_ATTR lpd6803_getPixelColorG(uint16_t n);
uint16_t ICACHE_FLASH_ATTR lpd6803_getPixelColorB(uint16_t n);
uint8_t ICACHE_FLASH_ATTR lpd6803_getMode();


//Running Pixel mode functions
void ICACHE_FLASH_ATTR lpd6803_startRunningPixel(uint16_t color);
void ICACHE_FLASH_ATTR lpd6803_RunningPixel_loop();

//Running Line mode functions
void ICACHE_FLASH_ATTR lpd6803_startRunningLine(uint16_t color);
void ICACHE_FLASH_ATTR lpd6803_RunningLine_loop();

//Rainbow mode functions
void ICACHE_FLASH_ATTR lpd6803_Rainbow_loop() ;
void ICACHE_FLASH_ATTR lpd6803_startRainbow();

void ICACHE_FLASH_ATTR lpd6803_Rainbow2_loop() ;
void ICACHE_FLASH_ATTR lpd6803_startRainbow2();

void ICACHE_FLASH_ATTR lpd6803_Snow_loop();
void ICACHE_FLASH_ATTR lpd6803_startSnow();

void ICACHE_FLASH_ATTR lpd6803_RGB_loop();
void ICACHE_FLASH_ATTR lpd6803_startRGB();

void ICACHE_FLASH_ATTR lpd6803_disableModes();
