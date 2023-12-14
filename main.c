#include <stdio.h>
#include <stdint.h>

#define POLY 0x1021

uint16_t crc_ccitt(const uint8_t *data, size_t length) {
    uint16_t crc = 0xFFFF;

    for (size_t i = 0; i < length; ++i) {
        crc ^= (data[i] << 8);
        for (int j = 0; j < 8; ++j) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ POLY;
            } else {
                crc <<= 1;
            }
        }
    }

    return crc;
}

int main() {
    // テストデータ
    uint8_t data[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};
    size_t length = sizeof(data) / sizeof(data[0]);

    // CRCを計算
    uint16_t result = crc_ccitt(data, length);

    // 結果を表示
    printf("CRC CCITT: 0x%X\n", result);

    return 0;
}