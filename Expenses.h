
#ifndef EXPENSES_H
#define EXPENSES_H

namespace hotel_app
{
   class Expenses
   {
   public:
      virtual double calculateBill() = 0;
   private:
      int bill_amount;
   };
}
#endif   
