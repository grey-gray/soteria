
#include "mqtt.h"
#include "publish_function.h"

char MQTT_HOST_DOMAIN[] = "broker.hivemq.com"; //brokerUrl
char MQTT_TCP_PORT[] = "1883"; //brokerPort
char MQTT_WEBSOCKET_PORT[] = "8000";
char MQTT_TOPIC[] = "hive/light_status";
#define GSM_ON 7
char CLIENT_ID[] = "clientID";




 void setup(){

     pinMode(GSM_ON, OUTPUT);

     serialComs(9600,19200,20000);//void serialComs(int baud_Serial_monitor, int baud_sim_module, int delay_micro)
 }



 void loop(){

       digitalWrite(GSM_ON, HIGH); //Starts the SIM module.
       delay(20000); //wait for 20 seconds GPRS getting stable

       boolean gprsReady = isGPRSReady();

       if(gprsReady == true){
          Serial.println("Ready to send");
          Serial.println("Sendind light: \"on\"");
          
         char light_status[] = "on";
         
           /* The arguments here are:
        clientID, IP, Port, Topic, Message
        */
          sendMQTTMessage(CLIENT_ID, MQTT_HOST_DOMAIN, MQTT_TCP_PORT, MQTT_TOPIC, light_status); 
       }


       digitalWrite(GSM_ON, LOW);
       delay(60000); //60 seconds

 }
