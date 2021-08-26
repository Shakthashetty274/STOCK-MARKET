typedef struct share_companies {                                           //structure named share_companies for storing name and id of company                                            
int company_id;                                                            //integer and array of character declaration
char company_name[40];
	
}sc;

int max_profit(double pp[],int a);
void SetColor(int ForgC);
void read_company(sc *s,int a);
double stockBuySellprofit(int price[], int n);
double stockBuySellloss(int price[], int n);
