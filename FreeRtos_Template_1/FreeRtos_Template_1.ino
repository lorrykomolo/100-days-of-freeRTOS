#include <Arduino_FreeRTOS.h>

const byte led1_pin = 6;
const byte led2_pin = 7;

void Led1(void *param);
void Led2(void *param);

//TaskHandle_t Task_Handle1;
//TaskHandle_t Task_Handle2;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (led1_pin, OUTPUT);
pinMode (led2_pin, OUTPUT);
xTaskCreate(Led1, "led1", 100, NULL, 1, NULL);

xTaskCreate(Led2, "led2", 100, NULL, 0, NULL);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void Led1(void *param){
  (void) param;

  while (1){
    digitalWrite(led1_pin, HIGH);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    digitalWrite(led1_pin, LOW);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    }
   
  }

  void Led2(void *param){
  (void) param;

  while (1){
    digitalWrite(led2_pin, HIGH);
    vTaskDelay(100/portTICK_PERIOD_MS);
    digitalWrite(led2_pin, LOW);
    vTaskDelay(50/portTICK_PERIOD_MS);
    }
   
  }
