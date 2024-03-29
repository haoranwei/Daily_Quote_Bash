#include <iostream>
#include <fstream>
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"

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
    if (quotes.IsArray()) {
        for (rapidjson::SizeType i = 0; i < quotes.Size(); i++) {
            std::cout << quotes[i].GetString() << std::endl;
        }
    }

    return 0;
}

