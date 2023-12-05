#include "Park.hpp"

Park::Park(StateManager& sm, View& view, int num, float x, float y) : stateManager(sm), numCoins(num), view(view), add(0), hasTransitioned(false), talkA(false), talkB(false), talkC(false), talkM(false), pressed(false), interval(seconds(1.2f)), flag(2), wasPressed(false), startMove(false), move(seconds(3.f)) {
    character.setTexture("Assets/Characters/charright1.png");
    character.setPosition(x, y);
    top.setTexture("Assets/Characters/parktop.png");
    prompt.loadFromFile("Assets/Characters/pressA.png");
    tile.setTexture("Assets/Characters/park.jpg");
    dialogueM.loadFromFile("Assets/Characters/meepopdialogue.png");
    pressA.setTexture(prompt);
    pressA.setPosition(30.f, 600.f);
    dialogueA.loadFromFile("Assets/Characters/saimgrave.png");
    dialogueB.loadFromFile("Assets/Characters/amnagrave.png");
    dialogueC.loadFromFile("Assets/Characters/razagrave.png");
    box.setPosition(80.f, 260.f);
    grave.loadFromFile("Assets/Characters/grave.png");
    stoneA.setTexture(grave);
    stoneA.setPosition(1400.f, 720.f);
    stoneB.setTexture(grave);
    stoneB.setPosition(1330.f, 570.f);
    stoneC.setTexture(grave);
    stoneC.setPosition(1600.f, 720.f);
    backs.resize(3);

    backs[0].loadFromFile("Assets/Characters/park1.png");
    backs[1].loadFromFile("Assets/Characters/park2.png");
    backs[2].loadFromFile("Assets/Characters/park3.png");
    soundtrack.openFromFile("Assets/Music/Park.wav");
    soundtrack.setLoop(true);
    soundtrack.play();
    coin.setTexture("Assets/Characters/coins.png");
    coin.setPosition(30.f, 30.f);
    font.loadFromFile("Assets/Fonts/Minecraft.ttf");
    coinText.setFont(font);
    coinText.setStyle(Text::Bold);
    coinText.setCharacterSize(60);
    coinText.setPosition(150, 30);
    coinText.setFillColor(Color::White);
    coinText.setOutlineColor(Color::Black);
    coinText.setOutlineThickness(5);
}

bool Park::door() {
    if (character.character.getPosition().x < 690 && character.character.getPosition().y < 765 && character.character.getPosition().y > 360) {
        return true;
    }
    return false;
}

void Park::fade(RenderWindow& window, View& view, Clock& track)
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

void Park::handleInput(RenderWindow& window, View& view, Clock& track) {
    tile.updatevals(view.getCenter().x, view.getCenter().y);
    tile.check();
    bound.set(park);
    if (door() && !hasTransitioned) {
        Vector2f newViewCenter = character.getPosition();
        view.setCenter(newViewCenter);
        fade(window, view, track);
        stateManager.changeState(make_unique<City>(stateManager, view, numCoins, 2640.f, 3240.f));
        hasTransitioned = true;
    }

    if (character.character.getGlobalBounds().intersects(stoneA.getGlobalBounds())) {
        talkA = true;
    }
    else {
        talkA = false;
    }
    if (character.character.getGlobalBounds().intersects(stoneB.getGlobalBounds())) {
        talkB = true;
    }
    else {
        talkB = false;
    }
    if (character.character.getGlobalBounds().intersects(stoneC.getGlobalBounds())) {
        talkC = true;
    }
    else {
        talkC = false;
    }
    if (character.character.getPosition().x > 900 && character.character.getPosition().x < 1080 && character.character.getPosition().y < 225) {
        talkM = true;
    }
    else {
        talkM = false;
    }
    if (Keyboard::isKeyPressed(Keyboard::A) && (talkA || talkB || talkC || talkM) && !wasPressed) {
        pressed = !pressed;
    }
    wasPressed = Keyboard::isKeyPressed(Keyboard::A);
}

void Park::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) {
    if (!pressed) {
        if (track.getElapsedTime() >= move) {
            startMove = true;
        }
        if (startMove) {
            character.handlemovement(event, deltaTime, track, tile, bound, clock);
        }
    }
}

void Park::render(RenderWindow& window, Clock& track) {
    window.clear();
    for (auto& i : bound.bound)
    {
        window.draw(i);
    }
    for (int x = tile.left; x < tile.right; x++)
    {
        for (int y = tile.up; y < tile.down; y++)
        {
            window.draw(tile.tilemap[x][y]);
        }
    }
    if (track.getElapsedTime() >= interval) {
        track.restart();
        background.character.setTexture(backs[flag - 1]);
        flag++;
        if (flag > 3) {
            flag = 1;
        }
    }
    background.draw(window);
    window.draw(stoneA);
    window.draw(stoneB);
    window.draw(stoneC);
    character.draw(window);
    top.draw(window);
    if ((talkA || talkB || talkC || talkM) && !pressed) {
        if (!door()) {
            window.setView(window.getDefaultView());
        }
        window.draw(pressA);
    }
    if (talkA && pressed) {
        if (!door()) {
            window.setView(window.getDefaultView());
        }
        box.setTexture(dialogueA);
        window.draw(box);
    }
    if (talkB && pressed) {
        if (!door()) {
            window.setView(window.getDefaultView());
        }
        box.setTexture(dialogueB);
        window.draw(box);
    }
    if (talkC && pressed) {
        if (!door()) {
            window.setView(window.getDefaultView());
        }
        box.setTexture(dialogueC);
        window.draw(box);
    }
    if (talkM && pressed) {
        if (!door()) {
            window.setView(window.getDefaultView());
        }
        box.setTexture(dialogueM);
        window.draw(box);
        if (add == 0) {
            numCoins += 3;
            add++;
        }
    }
    View view = window.getView();
    window.setView(window.getDefaultView());
    coin.draw(window);
    coinText.setString(" x " + to_string(numCoins));
    window.draw(coinText);
    window.setView(view);
}

Character& Park::getCharacter() {
    return character;
}

Tiling& Park::getTile() {
    return tile;
}