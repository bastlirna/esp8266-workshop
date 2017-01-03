#include <Arduino.h>

#include "hal.h"

#define LITE 1
#define FULL 2

typedef struct{
  uint16_t serialNumber;
  uint8_t boardType;
  uint32_t chipId;
}binfo_t;

static const binfo_t boards[] = {
  {1, LITE, 0x00d57af7},
  {2, FULL, 0x00d75d73},
  {3, LITE, 0x00d578d2},
  {4, LITE, 0x00d767c7},
  {5, LITE, 0x001487d5},
  {6, LITE, 0x00d768b8},
  {7, LITE, 0x00d76830},
  {8, LITE, 0x00d57b86},
  {9, LITE, 0x00d76690},
  {10, LITE, 0x00d76879},
  {11, LITE, 0x00149b1f},
  {12, LITE, 0x000a7895},
  {15, LITE, 0x000a7262},
  {0, 0, 0}
};

static const binfo_t* getBoardInfo()
{
  uint32_t chipId = ESP.getChipId();
  const binfo_t* i = boards;
  while(i->chipId){
    if(i->chipId == chipId){
      return i;
    }
    i++;
  }
  return NULL;
}

uint16_t HAL::getSerialNumber()
{
  const binfo_t* i = getBoardInfo();

  if(i == NULL){
    return 0;
  }

  return i->serialNumber;
}

char* HAL::getHostname()
{
  static char hostname[32];
  uint16_t sn = 0;

  if(hostname[0] == 0){

    const binfo_t* i = getBoardInfo();
    if(i != NULL){
      sn = i->serialNumber;
    }
    sprintf(hostname, "%02u", sn);
  }

  return hostname;
}
