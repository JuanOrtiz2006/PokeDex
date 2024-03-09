
#include <Firebase_ESP_Client.h>
#include <WiFi.h>
#include <addons/TokenHelper.h>
#include <ArduinoJson.h>
#define FIREBASE_USE_PSRAM

//Conectar a una red WiFi 
const char* WIFI_SSID = "Gaby JP";//el nombre de la red
const char* WIFI_PASSWORD = "Gaby20061218";//la contraseña de la red
//Recursos de Firebase
const char* API_KEY = "AIzaSyCv6A3HL4Lmw2YUi5_q10FGHGIgFE0na7w";
const char* FIREBASE_PROJECT_ID = "pokeapi-37f0f";
//CONFIGURAR UN EMAIL Y CONTRASEÑA EN AUTHENTICATION de Firebase
const char* USER_EMAIL = "esp32@prueba.com";
const char* USER_PASSWORD = "1034596";

//Define Firebase Data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
int tipo=23,tipo2=22,tipo3=21,tipo4=19, tipo5=18, tipo6=5, tipo7=17;



void setup() {

  

  pinMode(23,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(21,OUTPUT);
  pinMode(19,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(5,OUTPUT);
   Serial.begin(115200);
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);//Verificamos la version
  setupWiFi();//Llamamos la funcion de configuración wifi
  setupFirebase();//Llamamos la funcion de configuración Firebase
  

 
}

void loop(){
String path = "PokeApi";//RUTA DE COLECCION
  FirebaseJson json;

  if (Firebase.Firestore.getDocument(&fbdo, FIREBASE_PROJECT_ID, "", path.c_str(), "")) {

    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, fbdo.payload().c_str());

    if (!error) {
      for (JsonObject document : doc["documents"].as<JsonArray>()) {
        const char* document_name = document["name"];//PARAMETRO NOMBRE
        Serial.print(document);
        const bool state = document["fields"]["encender"]["booleanValue"];//PARAMETRO DE CAMPOS A REVISAR
        Serial.print(" : ");
        
        if (strstr(document_name, "fire") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo3,1): digitalWrite(tipo3,0);
          state ? Serial.println("LED1 On") : Serial.println("LED1 OFF");
        }
        if (strstr(document_name, "grass") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo4,1): digitalWrite(tipo4,0);
          state ? Serial.println("LED2 On") : Serial.println("LED2OFF");
        }
        if (strstr(document_name, "poison") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo6,1): digitalWrite(tipo6,0);
          state ? Serial.println("LED2 On") : Serial.println("LED2OFF");
        }
        if (strstr(document_name, "water") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo2,1): digitalWrite(tipo2,0);
          state ? Serial.println("LED1 On") : Serial.println("LED1 OFF");
        }
        if (strstr(document_name, "bug") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo4,1): digitalWrite(tipo4,0);
          state ? Serial.println("LED2 On") : Serial.println("LED2OFF");
        }
        if (strstr(document_name, "flying") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo7,1): digitalWrite(tipo7,0);
          state ? Serial.println("LED2 On") : Serial.println("LED2OFF");
        }
        if (strstr(document_name, "normal") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo,1): digitalWrite(tipo,0);
          state ? Serial.println("LED1 On") : Serial.println("LED1 OFF");
        }
        if (strstr(document_name, "fighting") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo,1): digitalWrite(tipo,0);
          state ? Serial.println("LED2 On") : Serial.println("LED2OFF");
        }
        if (strstr(document_name, "ground") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo,1): digitalWrite(tipo,0);
          state ? Serial.println("LED2 On") : Serial.println("LED2OFF");
        }
        if (strstr(document_name, "rock") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo7,1): digitalWrite(tipo7,0);
          state ? Serial.println("LED1 On") : Serial.println("LED1 OFF");
        }
        if (strstr(document_name, "ghost") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo7,1): digitalWrite(tipo7,0);
          state ? Serial.println("LED1 On") : Serial.println("LED1 OFF");
        }
        if (strstr(document_name, "steel") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo7,1): digitalWrite(tipo7,0);
          state ? Serial.println("LED1 On") : Serial.println("LED1 OFF");
        }
        if (strstr(document_name, "electric") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo5,1): digitalWrite(tipo7,0);
          state ? Serial.println("LED1 On") : Serial.println("LED1 OFF");
        }
        if (strstr(document_name, "psychic") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo6,1): digitalWrite(tipo6,0);
          state ? Serial.println("LED1 On") : Serial.println("LED1 OFF");
        }
        if (strstr(document_name, "ice") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo2,1): digitalWrite(tipo2,0);
          state ? Serial.println("LED1 On") : Serial.println("LED1 OFF");
        }
        if (strstr(document_name, "dragon") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo2,1): digitalWrite(tipo2,0);
          state ? Serial.println("LED1 On") : Serial.println("LED1 OFF");
        }
        if (strstr(document_name, "dark") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo6,1): digitalWrite(tipo6,0);
          state ? Serial.println("LED1 On") : Serial.println("LED1 OFF");
        }
        if (strstr(document_name, "fairy") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo6,1): digitalWrite(tipo6,0);
          state ? Serial.println("LED1 On") : Serial.println("LED1 OFF");
        }
        if (strstr(document_name, "unknown") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo7,1): digitalWrite(tipo,0);
          state ? Serial.println("LED1 On") : Serial.println("LED1 OFF");
        }
        if (strstr(document_name, "shadow") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(tipo7,1): digitalWrite(tipo,0);
          state ? Serial.println("LED1 On") : Serial.println("LED1 OFF");
        }
		}
	}
  }
}


//Funcion para configuara WiFi
void setupWiFi() {
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
}

void setupFirebase() {
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.token_status_callback = tokenStatusCallback;  // Ver addons/TokenHelper.h
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}