#include <Arduino.h>
#include <hal.h>

HAL hal(INIT_ALL_LED_PWM);

static Color colors[] = {BLACK,GRAY,SILVER,WHITE,MAROON,RED,OLIVE,YELLOW,GREEN,LIME,TEAL,AQUA,NAVY,BLUE,PURPLE,FUCHSIA};
static uint8_t idx = 0;

void setup()
{
  hal.init();
}

void loop()
{
  if(hal.readButton(SW1)){
    idx = (idx + 1) % (sizeof(colors) / sizeof(Color));
    hal.ledColor(colors[idx]);
  }
}
