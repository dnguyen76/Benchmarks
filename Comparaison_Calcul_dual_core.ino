#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

#define ARDUINO_CORE_0 0
#define ARDUINO_CORE_1 1



// define two tasks
void Task1( void *pvParameters );
void Task2( void *pvParameters );

char inChar ;
// the setup function runs once when you press reset or power the board
void setup() {
  
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
//  Serial.print (F( " 1 or 2 cores ? "));
//  if (Serial.available() > 0) {
//    // read incoming serial data:
//   inChar = Serial.read(); }

 uint64_t chipid;  
  chipid=ESP.getEfuseMac();//The chip ID is essentially its MAC address(length: 6 bytes).
  Serial.printf("ESP32 Chip ID = %04X",(uint16_t)(chipid>>32));//print High 2 bytes
  Serial.printf("%08X\n",(uint32_t)chipid);//print Low 4bytes.
  delay(3000);
  
    
  // Now set up two tasks to run independently.
  xTaskCreatePinnedToCore(
    Task1
    ,  "Task1"   // A name just for humans
    ,  100000  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL 
    ,  ARDUINO_CORE_1);

//    if((&inChar) == "2") {
//      Serial.println ( F(" 2 cores benchmark"));

  xTaskCreatePinnedToCore(
    Task2
    ,  "Task2"
    ,  100000  // Stack size
    ,  NULL
    ,  2  // Priority
    ,  NULL 
    ,  ARDUINO_CORE_0);
//    };


  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}


void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/








#ifndef ROPT
#define REG
        /* REG becomes defined as empty */
        /* i.e. no register variables   */
#else
#define REG register
#endif


/* variables for time measurement: */


unsigned long Begin_Time1,
              End_Time1,
              User_Time1,
              DT ;
              

unsigned long Begin_Time2,
              End_Time2,
              User_Time2;
             


void Task1(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  REG  long  Nombre_de_fois , Fois, Nombre_boucle, boucle;
  REG  unsigned long s ;

   // Somme des entiers consecutis au caré (n*(n+1)*(2n+1)/6

  
  /* Initializations */

  Nombre_boucle = 1000; 
  Nombre_de_fois = 1000; 
  
  s= Nombre_de_fois * (Nombre_de_fois +1)*(2*Nombre_de_fois +1)/6 ;
 
  Serial.printf("Somme carrés : %lu \n\n",s); 
  
  Serial.print(F("Execution demarre, "));
  Serial.printf("%d", Nombre_de_fois);
  Serial.println(F(" fois "));

  
  
  /***************/
  /* Start timer */
  /***************/
  
  Nombre_de_fois = 500 ; 
  Begin_Time1 = micros();

  for ( boucle=1 ; boucle <= Nombre_boucle ; boucle++)
 {
   Fois = 0 ; s=0 ;

  for ( ; Fois< Nombre_de_fois; )
  {
    Fois++ ;
    s =  s + Fois*Fois ;
     
  } /* loop "for Foisx" */
  
 }

  /**************/
  /* Stop timer */
  /**************/
  
  End_Time1 = micros();

   delay(3000);
    
  User_Time1 = End_Time1 - Begin_Time1;

  Serial.print(F("Fin execution "));
  Serial.printf(" %lu", Fois) ;
  Serial.printf("fois S = %lu\n", s);
  
  Serial.printf("%d", User_Time1);Serial.print(F(" Microsecondes dans le coeur  "));Serial.println(xPortGetCoreID());
  Serial.println();
    for(;;) //A Task shall never return or exit.
        for(;;) //A Task shall never return or exit.
         {  vTaskDelay(10000);  // one tick delay (10ms) in between reads for stability
 
         } 
}

void Task2(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

 
  REG  long  Nombre_de_fois , Fois, Nombre_boucle, boucle;
  REG  unsigned long s2;

  
  /* Initializations */


  Nombre_de_fois = 1000; // 
  Nombre_boucle = 1000;
  
 // Serial.print(F("Task1 running in core ")); Serial.println(xPortGetCoreID());
  
  Serial.print(F("Execution demarre, "));
  Serial.printf("boucle %lu de %lu fois \n",Nombre_boucle,Nombre_de_fois);
 

  
  /***************/
  /* Start timer */
  /***************/

 
 Begin_Time2 = micros();
 for ( boucle=1 ; boucle <= Nombre_boucle ; boucle++)
 {
   Fois =500 ; s2=0 ;

  for ( ; Fois< Nombre_de_fois; )
  {
    Fois++ ;
    s2 =  s2 + Fois*Fois ;
     
  } /* loop "for Foisx" */

 }
  /**************/
  /* Stop timer */
  /**************/
  
  End_Time2 = micros();
  
  User_Time2 = End_Time2 - Begin_Time2;
  delay(5000);
  
  
  Serial.print(F("Fin execution ")); 
  Serial.printf(" %d", Fois) ;
  Serial.printf(" fois S = %lu\n",s2);

 Serial.print( User_Time2);Serial.print(F(" Microsecondes dans le coeur  "));Serial.println(xPortGetCoreID());
   Serial.println();  

    for(;;) //A Task shall never return or exit.
        for(;;) //A Task shall never return or exit.
         {  vTaskDelay(10000);  // one tick delay (10ms) in between reads for stability
 //         Serial.print(F("Task1 running in core ")); Serial.println(xPortGetCoreID());
         } 
}
