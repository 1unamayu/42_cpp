#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
  std::cout << KBLA << "Bitcoin Exchange initialized" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
}
bool BitcoinExchange::isValideDate(const std::string &fecha)
{
  // Check basic format
  if (fecha.length() != 10 || fecha[4] != '-' || fecha[7] != '-')
    return false;

  // Check if all characters except separators are digits
  for (int i = 0; i < 10; i++)
  {
    if (i == 4 || i == 7)
      continue;
    if (!std::isdigit(fecha[i]))
      return false;
  }

  // Parse date components
  int anio = std::atoi(fecha.substr(0, 4).c_str());
  int mes = std::atoi(fecha.substr(5, 2).c_str());
  int dia = std::atoi(fecha.substr(8, 2).c_str());

  // Basic range checks
  if (anio < 2009 || anio > 2024 || mes < 1 || mes > 12 || dia < 1 || dia > 31)
    return false;

  // Check days per month
  static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int maxDays = daysInMonth[mes];

  // Handle leap years
  if (mes == 2)
  {
    bool esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
    maxDays = esBisiesto ? 29 : 28;
  }

  return dia <= maxDays;
}

bool BitcoinExchange::loadData(std::string const &csvFile)
{
  std::ifstream archivo(csvFile.c_str());
  if (!archivo.is_open())
  {
    std::cerr << "Error: could not open file " << csvFile << std::endl;
    return false;
  }

  std::string linea;
  std::getline(archivo, linea); // Skip header

  if (linea != "date,exchange_rate")
  {
    std::cerr << "Error: invalid CSV format. Expected header: date,exchange_rate" << std::endl;
    return false;
  }

  while (std::getline(archivo, linea))
  {
    std::istringstream iss(linea);
    std::string fecha;
    float valor;

    if (!std::getline(iss, fecha, ',') || !(iss >> valor))
    {
      std::cerr << "Error: bad input => " << linea << std::endl;
      return false;
    }

    if (!isValideDate(fecha))
    {
      std::cerr << "Error: invalid date in database => " << fecha << std::endl;
      return false;
    }

    if (valor < 0)
    {
      std::cerr << "Error: negative exchange rate found => " << valor << std::endl;
      return false;
    }

    _data[fecha] = valor;
  }

  if (_data.empty())
  {
    std::cerr << "Error: no valid data found in database" << std::endl;
    return false;
  }

  std::cout << "\033[32mDatabase loaded successfully with " << _data.size() << " entries\033[0m" << std::endl;
  return true;
}

bool BitcoinExchange::readInput(std::string const &inputFile)
{
  std::ifstream archivo(inputFile.c_str());
  if (!archivo.is_open())
  {
    std::cerr << "Error: could not open file " << inputFile << std::endl;
    return false;
  }

  std::string linea;
  std::getline(archivo, linea); // Skip header

  if (linea != "date | value")
  {
    std::cerr << "Error: invalid input format. Expected header: date | value" << std::endl;
    return false;
  }

  while (std::getline(archivo, linea))
  {
    std::istringstream iss(linea);
    std::string fecha;
    float valor;

    if (linea.empty())
      continue;

    if (!std::getline(iss, fecha, '|') || !(iss >> valor))
    {
      std::cerr << "Error: bad input => " << linea << std::endl;
      continue;
    }

    // Trim whitespace from fecha
    fecha.erase(0, fecha.find_first_not_of(" \t"));
    fecha.erase(fecha.find_last_not_of(" \t") + 1);

    if (!isValideDate(fecha))
    {
      std::cerr << "Error: bad input => " << fecha << std::endl;
      continue;
    }

    if (valor < 0)
    {
      std::cerr << "Error: not a positive number." << std::endl;
      continue;
    }

    if (valor > 1000)
    {
      std::cerr << "Error: too large a number." << std::endl;
      continue;
    }

    std::string fecha_valida = findDate(fecha);
    float exchange_rate = _data[fecha_valida];
    float result = exchange_rate * valor;

    std::cout << fecha << " => " << valor << " = " << result << std::endl;
  }

  return true;
}
std::string BitcoinExchange::findDate(const std::string &fecha)
{
  std::map<std::string, float>::iterator it = _data.lower_bound(fecha);

  // If the date is before the first entry or after the last entry
  if (it == _data.begin())
    return it->first;
  if (it == _data.end())
    return (--it)->first;

  // If exact date found
  if (it->first == fecha)
    return it->first;

  // Get the previous date (closest available)
  --it;
  return it->first;
}


