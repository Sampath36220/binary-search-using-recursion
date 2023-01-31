//binary search using recursion
#include <stdio.h>
#include <stdlib.h>
int binarySearch(int*, int, int, int);
int main(){
    int n, flag = 0, i;
    printf("Enter n value:\n");
    scanf("%d", &n);
    int* p;
    p = (int*)malloc(n * sizeof(int));
    printf("\nEnter elements into array:\n");
    for(i = 0; i < n; i++){
        scanf("%d", (p + i));
    }
    int key;
    printf("\nEnter key to be searched:\n");
    scanf("%d", &key);
    flag = binarySearch(p, 0, n, key);
    if(flag >= 0){
        printf("\n%d is available in the array at %d index.", key, flag);
    }
    else{
        printf("\n%d is not available in the array.", key);
    }
    return 0;
}
int binarySearch(int* p, int l, int h, int key){
    while(l <= h){
        int m = (l + h) / 2;
        if(p[m] == key){
            return m;
        }
        else if(p[m] < key){
            return binarySearch(p, m + 1, h, key);
        }
        else{
            return binarySearch(p, l, m - 1, key);
        }
    }
    return -1;
}
