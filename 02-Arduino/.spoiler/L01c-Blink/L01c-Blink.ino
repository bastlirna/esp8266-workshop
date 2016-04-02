/** Lekce 1 - Blikání RGB LED
 */

#include "hsv.h"

// definice pinů ESP8266 na které jsou připojeny LED
#define LED_R 16
#define LED_G 12
#define LED_B 14

void setup()
{
  Serial.begin(9600);
  
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

int a = 0;
int colors[3];

void loop()
{
  colorHSV(a, 255, 255, colors);
  
  analogWrite(LED_R, 1023 - 4 * colors[0]);
  analogWrite(LED_G, 1023 - 4 * colors[1]);
  analogWrite(LED_B, 1023 - 4 * colors[2]);
  
  a += 10;
  if (a >= 359) a = 0;

  Serial.println(a);

  delay(100);
}

