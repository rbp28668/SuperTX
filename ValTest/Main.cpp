#include <iostream>
#include <string>
#include <sstream>
#include "..\Value.h"

int main(int argc,char* argv[])
{

  std::string str;

  int i=0;
  CValue val(0);

  std::cout << "integer" << std::endl;
  for(i=-8; i<=8; ++i)
    {
    val.Set(i);
    std::cout << i << "->" << val.ToString(str) << std::endl;
    }

  std::cout << "fraction" << std::endl;
  for(i=1;i<=5; ++i)
    {
    val.Set(1,i);
    std::cout << "1/" << i << "->" << val.ToString(str) << std::endl;
    }

  std::cout << "negative numerator" << std::endl;
  for(i=1;i<=5; ++i)
    {
    val.Set(-1,i);
    std::cout << "-1/" << i << "->" << val.ToString(str) << std::endl;
    }

  std::cout << "negative denominator" << std::endl;
  for(i=1;i<=5; ++i)
    {
    val.Set(1,-i);
    std::cout << "1/-" << i << "->" << val.ToString(str) << std::endl;
    }

  std::cout << "large fractions" << std::endl;
  for(i=-4096;i<=4096; i+=256)
    {
    val.Set(i,2048);
    std::cout << i << "/2048" << "->" << val.ToString(str) << std::endl;
    }

  std::cout << "string conversion (integers)" << std::endl;
  for(i=-8; i<=8; ++i)
    {
    std::ostringstream oss;
    oss << i;
    val.Set(oss.str());
    std::cout << oss.str() << "->" << val.ToString(str) << std::endl;
    }

  std::cout << "string conversion (real)" << std::endl;
  for(i=-8; i<=8; ++i)
    {
    std::ostringstream oss;
    if(i<0)
      oss << "-0." << -i;
    else
      oss << "0." << i;

    val.Set(oss.str());
    std::cout << oss.str() << "->" << val.ToString(str) << std::endl;
    }

  std::cout << "integer addition" << std::endl;
  for(i=-8; i<=8; ++i)
    {
    val.Set(i);
    for(int j=-4; j<=4; ++j)
      {
      CValue op(j);
      CValue result = val + op;

      std::cout  << result.ToString(str) << " ";
      }
    std::cout << std::endl;
    }

  std::cout << "fractional addition" << std::endl;
  for(i=-8; i<=8; ++i)
    {
    val.Set(1,i);
    for(int j=-4; j<=4; ++j)
      {
      CValue op(1,j);
      CValue result = val + op;

      std::cout  << result.ToString(str) << " ";
      }
    std::cout << std::endl;
    }

  std::cout << "integer subtraction" << std::endl;
  for(i=-8; i<=8; ++i)
    {
    val.Set(i);
    for(int j=-4; j<=4; ++j)
      {
      CValue op(j);
      CValue result = val - op;

      std::cout  << result.ToString(str) << " ";
      }
    std::cout << std::endl;
    }


  std::cout << "integer multiply" << std::endl;
  for(i=-8; i<=8; ++i)
    {
    val.Set(i);
    for(int j=-4; j<=4; ++j)
      {
      CValue op(j);
      CValue result = val * op;

      std::cout  << result.ToString(str) << " ";
      }
    std::cout << std::endl;
    }

  std::cout << "fractional multiply" << std::endl;
  for(i=-8; i<=8; ++i)
    {
    val.Set(1,i);
    for(int j=-4; j<=4; ++j)
      {
      CValue op(1,j);
      CValue result = val * op;

      std::cout  << result.ToString(str) << " ";
      }
    std::cout << std::endl;
    }

  return 0;

}
