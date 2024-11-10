# Banking System Simulation

## Description

This is a simple banking system simulation that demonstrates how a queue data structure can be used to manage customer requests in a bank. Customers can be added to the queue to perform services like deposit, withdrawal, and account inquiry. The system processes customers sequentially, serving them in the order they arrive.

## Features

- *Customer Queue*: Customers are added to the queue based on their arrival.
- *Services*: Three types of services are offered:
  1. *Deposit*: Deposit a specified amount of money into the account.
  2. *Withdrawal*: Withdraw a specified amount of money from the account.
  3. *Account Inquiry*: Inquire about account status.
- *Queue Management*: The system serves customers in the order they arrive (FIFO).
- *Data Validation*: Ensures that negative amounts are not allowed for deposits or withdrawals.

## File Structure

- banking_system.c: Contains the main logic for the banking system simulation.
- README.md: This readme file.

## How to Compile and Run

1. *Clone the Repository*:
   Clone the repository to your local machine using the following command:
   
   git clone https://github.com/yourusername/banking-system.git
   

2. *Navigate to the Directory*:
   Go into the project directory:
   
   cd banking-system
   

3. *Compile the Code*:
   Use the following command to compile the program:
   
   gcc banking_system.c -o banking_system
   

4. *Run the Program*:
   After compilation, you can run the program using:
   
   ./banking_system
   

## Functions and Operations

### initQueue(Queue* queue)
- Initializes an empty queue.

### createCustomer(int id, char* name, int serviceType, float amount)
- Creates a new customer with the given details and returns a pointer to the new customer.

### enqueue(Queue* queue, Customer* customer)
- Adds a customer to the queue.

### dequeue(Queue* queue)
- Removes and returns the first customer from the queue.

### processCustomer(Customer* customer)
- Processes the customer’s request based on the selected service type (deposit, withdrawal, or inquiry).

### displayQueue(Queue* queue)
- Displays all customers currently in the queue, showing their IDs, names, and requested service types.

## Menu Options

1. *Add Customer to Queue*: Allows you to add a customer with an ID, name, service type, and amount (if applicable).
2. *Serve Customer*: Dequeues and processes the first customer in the queue.
3. *Display Queue*: Displays the current customers in the queue.
4. *Exit*: Exits the program.

## Example Usage

1. *Add a customer*:
   - ID: 101
   - Name: John Doe
   - Service Type: Deposit (1)
   - Amount: $500.00

2. *Serve the customer*:
   - The system processes the deposit for John Doe.

3. *Display Queue*:
   - Shows all customers currently waiting in the queue.

## License

This project is open-source and available under the MIT License.

## Contributions

Feel free to fork this repository and contribute to improvements. For any issues or suggestions, open an issue or submit a pull request.
