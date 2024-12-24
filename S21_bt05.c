#include <stdio.h>

int main() {
    int sodong;
    char chuoi[100];

    printf("Nhap so dong can ghi vao file: ");
    scanf("%d", &sodong);

    FILE *file = fopen("bt05.txt", "w");
    if(file == NULL){
        printf("Khong the mo file de ghi\n");
        return 1;
    }
    getchar();
    for(int i = 0; i < sodong; i++){
        printf("Nhap noi dung dong %d: ",i+1);
        fgets(chuoi, 100, stdin);
        fputs(chuoi, file);
    }
    fclose(file);

    file = fopen("bt05.txt", "r");
    if(file == NULL){
        printf("Khong the mo file de doc\n");
        return 1;
    }
    printf("\nNoi dung cua file:\n");
    while(fgets(chuoi, 100, file) != NULL){
        printf("%s", chuoi);
    }
    fclose(file);

    return 0;
}

