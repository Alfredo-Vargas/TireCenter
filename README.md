# TireCenter
This code is part of the assignment of the Course: Objected Oriented Programming part of the career Electronics ICT/AI from the Institute Thomas More (Belgium)
#
## NOTE:
For training purposes we implemented from scratch a Double Linked List.
Real implementations of this program should use the built-in list data type in C++ or even better just a vector:

## Class Diagram
![Class] (./Tire-Center-Class.png)

## User Case Diagram
![Use Case] (./Tire-Center-Use-Case.png)

## Check reasons why vectors are better than Linked Lists:
### https://www.youtube.com/watch?v=YQs6IC-vgmo&t=74s&ab_channel=AlessandroStamatto
### https://www.youtube.com/watch?v=DyG9S9nAlUM&t=2s&ab_channel=Computerphile
### https://www.geeksforgeeks.org/linked-list-vs-array/
#
# THE OBJECTIVE OF THE PROGRAM:
A tire dealer would like a new software package for their administration. In it they would like to manage their customer base, stock and invoicing. As a small software company you would like to win this order. For this it is necessary to submit a quotation to the customer which includes a use case diagram to show the functionality to the customer. You also need this to facilitate subsequent discussions. Internally in your company, it is also necessary to draw up a class diagram to divide the work and to estimate the duration and thus the cost of the project.
After a few conversations with those responsible for the system, the following emerges:
The tire center sells tires and rims in different sizes. They have a small stock of these, which they would like to manage with the program. They also want to keep track of the customers in this program and they want to know from each customer which tires and/or rims they have bought.
The program must be able to display the stock of all tires and rims that are sold. Even if they are not in stock, they must be displayed. It must be possible to display the entire stock, but it must also be possible to filter on either tires or rims. They would also like to be able to filter by size. Tires are sold per piece or per set of 2 or 4 pieces, rims always in sets of 4. When an employee has finished the total order of a customer, this stock is updated and an invoice is made with the price of the articles, the total price and the obtained discount.
All items have some fixed characteristics, such as a manufacturer, a name and a diameter. Tires have as additional characteristics a width and height (in mm), a speed index (letter) and a seasonal designation. Rims have a width (in inches) and a color and are made of steel or aluminum.
Customers are also tracked in the system. A split is made between private customers and corporate customers. For example, corporate customers are shown a different price than private customers and can receive an additional discount when purchasing 10 sets or more. Private customers get a discount when purchasing a set of four tires and extra discount when purchasing a matching set of rims. Each invoice prepared must be able to be linked to a customer.
The owner and an employee must be able to work with the system. The owner must be able to add new items and delete items. Both must be able to view and filter items. Also, both owner and employee must be able to add and view customers and retrieve invoices per customer. Only the owner should be able to delete a customer (the associated invoices should remain in the system).
Make sure you are complete in preparing your diagrams. Not all details were explicitly described, so you may make assumptions here and there.
