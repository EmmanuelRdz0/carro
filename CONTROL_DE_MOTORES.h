class CONTROL_DE_MOTORES{
  int m_der_avanzar = 9;     //Se definen los pines que controlaran los motores
  int m_der_retroceder = 10;
  int m_izq_avanzar = 6;
  int m_izq_retroceder = 5;
  
  public:
//    void Avanzar_adelante(int velocidad);  //Está funcion hace que el carro valla hacia delantee.
//    void Avanzar_atras(int velocidad);    //Para ir hacia atras solo hace falta enviar un pulso alto en los pines "retroceder" y la ausensia del pulso en los pines "avanzar"
//    void Girar_derecha(int velocidad);   //Para girar hacia la derecha se envia pulso alto en el pin "avanzar" pero solo el de la derecha, todos los demás deben de estar con ausencia de pulso
//    void Girar_izquierda(int velocidad);    //Para girar hacia la derecha se envia pulso alto en el pin "avanzar" pero solo el de la izquierda, todos los demás deben de estar con ausencia de pulso
//    void Detenerse();   //Para detenerse solo hace falta dejar de enviar pulsos a los cuatro pines
//    void Girar_u_derecha(int velocidad);  //Para girar sobre el eje central, se le da un sentido a un motor y el sentido contrario al otro motor.
//    void Girar_u_izquierda(int velocidad);  //Para girar sobre el eje central, se le da un sentido a un motor y el sentido contrario al otro motor.


//  CONTROL_DE_MOTORES(int m_der_avanzar, int m_der_retroceder, int m_izq_avanzar, int m_izq_retroceder){
//    this -> m_der_avanzar = m_der_avanzar;
//    this -> m_der_retroceder = m_der_retroceder;
//    this -> m_izq_avanzar = m_izq_avanzar;
//    this -> m_izq_retroceder = m_izq_retroceder;
//  }
  
  void Avanzar_adelante(int velocidad){  //Está funcion hace que el carro valla hacia delante.
    if(velocidad<=0)velocidad = 0;       //Control de potencia de los motores.
    if(velocidad>=255)velocidad = 255;
    
    pinMode(m_der_avanzar, OUTPUT);      //Se configuran los pines como pines de salida.
    pinMode(m_der_retroceder, OUTPUT);
    pinMode(m_izq_avanzar, OUTPUT);
    pinMode(m_izq_retroceder, OUTPUT);

    analogWrite(m_der_avanzar, velocidad);  //Para que el carro de mueva hacia delante se tiene que mandar un pulso alto el los pines "avanzar" y un la ausencia del pulso en los pines "retroceder" para que estos hagan de gnd.
    analogWrite(m_der_retroceder, 0);
    analogWrite(m_izq_avanzar, velocidad);
    analogWrite(m_izq_retroceder, 0);
    Serial.println("Avanzando adelante.");
  }

  void Avanzar_atras(int velocidad){    //Para ir hacia atras solo hace falta enviar un pulso alto en los pines "retroceder" y la ausensia del pulso en los pines "avanzar"
    if(velocidad<=0)velocidad = 0;       //Control de potencia de los motores.
    if(velocidad>=255)velocidad = 255;
    
    pinMode(m_der_avanzar, OUTPUT);
    pinMode(m_der_retroceder, OUTPUT);
    pinMode(m_izq_avanzar, OUTPUT);
    pinMode(m_izq_retroceder, OUTPUT);

    analogWrite(m_der_avanzar, 0);
    analogWrite(m_der_retroceder, velocidad);
    analogWrite(m_izq_avanzar, 0);
    analogWrite(m_izq_retroceder, velocidad);
    Serial.println("Avanzando atras.");
  }

  void Girar_derecha(int velocidad){   //Para girar hacia la derecha se envia pulso alto en el pin "avanzar" pero solo el de la derecha, todos los demás deben de estar con ausencia de pulso
    if(velocidad<=0)velocidad = 0;       //Control de potencia de los motores.
    if(velocidad>=255)velocidad = 255;
    int velocidad_reducida;
    velocidad_reducida = velocidad*.50;
    
    pinMode(m_der_avanzar, OUTPUT);
    pinMode(m_der_retroceder, OUTPUT);
    pinMode(m_izq_avanzar, OUTPUT);
    pinMode(m_izq_retroceder, OUTPUT);

    analogWrite(m_der_avanzar, velocidad_reducida);
    analogWrite(m_der_retroceder, 0);
    analogWrite(m_izq_avanzar, velocidad);
    analogWrite(m_izq_retroceder, 0);
    Serial.println("Girando derecha.");
  }

  void Girar_izquierda(int velocidad){    //Para girar hacia la derecha se envia pulso alto en el pin "avanzar" pero solo el de la izquierda, todos los demás deben de estar con ausencia de pulso
    if(velocidad<=0)velocidad = 0;       //Control de potencia de los motores.
    if(velocidad>=255)velocidad = 255;
    int velocidad_reducida;
    velocidad_reducida = velocidad*.50;

    pinMode(m_der_avanzar, OUTPUT);
    pinMode(m_der_retroceder, OUTPUT);
    pinMode(m_izq_avanzar, OUTPUT);
    pinMode(m_izq_retroceder, OUTPUT);

    analogWrite(m_der_avanzar, velocidad);
    analogWrite(m_der_retroceder, 0);
    analogWrite(m_izq_avanzar, velocidad_reducida);
    analogWrite(m_izq_retroceder, 0);
    Serial.println("Girando izquierda.");
  }
  
  void Detenerse(){   //Para detenerse solo hace falta dejar de enviar pulsos a los cuatro pines
    pinMode(m_der_avanzar, OUTPUT);
    pinMode(m_der_retroceder, OUTPUT);
    pinMode(m_izq_avanzar, OUTPUT);
    pinMode(m_izq_retroceder, OUTPUT);
    
    analogWrite(m_der_avanzar, LOW);
    analogWrite(m_der_retroceder, LOW);
    analogWrite(m_izq_avanzar, LOW);
    analogWrite(m_izq_retroceder, LOW);
    Serial.println("Se detectó un obstáculo.");
  }

  void Girar_u_derecha(int velocidad){  //Para girar sobre el eje central, se le da un sentido a un motor y el sentido contrario al otro motor.
    if(velocidad<=0)velocidad = 0;       //Control de potencia de los motores.
    if(velocidad>=255)velocidad = 255;
    
    pinMode(m_der_avanzar, OUTPUT);
    pinMode(m_der_retroceder, OUTPUT);
    pinMode(m_izq_avanzar, OUTPUT);
    pinMode(m_izq_retroceder, OUTPUT);
    
    analogWrite(m_der_avanzar, 0);
    analogWrite(m_der_retroceder, velocidad);
    analogWrite(m_izq_avanzar, velocidad);
    analogWrite(m_izq_retroceder, 0);
    Serial.println("Girando hacia derecha sobre eje central.");
  }

  void Girar_u_izquierda(int velocidad){  //Para girar sobre el eje central, se le da un sentido a un motor y el sentido contrario al otro motor.
    if(velocidad<=0)velocidad = 0;       //Control de potencia de los motores.
    if(velocidad>=255)velocidad = 255;
    
    pinMode(m_der_avanzar, OUTPUT);
    pinMode(m_der_retroceder, OUTPUT);
    pinMode(m_izq_avanzar, OUTPUT);
    pinMode(m_izq_retroceder, OUTPUT);
    
    analogWrite(m_der_avanzar, velocidad);
    analogWrite(m_der_retroceder, 0);
    analogWrite(m_izq_avanzar, 0);
    analogWrite(m_izq_retroceder, velocidad);
    Serial.println("Girando hacia derecha sobre eje central.");
  }
  /*
  void Girar_der_en_movimiento(){
  }
  void Girar_izq_en_movimiento(){
  }
  */
};
