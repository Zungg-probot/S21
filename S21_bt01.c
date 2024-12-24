#include <stdio.h>

int main() {
    char chuoi[100];
    printf("Nhap chuoi can ghi vao file: ");
    fgets(chuoi, 100, stdin);
    
    FILE *file = fopen("bt01.txt", "w");
    if(file == NULL){
        printf("Khong the mo file da ghi\n");
        return 1;
    }
    fputs(chuoi, file);
    fclose(file);

    printf("Da ghi chuoi thanh cong\n");

    return 0;
}
