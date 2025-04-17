#include "Input.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <string>
#include "../../UI/Log/Logger.h"
#include <cstdlib>
#include <cmath>


template <typename Type> Type Input::GetInputAs(const std::string prompt)
{
    Type result;

    // Display the prompt.
    std::cout << prompt << '\n';

    while (true)
    {
        std::string rawInput;
        getline(std::cin, rawInput);
        std::stringstream ss(rawInput);
        ss >> result;

        // Check if extraction was successful and no trailing characters remain.
        if (!ss.fail() && ss.eof())
        {
            return result;
        }
        else
        {
            CLEAR_CONSOLE();
            std::cout << Logger::AnsiString("Incorrect input. Try again: \n", TEXTSTYLE_BLINK, TEXTCOLOR_RED);
        }
    }

    // Source: https://cplusplus.com/reference/sstream/stringstream/
}

template <> std::string Input::GetInputAs<std::string>(const std::string prompt)
{
    while (true)
    {
        // Display the prompt.
        std::cout << prompt << '\n';

        // Get raw input.
        std::string rawInput;
        getline(std::cin, rawInput);

        if (!rawInput.empty())
        {
            return rawInput;
        }
        else
        {
            CLEAR_CONSOLE();
            std::cout << Logger::AnsiString("Incorrect input. Try again: \n", TEXTSTYLE_BLINK, TEXTCOLOR_RED);
        }
    }
}

template <> unsigned short Input::GetInputAs<unsigned short>(const std::string prompt)
{
    long long rawValue;
    
    while (true)
    {
        // Display the prompt.
        std::cout << prompt << '\n';
        
        std::string rawInput;
        getline(std::cin, rawInput);
        std::stringstream ss(rawInput);
        ss >> rawValue;

        // Check conversion and ensure no extra input remains.
        if (!ss.fail() && ss.eof())
        {
            rawValue = std::abs(rawValue);
            if (rawValue <= std::numeric_limits<unsigned short>::max())
            {
                return static_cast<unsigned short>(rawValue);
            }
            else
            {
                CLEAR_CONSOLE();
                std::cout << Logger::AnsiString("Value out of range (unsigned short). Try again: \n", TEXTSTYLE_BLINK, TEXTCOLOR_RED);
            }
        }
        else
        {
            CLEAR_CONSOLE();
            std::cout << Logger::AnsiString("Incorrect input. Try again: \n", TEXTSTYLE_BLINK, TEXTCOLOR_RED);
        }
    }

    // Source: https://cplusplus.com/reference/sstream/stringstream/
}

template <> bool Input::GetInputAs<bool>(const std::string prompt)
{
    while (true)
    {
        // Display the prompt.
        std::cout << prompt << '\n';
        
        // Retrieve raw input.
        std::string rawInput;
        getline(std::cin, rawInput);

        // Check for affirmative answers.
        if (rawInput == "yes" || rawInput == "y" || rawInput == "true" || rawInput == "1")
        {
            return true;
        }
        // Check for negative answers.
        else if (rawInput == "no" || rawInput == "n" || rawInput == "false" || rawInput == "0")
        {
            return false;
        }

        CLEAR_CONSOLE();
        std::cout << Logger::AnsiString("Incorrect input. Try again: \n", TEXTSTYLE_BLINK, TEXTCOLOR_RED);
    }
}