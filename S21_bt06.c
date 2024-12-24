#include <stdio.h>

int main() {
    FILE *filegoc, *filecopy;
    char chuoi[100];

    filegoc = fopen("bt01.txt", "r");
    if(filegoc == NULL){
        printf("Khong the mo file bt01.txt\n");
        return 1;
    }
    
    filecopy = fopen("bt06.txt", "w");
    if(filecopy == NULL){
        printf("Khong the mo file bt06.txt\n");
        fclose(filegoc);
        return 1;
    }
    while(fgets(chuoi, sizeof(chuoi), filegoc) != NULL){
        fputs(chuoi, filecopy);
    }

    printf("Sao chep noi dung tu bt01.txt sang bt06.txt thanh cong\n");
    fclose(filegoc);
    fclose(filecopy);
    return 0;
}

