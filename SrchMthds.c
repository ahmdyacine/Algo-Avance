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
void LinearSearch(int arr[],int n,int x){
 
    int i;
    int NumOfComprs = 0;// to Calculate number of compares

    clock_t start = clock(); //Setting timer 

    for(i = 0;i<n;i++){
        NumOfComprs++;
        if(arr[i] == x){
          break;
        }
    }

    clock_t end = clock();
// Calculating Execution time
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Execution time: %fs\n", elapsed);
    printf(" Number of compares = %d",NumOfComprs);
}

void BinarySearch(int arr[],int n,int x){

    int i = n/2;
    int nMax = n;
    int nMin = 0;
    int NumOfComprs = 0;

    clock_t start = clock();

    while(arr[i] != x){

         if(arr[i] > x){

           nMax = i-1;

        }else{

            nMin = i+1;

        }

        i = (nMax + nMin)/2; 

        NumOfComprs++;
    }



    clock_t end = clock();

    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Execution time: %fs\n", elapsed);
    printf(" Number of compares = %d",NumOfComprs);

}
int main(){
    int arr[100000]={};
    int n = 100000;
    int i;

    srand(time(NULL));

    int x = rand() % n;
    
    for(i = 0;i<n;i++){
        arr[i] = i;
    }

    printf("\n-------Leaner Search-------\n");

    LinearSearch(arr,n,x);
    
    printf("\n-------Binary Search-------\n");

    BinarySearch(arr,n,x);


    return 0;
}
//results
//-------Leaner Search-------
//Execution time: 0.000048s
//Number of compares = 48697
//-------Binary Search-------
//Execution time: 0.000001s
//Number of compares = 15
