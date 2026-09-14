# 📚 Smart Library Management System

A smart, low-cost library management system that combines RFID, barcode scanning, and an ESP32 to make issuing and returning books faster, more organized, and easier to track.
The system links a student's RFID ID card with the barcode of a library book, allowing the library to keep track of who has borrowed which book.

## 🎯 Project Goal

The goal of this project is to demonstrate how embedded systems, RFID, barcode technology, and software can be combined to build a practical library automation system.
It is designed to be affordable enough for schools while providing a foundation that can later be expanded into a complete digital library platform.

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


	
