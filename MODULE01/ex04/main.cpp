#include <cstring>
#include <fstream>
#include <iostream>
// COLORS
#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
#define KBLA "\033[0;30m"

static int showError(std::string error);
static std::string modifyString(std::string &s, std::string &s1, std::string &s2);
bool replaceStringInFile(const char *filename, const char *s1, const char *s2);
/**
 * @brief Main function of the program.
 *
 * This function serves as the entry point of the program. It takes command line arguments
 * and performs file operations to replace a specified string with another string in a file.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of C-style strings containing the command-line arguments.
 * @return Returns 0 upon successful execution, or 1 if an error occurs.
 */
int main(int argc, char *argv[])
{
  if(argc != 4)
    return (showError("Wrong number of arguments!"));

  if(strlen(argv[2]) == 0 || strlen(argv[3]) == 0)
    return (showError("Error!. Zero length argument detected!"));

  std::cout << KYEL "             Filename: " KNRM << argv[1] << std::endl;
  std::cout << KYEL "String to be replaced: " KNRM << argv[2] << std::endl;
  std::cout << KYEL "           New string: " KNRM << argv[3] << std::endl;
  std::ifstream file(argv[1]);
  if(!file.is_open())
  {
    return (showError("Error!. Cannot open file for reading!"));
  }

  if(!replaceStringInFile(argv[1], argv[2], argv[3]))
    return 1;
  std::cout << KBLU << argv[1] << ".replace" KNRM << " has been created!" << std::endl;
  return 0;
}

/**
 * @brief Replaces a specified string with another string in a file.
 *
 * This function takes a filename and two strings as input, reads the file line by line,
 * and replaces occurrences of the first string with the second string.
 *
 * @param filename The name of the file to perform the string replacement.
 * @param s1 The string to be replaced.
 * @param s2 The string to replace with.
 * @return Returns true if the string replacement is successful, false otherwise.
 */
bool replaceStringInFile(const char *filename, const char *s1, const char *s2)
{
  std::ifstream inputFile(filename);
  std::string outputFilename = std::string(filename) + ".replace";
  std::ofstream outputFile(outputFilename.c_str());

  if(!outputFile.is_open())
  {
    std::cerr << "Error: Unable to create output file." << std::endl;
    inputFile.close();
    return false;
  }
  std::string s11 = s1;
  std::string s22 = s2;
  std::string line;
  while(std::getline(inputFile, line))
  {
    outputFile << modifyString(line, s11, s22) << std::endl;
  }

  inputFile.close();
  outputFile.close();

  return true;
}
/**
 * @brief Modifies a string by replacing occurrences of a specified substring.
 *
 * This function takes a string and two substrings as input, and replaces occurrences
 * of the first substring with the second substring.
 *
 * @param s The string to be modified.
 * @param s1 The substring to be replaced.
 * @param s2 The substring to replace with.
 * @return Returns the modified string.
 */
static std::string modifyString(std::string &s, std::string &s1, std::string &s2)
{

  std::string ans = "";

  for(int i = 0; i < (int)s.length(); i++)
  {

    int k = 0;

    if(s[i] == s1[k] && i + s1.length() <= s.length())
    {

      int j;
      for(j = i; j < i + (int)s1.length(); j++)
      {
        if(s[j] != s1[k])
        {
          break;
        }
        else
        {
          k = k + 1;
        }
      }
      if(j == i + (int)s1.length())
      {
        ans.append(s2);
        i = j - 1;
      }
      else
      {
        ans.push_back(s[i]);
      }
    }
    else
    {
      ans.push_back(s[i]);
    }
  }
  return ans;
}
/**
 * @brief Displays an error message.
 *
 * This function prints an error message to the standard error stream.
 *
 * @param error The error message to be displayed.
 * @return Returns 1 to indicate an error.
 */
static int showError(std::string error)
{
  std::cerr << KRED << error << std::endl;
  return 1;
}
