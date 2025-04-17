#pragma once
#include <string>

/**
 * @brief Provides utility functions to retrieve user input from the console.
 *
 * The Input class offers templated functions for prompting the user and converting
 * the input to a desired data type. Specializations are available for std::string,
 * unsigned short, and bool.
 */
class Input
{
public:
    
    // Prompts the user and retrieves input converted to the specified type.
    template<typename Type> static Type GetInputAs(const std::string prompt);
};
