# Postup instalace nezbytného SW

## 1. Arduino IDE

Naistalujte si poslední verzi arduino IDE pro váš operační systém z webu [http://www.arduino.cc/](http://www.arduino.cc/). 

Minimálné verze, kterou budete potřebovat je 1.6.4.

> Opravdu potřebujete verzi z arduino.cc, IDE od arduino.org nebude fungovat!

Odkazy:

- [https://www.arduino.cc/en/Main/Software](https://www.arduino.cc/en/Main/Software)

## 2. ESP8266 core for Arduino

Nejsnažší instalace je pomocí **Board Manager** (součást Arduino IDE od verze 1.6.4). 

Aby Board Manager věděl odkud stáhnout podporu pro ESP, je třeba přidat URL do nastavení IDE.

![Menu](.images/arduino-ide-1.jpg)

Do pole *Správce dalších desek URL* (v anglické verzi *Additional Board Manager URL*) zadejte URL:

`http://arduino.esp8266.com/stable/package_esp8266com_index.json`

![Vlastnosti](.images/arduino-ide-2.jpg)

Následně pokračujte do *Manažér desek*

![Menu](.images/arduino-ide-3.jpg)

Nyní by mělo být rovnou najít *ESP8266* v dostupných deskách, vybrat poslední verzi (aktuálně 2.1.0) a kliknout na instalovat.

![Menu](.images/arduino-ide-4.jpg)

> Instalace je poměrně časově náročný postup, zabere 10 - 30 minut.


Odkazy:

- [https://github.com/esp8266/Arduino](https://github.com/esp8266/Arduino)