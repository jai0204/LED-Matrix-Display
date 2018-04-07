/*Program to display scrolling text - "HAPPY" using common anode configuration on 5x3 led matrix*/
#include<reg52.h>//header file for 8051 microcontroller(at89s52)
#include<stdio.h>
void delay(int);
void main()
{
    /*hex values taken are inverted due to use of external power supply for more brightness*/
    unsigned char z[]={0xe0,0xe0,0xff,0xe4,0xff,0xe0,//hex values for 'H'
                       0xfe,0xe5,0xfe,0xe0,          //hex values for 'A'
                       0xff,0xe5,0xe2,0xe0,          //hex values for 'P'
                       0xff,0xe5,0xe2,0xe0,          //hex values for 'P'
                       0xe1,0xfc,0xe1,0xe0,0xe0};    //hex values for 'Y'
    while(1)
    {
        int i,j;
        unsigned char c1,c2,c3;
        c1=0xdf;//masking value for column 1
        c2=0xbf;//masking value for column 2
        c3=0x7f;//masking value for column 3
        for(i=2;i<23;i++)
        {
            for(j=0;j<35;j++)//loop for proper persistence of vision
            {
                P0=z[i]&c3;
                delay(1);
                P0=z[i-1]&c2;
                delay(1);
                P0=z[i-2]&c1;
                delay(1);
            }
        }
        P0=0xff;//again initializing the led matrix
        delay(200);
    }
}
void delay(int val)
{
    int m,n;
    for(m=0;m<val;m++)
        for(n=0;n<1270;n++);
}
