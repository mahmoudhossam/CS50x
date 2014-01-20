#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

char rot13(char c, int k);
void encrypt_string(string input, int key);

int main(int argc, string argv[])
{
    int key;
    if (argc != 2){
        printf("Wrong number of arguments, exiting...");
        return 1;
    } else {
        key = atoi(argv[1]);
    }
    string input = GetString();
    encrypt_string(input, key);
    return 0;
}

void encrypt_string(string input, int key)
{
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        printf("%c", rot13(input[i], key));
    }
    printf("\n");
}


char rot13(char c, int k)
{
    int start;
    if (c >= 65 && c <= 90)
    {
        start = 65;
        c = ((c - start + k) % 26) + start;
    } else if(c >= 97 && c <= 122) {
        start = 97;
        c = ((c - start + k) % 26) + start;
    }
    return c;
}