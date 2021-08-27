#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nextRandom(int prev) {
    if (prev == 0) {
        srand((unsigned) time(NULL));
    } else {
        srand(prev);
    }
    return rand();
}

//messIndex
void messIndex(int size, int *resortIndex) {
    int prevRandom = 0;
    char getTag[size];
    for (int i = 0; i < size; i = i + 1) {
        getTag[i] = 0;
    }
    for (int i = 0; i < size; i = i + 1) {
        prevRandom = nextRandom(prevRandom);
        int nextIndex = prevRandom % size;
        //get next nextIndex
        if (getTag[nextIndex] == 1) {
            int left = nextIndex;
            int right = nextIndex;
            while (1 == 1) {
                if (right < size - 1) {
                    right = right + 1;
                    if (getTag[right] == 0) {
                        nextIndex = right;
                        break;
                    }
                }
                if (left > 0) {
                    left = left - 1;
                    if (getTag[left] == 0) {
                        nextIndex = left;
                        break;
                    }
                }
            };
        }
        getTag[nextIndex] = 1;
        resortIndex[i] = nextIndex;
    }
}


int check(int size, const int *resortIndex) {
    int errorCount = 0;
    char temp[size];
    for (int i = 0; i < size; ++i) {
        temp[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        if (temp[resortIndex[i]] == 1) {
            printf("repeat:%d:%d\n", size, resortIndex[i]);
        }
        temp[resortIndex[i]] = 1;
    }

    for (int i = 0; i < size; ++i) {
        if (temp[i] != 1) {
            errorCount++;
            printf("size:%d,index:%d,actual index: %d\n", size, i, resortIndex[i]);
        }
    }
    if (errorCount > 0) {
        return 0;
    }
    return 1;
}

int testResort(int times) {
    int errorCount = 0;
    for (int i = 0; i < times; ++i) {
        //test messIndex
        int count = i;
        int indexArr[count];
        for (int j = 0; j < count; ++j) {
            indexArr[j] = j;
        }
        messIndex(count, indexArr);

        int checkResult = check(count, indexArr);
        if (checkResult == 0) {
            errorCount++;
        }
    }
    return errorCount;
}

int main() {
    //test resort
    int failCount = testResort(1000);
    printf("failed count:%d\n", failCount);
    return 0;
}