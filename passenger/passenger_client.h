#ifndef _PASSENGER_
#define _PASSENGER_

#include "client_socket.h"
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

class passenger_client
{
public:
      passenger_client(string argv1 , int argv2);
      ~passenger_client();
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
