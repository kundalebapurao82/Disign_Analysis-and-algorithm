#include <stdio.h>

struct Job{
    int id;
    int resources;
    int profit;
    float ratio;
};

int main(){
    struct Job jobs[50], temp;
    int n,i,j,totalResources;
	int used = 0;
	int totalProfit = 0;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter total available resources: ");
    scanf("%d", &totalResources);

    for(i = 0; i<n; i++){
    	jobs[i].id= i+1;
        printf("Job %d:\n", jobs[i].id);
        printf("Resources: ");
        scanf("%d", &jobs[i].resources);
        printf("Profit: ");
        scanf("%d", &jobs[i].profit);
        jobs[i].ratio = (float)jobs[i].profit/jobs[i].resources;
    }

    // Sort by profit/resource ratio (descending)
    for(i=0; i<n-1; i++){
        for(j =i+1; j<n; j++){
            if(jobs[i].ratio < jobs[j].ratio){
                temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    printf("\nAllocated Jobs:\n");
    for(i = 0; i < n; i++) {
        if(used + jobs[i].resources <= totalResources) {
            used += jobs[i].resources;
            totalProfit += jobs[i].profit;
            printf("Job %d (Resources: %d, Profit: %d)\n",jobs[i].id,jobs[i].resources, jobs[i].profit);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);

    return 0;
}

