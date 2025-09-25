all: server

server: main.o server_socket.o server.o tools.o spaceship.o time.o user.o trip.o system.o command.o universe.o
	g++ main.o server_socket.o server.o tools.o spaceship.o time.o user.o trip.o system.o command.o universe.o -o server

server.o: server.cpp server.h system.h command.h
	g++ -c server.cpp
	
server_socket.o: server_socket.cpp server_socket.h tools.h network_exception.h
	g++ -c server_socket.cpp
	
tools.o: tools.cpp tools.h
	g++ -c tools.cpp
spaceship.o: spaceship.h spaceship.cpp
	g++ -c spaceship.cpp
time.o: time.cpp time.h
	g++ -c time.cpp
user.o: user.h user.cpp spaceship.h system.h trip.h
	g++ -c user.cpp
trip.o: trip.h trip.cpp user.h time.h
	g++ -c trip.cpp
system.o: system.h system.cpp user.h universe.h time.h
	g++ -c system.cpp
command.o: command.h command.cpp system.h
	g++ -c command.cpp
exeptions.o: exeptions.h
universe.o: universe.h universe.cpp exeptions.h
	g++ -c universe.cpp
clean:
	rm *.o server