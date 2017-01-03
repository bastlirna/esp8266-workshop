
#ifndef _HAL_H
#define _HAL_H

#include <Arduino.h>


#define INIT_LEDS 1
#define INIT_LEDS_PWM 2
#define INIT_BUTTONS 4
#define INIT_BEEPER 8


#define INIT_ALL (INIT_LEDS | INIT_BUTTONS | INIT_BEEPER)

#define INIT_ALL_LED_PWM (INIT_LEDS_PWM | INIT_BUTTONS)

typedef enum{
  SW1 = 0,
  SW2,
  BOOT
} Button;

typedef uint32_t Color;

typedef enum{
  BLACK = 0x000000,
  GRAY = 0x808080,
  SILVER = 0xC0C0C0,
  WHITE = 0xFFFFFF,
  MAROON = 0x800000,
  RED = 0xFF0000,
  OLIVE = 0x808000,
  YELLOW = 0xFFFF00,
  GREEN = 0x008000,
  LIME = 0x00FF00,
  TEAL = 0x008080,
  AQUA = 0x00FFFF,
  NAVY = 0x000080,
  BLUE = 0x0000FF,
  PURPLE = 0x800080,
  FUCHSIA = 0xFF00FF
} SystemColor;

class HAL{
private:
  uint8_t init_perphials;
  void initLeds();
  void initButtons();
  void initBeeper();
  float calculatePhysiologicalIntensity(float val);
  void ledIntensity(uint8_t led, uint16_t intensity);
public:

  HAL(uint8_t _init_perphials = INIT_ALL) : init_perphials(_init_perphials) {};

  void init() {
      initLeds();
      initButtons();
      initBeeper();
  };
  bool readButton(Button btn);
  bool readButton(Button btn, bool noDebounce);
  void ledColor(Color color);
  void ledColor(SystemColor color);
  void ledColor(uint8_t r, uint8_t g, uint8_t b);
  Color getColor();

  void beep(uint16_t frequency, uint32_t duration = 0);
  bool isBeeping();
  bool stopBeeping();

  uint16_t getSerialNumber();
  char* getHostname();
};


#endif
