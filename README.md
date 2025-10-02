# 🚀 Distributed Space Transportation System

A comprehensive distributed ride-hailing platform built with C++ and Qt, simulating a space transportation network across multiple galaxies and planets.

## 🌟 Features

- **Multi-Client Architecture**: Separate passenger and driver GUI applications
- **Real-time Communication**: Socket-based client-server architecture
- **Space Theme**: Star Wars-inspired spaceship fleet management
- **User Management**: Passenger registration, driver approval system
- **Trip Management**: Complete trip lifecycle from request to completion
- **VIP System**: Special handling for VIP passengers
- **Rating System**: Driver feedback and evaluation
- **Admin Dashboard**: System management and reporting

## 🛠️ Technology Stack

- **Backend**: C++ with custom socket implementation
- **Frontend**: Qt 5.15+ for cross-platform GUI
- **Architecture**: Client-Server with real-time communication
- **Build System**: Makefile for server, Qt project files for clients


## 🌌 System Overview

The system operates across multiple galaxies with defined topology, featuring various Star Wars-themed vehicles for transportation. Users can register as passengers or drivers, with drivers requiring admin approval to become active.


## 📁 Project Structure

```text
├── server/               # Central server application
│   ├── topology.cfg      # Galaxy/planet configuration
│   └── vehicles.cfg      # Available spaceship models
├── passenger/            # Passenger GUI client
└── driver/               # Driver GUI client
```



## 🎯 Key Components

- **Server**: Handles user authentication, trip management, and system administration
- **Passenger Client**: Trip requests, account management, driver rating
- **Driver Client**: Trip acceptance, status management, spaceship handling
- **Configuration**: Galaxy topology and vehicle fleet management
