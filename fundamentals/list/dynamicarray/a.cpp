#include <cstdio>

// 

int darray_size = 0;
int darray_capacity = 1024;
int darray_capacity_delta = 1024;
int* darray;

void DarrayPush(int new_value) {
  // if darray is fulll reallocate memory
  if (darray_size == darray_capacity) {
    int new_capacity = darray_capacity + darray_capacity_delta;
    int* new_arr = new int[new_capacity];
    // copy legacy array
    for (int i = 0; i < darray_size; ++i) {
      new_arr[i] = darray[i];
    }
    // delete legacy array, change to new array
    if (darray)
      delete [] darray;
    darray = new_arr;
    darray_capacity = new_capacity;
  }
  // push new_value
  darray[darray_size++] = new_value;
}

int main() {
  darray = new int[darray_capacity];
  DarrayPush(3);
  return 0;
}

