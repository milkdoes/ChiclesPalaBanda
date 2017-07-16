// ENUMERACIONES.
// Pines donde estan conectados los leds.
enum LED {
  LED_X1 = 5,
  LED_X2 = 6,
  LED_Y = 7
};

// CONSTANTES.
const byte CANTIDAD_LEDS = 3;
// Pines donde estan conectados los fototransistores.
const byte FOTOTRANSISTOR_X1 = 2;
const byte FOTOTRANSISTOR_X2 = 3;
const byte FOTOTRANSISTOR_Y = 4;

// FUNCIONES.
// Prender o apagar un led en un pin y de acuerdo a una instruccion.
void CambiarEstadoLed(const byte pinLed, const bool prender) {
  if (prender) {
    digitalWrite(pinLed, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
  }
}

// INICIO.
void setup() {
  // Inicializar lectura de serial.
  Serial.begin(9600);

  // Inicializar pines de salida para leds.
  pinMode(LED_X1, OUTPUT);
  pinMode(LED_X2, OUTPUT);
  pinMode(LED_Y, OUTPUT);

  // Inicializar pines de entrada para fototransistores.
  pinMode(FOTOTRANSISTOR_X1, INPUT);
  pinMode(FOTOTRANSISTOR_X2, INPUT);
  pinMode(FOTOTRANSISTOR_Y, INPUT);
}

// PRINCIPAL.
void loop() {
  // Verificar si la longitud y altura para un producto cubren los sensores.
  const bool xNegativaValida = digitalRead(FOTOTRANSISTOR_X1) == false;
  const bool xPositivaValida = digitalRead(FOTOTRANSISTOR_X2) == false;
  const bool longitudValida = xNegativaValida && xPositivaValida;
  const bool alturaValida = digitalRead(FOTOTRANSISTOR_Y) == false;

  // Prender ó apagar los leds que corresponden a los indicadores de mediciones.
  CambiarEstadoLed(LED_X1, xNegativaValida);
  CambiarEstadoLed(LED_X2, xPositivaValida);
  CambiarEstadoLed(LED_Y, alturaValida);
}
