#include "header.h"
#include <iostream>
#include <string>

int main()
{
    int maximum_attempts = 3;
    int attempts_remaining = maximum_attempts;
    bool permission{};
    
    do {
        display_attempts_remaining(attempts_remaining);
        std::string username = get_username();
        std::string password = get_password();
        
        permission = validate_credentials(username, password, attempts_remaining);
        
        display_permission(permission, attempts_remaining);
    } while ((permission == false) && (attempts_remaining != 0));
    
   
    if (permission != true)
    {
        std::cout << "Maximum attempts reached.\n\n";
        return 1;
    }
    
    return 0;
}








