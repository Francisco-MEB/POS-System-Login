#ifndef HEADER_H
#define HEADER_H

#include <vector>

#include "StructDefs.h"

namespace FileSpecifications
{
    inline constexpr int numberOfColumns{2};
    inline const std::string headerRow{"Username,Password"};
};

namespace ProgramRestrictions
{
    inline constexpr int maximumAttempts{3};
};

void ignoreLine();
bool correctFilePath(const std::string& filePath);
std::string getFilePath(std::string_view request);
void readHeaders(std::ifstream& file);
void readAccountInformation(std::ifstream& file, std::vector<Account>& accounts);
bool sortByUsername(const Account& a, const Account& b);
std::string getUsername();
std::string getPassword();
void displayPermission(const bool accessStatus);

#endif
