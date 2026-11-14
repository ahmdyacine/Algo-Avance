#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printArr(int arr[],int n){

    int i;
    for(i = 0;i < n;i++){
        printf("%d ,",arr[i]);
        
    }
    printf("\n");
    
}
// Swap function
void swap(int x,int y){
    x += y;
    y = x-y;
    x = x-y;
}
//simple sort methosds
//1 selection sort
void SelecSort(int arr[],int n){
    int i;
    int j;
    int x = arr[0];
    clock_t start = clock();
    for(j = 0 ;j < n; j++){
    for(i = j+1;i < n; i++){
         if(x > arr[i]){
           x++;
           i = x+1;
        }
      arr[j] = x;
    }
}
    clock_t end = clock();
// Calculating Execution time
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Execution time: %fs\n", elapsed);
}
//2 Bubble sort
void BubbleSort(int arr[],int n){
   int i;
   int j;
   int count;
   clock_t start = clock();
   while(count<n){
    count = 0;
    for(i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
        swap(arr[i],arr[i+1]);
        }else count++;
        
    }
   }
       clock_t end = clock();
// Calculating Execution time
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Execution time: %fs\n", elapsed);
}
//3 Insertion sort
void insertionSort(int arr[], int n)
{
    clock_t start = clock();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    clock_t end = clock();
// Calculating Execution time
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Execution time: %fs\n", elapsed);
}

int main(){
    int arr[100000];
    int n = 100000;
    int i,mthdNum;
    
    srand(time(NULL));

    
    for(i = 0;i<n;i++){

        arr[i] = rand() % n;
    }
while(1){
    printf("1 for selection sort\n2 for bubble sort\n3 for insertion sort");
    
    scanf("%d",&mthdNum);
    switch (mthdNum)
    {
    case 1:
        SelecSort(arr,n);
        break;
    case 2:
        BubbleSort(arr,n);
        break;
    case 3:
    insertionSort(arr,n);
        break;
    default:
        break;
    }
}
return 0;
}