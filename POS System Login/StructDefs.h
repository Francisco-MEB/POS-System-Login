#ifndef STRUCTDEFS_H
#define STRUCTDEFS_H

struct Account
{
    std::string username{};
    std::string password{};
    
    bool operator<(const Account& other) const
    {
        return username < other.username;
    }
};

#endif
