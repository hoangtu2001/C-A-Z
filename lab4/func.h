#include <string>
#include <fstream>
void logStdout(const std::string& msg)
{
    std::cout<< msg;
}
void logToFile(const std::string& msg)
{
    std::ofstream file;
    file.open("log.txt", std::ios::app);

    file << msg;
    file.close();
}