#include <stdio.h>                                                         //this is a standard input and output header file           
#include <string.h>                                                        //header file required for string functions
#include <windows.h>                                                       //used to access the Win32 API functions and it makes it easy 
#include "m_server.h"

int main()
{	SetColor(3);                                                                                                  //function call
	printf("\n********************************************************************WELCOME TO STOCK MARKET ANALYSER****************************************************************\n");
	SetColor(13);                                                                                                 //function call
	printf("\nHERE WE ARE CONSIDERING BUYING PRICE OF THE STOCK TO BE THE DAY 1 STOCK PRICE\n");                  
	SetColor(5);double pp[100];                                                                    //pp is array of profit of every company
	int price[100],i,n;int cn;
	int m;int a;double profit,loss;
	sc s[100];int k;
	printf("\nHOW MANY COMAPNY STOCKS U WANT TO ANALYSE :::    ");                                //a is no' of stocks
	scanf("%d",&a);
	read_company(s,a);                                                                             //s is structure
	printf("\nENTER COMPANY DETAILS:- \n");
	for(i=1;i<a+1;i++)
		{
			
			printf("\nCOMAPANY DETAILS OF %d COMPANY\n",i);
			printf("\nLET US KNOW FOR HOW MANY DAYS DO YOU WANT TO ANALYSE :-  ");                           //n is no' of days
			scanf("%d",&n);
			if(n==0||n==1)                                                                            //n can't be zero bcz invalid
			{                                                                          //n=1 is a case of neither profit nor loss
				printf("\nPLEASE ENTER MINIMUM OF TWO DAYS!!\n");                  //hence invalid not included 
				scanf("%d",&n);                                                  //stocks cannot be buyed and selled on same day
			}
			printf("\nENTER THE STOCKS FOR %d DAYS :  ",n);
			int j;
			for(j=0;j<n;j++)
			{
				scanf("%d",&price[j]);
			}  
			
			profit=stockBuySellprofit(price, n);                                   //use of function call
			pp[i-1]=profit;                                                        //array of profit
			
			loss=stockBuySellloss(price,n);
			SetColor(13);
			printf("\n ______________________________________________________________________\n");
			SetColor(13);
			printf("|COMPANY_ID    |    COMPANY_NAME   |     PROFIT PER  |     LOSS PER    |\n");
			printf("|   %d          |     %s       | %lf       | %lf        |\n",s[i-1].company_id,s[i-1].company_name,profit,loss);	
			printf("|______________|___________________|_________________|_________________|\n");
			SetColor(5);			       
		}
		k=max_profit(pp,a);
		printf("\nMAXIMUM PROFIT ATTAINED BY %s\n ",s[k].company_name);
	return 0;

}                                                                                                          //we enjoyed making this code:)

