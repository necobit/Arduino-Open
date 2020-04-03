#include "M5Atom.h"

void setup() {
  Serial.begin(115200);
  M5.begin(true, false, true);
  delay(50);
  M5.dis.drawpix(0, 0xf00000);
}
long color;
int r = 255;
int g = 255;
int b = 0;
void loop() {
  int rn = random(255);
  int gn = random(255);
  int bn = random(255);
  int rp = (rn - r) / 20;
  int gp = (gn - g) / 20;
  int bp = (bn - b) / 20;
  for (int i = 0; i < 20; i++) {
    r = r + rp;
    g = g + gp;
    b = b + bp;
    long gb = g << 16;
    long rb = r << 8;
    long bb = b << 0;
    color = rb + gb + bb;
    painting();
  }
}

void painting() {
  for (int x = 0; x < 25; x++) {
    Serial.print(r); Serial.print(",");
    Serial.print(g); Serial.print(",");
    Serial.println(b); 
//    Serial.println(",");
//    Serial.println(color, HEX);
    M5.dis.drawpix(x, color);
  }
  delay(25);
  M5.update();
}
