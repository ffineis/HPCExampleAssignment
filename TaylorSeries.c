//
//  TaylorSeries.c
//  
//
//  Created by Frank Fineis on 4/4/15.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pascalTriangle.h"

double sinTaylor(double N, double x);
double cosTaylor(double N, double x);


int main()
{
    //Select problem to do, choose from 2 or 3//
    int test;
    printf("Please enter 2 for problem 2, enter 3 for problem 3.\n");
    scanf("%d", &test);
    
    if(test == 2)
    {
        double N, x, diffsin, diffcos;
        printf("Please enter integer N specifying length of series:\n");
        scanf("%lf", &N);
        printf("\nPlease enter value of double x to evaluate sine and cosine series:\n");
        scanf("%lf", &x);
        //printf("\nTaylor approx for sin(%lf) is %lf\n", x, sinTaylor(N, x));//
    
        diffsin = fabs(sin(x) - sinTaylor(N,x));
        diffcos = fabs(cos(x) - cosTaylor(N,x));
    
        printf("\nDifference between sin(%lf) and Taylor Series sin(%lf) is %lf\n", x, x, diffsin);
        printf("\nDifference between cos(%lf) and Taylor Series cos(%lf) is %lf\n", x, x, diffcos);
    
        return 0;
        
    }
    else
    {
        double a, b, g, l, r, tol, fl, fr;
        tol = pow(10.0, -6.0);
        printf("Please enter float a for left boundary:\n");
        scanf("%lf", &a);
        printf("Please enter float b for right boundary:\n");
        scanf("%lf", &b);

        double A = a;
        double B = b;
        
        g = ((-1) + sqrt(5))/2;
        l = b-g*(b-a);
        r = a+ g*(b-a);
        
        while((b-a)>tol)
        {
            fl = cos(l);
            fr = cos(r);
            if( fl > fr)
            {
                b = r;
                l = b-g*(b-a);
                r = a+ g*(b-a);
            }
            else
            {
                a = l;
                l = b-g*(b-a);
                r = a+ g*(b-a);
            }
        }
        printf("\nAccording to golden-ratio algorithm,\nLocal maximum of cosine between %lf and %lf is at x = %lf\n", A, B, (a+b)/2);
    }
}



double sinTaylor(double N, double x)
{
    int i;
    double sum = 0;
    double negone;
    for(i =0; i <= N; i+=1)
    {
        negone = pow((-1.0), i);
        sum += negone*pow(x, ((2*i)+1))/factorial(2*i+1);
    }
    return sum;
}

double cosTaylor(double N, double x)
{
    int i;
    double sum = 0;
    double negone;
    for(i =0; i <= N; i+=1)
    {
        negone = pow((-1.0), i);
        sum += negone*pow(x, ((2*i)))/factorial(2*i);
    }
    return sum;
}

