
      dP"8                                                              888              d8         888 88b, ,e, 888 888 ,e,                          e88'Y88         888                    888           d8   ,e,                          dP"8                   d8                       
     C8b Y 8888 8888 888 88e   ,e e,  888,8, 888 888 8e   ,"Y88b 888,8, 888 ee  ,e e,   d88         888 88P'  "  888 888  "  888 8e   e88 888        d888  'Y  ,"Y88b 888  e88'888 8888 8888 888  ,"Y88b  d88    "   e88 88e  888 8e        C8b Y Y8b Y888P  dP"Y  d88    ,e e,  888 888 8e  
      Y8b  8888 8888 888 888b d88 88b 888 "  888 888 88b "8" 888 888 "  888 P  d88 88b d88888       888 8K   888 888 888 888 888 88b d888 888       C8888     "8" 888 888 d888  '8 8888 8888 888 "8" 888 d88888 888 d888 888b 888 88b        Y8b   Y8b Y8P  C88b  d88888 d88 88b 888 888 88b 
     b Y8D Y888 888P 888 888P 888   , 888    888 888 888 ,ee 888 888    888 b  888   ,  888         888 88b, 888 888 888 888 888 888 Y888 888        Y888  ,d ,ee 888 888 Y888   , Y888 888P 888 ,ee 888  888   888 Y888 888P 888 888       b Y8D   Y8b Y    Y88D  888   888   , 888 888 888 
     8edP   "88 88"  888 88"   "YeeP" 888    888 888 888 "88 888 888    888 8b  "YeeP"  888         888 88P' 888 888 888 888 888 888  "88 888         "88,d88 "88 888 888  "88,e8'  "88 88"  888 "88 888  888   888  "88 88"  888 888       8edP     888    d,dP   888    "YeeP" 888 888 888 
                     888                                                                                                               ,  88P                                                                                                        888                                     
                     888                                                                                                              "8",P"                                                                                                         888                                     
                                                                                                                                                                                                                                                                                                     
# **SUPERMARKET BILLING CALCULATION SYSTEM** 
                                       
## **Problem Statement**
Supermarket is the self-service shop where the customers come to purchase their daily using products and pay for that. 

It is very difficult for the Supermarket team to manage the record of each and every item in the store and keep track of all the sales records and there is also a need to calculate how many products are sold and to generate the bill for the customer. 

So all these tasks are not simple and easier so what I did is keeping these points in my mind I build this project using C++ objects and classes concepts.

#
## **INTRODUCTION**


The project is on Supermarket Billing Calculation System.

In my project I have 2 users. First one is the Manager who has the rights to change the login details of himself and the cashier or to add the new manager or new cashier. The manager also has the rights to change the stock and price of the items of the supermarket and add new item to the supermarket in short we can say that the manager has the rights to update the stock of items in supermarket.

Second one is the cashier who only has the rights to generate the bill by accepting the items and the quantity of the item purchased by the customer and generate the bill according to the item list made by the manager and then finally print the bill and generate the text file of the bill and at last collect the cash.

This supermarket billing system is created to assist cashier workers to calculate the total price of items that are purchased by the customers. To make the cashier worker's job more convenient, the system allows them to type in the product name and the stock of products purchased, thus calculating the total bill. Besides that, the system allows the manager to add, edit, all the products.

It also provide the manager to change his or her id password as well as the cashiers id password.

#
## **WORK FLOW**


Work in the Supermarket will be done in the following ways:
- The item will come in the store.
- Manager will enter the name, stock, and price of the item in the database.
- The customer will come and take the basket with him/her and choose the items and put them in the basket and took the basket to the counter.
- The cashier will take the item one by one and using barcode make the entry in the database and then the bill will be calculated and generated and then the total payment is shown.
- Customer will pay for the items.
- All the items will be packed by the cashier and then he will hand over it to the customer along with the bill. 

#
## **TOOLS USED**


- Programming language which is used is C++ .

- Operating System which is used is macOS BIG SUR Version: 11.6.4 .

- Software which is used is Visual Studio Code Version: 1.64.2(Universal) . 

- File handling is used for the Database which makes the project Standalone project so that full access of the project is given to the user that is the manager and cashier of supermarket without any requirement of the network. 


#
## **METHODOLOGY**
#

### **HEADER FILES USED**
#
```cpp 
#include<iostream>
```

     To use cin , cout that are basic input output streams.
#
```cpp 
#include<iomanip>
```
     
     To use the input output manipulators and one which is used in my code is setprecision().
#
```cpp 
#include<fstream>
```

     To do file handling as it has ofstream and ifstream in it.
#
```cpp 
#include<stdlib.h>
```

     To use clear screen function that is system(“clear”) .
#
```cpp 
#include<chrono>
#include<thread>
```
     Chrono and thread both are used to add time delay in my code.
     sleep_for(nanosecond())
     sleep_until(system_clock::now()+seconds())
#
```cpp 
#include<vector>
```
     It is used to use the vectors of STL.
#
```cpp 
#include<sstream>
```
     To create string object that is treated as the stream.
#
```cpp 
#include<ctime>
```
     To print the date and time .
#
```cpp 
#include<unistid.h>
```
     To create the loading animation.
#

### **CLASSES CREATED**
#
#### **User**
I have created an abstract class of  the user by declaring the pass_check() function as the pure virtual function in this class so that no object of this class can me created. And approximately my whole main components are written in this class only.

     Member Function of this class User

#
     1-initially()- Used to initialize the grand total and GST to 0 .
#
     2-set_id_pass()- Used to read the id pass of manager and cashier from the file password.txt and set them as the value in the variables .
#
     3-set_manager()- To set the updated id pass of manager to the file password.txt.
#
     4-set_cashier()- To set the updated id pass of cashier to the file password.txt.
#
     5-check_manager()- To check the login details of manager and return true if the details are matched .
#
     6-check_pass()- To check the password of both the manager and the cashier and return 1 if it matches the manager’s id/pass and if it matches the cashier’s id/pass return 2 else if it doesn’t matches with any one  return 0 .
#
     7-items()- To check for the item present in the stock and update the stock and price of the item if found and reflect the change back to the file items.txt
#
     8-Cashier_items()- To check if the item present in the file items.txt and if present then check its stock and price and then update it by asking user how many he wants to buy and then update the new reduced stock in the file items.txt and then keep the track of the item purchased for the generation of the bill.
#
     9-items_stock()- To update the stock of the item in items.txt.
#
     10-add_item()- To add the new item in the file items.txt.
#
     11-Bill_generate()- To take the list of purchased item and help in generating bill.
#
     12-load()- To create the loading animation().
#
     13-Bill_printing()- To print the bill in the terminal window and make the text file of the bill for the future reference.

#
#### **login**
I have created this class by inheriting the class User in it in public mode so that I can access all the member functions of class User.

     Member Function of this class login
#
     1-login()- To call the function initially of the class User.
#	
     2-manager_check()- To call the check_manager() function of the class User.
#
     3-pass_check()- To call the function check_pass() of the class User.
#
     4-set_id_password()- To call the function set_id_pass() of t	the class User.
#
     5-sign_up()- To set the id password for the manager and the cashier by calling the functions set_manager() and set_cashier() functions of the class User.
#    
     6-manager()-  Functions that gives the access to the manager to change the stock and price of the item by calling the function item_stock() and to add new items by calling the function add_item() of the class User.
#
     7-cashier()- Function that gives the access to the cashier to generate and print the bill by calling the function Bill_generate() of the class User.
#
And then there is the main program that is just the menu from where the control is transferred to the functions.

# Interface

![](screenshots/Screenshot%202022-02-26%20at%201.57.39%20PM.png)
#
When you press 1 ?

     You have to either enter manager’s or cashier’s id and password

![](screenshots/Screenshot%202022-02-26%20at%203.40.29%20PM.png)

If login credentials are correct

![](screenshots/Screenshot%202022-02-26%20at%203.45.19%20PM.png)

If login credentials are not correct

![](screenshots/Screenshot%202022-02-26%20at%203.50.08%20PM.png)

#
![](screenshots/Screenshot%202022-02-26%20at%201.57.39%20PM.png)

When you press 2 ?

     You have to enter manager’s or id and password

![](screenshots/Screenshot%202022-02-26%20at%203.40.29%20PM.png)

When the manager’s id pass are correct

![](screenshots/Screenshot%202022-02-26%20at%204.08.53%20PM.png)

When you press 1 ?

     You have to enter new manager’s or id and password

![](screenshots/Screenshot%202022-02-26%20at%204.12.09%20PM.png)

     Same goes for changing the cashiers id pass.

#
## *Managers interface*

![](screenshots/Screenshot%202022-02-26%20at%204.28.05%20PM.png)

     Here the manager can manage the stock of the previous item or add new items to the list.

#
## *Cashiers interface*

![](screenshots/Screenshot%202022-02-26%20at%204.30.37%20PM.png)

When the cashier prints 1 to generate the bill.


     He has to enter the names of the items purchased and then how many items were purchased.


     And when he is done entering all the items he should press 0

![](screenshots/Screenshot%202022-02-26%20at%204.37.29%20PM.png)

And then enter the customers name.

![](screenshots/Screenshot%202022-02-26%20at%204.39.50%20PM.png)

     And the bill get generated.

![](screenshots/Screenshot%202022-02-26%20at%204.42.51%20PM.png)

Text file of the bill also get generated in folder bills

     With the name of the customer and the receipt number of the bill with extension .txt

![](screenshots/Screenshot%202022-02-26%20at%204.44.43%20PM.png)

#### *And at last the command to the cashier is given to collect the cash*

![](screenshots/Screenshot%202022-02-26%20at%204.55.22%20PM.png)


#
# **Aim**

To make software fast in processing with good UI  so that it could be used for long duration without errors.

# **Objectives**

- To reduce large paper work.
- To increase efficiency and accuracy of system.
- To reduce time for organization.
- To search for data faster.

#
# **CONCLUSION**

At last I am able to complete the project and my project is fully functional and can be easily used by the supermarket to make their work fast and simple.
#
# **REFERENCE**

Some reference to complete this project is taken from google and youtube.
#
