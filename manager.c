#include "manager.h"

int selectMenu(){
    int menu;
    printf("\n*** 제품 관리 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
void listProduct(Product *p,int count){

    printf("\nNo. Name          weight price\n");
    printf("================================\n");
    for(int i=0; i<count; i++){
        if( p[i].weight == -1 || p[i].price == -1 ) continue;
        printf("%2d.", i+1);
        readProduct(&p[i]);
    }
    printf("\n");
}

int selectDataNo(Product *p, int count){
    int no;
    listProduct(p,count);
    printf("번호는 (취소:0)?");
    scanf("%d",&no);
    getchar();
    return no;
}

//배열데이터를 파일에 저장하는 함수
void saveData(Product p[],  int count){
FILE *fp;
fp=fopen("product.txt","wt");
for(int i=0;i<count;i++){
if( p[i].price ==-1 ) continue;
fprintf(fp,"%d %d %s\n", p[i].weight, p[i].price, p[i].name);
}
fclose(fp);
printf("저장됨!");
}

int loadData(Product *p){
int count=0;
FILE *fp;
int i=0;
fp= fopen("product.txt", "rt");
 if (fp!=NULL){
 for(i=0;i<100;i++){
if(feof(fp)) break;
fscanf(fp,"%d", &p[i].weight);
fscanf(fp,"%d", &p[i].price);
fscanf(fp,"%s", p[i].name);
}
fclose(fp);
printf("=> 로딩 성공!\n");
return i;
}
else {
printf("=> 파일 없음\n");
return 0;
}
}
