#include <WiFi.h>
#include <WebServer.h> // Pas 2.1: Llibreria del servidor

// Dades de connexió
const char* ssid = "ProjectesSMX";
const char* password = "Hola1234";

// Pas 2.1: Creació del servidor al port 80 (el port estàndard web)
WebServer server(80);

// Pas 2.2: Funció que s'executa quan algú entra a la web
void enviarPaginaPrincipal() {
  server.send(200, "text/plain", "Hola, soc el teu ESP32");
}

void setup() {
  Serial.begin(115200);
  
  // Connexió WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connectant...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnectat!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // Pas 2.3: Assignar la ruta principal ("/") a la funció de resposta
  server.on("/", enviarPaginaPrincipal);
  
  // Pas 2.3: Activar el servidor
  server.begin();
  Serial.println("Servidor web en marxa!");
}

void loop() {
  // Pas 2.3: Gestionar les peticions dels clients (mòbils, PCs)
  server.handleClient();
}
