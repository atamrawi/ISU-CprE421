#include <stdio.h>
#include <stdlib.h>

int main() {
    int account_balance = 1100;
    int price = 1000;
    int quantity;

    printf("You have %d in your account.\n", account_balance);
    printf("Each item costs %d.\n", price);

    // Ask the user how many items they want to buy
    printf("How many items would you like to buy? ");
    scanf("%d", &quantity);

    // Calculate the total cost
    int total_cost = price * quantity;
    printf("Total cost is: %d\n", total_cost);

    // Check if the user has enough money
    if(total_cost <= account_balance) {
        account_balance -= total_cost;
        printf("Purchase successful! New balance: %d\n", account_balance);
    } else {
        printf("Not enough funds!\n");
    }

    return 0;
}


