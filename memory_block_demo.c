#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

# define ZERO_ASCII 48

static const uint32_t key_count_bytes = 4;

static const uint32_t key_length_index = 0;
static const uint32_t key_length_bytes = 4;
static const uint32_t value_length_bytes = 4;
static const uint32_t value_length_index = key_length_bytes;
static const uint32_t key_fixed_space = 100;
static const uint32_t key_fixed_space_index = value_length_index + value_length_bytes;
static const uint32_t value_fixed_space = 500;
static const uint32_t value_fixed_space_index = key_fixed_space_index + key_fixed_space;
static const uint32_t single_param_size = key_length_bytes + value_length_bytes + key_fixed_space + value_fixed_space;

uint32_t get_length(uint32_t value) {
    uint32_t length = 1;
    while ((value = value / 10) > 0) {
        length++;
    }
    return length;
}

char *intToStringFourByte(uint32_t value) {
    uint32_t value_length = 4;

    char *result = malloc(value_length + 1);
    for (int i = 0; i < value_length; ++i) {
        result[i] = (char) (0 + ZERO_ASCII);
    }
    result[value_length] = '\0';

    if (value == 0) {
        result[0] = '0';
        return result;
    }


    //value != 0
    uint32_t index = value_length - 1;
    while (value > 0) {
        uint32_t modValue = value % 10;
        result[index] = (char) (modValue + ZERO_ASCII);
        index--;
        value = value / 10;
    }

    return result;
}

uint32_t stringToIntFourByte(const char *value) {
    uint32_t result = 0;
    uint64_t length = strlen(value);
    for (int i = 0; i < length; ++i) {
        result = result * 10 + (uint32_t) (value[i] - ZERO_ASCII);
    }
    return result;
}

char *intToString(uint32_t value) {
    uint32_t value_length = get_length(value);

    char *result = malloc(value_length + 1);
    for (int i = 0; i < value_length; ++i) {
        result[i] = (char) (0 + ZERO_ASCII);
    }
    result[value_length] = '\0';

    if (value == 0) {
        result[0] = '0';
        return result;
    }


    //value != 0
    uint32_t index = value_length - 1;
    while (value > 0) {
        uint32_t modValue = value % 10;
        result[index] = (char) (modValue + ZERO_ASCII);
        index--;
        value = value / 10;
    }

    return result;
}

uint32_t stringToInt(const char *value) {
    uint32_t result = 0;
    uint64_t length = strlen(value);
    for (int i = 0; i < length; ++i) {
        result = result * 10 + (uint32_t) (value[i] - ZERO_ASCII);
    }
    return result;
}

char *alloc_memory(uint32_t paramCount) {
    return malloc(paramCount * single_param_size);
}

typedef struct KeyValue {
    char *key;
    char *value;
} KV;


void writeData(char *startPoint, const char *data, uint32_t length) {
    for (int i = 0; i < length; ++i) {
        startPoint[i] = data[i];
    }
}

int write(char *startPoint, KV *dataList, int length) {
    //write data count to first line
    char *count = intToStringFourByte(length);
    writeData(startPoint, count, strlen(count));

    //next line
    startPoint += single_param_size;
    for (int i = 0; i < length; ++i) {
        if (strlen(dataList[i].key) > key_fixed_space) {
            return -1;
        }
        if (strlen(dataList[i].value) > value_fixed_space) {
            return -2;
        }
        //keyLength
        char *keyLength = intToStringFourByte(strlen(dataList[i].key));
        writeData(startPoint + key_length_index, keyLength, key_length_bytes);
        //valueLength
        char *valueLength = intToStringFourByte(strlen(dataList[i].value));
        writeData(startPoint + value_length_index, valueLength, value_length_bytes);
        //keyLength data
        writeData(startPoint + key_fixed_space_index, dataList[i].key, strlen(dataList[i].key));
        //valueLength data
        writeData(startPoint + value_fixed_space_index, dataList[i].value, strlen(dataList[i].value));
        startPoint += single_param_size;
    }
    return 0;
}

char *readData(const char *startPoint, uint32_t length) {
    char *result = malloc(length + 1);
    for (int i = 0; i < length; ++i) {
        result[i] = startPoint[i];
    }
    result[length] = '\0';
    return result;
}

KV *read(char *start_point) {
    uint32_t count = stringToIntFourByte(readData(start_point, key_count_bytes));
    KV *result = malloc(sizeof(KV) * count);
    start_point += single_param_size;
    for (int i = 0; i < count; ++i) {
        uint32_t key_length = stringToIntFourByte(readData(start_point + key_length_index, key_length_bytes));
        uint32_t value_length = stringToIntFourByte(readData(start_point + value_length_index, value_length_bytes));

        char *key = readData(start_point + key_fixed_space_index, key_length);
        char *value = readData(start_point + value_fixed_space_index, value_length);
        KV kv;
        kv.key = key;
        kv.value = value;
        result[i] = kv;
        start_point += single_param_size;
    }
    return result;
}

int main() {
    int paramCount = 5120;
    char *start_address = alloc_memory(paramCount + 1);
    char *write_point = start_address;
    char *read_point = start_address;

    KV data[paramCount];
    for (uint32_t i = 0; i < paramCount; ++i) {
        KV kv;
        char *k = intToString(i);
        kv.key = malloc(strlen(k) + 1);
        kv.value = malloc(strlen(k) + 1);
        for (int j = 0; j < strlen(k); ++j) {
            kv.key[j] = k[j];
            kv.value[j] = k[j];
        }
        kv.key[strlen(k)] = '\0';
        kv.value[strlen(k)] = '\0';
        data[i] = kv;
    }

    write(write_point, data, paramCount);

    KV *kv = read(read_point);

    for (int i = 0; i < paramCount; ++i) {
        printf("%s:%s\n", kv[i].key, kv[i].value);
    }
}
