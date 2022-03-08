#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lowest, highest = 300, step = 20, cel;
    float fahr;

    printf("Enter lowest celsius degree: ");
    scanf("%d",&lowest);

    while (lowest < 0)
    {
        printf("You have to enter only positive number\n\n");
        printf("Enter lowest celsius degree: ");
        scanf("%d",&lowest);
    }

    printf("Celsius to Fahrenheit\n");
    printf("C\tF\n");

    for(cel=lowest;cel<=highest;cel+=step)
    {
        fahr = cel * 9./5 + 32;
        printf("%d\t%g\n",cel,fahr);
    }
    return 0;
}
