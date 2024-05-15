#ifndef SMOLES_BLUETOOTH_CONNECTION_H
#define SMOLES_BLUETOOTH_CONNECTION_H

#include "smoles.h"

class BluetoothConnection
{
  private:
    BLECharacteristic *characteristicTX;

  public:
    void setup();
    void notify(const char *message);

};

#endif
