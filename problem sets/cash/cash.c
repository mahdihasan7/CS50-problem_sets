#include"cs50.h"
#include<stdio.h>

void CalculateChange(int amount){
    int quarters, dimes, nickels, pennies, total_coins;
    //calculating quarters
    quarters = amount / 25;
    amount %= 25;
    //calculating dimes
    dimes = amount / 10;
    amount %= 10;
    //calculating nickels
    nickels = amount / 5;
    amount %= 5;
    //calculating pennies
    pennies = amount;
    //calculating total coins
    total_coins = quarters + dimes + nickels + pennies;

    printf("Total number of coins: %d", total_coins);
}

int main()
{
    int change = get_int("Change owed: ");
    CalculateChange(change);
}