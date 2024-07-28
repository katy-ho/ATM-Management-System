# ATM Management System

## Description
This project simulates an ATM management system with functionalities such as checking balance, depositing money, withdrawing money, transferring funds, and viewing transaction history. The user interacts with the system through a command-line interface.

## Features
1. **PIN Authentication**: Users must enter a 4-digit PIN to access the system.
2. **Check Balance**: View the current account balance.
3. **Cash Deposit**: Deposit money into the account.
4. **Cash Withdrawal**: Withdraw money from the account.
5. **Funds Transfer**: Transfer funds to another account.
6. **Transaction History**: View the history of all transactions.
7. **Session Management**: Clear transaction history at the start of a new session.

## Usage
1. Clone the repository or download the source code.
2. Compile the code using a C compiler.
3. Run the executable to start the ATM simulation.

## Code Structure
- **pin**: Function for PIN authentication.
- **menu**: Function to display the main menu and get the user's choice.
- **checkBalance**: Function to display the current balance.
- **deposit1**: Function to handle cash deposits.
- **withdrawl**: Function to handle cash withdrawals.
- **fund_transfer**: Function to handle fund transfers.
- **isNumeric**: Helper function to check if a string contains only numeric characters.
- **saveTransactionToFile**: Function to save transaction details to a file.
- **checkTransaction**: Function to display the transaction history.
- **clearFile**: Function to clear the transaction history at the start of a new session.
- **countinue1**: Function to ask the user if they want to perform another transaction.
- **line**: Function to print a separator line.

## Example
Here's an example of how to run the ATM management system:

1. Start the program and enter the 4-digit PIN.
2. Choose an option from the menu (e.g., check balance, deposit money).
3. Follow the prompts to complete the selected transaction.
4. View the updated balance or transaction history as needed.

## Note
- Ensure that the transaction file path is correctly set in the code.
- This project uses file I/O to save and retrieve transaction details. Make sure the file path is accessible and has the necessary permissions.
