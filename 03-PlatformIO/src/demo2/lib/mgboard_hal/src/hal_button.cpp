#include <Arduino.h>
#include <DebouncedInput.h>

#include "hal_inner.h"
#include "hal.h"


static DebouncedInput sw1(SWITCH1, DEBOUNCE_TIME, true);
static DebouncedInput sw2(SWITCH2, DEBOUNCE_TIME, true);
static DebouncedInput boot(BOOT_BTN, DEBOUNCE_TIME, true);

void HAL::initButtons()
{
  if(init_perphials & INIT_BUTTONS){
    pinMode(SWITCH1, INPUT);
    pinMode(SWITCH2, INPUT);
    pinMode(BOOT_BTN, INPUT);

    sw1.begin();
    sw2.begin();
    boot.begin();

  }
}

bool HAL::readButton(Button btn, bool noDebounce)
{
  if(!noDebounce){
    switch(btn){
      case SW1:
        return sw1.changedTo(LOW);
      case SW2:
        return sw2.changedTo(LOW);
      case BOOT:
        return boot.changedTo(LOW);
    }
  }else{
    switch(btn){
      case SW1:
        return digitalRead(SWITCH1) == 0;
      case SW2:
        return digitalRead(SWITCH2) == 0;
      case BOOT:
        return digitalRead(BOOT_BTN) == 0;
    }
  }

  return false;
}

bool HAL::readButton(Button btn)
{
  return readButton(btn, false);
}
