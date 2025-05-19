#include <Arduino.h>

#define FLOW_PIN 18 

volatile uint32_t pulseCount = 0;   

void IRAM_ATTR onFlow() {         
  pulseCount++;
}

void setup() {
  Serial.begin(115200);
  pinMode(FLOW_PIN, INPUT_PULLUP);                 
  attachInterrupt(digitalPinToInterrupt(FLOW_PIN),
                  onFlow,
                  FALLING);

  Serial.println(F("\nContador de pulsos iniciado"));
}

void loop() {
  static uint32_t lastPrint = 0;
  uint32_t now = millis();

  if (now - lastPrint >= 1000) {
    noInterrupts();              
    uint32_t pulses = pulseCount;
    interrupts();

    Serial.printf("Pulsos acumulados: %lu\n", pulses);
    lastPrint = now;
  }

}
