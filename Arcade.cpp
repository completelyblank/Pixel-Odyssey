#include "Arcade.hpp"

Arcade::Arcade(StateManager& sm, View& view, int num, float x, float y) : playerspeed(100.f), fin(false), numCoins(num), stateManager(sm), sub(false), insufficient(false), view(view), score(0), win(false), hasTransitioned(false), talkA(false), talkB(false), pressed(false), interval(seconds(1.2f)), interval2(seconds(0.5f)), interval3(seconds(2.f)), scoreInterval(seconds(1.f)), flag(2), wasPressed(false), play(false), move(seconds(3.f)), startMove(false) {
    character.setTexture("Assets/Characters/charup1.png");
    character.setPosition(x, y);
    tile.setTexture("Assets/Characters/arcadetile.png");
    npcB.loadFromFile("Assets/Characters/byronup.png");
    byron.setPosition(1110.f, 420.f);
    byron.setTexture(npcB);
    prompt.loadFromFile("Assets/Characters/pressA.png");
    pressA.setTexture(prompt);
    pressA.setPosition(30.f, 600.f);
    dialogueB.loadFromFile("Assets/Characters/byrondialogue.png");
    dialogueA.loadFromFile("Assets/Characters/aarondialogue.png");
    box.setPosition(80.f, 270.f);
    boiText.loadFromFile("Assets/Characters/boi.png");
    boi.setTexture(boiText);
    boi.setPosition(1660.f, 720.f);
    sprites.resize(2);
    sprites.push_back(byron);
    sprites.push_back(boi);
    mazebox.setPosition(250.f, 50.f);
    backs.resize(3);
    maze.resize(3);
    pacman.resize(3);
    gameChar.setPosition(355.f, 100.f);
    maze[0].loadFromFile("Assets/Characters/mazee1.png");
    maze[1].loadFromFile("Assets/Characters/mazee2.png");
    maze[2].loadFromFile("Assets/Characters/mazee3.png");
    backs[0].loadFromFile("Assets/Characters/arcade1.png");
    backs[1].loadFromFile("Assets/Characters/arcade2.png");
    backs[2].loadFromFile("Assets/Characters/arcade3.png");
    pacman[0].loadFromFile("Assets/Characters/pacman1.png");
    pacman[1].loadFromFile("Assets/Characters/pacman2.png");
    pacman[2].loadFromFile("Assets/Characters/pacman1.png");
    scoreboard.loadFromFile("Assets/Characters/scores.png");
    pac.setTexture("Assets/Characters/pacman.png");
    pac.setPosition(355.f, 125.f);
    open.openFromFile("Assets/Music/Open.wav");
    close.openFromFile("Assets/Music/Close.wav");
    open.setVolume(50);
    close.setVolume(50);
    close.play();
    soundtrack.openFromFile("Assets/Music/Arcade.wav");
    soundtrack.setLoop(true);
    soundtrack.play();
    font.loadFromFile("Assets/Fonts/Minecraft.ttf");
    scores.resize(5);
    arrS[0] = 15;
    arrS[1] = 25;
    arrS[2] = 14;
    arrS[3] = 21;
    arrS[4] = 0;
    arrN[0] = "Gamer101";
    arrN[1] = "Fire23";
    arrN[2] = "SnowBros1";
    arrN[3] = "Chad11";
    arrN[4] = "You";
    for (int i = 0; i < 5; i++) {
        scores[i].setFont(font);
        scores[i].setFillColor(Color::Black);
        scores[i].setStyle(Text::Bold);
        scores[i].setCharacterSize(30);
        scores[i].setPosition(550.f, 200.f + i*73);
    }
    coin.setTexture("Assets/Characters/coins.png");
    coin.setPosition(30.f, 30.f);
    coinText.setFont(font);
    coinText.setStyle(Text::Bold);
    coinText.setCharacterSize(60);
    coinText.setPosition(150, 30);
    coinText.setFillColor(Color::White);
    coinText.setOutlineColor(Color::Black);
    coinText.setOutlineThickness(5);
}

bool Arcade::door() {
    if (character.character.getPosition().x > 1100 && character.character.getPosition().x < 1400 && character.character.getPosition().y > 940) {
        return true;
    }
    return false;
}

void Arcade::fade(RenderWindow& window, View& view, Clock& track) 
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

void Arcade::handleInput(RenderWindow& window, View& view, Clock& track) {
    bound.set(arcade);
    bound2.set(mazeBounds);
    if (door() && !hasTransitioned) {
        Vector2f newViewCenter = character.getPosition();
        view.setCenter(newViewCenter);
        open.play();
        fade(window, view, track);
        stateManager.changeState(make_unique<City>(stateManager, view, numCoins, 500.f, 3375.f));
        hasTransitioned = true;
    }

    if (character.character.getGlobalBounds().intersects(byron.getGlobalBounds())) {
        talkB = true;
    }
    else {
        talkB = false;
    }
    if (character.character.getGlobalBounds().intersects(boi.getGlobalBounds())) {
        talkA = true;
    }
    else {
        talkA = false;
    }
    if (character.character.getGlobalBounds().top < 450.f && character.character.getGlobalBounds().left > 1250) {
        play = true;
    } 
    else {
        play = false;
    }
    if (Keyboard::isKeyPressed(Keyboard::A) && (talkA || talkB || play) && !wasPressed && !(play && pressed && !win)) {
        pressed = !pressed;
        if (play && win && !pressed) {
            win = false;
            pac.setPosition(355.f, 125.f);
            gameChar.setPosition(355.f, 100.f);
            mazebox.setTexture(maze[0]);
            numCoins += 2;
        }
    }
    wasPressed = Keyboard::isKeyPressed(Keyboard::A);
}

void Arcade::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) {
    coinText.setString(" x " + to_string(numCoins));
    if (!pressed) {
        if (track.getElapsedTime() >= move) {
            startMove = true;
        }
        if (startMove) {
            character.handlemovement(event, deltaTime, track, tile, bound, clock);
        }
    }
    if (play && !win) {
        if (track.getElapsedTime() >= scoreInterval) {
            track.restart();
            score++;
        }
        if (pac.character.getGlobalBounds().left > 900.f && (pac.character.getGlobalBounds().left + pac.character.getGlobalBounds().width) < 990.f && (pac.character.getGlobalBounds().top + pac.character.getGlobalBounds().height) > 590.f && play && pressed) {
            win = true;
            play = false;
            arrS[4] = score;
            score = 0;
            Sort();
            for (int i = 0; i < 5; i++) {
                scores[i].setString(arrN[i] + "  -  " + to_string(arrS[i]) + " seconds");
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            if (bound2.collision(pac.character, -playerspeed * deltaTime, 0.f).x != 0) {
                gameChar.move(-playerspeed * deltaTime, 0.f);
            }
            pac.character.move(bound2.collision(pac.character, -playerspeed * deltaTime, 0.f));
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right)) {
            if (bound2.collision(pac.character, playerspeed * deltaTime, 0.f).x != 0) {
                gameChar.move(playerspeed * deltaTime, 0.f);
            }
            pac.character.move(bound2.collision(pac.character, playerspeed * deltaTime, 0.f));
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down)) {
            if (bound2.collision(pac.character, 0.f, playerspeed * deltaTime).y != 0) {
                gameChar.move(0.f, playerspeed * deltaTime);
            }
            pac.character.move(bound2.collision(pac.character, 0.f, playerspeed * deltaTime));
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up)) {
            if (bound2.collision(pac.character, 0.f, -playerspeed * deltaTime).y != 0) {
                gameChar.move(0.f, -playerspeed * deltaTime);
            }
            pac.character.move(bound2.collision(pac.character, 0.f, -playerspeed * deltaTime));
        }
    }
}

void Arcade::render(RenderWindow& window, Clock& track) {
    window.clear();
    if (track.getElapsedTime() >= interval) {
        track.restart();
        background.character.setTexture(backs[flag - 1]);
        flag++;
        if (flag > 3) {
            flag = 1;
        }
    }
    for (auto& i : bound.bound)
    {
        window.draw(i);
    }
    background.draw(window);
    window.draw(byron);
    window.draw(boi);
    character.draw(window);
    if ((talkA || talkB || play) && !pressed) {
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
    if (play && pressed && !win) {
        if (!sub) {
            if (numCoins == 0) {
                insufficient = true;
            }
            else {
                numCoins--;
                sub = true;
            }
        }
        coinText.setString(" x " + to_string(numCoins));
        if (!door()) {
            window.setView(window.getDefaultView());
        }
        if (track.getElapsedTime() >= interval2) {
            track.restart();
            mazebox.setTexture(maze[flag - 1]);
            gameChar.setTexture(pacman[flag - 1]);
            flag++;
            if (flag > 3) {
                flag = 1;
            }
        }
        for (auto& i : bound2.bound)
        {
            window.draw(i);
        }
        pac.draw(window);
        window.draw(mazebox);
        window.draw(gameChar);
    }
    if (play && pressed && win) {
        sub = false;
        if (!door()) {
            window.setView(window.getDefaultView());
        }
        mazebox.setTexture(scoreboard);
        window.draw(mazebox);
        for (int i = 0; i < 5; i++) {
            window.draw(scores[i]);
        }
    }
    View view = window.getView();
    window.setView(window.getDefaultView());
    coin.draw(window);
    window.draw(coinText);
    window.setView(view);
}

void Arcade::Sort() {
    for (int i = 0; i < 4; i++) {
        int least = i;
        for (int j = i + 1; j < 5; j++) {
            if (arrS[least] > arrS[j]) {
                swap(arrS[least], arrS[j]);
                swap(arrN[least], arrN[j]);
            }
        }
    }
}

Character& Arcade::getCharacter() {
    return character;
}

Tiling& Arcade::getTile() {
    return tile;
}