#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
string caesar_cipher(string plaintext, int key);

int main(int argc, string argv[])
{
    // Check if the correct number of command-line arguments is provided
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the key from a string to an integer
    int key = atoi(argv[1]);

    // Check if the key is a non-negative integer
    if (key < 0)
    {
        printf("Key must be a non-negative integer.\n");
        return 1;
    }

    // Prompt the user for plaintext
    string plaintext = get_string("plaintext: ");

    // Encrypt the plaintext
    string ciphertext = caesar_cipher(plaintext, key);

    // Print the ciphertext
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

string caesar_cipher(string plaintext, int key)
{
    int n = strlen(plaintext);
    // Allocate memory for ciphertext
    string ciphertext = plaintext;

    // Iterate over each character in the plaintext
    for (int i = 0; i < n; i++)
    {
        // Check if the character is an uppercase letter
        if (isupper(plaintext[i]))
        {
            // Shift the character by key positions
            ciphertext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
        }
        // Check if the character is a lowercase letter
        else if (islower(plaintext[i]))
        {
            // Shift the character by key positions
            ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
        }
        // If the character is not a letter, leave it unchanged
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    return ciphertext;
}
