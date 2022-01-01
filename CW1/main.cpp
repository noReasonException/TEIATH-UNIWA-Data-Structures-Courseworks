#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

int Menu_Main();
int *initRandomArray(int Size);
void  SearchMenu(int *arr,int Size,int(*ptr)(int*,int ,int ));

int SerialSearch(int *arr,int Size,int key);
void MergeSort(int *arr,int Size);
void MergeSort1(int *arr,int Left,int Right);
void Merge(int *arr,int Left,int Mid,int Right );
int BinarySearch(int *arr,int Size,int key);
int BinarySearch1(int *arr,int Right,int Left,int key);
int * MergeOfSortedArrays(int *arr1,int Size1,int *arr2,int Size2);
void MergeOfTwoSortedArraysMenu(int *arr1,int Size1);
void printArray(int *ptr,int Size);
int *LoadArray(char *filename,int *Size);
int *LoadArrayMenu(int *Size);
void SaveArrayMenu(int *generatedArray,int Size);


void SaveArray(char *fileName,int *ptr,int Size);
int main() {
    srand(time(NULL));
    //SaveArray("s.txt",initRandomArray(10),10);
    return Menu_Main();
}
int Menu_Main(){
    int res;
    int Size;
    printf("Size of Random generated array?");
    scanf("%d",&Size);
    if(Size<0)
        return EXIT_FAILURE;
    int *generatedArray = initRandomArray(Size);
    do{
        printf("*------------------------------------------------------------------*\n");
        printf("1)Serial Search of rand\n");
        printf("2)Merge Sort\n");
        printf("3)Binary Search\n");
        printf("4)Merge of two sorted arrays\n");
        printf("5)Print Array\n");
        printf("6)Load Array\n");
        printf("7)Save Array\n");
        printf("8)Generate new Array\n");
        printf("9)Exit\n");
        printf("*------------------------------------------------------------------*\n");
        scanf("%d",&res);
        switch (res){
            case 1:SearchMenu(generatedArray,Size,SerialSearch);break;
            case 2: MergeSort(generatedArray,Size);break;
            case 3:SearchMenu(generatedArray,Size,BinarySearch);break;
            case 4:MergeOfTwoSortedArraysMenu(generatedArray,Size);break;
            case 5:printArray(generatedArray,Size);break;
            case 6:free(generatedArray);generatedArray=LoadArrayMenu(&Size);break;
            case 7:SaveArrayMenu(generatedArray,Size);break;
            case 8:free(generatedArray);generatedArray=initRandomArray(Size);break;
            case 9:free(generatedArray);
                break;

        }

    }while(res!=9);
    return EXIT_SUCCESS;

}

int *initRandomArray(int Size){

    int *returnArray = (int *)malloc(sizeof(int )*Size);
    for (int i = 0; i < Size; ++i) {
        *(returnArray+i)=30+(rand()%20);
    }
    return returnArray;

}
int SerialSearch(int *arr,int Size,int key){
    for (int i = 0; i <Size ; ++i) {
        if(*(arr+i)==key)return i;
    }
    return -1;
}


void MergeSort(int *arr, int Size) {
    MergeSort1(arr,0,Size-1);
}

void MergeSort1(int *arr, int Left, int Right) {
    int m=(Left+Right)/2;
    if(Left<Right){
        MergeSort1(arr,Left,m);
        MergeSort1(arr,m+1,Right);
        Merge(arr,Left,m,Right);
    }
}

void Merge(int *arr, int Left,int Mid,int Right) {
    int FirstSubArrayIndex=0;
    int SecondSubArrayIndex =0;
    int MergedSubArrayIndex =Left;

    int SizeOfFirst=Mid-Left+1;
    int SizeOfSecond=Right-Mid;

    int *FirstArray = (int *)malloc(sizeof(int)*SizeOfFirst);
    int *SecondArray = (int *)malloc(sizeof(int)*SizeOfSecond);
    for (int i = 0; i < SizeOfFirst; ++i) {
        *(FirstArray+i)= *(arr+Left+i); //Copy
    }
    for (int j = 0; j < SizeOfSecond; ++j) {
        *(SecondArray+j)=*(arr+Mid+1+j); //CopySecond
    }
    while(FirstSubArrayIndex<SizeOfFirst &&SecondSubArrayIndex<SizeOfSecond){
        if(*(FirstArray+FirstSubArrayIndex)<*(SecondArray+SecondSubArrayIndex)){
            *(arr+MergedSubArrayIndex)=*(FirstArray+FirstSubArrayIndex);
            FirstSubArrayIndex+=1;
        }
        else
        {
            *(arr+MergedSubArrayIndex)=*(SecondArray+SecondSubArrayIndex);
            SecondSubArrayIndex+=1;
        }
        MergedSubArrayIndex+=1;
    }
    while(FirstSubArrayIndex<SizeOfFirst){
        *(arr+MergedSubArrayIndex)=*(FirstArray+FirstSubArrayIndex);
        FirstSubArrayIndex+=1;
        MergedSubArrayIndex+=1;
    }
    while(SecondSubArrayIndex<SizeOfSecond){
        *(arr+MergedSubArrayIndex)=*(SecondArray+SecondSubArrayIndex);
        SecondSubArrayIndex+=1;
        MergedSubArrayIndex+=1;

    }
    free(FirstArray);
    free(SecondArray);


}
int BinarySearch(int *arr,int Size,int key){
    return BinarySearch1(arr,0,Size,key);
}
int BinarySearch1(int *arr,int Right,int Left,int key){
    int mid=(Right+Left)/2;
    if(Right<Left){
        if(key>*(arr+mid)){
            return BinarySearch1(arr,mid+1,Left,key);
        }
        else if(key<*(arr+mid)){
            return BinarySearch1(arr,Right,mid,key);
        }
        else return mid;
    }
    return -1;
}
/*--------*/
int * MergeOfSortedArrays(int *arr1, int Size1, int *arr2, int Size2) {
    int *ReturnArray=(int *)malloc(sizeof(int)*(Size1+Size2+1));
    int Index1=0;
    int Index2=0;
    int IndexReturnArray=0;
    while(Index1<Size1 && Index2<Size2){
        if(*(arr1+Index1)<*(arr2+Index2)){
            *(ReturnArray+IndexReturnArray)=*(arr1+Index1);
            Index1+=1;
        }
        else{
            *(ReturnArray+IndexReturnArray)=*(arr2+Index2);
            Index2+=1;
        }
        IndexReturnArray+=1;
    }
    while(Index1<Size1){
        *(ReturnArray+IndexReturnArray)=*(arr1+Index1);
        Index1+=1;
        IndexReturnArray+=1;
    }
    while(Index2<Size2){
        *(ReturnArray+IndexReturnArray)=*(arr2+Index2);
        Index2+=1;
        IndexReturnArray+=1;
    }
    return ReturnArray;
}

void printArray(int *ptr, int Size) {
    for (int i = 0; i < Size; ++i) {
        printf("|%d| ",*(ptr+i));
    }
    printf("\n");
}

int *LoadArray(char *filename,int *SizeOfArray) {
    int Size;

    FILE *p;
    p=fopen(filename,"r");
    fscanf(p,"%d",&Size);
    int *returnArray = (int *)malloc(sizeof(int)*Size);
    int tmp;
    for (int i = 0; i < Size; ++i){
        fscanf(p,"%d",&tmp);
        (*(returnArray+i))=tmp;
    }
    fclose(p);

    *SizeOfArray=Size;
    return returnArray;

}

void SaveArray(char *fileName,int *ptr,int Size) {
    FILE *ptrToOpenFile=fopen(fileName,"w");
    fprintf(ptrToOpenFile,"%d ",Size);
    for (int i = 0; i < Size; ++i) {
        fprintf(ptrToOpenFile,"%d ",*(ptr+i));
    }
    fclose(ptrToOpenFile);
}

void SearchMenu(int *arr, int Size,int(*ptr)(int*arr,int Size,int key)) {
    int key;
    printf("Enter The key you looking for...");
    scanf("%d",&key);
    if(key<30 or key >50){
        printf("Invalid Value\n");
        return ;
    }
    int location = ptr(arr,Size,key);
    if(location<0){
        printf("Not Found\n");
    }
    else{
        printf("Found At %d\n",location);
    }
}


void MergeOfTwoSortedArraysMenu(int *arr1, int Size1) {
    int Size2;
    char ans;
    //char filename[50];
    char *filename = (char *)malloc(sizeof(char)*50);
    printf("Give size of second Array!");
    scanf("%d",&Size2);
    if(Size2<0){
        printf("Invalid Size\n");
        return;
    }
    int *SecondGeneratedArray = initRandomArray(Size1);
    MergeSort(SecondGeneratedArray,Size2);
    int *UnifiedArray = MergeOfSortedArrays(arr1,Size1,SecondGeneratedArray,Size2);
    printArray(UnifiedArray,Size1+Size2);

    scanf("%c",&ans);
    printf("Do you want to save in file your new Generated Array?(y/n)");
    scanf("%c",&ans);
    if(ans=='y'){
        printf("Filename?: ");
        scanf("%s",filename);
        SaveArray(filename,SecondGeneratedArray,Size2);
    }
    scanf("%c",&ans);
    printf("Do you want to save in file your new BIG Merged Generated Array?(y/n)");
    scanf("%c",&ans);
    if(ans=='y'){
        printf("Filename?: ");
        scanf("%s",filename);
        SaveArray(filename,UnifiedArray,Size1+Size2);
    }

    free(SecondGeneratedArray);
    free(UnifiedArray);
    free(filename);
    return;


}
int *LoadArrayMenu(int *Size) {
    int *returnValue;
    char *filename = (char *)malloc(sizeof(char)*50);
    printf("Filename?:");
    scanf("%s",filename);
    returnValue = LoadArray(filename,Size);
    free(filename);
    return returnValue;
}
void SaveArrayMenu(int *generatedArray,int Size) {
    char *filename = (char *)malloc(sizeof(char)*50);
    printf("Filename?:");
    scanf("%s",filename);
    SaveArray(filename,generatedArray,Size);
    free(filename);
}