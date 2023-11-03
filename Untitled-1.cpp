#include <iostream>
#include <sstream>
#include <cassert>

void runUnitTests();

void runUnitTest(int t, std::string expectedOutput)
{
    std::stringstream input;
    input << t << "\n";
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char x = '2';
            input << x << " ";
        }
        input << "\n";
    }

    std::stringstream output;
    std::streambuf *originalOutput = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    std::streambuf *originalInput = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    runUnitTests();

    std::cout.rdbuf(originalOutput);
    std::cin.rdbuf(originalInput);

    std::string actualOutput = output.str();
    actualOutput.pop_back(); // Remove last newline character

    assert(actualOutput == expectedOutput);
}

void runUnitTests()
{
    runUnitTest(1, "111111111\n");
    runUnitTest(3, "111111111\n111111111\n111111111\n");
    runUnitTest(1, "1\n");
    runUnitTest(1, "2\n");
    runUnitTest(1, "3\n");
}

int main()
{
    runUnitTests();

    return 0;
}
