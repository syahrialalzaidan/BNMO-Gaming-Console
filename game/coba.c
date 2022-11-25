#include <stdio.h>

int main() {
    int i = 1;
    int n = 6;
    for (int j = 1; j < n; j++) {
        i *= 2;
        i++;
    }
    printf("%d", i);
    return 0;
}
// 31