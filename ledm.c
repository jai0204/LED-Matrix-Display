/*Program to display digits from 0-9*/
#include<reg52.h>
#include<stdio.h>
void delay(int);
void main()
{
    unsigned char d[]={0xdf,0xb1,0x7f,//0
                       0xff,0xff,0x7f,//1
                       0xdd,0xb5,0x77,//2
                       0xd5,0xb5,0x7f,//3
                       0xc7,0xa4,0x7f,//4
                       0xd7,0xb5,0x7d,//5
                       0xdf,0xb5,0x7d,//6
                       0xc1,0xa1,0x7f,//7
                       0xdf,0xb5,0x7f,//8
                       0xd7,0xb5,0x7f};//9
    while(1)
    {
        int i;
        for(i=0;i<10;i++)
        {
            for(j=0;j<100;j++)
            {
                for(k=0;k<3;k++)
                {
                    P0=d[i*3+k];   //persistence of vision
                    delay(1);
                }
            }
            P0=0xff;
            delay(350);   //delay in displaying next digit
        }
    }
}
void delay(int val)
{
    int x,y;
    for(x=0;x<val;x++)
    for(y=0;y<1275;y++);
}
