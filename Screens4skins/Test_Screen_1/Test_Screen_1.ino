#include <SPI.h>
#include <TFT_eSPI.h> 
#include "image_Screen_Test_1_pixels.h"
#include "Free_Fonts.h"
#include <CD74HC4067.h>

TFT_eSPI tft = TFT_eSPI(); 

// --- CONFIGURACIÓN DE MULTIPLEXERS (BUS COMPARTIDO) ---
CD74HC4067 mux(0, 1, 2, 3); 

const int MUX_SIG_BTN_PIN = 4;  // Entrada Digital (Botones)
const int MUX_SIG_POT_PIN = 14; // Entrada Analógica (Pots/Joys)

// --- 1. LISTA DE ASIGNACIÓN DE CANALES (PADS) ---
// FILA 1
#define PAD_R1_C1_CH  12
#define PAD_R1_C2_CH  11
#define PAD_R1_C3_CH  4
#define PAD_R1_C4_CH  3
// FILA 2
#define PAD_R2_C1_CH  13
#define PAD_R2_C2_CH  10
#define PAD_R2_C3_CH  5
#define PAD_R2_C4_CH  2
// FILA 3
#define PAD_R3_C1_CH  14
#define PAD_R3_C2_CH  9
#define PAD_R3_C3_CH  6
#define PAD_R3_C4_CH  1
// FILA 4
#define PAD_R4_C1_CH  15
#define PAD_R4_C2_CH  8
#define PAD_R4_C3_CH  7
#define PAD_R4_C4_CH  0

// --- COLORES ---
#define COLOR_PAD_OFF 0x861   
#define COLOR_PAD_ON  0xE8EC  

// --- ESTRUCTURA PARA MAPEAR BOTONES ---
struct PadMapping {
  int channel; 
  int x;       
  int y;       
};

PadMapping pads[16] = {
  {PAD_R1_C1_CH, 193, 113}, {PAD_R1_C2_CH, 224, 113}, {PAD_R1_C3_CH, 255, 113}, {PAD_R1_C4_CH, 286, 113},
  {PAD_R2_C1_CH, 193, 144}, {PAD_R2_C2_CH, 224, 144}, {PAD_R2_C3_CH, 255, 144}, {PAD_R2_C4_CH, 286, 144},
  {PAD_R3_C1_CH, 193, 175}, {PAD_R3_C2_CH, 224, 175}, {PAD_R3_C3_CH, 255, 175}, {PAD_R3_C4_CH, 286, 175},
  {PAD_R4_C1_CH, 193, 206}, {PAD_R4_C2_CH, 224, 206}, {PAD_R4_C3_CH, 255, 206}, {PAD_R4_C4_CH, 286, 206}
};

// --- ARRAYS DE ESTADO PREVIO ---
int previousButtonState[16];   
int previousPotValues[16]; 

// --- VARIABLES DEL DISPLAY ---
int Enc_Val_1 = 0, Enc_Val_2 = 0, Enc_Val_3 = 0, Enc_Val_4 = 0;
int Joy_X_1 = 0, Joy_X_2 = 0, Joy_X_3 = 0;
int Joy_Y_1 = 0, Joy_Y_2 = 0, Joy_Y_3 = 0;
int Pot_Val_1 = 0, Pot_Val_2 = 0, Pot_Val_3 = 0, Pot_Val_4 = 0;
int Pot_Val_5 = 0, Pot_Val_6 = 0, Pot_Val_7 = 0, Pot_Val_8 = 0;

unsigned long previousMillis = 0;
const long interval = 1000; 

// --- FUNCIÓN DE DIBUJO OPTIMIZADA (4 CIFRAS) ---
void drawValue(const char* label, int value, int x, int y, uint16_t color) {
    tft.setTextColor(color, 0x861); // Color Texto, Color Fondo (clave para borrar)
    tft.setFreeFont(&FreeSans9pt7b);
    tft.setTextSize(1);
    
    // Formateamos el valor a 4 dígitos con ceros a la izquierda (ej. 0050, 1024)
    char formattedVal[6]; // Buffer para 4 dígitos + terminador nulo
    sprintf(formattedVal, "%04d", value);

    // Construimos el String final
    String textToPrint = String(label) + "-" + String(formattedVal);
    
    tft.drawString(textToPrint, x, y);
}

// Actualiza todos los valores (se usa al inicio setup)
void updateSensorValues() {
    // Pots
    drawValue("1", Pot_Val_1, 10, 112, 0xB72B); drawValue("2", Pot_Val_2, 10, 127, 0x8E25);
    drawValue("3", Pot_Val_3, 10, 142, 0xB72B); drawValue("4", Pot_Val_4, 10, 157, 0x8E25);
    drawValue("5", Pot_Val_5, 10, 172, 0xB72B); drawValue("6", Pot_Val_6, 10, 187, 0x8E25);
    drawValue("7", Pot_Val_7, 10, 202, 0xB72B); drawValue("8", Pot_Val_8, 10, 217, 0x8E25);
    // Joys
    drawValue("X1", Joy_X_1, 83, 117, 0xFC00); drawValue("Y1", Joy_Y_1, 83, 136, 0xFAC0);
    drawValue("X2", Joy_X_2, 83, 157, 0xFC00); drawValue("Y2", Joy_Y_2, 83, 176, 0xFAC0);
    drawValue("X3", Joy_X_3, 83, 197, 0xFC00); drawValue("Y3", Joy_Y_3, 83, 216, 0xFAC0);
    // Encoders (Estos siguen siendo contadores ficticios por ahora)
    drawValue("P1", Enc_Val_1, 10, 10, 0xD9F); drawValue("P2", Enc_Val_2, 10, 34, 0x378);
    drawValue("P3", Enc_Val_3, 10, 58, 0xD9F); drawValue("P4", Enc_Val_4, 10, 82, 0x378);
}

void drawScreen_1(void) {
    tft.pushImage(0, 0, 320, 240, image_Screen_Test_1_pixels);
    
    // Dibujar Pads iniciales
    for(int i=0; i<16; i++) {
       tft.fillRect(pads[i].x, pads[i].y, 24, 24, COLOR_PAD_OFF);
    }
    // Elementos estáticos
    uint16_t joyBtnColor = 0xFBC6;
    tft.fillRect(155, 198, 21, 28, joyBtnColor); tft.fillRect(155, 158, 21, 28, joyBtnColor);
    tft.fillRect(155, 118, 21, 28, joyBtnColor);
    uint16_t encBtnColor = 0xD9F;
    tft.fillRect(78, 10, 16, 16, encBtnColor); tft.fillRect(78, 34, 16, 16, encBtnColor);
    tft.fillRect(78, 58, 16, 16, encBtnColor); tft.fillRect(78, 82, 16, 16, encBtnColor);
    uint16_t ctrlBtnColor = 0xFF6C;
    tft.fillRect(117, 53, 17, 17, ctrlBtnColor); tft.fillRect(143, 53, 17, 17, ctrlBtnColor);
    tft.fillRect(169, 53, 17, 17, ctrlBtnColor); tft.fillRect(195, 53, 17, 17, ctrlBtnColor);
    tft.fillRect(221, 53, 17, 17, ctrlBtnColor);
    tft.fillRect(143, 79, 17, 17, ctrlBtnColor); tft.fillRect(169, 79, 17, 17, ctrlBtnColor);
    tft.fillRect(195, 79, 17, 17, ctrlBtnColor); tft.fillRect(221, 79, 17, 17, ctrlBtnColor);

    updateSensorValues();
}

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(1); 
  
  drawScreen_1();

  pinMode(MUX_SIG_BTN_PIN, INPUT_PULLUP);
  pinMode(MUX_SIG_POT_PIN, INPUT); 

  // Inicializar estados previos
  for (int i = 0; i < 16; i++) {
    previousButtonState[i] = HIGH; 
    previousPotValues[i] = -100; // Valor imposible para forzar actualización inicial
  }
}

void loop() {
  // --- LÓGICA DE MULTIPLEXORES ---
  for (int i = 0; i < 16; i++) {
    
    // Seleccionar Canal en ambos Mux
    mux.channel(i);
    delayMicroseconds(10); 
    
    // --- 1. LECTURA DE BOTONES ---
    int btnVal = digitalRead(MUX_SIG_BTN_PIN);
    
    if (btnVal != previousButtonState[i]) {
      previousButtonState[i] = btnVal;
      
      // Buscar qué pad visual corresponde a este canal
      for(int k=0; k<16; k++) {
        if(pads[k].channel == i) {
          if (btnVal == LOW) { // Oprimido
            Serial.print("Pad "); Serial.print(k); Serial.println(" ON");
            tft.fillRect(pads[k].x, pads[k].y, 24, 24, COLOR_PAD_ON);
          } else { // Soltado
            Serial.print("Pad "); Serial.print(k); Serial.println(" OFF");
            tft.fillRect(pads[k].x, pads[k].y, 24, 24, COLOR_PAD_OFF);
          }
          break; 
        }
      }
    }

    // --- 2. LECTURA DE POTENCIÓMETROS (Canales 0 a 13) ---
    if (i <= 13) { 
      int potVal = analogRead(MUX_SIG_POT_PIN);
      
      // Filtro de ruido (> 5 unidades)
      if (abs(potVal - previousPotValues[i]) > 5) {
        previousPotValues[i] = potVal;

        // Mostrar en Serial (formateado visualmente también en serial si deseas)
        char bufSerial[30];
        sprintf(bufSerial, "Canal analogico %d - %04d", i, potVal);
        Serial.println(bufSerial);

        // Actualizar variables y Display INMEDIATAMENTE
        switch(i) {
          // --- POTENCIÓMETROS VERDES (0-7) ---
          case 0: Pot_Val_1 = potVal; drawValue("1", potVal, 10, 112, 0xB72B); break;
          case 1: Pot_Val_2 = potVal; drawValue("2", potVal, 10, 127, 0x8E25); break;
          case 2: Pot_Val_3 = potVal; drawValue("3", potVal, 10, 142, 0xB72B); break;
          case 3: Pot_Val_4 = potVal; drawValue("4", potVal, 10, 157, 0x8E25); break;
          case 4: Pot_Val_5 = potVal; drawValue("5", potVal, 10, 172, 0xB72B); break;
          case 5: Pot_Val_6 = potVal; drawValue("6", potVal, 10, 187, 0x8E25); break;
          case 6: Pot_Val_7 = potVal; drawValue("7", potVal, 10, 202, 0xB72B); break;
          case 7: Pot_Val_8 = potVal; drawValue("8", potVal, 10, 217, 0x8E25); break;

          // --- JOYSTICKS (8-13) ---
          case 8:  Joy_X_1 = potVal; drawValue("X1", potVal, 83, 117, 0xFC00); break;
          case 9:  Joy_Y_1 = potVal; drawValue("Y1", potVal, 83, 136, 0xFAC0); break;
          case 10: Joy_X_2 = potVal; drawValue("X2", potVal, 83, 157, 0xFC00); break;
          case 11: Joy_Y_2 = potVal; drawValue("Y2", potVal, 83, 176, 0xFAC0); break;
          case 12: Joy_X_3 = potVal; drawValue("X3", potVal, 83, 197, 0xFC00); break;
          case 13: Joy_Y_3 = potVal; drawValue("Y3", potVal, 83, 216, 0xFAC0); break;
        }
      }
    }
  }

  // --- LÓGICA DE SENSORES FICTICIOS RESTANTES (Encoders) ---
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    Enc_Val_1++; Enc_Val_2++; Enc_Val_3++; Enc_Val_4++;

    // La función drawValue ya aplica el formato 0000 automáticamente aquí también
    drawValue("P1", Enc_Val_1, 10, 10, 0xD9F);
    drawValue("P2", Enc_Val_2, 10, 34, 0x378);
    drawValue("P3", Enc_Val_3, 10, 58, 0xD9F);
    drawValue("P4", Enc_Val_4, 10, 82, 0x378);
  }
}