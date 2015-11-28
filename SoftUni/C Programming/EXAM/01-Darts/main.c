#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct circle
{
    double x;
    double y;
    double R;
} Circle;

typedef struct
{
    double topLeftX;
    double topLeftY;
    double bottomRightX;
    double bottomRightY;
} Rect;

typedef struct
{
    double shotX;
    double shotY;
} Point;

int isInCircle(Circle *, Point *);
int isInsedeRectangle(Rect *, Point *);

int main()
{
    Circle board;
    Circle head;
    Rect arm;

    scanf("%lf %lf %lf%*c", &board.x, &board.y, &board.R);
    scanf("%lf %lf %lf%*c", &head.x, &head.y, &head.R);
    scanf("%lf %lf %lf %lf%*c", &arm.topLeftX, &arm.topLeftY,
          &arm.bottomRightX, &arm.bottomRightY);

    int spyroShots;
    scanf("%d%*c", &spyroShots);
    
    int totalPoint = 0;
    int successfulHitRatio;
    int hitOnBoard = 0;
    int baiMileHelth = 100;
    int countShots = 0;

    Point shot;
    int i;
    for (i = 0; i < spyroShots; i++)
    {
        scanf("%lf %lf%*c", &shot.shotX, &shot.shotY);

        if (isInCircle(&board, &shot))
        {
            if (isInCircle(&head, &shot) || isInsedeRectangle(&arm, &shot))
            {
                totalPoint += 25;
            }
            else
            {
                totalPoint += 50;
            }
            hitOnBoard++;
        }
        if (isInCircle(&head, &shot))
        {
            baiMileHelth -= 25;
        }
        if (isInsedeRectangle(&arm, &shot))
        {
            baiMileHelth -= 30;
        }

        countShots++;

        if (baiMileHelth <= 0)
        {
            baiMileHelth = 0;
            break;
        }
    }

    printf("\nPoints: %d\n", totalPoint);
    successfulHitRatio = (hitOnBoard / (float) (countShots))*100;
    printf("Hit ratio: %d%%\n", successfulHitRatio);
    printf("Bay Mile: %d\n", baiMileHelth);

    return (EXIT_SUCCESS);
}

int isInCircle(Circle *a, Point *tryShot)
{
    int isInside = ((a->x - tryShot->shotX) * (a->x - tryShot->shotX)) +
            ((a->y - tryShot->shotY) * (a->y - tryShot->shotY)) <= a->R * a->R;

    return isInside ? 1 : 0;
}

int isInsedeRectangle(Rect *a, Point *tryShot)
{
    int isInside = (a->topLeftX <= tryShot->shotX &&
                    a->bottomRightX >= tryShot->shotX) &&
                    (a->topLeftY >= tryShot->shotY &&
                    a->bottomRightY <= tryShot->shotY);

    return (isInside ? 1 : 0);
}