#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#define size_PROTECTED 10

// #define SCREEN_WIDTH 128
// #define SCREEN_HEIGHT 64
// #define OLED_RESET -1
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int OV[size_PROTECTED] = {A1, A2, A3, A4, A5, A6, A7, A8, A9};

class menu
{
private:
    uint8_t indexMenu;
    uint8_t txtSize;
    int intervalDsp;
    const char *logo;

private:
    int xx;
    int yy;

public:
    menu() : indexMenu(0) {};

    void begin(const char *Logo, int intervalDisplay);
    void showMenu(Adafruit_SSD1306 *dsp, const char *msg);
};
