#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define Customer Information
struct Customer {
    char name[50];
    char sex[10];
    int age;
    char accountNumber[20];
    char telephone[20];
    char email[50];
    char address[100];
    char occupation[50];
};

// Global Variables
float balance = 74500.5000;
int transactionID = 1;

// Function to generate transaction ID
void generateTransactionID(char type[], char transID[]) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(transID, "%02d%02d%04d%s%06d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, type, transactionID++);
}

// Function to display customer information
void displayCustomerInfo(struct Customer customer) {
    printf("\nCustomer Information:\n");
    printf("Name: %s\nSex: %s\nAge: %d\nAccount Number: %s\nTelephone: %s\nEmail: %s\nAddress: %s\nOccupation: %s\n",
           customer.name, customer.sex, customer.age, customer.accountNumber, customer.telephone,
           customer.email, customer.address, customer.occupation);
}

// Function to check balance
void checkBalance() {
    printf("\nCurrent Balance: %.2f Frw\n", balance);
}

// Function to perform withdrawal
void withdraw() {
    float amount;
    char transID[20];
    printf("\nEnter Amount to Withdraw: ");
    scanf("%f", &amount);

    if (amount >= 17470.5000 && amount <= 72500.5000 && amount <= balance) {
        balance -= amount;
        generateTransactionID("WD", transID);
        printf("Withdrawal Successful!\nTransaction ID: %s\nNew Balance: %.2f Frw\n", transID, balance);
    } else {
        printf("Invalid Withdrawal Amount!\n");
    }
}

// Function to perform deposit
void deposit() {
    float amount;
    char transID[20];
    printf("\nEnter Amount to Deposit: ");
    scanf("%f", &amount);

    if (amount >= 1455.5000) {
        balance += amount;
        generateTransactionID("DP", transID);
        printf("Deposit Successful!\nTransaction ID: %s\nNew Balance: %.2f Frw\n", transID, balance);
    } else {
        printf("Minimum deposit amount is 1455.5000 Frw!\n");
    }
}

int main() {
    struct Customer customer = {"NIYONIZEYE John Peter", "Male", 28, "100074500205", "+250 734772160", 
                                "niyojohnpeter01@gmail.com", "Karongi, Bwishyura, Kiniha, Karutete", "Teacher/Trainer"};
    int choice;
    
    while (1) {
        printf("\nMAIN MENU\n");
        printf("1. Display Customer Information\n");
        printf("2. Check Balance\n");
        printf("3. Withdraw\n");
        printf("4. Deposit\n");
        printf("5. Continue\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayCustomerInfo(customer);
                break;
            case 2:
                checkBalance();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                deposit();
                break;
            case 5:
                continue;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid Choice! Please try again.\n");
        }
    }
    return 0;
}

