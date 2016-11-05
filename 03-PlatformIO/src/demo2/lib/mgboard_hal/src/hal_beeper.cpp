#include <Arduino.h>

#include "hal_inner.h"
#include "hal.h"

static uint32_t lastRun = 0;
static uint32_t lastDuration = 0;

void HAL::initBeeper()
{
  if(init_perphials & INIT_BEEPER){
    pinMode(BEEPER, OUTPUT);
    digitalWrite(BEEPER, LOW);
  }
}

bool HAL::isBeeping()
{
  if(lastDuration == 0){
      return lastRun != 0;
  }

  if((millis() - lastRun) >= lastDuration){
    lastRun = 0;
    lastDuration = 0;

    return false;
  }

  return true;
}

void HAL::beep(uint16_t frequency, uint32_t duration)
{
  if(init_perphials & INIT_BEEPER){
    lastDuration = duration;
    lastRun = millis();
    tone(BEEPER, frequency, duration);
  }
}

bool HAL::stopBeeping()
{
  if(init_perphials & INIT_BEEPER){
    noTone(BEEPER);
    lastRun = 0;
    lastDuration = 0;
  }
}
