# Prob51Course7PAUpdateClientByAccountNumber
# 🧾 Update Client by Account Number (C++ Project)

### 📂 File:
`Prob51Course7PAUpdateClientByAccountNumber.cpp`

---

## 📝 Overview

This console application allows you to **update client information** stored in a text file (`ClientsUpdate.txt`) using the **Account Number** as a unique key.

It reads all clients from the file, displays the selected client’s details, confirms the update request, and then overwrites the file with the new client data.

This project is part of **Course 7 - Problem 51** from *Programming Advices*.

---

## ⚙️ Features

- Read and parse client records from a text file.
- Find a specific client by their account number.
- Display existing client information.
- Update client details (PinCode, Name, Phone, Balance).
- Save all updated data safely back to the file.


---

## 📄 File Format

The program uses the following file:

Each client record must follow this format:
AccountNumber#//#PinCode#//#Name#//#Phone#//#AccountBalance
### ✅ Example:
A101#//#1234#//#Esraa Alharbi#//#0551234567#//#5000.75



> ⚠️ Make sure **there are no empty lines** in the text file — otherwise the program may fail to load data correctly.

---


## 🧩 Main Functions Explained

| Function | Description |
|-----------|-------------|
| `SplitString()` | Splits a string by a custom delimiter (`#//#`). |
| `ConvertLineToRecord()` | Converts a line of text into a `sClient` struct. |
| `ConvertRecordToLine()` | Converts a `sClient` struct back into a line of text. |
| `LoadClientsDataFromFile()` | Reads all clients from the file and stores them in a vector. |
| `FindClientByAccountNumber()` | Searches for a client in the vector. |
| `ChangeClientRecord()` | Reads updated client details from the user. |
| `SaveClientDataToFile()` | Overwrites the file with the updated vector data. |
| `UpdateClientByAccountNumber()` | Coordinates the entire update process. |

---
##Example Run

Please enter account Number?
A101
The following are the Client details

Account Number: A101
PinCode       : 1234
Name          : Esraa Alharbi
Phone         : 0551234567
Account Balance: 5000.75

Are you sure you want to update this Client? y/n ? y

Enter PinCode? 5678
Enter Name? Esraa F. Alharbi
Enter Phone? 0550001111
Enter AccountBalance? 5200.50

Client Updated Successfully

## 🧠 Data Structure

The `sClient` struct stores each client's information:
```cpp
struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};
```

##Example Run
```cpp
Please enter account Number?
A101
The following are the Client details

Account Number: A101
PinCode       : 1234
Name          : Esraa Alharbi
Phone         : 0551234567
Account Balance: 5000.75

Are you sure you want to update this Client? y/n ? y

Enter PinCode? 5678
Enter Name? Esraa F. Alharbi
Enter Phone? 0550001111
Enter AccountBalance? 5200.50

Client Updated Successfully
```
👩‍💻 Author

Esraa Fahad Alharbi
🎓 B.Sc. in Computer Science – Taibah University
💡 Passionate about web development, and software engineering.

