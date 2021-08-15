#include <stdio.h>
#include<windows.h>
#include<time.h>

int main(){
	system("color 06");
	int pin=1234,option,enteredPin,count=4,amount=1;
	float balance=5000;
	int continueTransaction=1;
	
	time_t now;
	time(&now);
	printf("\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t      %s",ctime(&now));
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    ....................................WELCOME TO DEV'S ATM BANKING SYSTEM....................................");
	while(pin!=enteredPin){
		printf("\n\n\n\t\t\t\t\tPlease enter your PIN:");
		scanf("%d",&enteredPin);
		if(enteredPin!=pin){
			Beep(610,500);
			printf("\n\t\t\t\t\tInvalid PIN. You have %d more attempts left",count-2);
		}
		count--;
		if(count==1 && pin!=enteredPin){
			exit(0);
		}
	}
	
	while(continueTransaction!=0) {
	
	
		printf("\n\t\t\t\t\t\t\t             ..........................AVAILABLE TRANSACTIONS..........................");
		printf("\n\n\t\t\t\t\t1.Withdrawal");
		printf("\n\n\t\t\t\t\t2.Deposit");
		printf("\n\n\t\t\t\t\t3.Check Balance");
		printf("\n\n\n\n\t\t\t\t\tPlease select an option: ");
	    scanf("%d",&option);
	
	    switch(option){
	    	case 1:
	    		while(amount%500!=0){
	    			printf("\n\n\t\t\t\t\tEnter the amount:");
	    			scanf("%d",&amount);
	    			if(amount%500!=0){
					printf("\n\n\t\t\t\t\tThe amount should be multiple of 500.");
				}
			}
			if(balance<amount){
				printf("\n\n\t\t\t\t\tSorry insufficient balance.");
				amount=1;
				break;
			}
			else{
				balance-=amount;
				printf("\n\n\t\t\t\t\tYou have withdrawn INR %d. Yor new balance is INR %.2f",amount,balance);
				amount=1;
				break;
			}
			
			case 2:
				printf("\n\n\t\t\t\t\tPlease enter the amount: ");
				scanf("%d",&amount);
				balance+=amount;
				printf("\n\n\t\t\t\t\tYou have deposited INR %d. Your new balance is INR %.2f",amount,balance);
				amount=1;
				break;
				
			case 3:
				printf("\n\n\t\t\t\t\tYour account balance is INR %.2f",balance);
				break;
				
			default:
				Beep(610,500);
				printf("\n\n\t\t\t\t\tINVALID OPTION!!!");
		}
		printf("\n\n\t\t\t\t\tDo you wish to perform another transaction? Press: 1[YES] 0[NO]: ");
		scanf("%d",&continueTransaction);
		if(continueTransaction==0){
			printf("\n\n\t\t\t\t\t\t\t\t\t    THANK YOU FOR BANKING WITH DEV. HAVE AN EXCELLENT DAY !!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		}
		
	}
	return 0;
}
