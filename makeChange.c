
#include <stdio.h>
#include <stdlib.h>

//
// Steven Lamers, 2025
// Given an amount to make change for and given different denominations
// calcuate the change that we can give using these denoninations. 

int coins[] = {1, 5, 10, 20, 50,100, 1000}; // Coin denominations
const int numCoins = sizeof(coins) / sizeof(coins[0]);

int changeFor(int amount) {
    int totalpaid = 0;
    // if amount is 0, no channge is needed
    if (amount == 0) {
        return 0;
    }
    // Highest denomination values first
    for (int i = numCoins - 1; i >= 0; i--) {

        if ( coins[i] <= amount ) {
            // the coin is less than or equal to the amount.
            // So how many coins can we pay out with this coin 
	        // before it would go negative?
            // then stop and pay that much and return how much 
	        // we sitll owe
            do {
                    // pay with the coins value and total it
                    totalpaid += coins[i] ;

                    // show the payment
                    printf("Here's %4d, that's %d \n", coins[i], totalpaid  );

                    // how much more do we owe? 
                    amount -= coins[i] ; // subtract what we've paid this time 

                } while ( amount >= coins[i]  ) ; 
					
        }              
    } // next coin

     return( amount ); // should be 0
}

void main(int argc, char *argv[]) {

        int amount = 0; // Amount to make change for
        int iou    = 0; // IOU

    	if (argc < 2) {
        	printf("Please provide a number as a command line argument.\n");
        	return;
    	}

    	amount = atoi(argv[1]);

        printf("\nMaking change for %d\n\n", amount);

        do {
                iou = changeFor(amount); 
                amount = iou;

        } while (  amount > 0) ;

        printf("\nThank you, come again! \n\n");

}
