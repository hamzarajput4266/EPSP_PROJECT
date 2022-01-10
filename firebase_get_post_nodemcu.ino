
#include <Arduino.h>
#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "PTCL-BB-208"
#define WIFI_PASSWORD "356E3FB0"

// Insert Firebase project API Key
#define API_KEY "AIzaSyBHtgxSVQwP-_OJv0cfj1a525ssrBBEVLM"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://epsp-cep-2022-default-rtdb.firebaseio.com"

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int i1m, i2m, i3m, i1p, i2p, i3p, v1m, v2m, v3m, v1p, v2p, v3p;
float floatValue, zero_seq, postive_seq, negative_seq;
String fault;

bool signupOK = false;

void setup()
{
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", ""))
  {
    Serial.println("ok");
    signupOK = true;
  }
  else
  {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop()
{
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
    sendDataPrevMillis = millis();

    // GET CODE:

    //Getting data from react app via firebase real time database
    //It gets data from api, every const has its own api

    //current1 api :  /test/current/current1
    //current2 api :  /test/current/current2

    if (Firebase.RTDB.getInt(&fbdo, "/test/Input/phase1_current"))
    {
      if (fbdo.dataType() == "int")
      {
        i1m = fbdo.intData();
        Serial.println(i1m);
      }
    }
    else
    {
      Serial.println(fbdo.errorReason());
    }
    if (Firebase.RTDB.getInt(&fbdo, "/test/Input/phase2_current"))
    {
      if (fbdo.dataType() == "int")
      {
        i2m = fbdo.intData();
        Serial.println(i2m);
      }
    }
    else
    {
      Serial.println(fbdo.errorReason());
    }
    if (Firebase.RTDB.getInt(&fbdo, "/test/Input/phase3_current"))
    {
      if (fbdo.dataType() == "int")
      {
        i3m = fbdo.intData();
        Serial.println(i3m);
      }
    }
    else
    {
      Serial.println(fbdo.errorReason());
    }
    if (Firebase.RTDB.getInt(&fbdo, "/test/Input/phase1_current_angle"))
    {
      if (fbdo.dataType() == "int")
      {
        i1p = fbdo.intData();
        Serial.println(i1p);
      }
    }
    else
    {
      Serial.println(fbdo.errorReason());
    }
    if (Firebase.RTDB.getInt(&fbdo, "/test/Input/phase2_current_angle"))
    {
      if (fbdo.dataType() == "int")
      {
        i2p = fbdo.intData();
        Serial.println(i2p);
      }
    }
    else
    {
      Serial.println(fbdo.errorReason());
    }
    if (Firebase.RTDB.getInt(&fbdo, "/test/Input/phase3_current_angle"))
    {
      if (fbdo.dataType() == "int")
      {
        i3p = fbdo.intData();
        Serial.println(i3p);
      }
    }
    else
    {
      Serial.println(fbdo.errorReason());
    }
    if (Firebase.RTDB.getInt(&fbdo, "/test/Input/phase1_voltage"))
    {
      if (fbdo.dataType() == "int")
      {
        v1m = fbdo.intData();
        Serial.println(v1m);
      }
    }
    else
    {
      Serial.println(fbdo.errorReason());
    }
    if (Firebase.RTDB.getInt(&fbdo, "/test/Input/phase2_voltage"))
    {
      if (fbdo.dataType() == "int")
      {
        v2m = fbdo.intData();
        Serial.println(v2m);
      }
    }
    else
    {
      Serial.println(fbdo.errorReason());
    }
    if (Firebase.RTDB.getInt(&fbdo, "/test/Input/phase3_voltage"))
    {
      if (fbdo.dataType() == "int")
      {
        v3m = fbdo.intData();
        Serial.println(v3m);
      }
    }
    else
    {
      Serial.println(fbdo.errorReason());
    }
    if (Firebase.RTDB.getInt(&fbdo, "/test/Input/phase1_voltage_angle"))
    {
      if (fbdo.dataType() == "int")
      {
        v1p = fbdo.intData();
        Serial.println(v1p);
      }
    }
    else
    {
      Serial.println(fbdo.errorReason());
    }
    if (Firebase.RTDB.getInt(&fbdo, "/test/Input/phase2_voltage_angle"))
    {
      if (fbdo.dataType() == "int")
      {
        v2p = fbdo.intData();
        Serial.println(v2p);
      }
    }
    else
    {
      Serial.println(fbdo.errorReason());
    }
    if (Firebase.RTDB.getInt(&fbdo, "/test/Input/phase3_voltage_angle"))
    {
      if (fbdo.dataType() == "int")
      {
        v3p = fbdo.intData();
        Serial.println(v3p);
      }
    }
    else
    {
      Serial.println(fbdo.errorReason());
    }

    // LOGIC
    //After getting data, it stores in some variables which in this case are intValue and floatValue

    //  floatValueNew = floatValue + 5;
    //  intValueNew = intValue + 5;

    // POST CODE

    //After apply particular conditions on variables which we got, now its time to post to react app via firebase

    fault = "LINE_TO_LINE"; //this varible will contain string fault
    zero_seq = 0;           //place zero seq
    postive_seq = 0;
    negative_seq = 0;

    if (Firebase.RTDB.setString(&fbdo, "test/Input/Fault_type", fault))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    if (Firebase.RTDB.setfloat(&fbdo, "test/Input/zero_seq", zero_seq))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    if (Firebase.RTDB.setfloat(&fbdo, "test/Input/positive_seq", postive_seq))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    if (Firebase.RTDB.setfloat(&fbdo, "test/Input/negative_seq", negative_seq))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    //    count++;

    // Write an Float number on the database path test/float
  }
}
