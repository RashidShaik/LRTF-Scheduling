#include<conio.h> 
#include<stdio.h>

struct student
{
    int S_Id;
    int F_Time;
    int W_Time;
    int TA_Time;
};
float ttemp,ttemp2;
void input(struct student list[], int s)
{
    int i;
    list[0].S_Id=2132;
    list[1].S_Id=2102;
    list[2].S_Id=2453;
    
    list[0].F_Time=2;
    list[1].F_Time=4;
    list[2].F_Time=8;
}
void display(struct student list[], int s)
{
    int i,AvgW_Time=0,AvgTA_Time=0;
	int TotalWatingTime=0,TotalTA_Time=0;
    printf("\n\n\t\t\tOutput Of LRTF\n");
    printf("\n\t\t\t|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|");
    printf("\n\t\t\t|Student_id\tFood_Taken_Time\t\tWaiting_Time\tTurn_Around_Time  |");
    printf("\n\t\t\t|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|");    
    for (i = 0; i < s; i++)
    {
        printf("\n\t\t\t|  %d\t\t\t%d\t            %d\t\t        %d\t  ", list[i].S_Id, list[i].F_Time,list[i].W_Time,list[i].TA_Time);
        printf("\a\n\t\t\t|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|");
		TotalWatingTime= TotalWatingTime+list[i].W_Time;
		ttemp=(float)TotalWatingTime;
		TotalTA_Time= TotalTA_Time+list[i].TA_Time;
		ttemp2=(float)TotalTA_Time;
	} 
	printf("\n\n\t\t\tTotal Waiting Time is: = %d",TotalWatingTime);
	printf("\n\t\t\tTotal Turn around Time is: = %d\n\n",TotalTA_Time);
	printf("\n\n\t\t\tAverage Waiting Time is: = %f",ttemp/3.0);
	printf("\n\t\t\tAverage Turn around Time is: = %f\n\n",ttemp2/3.0);
}
void scheduling(struct student list[], int s)
{
    int i, j;
    struct student temp;
    
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (list[j].F_Time < list[j + 1].F_Time)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            } 
            else if(list[j].F_Time == list[j + 1].F_Time)
            {
            	if(list[j].S_Id > list[j + 1].S_Id)
            	{
            	temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                }
			}
        }
    }
}
void W_Time(struct student list[], int n)
{
	int j;
    list[0].W_Time=0;
    for(j=1;j<n;j++)
    {
        list[j].W_Time=list[j-1].W_Time+list[j-1].F_Time;
    }
}
void TA_Time(struct student list[], int n)
{
	int j;
    
    for(j=0;j<n;j++)
    {
        list[j].TA_Time=list[j].W_Time+list[j].F_Time;
    }
}
int main()
{
    struct student data[20];
    int Num=3;
    input(data, Num);
    scheduling(data, Num);
    W_Time(data,Num);
    TA_Time(data, Num);
    display(data, Num);
}
