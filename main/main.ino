#include <LiquidCrystal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FPS 25.0
#define MPS ((1.0 / FPS) * 1000.0)
#define BAUD_RATE 9600
#define PIN_JOYSTICK_X 1
#define PIN_JOYSTICK_Y 0
#define PIN_JOYSTICK_BUTTON 4
#define TRUE 1
#define FALSE 0
#define CONTRAST 15

int js_y;
int js_x;
int js_button;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    pinMode(PIN_JOYSTICK_BUTTON, INPUT);
    digitalWrite(PIN_JOYSTICK_BUTTON, HIGH);
    analogWrite(6, CONTRAST);
    lcd.begin(16, 2);
    Serial.begin(BAUD_RATE);

    js_button = FALSE;
    js_y = 0;
    js_x = 0;
}

void loop()
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MDMA <3");
    js_x = analogRead(PIN_JOYSTICK_X);
    js_y = analogRead(PIN_JOYSTICK_Y);
    js_button = digitalRead(PIN_JOYSTICK_BUTTON);
    // Serial.println(js_x);
    // Serial.println(js_y);
    // Serial.println(js_button);
    delay(MPS);
}
