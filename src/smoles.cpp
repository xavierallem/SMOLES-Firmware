#include <smoles.h>

#include "CD74HC4067.h"
#include "utils.h"

CD74HC4067 mux(5, 18, 19, 23 /*, 2*/); // Enabling pin is not connected currently

Smoles::Smoles(bool _use_json_output, bool _use_left_foot) : use_json_output(_use_json_output),
                                                             use_left_foot(_use_left_foot)
{
  measurement_values = std::vector<int>(16, 0);
  labeling_value = 0;
}

void Smoles::setup()
{
  // Actuals Pins for the sensors in esp32.
  // Last pin used twice because we cannot read 16 values so far.
  // analog_pin_config = {36,39,34,35,32,33,25,26,27,14,12,13,4,2,15,15};
  // labeling_pin_config = 23;

  bluetooth_connection.setup();
}

void Smoles::loop() {
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
  // labeling_value = digitalRead(labeling_pin_config);
  for (int i = 0; i < analog_pin_config.size(); ++i)
  {
    // Direct read
    // measurement_values.at(i) = analogRead(analog_pin_config.at(i));

    // MUX read
    mux.setChannel(i);
    delay(1);
    measurement_values.at(i) = analogRead(4);
    delay(1);

    Serial.print(measurement_values.at(i));
    Serial.print(',');
  }
  Serial.println();
}

const std::string Smoles::get_csv_message()
{
  std::string message;
  if (use_left_foot)
  {
    message = std::to_string(millis()) + ",left," + std::to_string(labeling_value);
  }
  else
  {
    message = std::to_string(millis()) + ",right," + std::to_string(labeling_value);
  }
  
  for (int measurement_value : measurement_values)
  {
    message += "," + std::to_string(measurement_value);
  }

  return message;
}

const std::string Smoles::get_json_message()
{
  JsonDocument doc;
  doc["timeStamp"] = TimeUtil::getTime(initialTimestamp+(millis()/1000));
  doc["leftFoot"] = use_left_foot;
  doc["label"] = labeling_value;

  JsonArray sensorData = doc["sensorData"].to<JsonArray>();

  for (int value : measurement_values)
  {
    sensorData.add(value);
  }

  std::string message;
  serializeJson(doc, message);
  return message;
}
