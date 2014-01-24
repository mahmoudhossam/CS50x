#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

char rot13(char character, int k);
bool is_alpha(string x);
string make_key(string key, int length);
int ord(char character);

int main(int argc, string argv[])
{
    if (argc != 2 || !is_alpha(argv[1]))
    {
        printf("An error has occurred, check the arguments and try again.\n");
        return 1; 
    }
    string plaintext = GetString();
    int length = strlen(plaintext);
    string key = make_key(argv[1], length);
    for(int i = 0, j = 0; i < length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            printf("%c", rot13(plaintext[i], ord(key[j])));
            j++;
        } else
        {
            printf("%c", plaintext[i]);
        }
    } 
    
    printf("\n");
    // Don't leak memory
    free(key);
    return 0;
}

// Returns the ordinal value for a character
int ord(char character)
{
    return toupper(character) - 65;
}

// Returns true if all characters in a string were alphabetic.
bool is_alpha(string x)
{
    int length = strlen(x);
    for(int i = 0; i < length; i++)
    {
        if (!isalpha(x[i]))
        {
            return false;
        }
    }
    return true;
}

// Creates a key with the specified length 
string make_key(string key, int length)
{
    char* result = malloc(length * sizeof(char));
    int key_length = strlen(key);
    for (int i = 0; i <= length; i += key_length)
    {
        strncat(result, key, length - i); 
    }
    return result;
}

// Caesar cipher function
char rot13(char character, int k)
{
    int start;
    if (isupper(character))
    {
        start = 65;
        character = ((character - start + k) % 26) + start;
    } else if (islower(character))
    {
        start = 97;
        character = ((character - start + k) % 26) + start;
    } 
    return character;
}