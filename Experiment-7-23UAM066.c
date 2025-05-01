#include<stdio.h>
struct Coins{
	int val;
	int count;
};
void sortCoinDenominations(struct Coins coin[],int n){
	int i,j;
	int temp;
	for(i=0; i<n-1; i++){
        for(j =i+1; j<n; j++){
            if(coin[j].val>coin[i].val){
            	temp = coin[j].val;
            	coin[j].val = coin[i].val;
            	coin[i].val = temp;
			}
        }
    }
}
int main(){
	int n,i;
	int amount;
	struct Coins coin[10];
	printf("Enter no. of coin denominations: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Coin Denomination %d: ",i+1);
		printf("Val: ");
		scanf("%d",&coin[i].val);
		coin[i].count=0;
	}
	printf("Enter total amount : ");
	scanf("%d",&amount);
	sortCoinDenominations(coin,n);
	int tCount = 0;
	for(i=0;i<n;i++){
		while(amount-coin[i].val>=0){
			amount = amount - coin[i].val;
			coin[i].count++;
			tCount++;
		}
	}
	printf("Minimum coins required: %d",tCount);
	printf("\nCoins Used:\n");
	for(i=0;i<n;i++){
		if(coin[i].count!=0){
			printf("Coin denomination %d : coins used %d.\n",coin[i].val, coin[i].count);
		}
	}
	return 0;
}
