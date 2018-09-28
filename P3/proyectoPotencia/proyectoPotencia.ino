
//Variables globales
char buff[20];  //Buffer serial
int vel,
    vel2;

void setup(){
  //Inicialización y declaración de variables
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(2,OUTPUT);

  pinMode(6,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);   //Habilita comunicación serial
  Serial.setTimeout(100); //100ms máximo para caracter nulo
  Serial.println("Instrucciones para el motor:");
  Serial.println("1) M1 speed (PWM)\n2) M2 speed (PWM)\n3) M1 off\n"
  "4) M2 off");
  Serial.println("Al escribir positivo o negativo el valor del PWM se"
  "cambia el sentido de giro");
  
  Serial.println("Escribe la instrucción completa");
  //Apaga los motores
  digitalWrite(4,LOW);
  digitalWrite(2,LOW);
  //Motores al 50%
  analogWrite(5,127);
  analogWrite(6,127);

  digitalWrite(4,HIGH);
  digitalWrite(2,HIGH);
} 

void loop(){
}

void serialEvent(){
  analogWrite(5,127+30);
  analogWrite(6,127+30);
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
    	else if(!strncmp(buff,"M2 speed",8)){
       		vel2=atoi(buff+8);
       		Serial.println(vel2);
       		if(vel2<=127 && vel2>=-127){
        	vel2=vel2+127;
        	analogWrite(3,vel2);
       		}
    	}
    	else if(!strcmp(buff, "M1 off")){
      		digitalWrite(2,0);
    	}
    	else if(!strcmp(buff, "M2 off")){
      		analogWrite(4,0);
    	}else{
		Serial.println("No existe ese comando");
	}
    	memset(buff,0,sizeof(buff));
  	}
}
