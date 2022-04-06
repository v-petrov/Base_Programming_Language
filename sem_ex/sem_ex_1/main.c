#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //#1
    for(int i = 1; i <= 10; ++i)
    {
        switch(i)
        {
            case 1:
                printf("%d => One\n", i);
                break;
            case 2:
                printf("%d => Two\n", i);
                break;
            case 3:
                printf("%d => Three\n", i);
                break;
            case 4:
                printf("%d => Four\n", i);
                break;
            case 5:
                printf("%d => Five\n", i);
                break;
            case 6:
                printf("%d => Six\n", i);
                break;
            case 7:
                printf("%d => Seven\n", i);
                break;
            case 8:
                printf("%d => Eight\n", i);
                break;
            case 9:
                printf("%d => Nine\n", i);
                break;
            case 10:
                printf("%d => Ten\n", i);
                break;
        }
    }

    //#2
    char x = '*';
    for(int i = 1; i <= 10; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            printf("%c", x);
        }
        printf("\n");
    }

    //#3
    char c, ws = ' ';
    int width,length;
    printf("Enter a char: ");
    scanf("%c", &c);
    printf("Enter the size of the frame(width): ");
    scanf("%d", &width);
    printf("Enter the size of the frame(length): ");
    scanf("%d", &length);
    printf("The size of your frame is: %d x %d\n\n", width, length);

    for(int i = 1; i <= length; ++i)
    {
        if(i == 1 || i == length)
        {
            for(int j = 1; j <= width; ++j)
            {
                printf("%c", c);
            }
        }
        else
        {
            printf("%c", c);
            for(int k = 1; k <= width - 2; ++k)
            {
                printf("%c", ws);
            }
            printf("%c", c);
        }
        printf("\n");
    }

    //#5
    int n;
    float inches,cm,mm,dm,m;
    printf("Enter inches: ");
    scanf("%g", &inches);
    printf("CM => type 1\nMM => type 2\nDM => type 3\nM => type 4\n");
    printf("Type in what do you want inches to be converted: ");
    scanf("%d", &n);

    switch(n)
    {
        case 1:
            cm = inches * 2.54;
            printf("Inches: %g => Centimeters: %g", inches, cm);
            break;
        case 2:
            mm = inches * 25.4;
            printf("Inches: %g => Millimeters: %g", inches, mm);
            break;
        case 3:
            dm = inches * 0.254;
            printf("Inches: %g => Decimeters: %g", inches, dm);
            break;
        case 4:
            m = inches * 0.0254;
            printf("Inches: %g => Meters: %g", inches, m);
            break;
        default:
            printf("Invalid metric converter!!!");
    }

    //#10
    double angle,val,ret;
    printf("Enter an angle: ");
    scanf("%lf", &angle);

    val = 3.14159265 / 180;
    ret = sin(angle*val);
    printf("The sine of %lf is %lf degrees", angle, ret);

    //#14
    double ppk_veg,ppk_fruit,veg_k,fruit_k,profit;
    printf("Enter the price for a killogram of vegetables in leva: ");
    scanf("%lf", &ppk_veg);
    printf("Enter the price for a killogram of fruits in leva: ");
    scanf("%lf", &ppk_fruit);
    printf("How many killogram of vegetables do you have: ");
    scanf("%lf", &veg_k);
    printf("How many killogram of fruits do you have: ");
    scanf("%lf", &fruit_k);

    profit = (ppk_veg * veg_k + ppk_fruit * fruit_k) / 1.72;
    printf("Your profit is: %lf $", profit);
    return 0;
}
