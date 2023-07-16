#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "Header.h"
#include "StructDefs.h"

int main()
{
    std::ifstream file_accountInformation;
    std::string filePath_accountInformation{getFilePath("account information")};
    file_accountInformation.open(filePath_accountInformation, std::ios::in);
    if (!file_accountInformation.is_open())
    {
        std::cerr << "Could not open file containing account information." << '\n';
        return 1;
    }
    
    readHeaders(file_accountInformation);
    
    std::vector<Account> accounts{};
    readAccountInformation(file_accountInformation, accounts);
    std::sort(accounts.begin(), accounts.end(), sortByUsername); // Safeguard for unsorted file (unneeded if not using binary search)
    
    file_accountInformation.close();
    
    bool accessStatus{false};
    for (int i = ProgramRestrictions::maximumAttempts; i > 0; --i)
    {
        std::cout << "Attempts remaining: " << i << '\n';
        Account account{};
        account.username = getUsername();
        account.password = getPassword();
        
        if (std::binary_search(accounts.begin(), accounts.end(), account))
        {
            accessStatus = true;
            break;
        }
        
        /* Alternative for lack of library algorithms
        for (int i = 0; i < accounts.size(); ++i)
        {
            if (accounts[i].username == account.username && accounts[i].password == account.password)
            {
                accessStatus = true;
                break;
            }
        }
        
        if (accessStatus == true)
            break;
        */
    }
    
    displayPermission(accessStatus);
    
    
    return 0;
}
