#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

int guess(int n){
	//array to store number of guesses for each player.
	int arr[n];
	
	//sequence of the game for each player using for and while loop.
	for (int i=0; i<n; i++){
	
		//random number generator.
		srand(time(0));
		int r=(rand()%100)+1;
		printf("\n%d",r);
		
		int count=0;
		printf("\n \n===PLAYER %d===\n \n",i+1);
		while(1){
			int g;
			printf("\n Guess a number (from 1 to 100) => ");
			scanf("%d",&g); 
			if(g<1 || g>100) printf("\nGuess within the range...\n");
			else {
				if(g>r){
					printf("\nYour guess is high!  :(\n");
					count++;
				}	
				
				else if(g<r){
					printf("\nYour guess is low! :(\n");
					count++;
				}
			
				else{
					printf("\nYour guess is right!!  :)\n");
					count++;
					break;
				}
			}
			
		}
		
		printf("\nNumber of guesses of player %d is => %d",i+1,count);
		arr[i]=count; //storing number of guesses for each player.
	}	
	
	//finding maximum 
	int min=INT_MAX;
	int id;
	for(int i=0; i<n; i++){
		if(arr[i]<min) {
		min=arr[i];
		id=i+1;
		}
	}
	
	//win is the number of winners.
	//wid[min] stores the ids of the winners using that for loop.	
	int win=0;
	int wid[win];
	int k=0;
	for(int i=0; i<n; i++){
		if(arr[i]==min) {
		win++;
		wid[k]=i+1;
		k++;
		}
	}
	
	//result statements
	printf("\n\n===WINNERS===");
	if(win==1) printf("\n\nPlayer %d is the winner!!!!\n\nWith the least number of guesses : %d.",id,min);
	
	if(win>1) printf("\n\nPlayers %d",wid[0]);
	int j=1;
	while(j<win){
		printf(", %d",wid[j]);
		j++;
	}
	if(win>1) {
		printf(" are the winners!!!\n\nWith the least number of guesses : %d.\n",min);
		printf("     TIE BREAKER ROUND between players %d",wid[0]);
		int p=1;
		while(p<win){
			printf(", %d",wid[p]);
			p++;
		}
		printf(".\n");
	}
	return win;
}

int main(){
	//input for number of players.
	int n;
	printf("How many are playing? : ");
	scanf("%d",&n);
	
	int nwin=guess(n);
	while(nwin>1){
	nwin=guess(nwin);
	}
	//game ends
	return 0;
}

