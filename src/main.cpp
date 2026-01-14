#include <Arduino.h>

// Seeed XIAO ESP32-C3 引脚映射
// D1 -> GPIO3
// D2 -> GPIO4
const int pinJ2 = 3;   // D1, 连接到 J2 (VOUT1)
const int pinJ3 = 4;   // D2, 连接到 J3 (VOUT2)

void setup() {
    Serial.begin(115200);
    delay(1000);

    // 设置 ADC 分辨率
    analogReadResolution(12);   // 0~4095

    // 设置 ADC 衰减，使量程接近 0~3.3V
    analogSetAttenuation(ADC_11db);  

    Serial.println("ESP32-C3 Voltage Read Start...");
}

void loop() {
    int adcJ2 = analogRead(pinJ2);
    int adcJ3 = analogRead(pinJ3);

    // 将 ADC 值转换为电压（基准 3.3V）
    float voltageJ2 = (adcJ2 / 4095.0) * 3.3;
    float voltageJ3 = (adcJ3 / 4095.0) * 3.3;

    Serial.print("J2 (VOUT1): ADC = ");
    Serial.print(adcJ2);
    Serial.print("  Voltage = ");
    Serial.print(voltageJ2, 3);
    Serial.println(" V");

    Serial.print("J3 (VOUT2): ADC = ");
    Serial.print(adcJ3);
    Serial.print("  Voltage = ");
    Serial.print(voltageJ3, 3);
    Serial.println(" V");

    Serial.println("----------------------------");
    delay(500);
}
