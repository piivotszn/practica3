#include <WiFi.h>
#include <WebServer.h>

// Issue #1: Dades WiFi
const char* ssid = "ProjectesSMX";
const char* password = "Hola1234";

// Issue #4: Pin del sensor
const int pinSensor = 34; 

// Issue #2: Servidor
WebServer server(80);

void enviarPaginaPrincipal() {
  // Issue #4: Lectura del sensor
  int valorBrut = analogRead(pinSensor);
  float tempReal = (valorBrut *5 / 4095.0) * 100.0; 

  // Issue #3 i #5: HTML dinàmic
  String html = "<html><head><meta charset='UTF-8'>";
  
  // --- AQUÍ ESTÀ L'ISSUE #5: Actualització automàtica cada 2 segons ---
  html += "<meta http-equiv='refresh' content='2'>"; 
  
  html += "<style>body{font-family:sans-serif; text-align:center; background:#f4f4f4;}";
  html += ".card{padding:20px; color:white; display:inline-block; margin:10px; border-radius:10px; min-width:150px; font-size:24px;}";
  html += "</style></head><body>";
  
  html += "<h1>Monitor CPD en Temps Real</h1>";
  
  String colorCard = (tempReal > 30) ? "#e74c3c" : "#2ecc71";
  
  html += "<div class='card' style='background:" + colorCard + ";'>";
  html += "<h3>Temperatura</h3>";
  html += "<p>" + String(tempReal, 1) + " °C</p>";
  html += "</div>";
  
  html += "<p>La pàgina s'actualitza sola cada 2 segons.</p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  // Ajustat a 9600 perquè puguis veure la IP al teu Monitor Sèrie
  Serial.begin(9600); 
  
  WiFi.begin(ssid, password);
  Serial.print("Connectant...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnectat!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", enviarPaginaPrincipal);
  server.begin();
}

void loop() {
  server.handleClient();
}
