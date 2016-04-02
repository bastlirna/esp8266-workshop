/** Lekce 2 - Tlačítka
 * 
 */

// https://github.com/thomasfredericks/Bounce2

#include <Bounce2.h>

Bounce btn = Bounce(); 

// definice pinů ESP8266 na které jsou připojeny tlačítka
#define SW1 4
#define SW2 5
#define LED_G 12

bool led = HIGH;

void setup()
{
  pinMode(SW1, INPUT);
  btn.attach(SW1);
  pinMode(LED_G, OUTPUT);

  digitalWrite(LED_G, HIGH);
}

void loop()
{
  btn.update();
  if (btn.fell()) 
  {
    led = !led;
    digitalWrite(LED_G, led);
  }
}

