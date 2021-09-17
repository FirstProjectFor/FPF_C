#include <stdio.h>
#include <pthread.h>
#include <assert.h>

void *printName(void *name) {
    for (int i = 0; i < 10; ++i) {
        printf("name is: %s\n", (char *) name);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int rc;
    printf("main begin.\n");
    rc = pthread_create(&t1, NULL, printName, "A");
    assert(rc == 0);
    rc = pthread_create(&t2, NULL, printName, "B");
    assert(rc == 0);
    //join to wait thread run finished

    rc = pthread_join(t1, NULL);
    assert(rc == 0);

    rc = pthread_join(t2, NULL);
    assert(rc == 0);

    printf("main begin.\n");
    return 0;
}