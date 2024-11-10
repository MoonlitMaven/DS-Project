#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Customer {
    int id;
    char name[50];
    int serviceType;
    float amount;
    struct Customer* next;
} Customer;

typedef struct Queue {
    Customer* front;
    Customer* rear;
    int size;
} Queue;

void initQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
    queue->size = 0;
}

Customer* createCustomer(int id, char* name, int serviceType, float amount) {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    newCustomer->id = id;
    strcpy(newCustomer->name, name);
    newCustomer->serviceType = serviceType;
    newCustomer->amount = amount;
    newCustomer->next = NULL;
    return newCustomer;
}

void enqueue(Queue* queue, Customer* customer) {
    if (queue->rear == NULL) {
        queue->front = queue->rear = customer;
    } else {
        queue->rear->next = customer;
        queue->rear = customer;
    }
    queue->size++;
    printf("Customer %s added to the queue.\n", customer->name);
}

Customer* dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty! No customers to serve.\n");
        return NULL;
    }
    Customer* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    queue->size--;
    return temp;
}

void processCustomer(Customer* customer) {
    printf("\nProcessing Customer ID: %d\n", customer->id);
    printf("Name: %s\n", customer->name);
    switch (customer->serviceType) {
        case 1:
            printf("Service: Deposit\n");
            printf("Amount Deposited: $%.2f\n", customer->amount);
            break;
        case 2:
            printf("Service: Withdrawal\n");
            printf("Amount Withdrawn: $%.2f\n", customer->amount);
            break;
        case 3:
            printf("Service: Account Inquiry\n");
            printf("Account Inquiry in Process...\n");
            break;
        default:
            printf("Invalid Service Type\n");
    }
    free(customer);
}

void displayQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("The queue is empty.\n");
        return;
    }
    Customer* temp = queue->front;
    printf("\nCurrent Queue:\n");
    while (temp != NULL) {
        printf("Customer ID: %d, Name: %s, Service Type: %d\n", temp->id, temp->name, temp->serviceType);
        temp = temp->next;
    }
}

int main() {
    Queue queue;
    initQueue(&queue);
    int choice, id, serviceType;
    char name[50];
    float amount;

    printf("=== Banking System Simulation ===\n");
    do {
        printf("\nMenu:\n");
        printf("1. Add Customer to Queue\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Customer ID: ");
                scanf("%d", &id);
                printf("Enter Customer Name: ");
                scanf(" %[^\n]", name);
                printf("Select Service Type (1: Deposit, 2: Withdrawal, 3: Inquiry): ");
                scanf("%d", &serviceType);
                
                amount = 0;
                if (serviceType == 1 || serviceType == 2) {
                    printf("Enter Amount: ");
                    scanf("%f", &amount);
                    
                    
                    if (amount < 0) {
                        printf("Error: Negative amounts are not allowed for deposits or withdrawals.\n");
                        break; 
                    }
                }

                
                Customer* customer = createCustomer(id, name, serviceType, amount);
                enqueue(&queue, customer);
                break;
            case 2:
                if (queue.size > 0) {
                    Customer* servedCustomer = dequeue(&queue);
                    processCustomer(servedCustomer);
                } else {
                    printf("No customers in the queue to serve.\n");
                }
                break;
            case 3:
                displayQueue(&queue);
                break;  
            case 4:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    
    while (queue.size > 0) {
        Customer* remainingCustomer = dequeue(&queue);
        free(remainingCustomer);
    }

    return 0;
}
