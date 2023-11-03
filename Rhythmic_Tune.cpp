#include <iostream>
#include <regex>
#include <string>
using namespace std;

// Function to manually escape special characters in a regex pattern
string regex_escape(const string &s)
{
    string escaped;
    for (char c : s)
    {
        if (c == '.' || c == '[' || c == ']' || c == '(' || c == ')' || c == '|' || c == '*' || c == '+' || c == '?' || c == '{' || c == '}' || c == '\\' || c == '^' || c == '$')
        {
            escaped += '\\';
        }
        escaped += c;
    }
    return escaped;
}

int maxConsecutiveOccurrences(const string &substring, const string &str)
{
    regex pattern("(" + regex_escape(substring) + ")+");
    sregex_iterator it(str.begin(), str.end(), pattern);
    sregex_iterator end;
    int maxOccurrences = 0;
    while (it != end)
    {
        int length = it->length();
        int occurrences = length / substring.length();
        if (occurrences > maxOccurrences)
        {
            maxOccurrences = occurrences;
        }
        ++it;
    }
    return maxOccurrences;
}

vector<string> regexMatch(const string &inputString)
{
    regex pattern("(.+)\\1+");
    sregex_iterator it(inputString.begin(), inputString.end(), pattern);
    sregex_iterator end;
    vector<string> matches;
    while (it != end)
    {
        matches.push_back(it->str());
        ++it;
    }
    return matches;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; ++i)
    {
        string inputString;
        getline(cin, inputString);

        vector<string> matches = regexMatch(inputString);
        int ans = 0;

        for (const string &match : matches)
        {
            int lst = maxConsecutiveOccurrences(match, inputString);
            ans = max(ans, lst * static_cast<int>(match.length()));
        }

        cout << ans << endl;
    }

    return 0;
}
