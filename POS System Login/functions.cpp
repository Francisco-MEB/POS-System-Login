#include "header.h"
#include <iostream>
#include <string>

void display_attempts_remaining(int attempts_remaining)
{
    std::cout << "Attempts remaining: " << attempts_remaining << '\n';
}

std::string get_username()
{
    std::string user_id{};
    std::cout << "Username: ";
    std::getline(std::cin >> std::ws, user_id);
    
    return user_id;
}

std::string get_password()
{
    std::string password{};
    std::cout << "Password: ";
    std::getline(std::cin >> std::ws, password);
    
    return password;
}

bool validate_credentials(std::string username, std::string password, int &attempts)
{
    bool access_granted{};
    if ((username == admin_information::username) && (password == admin_information::password))
    {
        access_granted = true;
    }
    else
    {
        attempts--;
        access_granted = false;
    }
    
    return access_granted;
}

void display_permission(bool permission, int attempts_remaining)
{
    if (permission == true)
    {
        std::cout << "Access granted!\n\n";
    }
    else if (permission == false)
    {
        std::cout << "Access denied!\n\n";
    }
}





