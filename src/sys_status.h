#ifndef SYS_STATUS_H
#define SYS_STATUS_H

struct systemStatus_structure {                     // currently 14 bytes long
  uint8_t structuresVersion;                        // Version of the data structures (system and data)
  uint8_t placeholder;                              // available for future use
  bool clockSet;                                    // Tells us if we need to connect and set the RTC
  uint8_t connectedStatus;
  uint8_t verboseMode;
  uint8_t solarPowerMode;
  uint8_t lowPowerMode; // bool?
  uint8_t lowBatteryMode;
  int stateOfCharge;                                // Battery charge level
  uint8_t batteryState;                             // Stores the current battery state
  int resetCount;                                   // reset count of device (0-256)
  float timezone;                                   // Time zone value -12 to +12
  float dstOffset;                                  // How much does the DST value change?
  int openTime;                                     // Hour the park opens (0-23)
  int closeTime;                                    // Hour the park closes (0-23)
  unsigned long lastHookResponse;                   // Last time we got a valid Webhook response
  uint8_t sensorType;                               // What is the sensor type - 0-Pressure Sensor, 1-PIR Sensor
};

extern struct systemStatus_structure sysStatus;

extern bool systemStatusWriteNeeded;               // Keep track of when we need to write

#endif
