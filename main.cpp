//Your late to cPlusPlus! Gather your things and find your way to room 1-20 
#include "room.h"
#include <utility>
#include <cstring>


using namespace std;

//global variable and function prototypes
vector<Room*> vect;
vector<Item*> playerInventory;
void showExits(Room* room_ptr);
void showItems(vector<Item*> vect);
void roomInfo(Room* room_ptr);
bool checkItems(Room* room_ptr);

int main() {
	char description[300];
	char name[20];
	char item[20];
	//create rooms and set their items
	strcpy(description, "Mr. Hall is conducting the band!");
	strcpy(name, "Band Room");
	strcpy(item, "Flute");
	Room* band = new Room(description, name, item);
	vect.push_back(band);
	//begin at band room, current_ptr keeps track of where u are
	Room* current_ptr = band;

	strcpy(description, "The play just beginning!");
	strcpy(name, "Auditorium");
	Room* auditorium = new Room(description, name, item);
	vect.push_back(auditorium);
	strcpy(description, "There has been an explosion! Oh no!");
	strcpy(name, "Chem lab");
	strcpy(item, "Beaker");
	Room* chemLab = new Room(description, name, item);
	vect.push_back(chemLab);
	strcpy(description, "All the students are deep into their books!");
	strcpy(name, "Lit Class");
	strcpy(item, "Hamlet");
	Room* lit = new Room(description, name, item);
	vect.push_back(lit);
	strcpy(description, "Oh no, there is a calculus test, better run!");
	strcpy(name, "Calc Class");
	strcpy(item, "Test");
	Room* calc = new Room(description, name, item);
	vect.push_back(calc);
	strcpy(description, "It started raining!");
	strcpy(name, "Tennis Court");
	strcpy(item, "Racquet");
	Room* tennis = new Room(description, name, item);
	vect.push_back(tennis);
	strcpy(description, "Dodge! It's Dodgball!");
	strcpy(name, "Gym");
	strcpy(item, "Ball");
	Room* gym = new Room(description, name, item);
	vect.push_back(gym);
	strcpy(description, "Ahh the smell of food.");
	strcpy(name, "Cafeteria");
	strcpy(item, "Burger");
	Room* cafeteria = new Room(description, name, item);
	vect.push_back(cafeteria);
	strcpy(description, "Oof it smells in here!");
	strcpy(name, "Bathroom");
	strcpy(item, "Toilet");
	Room* bathroom = new Room(description, name, item); //9
	vect.push_back(bathroom);
	strcpy(description, "Get back inside! You're going to be locked out!");
	strcpy(name, "Main entrance");
	Room* main = new Room(description, name, item); //10
	vect.push_back(main);
	strcpy(description, "Wow! Look at that artwork!");
	strcpy(name, "Art Room");
	strcpy(item, "Pencil");
	Room* art = new Room(description, name, item); //11
	vect.push_back(art);
	strcpy(description, "We're already studying the global pandemic?");
	strcpy(name, "History");
	strcpy(item, "Textbook");
	Room* history = new Room(description, name, item); //12
	vect.push_back(history);
	strcpy(description, "Learning how the world works!");
	strcpy(name, "Physics Class");
	strcpy(item, "Circuit");
	Room* physics = new Room(description, name, item); //13
	vect.push_back(physics);
	strcpy(description, "Wow those are some heavy weights!");
	strcpy(name, "Weightroom");
	strcpy(item, "5lb weight");
	Room* weightroom = new Room(description, name, item); //15
	vect.push_back(weightroom);
	strcpy(description, "Finally! You've made it to class! Time to cPlusPlus.");
	strcpy(name, "cPlusPlus");
	strcpy(item, "Monitor");
	Room* cPlusPlus = new Room(description, name, item); //9
	vect.push_back(cPlusPlus);

	// create Exits NESW
    char* direction = new char(5);
    strcpy(direction, "WEST");
    bathroom->setExit(direction, band);
    gym->setExit(direction, bathroom);
    weightroom->setExit(direction, gym);
    lit->setExit(direction, auditorium);
    cafeteria->setExit(direction, lit);
    physics->setExit(direction, cafeteria);
    chemLab->setExit(direction, physics);
    cPlusPlus->setExit(direction, calc);
    history->setExit(direction, cPlusPlus);

    strcpy(direction, "EAST");
    bathroom->setExit(direction, gym);
    cafeteria->setExit(direction, physics);
    physics->setExit(direction, chemLab);
    cPlusPlus->setExit(direction, history);
    calc->setExit(direction, cPlusPlus);
    band->setExit(direction, bathroom);
    gym->setExit(direction, weightroom);
    auditorium->setExit(direction, lit);
    lit->setExit(direction, cafeteria);

    strcpy(direction, "NORTH");
    lit->setExit(direction, bathroom);
    calc->setExit(direction, lit);
    cafeteria->setExit(direction, gym);
    weightroom->setExit(direction, tennis);
    main->setExit(direction, history);
    art->setExit(direction, band);

    strcpy(direction, "SOUTH");
    tennis->setExit(direction, weightroom);
    bathroom->setExit(direction, lit);
    lit->setExit(direction, calc);
    gym->setExit(direction, cafeteria);
    physics->setExit(direction, history);
    band->setExit(direction, auditorium);
    auditorium->setExit(direction, art);

    //playing the game

    bool playing = true;
    char* input = new char[10];

    cout << "Welcome to Zuul! You are late to cPlusPlus class! Gather your things and find your way!" << endl;
    //while the player is playing do the following
    while (playing) {
    	//print room information every turn
    	roomInfo(current_ptr);
    	cout << "Would you like to: MOVE (to go to another room), PICK (up item), DROP (item), PRINT (inventory), or QUIT" << endl;
    	cin.getline(input, 10, '\n');

    	if (strcmp(input, "MOVE") == 0) {
    		cout << "Which direction would you like to move: ";
    		showExits(current_ptr);
    		cin.getline(input, 10, '\n');
    		current_ptr->move(input, current_ptr);
    	}
    	else if (strcmp(input, "PICK") == 0) {
    		//allows only 5 items in inventory
    		if(playerInventory.size() < 6) {
    			cout << "Input the name of the item you would like to pick up: ";
    			showItems(current_ptr->items);
    			cin.getline(input, 10,'\n');
    			//remove item from the room vector and add to inventory vector
    			Item* item_ptr = current_ptr->removeItem(input);
    			if (item_ptr != NULL) {
    				playerInventory.push_back(item_ptr);
    				cout << "You are currently holding these items: ";
    				showItems(playerInventory);
    			}
    			else {
    				cout << "This item doesn't exist in this room." << endl;
    			}
    		}	
    		else {
    			cout << "Not enough room in your inventory! Drop an item and try again!" << endl;
    		}
    	}
    	else if (strcmp(input, "DROP") == 0) {
    		//print what is inventory to drop
    		cout << "Which item would you like to drop: ";
    		showItems(playerInventory);
    		cin.getline(input, 10, '\n');
    		if (current_ptr->addItem(playerInventory, input)) {
    			cout << "You dropped " << input << ". You are now holding: ";
    			showItems(playerInventory);
    		}
    		else {
    			cout << "You don't have" << input << " in your inventory." << endl;
    		}
    	}
    	else if (strcmp(input, "PRINT") == 0) {
    		cout << "You are curretly holding: ";
    		showItems(playerInventory);
    	}
    	else if (strcmp(input, "QUIT") == 0) {
    		playing = false;
    	}
    	else {
    		cout << "Ah man, invalid input." << endl;
    	}
    	//check current standing to see if won
    	if (checkItems(current_ptr) == true) {
    		cout << "Out of breath? Don't worry you're finally in room 1-20! Say hi to Mr. Galbraith!" << endl;
    		cout << "Class has started. Time to code you're zuul project :D." << endl;
    		playing = false;
    	}
    }

    cout << "Thanks for coming along on this journey!" << endl;
    
    //delete items and room vector
    while (!vect.empty()) {
        Room* room_ptr = vect.back();
        vect.pop_back();
        delete room_ptr;
    }

    while (!playerInventory.empty()) {
        Item* item_ptr = playerInventory.back();
        playerInventory.pop_back();
        delete item_ptr;
    }

	return 0;
}

//prints the exits
void showExits(Room* room_ptr) {
    for (auto& x : room_ptr->exits) {
        cout << x.first << " ";
    }
    cout << endl;
}

//prints the items currently in the room
void showItems(vector<Item*> vect) {
	for(vector<Item*>::iterator it = vect.begin(); it!= vect.end(); it++) {
		cout << (*it)->getName() << endl;
	}
	 if ((vect).empty()) {
        cout << "no items\n";
    }
}

//prints the room information
void roomInfo(Room* room_ptr) {
	cout << "You are in room: " << room_ptr->getName() << endl;
	cout << room_ptr->description << endl;
	cout << "The items in the room are: " << endl;
	showItems(room_ptr->items);
	cout << "The exits are: " << endl;
	showExits(room_ptr);
}

//check if the items in inventory are correct and you are in the correct room for winning game
bool checkItems(Room* room_ptr) {
	int count = 0;
	//go thru the inventory and determine whether the player has the correct items
	for (vector<Item*>::iterator it = playerInventory.begin(); it != playerInventory.end(); it++) {
		if (strcmp((*it)->getName(), "Toilet") == 0){
			count++;
		} 
		if (strcmp((*it)->getName(), "Flute") == 0){
			count++;
		} 
		if (strcmp((*it)->getName(), "Test") == 0){
			count++;
		} 
		if (strcmp((*it)->getName(), "Racquet") == 0){
			count++;
		} 
	}
	if (count > 4 && strcmp(room_ptr->getName(), "cPLusPLus") == 0) {
		return true;
	}
	else {
		return false;
	}

}
