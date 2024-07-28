#include <stdio.h>  
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void pin(char PIN[4]);
int menu(void);
void checkBalance(float balance);
float deposit1(float balance, float deposit);
float withdrawl(float balance, float withdraw);
void countinue1(int continue2);
void line(void);
float fund_transfer(float amount, float balance, char acc[8]);
bool isNumeric(const char *str);
void saveTransactionToFile(const char *transaction);
void checkTransaction(void);
void clearFile(void);

float balance, deposit, withdraw;
int option, continue2;

void main(void)
{
    balance = 3000;
    char PIN[4], acc[8];
    
    pin(PIN);
    system("cls"); //clear screen
    clearFile();
    option = menu();
    system("cls");
    
    while (option > 0 && option < 6)
    {  
            if (option == 1)
            {
                checkBalance(balance);
            }
            
            if (option == 2)
            {
                printf("You choose to deposit money\n");
                printf("Your balance is: $%.2f\n", balance);
                printf("\nEnter the amount to deposit: ");
                scanf(" %f", &deposit);
                balance = deposit1(balance, deposit); // balance = balance + deposit
                printf("\nYour new balance is: $%.2f\n\n", balance);
            }
            
            if (option == 3)
            {
                printf("You choose to withdraw money\n");
                printf("Your balance is: $%.2f\n", balance);
                printf("\nEnter the amount to withdraw:  ");
                scanf(" %f", &withdraw);
                
                if(withdraw <= balance && withdraw > 0)
                {
                    balance = withdrawl(balance, withdraw); // balance = balance - withdraw, to keep the returned data, assign it to a variable
                    printf("\nYour new balance is: $%.2f\n\n", balance);
                }
       
                else if(withdraw > balance)
                    printf("You have insufficient balance.\n");
            }
            
            if (option == 4)
            {
                float amount;
                printf("You choose to transfer funds\n");
                printf("Your balance is: $%.2f\n\n", balance);
                printf("Enter account number (8 digits): ");
                scanf(" %s", acc);
                      
                if(strlen(acc) != 8 || (!isNumeric(acc)))
                    printf("You have entered an invalid account number.\n");
                
                else
                {
                    printf("Enter the amount to transfer: ");
                    scanf(" %f", &amount);
                    
                    if(amount <= balance && amount > 0)
                    {
                        system("cls");
                        balance = fund_transfer(amount, balance, acc);
                        printf("You have transfered successfully $%.2f to account no. %s.\n", amount, acc);
                        printf("Your available balance is: $%.2f\n\n", balance);
                    }

                    else if(amount > balance)
                        printf("You have insufficient balance.\n");
                 }
            }
            
            if (option == 5)
            {
                printf("Transaction History\n");
                checkTransaction();
            }
            
            line();
            countinue1(continue2);
            system("cls"); 
            option = menu();   
            system("cls");    
    }      
}
    
void pin(char PIN[4])
{   
    int num;
    int inputTimes = 3;
    int count      = 0;
    while(strlen(PIN) != 4 || (!isNumeric(PIN)))
        {
            if(count >= 1)
            {
                printf("\nYou have entered the wrong PIN %d times.\n", count);
                printf("You have %d more chances.\n\n", inputTimes - count);
               
            }
            count+=1;// count++ count the number of wrong inputs, to limit number of inputs
            
            if(count > inputTimes)
            {
                system("cls");
                printf("Please find assistance."); 
                exit(0); /* terminate the program without any error during the execution process
                            exit(1): forcefully terminate the program with an error */     
            }
                        
            printf("Enter 4-digit PIN: ");
            scanf(" %s", PIN);
        }   
}
    
bool isNumeric(const char *str)// determine whether the given string contains only numeric characters
{
    if(str == NULL || str[0] == '\0')//NULL: str points to an invalid memory location
    {
        return false;// str[0] == '\0' check whether the str is empty by examining the first character
    }
    const char *ptr = str;//use a pointer to trasverse the string, point to the first character of str
        
    while (*ptr != NULL || *ptr != '\0')//check through each character
    {
        if (*ptr < '0' || *ptr > '9')//if a non-numeric character is found, return false
        {
            return false;
        }
        ptr++; //move to the next character
    }
    
    return true; //all characters are numeric, return true
}

int menu(void)
{
    int i;
    printf("\nWelcome to the DBS\n");
    line(); 
    printf("<1> Check Balance\n");
    printf("<2> Cash Deposit\n");
    printf("<3> Cash Withdrawal\n");
    printf("<4> Funds Transfer\n");
    printf("<5> Check Transaction History\n");
    printf("<6> Exit");
    line(); 
    printf("\nPlease choose one of the options:  ");
    scanf(" %d", &i);
    printf("\n");
    return i;
}

void checkBalance(float balance)
{
    printf("You choose to check you balance\n");
    printf("Your available balance is: $%.2f\n", balance);
    
    char transaction[100];
    snprintf(transaction, sizeof(transaction), "Check Balance: $%.2f", balance);
    saveTransactionToFile(transaction);
}

float deposit1(float balance, float deposit)
{
    balance += deposit;
    
    char transaction[100];
    snprintf(transaction, sizeof(transaction), "Deposited: $%.2f", deposit);
    saveTransactionToFile(transaction);
    
    return balance;
}

float withdrawl(float balance, float withdraw)
{
    balance -= withdraw;
    
    char transaction[100];
    snprintf(transaction, sizeof(transaction), "Withdrew: $%.2f", withdraw);//snprintf function to format the transaction details and store them in the transaction array
    saveTransactionToFile(transaction);//call the function with transaction as the argument, pass the argument to the function 
    
    return balance;
}

void countinue1(int continue2)
{
    printf("\nDo you want to continue with other transactions? ");
    printf("\n<1> Yes\n");
    printf("<2> No\n");
    scanf(" %d", &continue2);
    system("cls");
    
    if (continue2 != 1)
        exit(0);
}

float fund_transfer(float amount, float balance, char acc[8])
{
   balance -= amount; 
   
   char transaction[100];
   snprintf(transaction, sizeof(transaction), "Transfered: $%.2f to account no. %s", amount, acc);
   saveTransactionToFile(transaction);
   
   return balance;
}

void line(void)
{
    printf("\n--------------------\n");
}

void saveTransactionToFile(const char *transaction)
{
    FILE *file = fopen("C:\\Users\\Thinkpad\\Desktop\\transaction\\data.txt", "a");//apend whatever content that we write to the file
    if(file == NULL)
    {
        printf("Error opening");
        return;
    }
    
    time_t now;//declare a variable named 'now' of data type 'time_t'
    time(&now);//retrieve the current time from the system and store in 'now' variable
    struct tm *local_time = localtime(&now);//local function take the pointer to variable time_t, return to struct
    char time_str[50];//struct tm represent calendar and time info, localtime, strftime: function
    strftime(time_str, sizeof(time_str), "%d-%m-%Y %H:%M:%S", local_time);//local_time is a pointer to to struct tm
    
    fprintf(file, "%s - %s\n", time_str, transaction);//what is printed in the file, file: where to write(argument)
    fclose(file);        
}

void checkTransaction(void)
{
    FILE *file = fopen("C:\\Users\\Thinkpad\\Desktop\\transaction\\data.txt", "r");//open file and assign it to 'file', read the file
    if(file == NULL)
    {
        printf("Error opening");
        return;
    }
    
    char line[1000];//array to store each line in the file
    while (fgets(line, sizeof(line), file) != NULL) //fgets copy the characters from file to array 'line'
    {
        printf(" %s", line);//to print all the lines
    }
    
    fclose(file);
}

void clearFile(void)
{
    FILE *file = fopen("C:\\Users\\Thinkpad\\Desktop\\transaction\\data.txt", "w");//open file for writing
    if(file == NULL)// w: open then delete whatever in that file, start with a blank file, then write into the file
    {
        printf("Error clear file");
        return;
    }
    
    fclose(file);//close access to the file
}




