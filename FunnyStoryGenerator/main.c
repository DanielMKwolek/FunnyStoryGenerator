//
//  main.c
//  FunnyStoryGenerator
//
//  Created by Daniel Kwolek on 8/14/16.
//  Copyright © 2016 Arcore. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

int getChoice(int choiceMin,int choiceMax,char *prompt);

int main(int argc, const char * argv[])
{
    printf("Welcome to the Funny Story Generator!\n\nWhat would you like to be called?");
    fpurge(stdin);
    char *userName;
    int scanReturnVal;
    scanReturnVal = scanf("%s", userName);
    printf("Hello %s!", userName);
    
    enum Adjective
    {
        AdjBlue = 0,
        AdjRound,
        AdjBright,
        AdjVoid = INT_MIN
    };
    enum Noun
    {
        NounHorse = 0,
        NounGrass,
        NounTable,
        NounVoid = INT_MIN
    };
    enum Verb
    {
        VerbEat = 0,
        VerbSquish,
        VerbCuddle,
        VerbVoid = INT_MIN
    };
    
    int AdjChosenVal = AdjVoid;
    int NounChosenVal = NounVoid;
    int VerbChosenVal = VerbVoid;
    
    char *AdjChosen = NULL;
    char *NounChosen = NULL;
    char *VerbChosen = NULL;
    
    AdjChosenVal = getChoice(AdjBlue, AdjBright, "\n\nPlease pick an adjective by entering the corresponding integer:\n0: Blue\n1: Round\n2: Bright\n: ");
    
    switch (AdjChosenVal)
    {
        case (AdjBlue):
        {
            AdjChosen = "Blue";
            break;
        }
        case (AdjRound):
        {
            AdjChosen = "Round";
            break;
        }
        case (AdjBright):
        {
            AdjChosen = "Bright";
            break;
        }
            
        default:
        {
            printf("Something has gone wrong\n\n");
            return 1;
            break;
        }
    }
    
    /*switch (<#expression#>)
    {
        case <#constant#>:
        {
            <#statements#>
            break;
        }
        case <#constant#>:
        {
            <#statements#>
            break;
        }
        case <#constant#>:
        {
            <#statements#>
            break;
        }
            
        default:
        {
            break;
        }
    }
    
    switch (<#expression#>)
    {
        case <#constant#>:
        {
            <#statements#>
            break;
        }
        case <#constant#>:
        {
            <#statements#>
            break;
        }
        case <#constant#>:
        {
            <#statements#>
            break;
        }
            
        default:
        {
            break;
        }
    }
    */
    
}

int getChoice(int choiceMin, int choiceMax,char *prompt)
{
    int returnValue;
    do
    {
        fpurge(stdin);
        printf("%s", prompt);
        scanf("%1d", &returnValue);
        fpurge(stdin);
    } while (returnValue < choiceMin || returnValue > choiceMax);
    return returnValue;
}
