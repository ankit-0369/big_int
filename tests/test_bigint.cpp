#include "bigint.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

int main() {
    const std::vector<std::pair<std::string, std::string>> good = {
        {"0", "0"}, {"-0", "0"}, {"+5", "5"}, {"000123", "123"}, {"-007", "-7"},
        {"999999999", "999999999"},
        {"1000000000", "1000000000"},                 // exactly one base
        {"1000000005", "1000000005"},                 // inner limb needs padding
        {"0000000000123", "123"},                     // a whole limb of zeros to trim
        {"-123456789012345678901", "-123456789012345678901"},
    };

    int failed = 0;
    for (const auto& [in, want] : good) {
        std::string got = BigInt(in).to_string();
        if (got != want) {
            ++failed;
            std::cout << "FAIL: \"" << in << "\" gave \"" << got << "\", wanted \"" << want << "\"\n";
        }
    }

    for (const char* bad : {"", "-", "+", "12a", " 5", "1-2"}) {
        try {
            BigInt tmp{std::string(bad)};
            (void)tmp;
            ++failed;
            std::cout << "FAIL: \"" << bad << "\" should have thrown\n";
        } catch (const std::invalid_argument&) {
        }
    }

    std::cout << (failed ? "FAILED\n" : "all passed\n");
    return failed != 0;
}