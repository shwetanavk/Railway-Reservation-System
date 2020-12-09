#include <conio.h>
#include <stdio.h>


void main()
{

  int i,temp,flag1=-1,flag=-1,max=0;
  int in[12],out[12];

  printf("enter all 12 digits");
   for(i=0;i<12;i++)
   {
       scanf("%d", &in[i]);
   }

  for(i=0;i<12;i++)
  {
     if(in[i]==1)
      {
        temp=in[0];
        in[0]=1;
        in[i]=temp;
        flag=1;
      }
  }

 if(flag==-1)
 {

  for(i=0;i<12;i++)
  {
     if(in[i]==0)
      {
        temp=in[0];
        in[0]=0;
        in[i]=temp;
        flag=2;
      }
  }
 }

  if(flag<0)
     printf("output:0");
// for month 1st digit

     if (flag==1)
     {
          for(i=1;i<12;i++)
     {
        if(in[i]==2)
        {
         temp=in[1];
         in[1]=2;
         in[i]=temp;
         flag1=1;
       }
      }



       if(flag1==-1)
    {

    for(i=1;i<12;i++)
     {
        if(in[i]==1)
        {
         temp=in[1];
         in[1]=1;
         in[i]=temp;
         flag1=2;
       }
    }

    }

       if(flag1==-1)
    {

    for(i=1;i<12;i++)
     {
        if(in[i]==0)
        {
         temp=in[1];
         in[1]=0;
         in[i]=temp;
         flag1=3;
       }
    }

    }
   }


    if(flag==2)
    {
          for(i=1;i<12;i++)
          {
              if(in[i] >max)
              {
                  max=in[i];
              }
          }

          temp=in[1];
          in[1]=max;
          in[i]=temp;

    }

  // month is set


























 printf(" output is: \n ");


 for(i=0;i<2;i++)
  { printf("%d ",in[i]);
  }

 printf(" / ");


for(i=2;i<12;i++)
  { printf("%d ",in[i]);
  }






  getch();

}
