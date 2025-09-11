#include <stdio.h>

int tmax(void) {
    int x = 0xFF;
   return ~(x << 31);
}

int main() {
    int result = tmax();
    printf("tmax = %d\n", result);
    return 0;
}