#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float price;
} MenuItem;

float orderMenu(MenuItem menu[], int numItems);
void displayMenu(MenuItem menu[], int numItems);
int getChoice(int max);
void clearBuffer();

float EndReceiptBill(void);

int main() {
    float totalBill = EndReceiptBill();
    printf("Your total is going to be: $ %.2f\n", totalBill);
    printf("Thank You For Choosing Krish's Cafe\n");
    return 0;
}

float EndReceiptBill() {
    char c;
    char item;
    float Payment = 0;
    char selectAgain;
    MenuItem coffeeMenu[] = {{"Hot/Cold Latte", 4.50}, {"Frappe", 5.00}, {"Espresso", 4.70}, {"Cappuccino", 5.00}, {"Cold Brew", 4.00}};
    MenuItem teaMenu[] = {{"Green Tea", 3.00}, {"Black Tea", 2.50}, {"Sweet Tea", 3.00}, {"Oolong Tea", 3.70}, {"Chai Tea", 4.00}};
    MenuItem donutsMenu[] = {{"Chocolate Donut", 2.50}, {"Strawberry Donut", 2.50}, {"Vanilla Donut", 2.50}, {"Old Fashioned Donut", 2.50}, {"Blueberry Donut", 2.50}};
    
    while(1) {
        printf("----------------|Welcome to Krish's Cafe :)|--------------\n");
        printf("Press K to start your order: ");
        clearBuffer();
        scanf("%c", &c);
        
        if(c == 'k' || c == 'K') {
            while(1) {
                printf("\nPress C for Coffee, T for Tea, D for Donuts\n");
                scanf(" %c", &item); // Space before %c to consume previous newline

                if(item == 'c' || item == 'C') {
                    Payment += orderMenu(coffeeMenu, 5);
                } else if(item == 't' || item == 'T') {
                    Payment += orderMenu(teaMenu, 5);
                } else if(item == 'd' || item == 'D') {
                    Payment += orderMenu(donutsMenu, 5);
                } else {
                    printf("Invalid choice, please try again!\n");
                    continue;
                }

                printf("Do you want to add more items, Y or N? ");
                clearBuffer();
                scanf("%c", &selectAgain);
                if(selectAgain == 'Y' || selectAgain == 'y') continue;
                else break;
            }
            break;
        } else {
            printf("Invalid input, please press K to start your order!\n");
        }
    }
    return Payment;
}

void displayMenu(MenuItem menu[], int numItems) {
    for(int i = 0; i < numItems; i++) {
        printf("(%d) %s - Price: $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

int getChoice(int max) {
    int choice;
    while(1) {
        printf("Select an item (1-%d): ", max);
        if(scanf("%d", &choice) == 1 && choice >= 1 && choice <= max) {
            return choice;
        } else {
            printf("Invalid input, try again!\n");
            clearBuffer();
        }
    }
}

float orderMenu(MenuItem menu[], int numItems) {
    displayMenu(menu, numItems);
    int choice = getChoice(numItems);
    printf("You selected: %s - Price: $%.2f\n", menu[choice - 1].name, menu[choice - 1].price);
    return menu[choice - 1].price;
}

void clearBuffer() {
    while(getchar() != '\n');
}
