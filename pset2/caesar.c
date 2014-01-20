#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

char rot13(char character, int k);
void print_cipher(string input, int key);

int main(int argc, string argv[])
{
    int key;
    if (argc != 2)
    {
        printf("Wrong number of arguments, exiting...");
        return 1;
    } else
    {
        key = atoi(argv[1]);
    }
    string input = GetString();
    print_cipher(input, key);
    return 0;
}

void print_cipher(string input, int key)
{
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        printf("%c", rot13(input[i], key));
    }
    printf("\n");
}


char rot13(char character, int k)
{
    int start;
    if (character >= 65 && character <= 90)
    {
        start = 65;
        character = ((character - start + k) % 26) + start;
    } else if(character >= 97 && character <= 122)
    {
        start = 97;
        character = ((character - start + k) % 26) + start;
    }
    return character;
}