/*
   Purpose: This program simulates software that could be used by a hotel to enter customers,
   record when customer leave, etc. An add on would be to have the program store the customer
   information in a database when they leave and before it deletes the customer object.
   Author: Matthew Rossi
   Date: 8/26/15
   IDE: Visual Studio Express 2013
   Language: C++    
*/

#include <iostream> //cin, cout, getline, cin.clear(), cin.ignore()
#include "Hotel.h"
#include "TotalCombinedExpenses.h" 
#include "Customer.h"
#include <cstring> //getchar()
#include <exception> //exception

using namespace hotel_app;
using namespace std;

class creation_error : public exception
{
   virtual const char* what() const throw()
   {
      return "Error creating object";
   }
} creation_error;


void hotelOperations(Hotel hotel);

int main()
{
   Hotel hotel;
   hotelOperations(hotel);
   getchar();
   return 0;
}
void hotelOperations(Hotel hotel)
{
   int choices = 0;
   bool sentry = true;
   while (sentry)                                                          //continues until user enters 4
   {
      choices = 0;
      cin.clear();
      cout << "Enter a choice for your hotel: 1 for add customer, 2 for delete customer, \n3 show bill or 4 quit\n";
      cin >> choices;                                                      
      cin.clear();
      switch (choices)                                                     //main operation responding to user input 
      {
         case 1:                                                           //create new customer object and put it in hotel
         {
           {
               try
               {
                  Customer customer;
                  string temp_name, temp_cc, temp_addr;
                  int temp_party= 0;
                  cout << "Enter customer name, credit card, address, and number in party\n";
                  cin.clear();
                  cin.ignore(100, '\n');                                   //the .clear() and .ignore() are to clear buffer or left over chars
                  getline(cin, temp_name, '\n');
                  if (hotel.customerExists(temp_name))                     //This checks if the given name already is associated with a room
                  {
                     cout << "Customer by that name already stays here. Add a middle or new name.\n";
                     break;
                  }
                  cin.clear();
                  getline(cin, temp_cc, '\n');
                  getline(cin, temp_addr, '\n');  
                  cin.clear(); 
                  cin >> temp_party;
                  cin.clear();
                  cin.ignore(100, '\n');
                  customer.setName(temp_name);                     
                  customer.setAddress(temp_addr);                     
                  customer.setCreditCard(temp_cc);
                  customer.setPartyNumber(temp_party);
                  customer.setExpenses();
                  if (!(hotel.addCustomer(customer.getName(), customer)))
                     throw creation_error;
                  cout << "Room number is: " << ((hotel.getCustomer(temp_name, hotel)).getRoom()) << "\n";
               }
               catch (const char* str)                                     //this catches any thrown string that contains info on what went wrong
               {
                  cout << str << "\n";
               }
               catch (exception& e)
               {
                  cout << e.what() << '\n';
               }
               catch (...)
               {
                  cout << "Error creating customer object; try again or enter 4 to quit\n";
               }       
           }
           break;
         }
         case 2:                                                           //delete just customer
         {
           {
              string temp_name;
              cout << "Enter name of customer to delete\n";
              getline(cin >> ws, temp_name);
              try
              {
                 hotel.eraseCustomer(temp_name, hotel);
              }
              catch (...)
              {
                  cout << "Error erasing customer object; try again or enter 4 to quit\n";
              }
           }
           break;
         }
         case 3:                                                           //I kept this separate from Hotel and Customer to make 
         {                                                                 //demonstration of polymorphism easier
           {
              string billed_name;
              cout << "Enter name of customer to show bill\n";
              cin.clear();
              cin >> billed_name;
              cin.clear();
              if (!hotel.customerExists(billed_name))
              {
                 cout << "No customer here by that name.\n";
                 break;
              }                                                            //room service is like maids cleaning the room         
              cout << "Enter 1 for room service bill, 2 for time stayed bill, or  for total\n";
              int choice = 0;
              cin.clear();
              cin.ignore(100, '\n');
              cin >> choice;
              Expenses* ptr;
              switch (choice)                                              //switch in which polymorphism is demonstrated
              {
                 case 1:
                 {
                      {
                          cout << "Enter how many hours of service were done\n";
                          int i = 0;
                          cin >> i;
                          RoomServiceExpenses roomObject(i);
                          ptr = &roomObject;
                          cout << "Amount due is: $" << ptr->calculateBill() << "\n";
                          break;                           
                      }
                 }
                 case 2:
                 {
                      {
                          cout << "Enter how much time was spent here in days using decimal if necessary\n";
                          double i = 0;
                          cin >> i;
                          DaysStayedExpenses roomObject(i);
                          ptr = &roomObject;
                          cout << "Amount due is: $" << ptr->calculateBill() << "\n";
                          break;                          
                        }
                 }
                 case 3:
                 {
                     {
                        cout << "Enter how much time spent in hotel and how much time was spent on room service\n";
                        int i = 0;
                        double j = 0;
                        cin >> i >> j;
                        TotalCombinedExpenses roomObject(j, i);
                         ptr = &roomObject;
                         cout << "Amount due is: $" << ptr->calculateBill() << "\n";
                         break;                           
                     }
                 }
              }
            }
            break;
            }
            case 4:                                                        //option to exit system
            {
               {
                  cout << "Thank you for using the system. Good bye \n";
                  return;
               }
               break;
            }
            default:
            {
               cout << "Invalid. Reeter\n";
               break;
            }

           }
         }
      }
