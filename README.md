# 🖥️ Pràctica 3 - Dashboard de monitorització d’un CPD

## 📌 Descripció

Aquesta pràctica consisteix en el desenvolupament d’un sistema de monitorització per a un CPD (Centre de Processament de Dades) utilitzant una placa ESP32.

L’ESP32 actua com a servidor web, permetent visualitzar des d’un navegador web les dades recollides pels sensors en temps real, com la temperatura o la llum ambiental. A més, el sistema incorpora alertes visuals i físiques mitjançant un LED quan es detecten valors perillosos.

---

## 🎯 Objectius

- Connectar l’ESP32 a una xarxa WiFi
- Crear un servidor web accessible des del navegador
- Mostrar dades en temps real dels sensors
- Implementar una interfície web amb HTML i CSS
- Desenvolupar un sistema d’alertes basat en condicions
- Controlar un LED segons l’estat del sistema
- Organitzar el projecte amb GitHub (issues, kanban, etc.)

---

## ⚙️ Funcionament

1. L’ESP32 es connecta a la xarxa WiFi
2. S’inicia un servidor web al port 80
3. L’usuari accedeix a la IP del dispositiu
4. Es mostren les dades dels sensors en una pàgina web
5. El sistema comprova si hi ha condicions de perill
6. Si hi ha risc:
   - Es canvia el color de la web
   - S’activa un LED
7. El sistema es manté en funcionament continu

---

## 🧩 Tecnologies utilitzades

- ESP32
- Arduino IDE
- Llibreria WiFi (`WiFi.h`)
- Llibreria WebServer (`WebServer.h`)
- HTML / CSS
- GitHub

---

## 📁 Estructura del projecte
── practica3/
    ├── README.md          ← Explicació general de la pràctica i objectius
    ├── src/               ← Fitxers de codi (.cpp, .h, .ino…)
    │   └── main.ino
    └── doc/               ← Documentació, captures, PDF, imatges, vídeos


---

## 🌐 Funcionalitats principals

- ✔️ Connexió a WiFi
- ✔️ Servidor web funcional
- ✔️ Visualització de dades en temps real
- ✔️ Actualització automàtica de la pàgina
- ✔️ Sistema d’alertes
- ✔️ Control de LED
- ✔️ Pàgina secundària de crèdits

---

## 👨‍💻 Autors

- Raul Alumne 1  
- Jan Alumne 2  

---

## 📄 Llicència

Aquest projecte és per a ús educatiu.
