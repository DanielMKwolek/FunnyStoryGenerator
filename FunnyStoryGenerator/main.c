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
    printf("Welcome to the Funny Story Generator!\n\nWhat would you like to be called?\n: ");
    fpurge(stdin);
    char userName[100];
    int scanReturnVal;
    scanReturnVal = scanf("%99s", userName);
    printf("\n\nHello %s,", userName);
    
    enum Adjective
    {
        AdjBlue = 0,
        AdjRound,
        AdjBright,
        AdjVoid = INT_MIN,
        AdjMin = AdjBlue,
        AdjMax = AdjBright
    };
    enum Noun
    {
        NounHorse = 0,
        NounGrass,
        NounTable,
        NounVoid = INT_MIN,
        NounMin = NounHorse,
        NounMax = NounTable
    };
    enum Verb
    {
        VerbEat = 0,
        VerbSquish,
        VerbCuddle,
        VerbVoid = INT_MIN,
        VerbMin = VerbEat,
        VerbMax = VerbCuddle
    };
    
    int AdjChosenVal = AdjVoid;
    int NounChosenVal = NounVoid;
    int VerbChosenVal = VerbVoid;
    
    char *AdjChosen = NULL;
    char *NounChosen = NULL;
    char *VerbChosen = NULL;
    
    AdjChosenVal = getChoice(AdjMin, AdjMax, "\n\nPlease pick an adjective by entering the corresponding integer:\n0: Blue\n1: Round\n2: Bright\n: ");
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
    printf("You chose the Adjective: %s", AdjChosen);
    
    NounChosenVal = getChoice(NounMin, NounMax, "\n\nPlease pick a Noun by entering the corresponding integer:\n0: Horse\n1: Grass\n2: Table\n: ");
    switch (NounChosenVal)
    {
        case (NounHorse):
        {
            NounChosen = "Horse";
            break;
        }
        case (NounGrass):
        {
            NounChosen = "Piece of Grass";
            break;
        }
        case (NounTable):
        {
            NounChosen = "Table";
            break;
        }
            
        default:
        {
            printf("Something has gone wrong\n\n");
            return 1;
            break;
        }
    }
    printf("You chose the Noun: %s", NounChosen);
    
    VerbChosenVal = getChoice(VerbMin, VerbMax, "\n\nPlease pick a Verb by entering the corresponding integer:\n0: Eat\n1: Squish\n2: Cuddle\n: ");
    switch (VerbChosenVal)
    {
        case (VerbEat):
        {
            VerbChosen = "Eat";
            break;
        }
        case (VerbSquish):
        {
            VerbChosen = "Squish";
            break;
        }
        case (VerbCuddle):
        {
            VerbChosen = "Cuddle";
            break;
        }
            
        default:
        {
            printf("Something has gone wrong\n\n");
            return 1;
            break;
        }
    }
    printf("You chose the Verb: %s", VerbChosen);
    
    printf("\nHere is your story:");
    printf("\n\nOne day, %s was walking along minding their own business when a giant %s began terrorizing Atlanta. This did not phase %s however because they had dealt with this before. They donned their %s costume and approached the %s. The %s-ness of their costume stunned the sentient %s and gave them enough time to %s the %s into submission. Having saved the day again, %s retired into the night, knowing that one day they would be needed again.\n\n", userName, NounChosen, userName, AdjChosen, NounChosen, AdjChosen, NounChosen, VerbChosen, NounChosen, userName);
    
    return 0;
   
    
}

int getChoice(int choiceMin, int choiceMax,char *prompt)
{
    int returnValue;
    do
    {
        fpurge(stdin);
        printf("%s", prompt);
        scanf("%d", &returnValue);
        fpurge(stdin);
    } while (returnValue < choiceMin || returnValue > choiceMax);
    return returnValue;
}
