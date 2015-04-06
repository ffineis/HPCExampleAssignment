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

double sinTaylor(double N, double x);
double cosTaylor(double N, double x);
int factorial(int K);
int combinatorial (int N, int K);


int main()
{
    //Select problem to do, choose from 2 or 3//
    int test;
    printf("Please enter 1 for problem 1, enter 2 for problem 2, etc.\n");
    scanf("%d", &test);
    
    if(test ==1)
    {
        int n, k, fact, ROW;
        int i, j;
        printf("Please enter how many lines of the Pascal triangle you would like to display\n");
        scanf("%d", &ROW);
        
        for(i = 0; i<ROW; i+=1)
        {
            printf("\n");
            for(j = 0; j<= i; j+=1)
            {
                if (j==0)
                {
                    fact = combinatorial(i, j);
                    printf("%12d", fact);
                }
                else
                {
                    fact = combinatorial(i,j);
                    printf("%5d", fact);
                }
            }
        }
        printf("\n");
        //printf("%d choose %d is %6d\n", n, k, soln);//
        return 0;
    }
    
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
        sum += negone*pow(x, ((2.*i)))/factorial(2*i);
    }
    printf("Taylor approx to cos(%fl) is %fl", x, sum);
    return sum;
}

int factorial(int K)
{
    int i, fact = 1;
    if(K == 0)
    {
        fact = 1;
    }
    else
    {
        for(i = 1; i<=K; i+=1)
        {
            fact *= i;
        }
    }
    return fact;
}

int combinatorial (int N, int K)
{
    int denom, soln, factn, factk;
    if(N==0 && K == 0)
    {
        soln = 1;
    }
    else
    {
        factn = factorial(N);
        factk = factorial(K);
        denom = factorial((N-K));
        soln = factn/(factk*denom);
    }
    return soln;
}

