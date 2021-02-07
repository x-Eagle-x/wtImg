#include <iostream>
#include <string>
#include <windows.h>
#include <SFML/Graphics.hpp>

#define STD_OUTPUT_HANDLE -11
#define VT100_MODE 0x4

int main(int argsCount, char** args)
{
    if (argsCount < 1)
    {
        std::cout << "No image was provided...\n";
        return EXIT_FAILURE;
    }

    sf::Texture tempTexture;
    if (!tempTexture.loadFromFile(args[1]))
    {
        std::cout << "No existing image was provided or lacking administrator privileges...\n";
        return EXIT_FAILURE;
    }
        
    auto hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD dMode;
    CONSOLE_FONT_INFOEX cFont;

    GetConsoleMode(hConsole, &dMode);
    SetConsoleMode(hConsole, dMode | VT100_MODE);
    
    GetCurrentConsoleFontEx(hConsole, TRUE, &cFont);
    cFont.cbSize = sizeof(cFont);
    cFont.dwFontSize.X = 1;
    cFont.dwFontSize.Y = 1;
    SetCurrentConsoleFontEx(hConsole, FALSE, &cFont);

    sf::Image image = tempTexture.copyToImage();
    sf::Color pixel;

    std::string output;

    auto sizeX = image.getSize().x, sizeY = image.getSize().y;
    for (int y = 0, x; y < sizeY; y++)
    {
        for (x = 0; x < sizeX; x++)
        {
            pixel = image.getPixel(x, y);
            output += "\033[48;2;" + std::to_string(pixel.r) + ";" + std::to_string(pixel.g) + ";" + std::to_string(pixel.b) + "m█\033[0m";
        }

        output += "\n";
    }

    std::cout << output;
    return EXIT_SUCCESS;
}
