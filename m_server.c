#include <stdio.h>                                                         //this is a standard input and output header file           
#include <string.h>                                                        //header file required for string functions
#include <windows.h>                                                       //used to access the Win32 API functions and it makes it easy
#include "m_server.h" 
        
                                                                       
int max_profit(double pp[],int a)                                          //function max_profit which contains two arguments
{                                                                          //a is company stocks
int max=0,d;                                                              
 for (int i=0;i<a;i++)                                                     //looping
{
	if(pp[i]>max)                                                      //if condition
	{
	 max=pp[i];                                                        //replacing max
	d=i;                                                                
	}
}
return d;                                                                  //to access the copany name 
} 
	
                                                                            //function setcolor
void SetColor(int ForgC)                                     
 {
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                 //Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 } 
void read_company(sc *s,int a)                                             //function to read company_id and company_name                        
 {
int i;
for(i=0;i<a;i++)
{

printf("\nENTER %d COMPANY ID AND NAME\n",(i+1));
scanf("%d",&s[i].company_id);
scanf("%[^\n]s",s[i].company_name);

}
}     

double stockBuySellprofit(int price[], int n)                            //function to find profit of a company                                  
{                                                                        //two arguments....price[] array and number of days
	int count = 0;                                                               
	int day =1;                                                                 
	int i = 0;
	int j=1;
	int max;
	int d;
	double profit_percentage;
			max =price[j]-price[0];                           //to find arbitrary max                       
			for(int j=2;j<n;j++)                                         
			{
				d=price[j]-price[i];                                 
				if(d>max)                                            
				{
				max=d;                                    //to find real max use of for loops                                 
				day=j;                                               

				}
				else 
				continue;	
			}
			printf("\nTHE MAXIMUM VALUE OF PROFIT GAINED CAN BE %d BY SELLING ON DAY %d\n",max,day+1);                //display
			double p=(double)max/price[0];                                                               //implicit conversion
			profit_percentage=p*100;                                                                     
			printf("\nTHE PERCENTAGE PROFIT OF SELLING ON DAY %d IS:%.2f\n",day+1,profit_percentage); 
			if(profit_percentage>=100)
			{
				printf("\nEXCELLENT PROFIT!!!!   AS THE PRICE OF STOCKS ARE MORE THAN DOUBLE OF BUYING PRICE.\n");
 			}
			
	return profit_percentage;
}
double stockBuySellloss(int price[], int n)                                                   //same as profit function with bit variable and 
{                                                                                             //sign changes
	int count = 0;                
	int day =1;
	int i = 0;
	int j=1;
	int min;
	int d;
	double loss_percentage;
			for (i=1;i<n;i++){                                                    
				if(price[i]>price[0]){
					count++;
				}
			}
			if(count==n-1)                                                            //if prices are continuosly increasing
			{
				printf("\nNO LOSS!!\n");                                          //no chances of loss
			}
			else{
			i=0;	
			min=price[j]-price[0];
			for(int j=2;j<n;j++)
			{
				d=price[j]-price[i];
				if(d<min)
				{
				min=d;
				day=j;

				}
				else 
				continue;	
			}
			printf("\nTHE MAXIMUM VALUE OF LOSS FACED CAN BE %d BY SELLING ON DAY %d\n",(-min),day+1);
			double p=(double)(-min)/price[0];
			loss_percentage=p*100;
			printf("\nTHE PERCENTAGE LOSS OF SELLING ON DAY %d IS:%.2f\n",day+1,loss_percentage); 
			if(loss_percentage>100)
			{
				printf("THIS IS A HIGH LOSS:|");
			}
			}	
	return loss_percentage;
}