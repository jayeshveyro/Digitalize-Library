#include <SPI.h>
#include <MFRC522.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#define RFID_SS   5
#define RFID_RST  22
#define TFT_CS    17
#define TFT_DC    16
#define TFT_RST   21


#define BUZZER    25
#define ISSUE_BTN 26
#define RETURN_BTN 27

// SPI pins
#define SPI_SCK   18
#define SPI_MISO  19
#define SPI_MOSI  23

MFRC522 rfid(RFID_SS, RFID_RST);

Adafruit_ILI9341 tft(
  TFT_CS,
  TFT_DC,
  TFT_RST
);


struct Student {
  String uid;
  String name;
  String className;
};

struct Book {
  String barcode;
  String title;
  bool issued;
  String issuedTo;
};

Student students[] = {

   {"43:A7:2C:19", "Test Student", "Class 10"},

};

const int studentCount =
  sizeof(students) / sizeof(students[0]);

Book books[] = {

  {"9780132350884", "Programming Basics", false, ""},
  {"9780000000001", "Science", false, ""},
  {"9780000000002", "Mathematics", false, ""},
  {"9780000000003", "English Literature", false, ""}

  };

  const int bookCount =
  sizeof(books) / sizeof(books[0]);

String currentStudentName = "";

enum Mode {
  SELECT_MODE,
  ISSUE_MODE,
  RETURN_MODE
};

Mode currentMode = SELECT_MODE;

void setup() {

  Serial.begin(115200);

  // Buttons
  pinMode(ISSUE_BTN, INPUT_PULLUP);
  pinMode(RETURN_BTN, INPUT_PULLUP);

  // Buzzer
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  // SPI
  SPI.begin(
    SPI_SCK,
    SPI_MISO,
    SPI_MOSI
  );

   // RFID
  rfid.PCD_Init();

  // TFT
  tft.begin();
  tft.setRotation(1);

  showStartup();

  delay(2000);

  showHome();

   Serial.println();
  Serial.println("==============================");
  Serial.println(" SCHOOL LIBRARY SYSTEM");
  Serial.println("==============================");
  Serial.println("System ready.");
  Serial.println("Tap RFID card...");
}

void loop() {

  if (digitalRead(ISSUE_BTN) == LOW) {
    currentMode = ISSUE_MODE;
    beep(1);
    showMode("ISSUE BOOK");
    delay(300);
    waitForStudent();
    return;
  }


  if (digitalRead(RETURN_BTN) == LOW) {
    currentMode = RETURN_MODE;
    beep(1);
    showMode("RETURN BOOK");
    delay(300);
    waitForStudent();
    return;
  }

  if (digitalRead(RETURN_BTN) == LOW) {
    currentMode = RETURN_MODE;
    beep(1);
    showMode("RETURN BOOK");
    delay(300);
    waitForStudent();
    return;
  }

    if (Serial.available()) {
    String barcode = Serial.readStringUntil('\n');
    barcode.trim();
    if (barcode.length() > 0) {
      Serial.print("Barcode received: ");
      Serial.println(barcode);
      processBarcode(barcode);
    }
  }
   delay(50);
}

void showStartup() {
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.setCursor(35, 70);
  tft.println("SCHOOL");
  tft.setCursor(40, 110);
  tft.println("LIBRARY");
  tft.setTextSize(2);
  tft.setCursor(70, 160);
  tft.println("SYSTEM");
  beep(1);
}

void showHome() {
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.setCursor(65, 25);
  tft.println("LIBRARY");
  tft.setTextSize(2);
  tft.setCursor(45, 85);
  tft.println("Select Action");
  tft.drawRect(25, 125, 115, 55, ILI9341_WHITE);
  tft.setCursor(45, 145);
  tft.println("ISSUE");
  tft.drawRect(160, 125, 115, 55, ILI9341_WHITE);
  tft.setCursor(180, 145);
  tft.println("RETURN");
  tft.setTextSize(1);
  tft.setCursor(70, 205);
  tft.println("Tap RFID card after selecting");
  tft.setCursor(85, 220);
  tft.println("an operation");
}

void showMode(String mode) {
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.setCursor(45, 30);
  tft.println(mode);
  tft.setTextSize(2);
  tft.setCursor(55, 100);
  tft.println("Tap student");
  tft.setCursor(85, 130);
  tft.println("RFID card");
  tft.setTextSize(1);
  tft.setCursor(85, 180);
  tft.println("Waiting...");
}

void waitForStudent() {
  Serial.println();
  Serial.println("------------------------------");
  if (currentMode == ISSUE_MODE) {
    Serial.println("ISSUE MODE");
  }
  else {
    Serial.println("RETURN MODE");
  }
  Serial.println("Waiting for RFID card...");
  while (true) {

    if (rfid.PICC_IsNewCardPresent() &&
        rfid.PICC_ReadCardSerial()) {
      String uid = getUID();
      Serial.print("RFID UID: ");
      Serial.println(uid);
      int studentIndex = findStudent(uid);
      if (studentIndex == -1) {
        showError("Unknown Card");
        Serial.println("Unknown RFID card.");
        beepError();
        delay(2500);
        showHome();
        return;
      }
      currentStudent = students[studentIndex].uid;
      currentStudentName =
        students[studentIndex].name;

      showStudent(
        students[studentIndex].name,
        students[studentIndex].className
      );
      beepSuccess();
      delay(1800);

      if (currentMode == ISSUE_MODE) {
        showScanBook("SCAN BOOK");
        Serial.println();
        Serial.println("Student:");
        Serial.println(currentStudentName);
        Serial.println("Scan/enter book barcode...");
      }
      else {
        showScanBook("SCAN RETURN");
        Serial.println();
        Serial.println("Student:");
        Serial.println(currentStudentName);
        Serial.println("Scan/enter returned book barcode...");
      }
      
      while (true) {
        if (Serial.available()) {
          String barcode =
            Serial.readStringUntil('\n');
          barcode.trim();
          if (barcode.length() > 0) {
            processBarcode(barcode);
            return;
          }
        }
        delay(20);
      }
    }
    delay(50);
  }
}

String getUID() {
  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) {
      uid += "0";
    }
    uid += String(
      rfid.uid.uidByte[i],
      HEX
    );
    if (i < rfid.uid.size - 1) {
      uid += ":";
    }
  }
  uid.toUpperCase();
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  return uid;
}

int findStudent(String uid) {
  uid.toUpperCase();
  for (int i = 0; i < studentCount; i++) {
    String storedUID =
      students[i].uid;
    storedUID.toUpperCase();
    if (storedUID == uid) {
      return i;
    }
  }
  return -1;
}

int findBook(String barcode) {
  for (int i = 0; i < bookCount; i++) {
    if (books[i].barcode == barcode) {
      return i;
    }
  }
  return -1;
}

void processBarcode(String barcode) {
  Serial.println();
  Serial.print("Processing barcode: ");
  Serial.println(barcode);
  int bookIndex = findBook(barcode);

  if (bookIndex == -1) {
    showError("Book Not Found");
    Serial.println("Book does not exist.");
    beepError();
    delay(2500);
    showHome();
    return;
  }

  if (currentMode == ISSUE_MODE) {
    issueBook(bookIndex);
    return;
  }

  if (currentMode == RETURN_MODE) {
    returnBook(bookIndex);
    return;
  }
}

void issueBook(int bookIndex) {
  Book &book = books[bookIndex];


  if (book.issued) {
    showError("Already Issued");

    Serial.println();
    Serial.println("BOOK ALREADY ISSUED");
    Serial.print("Issued to: ");
    Serial.println(book.issuedTo);

    beepError();
    delay(3000);
    showHome();
    return;
  }

  book.issued = true;
  book.issuedTo = currentStudent;

  Serial.println();
  Serial.println("==============================");
  Serial.println("BOOK ISSUED");
  Serial.println("==============================");
  Serial.print("Student: ");
  Serial.println(currentStudentName);
  Serial.print("Book: ");
  Serial.println(book.title);
  Serial.print("Barcode: ");
  Serial.println(book.barcode);

  showSuccess(
    "BOOK ISSUED",
    book.title
  );
  beepSuccess();
  delay(3500);
  resetSession();
  showHome();
}

void returnBook(int bookIndex) {
  Book &book = books[bookIndex];

  if (!book.issued) {
    showError("Not Issued");

    Serial.println();
    Serial.println("BOOK IS NOT CURRENTLY ISSUED");

    beepError();
    delay(3000);
    showHome();
    return;
  }

  if (book.issuedTo != currentStudent) {
    showError("Wrong Student");

    Serial.println();
    Serial.println("This book is registered to another student.");

    beepError();
    delay(3000);
    showHome();
    return;
  }

  book.issued = false;
  book.issuedTo = "";

  Serial.println();
  Serial.println("==============================");
  Serial.println("BOOK RETURNED");
  Serial.println("==============================");
  Serial.print("Student: ");
  Serial.println(currentStudentName);
  Serial.print("Book: ");
  Serial.println(book.title);

  showSuccess(
    "BOOK RETURNED",
    book.title
  );
  beepSuccess();
  delay(3500);
  resetSession();
  showHome();
}

void showStudent(
  String name,
  String className
) {
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(60, 20);
  tft.println("STUDENT");
  tft.setTextSize(3);
  tft.setCursor(30, 70);
  tft.println(name);
  tft.setTextSize(2);
  tft.setCursor(85, 125);
  tft.println(className);
  tft.setCursor(55, 180);
  tft.println("Card accepted");
}

void showScanBook(String title) {
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.setCursor(35, 25);
  tft.println(title);
  tft.setTextSize(2);
  tft.setCursor(60, 100);
  tft.println("Scan barcode");
  tft.setCursor(70, 135);
  tft.println("of book");
  tft.setTextSize(1);
  tft.setCursor(75, 190);
  tft.println("Waiting for barcode...");
}

void showSuccess(
  String title,
  String bookTitle
) {
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.setCursor(45, 25);
  tft.println("SUCCESS");
  tft.setTextSize(2);
  tft.setCursor(55, 80);
  tft.println(title);
  tft.setTextSize(1);
  tft.setCursor(25, 140);
  tft.println(bookTitle);
  tft.setCursor(75, 190);
  tft.println("Transaction complete");
}

void showError(String message) {
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.setCursor(75, 35);
  tft.println("ERROR");
  tft.setTextSize(2);
  tft.setCursor(40, 110);
  tft.println(message);
}

void resetSession() {

  currentStudent = "";
  currentStudentName = "";
  currentMode = SELECT_MODE;
}

void beep(int count) {
  for (int i = 0; i < count; i++) {

    digitalWrite(BUZZER, HIGH);

    delay(100);

    digitalWrite(BUZZER, LOW);

    delay(100);
  }
}

void beepSuccess() {
  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
  delay(100);
  digitalWrite(BUZZER, HIGH);
  delay(200);
  digitalWrite(BUZZER, LOW);
}

void beepError() {
  digitalWrite(BUZZER, HIGH);
  delay(500);
  digitalWrite(BUZZER, LOW);
}

