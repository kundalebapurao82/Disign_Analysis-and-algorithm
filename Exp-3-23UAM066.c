#include<stdio.h>
void quickSort(int a[],int p,int r);
int partition(int a[],int m,int p);
void display(int a[],int n);

int main(){
    int a[100], n, i;

    printf("Enter number of elements : ");
    scanf("%d",&n);

    printf("Enter array elements: ");
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }

    quickSort(a, 0, n - 1);

    printf("Sorted array is : \n");
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}

void quickSort(int a[], int p, int r){
    int j;
    if(p < r){
        j = partition(a, p, r + 1);
        quickSort(a, p, j - 1);
        quickSort(a, j + 1, r);
    }
}
int partition(int a[], int m, int p){
    int v, i, j;
	int temp;
    v = a[m];
    i = m;
    j = p;

    do{
        do{
            i++;
        }while(i<p && a[i]<v);
        do{
            j--;
        }while(j>m && a[j]>v);
        if(i<j){
        	temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }while(i < j);

    a[m] = a[j];
    a[j] = v;

    return j;
}


