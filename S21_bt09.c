#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char name[50];
    char author[50];
    float price;
    char category[30];
};

int main() {
    struct Book book[100];
    int size;
    FILE *file;
    int chose;
    do {
        printf("\tMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chose);

        switch (chose){
            case 1:
                printf("Nhap so luong sach: ");
                scanf("%d", &size);
                for (int i = 0; i < size; i++){
                    printf("Ma sach: ");
                    scanf("%d", &book[i].id);
                    getchar();
                    printf("Ten sach: ");
                    fgets(book[i].name, sizeof(book[i].name), stdin);
                    book[i].name[strcspn(book[i].name, "\n")] = '\0';
                    printf("Tac gia: ");
                    fgets(book[i].author, sizeof(book[i].author), stdin);
                    book[i].author[strcspn(book[i].author, "\n")] = '\0';
                    printf("Gia tien: ");
                    scanf("%f", &book[i].price);
                    getchar();
                    printf("The loai: ");
                    fgets(book[i].category, sizeof(book[i].category), stdin);
                    book[i].category[strcspn(book[i].category, "\n")] = '\0';
                }
                break;
            case 2:
                file = fopen("book.bin", "wb");
                if(file == NULL){
                    printf("Khong the mo file\n");
                    break;
                }
                fwrite(&size, sizeof(int), 1, file);
                fwrite(book, sizeof(struct Book), size, file);
                fclose(file);
                printf("Da luu thong tin sach vao file\n");
                break;
            case 3:
                file = fopen("books.bin", "rb");
                if(file == NULL){
                    printf("Khong the mo file\n");
                    break;
                }
                fread(&size, sizeof(int), 1, file);
                fread(book, sizeof(struct Book), size, file);
                fclose(file);
                printf("Da lay thong tin sach tu file\n");
                break;
            case 4:
                if(size == 0){
                    printf("Khong co thong tin sach nao\n");
                }else{
                    for (int i = 0; i < size; i++){
                        printf("Sach %d:\n", i + 1);
                        printf("Ma sach: %d\n", book[i].id);
                        printf("Ten sach: %s\n", book[i].name);
                        printf("Tac gia: %s\n", book[i].author);
                        printf("Gia tien: %f\n", book[i].price);
                        printf("The loai: %s\n", book[i].category);
                        printf("\n");
                    }
                }
                break;
            case 5:
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (chose != 5);
}

