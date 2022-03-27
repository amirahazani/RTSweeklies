#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

//pins
int LED_BUILTIN = 2; 
int LEDpin = LED_BUILTIN;

//Task: blink LED

void toggleLED(void*parameter){
  while(1){
    digitalWrite(LEDpin, HIGH);
    vTaskDelay(500/portTICK_PERIOD_MS);
    digitalWrite(LEDpin, LOW);
    vTaskDelay(250/portTICK_PERIOD_MS);
  }
}

void setup() {
  //configure pin
  pinMode(LEDpin, OUTPUT);

  //task to run forever
  xTaskCreatePinnedToCore(
              toggleLED, //function to be called
              "Toggle LED", //name of task
              1024, //Stack size
              NULL, //Parameter to pass to function
              1, //Task priority
              NULL, //Task handle
              app_cpu); //Run on one core for demo purposes
            
}

void loop() {
  // put your main code here, to run repeatedly:

}
