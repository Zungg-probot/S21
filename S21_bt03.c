#include <stdio.h>

int main() {
	
    char chuoi[100];
    printf("Nhap chuoi can them vao file: ");
    fgets(chuoi, 100, stdin);
    
    FILE *file = fopen("bt01.txt", "a");
    if(file == NULL){
        printf("Khong the mo file da ghi\n");
        return 1;
    }
    fputs(chuoi, file);
    fclose(file);
    printf("Da them chuoi thanh cong\n");
    
    return 0;
}

