#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>

namespace admin_information
{
    const std::string username = "admin";
    const std::string password = "admin123";
}

void display_attempts_remaining(int attempts_remaining);
std::string get_username();
std::string get_password();

bool validate_credentials(std::string username, std::string password, int &attempts);
void display_permission(bool permission, int attempts_remaining);

#endif
