
#include "Hotel.h"
#include "Customer.h"
#include <vector>
#include <map>
#include <iostream>

using namespace std;
using namespace hotel_app;

   Hotel::Hotel()
   {
      rooms.reserve(ROOMS);
      filled_rooms = 0;
   }
   bool Hotel::addCustomer(string customerName, Customer customer)
   {
      if (!isHotelFull())
      {
         try
         {
            customer_list.insert(pair<string, Customer>(customerName, customer));
            cout << "Customer is in the system. Have a great stay \n";
            rooms.insert(rooms.begin() + filled_rooms, customerName);
            customer.setRoom(filled_rooms);
            customer.setRoom(filled_rooms);
            ++filled_rooms;
            return true;
         }
         catch (...)
         {
            throw;
         }
      }
      else
      {
         cout << "Hotel is full. We cannot accept any more customers. \n";
         return false;
      }     
   }
   bool Hotel::eraseCustomer(string customerName, const Hotel& hotel)
   {
      try
      {
         if (customerExists(customerName))
         {
            int temp = (hotel.getCustomer(customerName, hotel)).getRoom();
            rooms.at(temp-1) = "EMPTY";
            customer_list.erase(customerName);           
            cout << "Thanks's for visiting us. Come again \n";
            return true;
         }
         cout << "No customer by that name, but thanks.\n";
         return true;
      }
      catch (...)
      {
         throw;
      }
   }
   bool Hotel::isHotelFull()
   {
      if (filled_rooms >= ROOMS)
         return true;
      return false;
   }
   void Hotel::displayCustomerList(map<string, Customer> cust_list)
   {
      typedef map<string, Customer>::const_iterator MapIterator;
      for (MapIterator iter = customer_list.begin(); iter != customer_list.end(); iter++)
      {
         cout << "Details:  " << iter->second << "\n";
      }
   }
   const map<string, Customer>& Hotel::getCustomerList() const 
   {
      return customer_list;
   }
