
//Variables globales
char buff[20];  //Buffer serial
int vel=0,
    vel2= 0;

void setup(){
  //Inicialización y declaración de variables
  pinMode(3,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);   //Habilita comunicación serial
  Serial.setTimeout(100); //100ms máximo para caracter nulo
 // while(!Serial){}
  Serial.println("Instrucciones para el motor:");
  Serial.println("1) M1 speed (PWM)\n 2) M2 speed (PWM)\n 3) M1 off\n 4) M2 off");
  Serial.println("Al escribir positivo o negativo el valor del PWM se cambia el sentido de giro");
  Serial.println("Escribe la instuccion completa");
}

void loop(){
  if(Serial.available()){
    Serial.readBytes(buff,20);
    Serial.println(buff);
    if(!strncmp(buff,"M1 speed",8)){
      vel=atoi(buff+8);
      Serial.println(vel);
       if(vel<=127 && vel>=-127){
        vel=vel+127;
        analogWrite(5,vel);
       }
    }
    if(!strncmp(buff,"M2 speed",8)){
       vel2=atoi(buff+8);
       Serial.println(vel2);
       if(vel2<=127 && vel2>=-127){
        vel2=vel2+127;
        analogWrite(3,vel2);
        }
       }
    if(!strcmp(buff, "M1 off")){
      vel=0;
      analogWrite(10,vel);
      }
    if(!strcmp(buff, "M2 off")){
      vel=0;
      analogWrite(9,vel);
      }
    else{
      Serial.println("No existe ese comando");
    }
    memset(buff,0,sizeof(buff));
    }
  }

