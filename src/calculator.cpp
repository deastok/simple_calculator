

#include "calculator.hpp"



void run() {
    std::string input;
    double x, y;
    char op;

    std::cout << "Calculator (q=quit, help, clear)\n";

    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, input);

        if (input == "q" || input == "quit") {
            std::cout << "Goodbye!\n";
            break;
        }

        if (input == "help") {
            std::cout << "Commands:\n"
                      << "  q or quit -> exit\n"
                      << "  help      -> show this\n"
                      << "  clear     -> clear screen\n"
                      << "  Math: 5 + 3, 10.5 * 2, etc.\n";
            continue;
        }

        if (input == "clear") {
            system(
        #ifdef _WIN32
                "cls"
        #else
                "clear"
        #endif
            );
            continue;
        }

        if (input.empty()) continue;

        std::stringstream ss(input);
        if (!(ss >> x >> op >> y)) {
            std::cout << "Invalid input. Usage: 'num op num'\n";
            continue;
        }

        std::string junk;
        if (ss >> junk) {
            std::cout << "Warning: Extra input ignored: '" << junk << "'\n";
        }

        double result = calculate(x, op, y);
        if (!std::isnan(result)) {
            std::cout << result << "\n";
        }
    }
}