#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include "InterestCalculator.h"
using namespace std;

/*@author Christian Clark
 *@date 7/31/24
 *
 *This program will calculate the yearly interest rate with and without the montly deposit
 *given the initial investment, monthly deposit, interest rate, and number of years
 *will loop unitl the user asks to quit
 *
 */

//asks user for input and returns using the parameters
void getUserInput(double &t_initialInvestment, double &t_monthlyDeposit, double &t_interestRate, int &t_numberOfYears)
{
    cout << "****************************************" << endl;
    cout << "************** Data Input **************" << endl;
    //input validation
    while(true)
    {
        cout << "Iniitial Investment Amount: ";
        try
        {
            cin >> t_initialInvestment;
            if(cin.fail())
            {
                throw runtime_error("Invalid Input");
            }
            if(fabs(t_initialInvestment - 0) < 0.0001 || t_initialInvestment > 0)
            {
                break;
            }
            throw runtime_error("Please enter value of 0 or greater");
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while(true)
    {
        cout << endl << "Monthly Deposit: ";
        try
        {
            cin >> t_monthlyDeposit;
            if(cin.fail())
            {
                throw runtime_error("Invalid Input");
            }
            if(fabs(t_monthlyDeposit - 0) < 0.0001 || t_monthlyDeposit > 0)
            {
                break;
            }
            throw runtime_error("Please enter value of 0 or greater");
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while(true)
    {
        cout << endl << "Annual Interest: ";
        try
        {
            cin >> t_interestRate;
            if(cin.fail())
            {
                throw runtime_error("Invalid Input");
            }
            if(fabs(t_interestRate - 0) < 0.0001 || t_interestRate > 0)
            {
                break;
            }
            throw runtime_error("Please enter value of 0 or greater");
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while(true)
    {
        cout << endl << "Number of years: ";
        try
        {
            cin >> t_numberOfYears;
            if(cin.fail())
            {
                throw runtime_error("Invalid Input");
            }
            if(t_numberOfYears > 0)
            {
                break;
            }
            throw runtime_error("Please enter positive value");
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << endl;
    //this prints press any key to continue and waits for user input
    system("pause");
}

int main()
{
    //local variables for the program
    auto calc = std::make_unique<InterestCalculator>();
    string continueInput = "y";
    double initialInvestment, monthlyDeposit, interestRate;
    int numberOfYears;

    //loop to get input and print interest
    while(continueInput == "y")
    {
        getUserInput(initialInvestment, monthlyDeposit, interestRate, numberOfYears);
        calc->repopulate(initialInvestment, monthlyDeposit, interestRate, numberOfYears);
        // calc->balanceWithMonthlyDeposit();
        calc->balanceWithV2();
        calc->calculateBalanceWithoutMonthlyDeposit();
        cout << "Type \"y\" to use another set of parameters or \"n\" to quit" << endl;
        cin >> continueInput;
    }

    cout << "Exiting program" << endl;
    return 0;
}
