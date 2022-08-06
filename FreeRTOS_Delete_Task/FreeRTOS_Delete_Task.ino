#include <Arduino_FreeRTOS.h>

const byte led1_pin = 6;
const byte led2_pin = 7;
int count=0;

void Led1(void *param);
void Led2(void *param);

TaskHandle_t Task_Handle1;
TaskHandle_t Task_Handle2;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (led1_pin, OUTPUT);
pinMode (led2_pin, OUTPUT);
xTaskCreate(Led1, "led1", 100, NULL, 1, &Task_Handle1);

xTaskCreate(Led2, "led2", 100, NULL, 1, &Task_Handle2);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void Led1(void *param){
  (void) param;

  while (1){
    Serial.println("Task1");
    digitalWrite(led1_pin, HIGH);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    digitalWrite(led1_pin, LOW);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    }
   
  }

  void Led2(void *param){
  (void) param;

  while (1){
    count++;
    Serial.println("Task2");
    digitalWrite(led2_pin, HIGH);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    digitalWrite(led2_pin, LOW);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    if (count==10){
    vTaskDelete(Task_Handle2);
    }
    }
   
  }
