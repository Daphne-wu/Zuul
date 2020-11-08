#ifndef room_H
#define room_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>


using namespace std;
//struct of items
struct Item {
  char* name;
  char* getName() {
    return name;
  }
};


///room class
class Room {
  
public:
  //functions
  Room(char* description, char* name, char* item);
  Room(char* description,  char* name);
  ~Room();
  Item* removeItem(char* item);
  void setExit(char* direction, Room* room);
  virtual void move(char* direction, Room* &ptr);
  bool addItem(vector<Item*> &vect, char* item);
  char* getName();
//variables
  char* description;
  char*name;
  vector<Item*> items;
  unordered_map<char*, Room*> exits;
};

#endif