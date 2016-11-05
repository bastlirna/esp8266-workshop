# Drátujeme IoT: ESP8266
Workshop na programování chipu ESP8266. Workshop využívá [ESP8266 demo board] (https://github.com/bastlirna/esp8266-board).

## Demo 1
Naprogramujte ESP8266 tak aby po seriové lince vypisovalo "Hello world". Použijte Arduino knihovny.

Target platform při vytvráření projektu je **Espressif ESP8266 ESP-12E**. Nebo v *platformio.ini*

	[env:esp12e]
	platform = espressif8266
	framework = arduino
	board = nodemcu

## Demo 2
Ukázka připojení k MQTT serveru. [demo 2] (demo2.zip)

* Přepište kód tak, aby jste zápisem do kanálu **/workshop/*<serialNO>*/command** mohli rozsvítit ledku.
* Přepište kód tak, aby při stisku tlačítka odeslal zprávu do topicu **/workshop/*<serialNO>*/button**

## Demo 3
Ukázka čtení teploty a vlhkosti z DHT11. [demo 3] (demo3.zip)

* Zkombinujte demo3 s demo2, aby jste odesílali hodnoty z čidla na MQTT kanál **/workshop/*<serialNO>*/temperature**


## Doporučení
Pro připojení k MQTT serveru je potřeba knihovně *PubSubClient* říct, jakou má použít verzi protokolu. V *PlatformIO* to lze za pomoci volby v *platform.ini*

	build_flags = -D MQTT_VERSION=MQTT_VERSION_3_1

Pro rychlejší nahrávání programu zvyšte *baud rate*. Pokud je potřeba vydefinovat port, tak to lze za pomoci **upload_port**.

	upload_speed = 921600

Používané knihovny při workshopu

	lib_deps = WifiManager@~0.12, PubSubClient@~2.6, DebouncedInput@~1.0.13
