
import serial
from time import sleep
import sys


COM = '/dev/ttyACM0' 
BAUD = 9600

ser = serial.Serial(COM, BAUD, timeout = .1)

print('Waiting for device')
sleep(3)
print(ser.name)
print("Instrucciones para el motor:")
print("1) M1 speed (PWM)\n2) M2 speed (PWM)\n3) M1 off\n4) M2 off")
print("Al escribir positivo o negativo el valor del PWM se cambia el sentido de giro")
print("Escribe la instruccion completa")

while True:
	#val = str(ser.readline().decode().strip('\r\n')) # Capture serial output as a decoded string
	#val=str(ser.write())
        #_line = str(ser.readline()).strip()
        #print(_line.split('/'))
        # Leer comando de la terminal
        term_inp = raw_input('--------\nEscribe tu comando \n')
        # Imprime comando leido de terminal
        print('Comando Python: ', term_inp)
        # Enviar comando a Arduino
        ser.write(term_inp)
        # Imprime lo que manda arduino
        print('Comando de Arduino: ', ser.readline().strip())
