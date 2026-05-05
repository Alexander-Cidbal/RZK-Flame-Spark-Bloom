Traducción: [English](README.md)
<div align="center">
  <img src="https://i.imgur.com/8T0b9uv.png" alt="Vista Frontal" height="300">
  <img src="https://i.imgur.com/PClQnu1.png" alt="Vista en Perspectiva" height="300">
  
  <p><em>Imágenes conceptuales renderizadas en Blender (¡Fotos del instrumento real PRÓXIMAMENTE!) </em></p>

  # RZK Flame Spark Bloom (FS-B1)

  ![Estado](https://img.shields.io/badge/Estado-Desarrollo_Temprano-%23b1fc03)
  ![Versión](https://img.shields.io/badge/Versi%C3%B3n-0.0.0-orange)
  ![Hardware](https://img.shields.io/badge/Hardware-Teensy_4.1-blue)

[![Licencia: CC BY-NC-SA 4.0](https://licensebuttons.net/l/by-nc-sa/4.0/80x15.png)](https://creativecommons.org/licenses/by-nc-sa/4.0/)
Esta obra está bajo una [Licencia Internacional Creative Commons Atribución-NoComercial-CompartirIgual 4.0](https://creativecommons.org/licenses/by-nc-sa/4.0/).

  ---

## ⚠️❗¡Atención! Este proyecto se encuentra en una etapa temprana de desarrollo. Muchas cosas todavía se están planificando y pueden (y van a) cambiar sin previo aviso. El código fuente está en desarrollo y se subirá PRÓXIMAMENTE.

  <p>
    Un sampler DIY basado en la placa de desarrollo Teensy 4.1, enfocado en la creación de ritmos (beatmaking), muestreo (sampling) y producción de música en vivo.
  </p>
</div>

---

## 📋 Contenido

1. [Acerca de](#-acerca-de)
2. [Características](#-características)
3. [Componentes](#-componentes)
4. [Tecnologías](#-tecnologías)
5. [Instrucciones](#-instrucciones)
6. [Hoja de Ruta](#-hoja-de-ruta)
7. [Licencia](#-licencia)

---

## 📖 Acerca de

Este proyecto nació de tres de mis grandes pasiones: **el beatmaking, la electrónica y el diseño**. 

Actualmente, existen muchas alternativas de hardware que sirven para propósitos similares (como la SP-404 o las MPC), pero casi ninguna de ellas es verdaderamente de código abierto. Este proyecto busca cerrar esa brecha con la siguiente filosofía:

- **Código Abierto (Open Source):** El código y los diagramas esquemáticos están disponibles para que cualquiera pueda experimentar, modificar y reinventar su propia máquina.
- **Económico (Budget Friendly):** Diseñado utilizando componentes fáciles de encontrar en tiendas de electrónica estándar (excepto por la placa Teensy, disponible en Sparkfun o distribuidores similares).
- **Carcasa DIY:** La carcasa está diseñada para ser adaptable. Puedes usar cualquier recipiente de plástico o imprimir el tuyo en 3D, siempre y cuando tengas las herramientas para cortar y perforar.
- **Expandible:** ¡Las modificaciones son bienvenidas! Valoro mucho los comentarios de las comunidades de beatmaking, electrónica y *makers*. 

---

## 🎛 Características

### Hardware
- **16 Interruptores Mecánicos:** Usados para *finger drumming* y presentaciones en vivo. Elegí interruptores de teclas mecánicas (estilo Cherry MX) por esa sensación táctil de clic y su durabilidad.
- **8 Potenciómetros:** Para el control en tiempo real de efectos, volumen y parámetros.
- **4 Encoders:** Encoders rotativos infinitos con pulsador (switch) para control de envolvente ADSR, navegación por menús y ajuste fino de valores.
- **4 Joysticks:** ¿Por qué no hacerlo divertido y expresivo? Asigna valores a los ejes X e Y para manipular efectos mientras tocas en vivo, además de un pulsador integrado en cada uno.
- **8 Botones de Función:** Controles del sistema que incluyen "Spark", "Shift" y atajos.

### Software (Planeado)
- **Salida USB-MIDI:** Úsalo como un controlador MIDI potente y expresivo para presentaciones en vivo o sesiones de estudio.
- **Reproducción de Samples:** Disparo de baja latencia desde tarjeta SD y memoria RAM.
- **Secuenciador:** Secuenciador por pasos y grabación en vivo.
- **Efectos:** Implementación de Reverb, Delay y Bitcrusher.

---

## 🔌 Componentes

Lista de los componentes principales utilizados en esta construcción:

* **1x**- Teensy 4.1
* **1x**- Teensy Audio Shield
* **1x**- Pantalla LCD OLED TFT de 2.0 pulgadas 
* **16x**- Interruptores Mecánicos Cherry MX
* **24x**- Teclas (Keycaps)
* **8x**- Potenciómetros B10k
* **4x**- Encoders rotativos con pulsador
* **4x**- Módulos de Joystick
* **8x**- Botones Pulsadores (o más interruptores mecánicos)
* **3x**- Módulo Breakout Multiplexor Digital de 16 canales CD74HC4067
* **1x**- Carcasa (Enclosure). Puedes usar recipientes de plástico, recipientes de metal, cajas recicladas, una carcasa impresa en 3D, o incluso hacer tu propia caja de cartón usando la plantilla en este repositorio. ¡Ponte creativo y haz algo increíble y original!

---

## 🛠 Tecnologías

Estoy utilizando las siguientes tecnologías y librerías. Muchas gracias a sus creadores y mantenedores:

* [Arduino IDE](https://www.arduino.cc/en/software/) - Entorno de desarrollo principal.
* [Teensy Audio Library](https://www.pjrc.com/teensy/td_libs_Audio.html) - El motor principal para el procesamiento de audio.
* [Control Surface](https://github.com/tttapa/Control-Surface) - Increíble librería para MIDI.
* [Cirkit](https://app.cirkitdesigner.com/) - Utilizado para la captura de esquemas y el diseño de circuitos.


---

## 🚀 Instrucciones

### **Ensamblaje y Cableado**
> 🚧 **Trabajo en Progreso:** Próximamente se publicarán diagramas de cableado detallados y una guía de ensamblaje. 
### Puedes ver los esquemas actuales [AQUÍ](https://i.imgur.com/oImRSiw.png).

El diagrama de cableado interactivo está alojado en Cirkit Designer. Dado que GitHub no permite incrustaciones interactivas, **haz clic en la imagen a continuación para abrir el visor interactivo**: 

<a href="https://app.cirkitdesigner.com/project/12ed71a3-bdbf-4b91-8f72-1112bf8fde8e?view=interactive_preview" target="_blank"> 
  <img src="https://i.imgur.com/5Yv8cYv.png" alt="Diagrama de Cableado Interactivo" width="100%"> 
</a> 

<p align="center">   
  <a href="https://app.cirkitdesigner.com/project/12ed71a3-bdbf-4b91-8f72-1112bf8fde8e" target="_blank">Editar en Cirkit Designer</a>
</p>


---

## 🗺 Hoja de Ruta

 - [x] **Soporte USB-MIDI**
 - [x] **Prototipo de cableado físico**
 - [x] **Diseño del circuito de alimentación (Soporte para batería)**
 - [ ] Pruebas de pantalla TFT para depuración de controles
 - [ ] Sistema de Audio Independiente (Standalone)
 - [ ] Sistema de Muestreo (Sampling)
 - [ ] ...más por definir...
---
## 📄 Licencia
![Licencia: CC BY-NC-SA 4.0](https://licensebuttons.net/l/by-nc-sa/4.0/80x15.png)
CC BY-NC-SA 4.0

---
