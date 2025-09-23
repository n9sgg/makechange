#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Steven Lamers, 2025 All rights reserved.
// Given an amount to make change for and given different denominations
// calculate the change that we can give using these denominations. 
// Uses only integer math, does not use floats.

// Coin denominations - pennies n/100th of a dollar
int coins[] = {1, 5, 10, 20, 50, 100 }; 
const int numCoins = sizeof(coins) / sizeof(coins[0]);

// Paper denominations in circulation in 2025 real world
// int paper[] = {1, 2, 5, 10, 20, 50,100 }; 
// Paper denominations for testing or if you have larger bills
int paper[] = {1, 2, 5, 10, 20, 50,100, 1000, 10000 }; 
const int numPaper = sizeof(paper) / sizeof(paper[0]);

int changeFor( int denom[], int numberOfDenom, int amount) {
    int totalpaid = 0;  
    if (amount == 0) { // if amount is 0, no change is needed
        return 0;
    }
    // Highest denomination values first
    for (int i = numberOfDenom - 1; i >= 0; i--) {
        if ( denom[i] <= amount ) {
            do {                 
                    totalpaid += denom[i] ; // pay with the value and total it
                    printf("Here's %5d, that's %d \n", denom[i], totalpaid  );
                    amount -= denom[i] ; // subtract what we've paid this time 
            } while ( amount >= denom[i]  ) ; 
        }              
    } // next bill
     return( amount ); // should be 0
}

void main(int argc, char *argv[]) {
    int dollars     = 0;
    int cents       = 0;
    int x;
    char centstr[5];

        if (argc < 2) {
                printf("Please provide an amount in dollars and cents between 0.00 and %d.99\n", __INT_MAX__ - 1 );
                return;
        }    
        
        char *args = argv[1];

        // Get the amount in dollars 
        sscanf( args, "%d.", &dollars); 
        
        if( dollars >= __INT_MAX__  || dollars < 0  ){
                printf("Please provide an amount in dollars and cents between 0.00 and %d.99\n", __INT_MAX__ - 1 );
                return;
        }

        sscanf( args, "%*[^.].%2s", centstr );   // Get the amount in cents
        x = strlen( centstr);       
        
        sscanf(centstr, "%d", &cents);
        printf("\nMaking change for USD$ %d.%02d, Please wait.\n", dollars, cents );

        if( x == 1 ) {
            cents = cents * 10 ;
        }
           
        printf("\nPaper Bills $%d dollars\n\n", dollars);
        changeFor(paper, numPaper, dollars ); // Dollars change
        printf("\nCoins %d cents\n\n", cents);   
        changeFor(coins, numCoins, cents );   // Cents change   
        printf("\nChange made for USD$ %d.%02d Thank you, come again! \n", dollars, cents );      
}
