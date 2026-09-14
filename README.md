# 📚 Smart Library Management System

A ESP32 based book issuing project. The project makes use of rfid cards to for library cards and a barcode scanner for uploading the books into the database. The rfid library card allows hassle-free issuing and returing of book.

## 🛠️ Hardware Components

| Component           | Purpose                  |
| ------------------- | ------------------------ |
| ESP32               | Main controller          |
| RC522 RFID Reader   | Reads student RFID cards |
| ILI9341 TFT Display | Displays system status   |
| USB Barcode Scanner | Reads book barcodes      |
| Push Buttons ×2     | Issue / Return selection |
| Buzzer              | Audio feedback           |
| RFID Cards/Tags     | Student identification   |

## Pin Connections

### RC522 RFID

| RC522    | ESP32         |
| -------- | ------------- |
| VCC      | 3.3V          |
| GND      | GND           |
| SDA / SS | GPIO 5        |
| SCK      | GPIO 18       |
| MOSI     | GPIO 23       |
| MISO     | GPIO 19       |
| RST      | GPIO 22       |
| IRQ      | Not connected |

### ILI9341 TFT

| TFT        | ESP32   |
| ---------- | ------- |
| VCC        | 3.3V    |
| GND        | GND     |
| CS         | GPIO 17 |
| RST        | GPIO 21 |
| DC / RS    | GPIO 16 |
| MOSI / SDI | GPIO 23 |
| MISO / SDO | GPIO 19 |
| SCK / CLK  | GPIO 18 |
| LED / BL   | 3.3V    |

### Controls

| Component     | ESP32   |
| ------------- | ------- |
| Issue Button  | GPIO 26 |
| Return Button | GPIO 27 |
| Buzzer +      | GPIO 25 |
| Buzzer −      | GND     |

<img width="3000" height="2676" alt="circuit_image (1)" src="https://github.com/user-attachments/assets/d24124ea-c855-4e1d-ac9b-c65cacb45949" />

## Bill Of Materials
| No. | Component | Specification | Qty. | Unit Price | Total |
|---:|---|---|---:|---:|---:|
| 1 | RC522 RFID Reader | 13.56 MHz RFID Card Reader Module | 1 | ₹93 | ₹93 |
| 2 | RFID Cards | 13.56 MHz, Pack of 5 | 1 | ₹51 | ₹51 |
| 3 | Tactile Switch Caps | 12×12×7.3 mm, Round Cap, Black, Pack of 10 | 1 | ₹21 | ₹21 |
| 4 | Tactile Push Buttons | 12×12×7.3 mm, Pack of 10 | 1 | ₹58 | ₹58 |
| 5 | ESP32 Development Board | 38-Pin CP2102, Wi-Fi + Bluetooth, Type-C | 1 | ₹429 | ₹429 |
| 6 | TFT LCD Display | 2.2", 240×320, Color, SPI | 1 | ₹679 | ₹679 |
| 7 | Passive Buzzer | 5V, Pack of 10 | 1 | ₹47 | ₹47 |
| 8 | Barcode Scanner | HeleTT HT410, 1D + 2D/QR, Wired USB | 1 | ₹1,650 | ₹1,650 |
| | | **Grand Total** | | | **₹3,028** |

## Rough Sketch for CAD design
<img width="1037" height="1600" alt="rough sketch 3d design" src="https://github.com/user-attachments/assets/1354487a-9e8a-44d1-866e-d59c81d77c2c" />



	
