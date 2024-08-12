//
// Created by metat on 7/30/2024.
//

#include "InterestCalculator.h"
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
using namespace std;

/*@author Christian Clark
 *@date 7/31/24
 *
 *method definitions for the interest calculator class
 */

//default constructor
InterestCalculator::InterestCalculator()
{
    m_initialInvestment = 0;
    m_interestRate = 0;
    m_monthlyDeposit = 0;
    m_numberOfYears = 0;
}

//overloaded constructor
InterestCalculator::InterestCalculator(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears)
{
    m_initialInvestment = t_initialInvestment;
    m_interestRate = t_interestRate;
    m_monthlyDeposit = t_monthlyDeposit;
    m_numberOfYears = t_numberOfYears;
}

//basically re-runs the constructor and repopulates all of the member variables
void InterestCalculator::repopulate(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears)
{
    m_initialInvestment = t_initialInvestment;
    m_interestRate = t_interestRate;
    m_monthlyDeposit = t_monthlyDeposit;
    m_numberOfYears = t_numberOfYears;
}

//prints the year end label
void printYearEndLabels()
{
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Year" << right << setw(33) << "Year End Balance" << right << setw(35) << "Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------------------" << endl;
}


std::string InterestCalculator::createMoneyString(double t_inDouble)
{
    stringstream outStream;
    outStream << "$" << fixed << setprecision(2) << t_inDouble;
    return outStream.str();
}


//prints the details of a particular year both with the end balance and interest earned that year
void InterestCalculator::printDetails(int t_year, double t_yearEndBalance, double t_interestEarned)
{
    cout << t_year;
    cout << right << setw(35) << createMoneyString(t_yearEndBalance);
    cout << right << setw(35) << createMoneyString(t_interestEarned) << endl;
}

//calculates the balance without a monthly deposit
double InterestCalculator::calculateBalanceWithoutMonthlyDeposit()
{
    //printing the label
    cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
    printYearEndLabels();

    //local variables
    double openingAmount = m_initialInvestment;
    double sumThisYear = 0;
    double interestThisMonth;
    double interestRateCalc = m_interestRate / 100;
    int numMonths = m_numberOfYears * 12;

    //performing the calculation
    for(int i = 1; i <= numMonths; i++){
        interestThisMonth = (openingAmount) * (interestRateCalc/12);
        sumThisYear += (openingAmount) * (interestRateCalc/12);
        openingAmount += interestThisMonth;
        //when we reach a year print that year's end balance and interest for that year
        if(i % 12 == 0){
            printDetails((i / 12), openingAmount, sumThisYear);
            sumThisYear = 0;
        }
    }

    cout << endl;
    return openingAmount;
}

//method that matched the unit tests
double InterestCalculator::balanceWithMonthlyDeposit()
{
    //prints the label
    cout << "Balance and Interest With Additional Monthly Deposits" << endl;
    printYearEndLabels();

    //if we have 0 years then no interest is earned
    if(m_numberOfYears == 0)
    {
        return m_initialInvestment;
    }

    //local variables
    double openingAmount = m_initialInvestment;
    double sumThisYear = 0;
    double interestThisMonth;
    double interestRateCalc = m_interestRate / 100;
    int numMonths = m_numberOfYears * 12;

    //first month we don't get interest for the deposit
    interestThisMonth = (openingAmount) * (interestRateCalc/12);
    sumThisYear += (openingAmount) * (interestRateCalc / 12);
    openingAmount += interestThisMonth + m_monthlyDeposit;

    //month 2 and onward we do the normal calculation
    for(int i = 2; i <= numMonths; i++){
        interestThisMonth = (openingAmount ) * (interestRateCalc/12);
        sumThisYear += (openingAmount ) * (interestRateCalc/12);
        openingAmount += interestThisMonth + m_monthlyDeposit;
        //if we reach a month print the balance and interest earned
        if(i % 12 == 0){
            printDetails((i / 12), openingAmount, sumThisYear);
            sumThisYear = 0;
        }
    }

    cout << endl;
    return openingAmount;
}

//new formula to match the specifications
double InterestCalculator::balanceWithV2()
{
    //prints the label
    cout << "Balance and Interest With Additional Monthly Deposits" << endl;
    printYearEndLabels();

    //if we have 0 years then no interest is earned
    if(m_numberOfYears == 0)
    {
        return m_initialInvestment;
    }

    //local variables
    double openingAmount = m_initialInvestment;
    double sumThisYear = 0;
    double interestThisMonth;
    double interestRateCalc = m_interestRate / 100;
    int numMonths = m_numberOfYears * 12;

    for(int i = 1; i <= numMonths; i++){
        interestThisMonth = (openingAmount + m_monthlyDeposit) * (interestRateCalc/12);
        sumThisYear += (openingAmount + m_monthlyDeposit) * (interestRateCalc/12);
        openingAmount += interestThisMonth + m_monthlyDeposit;
        //if we reach a month print the balance and interest earned
        if(i % 12 == 0){
            printDetails((i / 12), openingAmount, sumThisYear);
            sumThisYear = 0;
        }
    }

    cout << endl;
    return openingAmount;
}
