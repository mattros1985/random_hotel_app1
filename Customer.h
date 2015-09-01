
#ifndef CUSTOMER_H


#define CUSTOMER_H

#include <map>
#include <iostream>
#include <algorithm>
#include <cctype> //need all these?
#include "Expenses.h"
#include <string>

using namespace std;

namespace hotel_app
{

   const int CREDIT_CARD_NUM_LEN = 16;

   class Customer
   {
      friend ostream& operator<< (ostream& stream, const Customer& customer)
      {
         cout << "Name:  " << customer.getName() << "\n" << "Address: " << customer.getAddress() << "\n"
            << "Credit card: " << customer.getCreditCard() << "\n" << "Number in party:" << customer.getPartyNumber() << "\n";
         return stream;
      }
      public:
         static int room;
         Customer(string name, string credit_card_number, string address, int number_in_party);
         size_t isValidName(const string name)
         {
            return name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");
         }
         bool isValidCreditCard(const string &card)
         {
            if ((card.length() == CREDIT_CARD_NUM_LEN) &&  (isDigits(card)))
               return true;
            return false;
         }
         Customer();
         bool isDigits(const string &str) const;
         int getRoom() const;
         string getName() const;
         string getCreditCard() const;
         string getAddress() const;
         int getPartyNumber() const;
         Expenses* getTotalExpenses() const; 
         void setName(string name);
         void setRoom(int filled_rooms);
         void setCreditCard(string credit_card_number);
         void setAddress(string address);
         void setPartyNumber(int number_in_party);
         void setExpenses();
      private:
         string name;
         string credit_card_number;
         string address;
         int number_in_party;          
         Expenses* expenses;
   };
}
#endif
