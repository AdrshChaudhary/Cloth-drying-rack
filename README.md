# 🌦 Smart Drying Rack System using Arduino

This project is a smart automation system designed to *extend or retract a clothes drying rack* based on real-time environmental conditions. It utilizes *temperature, **humidity, **rain detection, and **obstacle detection* to make intelligent decisions—helping you dry clothes efficiently while preventing exposure to rain or obstruction.

---

## 🚀 Features

- ✅ *DHT22 Sensor* to monitor *temperature and humidity*
- 🌧 *Rain detection* using a push button (simulated rain sensor)
- 🧱 *Ultrasonic Sensor (HC-SR04)* to detect nearby obstacles
- ⚙ *Servo Motor Control* for rack movement
- 🧠 Smart logic-based automation
- 📟 Real-time feedback on Serial Monitor

---

## 🧠 How It Works

- If it's *raining* or an *obstacle is detected, the rack is **retracted*.
- If *temperature ≥ 25°C* and *humidity ≤ 70%, and there's **no rain or obstacle, the rack is **extended*.
- Otherwise, the rack remains *retracted*.

### ✅ Decision Logic

IF (Rain detected OR Obstacle detected)
-> Retract drying rack
ELSE IF (Temperature ≥ 25°C AND Humidity ≤ 70%)
-> Extend drying rack
ELSE
-> Retract drying rack

## 🛠 Setup & Installation

1. Connect all components according to the pin configuration above.
2. Upload the Arduino code from smart_drying_rack.ino using the Arduino IDE.
3. Open *Serial Monitor* at 9600 baud rate to view live sensor data and system status.
4. Observe how the rack extends or retracts based on sensor inputs.

## ⌛ Timing and Delays

- The system reads sensors and updates every *2 seconds* using delay(2000).
- Ultrasonic distance is calculated using pulseIn().

## 📈 Sample Serial Output

Humidity: 61.20% Temperature: 28.50°C
Obstacle Distance: 34.22 cm
Rain Detected: No
Rack Extended: Conditions Suitable for Drying


## 📦 Future Enhancements

- Replace push button with a *real rain sensor module (YL-83 or FC-37)*
- Add *Wi-Fi or Bluetooth* support for remote monitoring or alerts
- Integrate a *solar intensity sensor* for optimal drying decisions
- Include an *OLED or LCD display* for local visual feedback
- Add *mobile app integration* or *web dashboard*
- Use *weather forecast API* for predictive actions

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

## 🙌 Acknowledgements

Thanks to the following resources and libraries:
- [DHT Sensor Library by Adafruit](https://github.com/adafruit/DHT-sensor-library)
- [Servo Library (Arduino Built-in)](https://www.arduino.cc/en/Reference/Servo)

---

## 👨‍💻 Author

*Aadarsh Chaudhary*  
Electronics and Communication Engineering, GGSIPU
