//
// Created by Surik Simonyan on 23.06.25.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

class CmsParser {
public:
    void parse(const std::string &filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Cannot open file: " << filename << std::endl;
            return;
        }

        std::string line;
        std::string currentSection;

        while (std::getline(file, line)) {
            trim(line);
            if (line.empty()) continue;
            if (line[0] == ';' || line[0] == '#') continue;

            if (line.front() == '[' && line.back() == ']') {
                currentSection = line.substr(1, line.size() - 2);
                trim(currentSection);
            } else {
                auto pos = line.find('=');
                if (pos != std::string::npos) {
                    std::string key = line.substr(0, pos);
                    std::string value = line.substr(pos + 1);
                    trim(key);
                    trim(value);
                    data[currentSection][key] = value;
                }
            }
        }
    }

    void toIni(const std::string &outFilename) const {
        std::ofstream out(outFilename);
        if (!out) {
            std::cerr << "Cannot write file: " << outFilename << std::endl;
            return;
        }

        for (const auto &sec: data) {
            out << "[" << sec.first << "]\n";
            for (const auto &kv: sec.second) {
                out << kv.first << " = " << kv.second << "\n";
            }
            out << "\n";
        }

        std::cout << "Written INI file: " << outFilename << std::endl;
    }

private:
    std::map<std::string, std::map<std::string, std::string> > data;

    static void trim(std::string &s) {
        auto notSpace = [](int ch) { return !std::isspace(ch); };
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), notSpace));
        s.erase(std::find_if(s.rbegin(), s.rend(), notSpace).base(), s.end());
    }
};

int main(const int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: cms2ini <input.cms> <output.ini>\n";
        return 1;
    }

    CmsParser parser;
    parser.parse(argv[1]);
    parser.toIni(argv[2]);

    return 0;
}
