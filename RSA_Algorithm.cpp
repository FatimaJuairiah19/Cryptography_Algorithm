#include<stdio.h>
#include<math.h>
#include<conio.h>
#include <string.h>
#include<iostream>

using namespace std;

long long pow_mod(long long x, long long y, long long z)
{
    long long number = 1;
    while (y)
    {
        if (y & 1)
            number = number * x % z;
        y >>= 1;
        x = (long long)x * x % z;
    }
    return number;
}

int main(void)
{

    char inputString[100], c;
    int numberString[200];
    int index = 0,l,i,j;
    int count=0;
    int prime1=397;    //397
    int prime2=401;    //401
    int n,e,plaintext=0; //e=343
    int d;//12007
    int k=0;
    int remain;
    long long int ciphertext,PT;
    char convertedString[10000];

    printf("Enter a string\n");
    /* Read string from user using getchar
     inside while loop */
    while((c = getchar()) != '\n')
    {
        inputString[index] = c;
        index++;
    }
    inputString[index] = '\0';
    /* Print string stored in inputString using putchar */
    index = 0;
    while(inputString[index] != '\0')
    {
        //putchar(inputString[index]);
        index++;
    }

    for(i=0,j=0; inputString[j] != '\0'; j++,i++)
    {

        if(inputString[j]>='k' && inputString[j]<='z')
        {
            numberString[i]= (int)inputString[j]-97;
        }
        else if(inputString[j]>='a' && inputString[j]<='j')
        {
            numberString[i] = 0;
            numberString[i+1]= (int)inputString[j]-97;
            i++;
        }
        else if(inputString[j]>='A' && inputString[j]<='Z')
        {
            numberString[i]= (int)inputString[j]-65;
        }
        else
        {
            numberString[i]= (int)inputString[j];
        }
        cout << numberString[i] <<endl;
    }

    //l=strlen(numberString);
    int bw =i-1;
    for(i=0; i<=bw; i++)
    {
        // printf("%d",numberString[i]);
        printf("\n");
        if(numberString[i]<10)
            plaintext= plaintext*10;
        else
            plaintext = plaintext*100;
        plaintext= plaintext+numberString[i];
        printf("\n");
        printf("%d",plaintext);
    }
    printf("\n");
    printf("%d\n",plaintext);
    n=prime1*prime2;
    printf("n is %d\n",n);

    printf("enter E\n");
    scanf("%d",&e);
    printf("\n");
    printf("Enter d\n");
    scanf("%d",&d);

    ciphertext= pow_mod(plaintext, e, n);
    printf("%lld\n",ciphertext);

    PT = pow_mod(ciphertext, d, n);
    //PT= pow(ciphertext,d);
    // PT= PT % n;
    printf(" P is %lld\n",PT);


    while(PT!=0)
    {
        remain = PT % 100;
        //cout << "a --> " <<a << endl;
        PT = PT/100;
        remain = remain +65;
        convertedString[k] = char(remain);
        k++;
        //cout << char(a) <<endl;
    }

    for(i=k; i>=0; i--)
    {
        printf("%c",convertedString[i]) ;
    }
}

