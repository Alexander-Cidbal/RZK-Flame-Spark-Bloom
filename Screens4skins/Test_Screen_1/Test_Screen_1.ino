#include <SPI.h>
#include <TFT_eSPI.h> 
#include "image_Screen_Test_1_pixels.h"
#include "Free_Fonts.h"

TFT_eSPI tft = TFT_eSPI(); 

// --- 1. Variables convertidas a int (Total: 18) ---
int Enc_Val_1 = 0;     // Original: "P1-000"
int Enc_Val_2 = 0;     // Original: "P2-000"
int Enc_Val_3 = 0;     // Original: "P3-000"
int Enc_Val_4 = 0;     // Original: "P4-000"

int Joy_X_1 = 1024;    // Original: "X1-1024"
int Joy_X_2 = 1024;    // Original: "X2-1024"
int Joy_X_3 = 1024;    // Original: "X3-1024"

int Joy_Y_1 = 1024;    // Original: "Y1-1024"
int Joy_Y_2 = 1024;    // Original: "Y2-1024"
int Joy_Y_3 = 1024;    // Original: "Y3-1024"

int Pot_Val_1 = 1024;  // Original: "1-1024"
int Pot_Val_2 = 1024;  // Original: "2-1024"
int Pot_Val_3 = 1024;  // Original: "3-1024"
int Pot_Val_4 = 1024;  // Original: "4-1024"
int Pot_Val_5 = 1024;  // Original: "5-1024"
int Pot_Val_6 = 1024;  // Original: "6-1024"
int Pot_Val_7 = 1024;  // Original: "7-1024"
int Pot_Val_8 = 1024;  // Original: "8-1024"

// Variable para el control del tiempo (cada segundo)
unsigned long previousMillis = 0;
const long interval = 1000; 

// --- Función Auxiliar para dibujar texto dinámico ---
// Dibuja la etiqueta + el valor int. 
// Usa TFT_BLACK como fondo del texto para "borrar" el valor anterior automáticamente.
void drawValue(const char* label, int value, int x, int y, uint16_t color) {
    tft.setTextColor(color, 0x861); // Color texto, Color fondo (para borrar el previo)
    tft.setFreeFont(&FreeSans9pt7b);
    tft.setTextSize(1);
    
    // Construimos el String: "Etiqueta" + "-" + "Valor"
    String textToPrint = String(label) + "-" + String(value);
    
    // Convertimos a char array para drawString
    tft.drawString(textToPrint, x, y);
}

// --- Función para actualizar SOLO los valores ---
void updateSensorValues() {
    // Pot_Val_1 a 8
    drawValue("1", Pot_Val_1, 10, 112, 0xB72B);
    drawValue("2", Pot_Val_2, 10, 127, 0x8E25);
    drawValue("3", Pot_Val_3, 10, 142, 0xB72B);
    drawValue("4", Pot_Val_4, 10, 157, 0x8E25);
    drawValue("5", Pot_Val_5, 10, 172, 0xB72B);
    drawValue("6", Pot_Val_6, 10, 187, 0x8E25);
    drawValue("7", Pot_Val_7, 10, 202, 0xB72B);
    drawValue("8", Pot_Val_8, 10, 217, 0x8E25);

    // Joy_X y Joy_Y
    drawValue("X1", Joy_X_1, 83, 117, 0xFC00);
    drawValue("Y1", Joy_Y_1, 83, 132, 0xFAC0);
    drawValue("X2", Joy_X_2, 83, 157, 0xFC00);
    drawValue("Y2", Joy_Y_2, 83, 172, 0xFAC0);
    drawValue("X3", Joy_X_3, 83, 197, 0xFC00);
    drawValue("Y3", Joy_Y_3, 83, 212, 0xFAC0);

    // Enc_Val_1 a 4
    drawValue("P1", Enc_Val_1, 10, 10, 0xD9F);
    drawValue("P2", Enc_Val_2, 10, 34, 0x378);
    drawValue("P3", Enc_Val_3, 10, 58, 0xD9F);
    drawValue("P4", Enc_Val_4, 10, 82, 0x378);
}

void drawScreen_1(void) {
    // 1. Dibujar Imagen de Fondo y Elementos Estáticos
    tft.pushImage(0, 0, 320, 240, image_Screen_Test_1_pixels);
    
    // Pads (Cuadrados estáticos)
    uint16_t padColor = 0xE8EC;
    // Fila 1
    tft.fillRect(193, 113, 24, 24, padColor);
    tft.fillRect(224, 113, 24, 24, padColor);
    tft.fillRect(255, 113, 24, 24, padColor);
    tft.fillRect(286, 113, 24, 24, padColor);
    // Fila 2
    tft.fillRect(193, 144, 24, 24, padColor);
    tft.fillRect(224, 144, 24, 24, padColor);
    tft.fillRect(255, 144, 24, 24, padColor);
    tft.fillRect(286, 144, 24, 24, padColor);
    // Fila 3
    tft.fillRect(193, 175, 24, 24, padColor);
    tft.fillRect(224, 175, 24, 24, padColor);
    tft.fillRect(255, 175, 24, 24, padColor);
    tft.fillRect(286, 175, 24, 24, padColor);
    // Fila 4
    tft.fillRect(193, 206, 24, 24, padColor);
    tft.fillRect(224, 206, 24, 24, padColor);
    tft.fillRect(255, 206, 24, 24, padColor);
    tft.fillRect(286, 206, 24, 24, padColor);

    // Botones Joy (Estáticos)
    uint16_t joyBtnColor = 0xFBC6;
    tft.fillRect(155, 198, 21, 28, joyBtnColor);
    tft.fillRect(155, 158, 21, 28, joyBtnColor);
    tft.fillRect(155, 118, 21, 28, joyBtnColor);

    // Botones Encoder (Estáticos)
    uint16_t encBtnColor = 0xD9F;
    tft.fillRect(78, 10, 16, 16, encBtnColor);
    tft.fillRect(78, 34, 16, 16, encBtnColor);
    tft.fillRect(78, 58, 16, 16, encBtnColor);
    tft.fillRect(78, 82, 16, 16, encBtnColor);

    // Botones Ctrl (Estáticos)
    uint16_t ctrlBtnColor = 0xFF6C;
    // Fila superior
    tft.fillRect(117, 53, 17, 17, ctrlBtnColor);
    tft.fillRect(143, 53, 17, 17, ctrlBtnColor);
    tft.fillRect(169, 53, 17, 17, ctrlBtnColor);
    tft.fillRect(195, 53, 17, 17, ctrlBtnColor);
    tft.fillRect(221, 53, 17, 17, ctrlBtnColor);
    // Fila inferior
    tft.fillRect(143, 79, 17, 17, ctrlBtnColor);
    tft.fillRect(169, 79, 17, 17, ctrlBtnColor);
    tft.fillRect(195, 79, 17, 17, ctrlBtnColor);
    tft.fillRect(221, 79, 17, 17, ctrlBtnColor);

    // 2. Dibujar los valores iniciales
    updateSensorValues();
}

void setup() {
  Serial.begin(115200);
  
  tft.init();
  tft.setRotation(1); 
  
  // Dibujamos la interfaz estática y los valores iniciales
  drawScreen_1();
}

void loop() {
  unsigned long currentMillis = millis();

  // Comprueba si ha pasado 1 segundo (1000 ms)
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // 1. Sumar 1 unidad a todas las variables
    Enc_Val_1++; Enc_Val_2++; Enc_Val_3++; Enc_Val_4++;
    Joy_X_1++; Joy_X_2++; Joy_X_3++;
    Joy_Y_1++; Joy_Y_2++; Joy_Y_3++;
    Pot_Val_1++; Pot_Val_2++; Pot_Val_3++; Pot_Val_4++;
    Pot_Val_5++; Pot_Val_6++; Pot_Val_7++; Pot_Val_8++;

    // 2. Actualizar SOLO las zonas de texto en pantalla
    updateSensorValues();
  }
}