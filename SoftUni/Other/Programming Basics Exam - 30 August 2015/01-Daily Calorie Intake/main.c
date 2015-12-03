#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double basal_metabolic_rate(int weight, int height, int age, char gender);

int main()
{
    int weight, height, age, workOuts;
    char gender;

    scanf("%d %d %d %c %d%*c", &weight, &height, &age, &gender, &workOuts);

    double bmr = basal_metabolic_rate(weight, height, age, gender);

    double dailyCalorieIntake;

    if (workOuts <= 0)
    {
        dailyCalorieIntake = bmr * 1.2;
    }
    else if (workOuts >= 1 && workOuts <= 3)
    {
        dailyCalorieIntake = bmr * 1.375;
    }
    else if (workOuts >= 4 && workOuts <= 6)
    {
        dailyCalorieIntake = bmr * 1.55;
    }
    else if (workOuts >= 7 && workOuts <= 9)
    {
        dailyCalorieIntake = bmr * 1.725;
    }
    else
    {
        dailyCalorieIntake = bmr * 1.9;
    }

    dailyCalorieIntake = floor(dailyCalorieIntake);
    printf("%.0lf", dailyCalorieIntake);

    return (EXIT_SUCCESS);
}

double basal_metabolic_rate(int weight, int height, int age, char gender)
{
    double weightInKG = weight / 2.2,
            heightInSM = height * 2.54;
    if (gender == 'm')
    {
        return (66.5 + (13.75 * weightInKG) +
                (5.003 * heightInSM) - (6.755 * age));
    }
    else
    {
        return (655 + (9.563 * weightInKG) +
                (1.850 * heightInSM) - (4.676 * age));
    }
}