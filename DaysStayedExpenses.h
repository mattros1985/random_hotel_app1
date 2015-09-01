

#ifndef DAYSSTAYEDEXPENSES_H
#define DAYSSTAYEDEXPENSES_H

#include "Expenses.h"

namespace hotel_app
{
   const int DAILY_CHARGE = 12;
   class DaysStayedExpenses : public virtual Expenses
   {
   public:
      DaysStayedExpenses()
      {
         days_stayed = 0;
         stayed_bill = 0;
      }
      DaysStayedExpenses(double days_stayed)
      {
         this->days_stayed = days_stayed;
      }
      double getDaysStayed() const
      {
         return days_stayed;
      }
      int getStayedBill() const
      {
         return stayed_bill;
      }
      virtual double calculateBill()
      {
         return(DAILY_CHARGE * days_stayed);
      }
   private:
      int stayed_bill;
      double days_stayed;
   };
}
#endif
