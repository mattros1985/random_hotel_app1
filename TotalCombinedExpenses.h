



#ifndef TOTALCOMBINEDEXPENSES_H
#define TOTALCOMBINEDEXPENSES_H

#include "RoomServiceExpenses.h"
#include "DaysStayedExpenses.h"

namespace hotel_app
{
   class TotalCombinedExpenses : public DaysStayedExpenses, public RoomServiceExpenses
   {

   public:
      TotalCombinedExpenses()
      {
         total_bill = 0;
      }
      TotalCombinedExpenses(double days_stayed, int service_hours)
         : DaysStayedExpenses(days_stayed), RoomServiceExpenses(service_hours)
      {
         total_bill = 0;
      }
      virtual double calculateBill()
      {
         total_bill = (DaysStayedExpenses::calculateBill()) + (RoomServiceExpenses::calculateBill());
         return total_bill;
      }
   private:
      double total_bill;
   };
}
#endif
