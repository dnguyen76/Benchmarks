
// the setup function runs once when you press reset or power the board
void setup() {
  
  // initialize serial communication at 19200 bits per second:
 
  Serial.begin(9600,SERIAL_8N1);
  Serial.print( "initialisation faite");
  Serial.println();
  delay(3000);

}


void loop()
{
  


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
             




 
 long  Nombre_de_fois2 , Fois2, Nombre_boucle, boucle;
 unsigned long s2;

  
  /* Initializations */


  Nombre_de_fois2 = 1000; // 
  Nombre_boucle = 1000;
//  Serial.print(F("Task1 running in core ")); Serial.println(xPortGetCoreID());
  
  Serial.print(F("Execution demarre "));
  Serial.print(Nombre_boucle),Serial.print( " boucles de ");Serial.println(Nombre_de_fois2);
 

  
  /***************/
  /* Start timer */
  /***************/

 
 Begin_Time2 = micros();
 for ( boucle=1 ; boucle <= Nombre_boucle ; boucle++)
 {
   Fois2 =0 ; s2=0 ;
   
  

  for ( ; Fois2< Nombre_de_fois2; )
  {
    Fois2++ ;
    s2 =  s2 + Fois2*Fois2 ;
     
  } /* loop "for Foisx" */

 }
  /**************/
  /* Stop timer */
  /**************/
  
  End_Time2 = micros();
  
  User_Time2 = End_Time2 - Begin_Time2;

  
  
  Serial.print(F("Fin execution Total : ")); 
//  Serial.print(Nombre_boucle, Fois2) ;
  Serial.println(s2);
 Serial.println(Begin_Time2,DEC); Serial.println(End_Time2,DEC);
 Serial.print(User_Time2,DEC);Serial.print(F(" Microsecondes ")); //Serial.println(xPortGetCoreID());
   Serial.println();  
 delay(3000);
 
  
}
