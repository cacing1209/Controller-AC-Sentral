#include <common.h>

// display.clearDisplay();
// display.setTextSize(3);
// display.setTextColor(SSD1306_WHITE);
// display.setCursor(50, 15);
// display.println(F("DQ"));
// display.display();
// delay(2000);
// display.clearDisplay();

void menu::showMenu(Adafruit_SSD1306 *dsp, const char *msg)
{
    static uint8_t preveousIndex = 0;
    if (preveousIndex != indexMenu)
        dsp->clearDisplay();
    dsp->setTextSize(txtSize);
    dsp->setTextColor(SSD1306_WHITE);
    dsp->setCursor(0, 0);
    dsp->print(msg);
    preveousIndex = indexMenu;
}
void menu::begin(const char *Logo, int intervalDisplay)
{
    intervalDsp = intervalDisplay;
    logo = Logo;
}

menu::menu()
{
    // default setup;
    txtSize = 2;
    intervalDsp = 1000;
}