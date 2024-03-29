#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime> // For time()
#include <cstdlib> // For srand() and rand()
#include "include/rapidjson/document.h"
#include "include/rapidjson/filereadstream.h"

// Function to generate a random number within a range
int getRandomNumber(int min, int max) {
    static bool firstTime = true;
    if (firstTime) {
        srand(time(NULL)); // Seed the random number generator
        firstTime = false;
    }
    return min + rand() % ((max + 1) - min);
}

// Function to print colored text
void printColorText(const std::string& text, const std::string& color) {
    if (color == "red") {
        std::cout << "\033[1;31m" << text << "\033[0m"; // Red color
    } else if (color == "green") {
        std::cout << "\033[1;32m" << text << "\033[0m"; // Green color
    } else if (color == "blue") {
        std::cout << "\033[1;34m" << text << "\033[0m"; // Blue color
    } else {
        std::cout << text; // Default color
    }
}

int main() {
    // Open the JSON file with a relative path
    FILE* fp = fopen("/Daily_Quote_Bash/quotes.json", "r");

    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    rapidjson::Document document;
    document.ParseStream(is);
    fclose(fp);

    // Extract quotes from the JSON document
    const rapidjson::Value& quotes = document["quotes"];
    std::vector<std::string> allQuotes;

    if (quotes.IsArray()) {
        for (rapidjson::SizeType i = 0; i < quotes.Size(); i++) {
            allQuotes.push_back(quotes[i].GetString());
        }
        
        // Select a random quote and print it with color
        int randomIndex = getRandomNumber(0, allQuotes.size() - 1);
        std::string randomQuote = allQuotes[randomIndex];
        
        // Choose a random color
        std::vector<std::string> colors = {"red", "green", "blue"};
        int randomColorIndex = getRandomNumber(0, colors.size() - 1);
        std::string randomColor = colors[randomColorIndex];
        
        std::cout << "Random Quote: ";
        printColorText(randomQuote, randomColor);
        std::cout << std::endl;
    }

    return 0;
}
