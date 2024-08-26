/*
 * CJMCU-Script-Runner
 * Arduino script for CJMCU BadUSB to read keystrokes from an SD card and inject them.
 * Author - WireBits
 */

#include <SD.h>
#include <SPI.h>
#include <Keyboard.h>

File scriptFile;
String defaultScriptFile = "script.txt";

char toLowerCase(char keyChar) {
  return (keyChar >= 'A' && keyChar <= 'Z') ? keyChar + ('a' - 'A') : keyChar;
}

void setup() {
  if (!SD.begin(4)) return;

  scriptFile = SD.open(defaultScriptFile);
  if (!scriptFile) return;

  Keyboard.begin();
  String line = "";
  while (scriptFile.available()) {
    char m = scriptFile.read();
    if (m == '\n') {
      scriptFileLines(line);
      line = "";
    } else if ((int)m != 13) {
      line += m;
    }
  }
  scriptFileLines(line);
  scriptFile.close();
  Keyboard.end();
}

void scriptFileLines(String lines) {
  int space_1 = lines.indexOf(" ");
  String cmd = (space_1 == -1) ? lines : lines.substring(0, space_1);
  String arg = (space_1 == -1) ? "" : lines.substring(space_1 + 1);

  if (cmd == "TYPE") {
    Keyboard.print(arg);
  } else if (cmd == "WAIT") {
    delay(arg.toInt());
  } else {
    pressKeys(lines);
  }
  Keyboard.releaseAll();
}

void pressKeys(String keys) {
  int space_1 = keys.indexOf(" ");
  while (space_1 != -1) {
    String key = keys.substring(0, space_1);
    pressKey(key);
    keys = keys.substring(space_1 + 1);
    space_1 = keys.indexOf(" ");
  }
  pressKey(keys);
}

void pressKey(String b) {
  struct KeyMap {
    const char* name;
    uint8_t key;
  } keyMap[] = {
    {"ENTER", KEY_RETURN}, {"CTRL", KEY_LEFT_CTRL}, {"SHIFT", KEY_LEFT_SHIFT},
    {"ALT", KEY_LEFT_ALT}, {"GUI", KEY_LEFT_GUI}, {"UP", KEY_UP_ARROW},
    {"DOWN", KEY_DOWN_ARROW}, {"LEFT", KEY_LEFT_ARROW}, {"RIGHT", KEY_RIGHT_ARROW},
    {"DELETE", KEY_DELETE}, {"PAGEUP", KEY_PAGE_UP}, {"PAGEDOWN", KEY_PAGE_DOWN},
    {"HOME", KEY_HOME}, {"ESC", KEY_ESC}, {"INSERT", KEY_INSERT},
    {"TAB", KEY_TAB}, {"END", KEY_END}, {"CAPSLOCK", KEY_CAPS_LOCK},
    {"F1", KEY_F1}, {"F2", KEY_F2}, {"F3", KEY_F3}, {"F4", KEY_F4},
    {"F5", KEY_F5}, {"F6", KEY_F6}, {"F7", KEY_F7}, {"F8", KEY_F8},
    {"F9", KEY_F9}, {"F10", KEY_F10}, {"F11", KEY_F11}, {"F12", KEY_F12},
    {"SPACE", ' '}
  };
  if (b.length() == 1) {
    Keyboard.press(toLowerCase(b[0]));
    return;
  }
  for (auto& k : keyMap) {
    if (b.equals(k.name)) {
      Keyboard.press(k.key);
      return;
    }
  }
}

void loop() {
  // Nothing to do here ;)
}
