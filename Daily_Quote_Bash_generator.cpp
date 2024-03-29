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

int main() {
    // Read the JSON file
    FILE* fp = fopen("quotes.json", "r");
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
        
        // Select a random quote and print it
        int randomIndex = getRandomNumber(0, allQuotes.size() - 1);
        std::cout << "Random Quote: " << allQuotes[randomIndex] << std::endl;
    }

    return 0;
}

