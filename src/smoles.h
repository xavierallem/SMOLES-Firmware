#ifndef SMOLES_H
#define SMOLES_H

#include <Arduino.h>
#include <ArduinoJson.h>

#include <BluetoothConnection.h>
#include <Constants.h>

class Smoles
{
public:
    Smoles(bool _use_json_output);
    void setup();
    void loop();
private:
    void measure();
    const std::string get_csv_message();
    const std::string get_json_message();

    BluetoothConnection bluetooth_connection;
    std::vector<int> measurement_values;
    int labeling_value;

    std::array<int, 16> analog_pin_config;
    int labeling_pin_config;
    bool use_json_output;
};

#endif