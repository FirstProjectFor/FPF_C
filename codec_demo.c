#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct CodecItem {
    char *key;
    char *value;
} CodecItem1;

uint32_t readInt(const char *data, int start) {
    uint32_t first = (uint32_t) data[start];
    uint32_t second = (uint32_t) data[start + 1] << 8;
    uint32_t third = (uint32_t) data[start + 2] << 16;
    uint32_t fourth = (uint32_t) data[start + 3] << 24;
    return first + second + third + fourth;
}

void writeInt(char *data, int start, uint32_t value) {
    data[start] = (char) value;
    data[start + 1] = (char) (value >> 8);
    data[start + 2] = (char) (value >> 16);
    data[start + 3] = (char) (value >> 24);
}


void unmarshal(char data[], int start, uint32_t rowCount, CodecItem1 result[]) {
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
        start = start + 4;
        uint32_t keyLength = readInt(data, start);
        start = start + 4;
        CodecItem1 row;
        char *key = malloc(keyLength + 1);
        key[keyLength] = '\0';
        memset(key, 0, keyLength);
        for (int keyIndex = 0; keyIndex < keyLength; ++keyIndex) {
            key[keyIndex] = data[start];
            start++;
        }
        row.key = key;
        start = start + 4;
        uint32_t valueLength = readInt(data, start);
        start = start + 4;
        char *value = malloc(valueLength);
        memset(value, 0, valueLength);
        value[valueLength] = '\0';
        for (int valueIndex = 0; valueIndex < valueLength; ++valueIndex) {
            value[valueIndex] = data[start];
            start++;
        }
        row.value = value;
        result[rowIndex] = row;
    }
}

void marshal(char *result, uint32_t rowCount, CodecItem1 data[]) {
    int start = 0;
    writeInt(result, start, rowCount);
    start = start + 4;
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
        uint32_t keyLength = (uint32_t) strlen(data[rowIndex].key);
        writeInt(result, start, keyLength);
        start = start + 4;
        for (int keyIndex = 0; keyIndex < keyLength; ++keyIndex) {
            result[start] = data[rowIndex].key[keyIndex];
            start = start + 1;
        }
        data[rowIndex].key;
        uint32_t valueLength = (uint32_t) strlen(data[rowIndex].value);
        writeInt(result, start, valueLength);
        start = start + 4;
        for (int valueIndex = 0; valueIndex < valueLength; ++valueIndex) {
            result[start] = data[rowIndex].value[valueIndex];
            start = start + 1;
        }
    }
}

int main() {
    char bbb[] = {18, 0, 0, 0, 1, 0, 0, 0, 6, 0, 0, 0, 98, 100, 99, 100, 121, 104, 1, 0, 0, 0, 28, 0, 0, 0, 49, 49, 48,
                  49, 48, 53, 48, 49, 50, 48, 48, 49, 71, 66, 48, 48, 51, 49, 52, 70, 48, 48, 48, 51, 48, 48, 53, 53, 1,
                  0, 0, 0, 15, 0, 0, 0, 99, 97, 110, 99, 101, 108, 114, 105, 103, 104, 116, 100, 97, 116, 101, 1, 0, 0,
                  0, 0, 0, 0, 0, 1, 0, 0, 0, 6, 0, 0, 0, 99, 101, 114, 116, 110, 111, 1, 0, 0, 0, 36, 0, 0, 0, 228, 186,
                  172, 229, 164, 174, 40, 50, 48, 50, 48, 41, 229, 184, 130, 228, 184, 141, 230, 135, 130, 228, 186,
                  167, 230, 157, 131, 231, 172, 172, 48, 48, 48, 48, 48, 52, 1, 0, 0, 0, 15, 0, 0, 0, 99, 114, 101, 97,
                  116, 101, 114, 105, 103, 104, 116, 100, 97, 116, 101, 1, 0, 0, 0, 9, 0, 0, 0, 50, 48, 50, 49, 47,
                  54, 47, 50, 52, 1, 0, 0, 0, 4, 0, 0, 0, 102, 119, 120, 122, 1, 0, 0, 0, 9, 0, 0, 0, 229, 149, 134,
                  229, 147, 129, 230, 136, 191, 1, 0, 0, 0, 4, 0, 0, 0, 103, 104, 121, 116, 1, 0, 0, 0, 6, 0, 0, 0, 228,
                  189, 143, 229, 174, 133, 1, 0, 0, 0, 2, 0, 0, 0, 105, 100, 1, 0, 0, 0, 1, 0, 0, 0, 53, 1, 0, 0, 0, 10,
                  0, 0, 0, 105, 115, 95, 100, 105, 115, 115, 101, 110, 116, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 15, 0,
                  0, 0, 105, 115, 95, 109, 111, 114, 116, 102, 111, 114, 101, 99, 97, 115, 116, 1, 0, 0, 0, 1, 0, 0, 0,
                  48, 1, 0, 0, 0, 11, 0, 0, 0, 105, 115, 95, 109, 111, 114, 116, 103, 97, 103, 101, 1, 0, 0, 0, 1, 0, 0,
                  0, 48, 1, 0, 0, 0, 11, 0, 0, 0, 105, 115, 95, 114, 101, 115, 116, 114, 105, 99, 116, 1, 0, 0, 0, 0, 0,
                  0, 0, 1, 0, 0, 0, 7, 0, 0, 0, 105, 115, 118, 97, 108, 105, 100, 1, 0, 0, 0, 1, 0, 0, 0, 49, 1, 0, 0,
                  0, 4, 0, 0, 0, 106, 122, 109, 106, 1, 0, 0, 0, 7, 0, 0, 0, 50, 50, 56, 48, 46, 54, 49, 1, 0, 0, 0, 3,
                  0, 0, 0, 113, 108, 114, 1, 0, 0, 0, 9, 0, 0, 0, 229, 173, 153, 233, 163, 158, 233, 190, 153, 1, 0, 0,
                  0, 6, 0, 0, 0, 113, 108, 114, 122, 106, 104, 1, 0, 0, 0, 18, 0, 0, 0, 49, 49, 48, 48, 48, 48, 48, 48,
                  48, 48, 48, 48, 48, 48, 48, 49, 51, 49, 1, 0, 0, 0, 7, 0, 0, 0, 113, 108, 114, 122, 106, 108, 120, 1,
                  0, 0, 0, 9, 0, 0, 0, 232, 186, 171, 228, 187, 189, 232, 175, 129, 1, 0, 0, 0, 5, 0, 0, 0, 114, 97,
                  116, 105, 111, 1, 0, 0, 0, 3, 0, 0, 0, 49, 48, 48, 1, 0, 0, 0, 2, 0, 0, 0, 122, 108, 1, 0, 0, 0, 27,
                  0, 0, 0, 229, 140, 151, 228, 186, 172, 232, 191, 144, 230, 178, 179, 229, 178, 184, 228, 184, 138,
                  231, 154, 1, 32, 233, 153, 162, 229, 173, 144};

    CodecItem1 c1;
    int start = 0;
    uint32_t rowCount = readInt(bbb, start);
    printf("read data row count: %d\n", rowCount);
    start = start + 4;
    CodecItem1 result1[rowCount];
    unmarshal(bbb, start, rowCount, result1);
    printf("unmarshal: %p\n", result1);
    for (int i = 0; i < rowCount; ++i) {
        printf("unmarshal   key: %s\n", result1[i].key);
        printf("unmarshal value: %s\n", result1[i].value);
    }
    return 0;
}