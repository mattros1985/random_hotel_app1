/*
   Defining methods declared in Hotel.h
*/
#include "Customer.h"

using namespace hotel_app;

   int Customer::room;
   Customer::Customer()
   {
      name = "";
      address = "";
      credit_card_number = "";
      room = -1;
      number_in_party = 0;
   }
   void Customer::setExpenses()
   {
      expenses = NULL;
   }
   void Customer::setRoom(int filled_rooms)
   {
      this->room = filled_rooms;
   }
   void Customer::setName(string name)
   {
      if (isValidName(name) == string::npos)
         this->name = name;
      else
         throw ("Not a valid name. Please no digits\n");
   }
   void Customer::setCreditCard(string credit_card_number)
   {
      if (isValidCreditCard(credit_card_number))
         this->credit_card_number = credit_card_number;
      else
         throw ("Not valid credit card number. Must be 16 digits.\n");
   }
   void Customer::setAddress(string address)
   {
      this->address = address;
   }
   void Customer::setPartyNumber(int number_in_party)
   {
      if (number_in_party <= 7)
         this->number_in_party = number_in_party;
      else
         throw ("two many peope in party. Log in as two different customer parties.\n");
   }
   string Customer::getName() const
   {
      return name;
   }
   string Customer::getCreditCard() const
   {
      return credit_card_number;
   }
   string Customer::getAddress() const
   {
      return address;
   }
   int Customer::getPartyNumber() const
   {
      return number_in_party;
   }

   bool Customer::isDigits(const string &str) const
   {
      return all_of(str.begin(), str.end(), ::isdigit);
   }
   int Customer::getRoom() const
   {
      int temp = room;
      room++;
      return temp;
   }

   Expenses* Customer::getTotalExpenses() const
   {
      return expenses;
   }

   Customer::Customer(string name, string credit_card_number, string address, int number_in_party)
   {
      try
      {
         if (isValidName(name))
            this->name = name;
         else
            throw("Name was not valid");
         if (isValidCreditCard(credit_card_number))
            this->credit_card_number = credit_card_number;
         else
            throw("Credit card number invalid");
         this->address = address;
         if (number_in_party <= 7)
            this->number_in_party = number_in_party;
         else
            throw("Too many people in party");
      }
      catch (char* ex)
      {
         cout << ex;
         throw;
      }
      catch (...)
      {
         cout << "Error constructing customer file.";
         throw;
      }
   }
