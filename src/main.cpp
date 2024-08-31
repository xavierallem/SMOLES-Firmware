#include <smoles.h>
#include <BluetoothConnection.h>

bool use_json_output = false;
bool use_left_foot = false;
Smoles smoles_manager(use_json_output, use_left_foot);

void setup()
{
  Serial.begin(115200);
  smoles_manager.setup();
}

void loop()
{
  smoles_manager.loop();
  delay(44);
}
