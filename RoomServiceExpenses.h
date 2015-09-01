
#ifndef ROOMSERVICEEXPENSES_H
#define ROOMSERVICEEXPENSES_H

#include "Expenses.h"

namespace hotel_app
{

   const double HOURLY_SERVICE_FEE = 9.5;
   class RoomServiceExpenses : public virtual Expenses
   {
   public:
      RoomServiceExpenses()
      {
         service_hours = 0;
      }
      RoomServiceExpenses(int service_hours)
      {
         this->service_hours = service_hours;
      }
      virtual double calculateBill()
      {
         return (HOURLY_SERVICE_FEE * service_hours);
      }
      int getServiceHours() const
      {
         return service_hours;
      }
   private:
      int service_hours;
   };
}
#endif
