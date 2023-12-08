#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char getScore(char player, char computer)
{
    if (player == computer)
    {
        return 'd';
    }
    else if (player == 'R' && computer == 'S')
    {
        return 'p';
    }
    else if (player == 'P' && computer == 'R')
    {
        return 'p';
    }
    else if (player == 'S' && computer == 'P')
    {
        return 'p';
    }
    else
    {
        return 'c';
    }
}

void display_rules()
{
    printf("\n\n\n\n\t\t\t\t\tWELCOME TO THE ROCK PAPER SCISSOR\n");
    printf("\n\n\t\t\t\t\t\tRULES ARE SIMPLE:\n");
    printf("\n\t\t\t\t     *SCISSOR WINS OVER A PAPER BUT NOT ROCK\n");
    printf("\n\t\t\t\t     *PAPER WINS OVER A ROCK BUT NOT SCISSOR\n");
    printf("\n\t\t\t\t     *ROCK WINS OVER A SCISSOR BUT NOT PAPER\n");

    printf("\n\n\t\t\t\t\t\t\tNOTE:\n");
    printf("\n\t\t\t\t\t     *ROCK CANNOT ATTACK ROCK\n");
    printf("\n\t\t\t\t\t    *PAPER CANNOT ATTACK PAPER\n");
    printf("\n\t\t\t\t\t  *SCISSOR CANNOT ATTACK SCISSOR\n");
    printf("\t\t================================================================================\n");
}

char validate_inputs(char c)
{
    if (c == 'R' || c == 'P' || c == 'S')
    {
        return c;
    }
    else if (c == 'r')
    {
        return 'R';
    }
    else if (c == 'p')
    {
        return 'P';
    }
    else if (c == 's')
    {
        return 'S';
    }
    else
    {
        return '\0';
    }
}

char take_inputs()
{
    char c;

    printf("\n\n\t\t\t\t\t\t  ENTER YOUR INPUT:\n");
    printf("\n\t\t\t\t*ROCK ---> R\t\t*PAPER ---> P\t\t*SCISSOR ---> S\n");
    scanf(" %c", &c);

    if (validate_inputs(c) != '\0')
    {
        return validate_inputs(c);
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            printf("\n\n\n\t\t\t\tINVALID INPUT...\n");
            printf("\t\t\t\tENTER AGAIN...\n");

            printf("\n\n\t\t\t\t\t\t  ENTER YOUR INPUT:\n");
            printf("\n\t\t\t\t*ROCK ---> R\t\t*PAPER ---> P\t\t*SCISSOR ---> S\n");
            scanf(" %c", &c);

            if (validate_inputs(c) != '\0')
            {
                return validate_inputs(c);
            }
        }

        printf("\n\n\n\t\t\t\tINVALID INPUTS...\n");
        printf("\t\t\t\tDISCONTINUING YOUR GAME\n\n\n\n");
        return 1;
    }
}

char getRandom()
{
    srand((unsigned)time(NULL));
    char r = "RPS"[rand() % 3];
    return r;
}

char validate_YN(char value)
{
    if (value == 'Y' || value == 'y')
    {
        return 'Y';
    }
    else if (value == 'N' || value == 'n')
    {
        return 'N';
    }
    else
    {
        return '\0';
    }
}

char take_YN()
{
    char temp;

    printf("\n\n\t\t\tPLAY AGAIN??? ;-)\n\n");
    printf("\n\t\t\t\t*YES ---> Y\t\t*NO ---> N\n");
    scanf(" %c", &temp);

    if (validate_YN(temp) != '\0')
    {
        return validate_YN(temp);
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            printf("\n\n\n\t\t\t\tINVALID INPUT...\n");
            printf("\t\t\t\tENTER AGAIN...\n");

            printf("\n\n\t\t\tPLAY AGAIN??? ;-)\n\n");
            printf("\n\t\t\t\t*YES ---> Y\t\t*NO ---> N\n");
            scanf(" %c", &temp);

            if (validate_YN(temp) != '\0')
            {
                return validate_YN(temp);
            }
        }

        printf("\n\n\n\t\t\t\tINVALID INPUTS...\n");
        printf("\t\t\t\tDISCONTINUING YOUR GAME\n\n\n\n");
        return 1;
    }
}

int main()
{
    char input, response;
    display_rules();
    char temp;

    do
    {
        input = take_inputs();
        response = getRandom();

        printf("\n\nYOU: %c", input);
        printf("\n\nCOMPUTER: %c", response);

        char output = getScore(input, response);

        printf("\n\n\n");

        if (output == 'p')
        {
            printf("\n\n\t\t\t\t\t\t  YOU WON!!!!\n\n\n\n\n");
        }
        else if (output == 'c')
        {
            printf("\n\n\t\t\t\t\t\t  YOU LOST :-(\n\n\n\n\n");
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t  ITS A DRAW...\n\n\n\n\n");
        }

        temp = take_YN();
        if (temp == 'Y')
        {
            printf("\n\n\n\t\t\t\tCONTINUING YOUR GAME!!!!!!!!!!!\n\n\n\n");
            continue;
        }
        else if (temp == 'N')
        {
            printf("\n\n\n\t\t\t\tBYEEEEEEEE!!!!!!!!!!!\n");
            printf("\t\t\t\tTHANK YOU FOR PLAYING <3\n\n\n\n");
            return 1;
        }
    } while (temp == 'y' || temp == 'Y');

    return 0;
}