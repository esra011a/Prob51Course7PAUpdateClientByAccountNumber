// Prob51Course7PAUpdateClientByAccountNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
const string ClientsFileName = "ClientsUpdate.txt";
vector<string> SplitString(string S1, string delim)
{
    vector<string> vString;
    //cout << "Your String Words are: \n";
    short pos = 0;
    string sword;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sword = S1.substr(0, pos);
        if (sword != "")
        {
            vString.push_back(sword);
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
    }
    return vString;
}
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double  AccountBalance;
    bool MarkForDelete = false;
    
};
string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string StClientRecord = "";
    StClientRecord += Client.AccountNumber + Seperator;
    StClientRecord += Client.PinCode + Seperator;
    StClientRecord += Client.Name + Seperator;
    StClientRecord += Client.Phone + Seperator;
    StClientRecord += to_string(Client.AccountBalance);

    return StClientRecord;
}
sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{

    sClient Client;
    vector <string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); //stod :cast string to double

    return Client;

}
vector <sClient> LoadClientsDataFromFile(string FileName)
{

    vector <sClient> VecClient;
    fstream MyFile;//out wirte //app append 
    MyFile.open(FileName, ios::in);//read mode
    if (MyFile.is_open())
    {
        string Line;
        sClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            VecClient.push_back(Client);

        }
        MyFile.close();
    }
    return VecClient;
}
void PrintClientRecord(sClient Client)
{
    // cout << "\n\nThe following is the extracted Clinet Record\n\n";
    cout << "Account Number: " << Client.AccountNumber << endl;
    cout << "PinCode       : " << Client.PinCode << endl;
    cout << "Name          : " << Client.Name << endl;
    cout << "Phone         : " << Client.Phone << endl;
    cout << "Account Balance: " << Client.AccountBalance << endl;
}
sClient ReadNewClient()
{
    sClient Client;


    cout << "Enter Account Number? ";
    //Usage of std::ws witll extract all teh whitespace charachter
    getline(cin >> ws, Client.AccountNumber);
    cout << endl;
    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);


    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}
string ReadFullString(string Message)
{
    string FullString;
    cout << Message << endl;
    getline(cin, FullString);
    return FullString;
}
bool FindClientByAccountNumber(string AccountNumber, vector <sClient> VecClients, sClient& Clinet)
{


    for (sClient C : VecClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Clinet = C;
            return true;
        }

    }
    return false;

}
vector <sClient> SaveClientDataToFile(string FileName, vector <sClient> VecClients)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out);//overwrite
    string DataLine;

    if (MyFile.is_open())
    {
        for (sClient C : VecClients)
        {
            if (C.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return VecClients;
}
sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;
    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin>>ws, Client.PinCode);
    
    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);


    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    
    return Client;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& VecClients)
{
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, VecClients, Client))
    {
        cout << "\nThe following are the Client details\n\n";
        PrintClientRecord(Client);
        cout << "\n Are you sure you want to update this Client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer=='Y')
        {
            for (sClient& C : VecClients)//imp to put & so the changeing will be saved in the vector
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
           
            }
            SaveClientDataToFile(ClientsFileName, VecClients);
           
            cout << "\n\nClient Updated Successfully\n";
            return true;
        }

    }
    else

    {
        cout << "\nClient with Account Number (" << AccountNumber;
        cout << ") Not Found!\n";
        return false;
    }
}
int main()
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadFullString("Please enter account Number? ");
    UpdateClientByAccountNumber(AccountNumber, vClients);
}

