#include <Wire.h>
#include "Adafruit_MPR121.h"
#include "capinput.h"

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

#define NUM_BUTTONS 12

Adafruit_MPR121 cap = Adafruit_MPR121();

uint16_t buttons[NUM_BUTTONS];
uint16_t curr = 0;

void setup() {

    Serial.begin(9600);
    cap.begin(0x5A);
    cap.setThresholds(100, 150);

    for (uint16_t i=0; i<NUM_BUTTONS; i++) {
        buttons[i] = 0;
    }
}

void loop() {

    int idx = 0;

    curr = cap.touched();

    for(uint16_t i=0; i<NUM_BUTTONS; i++) {
        buttons[idx] = ((curr & (1 << i)) != 0);
        idx += 1;
    }

    Serial.print("Red: ");
    Serial.print(buttons[red]);
    Serial.print("Yellow: ");
    Serial.print(buttons[yellow]);
    Serial.print("Blue: ");
    Serial.print(buttons[blue]);
    Serial.print("Pink: ");
    Serial.print(buttons[pink]);
    Serial.print("Green: ");
    Serial.print(buttons[green]);

    Serial.print("Up: ");
    Serial.print(buttons[up]);
    Serial.print("Square: ");
    Serial.print(buttons[square]);
    Serial.print("Down: ");
    Serial.print(buttons[down]);

    Serial.println("");
    delay(500);

}
