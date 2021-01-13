#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
int verification(int arr[3][3])
{
    int sum=0,i,j,n=3;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum+=arr[i][j];
        }
    }
    return sum;
}
int compare(int arr[3][3],int reference[3][3])
{
    int i,j,n=3,verify=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]==reference[i][j])
            {
                 verify++;
            }
        }
    }
    if(n*n==verify)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void print(int arr[3][3])
{
    int i,j,n=3;
    for(i=0;i<n;i++,printf("\n\n"))
    {
        for(j=0;j<n;j++)
        {
            printf("\t[_%d_]",arr[i][j]);
            
        }
    }
}
void swap(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
void left(int arr[3][3],int num)
{
    int i,j,n=3,temp,flag=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]==num && arr[i][j-1]==0)
            {
                swap(&(arr[i][j-1]),&(arr[i][j]));
                flag=1;
            }
        }
    }
    if(verification(arr)==36 && flag==1)
    {
       print(arr);
    }
    else
    {
        printf("\n\tInvalid move\a \n\n");
    }
}
void top(int arr[3][3],int num)
{
   int i,j,n=3,flag=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]==num&&arr[i-1][j]==0)
            {
                swap(&(arr[i-1][j]),&(arr[i][j]));
                flag=1;
            }
        }
    }
    if(verification(arr)==36&&flag==1)
    {
       print(arr);
    }
    else
    {
        printf("\n\tInvalid move\a \n\n");
    }
}
void right(int arr[3][3],int num)
{
   int i,j,n=3,flag=0;
    for(i=n-1;i>=0;i--)
    {
        for(j=n-1;j>=0;j--)
        {
            if(arr[i][j]==num&& arr[i][j+1]==0)
            {
                swap(&(arr[i][j]),&(arr[i][j+1]));
                flag=1;
            }
        }
    }
    if(verification(arr)==36&&flag==1)
    {
       print(arr);
    }
    else
    {
        printf("\n\tInvalid move\a \n\n");
    }
}

void bottom(int arr[3][3],int num)
{
    int i,j,n=3,flag=0;
    for(i=n-1;i>=0;i--)
    {
        for(j=n-1;j>=0;j--)
        {
            if(arr[i][j]==num && arr[i+1][j]==0)
            {
                swap(&(arr[i][j]),&(arr[i+1][j]));
                flag=1;
            }
        }
    }
    if(verification(arr)==36&&flag==1)
    {
       print(arr);
    }
    else
    {
        printf("\n\tInvalid move\a \n\n");
    }
}
void play(int arr[3][3],int choice,int number)
{
    switch (choice)
    {
        case 1:
          left(arr,number);
          break;
        case 2:
          top(arr,number);
          break;
        case 3:
          right(arr,number);
          break;
        case 4:
          bottom(arr,number);
          break;
        case 5:
          print(arr);
          break;
    }
}

int main()
{
    int hour, minute, second;
    hour=minute=second=0;
    int arr[3][3]={{4,1,3},{0,2,5},{7,8,6}},reference[3][3]={{1,2,3},{4,5,6},{7,8,0}},choice,number,times=0;
    printf("\n\n\t_________________________________________\n\n");
    printf("\tAre you ready to P.L.A.Y with numbers\n\t Rules:-)\n");
    printf("\t_________________________________________\n\n");
    printf("\tClick '1' for left move\n");
    printf("\tClick '2' for top move\n");
    printf("\tClick '3' for right move\n");
    printf("\tClick '4' for bottom move\n");
    printf("\tClick '5' for  <|| rewind ||>\n");
    printf("\tClick '0' for EXIT WINDOW!!\n ");
    printf("\tGET SET GO!\a \n\t Here's your grid!!\n\n");
    print(arr);
    printf("\n");
    while(1)
    {
        //system("clear");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t|_%02d_:_%02d_:_%02d_| \n\t\t\t\t\t\t\t\t\t| 1->left\n\t\t\t\t\t\t\t\t\t| 2->top\n\t\t\t\t\t\t\t\t\t| 3->right\n\t\t\t\t\t\t\t\t\t| 4->bottom\n\t\t\t\t\t\t\t\t\t| 5->savepoint\n"
        ,hour,minute,second);
        fflush(stdout);
        second++;
        if(second==60){
            minute+=1;
            second=0;
        }
        if(minute==60){
            hour+=1;
            minute=0;
        }
        if(hour==24){
            hour=0;
            minute=0;
            second=0;
        }
         
        sleep(1); 
       
        printf("\tYour choice : ");
        scanf("%d",&choice);
        //system("clear");
        if(choice>=1&&choice<=4)
        {
           printf("\n\tEnter the number to make a move : ");
           scanf("%d",&number);
           system("clear");
           printf("\n\n");
           play(arr,choice,number);
           
           if(compare(arr,reference)==1)
           {
               printf("\n\n\tCONGRATULATIONS!! YOU HAVE DONE in %d rounds!!",second);
               exit(0);
           }
           else
           {
               times++;
           }
        }
        if(choice==5)
        {
            play(arr,choice,0);
        }
        if(choice>5)
        {
            printf("\tWARNING InValid M.O.V.E!!\a read the instructions again\n");
            sleep(5);
            system("clear");
        }
        if(choice==0)
        {
            printf("\n\tWell played!! Better Luck Next Time");
            exit(0);
        }
        
    }


}