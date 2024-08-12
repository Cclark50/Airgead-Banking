//
// Created by metat on 7/30/2024.
//

#ifndef INTERESTCALCULATOR_H
#define INTERESTCALCULATOR_H
#include <string>

/*@author Christian Clark
 *@date 7/31/24
 *
 *header definition for the interest calculator program
 *the overloaded constructor really should not be used, only the repopulate method should
 *when given the initial investment, monthly deposit, interest rate, and number of years,
 *will show the projected interest rate with and without the monthly deposit
 */

class InterestCalculator {
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_interestRate;
    int m_numberOfYears;
public:
    void repopulate(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears);
    //setters and getters
    double getInitialInvestment(){ return m_initialInvestment;}
    void setInitialInvestment(double t_initial_investment){m_initialInvestment = t_initial_investment;}
    double getMonthlyDeposit() {return m_monthlyDeposit;}
    void setMonthlyDeposit(double t_monthly_deposit){m_monthlyDeposit = t_monthly_deposit;}
    double getInterestRate() {return m_interestRate;}
    void setInterestRate(double t_interest_rate){m_interestRate = t_interest_rate;}
    int getNumberOfYears() {return m_numberOfYears;}
    void setNumberOfYears(int t_number_of_years){m_numberOfYears = t_number_of_years;}

    std::string createMoneyString(double t_inDouble);
    double balanceWithV2();
    void printDetails(int t_year, double t_yearEndBalance, double t_interestEarned);
    double calculateBalanceWithoutMonthlyDeposit();
    double balanceWithMonthlyDeposit();
    InterestCalculator();
    InterestCalculator(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears);
};



#endif //INTERESTCALCULATOR_H
