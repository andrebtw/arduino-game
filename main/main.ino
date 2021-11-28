#include <LiquidCrystal.h>


const int pinX = A0;
const int pinY = A1;
const int pinBouton = 1;



LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int contrast=15;

int number = 0;

String Direction = "None";

int X;
int Y;


void setup () {
  analogWrite(6, contrast);
  lcd.begin(16, 2);
  Serial.begin(9600);

}

void loop () {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(Direction);
  Direction = "None";
  

  X = analogRead(pinX);
  Serial.println(X);

  Y = analogRead(pinY);
  Serial.println(Y);

  if (X > 960) { ///DOWN
    Direction = "DOWN";
      while (X > 850) {
        X = analogRead(pinX);
        Serial.println("waiting");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(Direction);
      }
    }
  if (X < 60) { ///UP
    Direction = "UP";
      while (X < 150) {
        X = analogRead(pinX);
        Serial.println("waiting");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(Direction);
      }
    }

    if (Y < 60) { ///RIGHT
    Direction = "RIGHT";
      while (Y < 150) {
        Y = analogRead(pinY);
        Serial.println("waiting");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(Direction);
      }
    }

    if (Y > 960) { ///LEFT
    Direction = "LEFT";
      while (Y > 850) {
        Y = analogRead(pinY);
        Serial.println("waiting");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(Direction);
      }
    }
  
}
