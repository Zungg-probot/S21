#include <stdio.h>

int main() {
    FILE *file = fopen("bt01.txt", "r");

    if(file == NULL){
        printf("Khong the mo file da ghi\n");
        return 1;
    }
    char c = fgetc(file);
    printf("Ky tu dau tien trong file: '%c'\n", c);

    fclose(file);

    return 0;
}

