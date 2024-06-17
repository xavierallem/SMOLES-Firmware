#include <smoles.h>

// #include "CD74HC4067.h"
#include "utils.h"

// CD74HC4067 mux(2, 3, 4, 5); // Actual Pins

Smoles::Smoles(bool _use_json_output) : use_json_output(_use_json_output)
{
  measurement_values = std::vector<int>(16, 0);
}

void Smoles::setup()
{
  // Actuals Pins for the sensors in esp32.
  // Last pin used twice because we cannot read 16 values so far.
  analog_pin_config = {36,39,34,35,32,33,25,26,27,14,12,13,4,2,15,15};

  bluetooth_connection.setup();
}

void Smoles::loop() {
  // for (int i = 0; i < 16; i++) {
  //   mux.setChannel(i);
  //   int value = analogRead(A0); // Analogue Pin for reading
  //   StaticJsonDocument<200> doc = JSONUtil::createJsonObject("sensor", value);
  //   serializeJson(doc, Serial);
  //   Serial.println();
  // }
  measure();

  if (use_json_output)
  {
    bluetooth_connection.notify(get_json_message());
  }
  else
  {
    bluetooth_connection.notify(get_csv_message());
  }
}

void Smoles::measure()
{
  for (int i = 0; i < analog_pin_config.size(); ++i)
  {
    measurement_values.at(i) = analogRead(analog_pin_config.at(i));
  }
}

const std::string Smoles::get_csv_message()
{
  std::string message;
  message = std::to_string(millis()) + ",left";
  
  for (int measurement_value : measurement_values)
  {
    message += "," + std::to_string(measurement_value);
  }

  return message;
}

const std::string Smoles::get_json_message()
{
  JsonDocument doc;
  doc["timeStamp"] = millis();
  doc["leftFoot"] = true;

  JsonArray sensorData = doc["sensorData"].to<JsonArray>();

  for (int value : measurement_values)
  {
    sensorData.add(value);
  }

  std::string message;
  serializeJson(doc, message);
  return message;
}
