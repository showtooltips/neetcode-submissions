struct Array {
    int *addr;
    int size;
    int capacity;
} global_arr;

Array build(int capacity) {
    Array arr;
    arr.size = 0;
    arr.capacity = capacity;
    arr.addr = (int*) malloc(capacity * sizeof *global_arr.addr); // allocates capacity * 4 (bytes) because addr is of int type
    return arr;
}

class DynamicArray {
public:

    DynamicArray(int capacity) {
        global_arr = build(capacity);
    }

    int get(int i) {
        return global_arr.addr[i];
    }

    void set(int i, int n) {
        global_arr.addr[i] = n;
    }

    void pushback(int n) {
        if (global_arr.size == global_arr.capacity) {
            resize();
        }
        int idx = global_arr.size == 0 ? 0 : global_arr.size;
        global_arr.addr[idx] = n;
        global_arr.size++;
    }

    int popback() {
        int lastElement = global_arr.addr[global_arr.size - 1];
        Array *a = &global_arr;
        --a->size; // reads a->size; subtracts 1; store the result back into a->size
        return lastElement;
    }

    void resize() {
        Array new_arr = build(global_arr.capacity * 2);
        new_arr.size = global_arr.size;

        for (size_t i = 0; i < global_arr.size; i++) {
            new_arr.addr[i] = global_arr.addr[i];
        }
        global_arr = new_arr;
    }

    int getSize() {
        return global_arr.size;
    }

    int getCapacity() {
        return global_arr.capacity;
    }
};
