#include <stdio.h>
int main()
{
        double x, y;
        double x1, y1;
        printf("Enter the x movement of the first point:");
        scanf("%lf",&x);
        printf("Enter the y movement of the first point:");
        scanf("%lf",&y);
        printf("Enter the x movement of the second point:");
        scanf("%lf",&x1);
        printf("Enter the y movement of the second point:");
        scanf("%lf",&y1);
        int number;
        mead:
        printf("Add, Subtract, or multiply vectors(1, 2, 3)?:");
        scanf("%d",&number);
        double x3, y3;
        if(number == 1)
        {
                x3 = x + x1;
                y3 = y + y1;
        }
        else if(number == 2)
        {
                x3 = x - x1;
                y3 = y - y1;
        }
        else if(number == 3)
        {
                double multiplier;
                int decision2;
                head:
                printf("How much should the vector be enlarged/shrank and course changed?:");
                scanf("%lf",&multiplier);
                printf("Add or subtract(1, 2)?:");
                scanf("%d",&decision2);
                if(decision2 == 1)
                {
                        x3 = (x + x1) * multiplier;
                        y3 = (y + y1) * multiplier;
                }
                else if(decision2 == 2)
                {
                        x3 = (x - x1) * multiplier;
                        y3 = (y - y1) * multiplier;
                }
                else
                {
                        printf("Funny Joke lad.\n");
                        goto head;
                }
        }
        else
        {
                printf("Funny Joke lad.\n");
                goto mead;
        }
        double ox, oy;
        printf("Enter your original x coordinate dot:");
        scanf("%lf",&ox);
        printf("Enter your original y coordinate dot:");
        scanf("%lf",&oy);
        ox = ox + x3;
        oy = oy + y3;
        printf("Your dot, moved by vectors(%lfX %lfY), is now at (%lf, %lf)\n",x3, y3, ox, oy);
}
