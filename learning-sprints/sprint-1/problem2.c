#include <stdio.h>
#include <stdlib.h>

int main() {
    int con;
    con = 0;
    int account_balance = 1100;
    while(con == 0){
        printf("=========================================\n");
        printf("Welcome to the Store - (World's Most Secure Purchasing App) \n");
        printf("[1] Check Account Balance\n");
        printf("[2] Buy Stuff\n");
        printf("[3] Exit\n");
        printf("=========================================\n");
        int menu;
        printf("Enter a menu selection: ");
        fflush(stdin);
        scanf("%d", &menu);
        printf("=========================================\n");
        if(menu == 1){
            printf("\n\n\nAccount Balance: %d \n\n\n", account_balance);
        } else if(menu == 2){
            printf("#########################################\n");
            printf("Current Auctions\n");
            printf("[1] Imitation Keys\n");
            printf("[2] Real Keys\n");
            printf("#########################################\n");
            int auction_choice;
            printf("Enter your selection: ");
            fflush(stdin);
            scanf("%d", &auction_choice);
            printf("#########################################\n");
            if(auction_choice == 1){
                printf("Imitation Keys cost 1000 each, how many would you like? ");
                int number_keys = 0;
                fflush(stdin);
                scanf("%d", &number_keys);
                if(number_keys > 0){
                    int total_cost = 0;
                    total_cost = 1000 * number_keys;
                    printf("\nYour total cost is: %d\n", total_cost);
                    if(total_cost <= account_balance){
                        account_balance = account_balance - total_cost;
                        printf("[SUCCESS] Your new balance: %d\n\n", account_balance);
                    } else{
                        printf("[ERROR] Not enough funds\n");
                    }
                }
            } else if(auction_choice == 2){
                printf("A genuine Key costs 100,000 dollars, and we only have 1 in stock\n");
                printf("Enter 1 to purchase: ");
                int bid = 0;
                fflush(stdin);
                scanf("%d", &bid);
                if(bid == 1){
                    if(account_balance > 100000){
                        printf("\n[SUCCESS] YOUR KEY IS: Software Security is a Journey!\n");
                    } else {
                        printf("\n[ERROR] Not enough funds for transaction\n");
                    }
                }
            }
        } else{
            con = 1;
        }
    }
    return 0;
}