#ifndef _TOOLS_H
#define _TOOLS_H

#include <string>
#include <sstream>
#include <vector>
#include <QMainWindow>

#define LEFT 1
#define RIGHT 2


class Tools {
public:
  static std::string decorate_text(std::string phrase, int length, int paddingside);
  static std::string itos(int number);
  static int mystoi(std::string number);
  static std::string qstos(QString qs);
  static QString stoqs(std::string s);
  std::vector<std::string> split(std::string statement, char delimeter);
private:
  Tools();
};

#endif
