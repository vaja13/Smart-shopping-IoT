#include <Arduino.h>
#include <Wire.h>
#include <MFRC522.h>
#include <SPI.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

char input[12];
int count = 0;
int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
double total = 0;
int count_prod = 0;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("HELLO :)");
  Serial.println("WELCOME TO THE SMARTMART |_/");
  Serial.println("                         O O");
}

void loop() {
  count = 0;
  while (Serial.available() && count < 12) {
    input[count] = Serial.read();
    count++;
    delay(5);
  }

  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String cardUID = "";

    for (byte i = 0; i < mfrc522.uid.size; i++) {
      cardUID += (mfrc522.uid.uidByte[i] < 0x10 ? "0" : "") + String(mfrc522.uid.uidByte[i]);
    }

    // Ensure cardUID has 12 characters, if not, pad it with zeros
    while (cardUID.length() < 12) {
      cardUID = "0" + cardUID;
    }

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();

    // Code for Bill details
    if (cardUID == "011515157221") {
      if (count_prod == 0) {
        Serial.println("No items in the cart");
      }
      Serial.println("<<Products>>      <<Quantity>>");
      if (p1 != 0) {
        Serial.print("Biscuits               ");
        Serial.println(p1);
      }
      if (p2 != 0) {
        Serial.print("Flour                  ");
        Serial.println(p2);
      }
      if (p3 != 0) {
        Serial.print("Butter                 ");
        Serial.println(p3);
      }
      if (p4 != 0) {
        Serial.print("Coffee                 ");
        Serial.println(p4);
      }
      Serial.print("You have purchased a total products : ");
      Serial.println(count_prod);
      Serial.print("Your total is : ");
      Serial.println(total);
      Serial.println("Thank You for visiting the SMARTMART |_/");
      Serial.println("                                     O O");
      total = 0;
      count_prod=0;
    }

    //Code for deleting the previously added item
    if (cardUID == "022712326246") {
      if (count_prod == 0) {
        Serial.println("No items in the cart");
      }
      else
      {
        Serial.println("All products have been released successfully");
        count_prod=0;
        total=0;
        p1=0;
        p2=0;
        p3=0;
        p4=0;
      }
    }
    // Add your handling of the RFID cards here
    if (cardUID == "000323022718") {
      // Card1 is detected
      // Handle the action for Card1

      Serial.println("Biscuits Added - RS 50");
      total += 50;
      count_prod++;
      p1++;
      Serial.print("Total Amount is : RS ");
      Serial.println(total);

    } else if (cardUID == "001634911117") {
      // Card2 is detected
      // Handle the action for Card2
      Serial.println("Flour Added - RS 100");
      total += 100;
      count_prod++;
      p2++;
      Serial.print("Total Amount is : RS ");
      Serial.println(total);

    } else if (cardUID == "009925022217") {
      // Card3 is detected
      // Handle the action for Card3
      Serial.println("Butter Added - RS 45");
      total += 45;
      count_prod++;
      p3++;
      Serial.print("Total Amount is : RS ");
      Serial.println(total);

    } else if (cardUID == "009919720017") {
      // Card4 is detected
      // Handle the action for Card4
      Serial.println("Coffee Added - RS 25");
      total += 25;
      count_prod++;
      p4++;
      Serial.print("Total Amount is : RS ");
      Serial.println(total);
    }
  }
}