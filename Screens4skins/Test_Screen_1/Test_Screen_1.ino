#include <SPI.h>
#include <TFT_eSPI.h> 
#include "image_Screen_Test_1_pixels.h"
// Incluimos la fuente. 
// NOTA: Asegúrate de que LOAD_GFXFF está descomentado en tu User_Setup.h
#include <TFT_eSPI.h> 
#include "Free_Fonts.h"
//#include <Fonts/FreeSans9pt7b.h> // La ruta estándar en la librería

TFT_eSPI tft = TFT_eSPI(); 

const char* Joy_X_1_text = "X1-1024";
const char* Joy_Y_1_text = "X1-1024";
const char* Pot_Val_1_text = "1-1024";
const char* Pot_Val_2_text = "2-1024";
const char* Pot_Val_3_text = "3-1024";
const char* Pot_Val_4_text = "4-1024";
const char* Pot_Val_5_text = "5-1024";
const char* Pot_Val_6_text = "6-1024";
const char* Pot_Val_7_text = "7-1024";
const char* Pot_Val_8_text = "8-1024";


void drawScreen_1(void) {
    // Screen_Test_1
    tft.pushImage(0, 0, 320, 240, image_Screen_Test_1_pixels);
    // Button_1
    tft.fillRect(193, 113, 24, 24, 0xFBC6);
    // Button_2
    tft.fillRect(224, 113, 24, 24, 0x10A2);
    // Pot_Val_1
    tft.setTextColor(0xB72B);
    tft.setTextSize(1);
    tft.setFreeFont(&FreeSans9pt7b);
    tft.drawString(Pot_Val_1_text, 10, 112);
    // Pot_Val_2
    tft.setTextColor(0x8E25);
    tft.drawString(Pot_Val_2_text, 10, 127);
    // Pot_Val_3
    tft.setTextColor(0xB72B);
    tft.drawString(Pot_Val_3_text, 10, 142);
    // Pot_Val_4
    tft.setTextColor(0x8E25);
    tft.drawString(Pot_Val_4_text, 10, 157);
    // Pot_Val_5
    tft.setTextColor(0xB72B);
    tft.drawString(Pot_Val_5_text, 9, 172);
    // Pot_Val_6
    tft.setTextColor(0x8E25);
    tft.drawString(Pot_Val_6_text, 10, 187);
    // Pot_Val_7
    tft.setTextColor(0xB72B);
    tft.drawString(Pot_Val_7_text, 10, 202);
    // Pot_Val_8
    tft.setTextColor(0x8E25);
    tft.drawString(Pot_Val_8_text, 10, 217);
    // Pot_Val_1 copy 1
    tft.setTextColor(0xD9F);
    tft.drawString("1-1024", 9, 69);
    // Pot_Val_2 copy 1
    tft.setTextColor(0x378);
    tft.drawString("2-1024", 9, 84);
    // Joy_X_1
    tft.setTextColor(0xFC00);
    tft.drawString(Joy_X_1_text, 83, 117);
    // Joy_Y_1
    tft.setTextColor(0xFAC0);
    tft.drawString(Joy_Y_1_text, 83, 132);
    // Joy_X_1 copy 1
    tft.setTextColor(0xFC00);
    tft.drawString("X1-1024", 83, 157);
    // Joy_Y_1 copy 1
    tft.setTextColor(0xFAC0);
    tft.drawString("X1-1024", 83, 172);
    // Joy_X_1 copy 2
    tft.setTextColor(0xFC00);
    tft.drawString("X1-1024", 83, 197);
    // Joy_Y_1 copy 2
    tft.setTextColor(0xFAC0);
    tft.drawString("X1-1024", 83, 212);
    // Button_1 copy 2
    tft.fillRect(155, 158, 21, 28, 0xFBC6);
    // Button_1 copy 1
    tft.fillRect(155, 118, 21, 28, 0xFBC6);
    // Button_1 copy 3
    tft.fillRect(155, 198, 21, 28, 0xFBC6);
}





void setup() {
  Serial.begin(115200);
  
  tft.init();
  tft.setRotation(1); // Ajusta esto (0-3) según como tengas puesta la pantalla
  
  // Dibujamos la interfaz una sola vez al inicio
  drawScreen_1();
}

void loop() {
  // Aquí iría la lógica para leer tus potenciómetros
  // y actualizar SOLO los números, no toda la pantalla.
}