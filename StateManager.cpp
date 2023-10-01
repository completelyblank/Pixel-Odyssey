#include "StateManager.hpp"
#include "City.hpp"
#include <stack>

StateManager::StateManager() {
   
}

void StateManager::pushState(unique_ptr<GameState> state) {
    states.push(move(state));
}

void StateManager::popState() {
    if (!states.empty()) {
        states.pop();
    }
}

void StateManager::changeState(unique_ptr<GameState> state) {
    if (!states.empty()) {
        popState();
    }
    pushState(std::move(state));
}

void StateManager::updateView(RenderWindow& window) {
    if (!states.empty()) {
        View view = window.getView();
        const Vector2f characterPosition = states.top()->getCharacter().getPosition(); // Assuming Character has getPosition() method
    }
}

void StateManager::handleInput(sf::RenderWindow& window, sf::View& view) {
    if (!states.empty()) {
        states.top()->handleInput(window, view);
    }
}

void StateManager::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) {
    if (!states.empty()) {
        states.top()->update(window, deltaTime, track, event, clock);
        updateView(window); 

    }
}

void StateManager::render(RenderWindow& window) {
    if (!states.empty()) {
        states.top()->render(window);
    }
}

Character& StateManager::getCharacter() {
    if (!states.empty()) {
        return states.top()->getCharacter();
    }
}
Tiling& StateManager::getTile() {
    if (!states.empty()) {
        return states.top()->getTile();
    }
}


