#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

// ANSI color codes for output
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KBLU "\x1B[34m"
#define KNRM "\x1B[0m"

/**
 * @brief Bitcoin Exchange Rate Calculator
 * 
 * This class handles the loading and processing of Bitcoin exchange rates
 * from a CSV database and calculates exchange rates for given dates and values.
 */
class BitcoinExchange
{
private:
  std::map<std::string, float> _data;  // Database of exchange rates
  std::map<std::string, float> _input; // Input values to process

  /**
   * @brief Validates a date string in YYYY-MM-DD format
   * @param fecha Date string to validate
   * @return true if date is valid, false otherwise
   */
  bool isValideDate(const std::string &fecha);

public:
  BitcoinExchange();
  ~BitcoinExchange();

  /**
   * @brief Loads exchange rate data from a CSV file
   * @param csvFile Path to the CSV file
   * @return true if successful, false otherwise
   */
  bool loadData(std::string const &csvFile);

  /**
   * @brief Processes input file and calculates exchange rates
   * @param inputFile Path to the input file
   * @return true if successful, false otherwise
   */
  bool readInput(std::string const &inputFile);

  /**
   * @brief Finds the closest available date in the database
   * @param fecha Date to find
   * @return The closest available date
   */
  std::string findDate(const std::string &fecha);
};

#endif