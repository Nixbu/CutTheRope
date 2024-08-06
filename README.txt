Project - Cut the Rope
***********************************************************************
Written by: 
	Nir Busheri
	Itay Mijan
	Sagi Seri
***********************************************************************
This project implements a Cut the Rope style game using SFML and Box2D physics.
The player interacts with various objects to guide a piece of candy to Om Nom.
The game features multiple levels, physics-based gameplay, and various
interactive elements like ropes, bubbles, and air cushions.

***********************************************************************
Level Format
***********************************************************************
To create a new level:
1. Add the name of the level to the file LevelPlaylist.txt.
2. Create the level file with the same name in the "resources" directory.
3. Define the level layout and objects in the file.
4. Add the level file to the CMakeLists.txt file:
   configure_file ("resources/<file_name>.txt" ${CMAKE_BINARY_DIR} COPYONLY)
***********************************************************************
FILES
***********************************************************************
Header Files:
Animation.h - Handles sprite animations for game objects
AirFactory.h - Factory for creating Air objects
AirPillowFactory.h - Factory for creating AirPillow objects
BubbleFactory.h - Factory for creating Bubble objects
CandyFactory.h - Factory for creating Candy objects
ChairFactory.h - Factory for creating Chair objects
DoubleHatFactory.h - Factory for creating DoubleHat objects
GravityButtonFactory.h - Factory for creating GravityButton objects
OmnomFactory.h - Factory for creating Omnom objects
RopeFactory.h - Factory for creating Rope objects
SpikesFactory.h - Factory for creating Spikes objects
StarFactory.h - Factory for creating Star objects
Air.h - Defines Air class for air current game mechanic
AirPillow.h - Defines AirPillow class for air cushion game mechanic
Bubble.h - Defines Bubble class for bubble lifting mechanic
Candy.h - Defines Candy class, the main object player interacts with
Chair.h - Defines Chair class for static obstacle
ClickableObject.h - Base class for objects that can be clicked
DoubleHat.h - Defines DoubleHat class for special hat mechanic
GameObject.h - Base class for all game objects
GravityButton.h - Defines GravityButton class to change gravity direction
Hat.h - Defines Hat class for basic hat mechanic
Hook.h - Defines Hook class for rope attachment points
NonClickableObject.h - Base class for objects that can't be clicked
Omnom.h - Defines Omnom class, the character players feed candy to
Rope.h - Defines Rope class for rope mechanics
RopeSegment.h - Defines RopeSegment class for individual rope parts
Spikes.h - Defines Spikes class for dangerous obstacles
Star.h - Defines Star class for collectible bonus objects
Button.h - Defines Button class for UI elements
ChangeScreen.h - Command class to change game screens
Command.h - Base class for command pattern implementation
MusicCommand.h - Command class to control game music
PlayLevel.h - Command class to start playing a level
ResetLevel.h - Command class to reset current level
CollisionHandling.h - Handles collision detection and resolution
Controller.h - Main game controller managing game flow
FactoryManager.h - Manages all object creation factories
GameState.h - Base class for different game states
HelpState.h - Defines HelpState class for help/instructions screen
InterstitalState.h - Defines InterstitalState class for between-level screens
Level.h - Defines Level class to manage individual game levels
LevelSelectState.h - Defines LevelSelectState class for level selection screen
MainState.h - Defines MainState class for main menu
Menu.h - Defines Menu class to manage groups of UI elements
PlayingState.h - Defines PlayingState class for active gameplay
ResourceManager.h - Manages loading and access to game resources
Settings.h - Contains game-wide constants and settings
WinState.h - Defines WinState class for level completion screen
World.h - Manages the game world, including physics simulation

CPP Files:
Animation.cpp - Implements sprite animation functionality
AirFactory.cpp - Implements Air object creation
AirPillowFactory.cpp - Implements AirPillow object creation
BubbleFactory.cpp - Implements Bubble object creation
CandyFactory.cpp - Implements Candy object creation
ChairFactory.cpp - Implements Chair object creation
DoubleHatFactory.cpp - Implements DoubleHat object creation
GravityButtonFactory.cpp - Implements GravityButton object creation
OmnomFactory.cpp - Implements Omnom object creation
RopeFactory.cpp - Implements Rope object creation
SpikesFactory.cpp - Implements Spikes object creation
StarFactory.cpp - Implements Star object creation
Air.cpp - Implements Air class functionality
AirPillow.cpp - Implements AirPillow class functionality
Bubble.cpp - Implements Bubble class functionality
Candy.cpp - Implements Candy class functionality
Chair.cpp - Implements Chair class functionality
ClickableObject.cpp - Implements ClickableObject base class functionality
DoubleHat.cpp - Implements DoubleHat class functionality
GameObject.cpp - Implements GameObject base class functionality
GravityButton.cpp - Implements GravityButton class functionality
Hat.cpp - Implements Hat class functionality
Hook.cpp - Implements Hook class functionality
NonClickableObject.cpp - Implements NonClickableObject base class functionality
Omnom.cpp - Implements Omnom class functionality
Rope.cpp - Implements Rope class functionality
RopeSegment.cpp - Implements RopeSegment class functionality
Spikes.cpp - Implements Spikes class functionality
Star.cpp - Implements Star class functionality
Button.cpp - Implements Button class functionality
ChangeScreen.cpp - Implements ChangeScreen command functionality
Command.cpp - Implements Command base class functionality
MusicCommand.cpp - Implements MusicCommand functionality
PlayLevel.cpp - Implements PlayLevel command functionality
ResetLevel.cpp - Implements ResetLevel command functionality
CollisionHandling.cpp - Implements collision handling logic
Controller.cpp - Implements main game control logic
FactoryManager.cpp - Implements factory management functionality
GameState.cpp - Implements GameState base class functionality
HelpState.cpp - Implements HelpState functionality
InterstitalState.cpp - Implements InterstitalState functionality
Level.cpp - Implements Level class functionality
LevelSelectState.cpp - Implements LevelSelectState functionality
MainState.cpp - Implements MainState functionality
Menu.cpp - Implements Menu class functionality
PlayingState.cpp - Implements PlayingState functionality
ResourceManager.cpp - Implements resource management functionality
WinState.cpp - Implements WinState functionality
World.cpp - Implements game world management and physics simulation
main.cpp - Contains the main function and program entry point
***********************************************************************
Data Structures
***********************************************************************
- std::vector for storing game objects
- std::unordered_map for resource management
- Custom classes for game objects (Air, Bubble, Candy, etc.)

***********************************************************************
Algorithms
***********************************************************************
- Box2D physics simulation
- Collision detection and handling
- Object creation using Factory pattern
- State management for game flow
- Resource loading and management

***********************************************************************
Design Patterns
***********************************************************************
- Factory Pattern: For creating game objects
- Command Pattern: For UI and game actions
- Singleton: For resource management
- State Pattern: For managing game states

***********************************************************************
Known Bugs
***********************************************************************


***********************************************************************
Other Comments
***********************************************************************
This game uses SFML for graphics and input handling, and Box2D for physics
simulation. The project structure allows for easy addition of new levels
and game objects.

Enjoy playing Cut the Rope!
