#include <cstdlib>
#include "server.h"
#include "system.h"
#include "command.h"

using namespace std;

#define ACCEPT_REGISTRATION "accept_registratio"
#define REJECT_REGISTRATION "reject_registration"
#define SHOW_REGISTRATION_REQUESTS "show_registration_requests"
#define SET_TIME "set_time"
#define PASSENGER_REPORT "passenger_report"
#define SYSTEM_REPORT "system_report"
#define LOGOUT "logout"
#define LOGIN "login"


class MyServer : public Server
{
public:
    MyServer(int port , System* sys) : Server(port) , system(sys) { login = false;}
    void on_standard_input(string line);
    void on_new_connection(int identifier);
    void on_new_message(int identifier, string message);
    void on_terminated_connection(int identifier);
    string establish_command(string command);
    bool check_validation();

private:
    System* system;
    bool login;
    string key;
    vector<string> arguments;
};

string MyServer::establish_command(string command)
{
    arguments.clear();
    string temp;
    vector <string> all_arguments;
    stringstream s (command);
    while(s>> temp)
        all_arguments.push_back(temp);
    key = all_arguments[0];
    temp = "";
    all_arguments.erase(all_arguments.begin());
    for(int i=0 ; i<all_arguments.size() ; i++)
        arguments.push_back(all_arguments[i]);
    if( key == LOGIN)
        temp +=("admin " + key + " " +arguments[1]);
    else 
    {
        temp += ("admin "+ key);
        for ( int i = 0 ; i < arguments.size() ; i++)
            temp += (" " + arguments[i]);
    }
    return temp;

}

bool MyServer::check_validation()
{
    if( key == LOGIN && arguments.size() ==2)
        return true;
    else if(key == LOGOUT && arguments.size() == 0)
        return true;
    else if( key == ACCEPT_REGISTRATION && arguments.size()==1)
        return true;
    else if( key == REJECT_REGISTRATION && arguments.size()==1)
        return true;
    else if ( key == SHOW_REGISTRATION_REQUESTS && arguments.size() == 0)
        return true;
    else if ( key == SET_TIME && arguments.size() == 1)
        return true;
    else if( key == PASSENGER_REPORT && arguments.size() == 1)
        return true;
    else if ( key == SYSTEM_REPORT && arguments.size() == 0)
        return true;
    return false;
}

void MyServer::on_standard_input(string line)
{
    string command = establish_command(line);
    if(check_validation())
    {
        string response;
        Command_Line_Interface cmd(command);
        response = cmd.run(system);
        if(key == LOGIN && response == "")
            login = true;
        if(key == LOGOUT)
            login = false;
        cout << response;
    }
    else
    {
        cout << "Wrong Command"<<endl;
    }


}

void MyServer::on_new_connection(int identifier) 
{
  cout << "NEW CONNECTION: " << identifier << endl;
}

void MyServer::on_new_message(int identifier, string message) 
{
    string response;
    Command_Line_Interface cmd(message);
    response = cmd.run(system);
    send(identifier, response);
}

void MyServer::on_terminated_connection(int identifier) 
{
  cout << "TERMINATED CONNECTION: " << identifier << endl;
}


int main(int argc, char* argv[])
{
    if (argc != 2) 
    {
        cerr << "valid operation: " << argv[0] << " [port number]\n";
        exit(-1);
    }

    System sys;
    MyServer server(Tools::mystoi(argv[1]) , &sys);
    server.run();
    return 0;
}