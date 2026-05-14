#include <WiFi.h>
#include <WebServer.h>

// --- Issue #1: Connexió ---
const char* ssid = "ProjectesSMX";
const char* password = "Hola1234";

// --- Issue #4: Configuració del Sensor ---
// En la placa SteamMakers, el sensor de temperatura acostuma a estar al pin 34
const int pinSensor = 34; 

WebServer server(80);

void enviarPaginaPrincipal() {
  // --- Issue #4: Llegir el sensor ---
  // Llegim el valor analògic (de 0 a 4095)
  int valorBrut = analogRead(pinSensor);
  
  // Convertim el valor a temperatura (Càlcul estàndard per a la SteamMakers)
  float tempReal = (valorBrut / 4095.0) * 100.0; 

  // --- Issue #3: Muntar HTML amb dades reals ---
  String html = "<html><head><meta charset='UTF-8'>";
  html += "<style>body{font-family:sans-serif; text-align:center; background:#f4f4f4;}";
  html += ".card{padding:20px; color:white; display:inline-block; margin:10px; border-radius:10px; min-width:150px; font-size:24px;}";
  html += "</style></head><body>";
  
  html += "<h1>Monitor CPD</h1>";
  
  // Lògica de color: si fa massa calor (>30°C), la targeta es posa vermella
  String colorCard = (tempReal > 30) ? "#e74c3c" : "#2ecc71";
  
  html += "<div class='card' style='background:" + colorCard + ";'>";
  html += "<h3>Temperatura</h3>";
  html += "<p>" + String(tempReal, 1) + " °C</p>"; // String(variable, decimals)
  html += "</div>";
  
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(9600);
  
  // Iniciar WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connectant...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnectat!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // Iniciar Servidor
  server.on("/", enviarPaginaPrincipal);
  server.begin();
}

void loop() {
  server.handleClient();
}
