#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_int(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string ogkey = argv[1];
    bool is_digit = is_int(ogkey);

    if (is_digit == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(ogkey);

    string p = get_string("plaintext: ");

    printf("ciphertext: ");

for (int i = 0; i < strlen(p); i++)
 {
        if (p[i] >= 'a' && p[i] <= 'z')
        {
            printf("%c", ((p[i] - 'a' + key) % 26) + 'a');
        }

        if (p[i] >= 'A' && p[i] <= 'Z')
        {
            printf("%c", ((p[i] - 'A' + key) % 26) + 'A');
        }

        else if (isalpha(p[i]) == false)
        {
            printf("%c", p[i]);
        }
    }

    printf("\n");
}

bool is_int(string s)
{
    if (s[0] == '\0') // Check if the string is empty
        return false;

    int i;
    int count = 0;
    for (i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]))
        {
            count++;
        }
    }

    if (strlen(s) == count)
    {
        return true;
    }
    else
    {
        return false;
    }
}
