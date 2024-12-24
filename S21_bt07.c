#include<stdio.h>
#include<string.h>

struct SinhVien{
	int id;
	char name[50];
	int age;
};

int main(){
	int n;
	printf("Nhap so luong sinh vien:");
	scanf("%d",&n);
	struct SinhVien sv[n];
	for(int i=0;i<n;i++){
		printf("Nhap id sinh vien: ");
		scanf("%d",&sv[i].id);
		fflush(stdin);
		printf("Nhap ten sinh vien: ");
		fgets(sv[i].name, 50, stdin);
		sv[i].name[strcspn(sv[i].name, "\n")]= '\0';
		printf("Nhap tuoi:");
		scanf("%d",&sv[i].age);
		fflush(stdin);
	}
	
	FILE *file = fopen("students.txt", "w");
    if(file == NULL){
        printf("Khong the mo file de ghi\n");
        return 1;
    }
    for(int i=0; i<n;i++){
        fprintf(file, "%d %s %d\n", sv[i].id, sv[i].name, sv[i].age);
    }
    printf("Thong tin sinh vien da duoc ghi vao file students.txt\n");
    fclose(file);
    
	return 0;
}

