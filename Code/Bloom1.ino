#include <Control_Surface.h>

//interfaz de depuración para ver los mensajes en el Serial Monitor (115200 baudios)
//USBDebugMIDI_Interface midi;
USBMIDI_Interface midi;

// Multiplexor 1: Keyswitches (SIG en pin 4)
CD74HC4067 muxKeyswitches {4, {0, 1, 2, 3}};

// Multiplexor 2: Analógico (SIG en pin 14)
CD74HC4067 muxAnalog {14, {0, 1, 2, 3}};

// Arreglo de keyswitches (ruteo físico optimizado y la octava C3)
NoteButton buttons[] = {
  {muxKeyswitches.pin(15), {MIDI_Notes::C(3), Channel_1}},  
  {muxKeyswitches.pin(8),  {MIDI_Notes::Db(3), Channel_1}}, 
  {muxKeyswitches.pin(7),  {MIDI_Notes::D(3), Channel_1}},  
  {muxKeyswitches.pin(0),  {MIDI_Notes::Eb(3), Channel_1}}, 
  
  {muxKeyswitches.pin(14), {MIDI_Notes::E(3), Channel_1}},  
  {muxKeyswitches.pin(9),  {MIDI_Notes::F_(3), Channel_1}}, 
  {muxKeyswitches.pin(6),  {MIDI_Notes::Gb(3), Channel_1}}, 
  {muxKeyswitches.pin(1),  {MIDI_Notes::G(3), Channel_1}},  
  
  {muxKeyswitches.pin(13), {MIDI_Notes::Ab(3), Channel_1}}, 
  {muxKeyswitches.pin(10), {MIDI_Notes::A(3), Channel_1}},  
  {muxKeyswitches.pin(5),  {MIDI_Notes::Bb(3), Channel_1}}, 
  {muxKeyswitches.pin(2),  {MIDI_Notes::B(3), Channel_1}},  
  
  {muxKeyswitches.pin(12), {MIDI_Notes::C(4), Channel_1}},  
  {muxKeyswitches.pin(11), {MIDI_Notes::Db(4), Channel_1}}, 
  {muxKeyswitches.pin(4),  {MIDI_Notes::D(4), Channel_1}},  
  {muxKeyswitches.pin(3),  {MIDI_Notes::Eb(4), Channel_1}}  
};

// Arreglo de entradas analógicas (Potenciómetros y Joysticks)
// Envían mensajes Control Change (CC) en el Canal 1.
CCPotentiometer potentiometers[] = {
  {muxAnalog.pin(0), {16, Channel_1}}, // Joystick/Pot 1 -> CC 16
  {muxAnalog.pin(1), {17, Channel_1}}, // Joystick/Pot 2 -> CC 17
  {muxAnalog.pin(2), {18, Channel_1}}, // Joystick/Pot 3 -> CC 18
  {muxAnalog.pin(3), {19, Channel_1}}, // Joystick/Pot 4 -> CC 19
  {muxAnalog.pin(4), {20, Channel_1}},
  {muxAnalog.pin(5), {21, Channel_1}},
  {muxAnalog.pin(6), {22, Channel_1}},
  {muxAnalog.pin(7), {23, Channel_1}},
  {muxAnalog.pin(8), {24, Channel_1}},
  {muxAnalog.pin(9), {25, Channel_1}},
  {muxAnalog.pin(10), {26, Channel_1}},
  {muxAnalog.pin(11), {27, Channel_1}},
  {muxAnalog.pin(12), {28, Channel_1}},
  {muxAnalog.pin(13), {29, Channel_1}},
  {muxAnalog.pin(14), {30, Channel_1}},
  {muxAnalog.pin(15), {31, Channel_1}} // Joystick/Pot 16 -> CC 31
};

void setup() {
  Control_Surface.begin();
}

void loop() {
  Control_Surface.loop();
}