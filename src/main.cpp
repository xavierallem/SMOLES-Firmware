#include <smoles.h>
#include <BluetoothConnection.h>

bool use_json_output = false;
Smoles smoles_manager(use_json_output);

void setup()
{
  Serial.begin(115200);
  smoles_manager.setup();
}

void loop()
{
  smoles_manager.loop();
  delay(1000);
}
