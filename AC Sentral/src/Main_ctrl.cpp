#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <common.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
#define NUMFLAKES 10
#define LOGO_HEIGHT 16
#define LOGO_WIDTH 16

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
menu mainMenu;
#define menu_UP 11
#define menu_DOWN 12
#define menu_CONFIRM 13

const int ov1 = A1;
const int ov2 = A2;
const int ov3 = A3;
const int ov4 = A4;
const int ov5 = A5;
const int ov6 = A6;
const int ov7 = A7;
const int ov8 = A8;
const int ov9 = A9;
const int sw1 = 13;
const int sw2 = 12;
const int sw3 = 11;
const int OFF = A10;
int MATI = 0;
int ok = 0;
int next = 0;
int back = 0;
int a01 = 0;
int a02 = 0;
int a03 = 0;
int a04 = 0;
int a05 = 0;
int a06 = 0;
int a07 = 0;
int a08 = 0;
int a09 = 0;
#define sizeTxtmenu 3

void setup()
{
  mainMenu.begin("DQ", 2000);
  pinMode(menu_CONFIRM, INPUT);
  pinMode(menu_UP, INPUT);
  pinMode(menu_DOWN, INPUT);
}

uint8_t idxMenu = 0;
void debouceBuntton(int xp)
{
  static unsigned long previouseTime = 0;
  if (millis() - previouseTime > 1000) // debouce press
  {
    idxMenu += xp;
    if (idxMenu > 4)
      idxMenu = 0;
    if (idxMenu == 0 && xp == -1)
      idxMenu = 3;
    previouseTime = millis();
  }
}

void IndexMenu()
{

  if (digitalRead(menu_UP) == HIGH)
  {
    debouceBuntton(1);
  }
  else if (digitalRead(menu_DOWN) == HIGH)
  {
  }
  else
  {
  }
}
void MenuSetup()
{
  String menutxt[sizeTxtmenu] = {"MODE COOL", "MODE FAN", "MODE TURBO"};
}

void loop()
{
  MenuSetup();
}

void setup()
{
  // POWER OFF/ON
  pinMode(OFF, INPUT);
  // M
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  // OL
  pinMode(ov1, INPUT);
  pinMode(ov2, INPUT);
  pinMode(ov3, INPUT);
  pinMode(ov4, INPUT);
  pinMode(ov5, INPUT);
  pinMode(ov6, INPUT);
  pinMode(ov7, INPUT);
  pinMode(ov8, INPUT);
  pinMode(ov9, INPUT);

  // KT
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  // OVR
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  // buzz
  pinMode(2, OUTPUT);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 alokasi gagal"));
    for (;;)
      ;
  }
  display.invertDisplay(true);
  delay(1000);
  display.invertDisplay(false);
  delay(1000);

  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(50, 15);
  display.println(F("DQ"));
  display.display();
  delay(2000);
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(25, 35);
  display.println(F("WELCOME"));
  display.display();
  delay(2000);
  // FANSTART
  display.clearDisplay();
  display.display();

  a01 = digitalRead(ov1);
  a02 = digitalRead(ov2);
  a03 = digitalRead(ov3);
  a04 = digitalRead(ov4);
  a05 = digitalRead(ov5);
  a06 = digitalRead(ov6);
  a07 = digitalRead(ov7);
  a08 = digitalRead(ov8);
  a09 = digitalRead(ov9);
  /// comp1
  if (a01 == HIGH)
  {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(19, 20);
    display.println(F("ERORC1"));
    display.display();

    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(10, LOW);
    delay(10000);
  }

  /// comp2
  if (a02 == HIGH)
  {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(19, 20);
    display.println(F("ERORC2"));
    display.display();

    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(9, LOW);
    delay(10000);
  }

  /// comp3
  if (a03 == HIGH)
  {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(19, 20);
    display.println(F("ERORC3"));
    display.display();

    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(8, LOW);
    delay(10000);
  }

  /// motor
  if (a04 == HIGH)
  {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(19, 20);
    display.println(F("ERORC4"));
    display.display();

    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(7, LOW);
    delay(10000);
  }
  /// WPUMP
  if (a05 == HIGH)
  {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(19, 20);
    display.println(F("ERORC5"));
    display.display();

    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(6, LOW);
    delay(10000);
  }

  /// HL1
  if (a06 == HIGH)
  {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(19, 20);
    display.println(F("ERORH1"));
    display.display();

    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(10, LOW);
    delay(10000);
  }
  /// HL2
  if (a07 == HIGH)
  {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(19, 20);
    display.println(F("ERORH2"));
    display.display();

    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(9, LOW);
    delay(10000);
  }

  /// HL3
  if (a08 == HIGH)
  {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(19, 20);
    display.println(F("ERORH3"));
    display.display();

    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(8, LOW);
    delay(10000);
  }
}

void Display()
{
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(19, 20);
  display.println(F("ERORC1"));
  display.display();
}
void loop()
{

OFFMODE:
  while (1)
  {
    MATI = digitalRead(OFF);
    if (MATI == LOW)
    {
      display.clearDisplay();
      display.setTextSize(3);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(15, 0);
      display.println(F("POWER  OFF"));
      display.display();

      // digitalWrite(2, LOW);
      // digitalWrite(3, LOW);
      // digitalWrite(4, LOW);
      // digitalWrite(5, LOW);
      // digitalWrite(8, LOW);
      // digitalWrite(9, LOW);
      // digitalWrite(10, LOW);
      // delay(2000);
      // digitalWrite(6, LOW);
      // digitalWrite(7, LOW);
      // delay(5000);
      for (int i = 1; i < 10; i++)
      {
        digitalWrite(i, LOW);
        if (i = 7 || i == 6)
        {
          delay(2000);
        }
      }
      goto LCDOFF;
    }

    if (MATI == HIGH)
    {

    menu:
      while (1)
      {
        display.clearDisplay();
        display.setTextSize(3);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(15, 0);
        display.println(F(" MODE   COOL  "));
        display.display();
        digitalWrite(7, HIGH);
        digitalWrite(6, HIGH);

        ok = digitalRead(sw1);
        next = digitalRead(sw2);
        back = digitalRead(sw3);
        a01 = digitalRead(ov1);
        a02 = digitalRead(ov2);
        a03 = digitalRead(ov3);
        a04 = digitalRead(ov4);
        a05 = digitalRead(ov5);
        a06 = digitalRead(ov6);
        a07 = digitalRead(ov7);
        a08 = digitalRead(ov8);
        a09 = digitalRead(ov9);
        MATI = digitalRead(OFF);
        if (MATI == LOW)
        {
          delay(3000);
          goto OFFMODE;
        }
        if (ok == LOW)
        {
          delay(300);
          goto COMP1;
        }
        if (next == LOW)
        {
          delay(300);
          goto next1;
        }
        if (back == LOW)
        {
          delay(300);
          goto timer;
        }
        /// comp1
        if (a01 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC1"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(10, LOW);
          delay(10000);
        }

        /// comp2
        if (a02 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC2"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(9, LOW);
          delay(10000);
        }

        /// comp3
        if (a03 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC3"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(8, LOW);
          delay(10000);
        }

        /// motor
        if (a04 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC4"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(7, LOW);
          delay(10000);
        }
        /// WPUMP
        if (a05 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC5"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(6, LOW);
          delay(10000);
        }

        /// HL1
        if (a06 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH1"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(10, LOW);
          delay(10000);
        }
        /// HL2
        if (a07 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH2"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(9, LOW);
          delay(10000);
        }

        /// HL3
        if (a08 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH3"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(8, LOW);
          delay(10000);
        }
      }

    COMP1:
      while (1)
      {

        display.clearDisplay();
        display.setTextSize(3);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(12, 16);
        display.println(F(" COMP1"));
        display.display();

        ok = digitalRead(sw1);
        next = digitalRead(sw2);
        back = digitalRead(sw3);
        a01 = digitalRead(ov1);
        a02 = digitalRead(ov2);
        a03 = digitalRead(ov3);
        a04 = digitalRead(ov4);
        a05 = digitalRead(ov5);
        a06 = digitalRead(ov6);
        a07 = digitalRead(ov7);
        a08 = digitalRead(ov8);
        a09 = digitalRead(ov9);
        MATI = digitalRead(OFF);
        if (MATI == LOW)
        {
          delay(3000);
          goto OFFMODE;
        }

        if (ok == LOW)
        {
          delay(300);
          digitalWrite(10, HIGH);
        }
        if (next == LOW)
        {
          delay(300);
          goto COMP2;
        }
        if (back == LOW)
        {
          delay(300);
          digitalWrite(10, LOW);
        }
        /// comp1
        if (a01 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC1"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(10, LOW);
          delay(10000);
        }

        /// comp2
        if (a02 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC2"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(9, LOW);
          delay(10000);
        }

        /// comp3
        if (a03 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC3"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(8, LOW);
          delay(10000);
        }

        /// motor
        if (a04 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC4"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(7, LOW);
          delay(10000);
        }
        /// WPUMP
        if (a05 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC5"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(6, LOW);
          delay(10000);
        }

        /// HL1
        if (a06 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH1"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(10, LOW);
          delay(10000);
        }
        /// HL2
        if (a07 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH2"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(9, LOW);
          delay(10000);
        }

        /// HL3
        if (a08 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH3"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(8, LOW);
          delay(10000);
        }
      }

    COMP2:
      while (1)
      {

        display.clearDisplay();
        display.setTextSize(3);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(12, 16);
        display.println(F("COMP2"));
        display.display();

        ok = digitalRead(sw1);
        next = digitalRead(sw2);
        back = digitalRead(sw3);
        a01 = digitalRead(ov1);
        a02 = digitalRead(ov2);
        a03 = digitalRead(ov3);
        a04 = digitalRead(ov4);
        a05 = digitalRead(ov5);
        a06 = digitalRead(ov6);
        a07 = digitalRead(ov7);
        a08 = digitalRead(ov8);
        a09 = digitalRead(ov9);
        MATI = digitalRead(OFF);
        if (MATI == LOW)
        {
          delay(3000);
          goto OFFMODE;
        }

        if (ok == LOW)
        {
          delay(300);
          digitalWrite(9, HIGH);
          ;
        }
        if (next == LOW)
        {
          delay(300);
          goto COMP3;
        }
        if (back == LOW)
        {
          delay(300);
          digitalWrite(9, LOW);
        }
        /// comp1
        if (a01 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC1"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(10, LOW);
          delay(10000);
        }

        /// comp2
        if (a02 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC2"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(9, LOW);
          delay(10000);
        }

        /// comp3
        if (a03 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC3"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(8, LOW);
          delay(10000);
        }

        /// motor
        if (a04 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC4"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(7, LOW);
          delay(10000);
        }
        /// WPUMP
        if (a05 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC5"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(6, LOW);
          delay(10000);
        }

        /// HL1
        if (a06 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH1"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(10, LOW);
          delay(10000);
        }
        /// HL2
        if (a07 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH2"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(9, LOW);
          delay(10000);
        }

        /// HL3
        if (a08 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH3"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(8, LOW);
          delay(10000);
        }
      }

    COMP3:
      while (1)
      {

        display.clearDisplay();
        display.setTextSize(3);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(12, 16);
        display.println(F("COMP3"));
        display.display();

        ok = digitalRead(sw1);
        next = digitalRead(sw2);
        back = digitalRead(sw3);
        a01 = digitalRead(ov1);
        a02 = digitalRead(ov2);
        a03 = digitalRead(ov3);
        a04 = digitalRead(ov4);
        a05 = digitalRead(ov5);
        a06 = digitalRead(ov6);
        a07 = digitalRead(ov7);
        a08 = digitalRead(ov8);
        a09 = digitalRead(ov9);
        MATI = digitalRead(OFF);
        if (MATI == LOW)
        {
          delay(3000);
          goto OFFMODE;
        }
        if (ok == LOW)
        {
          delay(300);
          digitalWrite(8, HIGH);
        }
        if (next == LOW)
        {
          delay(300);
          goto menu;
        }
        if (back == LOW)
        {
          delay(300);
          digitalWrite(8, LOW);
        }
        /// comp1
        if (a01 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC1"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(10, LOW);
          delay(10000);
        }

        /// comp2
        if (a02 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC2"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(9, LOW);
          delay(10000);
        }

        /// comp3
        if (a03 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC3"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(8, LOW);
          delay(10000);
        }

        /// motor
        if (a04 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC4"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(7, LOW);
          delay(10000);
        }
        /// WPUMP
        if (a05 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC5"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(6, LOW);
          delay(10000);
        }

        /// HL1
        if (a06 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH1"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(10, LOW);
          delay(10000);
        }
        /// HL2
        if (a07 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH2"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(9, LOW);
          delay(10000);
        }

        /// HL3
        if (a08 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH3"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(8, LOW);
          delay(10000);
        }
      }

    next1:
      while (1)
      {

        display.clearDisplay();
        display.setTextSize(3);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(15, 0);
        display.println(F(" MODE   FAN "));
        display.display();
        ok = digitalRead(sw1);
        next = digitalRead(sw2);
        back = digitalRead(sw3);
        a01 = digitalRead(ov1);
        a02 = digitalRead(ov2);
        a03 = digitalRead(ov3);
        a04 = digitalRead(ov4);
        a05 = digitalRead(ov5);
        a06 = digitalRead(ov6);
        a07 = digitalRead(ov7);
        a08 = digitalRead(ov8);
        a09 = digitalRead(ov9);
        MATI = digitalRead(OFF);
        if (MATI == LOW)
        {
          delay(3000);
          goto OFFMODE;
        }

        if (ok == LOW)
        {
          delay(300);
          digitalWrite(8, LOW);
          delay(300);
          digitalWrite(9, LOW);
          delay(300);
          digitalWrite(10, LOW);
        }
        if (back == LOW)
        {
          delay(300);
          goto menu;
        }
        if (next == LOW)
        {
          delay(300);
          goto modeturboxxx;
        }
        /// comp1
        if (a01 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC1"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(10, LOW);
          delay(10000);
        }

        /// comp2
        if (a02 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC2"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(9, LOW);
          delay(10000);
        }

        /// comp3
        if (a03 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC3"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(8, LOW);
          delay(10000);
        }

        /// motor
        if (a04 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC4"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(7, LOW);
          delay(10000);
        }
        /// WPUMP
        if (a05 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC5"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(6, LOW);
          delay(10000);
        }

        /// HL1
        if (a06 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH1"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(10, LOW);
          delay(10000);
        }
        /// HL2
        if (a07 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH2"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(9, LOW);
          delay(10000);
        }

        /// HL3
        if (a08 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH3"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(8, LOW);
          delay(10000);
        }
      }

    modeturboxxx:
      while (1)
      {
        display.clearDisplay();
        display.setTextSize(3);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(15, 0);
        display.println(F(" MODE  TURBO  "));
        display.display();

        ok = digitalRead(sw1);
        next = digitalRead(sw2);
        back = digitalRead(sw3);
        a01 = digitalRead(ov1);
        a02 = digitalRead(ov2);
        a03 = digitalRead(ov3);
        a04 = digitalRead(ov4);
        a05 = digitalRead(ov5);
        a06 = digitalRead(ov6);
        a07 = digitalRead(ov7);
        a08 = digitalRead(ov8);
        a09 = digitalRead(ov9);
        MATI = digitalRead(OFF);
        if (MATI == LOW)
        {
          delay(3000);
          goto OFFMODE;
        }

        if (ok == LOW)
        {

          display.clearDisplay();
          display.setTextSize(2);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(15, 25);
          display.println(F("PROSES!!!"));
          display.display();

          delay(7000);
          digitalWrite(8, HIGH);
          delay(12000);
          digitalWrite(9, HIGH);
          delay(9000);
          digitalWrite(10, HIGH);

          display.clearDisplay();
          display.setTextSize(1);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(15, 0);
          display.println(F(" MODE TURBO ACTIV  "));
          display.display();
        }
        if (next == LOW)
        {
          delay(300);
          goto timer;
        }
        if (back == LOW)
        {
          delay(300);
          goto next1;
        }
        /// comp1
        if (a01 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC1"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(10, LOW);
          delay(10000);
        }

        /// comp2
        if (a02 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC2"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(9, LOW);
          delay(10000);
        }

        /// comp3
        if (a03 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC3"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(8, LOW);
          delay(10000);
        }

        /// motor
        if (a04 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC4"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(7, LOW);
          delay(10000);
        }
        /// WPUMP
        if (a05 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC5"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(6, LOW);
          delay(10000);
        }

        /// HL1
        if (a06 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH1"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(10, LOW);
          delay(10000);
        }
        /// HL2
        if (a07 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH2"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(9, LOW);
          delay(10000);
        }

        /// HL3
        if (a08 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH3"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(8, LOW);
          delay(10000);
        }
      }

    timer:
      while (1)
      {

        display.clearDisplay();
        display.setTextSize(3);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(19, 20);
        display.println(F("TIMER"));
        display.display();
        ok = digitalRead(sw1);
        next = digitalRead(sw2);
        back = digitalRead(sw3);
        a01 = digitalRead(ov1);
        a02 = digitalRead(ov2);
        a03 = digitalRead(ov3);
        a04 = digitalRead(ov4);
        a05 = digitalRead(ov5);
        a06 = digitalRead(ov6);
        a07 = digitalRead(ov7);
        a08 = digitalRead(ov8);
        a09 = digitalRead(ov9);
        MATI = digitalRead(OFF);
        if (MATI == LOW)
        {
          delay(3000);
          goto OFFMODE;
        }
        if (ok == LOW)
        {

          delay(300);
          digitalWrite(8, LOW);
          delay(300);
          digitalWrite(9, LOW);
          delay(300);
          digitalWrite(10, LOW);

          // MODE TIMER
        }
        if (back == LOW)
        {
          delay(300);
          goto modeturboxxx;
        }
        if (next == LOW)
        {
          delay(300);
          goto menu;
        }
        /// comp1
        if (a01 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC1"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(10, LOW);
          delay(10000);
        }

        /// comp2
        if (a02 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC2"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(9, LOW);
          delay(10000);
        }

        /// comp3
        if (a03 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC3"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(8, LOW);
          delay(10000);
        }

        /// motor
        if (a04 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC4"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(7, LOW);
          delay(10000);
        }
        /// WPUMP
        if (a05 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORC5"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(6, LOW);
          delay(10000);
        }

        /// HL1
        if (a06 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH1"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(10, LOW);
          delay(10000);
        }
        /// HL2
        if (a07 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH2"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(9, LOW);
          delay(10000);
        }

        /// HL3
        if (a08 == HIGH)
        {
          display.clearDisplay();
          display.setTextSize(3);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(19, 20);
          display.println(F("ERORH3"));
          display.display();

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(8, LOW);
          delay(10000);
        }
      }
    }
  }

LCDOFF:
  while (1)
  {

    MATI = digitalRead(OFF);
    display.clearDisplay();
    display.display();
    if (MATI == HIGH)
    {
      delay(300);
      goto OFFMODE;
    }
  }
}
