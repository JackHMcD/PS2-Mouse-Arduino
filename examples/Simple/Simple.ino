/**
 * Reads X/Y values from a PS/2 mouse connected to an Arduino
 * using the PS2Mouse library available from
 *   http://github.com/kristopher/PS2-Mouse-Arduino/
 * Original by Kristopher Chambers <kristopher.chambers@gmail.com>
 * Updated by Jonathan Oxer <jon@oxer.com.au>
 */

#include <PS2Mouse.h>
#define MOUSE_DATA 4
#define MOUSE_CLOCK 3

PS2Mouse mouse(MOUSE_CLOCK, MOUSE_DATA, STREAM);

/**
 * Setup
 */
void setup()
{
  Serial.begin(9600);
  mouse.initialize();
}

/**
 * Main program loop
 */
void loop()
{
  delay(100);
  int16_t data[3];
  mouse.report(data);
  Serial.print(data[0]); // Status Byte
  Serial.print(":");
  Serial.print(data[1]); // X Movement Data
  Serial.print(",");
  Serial.print(data[2]); // Y Movement Data
  Serial.print(",");
  Serial.print(data[3]); // X Absolute Data
  Serial.print(",");
  Serial.print(data[4]); // Y Absolute Data
  Serial.print(",");
  Serial.print(data[5]); // Z Absolute Data
  Serial.println();
}
