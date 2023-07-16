#include <array>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string_view>
#include <vector>

#include "Header.h"
#include "StructDefs.h"

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool confirmFilePath(const std::string& filePath)
{
    char confirm{};
    do
    {
        std::cin.clear();
        if (std::cin.fail())
        {
            ignoreLine();
        }
        
        std::cout << "Are you sure " << filePath << " is the correct file path (y, n)? ";
        std::cin >> confirm;
        confirm = tolower(confirm);
    } while (std::cin.fail() || (confirm != 'y' && confirm != 'n'));
    
    switch (confirm)
    {
        case 'y': return true;
        case 'n': return false;
        default: return false;
    }
}

std::string getFilePath(std::string_view request)
{
    std::string filePath{};
    bool correctPath{false};
    do
    {
        std::cout << "Enter file path containing " << request << ": ";
        std::getline(std::cin >> std::ws, filePath);
        
        correctPath = confirmFilePath(filePath);
    } while (correctPath == false);
    
    return filePath;
}

void readHeaders(std::ifstream& file)
{
    std::string headerRow{};
    std::getline(file, headerRow);
}

void readAccountInformation(std::ifstream& file, std::vector<Account>& accounts)
{
    std::string line{};
    while (std::getline(file, line))
    {
        Account account{};
        std::istringstream iss(line);
        std::string val{};
        for (int i = 0; i < FileSpecifications::numberOfColumns; ++i)
        {
            if (!std::getline(iss, val, ','))
            {
                break;
            }
            
            switch (i)
            {
                case 0: account.username = val;
                    break;
                case 1: account.password = val;
                    break;
                default:
                    break;
            }
        }
        
        accounts.push_back(account);
    }
}

bool sortByUsername(const Account& a, const Account& b)
{
    return a.username < b.username;
}

std::string getUsername()
{
    std::string username{};
    do
    {
        std::cin.clear();
        if (std::cin.fail())
        {
            ignoreLine();
        }
        
        std::cout << "Enter username: ";
        std::getline(std::cin >> std::ws, username);
    } while (std::cin.fail());
    
    return username;
}

std::string getPassword()
{
    std::string password{};
    do
    {
        std::cin.clear();
        if (std::cin.fail())
        {
            ignoreLine();
        }
        
        std::cout << "Enter password: ";
        std::getline(std::cin >> std::ws, password);
    } while (std::cin.fail());
    
    return password;
}

void displayPermission(const bool accessStatus)
{
    if (accessStatus == true)
    {
        std::cout << "Access granted!" << '\n';
    }
    else if (accessStatus == false)
    {
        std::cout << "Access denied." << '\n';
    }
}
