# Bank Acc. Class

A C++ class for holding bank account details.

## Data Dictionary

| Attribute          | Data Type     | Description                          |
|--------------------|---------------|--------------------------------------|
| `acc_num`          | `std::string` | The name of the account's holder.    |
| `acc_holder_name`  | `std::string` | The unique number of the account.    |
| `balance`          | `double`      | The amount of money in the account.  |

## Methods List

| Method Signature                    | Return Type   | Description                                     |
|-------------------------------------|---------------|-------------------------------------------------|
| `BankAccount()`                     | (Constructor) | Default constructor.                            |
| `BankAccount(title, author, isbn)`  | (Constructor) | Parameterized constructor.                      |
| `BankAccount(BankAccount)`          | (Constructor) | Duplication.                                    |
| `getAccountNumber()`                | `std::string` | Gets account number.                            |
| `getAccountHolderName()`            | `std::string` | Gets account holder's name.                     |
| `getBalance()`                      | `double`      | Gets current balance.                           |
| `setAccountHolderName(std::string)` | `void`        | Sets the name of the holder.                    |
| `deposit(double)`                   | `void`        | Puts x money into account.                      |
| `withdraw(double)`                  | `double`      | Takes x money out and returns the amount taken. |
