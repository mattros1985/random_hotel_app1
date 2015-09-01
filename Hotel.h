
#ifndef HOTEL_H
#define HOTEL_H

#include <map>
#include <string>
#include "Customer.h"
#include <vector>

using namespace std;

namespace hotel_app
{
   const int ROOMS = 251;
   class Hotel
   {
   public:
      Hotel();
      bool customerExists(string &name) const
      {

         if ((getCustomerList().find(name)) == (getCustomerList().end()))
         {
            return false;
         }
         else
            return true;
      }
      static const int getHotelCapacity() 
      {
         return ROOMS;
      }
      bool addCustomer(string customerName, Customer customer);
      bool eraseCustomer(string customerName, const Hotel& hotel);
      bool isHotelFull();
      Customer Hotel::getCustomer(string &customer, const Hotel& hotel) const
      {
         if (hotel.customerExists(customer))
         {
            return (((getCustomerList()).find(customer))->second);            
         }
         else
            throw("Customer not in list\n");
      }
      const map<string, Customer>& getCustomerList() const;
      void displayCustomerList(map<string, Customer> cust_list);
   private:
      map <string, Customer> customer_list;
      vector<string> rooms;
      int filled_rooms;
   };
}
#endif
