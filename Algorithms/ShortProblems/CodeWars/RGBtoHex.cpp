/*
    https://www.codewars.com/kata/513e08acc600c94f01000001/cpp
    
    
    Convert 3 integer rgb values to 1 hexadecimal string
    in uppercase, 6 characters long, values rounded in to the range (0-255)
*/

#include <sstream>
#include <iomanip>

std::string decToHexStr(int dec)
{
  dec = std::min(255, std::max(0, dec)); // round
  
  std::stringstream ss;
  ss << std::hex << std::setfill('0') << std::setw(2) << std::uppercase << dec;
        
  return ss.str();
}

class RGBToHex
{
  public:
  
  static std::string rgb(int r, int g, int b)
  {
    return decToHexStr(r) + decToHexStr(g) + decToHexStr(b);
  }
};

/*
Reference:


#include <iomanip>
#include <sstream>

class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b)
  {
    std::stringstream outputStream;
    outputStream << std::uppercase << std::hex << std::setfill('0') << std::setw(2) << std::min(255, std::max(0, r))
                                               << std::setfill('0') << std::setw(2) << std::min(255, std::max(0, g))
                                               << std::setfill('0') << std::setw(2) << std::min(255, std::max(0, b));   
    return outputStream.str();
  }
};
*/
