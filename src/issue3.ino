#include <WiFi.h>
#include <WebServer.h>

// --- Dades de l'Issue #1 ---
const char* ssid = "ProjectesSMX";
const char* password = "Hola1234";

// --- Dades de l'Issue #2 ---
WebServer server(80);

// --- MODIFICACIÓ DE L'ISSUE #3 ---
void enviarPaginaPrincipal() {
  // Preparem la cadena de text amb format HTML
  String html = "<html><head><meta charset='UTF-8'>";
  
  // El disseny (CSS)
  html += "<style>body{font-family:sans-serif; text-align:center;} .card{padding:20px; color:white; display:inline-block; margin:10px; border-radius:10px;}</style>";
  
  html += "</head><body><h1>Monitor CPD</h1>";
  
  // La targeta visual
  html += "<div class='card' style='background:gray;'><h3>Temp</h3><p>-- °C</p></div>";
  
  html += "</body></html>";

  // Enviem la web al navegador
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  
  // Connexió (Issue #1)
  WiFi.begin(ssid, password);
  Serial.print("Connectant...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnectat!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // Configuració del servidor (Issue #2)
  server.on("/", enviarPaginaPrincipal);
  server.begin();
}

void loop() {
  // Mantenim el servidor actiu (Issue #2)
  server.handleClient();
}
