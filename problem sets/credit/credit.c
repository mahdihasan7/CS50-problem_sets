#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if all characters in the string are digits
int isAllDigits(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to implement Luhn's Algorithm
int isValidCreditCard(const char *cardNumber) {
    int len = strlen(cardNumber);
    int sum = 0;
    int isSecond = 0;

    for (int i = len - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0';

        if (isSecond) {
            digit *= 2;
        }

        sum += digit / 10;
        sum += digit % 10;

        isSecond = !isSecond;
    }

    return (sum % 10 == 0);
}

int main() {
    char cardNumber[20];

    printf("Enter the credit card number: ");
    scanf("%19s", cardNumber);

    // Check if the input contains only digits
    if (!isAllDigits(cardNumber)) {
        printf("Invalid input. Please enter only digits.\n");
        return 1;
    }

    if (isValidCreditCard(cardNumber)) {
        printf("The credit card number is valid.\n");
    } else {
        printf("The credit card number is invalid.\n");
    }

    return 0;
}
