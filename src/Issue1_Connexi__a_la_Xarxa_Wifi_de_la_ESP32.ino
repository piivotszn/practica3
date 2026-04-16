#include <WiFi.h>

// Pas 1.1: Definició de la llibreria i les dades de connexió
const char* ssid = "ProjectesSMX";
const char* password = "Hola1234";

void setup() {
  // Pas 1.2: Iniciar la comunicació sèrie i el WiFi
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.print("Connectant a la xarxa...");

  // Pas 1.3: L'espera fins que es connecti
  // El bucle "while" farà que el codi no avanci fins que la connexió sigui d'èxit
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Confirmació de connexió i mostra de la IP obtinguda
  Serial.println("\nConnectat correctament!");
  Serial.print("IP assignada: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // De moment el loop es queda buit, ja que l'objectiu de l'Issue #1

}
