#include <Pixy2.h>

// This is the main Pixy object
Pixy2 pixy;
int signature = 0;
int x = 0;
int y = 0;
unsigned int width = 0;
unsigned int height = 0;
unsigned int area = 0;
unsigned int newarea = 0;
int Xmin = 70;
int Xmax = 200;
int maxArea = 0;
int minArea = 0;
static int i = 0;

void setup() {
  Serial.begin(115200);
  pixy.init();
  Serial.println(F("Pixy2 Initialized"));
}

void loop() {
  scan();
  area = width * height;
  maxArea = area + 1000;
  minArea = area - 1000;
  delay(100);  // Add a small delay to make the output more readable
}

void scan() {
  uint16_t blocks;
  blocks = pixy.ccc.getBlocks();

  if (blocks > 0) {  // Check if at least one block was detected
    i = (i >= blocks) ? 0 : i; // Ensure 'i' is within the valid range
    signature = pixy.ccc.blocks[i].m_signature;
    x = pixy.ccc.blocks[i].m_x;
    y = pixy.ccc.blocks[i].m_y;
    width = pixy.ccc.blocks[i].m_width;
    height = pixy.ccc.blocks[i].m_height;

    // Print the values to the serial monitor
    Serial.print("Signature: ");
    Serial.println(signature);
    // Serial.print("X: ");
    // Serial.println(x);
    // Serial.print("Y: ");
    // Serial.println(y);
    // Serial.print("Width: ");
    // Serial.println(width);
    // Serial.print("Height: ");
    // Serial.println(height);
  } else {
    Serial.println(F("No blocks detected"));
    signature = 0;
  }
}
