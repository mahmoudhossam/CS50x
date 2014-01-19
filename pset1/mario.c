#include <stdio.h>
#include <limits.h>
#include <cs50.h>

int get_line_count();
void print_lines(int count);
void print_hashes(int total, int number);

int main()
{
    int num = get_line_count();
    print_lines(num);
    return 0;
}

int get_line_count()
{
    int input;
    printf("Enter a number: ");
    while ((input = GetInt()) != INT_MAX)
    {
        if (input >= 0 && input <= 23)
        {
            return input;
        } else {
            printf("Retry: ");
        }
    }
    return 0;
}

void print_lines(int count)
{
    for (int i = 3; i < count + 3; i++)
    {
        print_hashes(count, i);
        printf("\n");
    }
}

void print_hashes(int total, int number)
{
    total += 3;
    for (int i = 2; i < total; i++)
    {
        if (i > total - number){
            printf("#");
        } else {
            printf(" ");
        }
    }

}
