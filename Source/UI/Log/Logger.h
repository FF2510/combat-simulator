#pragma once


#pragma region LOGGER_MACROS

    // ANSI Styles:
    #define TEXTSTYLE_RESET "0"
    #define TEXTSTYLE_BOLD "1"
    #define TEXTSTYLE_UNDERLINE "4"
    #define TEXTSTYLE_BLINK "5"
    #define TEXTSTYLE_INVERSE "6"

    // ANSI Colors: 
    #define TEXTCOLOR_BLACK "30"
    #define TEXTCOLOR_RED "31"
    #define TEXTCOLOR_GREEN "32"
    #define TEXTCOLOR_YELLOW "33"
    #define TEXTCOLOR_BLUE "34"
    #define TEXTCOLOR_MAGENTA "35"
    #define TEXTCOLOR_CYAN "36"
    #define TEXTCOLOR_WHITE "37"

    // ANSI Backgrounds:
    #define TEXTBACKGROUND_BLACK "40"
    #define TEXTBACKGROUND_RED "41"
    #define TEXTBACKGROUND_GREEN "42"
    #define TEXTBACKGROUND_YELLOW "43"
    #define TEXTBACKGROUND_BLUE "44"
    #define TEXTBACKGROUND_MAGENTA "45"
    #define TEXTBACKGROUND_CYAN "46"
    #define TEXTBACKGROUND_WHITE "47"
    #define TEXTBACKGROUND_NONE ""

    
    // Multi-Platform console clear:
    #ifdef _WIN32
        #define CLEAR_CONSOLE() system("cls")
    #else
        #define CLEAR_CONSOLE() system("clear")
    #endif

#pragma endregion



class Logger final
{
    
};
