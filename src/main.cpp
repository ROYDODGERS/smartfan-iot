//integrantes equipo :
// Juan Pablo Luna Sotero
#include <Arduino.h>
#include <WiFi.h>     
#include "config.h"


const char* WIFI_SSID = "RI-UAEMex";
const char* WIFI_PASSWORD = "";


void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("\n🔌 Iniciando conexión WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  int intentos = 0;
  while (WiFi.status() != WL_CONNECTED && intentos < 20) {
    delay(500);
    Serial.print(".");
    intentos++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ Conectado exitosamente a la red WiFi!");
    Serial.print("📡 Dirección IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\n❌ No se pudo conectar a la red WiFi. Revisa tus credenciales.");
  }
}

void loop() {
 
  // Lectura del sensor, control del ventilador, etc.
  delay(1000);
}