#include <algorithm>
#include <memory>
#include <vector>
#include <filesystem>

#include "utils.hpp"

std::string SanitizedString(std::string s) {
    // Remove leading spaces
    while (s.size() > 0 && s[0] == ' ') {
        s.erase(0, 1);
    }

    // Replace line breaks with spaces
    std::replace(s.begin(), s.end(), '\n', ' ');

    // Remove consecutive spaces
    while (s.find("  ") != std::string::npos) {
        s.erase(s.find("  "), 1);
    }

    return s;
}

using FILEPtr = std::unique_ptr<FILE, decltype(&std::fclose)>;

bool CopyFile(const char* dst, const char* src) {
    try {
        std::filesystem::copy_file(src, dst, std::filesystem::copy_options::overwrite_existing);
        return true;
    } catch (...) { return false; }
}
