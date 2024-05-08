#ifndef SMOLES_BLUETOOTH_CONNECTION_H
#define SMOLES_BLUETOOTH_CONNECTION_H

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>

class BluetoothConnection
{
  private:
    BLECharacteristic *characteristicTX;

  public:
    void setup();
    void notify(const char *message);

};

#endif
