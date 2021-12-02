/*
M = Maniobra de salida
F = Freno activado
f = Freno desactivado
U = Avanzar adelante
u = Dejar de avanzar adelante
B = Avanzar atras
b = Dejar de avanzar atras
R = Girar hacia la derecha
r = Dejar de girar hacia la derecha
L = Girar hacia la izquierda
l (L minuscula) = Dejar de girar hacia la izquierda 
D = Girar en U hacia la derecha
d = Dejar de girar en U hacia la derecha
I = Girar en U hacia la izquierda
i = Dejar de girar en U hacia la izquierda
*/

#include "MEDIR_DISTANCIA.h"
#include "CONTROL_DE_MOTORES.h"
#include "ENCONTRAR_SALIDA.h"

float distancia;
int distancia_limite = 15;
char estado = 'F';
int led = 13;

MEDIR_DISTANCIA medir_distancia;
CONTROL_DE_MOTORES moverse;
ENCONTRAR_SALIDA encontrar_salida;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
//  distancia = medir_distancia.Medir_distancia();
//  Serial.println(distancia);

  
  if (Serial.available() > 0){
    estado = Serial.read(); 

    if (estado == 'M'){
      digitalWrite(led, HIGH);delay(20);
      digitalWrite(led, LOW);delay(20);
    }
    
    if (estado == 'U'){
      moverse.Avanzar_adelante(255);
    }
    
    if (estado == 'u'){
      moverse.Detenerse();
    }

    if (estado == 'B'){
      moverse.Avanzar_atras(255);      
    }

    if (estado == 'b'){
      moverse.Detenerse();
    }

    if (estado == 'R'){
      moverse.Girar_derecha(255);
    }

    if (estado == 'r'){
      moverse.Detenerse();
    }

    if (estado == 'L'){
      moverse.Girar_izquierda(255);
    }

    if (estado == 'l'){
      moverse.Detenerse();
    }

    if (estado == 'D'){
      moverse.Girar_u_derecha(255);
    }

    if (estado == 'd'){
      moverse.Detenerse();
    }

    if (estado == 'I'){
      moverse.Girar_u_izquierda(255);
    }

    if (estado == 'i'){
      moverse.Detenerse();
    }

    if (estado == 'F'){
      moverse.Detenerse();
    }
  }
  
}
