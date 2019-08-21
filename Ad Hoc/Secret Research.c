/* Problem Id : 621
   Problem    : Secret Research
   
   Problem Description : At a certain laboratory results of secret research are thoroughly encrypted. A result of a single experiment is stored as an information of its completion:
   ‘positive result’, ‘negative result’, ‘experiment failed’ or ‘experiment not completed’ 
   The encrypted result constitutes a string of digits S, which may take one of the following forms:
   positive result S = 1 or S = 4 or S = 78
  negative result S = S 35
  experiment failed S = 9S4
  experiment not completed S = 190S
  (A sample result S35 means that if we add digits 35 from the right hand side to a digit sequence then we shall get the digit sequence
  corresponding to a failed experiment)
  Task is to write a program which decrypts given sequences of digits

  Input
  A integer n stating the number of encrypted results and then consecutive n lines, each containing a sequence of digits given as ASCII strings.
  Output.For each analysed sequence of digits the following lines should be sent to output (in separate lines):
  + for a positive result
  - for a negative result
  * for a failed experiment
  ? for a not completed experiment
  In case the analysed string does not determine the experiment result, a first match from the above list should be outputted.
*/

#include<stdio.h>
#include<string.h>

int main()
{
    int n;

    scanf("%d", &n);

    char asciiString[1000];

    while(n--)
    {

        scanf("%999s", asciiString);

        if((strlen(asciiString) == 1)  || (strlen(asciiString) == 2))
        {
            int counter = 0;

            int i = 0;

            while(asciiString[i] != '\0')
            {
                counter++;

                i++;
            }

            i = 0;

            if(counter == 1)
            {
                while(asciiString[i] != '\0')
                {
                    if((asciiString[i] == '4') || (asciiString[i] == '1'))
                    {
                        printf("+\n");

                        i = 0;

                        break;
                    }
                    else
                    {
                        i = 0;

                        break;
                    }
                }
            }
            else if(counter == 2)
            {
                while(asciiString[i] != '\0')
                {
                    if(asciiString[i] == '7' && asciiString[i + 1] == '8')
                    {
                        printf("+\n");

                        i = 0;

                        break;
                    }
                    else
                    {
                        i = 0;

                        break;
                    }
                }
            }

        }
        else if(strlen(asciiString) >= 3)
        {
            int length = strlen(asciiString);

            if((asciiString[length - 2] == '3') && (asciiString[length - 1] == '5'))
            {
                printf("-\n");
            }
            else if((asciiString[0] == '9') && (asciiString[length - 1] == '4'))
            {
                printf("*\n");
            }
            else if((asciiString[0] == '1') && (asciiString[1] == '9') && (asciiString[2] == '0'))
            {
                printf("?\n");
            }
            else
            {
                printf("?\n");
            }
        }
    }

    return 0;
}
