#include "Beach.hpp"

Beach::Beach(StateManager& sm, View& view, int num, float x, float y) : stateManager(sm), numCoins(num), wasPressed(false), pressed(false), talk(false), space(2), index(1), empty(false), i(0), j(0), k(0), a(0), b(0), t1(true), t2(true), t3(true), t4(true), t5(true), view(view), hasTransitioned(false), interval(seconds(1.2f)), flag(2), pick(false), move(seconds(3.f)), startMove(false) {
    character.setTexture("Assets/Characters/charright1.png");
    character.setPosition(x, y);
    backs.resize(3);
    prompt.setTexture("Assets/Characters/pick.png");
    pressA.setTexture("Assets/Characters/pressA.png");
    pressA.setPosition(30.f, 600.f);
    dialogue.setTexture("Assets/Characters/francisdialogue.png");
    dialogue.setPosition(80.f, 240.f);
    francis.setTexture("Assets/Characters/Francis.png");
    francis.setPosition(1710.f, 900.f);
    prompt.setPosition(30.f, 600.f);
    backs[0].loadFromFile("Assets/Characters/beachh1.png");
    backs[1].loadFromFile("Assets/Characters/beachh2.png");
    backs[2].loadFromFile("Assets/Characters/beachh3.png");
    soundtrack.openFromFile("Assets/Music/Beach.wav");
    soundtrack.setLoop(true);
    soundtrack.play();
    waves.openFromFile("Assets/Music/Waves.wav");
    waves.setLoop(true);
    waves.play();
    can.loadFromFile("Assets/Characters/trashCan.png");
    trashCan.setTexture(can);
    trashCan.setPosition(1125.f, 270.f);
    font.loadFromFile("Assets/Fonts/Minecraft.ttf");
    trash1.setTexture("Assets/Characters/trash1.png");
    trash2.setTexture("Assets/Characters/trash2.png");
    trash3.setTexture("Assets/Characters/trash3.png");
    trash4.setTexture("Assets/Characters/trash4.png");
    trash5.setTexture("Assets/Characters/trash5.png");
    trash1.setPosition(1500.f, 470.f);
    garbage.push_back(trash1.character);
    trash2.setPosition(1800.f, 450.f);
    garbage.push_back(trash2.character);
    trash3.setPosition(1300.f, 700.f);
    garbage.push_back(trash3.character);
    trash4.setPosition(1750.f, 700.f);
    garbage.push_back(trash4.character);
    trash5.setPosition(1450.f, 1000.f);
    garbage.push_back(trash5.character);
    names.setFont(font);
    names.setStyle(Text::Bold);
    names.setCharacterSize(30);
    names.setFillColor(Color::White);
    names.setOutlineColor(Color::Black);
    names.setOutlineThickness(3);
}

bool Beach::door() {
    if (character.character.getPosition().y > 530 && character.character.getPosition().y < 730 && character.character.getPosition().x < 930) {
        return true;
    }
    return false;
}

void Beach::fade(RenderWindow& window, View& view, Clock& track)
{
    RectangleShape fadeShape(Vector2f(3250.f, 3250.f));
    for (int alpha = 0; alpha <= 255; alpha += 5)
    {
        fadeShape.setFillColor(Color(0, 0, 0, alpha));
        window.clear();
        render(window, track);
        window.draw(fadeShape);
        window.display();
    }
}

void Beach::handleInput(RenderWindow& window, View& view, Clock& track) {
    bound.set(beach);
    if (door() && !hasTransitioned) {
        Vector2f newViewCenter = character.getPosition();
        view.setCenter(newViewCenter);
        fade(window, view, track);
        stateManager.changeState(make_unique<City>(stateManager, view, numCoins, 2970.f, 1350.f));
        hasTransitioned = true;
    }
    if (Keyboard::isKeyPressed(Keyboard::A) && talk && !wasPressed) {
        pressed = !pressed;
    }
    wasPressed = Keyboard::isKeyPressed(Keyboard::A);

}

void Beach::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) {
    if (track.getElapsedTime() >= move) {
        startMove = true;
    }
    if (startMove) {
        character.handlemovement(event, deltaTime, track, tile, bound, clock);
    }
    if (character.character.getGlobalBounds().intersects(garbage[0].getGlobalBounds()) && i == 0) {
        pick = true;
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            t1 = false;
            i++;
            trashQueue.push("Blue Soda Can");
        }
    }
    else if (character.character.getGlobalBounds().intersects(garbage[1].getGlobalBounds()) && j == 0) {
        pick = true;
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            t2 = false;
            j++;
            trashQueue.push("Orange Soda Can");
        }
    }
    else if (character.character.getGlobalBounds().intersects(garbage[2].getGlobalBounds()) && k == 0) {
        pick = true;
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            t3 = false;
            k++;
            trashQueue.push("Juice Box");
        }
    }
    else if (character.character.getGlobalBounds().intersects(garbage[3].getGlobalBounds()) && a == 0) {
        pick = true;
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            t4 = false;
            a++;
            trashQueue.push("Apple");
        }
    }
    else if (character.character.getGlobalBounds().intersects(garbage[4].getGlobalBounds()) && b == 0) {
        pick = true;
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            t5 = false;
            b++;
            trashQueue.push("Wrapper");
        }
    }
    else {
        pick = false;
    }
    if (character.character.getGlobalBounds().intersects(trashCan.getGlobalBounds())) {
        if (!trashQueue.empty()) {
            prompt.setTexture("Assets/Characters/throw.png");
            pick = true;
            if (Keyboard::isKeyPressed(Keyboard::A)) {
                trashQueue = queue<String>();
            }
        }
    }
    else {
        prompt.setTexture("Assets/Characters/pick.png");
    }
    if (character.character.getGlobalBounds().intersects(francis.character.getGlobalBounds())) {
        talk = true;
    }
    else {
        talk = false;
    }
}

void Beach::render(RenderWindow& window, Clock& track) {
    window.clear();
    for (auto& i : bound.bound)
    {
        window.draw(i);
    }
    if (track.getElapsedTime() >= interval) {
        track.restart();
        background.character.setTexture(backs[flag - 1]);
        flag++;
        if (flag > 3) {
            flag = 1;
        }
    }
    background.setPosition(0.f, 0.f);
    background.draw(window);
    window.draw(trashCan);
    if (t1) {
        trash1.draw(window);
    }
    if (t2) {
        trash2.draw(window);
    }
    if (t3) {
        trash3.draw(window);
    }
    if (t4) {
        trash4.draw(window);
    }
    if (t5) {
        trash5.draw(window);
    }
    francis.draw(window);
    character.draw(window);
    View view = window.getView();
    window.setView(window.getDefaultView());
    if (pick) {
        prompt.draw(window);
    }
    if (talk && pressed) {
        dialogue.draw(window);
    }
    if (talk && !pressed) {
        pressA.draw(window);
    }
    names.setString("Collected Trash: ");
    names.setPosition(20, 30);
    window.draw(names);

    if (!trashQueue.empty()) {
        queue <String> trashQueueCopy = trashQueue;
        trashQueueCopy.push("");
        if (trashQueueCopy.front() != "") {
            space = 2;
            index = 1;
        }
        while (!trashQueueCopy.empty()) {
            if (trashQueueCopy.front() != "") {
                names.setString(to_string(index) + ")");
                index++;
                names.setPosition(20, 30 * index);
                window.draw(names);
                names.setString(trashQueueCopy.front());
                names.setPosition(70, 30 * space);
                space += 1.5;
                window.draw(names);
            }
            trashQueueCopy.pop();
        }
    }
    window.setView(view);
}

Character& Beach::getCharacter() {
    return character;
}

Tiling& Beach::getTile() {
    return tile;
}