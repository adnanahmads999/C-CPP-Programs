//
//  decimal to binary.c
//  c++ programs
//
//  Created by Adnan Ahmad on 17/10/21.
//

#include <stdio.h>
int main()
{
    
    int n,bin[40],i=0,n0=0,n1=0;
    //Taking input from user to convert into binary
    printf("Enter no to convert it into binary: ");
    scanf("%d",&n);
    
    while(n>0)
    {
        bin[i]=n%2;
        n=n/2;
        i++;
        
    }
    //priting binary form
    for(int j=i-1;j>=0;j--)
    {
        printf("%d",bin[j]);
    }
    //checking no of zero and one
    for(int j=i-1;j>=0;j--)
        {
            if(bin[j]==0)
           n0++;
            if(bin[j]==1)
            n1++;
        }
    printf("\n No of 1s is : %d",n1);
    printf("\n No of 0s is : %d",n0);
}
