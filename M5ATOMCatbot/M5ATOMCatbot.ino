#include "M5Atom.h"

int Catbot[25] = {
  0, 1, 0, 1, 0,
  1, 1, 1, 1, 1,
  1, 1, 1, 2, 1,
  1, 2, 1, 2, 1,
  1, 1, 1, 1, 1
};

void setup() {
  Serial.begin(115200);
  M5.begin(true, false, true);
  delay(50);
  for (int x = 0; x < 25; x++) {
    long color;
    if (Catbot[x] == 0) color = 0x000000;
    else if (Catbot[x] == 1) color = 0xFFF100;
    else if (Catbot[x] == 2) color = 0x00FF00;
    M5.dis.drawpix(x, color);
  }
  delay(25);
  M5.update();
}

boolean f;
void loop() {
  for (int i = 0; i < 51; i ++) {
    int r;
    for (int x = 0; x < 25; x++) {
      long color;
      if (Catbot[x] == 2) {
        if (f == true) r = i * 5;
        else r = (51 - i) * 5;
        color = r << 8;
        M5.dis.drawpix(x, color);
      }
    }
    delay(10);
    M5.update();
  }
  f = !f;
}
