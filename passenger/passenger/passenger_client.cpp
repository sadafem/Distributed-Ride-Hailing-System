#include "passenger_client.h"


#define LOGIN "login"
#define GET_DISCOUNT_CODE "get_discount_code"
#define REGISTER "register"
#define LOGOUT "logout"
#define ESTIMATE_TRIP "estimate_trip"
#define REQUEST_TRIP "request_trip"
#define CANCEL_TRIP_REQUEST "cancel_trip_request"
#define TRIP_STATUS "trip_status"
#define RATE_DRIVER "rate_driver"
#define CHARGE_ACCOUNT "charge_account"
#define GET_CREDIT "get_credit"

using namespace std;

passenger_client::passenger_client(string argv1 , int argv2)
{
    socket = new ClientSocket(argv1,argv2);
    cout << "# connection established\n";
    username = "";
}

passenger_client::~passenger_client()
{
    delete socket;
}

void passenger_client::establish_command(string command)
{
    arguments.clear();
    string temp;
    vector <string> all_arguments;
    stringstream s (command);
    while(s>> temp)
        all_arguments.push_back(temp);
    key = all_arguments[0];

    all_arguments.erase(all_arguments.begin());
    for(unsigned int i=0 ; i<all_arguments.size() ; i++)
        arguments.push_back(all_arguments[i]);
}

string passenger_client::run(string command)
{
    establish_command(command);
    if(key == REGISTER && username =="" && (arguments.size() == 3 || arguments.size()==4))
    {
        command = "";
        if(arguments.size()==3)
            command += (arguments [0] + " " + key + "_passenger " + arguments[1]+ " " + arguments[2]);
        else
            command += (arguments [0] + " " + key + "_passenger " + arguments[1]+ " " + arguments[2]+ " " + arguments[3]);
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
    else if(key == GET_DISCOUNT_CODE && arguments.size()==0)
    {
        if(!login)
            cout << "Login First"<<endl;
        command = "";
        command += (username + " " +key);
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
    else if(key == ESTIMATE_TRIP)
    {
        if(!login)
            cout << "Login First"<<endl;
        command = "";
        command += (username + " " + key);
        for(unsigned int i = 0 ; i < arguments.size() ; i ++)
            command +=(" " + arguments[i]);
        socket-> send(command);
    }
    else if( key == REQUEST_TRIP)
    {        
        if(!login)
            cout << "Login First"<<endl;
        command = "";
        command += (username + " " + key);
        for(unsigned int i = 0 ; i < arguments.size() ; i ++)
            command +=(" " + arguments[i]);
        socket-> send(command);
    }
    else if( key == CANCEL_TRIP_REQUEST && arguments.size() == 0)
    {
        if(!login)
            cout << "Login First"<<endl;
        command = "";
        command += (username + " " + key);
        socket-> send(command);
    }
    else if( key == TRIP_STATUS && arguments.size() == 0)
    {
        if(!login)
            cout << "Login First"<<endl;
        command = "";
        command += (username + " " + key);
        socket-> send(command);
    }
    else if( key == RATE_DRIVER && arguments.size()==1)
    {
        if(!login)
            cout << "Login First"<<endl;
        command = "";
        command += (username + " " + key + " " + arguments[0]);
        socket-> send(command);
    }
    else if( key == CHARGE_ACCOUNT && arguments.size() == 1)
    {
        if(!login)
            cout << "Login First"<<endl;
        command = "";
        command += (username + " " + key + " " + arguments[0]);
        socket-> send(command);
    }
    else if( key == GET_CREDIT && arguments.size()==0)
    {
        if(!login)
            cout << "Login First"<<endl;
        command = "";
        command += (username + " " +key);
        socket->send(command);
    }
    else
    {
        cout << "Wrong Command"<<endl;
    }
    string response = socket -> receive();
    if(response == "Incorrect Password\n" || response == "Incorrect Username\n")
    {
        username ="";
        login = false;
    }
    return response;
}
