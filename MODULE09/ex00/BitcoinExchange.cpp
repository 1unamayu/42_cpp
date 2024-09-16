
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
  if(fecha.length() != 10)
    return false;

  if(fecha[4] != '-' || fecha[7] != '-')
    return false;

  for(int i = 0; i < 10; i++)
  {
    if(i == 4 || i == 7)
      continue;
    if(!std::isdigit(fecha[i]))
      return false;
  }

  int anio = std::atoi(fecha.substr(0, 4).c_str());
  int mes = std::atoi(fecha.substr(5, 2).c_str());
  int dia = std::atoi(fecha.substr(8, 2).c_str());

  if(anio < 1 || mes < 1 || mes > 12 || dia < 1 || dia > 31)
    return false;

  if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
    return false;

  if(mes == 2)
  {
    bool esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
    if(dia > 29 || (dia == 29 && !esBisiesto))
      return false;
  }

  return true;
}

bool BitcoinExchange::loadData(std::string const &csvFile)
{
  std::ifstream archivo(csvFile.c_str());
  if(!archivo.is_open())
  {
    std::cerr << "Error: no se pudo abrir el archivo " << csvFile << std::endl;
    return false;
  }

  std::string linea;
  std::getline(archivo, linea); // Ignorar la primera línea (encabezados)

  while(std::getline(archivo, linea))
  {
    std::istringstream iss(linea);
    std::string fecha;
    float valor;

    if(std::getline(iss, fecha, ',') && iss >> valor)
    {
      if(!isValideDate(fecha))
      {
        std::cerr << "Error: invalid date found in the database =>" << fecha
                  << std::endl;
        return false;
      }
      _data[fecha] = valor;
    }
    else
    {
      std::cerr << "Error: bad input => " << linea << std::endl;
      return false;
    }
  }

  archivo.close();
  std::cout << "\033[32mData loaded successfully\033[0m" << std::endl;

  return true;
}

bool BitcoinExchange::readInput(std::string const &inputFile)
{
  std::ifstream archivo(inputFile.c_str());
  if(!archivo.is_open())
  {
    std::cerr << "Error: no se pudo abrir el archivo " << inputFile
              << std::endl;
    return false;
  }
  std::string linea;
  std::getline(archivo, linea); // Ignorar la primera línea (encabezados)

  while(std::getline(archivo, linea))
  {
    std::istringstream iss(linea);
    std::string fecha;
    float valor;
    // Ignorar la primera línea
    if(linea.find("date | value") != std::string::npos)
    {
      continue;
    }
    if(std::getline(iss, fecha, '|') && iss >> valor)
    {
      // Eliminar espacios en blanco al inicio y final de la fecha
      fecha.erase(0, fecha.find_first_not_of(" \t"));
      fecha.erase(fecha.find_last_not_of(" \t") + 1);

      if(!isValideDate(fecha))
      {
        std::cerr << "\033[31m" << fecha << " ==> " << valor << " [Error: bad date => " << fecha << "]" << "\033[0m" << std::endl;
        continue;
      }

      if(valor < 0)
      {
        std::cerr << "\033[31m" << fecha << " ==> " << valor << " [Error: not a positive number.]" << "\033[0m" << std::endl;
        continue;
      }

      if(valor > 1000)
      {
        std::cerr << "\033[31m" << fecha << " ==> " << valor << " [Error: too large a number.]" << "\033[0m" << std::endl;
        continue;
      }

      _input[fecha] = valor;
      std::string fecha_valida = findDate(fecha);
      std::cout << fecha << "[" << fecha_valida << "]" << "==>" << valor << "=" << _data[fecha_valida] * valor << std::endl;
    }
    else
    {
      std::cerr << "\033[31m" << linea << " [Error: bad input => " << linea << "]" << "\033[0m" << std::endl;
    }
  }

  archivo.close();

  return true;
}
std::string BitcoinExchange::findDate(const std::string &fecha)
{
  std::map<std::string, float>::iterator it = _data.lower_bound(fecha);

  if(it == _data.begin())
  {
    return it->first;
  }
  else if(it == _data.end() || it->first != fecha)
  {
    --it;
  }

  return it->first;
}


