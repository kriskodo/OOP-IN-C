#include <stdio.h>
#include <string.h>

#define MAX_KEYS 10

//const x = {a: 1, b: 2, c: 3};
//const y = { ...x, d: 4 };
//console.log(y);

struct Object {
    char *keys[MAX_KEYS];
    int values[MAX_KEYS];
    int count;
};

void initObject(struct Object *obj) {
    memset(obj, 0, sizeof(struct Object));
}

void setObject(struct Object *obj, char *key, int value) {
    int i;
    for (i = 0; i < obj->count; i++) {
        if (strcmp(key, obj->keys[i]) == 0) {
            obj->values[i] = value;
            return;
        }
    }
    obj->keys[obj->count] = key;
    obj->values[obj->count] = value;
    obj->count++;
}

int main() {
    struct Object x;
    initObject(&x);
    setObject(&x, "a", 1);
    setObject(&x, "b", 2);
    setObject(&x, "c", 3);

    struct Object y;
    initObject(&y);
    int i;
    for (i = 0; i < x.count; i++) {
        setObject(&y, x.keys[i], x.values[i]);
    }
    setObject(&y, "d", 4);

    for (i = 0; i < y.count; i++) {
        printf("%s: %d\n", y.keys[i], y.values[i]);
    }

    return 0;
}