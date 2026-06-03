// --- KOD MOTOR KAWALAN BLUETOOTH SPEED-Control ---

#include "BluetoothSerial.h"




// Definisi pin butang
#define bttnA        26
#define bttnB        32




// Definisi pin dan nama pemboleh ubah motor
const int motorkananA1 = 18;    
const int motorkananA2 = 19;    
const int motorkiriB1 = 17;    
const int motorkiriB2 = 12;    
const int buzzer = 25;


int vSpeed=200;




// Objek Bluetooth Serial dan nama Bluetooth
BluetoothSerial my_bluetooth;
const char* nama_bluetooth = "FoosBall KKSJaih";




void setup() {
  // --- Tetapan Pin Motor ---
  pinMode(motorkananA1, OUTPUT);
  pinMode(motorkananA2, OUTPUT);
  pinMode(motorkiriB1, OUTPUT);
  pinMode(motorkiriB2, OUTPUT);
 
  // --- Tetapan Pin Buzzer ---
  pinMode(buzzer, OUTPUT);




  // --- Tetapan Pin Butang (Amalan Terbaik) ---
  pinMode(bttnA, INPUT_PULLUP);
  pinMode(bttnB, INPUT_PULLUP);




  // --- Mulakan Komunikasi Serial (untuk debugging) & Bluetooth ---
  Serial.begin(115200);
  delay(100);
  my_bluetooth.begin(nama_bluetooth); // Memulakan Bluetooth
  Serial.println("Robot sedia menerima arahan melalui Bluetooth...");
}




void loop() {
  // Kod hanya akan bertindak jika ada data yang dihantar melalui Bluetooth
  if (my_bluetooth.available() > 0) {
    char dat = my_bluetooth.read(); // Membaca data dari Bluetooth
    Serial.print("Arahan Bluetooth diterima: ");
    Serial.println(dat);


    //----------speed-------------------
    if (dat == '0'){
      vSpeed=0;
      Serial.println(dat);}
    else if (dat == '1'){
      vSpeed=50;
      Serial.println(dat);}
    else if (dat == '2'){
      vSpeed=100;
      Serial.println(dat);}
    else if (dat == '3'){
      vSpeed=150;
      Serial.println(dat);}
    else if (dat == '4'){
      vSpeed=200;
      Serial.println(dat);}




    // Logik pergerakan motor dari kod terkini anda dimasukkan di sini
    if (dat == 'B') { // UNDUR
      analogWrite(motorkananA1, LOW);
      analogWrite(motorkananA2, vSpeed);
      analogWrite(motorkiriB1, vSpeed);
      analogWrite(motorkiriB2, LOW);
      Serial.println("Motor Gerak ke BELAKANG");
    }
    else if (dat == 'F') { // DEPAN
      analogWrite(motorkananA1, vSpeed);
      analogWrite(motorkananA2, LOW);
      analogWrite(motorkiriB1, LOW);
      analogWrite(motorkiriB2, vSpeed);
      Serial.println("Motor Gerak ke DEPAN");
    }
    else if (dat == 'S') { // BERHENTI
      analogWrite(motorkananA1, LOW);
      analogWrite(motorkananA2, LOW);
      analogWrite(motorkiriB1, LOW);
      analogWrite(motorkiriB2, LOW);
      Serial.println("Motor BERHENTI");
    }
      //kod kiri dan kanan telah dibetulkan
    else if (dat == 'L') { // KIRI (Sweep Turn)
      analogWrite(motorkananA1, LOW);
      analogWrite(motorkananA2, LOW);
      analogWrite(motorkiriB1, LOW);
      analogWrite(motorkiriB2, vSpeed);
      Serial.println("Motor Pusing ke KIRI");
    }
    else if (dat == 'R') { // KANAN (Sweep Turn)
      analogWrite(motorkananA1, vSpeed);
      analogWrite(motorkananA2, LOW);
      analogWrite(motorkiriB1, LOW);
      analogWrite(motorkiriB2, LOW);
      Serial.println("Motor Pusing ke KANAN");
    }
  }
}





