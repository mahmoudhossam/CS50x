#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

int count_change(float amount);
float process_input();

int main()
{
    float amount = process_input(); 
    int result = count_change(amount);
    printf("%d\n", result);
    return 0;
}

float process_input()
{
    printf("How much change is owed: ");
    float input = GetFloat();
    if (input > 0)
    {
        input = round(input * 100); 
    } else {
        process_input();
    }
    // TODO: validate input
    return input;
}

int count_change(float amount)
{
	int count = 0;
	int change[4] = {QUARTER, DIME, NICKEL, PENNY};
    while (amount > 0)
    {
        for (int i = 0; i < 4; i++)
        {
             if(amount >= change[i])
             {
                amount -= change[i];
                count += 1;
                break;
             }
        }
    }
    return count;
}
