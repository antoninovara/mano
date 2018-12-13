/***   Included libraries  ***/
#include <Servo.h>

/***   Global variables and function definition  ***/
const int motor3_cierra = 2;
const int motor3_abre = 3;
const int motor2_cierra = 4;
const int motor2_abre = 5;
const int motor1_cierra = 6;
const int motor1_abre = 7;
Servo muneca;
const int control_motor1 = A0;
const int control_motor2 = A1;
const int control_motor3 = A2;
const int prox_dcha = A4;
const int prox_izda = A3;

float umbral_inf_dcho = 150;
float umbral_inf_izq = 150;
float umbral_abrir_dcho = 800;
float umbral_cerrar_izq = 800;
float control_motor1_max = 750;
float control_motor1_min = 150;
float control_motor2_max = 750;
float control_motor2_min = 150;
float control_motor3_max = 750;
float control_motor3_min = 150;
void abrir_motor1() {
    if (analogRead(control_motor1) <= control_motor1_max) {
        digitalWrite(motor1_abre, HIGH);
        digitalWrite(motor1_cierra, LOW);
    } else {
        digitalWrite(motor1_abre, LOW);
        digitalWrite(motor1_cierra, LOW);
    }
}
void cerrar_motor1() {
    if (analogRead(control_motor1) >= control_motor1_min) {
        digitalWrite(motor1_abre, LOW);
        digitalWrite(motor1_cierra, HIGH);
    } else {
        digitalWrite(motor1_abre, LOW);
        digitalWrite(motor1_cierra, LOW);
    }
}
void abrir_motor2() {
    if (analogRead(control_motor2) <= control_motor2_max) {
        digitalWrite(motor2_abre, HIGH);
        digitalWrite(motor2_cierra, LOW);
    } else {
        digitalWrite(motor2_abre, LOW);
        digitalWrite(motor2_cierra, LOW);
    }
}
void cerrar_motor2() {
    if (analogRead(control_motor2) >= control_motor2_min) {
        digitalWrite(motor2_abre, LOW);
        digitalWrite(motor2_cierra, HIGH);
    } else {
        digitalWrite(motor2_abre, LOW);
        digitalWrite(motor2_cierra, LOW);
    }
}
void abrir_motor3() {
    if (analogRead(control_motor3) <= control_motor3_max) {
        digitalWrite(motor3_abre, HIGH);
        digitalWrite(motor3_cierra, LOW);
    } else {
        digitalWrite(motor3_abre, LOW);
        digitalWrite(motor3_cierra, LOW);
    }
}
void cerrar_motor3() {
    if (analogRead(control_motor3) >= control_motor3_min) {
        digitalWrite(motor3_abre, LOW);
        digitalWrite(motor3_cierra, HIGH);
    } else {
        digitalWrite(motor3_abre, LOW);
        digitalWrite(motor3_cierra, LOW);
    }
}
void parar_todo() {
    digitalWrite(motor1_cierra, LOW);
    digitalWrite(motor1_abre, LOW);
    digitalWrite(motor2_abre, LOW);
    digitalWrite(motor2_cierra, LOW);
    digitalWrite(motor3_abre, LOW);
    digitalWrite(motor3_cierra, LOW);
}



/***   Setup  ***/
void setup() {
    pinMode(motor3_cierra, OUTPUT);
    pinMode(motor3_abre, OUTPUT);
    pinMode(motor2_cierra, OUTPUT);
    pinMode(motor2_abre, OUTPUT);
    pinMode(motor1_abre, OUTPUT);
    pinMode(motor1_cierra, OUTPUT);
    muneca.attach(12);
    pinMode(control_motor1, INPUT);
    pinMode(control_motor2, INPUT);
    pinMode(control_motor3, INPUT);
    pinMode(prox_dcha, INPUT);
    pinMode(prox_izda, INPUT);

}


/***   Loop  ***/
void loop() {
    if (analogRead(prox_dcha) >= umbral_abrir_dcho) {
        abrir_motor1();
        abrir_motor2();
        abrir_motor3();
    } else if (analogRead(prox_izda) >= umbral_cerrar_izq) {
        cerrar_motor1();
        cerrar_motor2();
        cerrar_motor3();
    } else if (analogRead(prox_dcha) >= umbral_inf_dcho) {
        parar_todo();
        muneca.write(180);
    } else if (analogRead(prox_izda) >= umbral_inf_izq) {
        parar_todo();
        muneca.write(0);
    } else {
        parar_todo();
    }
}
