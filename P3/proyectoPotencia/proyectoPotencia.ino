#include<string.h> //para strcmp() compara cadenas
#include<math.h>

//Variables globales
int i;
short int contacto = 0,
          foto_Resistencia_Digital;
double  foto_Resistencia_Analogica = 0,
        infrarojo = 0;
char buff[20];  //Buffer serial;

void setup(){
  //Inicialización y declaración de variables
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  
  Serial.begin(9600);   //Habilita comunicación serial
  Serial.setTimeout(100); //100ms máximo para caracter nulo
}

void loop(){
  
}
/**/
int velocidad = 0;
void serialEvent(){
  if(Serial.available()){ //Sí, hay datos en el buffer
    //Carga los datos en un buffer auxiliar
    Serial.readBytesUntil('\n', buff, 20);
    //Serial.println(buff);
    if(!strncmp(buff, "M1 speed", 8)){//Compara el buffer
      velocidad = atoi(buff+8);
      if(velocidad <128 && velocidad >-128){
        velocidad = velocidad +128;
        analogWrite(3,velocidad);
      }
    }else{
        Serial.println("Ningun sensor con esa descripción");
    }
    memset(buff,0,sizeof(buff));//Limpia el buffer
  }
}
