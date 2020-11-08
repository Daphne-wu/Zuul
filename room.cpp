#include "room.h"
#include <utility>
#include <cstring>


using namespace std;

// constructor for a room with no objects
Room::Room(char* description2, char* nameE) {
	name = new char[strlen(nameE)+1]; //add 1 to make up for the missing 0 value
	description = new char[strlen(description2)+1];
	strcpy(name, nameE);
	strcpy(description, description2);
}

// constructor for room with objects
Room::Room(char* description1, char* name1, char* item1) {
	name = new char[strlen(name1)+1];
	strcpy(name, name1);
	description = new char[strlen(description1)+1];
	strcpy(description, description1);
	Item* item = new Item();
	item->name = new char[strlen(item1)+1];
	strcpy(item->name, item1);
	items.push_back(item);
}

Room::~Room() {
	if (name != NULL) {
		delete name;
	}
	if (description != NULL) {
		delete description;
	}
	if (!items.empty()) {
		items.clear();
	}
}


char* Room::getName() {
  return name;
}

 // adds a direction and a room to an unordered map in c++
void Room::setExit(char* direction1, Room* room) {
  char* direction = new char[strlen(direction1)+1];
  strcpy(direction, direction1);
  exits.insert(make_pair(direction, room)); //use make_pair to insert into map
}

//moves the pointer to the room indicated by the direction chosen in the map
void Room::move(char* direction, Room* &room_ptr) {    //unordered_map<char*, Room*> exits -> unordered_map<key, value> exits -> unordered_map<first, second> exits
	bool done = false;
	for (auto& map : exits) {
		if(strcmp(map.first, direction) == 0) {
			room_ptr = map.second;
			done = true;
		}
	}
	if (done == false) {
		cout << "The direction you entered does not exist." << endl;
	}
}

// adds item from player inventory to the rooms item vector
bool Room::addItem(vector<Item*> &vect, char* item) {
	  for (vector<Item*>::iterator it = vect.begin(); it != vect.end(); it++) {
        if(strcmp((*it)->getName(), item) == 0) {
        	items.push_back(*it);
        	vect.erase(it);
        	return true;
        	break;
        }
    }
    return false;
}

// removes item from the rooms item vector and returns the item
Item* Room::removeItem(char* item) {
	for (vector<Item*>::iterator it = (items).begin(); it != (items).end(); ++it) {
		if (strcmp((*it)->getName(), item) == 0) {
			Item* ptr = *it;
			items.erase(it);
			return ptr;
			break;
		}
	}
	return NULL;
}

