/*Program to display a simple pattern*/
#include<reg52.h>
#include<stdio.h>
void delay(int);
void main()
{
    unsigned char row[]={0xde,0xbf,0x7f,
                         0xde,0xbe,0x7f,
                         0xde,0xbe,0x7e,
                         0xdc,0xbe,0x7e,
                         0xdc,0xbc,0x7e,
                         0xdc,0xbc,0x7c,
                         0xd8,0xbc,0x7c,
                         0xd8,0xb8,0x7c,
                         0xd8,0xb8,0x78,
                         0xd0,0xb8,0x78,
                         0xd0,0xb0,0x78,
                         0xd0,0xb0,0x70,
                         0xc0,0xb0,0x70,
                         0xc0,0xa0,0x70,
                         0xc0,0xa0,0x60};
    while(1)
    {
        int i,j,k,index=0;
        for(i=1;i<=120;i++)
        {
            P0=0xdf;//P0 - port0 of microcontroller
            delay(1);
            P0=0xbf;
            delay(1);
            P0=0x7f;
            delay(1);
        }
        for(i=0;i<15;i++)
        {
            for(j=0;j<50;j++)
            {
                for(k=0;k<3;k++)
                {
                    P0=row[index*3+k];
                    delay(1);
                }
            }
            index++;
         }
         delay(30);
    }
}
void delay(int val)
{
    int m,n;
    for(m=0;m<val;m++)
        for(n=0;n<1270;n++);
}
