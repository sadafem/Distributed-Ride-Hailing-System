#include "driver_client.h"

using namespace std;

#define LOGIN "login"
#define SET_STATUS "set_status"
#define REGISTER "register"
#define LOGOUT "logout"
#define SHOW_TRIP_REQUESTS "show_trip_requests"
#define ACCEPT_TRIP_REQUEST "accept_trip_request"
#define ARRIVED "arrived"
#define END_TRIP "end_trip"

driver_client::driver_client(string argv1 , int argv2)
{
    socket = new ClientSocket(argv1,argv2);
    cout << "# connection established\n";
    username = "";
}

driver_client::~driver_client()
{
    delete socket;
}

void driver_client::establish_command(string command)
{
    arguments.clear();
    string temp;
    vector <string> all_arguments;
    stringstream s (command);
    while(s>> temp)
        all_arguments.push_back(temp);
    key = all_arguments[0];

    all_arguments.erase(all_arguments.begin());
    for(int i=0 ; i<all_arguments.size() ; i++)
        arguments.push_back(all_arguments[i]);
}

string driver_client::run(string command)
{
    establish_command(command);
    if(key == REGISTER && (arguments.size() == 7 || arguments.size() == 6) && !login)
    {
        command = "";
        command += (arguments [0] + " " + key + "_driver");
        for(int i = 1 ; i < arguments.size() ; i ++)
            command +=(" " + arguments[i]);
        socket->send(command);
    }
    else if(key == LOGIN && !login && arguments.size()==2)
    {
        username = arguments[0];
        login = true;
        command = "";
        command += (arguments[0] + " " + key + " " + arguments[1]);
        socket -> send(command);
    }
    else if(key == SET_STATUS && (arguments.size()==1 || arguments.size()==2))
    {
        if(!login)
            cout << "Login First"<<endl;
        command = "";
        command += (username + " " +key);
        for(int i = 0 ; i < arguments.size() ; i ++)
            command +=(" " + arguments[i]);
        socket -> send(command);
    }
    else if ( key == LOGOUT && login && arguments.size()==0)
    {
        login = false;
        command = "";
        command += (username + " " + key);
        username = "";
        socket -> send(command);
    }
    else if(key == SHOW_TRIP_REQUESTS && arguments.size()==0 )
    {
        if(!login)
            cout << "Login First"<<endl;
        command = "";
        command += (username + " " + key);
        for(int i = 0 ; i < arguments.size() ; i ++)
            command +=(" " + arguments[i]);
        socket-> send(command);
    }
    else if( key == ACCEPT_TRIP_REQUEST && arguments.size()==1)
    {        
        if(!login)
            cout << "Login First"<<endl;
        command = "";
        command += (username + " " + key);
        for(int i = 0 ; i < arguments.size() ; i ++)
            command +=(" " + arguments[i]);
        socket-> send(command);
    }
    else if( key == ARRIVED && arguments.size() == 0)
    {
        if(!login)
            cout << "Login First"<<endl;
        command = "";
        command += (username + " " + key);
        socket-> send(command);
    }
    else if( key == END_TRIP && arguments.size() == 0)
    {
        if(!login)
            cout << "Login First"<<endl;
        command = "";
        command += (username + " " + key);
        socket-> send(command);
    }
    else
    {
        cout << "Wrong Command"<<endl;
    }
    string response = socket -> receive();
    if(response == "Incorrect Password\n" || response == "Incorrect Username\n" || response == "Pending registration\n")
    {
        username = "";
        login = false;
    }
    return response;
}
