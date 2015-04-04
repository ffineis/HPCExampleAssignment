//
//  exampleAssignment1.c
//  
//
//  Created by Frank Fineis on 4/3/15.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int K);
int combinatorial (int N, int K);

int main()
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