#include <stdio.h>
#include <stdlib.h>

void srt(int*,int,int);
int prt(int*,int,int);
void swp(int*,int,int);
int main() {
    char* path=(char*)malloc(255*sizeof(char));
    printf("enter filepath:\n");
    scanf("%s",path);
    FILE* t1=fopen(path,"r");
    int* arr=(int*)malloc(sizeof(int));
    int tmp;
    int dpth=0;
    while(fscanf(t1,"%d,",&tmp)!=EOF){
        arr[dpth]=tmp;
        dpth++;
        arr=(int*)realloc(arr,((dpth+1)*sizeof(int)));
    }
    fclose(t1);
    free(path);
    srt(arr,0,dpth);
    FILE* t2=fopen("res.txt","w");
    for(int c1=0;c1<dpth;c1++){
        fprintf(t2,"%d",arr[c1]);
        if(c1!=(dpth-1)){
            fprintf(t2,",");
        }
    }
    fclose(t2);
    free(arr);
    return 0;
}
void srt(int* arr,int l,int h){
    if(l<h){
        int pvt=prt(arr,l,h);
        srt(arr,l,pvt-1);
        srt(arr,pvt+1,h);
    }
}
int prt(int* arr,int l,int h){
    int pvt=arr[h];
    int c1=l-1;
    for(int c2=l;c2<h;c2++){
        if(arr[c2]<=pvt){
            c1++;
            swp(arr,c1,c2);
        }
    }
    swp(arr,c1+1,h);
    return(c1+1);
}
void swp(int* arr,int r1,int r2){
    int r3=arr[r1];
    arr[r1]=arr[r2];
    arr[r2]=r3;
}
