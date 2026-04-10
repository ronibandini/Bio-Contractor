// Calibrarion Script
// Use this script to check pot max-min

// --- PIN 
#define POT_HAT    A1 
#define POT_KICK   A2
#define POT_SNARE  A3
#define POT_SHAPE  A4 
#define POT_BPM    A5
#define SW_PLAY    12
#define SW_TRIG    11

// Potentiometer Min/Max Trackers
int potMin[5] = {16383, 16383, 16383, 16383, 16383};
int potMax[5] = {0, 0, 0, 0, 0};
int potPins[5] = {POT_HAT, POT_KICK, POT_SNARE, POT_SHAPE, POT_BPM};
const char* potNames[5] = {"HAT", "KICK", "SNARE", "SHAPE", "BPM"};

// Switch State Trackers
bool d2_saw_high = false;
bool d2_saw_low  = false;
bool d3_saw_high = false;
bool d3_saw_low  = false;

void setup() {
  Serial.begin(115200);
  while (!Serial); 

  // Explicitly setting input pullup
  pinMode(SW_PLAY, INPUT_PULLUP);
  pinMode(SW_TRIG, INPUT_PULLUP);

  Serial.println("--- Bio Contractor Calibration Roni Bandini 4/2026---");
}

void loop() {
  Serial.println("\n--- NEW READ CYCLE ---");

  // 1. Potentiometer Logic (Real-time + Permanent High/Low)
  for (int i = 0; i < 5; i++) {
    int val = analogRead(potPins[i]);
    if (val < potMin[i]) potMin[i] = val;
    if (val > potMax[i]) potMax[i] = val;

    Serial.print(potNames[i]);
    Serial.print(": "); Serial.print(val);
    Serial.print(" [Min: "); Serial.print(potMin[i]);
    Serial.print(" Max: "); Serial.print(potMax[i]);
    Serial.println("]");
  }

  // 2. Switch Logic
  int d2 = digitalRead(SW_PLAY);
  int d3 = digitalRead(SW_TRIG);

  if (d2 == 1) d2_saw_high = true;
  if (d2 == LOW)  d2_saw_low  = true;
  if (d3 == 1) d3_saw_high = true;
  if (d3 == LOW)  d3_saw_low  = true;


  // 3. Status Report
  Serial.print("BUTTON D2 -> Current: "); 
  Serial.print(d2 == LOW ? "LOW (GND)" : "HIGH (VCC)");
  Serial.print(" | Ever LOW: "); Serial.print(d2_saw_low ? "YES" : "NO");
  Serial.print(" | Ever HIGH: "); Serial.println(d2_saw_high ? "YES" : "NO");

  Serial.print("BUTTON D3 -> Current: "); 
  Serial.print(d3 == LOW ? "LOW (GND)" : "HIGH (VCC)");
  Serial.print(" | Ever LOW: "); Serial.print(d3_saw_low ? "YES" : "NO");
  Serial.print(" | Ever HIGH: "); Serial.println(d3_saw_high ? "YES" : "NO");

  delay(500); 
}