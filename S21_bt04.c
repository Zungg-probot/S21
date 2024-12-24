#include <stdio.h>

int main() {
    FILE *file = fopen("bt01.txt", "r");

    if(file == NULL){
        printf("Khong the mo file da ghi\n");
        return 1;
    }

    char dong[100];
    if(fgets(dong, 100, file) != NULL){
        printf("Dong dau tien trong file: %s\n", dong);
    }else{
        printf("File khong co noi dung\n");
    }
    fclose(file);

    return 0;
}
