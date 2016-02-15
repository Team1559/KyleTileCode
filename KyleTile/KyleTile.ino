#include <HID-Project.h>
#include <HID-Settings.h>

int i = 1;
int numButts = 6;

void setup() {
  // put your setup code here, to run once:
  {
    for (int i = 2; i <= numButts + 1; i++) {
      pinMode(i, INPUT_PULLUP);
    }
    Gamepad.begin();
  }

  void loop() {
    // put your main code here, to run repeatedly:
    for (int i = 2; i <= numButts + 1; i++) {
      if (digitalRead(i) == LOW) {
        Gamepad.press(i - 2);
      }
      else {
        Gamepad.release(i - 2);
      }
    }
    Gamepad.xAxis(analogRead(A0));
    Gamepad.write();
  }
