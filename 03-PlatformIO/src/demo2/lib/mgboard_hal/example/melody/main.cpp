#include <Arduino.h>
#include <hal.h>

#include "songs.h"

HAL hal(INIT_ALL);

static uint8_t idx = 0;
static uint8_t songId = 0;

void setup()
{
  hal.init();
}

void loop()
{
  // beeper a RGB color mixing are sharing PWM hardware, so you can't use both

  song_t *song;
  switch (songId) {
    case 0:
      song = &mario;
      break;
    case 1:
      song = &underworld;
      break;
  }

  if(hal.readButton(SW1)){
    songId = !songId;
    idx = 0;
    delay(1000);
  }

  if(!hal.isBeeping()){
    if(idx == 0){
      delay(1000);
    }

    int noteDuration = 1000/song->tempo[idx];
    if(song->melody[idx] == 0){
      delay(noteDuration+50);
    }else{
      hal.beep(song->melody[idx], noteDuration+50);
    }
    delay(noteDuration / 3);
    idx = (idx + 1) % song->lenght;
  }

}
