# makechange
Code to make change from a given amount

It has 1, 2, 5, 10, 20, 50,100, 1000 denominations it can make change for.

You can change the denominations be editing the following in the code.

int coins[] = {1, 5, 10, 20, 50,100, 1000}; // Coin denominations



To make the executable run the following at the bash prompt. 

> gcc makeChange.c -o makeChange


Then you can run it and give the amount of change desired  ...

> makeChage 1234.99

Making change for USD$ 1234.99, Please wait.

Paper Bills $1234 dollars

Here's  1000, that's 1000 
Here's   100, that's 1100 
Here's   100, that's 1200 
Here's    20, that's 1220 
Here's    10, that's 1230 
Here's     2, that's 1232 
Here's     2, that's 1234 

Coins 99 cents

Here's    50, that's 50 
Here's    20, that's 70 
Here's    20, that's 90 
Here's     5, that's 95 
Here's     1, that's 96 
Here's     1, that's 97 
Here's     1, that's 98 
Here's     1, that's 99 

Change made for USD$ 1234.99 Thank you, come again! 

Steven Lamers - 2025 - All rights reserved

