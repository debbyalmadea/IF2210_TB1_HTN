all:
	g++ src/main.cpp src/GameState/GameState.cpp src/IO/FileReader.cpp src/Ability/*.cpp src/Card/PermenCard.cpp src/Exception/*.cpp src/Deck/AbilityDeck.cpp -o bin/main -std=c++17 