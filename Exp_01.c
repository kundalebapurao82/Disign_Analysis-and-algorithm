#include<stdio.h>

int search(int arr[], int low, int high, int target) {
    	int mid;
	while(low<=high){
		mid = (low+high)/2;
		if(arr[mid] == target){
			return mid;
		}
        if(arr[low]<= arr[mid]){
            if(arr[low]<=target && target < arr[mid]){
                high = mid  -1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(arr[mid]<target && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
		// else{
		// 	if(arr[low]<arr[mid]){
		// 		if(arr[low]<= target && target< arr[mid]){
		// 			high = mid-1;
		// 		}
		// 		else 
		// 			low = mid+1;
		// 	}
		// 	else {
        //         //if(arr[mid+1]<arr[high])
		// 		if(arr[mid]<target && target <= arr[high]){
		// 			low = mid+1;
		// 		}
		// 		else
		// 			high = mid-1;
		// 	}
		// }
	}
	return -1;
}
int main(){
    int arr[50];
    int size, result, target;
    printf("Enter array size: ");
    scanf("%d",&size);

    int i;
    printf("Enter array elements : ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("Enter target element: ");
    scanf("%d",&target);
    result = search(arr, 0, size-1, target);
    if(result == -1){
        printf("Target element not found in array.");
    }
    else{
        printf("Target found at %d position.",result);
    }

    return 0;
}