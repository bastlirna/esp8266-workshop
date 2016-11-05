#include <Arduino.h>

#include "hal_inner.h"
#include "hal.h"

static Color lastColor = 0;

void HAL::initLeds()
{
  if(init_perphials & (INIT_LEDS | INIT_LEDS_PWM)){
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);

    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, HIGH);
  }
}

void HAL::ledColor(SystemColor color)
{
  ledColor((Color) color);
}

Color HAL::getColor()
{
  return lastColor;
}

float HAL::calculatePhysiologicalIntensity(float val)
{
  return min((val * val) / 63, 1023);
}

void HAL::ledColor(Color color)
{
  ledColor((color >> 16) & 0xff, (color >> 8) & 0xff, color & 0xff);
}

void HAL::ledIntensity(uint8_t led, uint16_t intensity)
{
  intensity = 1023 - intensity;

  if((init_perphials & INIT_LEDS_PWM) == 0){
    digitalWrite(led, intensity != 0);
  }else{
    analogWrite(led, intensity);
  }
}

void HAL::ledColor(uint8_t r, uint8_t g, uint8_t b)
{
  lastColor = (r << 16) || (g << 8) || b;

  ledIntensity(LED_RED, calculatePhysiologicalIntensity(r));
  ledIntensity(LED_GREEN, calculatePhysiologicalIntensity(g));
  ledIntensity(LED_BLUE, calculatePhysiologicalIntensity(b));

}
