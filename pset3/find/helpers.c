/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n < 1)
    {
        return false;
    } else
    {
        for (int i = 0; i < n; i++)
        {
            if (values[i] == value)
            {
                return true;
            }
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (values[i] < values[i - 1])
        {
            for (int j = i; j > 0; j--)
            {
                if (values[j] < values[j - 1])
                {
                    int temp = values[j];
                    values[j] = values[j - 1];
                    values[j - 1] = temp;
                }
            }
        }
    }
}
