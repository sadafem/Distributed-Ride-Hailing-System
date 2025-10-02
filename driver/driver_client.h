#ifndef _DRIVER_
#define _DRIVER_

#include "client_socket.h"
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

class driver_client
{
public:
      driver_client(string argv1 , int argv2);
      ~driver_client();
      void establish_command(string command);
      string run(string command);

private:
      ClientSocket* socket;
      string username;
      string key;
      bool login;
      vector<string> arguments;
};

#endif