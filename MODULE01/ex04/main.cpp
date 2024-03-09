#include <cstring>
#include <fstream>
#include <iostream>
// Color codes for console output
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


bool replaceStringInFile(const char *filename, const char *s1, const char *s2)
{
  // Open the input file
  std::ifstream inputFile(filename);
  // Open the output file
  std::string outputFilename = std::string(filename) + ".replace";
  std::ofstream outputFile(outputFilename.c_str());

  if(!outputFile.is_open())
  {
    std::cerr << "Error: Unable to create output file." << std::endl;
    inputFile.close(); // Close the input file
    return false;
  }
  std::string s11 = s1;
  std::string s22 = s2;
  // Copy content while replacing s1 with s2
  std::string line;
  while(std::getline(inputFile, line))
  {
    outputFile << modifyString(line, s11, s22) << std::endl;
  }

  // Close files
  inputFile.close();
  outputFile.close();

  return true;
}
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

static std::string modifyString(std::string &s, std::string &s1, std::string &s2)
{
  // Stores the resultant string
  std::string ans = "";

  // Traverse the string s
  for(int i = 0; i < (int)s.length(); i++)
  {

    int k = 0;

    // If the first character of
    // string s1 matches with the
    // current character in string s
    if(s[i] == s1[k] && i + s1.length() <= s.length())
    {

      int j;

      // If the complete string
      // matches or not
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

      // If complete string matches
      // then replace it with the
      // string s2
      if(j == i + (int)s1.length())
      {
        ans.append(s2);
        i = j - 1;
      }

      // Otherwise
      else
      {
        ans.push_back(s[i]);
      }
    }

    // Otherwise
    else
    {
      ans.push_back(s[i]);
    }
  }

  // Print the resultant string
  return ans;
}
static int showError(std::string error)
{
  std::cerr << KRED << error << std::endl;
  return 1;
}