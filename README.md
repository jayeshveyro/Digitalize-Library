#  Digitalize Library 

The project makes use of rfid cards  for library cards and a barcode scanner for uploading the books into the database. The rfid library card allows hassle-free issuing and returing of book.

##  Hardware Components

| Component           | Purpose                  |
| ------------------- | ------------------------ |
| ESP32               | Main controller          |
| RC522 RFID Reader   | Reads student RFID cards |
| ILI9341 TFT Display | Displays system status   |
| USB Barcode Scanner | Reads book barcodes      |
| Push Buttons ×2     | Issue / Return selection |
| Buzzer              | Audio feedback           |
| RFID Cards/Tags     | Student identification   |

<img width="3000" height="2676" alt="circuit_image (1)" src="https://github.com/user-attachments/assets/d24124ea-c855-4e1d-ac9b-c65cacb45949" />

## Bill Of Materials
| No. | Component | Specification | Qty. | Unit Price | Total |
|---:|---|---|---:|---:|---:|
| 1 | [RC522 RFID Reader](https://robu.in/product/rc522-rfid-card-reader-module-13-56mhz/) | 1 | ₹93 | ₹93 |
| 2 | [RFID Cards](https://robu.in/product/rfid-13-56mhz-card/) | 1 | ₹51 | ₹51 |
| 3 | [Tactile Switch Caps](https://robu.in/product/round-cap-for-12x12x7-3mm-square-switch-black-pack-of-10/) | 1 | ₹21 | ₹21 |
| 4 | [Tactile Push Buttons](https://robu.in/product/12x12x7-3mm-tactile-push-button-switch-10pcs/) | 1 | ₹58 | ₹58 |
| 5 | [ESP32 Development Board](https://robu.in/product/38pin-cp2102-esp-32-wifibluetooth-development-board-with-type-c-usb-interface/) | 38-Pin CP2102, Wi-Fi + Bluetooth, Type-C | 1 | ₹429 | ₹429 |
| 6 | [TFT LCD Display](https://robu.in/product/2-2-inch-240320-lcd-color-screen-tft-spi-serial-interface-module-compatible-with-5110/) | 1 | ₹679 | ₹679 |
| 7 | [Passive Buzzer](https://robu.in/product/1-month-warranty-1248/) | 1 | ₹47 | ₹47 |
| 8 | [Helett HT410 Barcode Scanner](https://www.amazon.in/helett-HT410-Handheld-Indicator-Induction/dp/B0CBC9G7W2/) | 1 | ₹1,650 | ₹1,650 |
| 9 | [Robu 3D printing services](https://robu.in/services/) | 1 | ₹572 | ₹572 |
| | | **Grand Total** | | | **₹3,600** |
## Rough Sketch for CAD design
<img width="1037" height="1600" alt="rough sketch 3d design" src="https://github.com/user-attachments/assets/1354487a-9e8a-44d1-866e-d59c81d77c2c" />
![image.png](https://cdn.hackclub.com/01a0c52b-1055-7d22-aeb9-6e7125dd740a/image.png)
![image.png](https://cdn.hackclub.com/01a0c52b-66c4-7d3e-9152-99d68b9474e1/image.png)
![image.png](https://cdn.hackclub.com/01a0c52b-a3cd-7949-b94c-b228133506ed/image.png)
![image.png](https://cdn.hackclub.com/01a0c52e-3072-7567-9bf0-fe9845ad9b2d/image.png)
![image.png](https://cdn.hackclub.com/01a0c52f-86e2-7203-8225-2984f2ebf956/image.png)
