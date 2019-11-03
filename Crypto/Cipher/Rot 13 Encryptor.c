#include<stdio.h>
#include<stdlib.h>

char *rot13Encryptor(const char *str, int size)
{
    char *string = (char *) malloc(sizeof(char) * size);

    int i = 0, charInt;

    while(str[i] != '\0')
    {
        charInt = (int) str[i];

        if((charInt >= 65) && (charInt <= 90))
        {
            if(charInt - 65 < 13)
            {
                string[i] = (char) (charInt + 13);
            }
            else
            {
                string[i] = (char) (charInt - 13);
            }
        }
        else if((charInt >= 97) && (charInt <= 122))
        {
            if(charInt - 97 < 13)
            {
                string[i] = (char) (charInt + 13);
            }
            else
            {
                string[i] = (char) (charInt - 13);
            }
        }
        else
        {
            string[i] = str[i];
        }

        i++;
    }

    string[i] = '\0';

    return string;
}

int main()
{
    printf("\nSize of String: ");

    int size;

    scanf("%d", &size);

    printf("\nGive String to Crypt: ");

    char *string = (char *) malloc(sizeof(char) * size);

    getchar();

    scanf("%[^\n]%*c", string);

    int i = 0;

    while(string[i] != '\0')
    {
        i++;
    }

    if(i > size)
    {
        printf("\nYou have Given a String, Greater than the Size you Mentioned!!\n");
    }
    else
    {
        printf("\nUsing Rot 13 Algorithm, We get: %s\n", rot13Encryptor(string, size));
    }

    return 0;
}
