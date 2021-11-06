/*  Title: Program3.cpp
    Author: Gabriel Snider
    Date: 3-16-2020
    Description : Profit totals for the Foruli Flourish and Balbus Blotts bookstore. Using functions and arrays.
*/

#include "Program3.h"

/* The main function calls the other ones and prints out the output and sales totals. */
int main()
{
    bool runAgain = false;
    char userChoice;

    double profit[12];

    string months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    
    double quarterlyProfit[4];

    do {
        getProfit(profit);
        cout << setprecision(2)<<fixed;
        double yearProfit=getTotal(profit);
        double yearAverage=getAverage(profit);
        double mostProfit=getMax(profit);
        double minProfit=getMin(profit);
        int mostMonth=getMaxMonth(profit);
        int minMonth=getMinMonth(profit);
        getQuarterly(profit, quarterlyProfit);

        cout <<"Welcome to Flourish and Blotts Bookstore!" << endl;
        cout <<"--------------------------------------------------------------" << endl;
        cout <<"--------------------------------------------------------------" << endl;
        cout <<"\t TOTAL PROFITS FOR YEAR: \t $  " << yearProfit << endl;
        cout <<"\t YEARLY AVERAGE PROFIT: \t $  " << yearAverage << endl;
        cout <<"\t MONTH WITH LARGEST PROFIT: \t " << months[mostMonth] << " totaling at $ " << mostProfit << endl;
        cout <<"\t MONTH WITH SMALLEST PROFIT: \t " << months[minMonth] << " totaling at $ " << minProfit << endl;
        cout <<"--------------------------------------------------------------" << endl;
        cout <<"\n \n \t \t \t QUARTERLY PROFITS" << endl;
        cout <<"\t January - March \t $" << quarterlyProfit[0] << endl;
        cout <<"\t April - June \t \t $" << quarterlyProfit[1] << endl;
        cout <<"\t July - September \t $" << quarterlyProfit[2] << endl;
        cout <<"\t October - December \t $" << quarterlyProfit[3] << endl << endl;
        cout <<"--------------------------------------------------------------" << endl;
        cout <<"--------------------------------------------------------------" << endl;
        cout <<"Would you like to run the program again? (Y/N)" << endl;
        cin >> userChoice;

        if (userChoice == 'n')
        {
            return 0;
        }
        else if (userChoice == 'y')
        {
            runAgain=true;
        }
   
    }while (runAgain=true);

    return 0;
}


/* The getProfit function allows the user to enter in sales amounts for all 12 months. The data is then stored into the profit array. */
double getProfit(double *profit)
{
    for(int x=0; x<12; x++)
    {
        cout <<"Enter the profit for month " << x+1 <<":  $";
        cin >> profit[x];
        while(profit[x] < 0)
        {
            cout <<"I'm sorry, you must enter a profit greater than zero." << endl;
            cin >> profit[x];
        }

    }
}


/* The getTotal function tallys all the elements in the profit array together to get a total sales amount. The data is saved in the totalProfit variable. */
double getTotal(double *profit)
{
    double totalProfit=0;
    for(int i = 0; i < 12; i++)
    {
        totalProfit += profit[i];
    }
    return totalProfit;
}


/* The getMax function finds the month with the most profit in it from the profit array. */
double getMax(double *profit)
{
    double mostProfit=profit[0];
    int mostMonth=0;
    for(int i = 0; i < 12; i++)
    {
        if(profit[i] > mostProfit)
            mostProfit = profit[i];
            mostMonth= i;
        
    }
    return mostProfit;
} 
/* The getMaxMonth function does the same thing as the getMax Function except it returns the index for the Month instead of the profit. */
int getMaxMonth(double *profit)
{
    double mostProfit=profit[0];
    int mostMonth=0;
    for(int i = 0; i < 12; i++)
    {
        if(profit[i] > mostProfit)
        {
            mostProfit = profit[i];
            mostMonth= i;
        }
    }
    return mostMonth;
} 


/* The getMin function finds the month with the least profit in it from the profit array */
double getMin(double *profit)
{
    double leastProfit=profit[0];
    int leastMonth=0;
    for(int i = 0; i < 12; i++)
    {
        if(profit[i] < leastProfit)
        {
            leastProfit = profit[i];
            leastMonth= i;
        }
    }
    return leastProfit;
} 


/* The getMinMonth function does the same thing as the getMin function except it returns the index for the Month instead of the profit. */
int getMinMonth(double *profit)
{
    double leastProfit=profit[0];
    int leastMonth=0;
    for(int i = 0; i < 12; i++)
    {
        if(profit[i] < leastProfit)
        {
            leastProfit = profit[i];
            leastMonth= i;
        }
    }
    return leastMonth;
} 


/* The getQuarterly function finds the quarterly profit by using data from the profit array */
double getQuarterly(double *profit, double *quarterlyProfit)
{
    quarterlyProfit[0]=profit[0] + profit[1] + profit[2];
    quarterlyProfit[1]=profit[3] + profit[4] + profit[5];
    quarterlyProfit[2]=profit[6] + profit[7] + profit[8];
    quarterlyProfit[3]=profit[9] + profit[10] + profit[11];
    
} 


/* The getAverage function calculates the yearly average profit and returns that amount. */
double getAverage(double *profit)
{
    double yearAverage;
    yearAverage=(profit[0]+profit[1]+profit[2]+profit[3]+profit[4]+profit[5]+profit[6]+profit[7]+profit[8]+profit[9]+profit[10]+profit[11])/12;
    
    return yearAverage;
} 



