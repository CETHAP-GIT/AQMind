/*
 * AQMind – Monitor de Nível e Fluxo d’Água
 * ESP32 + HC-SR04 + YF-S201
 * Autor: ChatGPT (OpenAI) – 19 mai 2025
 */

#include <Arduino.h>

/* ---------- PINAGEM ---------- */
const int PIN_TRIG  = 5;
const int PIN_ECHO  = 18;  // via divisor resistivo
const int PIN_FLUXO = 19;

/* ---------- TANQUE ---------- */
const float ALTURA_TANQUE_CM = 120.0;   // altura total
const float AREA_BASE_CM2    = 7850.0;  // área da base

/* ---------- SENSOR DE FLUXO ---------- */
const float K_FACTOR = 450.0;  // <= substitua pelo valor calibrado!
volatile unsigned long pulsosFluxo = 0;
float vazaoLmin = 0.0;
float volumeConsumido = 0.0;

/* ---------- VARIÁVEIS DE NÍVEL ---------- */
float nivelAguaCm   = 0.0;
float quantidadeAguaL = 0.0;

/* ---------- PROTÓTIPOS ---------- */
void IRAM_ATTR contaPulso();
float medeDistancia();
void atualizaVolume();

/* ============================== */
void setup() {
  Serial.begin(115200);

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  pinMode(PIN_FLUXO, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_FLUXO), contaPulso, RISING);

  Serial.println(F("\nAQMind iniciado."));
}

void loop() {

  /* 1) NÍVEL */
  nivelAguaCm = medeDistancia();
  atualizaVolume();

  /* 2) FLUXO */
  static unsigned long tPrevFluxo = 0;
  unsigned long agora = millis();
  unsigned long dt = agora - tPrevFluxo;
  if (dt >= 1000) {                        // janela de 1 s
    noInterrupts();
    unsigned long p = pulsosFluxo;
    pulsosFluxo = 0;
    interrupts();

    vazaoLmin       = (p / K_FACTOR) * (60000.0 / dt);
    volumeConsumido += (p / K_FACTOR);

    tPrevFluxo = agora;
  }

  /* 3) SERIAL */
  static unsigned long tPrevPrint = 0;
  if (agora - tPrevPrint >= 5000) {        // a cada 5 s
    Serial.printf("Nível: %.1f cm | Água no tanque: %.1f L\n",
                  nivelAguaCm, quantidadeAguaL);
    Serial.printf("Vazão: %.2f L/min | Volume consumido: %.2f L\n\n",
                  vazaoLmin, volumeConsumido);
    tPrevPrint = agora;
  }
}

/* ---------- ISR fluxo ---------- */
void IRAM_ATTR contaPulso() { pulsosFluxo++; }

/* ---------- Medição ultrassônica ---------- */
float medeDistancia() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(3);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  long dur = pulseIn(PIN_ECHO, HIGH, 25000);       // timeout 25 ms
  if (dur == 0) return NAN;                         // sem eco
  return (dur / 2.0) * 0.0343;                      // µs → cm
}

/* ---------- Cálculo de volume ---------- */
void atualizaVolume() {
  if (isnan(nivelAguaCm) || nivelAguaCm > ALTURA_TANQUE_CM) {
    quantidadeAguaL = 0;
    return;
  }
  float coluna = ALTURA_TANQUE_CM - nivelAguaCm;    // cm
  quantidadeAguaL = (AREA_BASE_CM2 * coluna) / 1000.0;  // cm³→L
}
