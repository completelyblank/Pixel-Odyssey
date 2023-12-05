#include "Fountain.hpp"

#ifdef _WIN32
#define EXECUTABLE_DIRECTORY ""
#else
#define EXECUTABLE_DIRECTORY "./"
#endif

Fountain::Fountain(StateManager& sm, View& view, int num, float x, float y) : j(true), f(false), wasPressed(false), stateManager(sm), numCoins(num), view(view), hasTransitioned(false), interval(seconds(0.5f)), flag(1), pressed(false) {
    backs.resize(6);
    backs[0].loadFromFile("Assets/Characters/frame1.png");
    backs[1].loadFromFile("Assets/Characters/frame2.png");
    backs[2].loadFromFile("Assets/Characters/frame3.png");
    backs[3].loadFromFile("Assets/Characters/frame4.png");
    backs[4].loadFromFile("Assets/Characters/frame5.png");
    backs[5].loadFromFile("Assets/Characters/frame6.png");
    soundtrack.openFromFile("Assets/Music/Fountain.wav");
    soundtrack.setLoop(true);
    soundtrack.play();
    select.openFromFile("Assets/Music/Select.wav");
    font.loadFromFile("Assets/Fonts/Minecraft.ttf");
    coinText.setFont(font);
    coinText.setCharacterSize(70);
    coinText.setPosition(130, 160);
    coinText.setStyle(Text::Bold);
    coinText.setFillColor(Color::Black);
    joke.setFont(font);
    joke.setCharacterSize(70);
    joke.setPosition(370, 460);
    joke.setStyle(Text::Bold);
    joke.setFillColor(Color::Red);
    fact.setFont(font);
    fact.setCharacterSize(70);
    fact.setPosition(790, 460);
    fact.setStyle(Text::Bold);
    fact.setFillColor(Color::Black);
    fact.setString("Fact");
    joke.setString("- Joke -");
    coinText.setString("\t\t Ahoy there! I'm Aqua.\nReady for a chuckle or a fact?\n\t\t  Choose yer fancy!");
    press.setFont(font);
    press.setCharacterSize(50);
    press.setPosition(430, 600);
    press.setStyle(Text::Bold);
    press.setFillColor(Color::White);
    press.setString("Press A To Select . . .");

    root = new DecisionTreeNode;
    root->jokes.insert("What did the fish say\nwhen it swam into the wall?\nOh dam!");
    root->jokes.insert("Why don't skeletons fight\neach other?\nThey don't have the guts.");
    root->jokes.insert("Why did the math book look sad?\nBecause it had too many\nproblems.");
    root->jokes.insert("What do you call a pile of cats?\nA meowtain.");
    root->jokes.insert("What do you call a can opener\nthat doesn't work?\nA can't opener.");
    root->facts.insert("Cows have best friends and\ncan become stressed when\nthey are separated.");
    root->facts.insert("The Eiffel Tower can be 15 cm\ntaller during the summer due\nto thermal expansion.");
    root->facts.insert("Octopuses have three\nhearts and blue blood.");
    root->facts.insert("The average person will spend\nsix months of their life waiting\nfor red lights to turn green.");
    root->facts.insert("Archaeologists have found pots of\nhoney in ancient Egyptian tombs\n that are over 3,000 years old\nand still perfectly edible.");
    root->left = nullptr;
    root->right = nullptr;
}

void Fountain::fade(RenderWindow& window, View& view, Clock& track) {
    RectangleShape fadeShape(Vector2f(3250.f, 3950.f));
    for (int alpha = 0; alpha <= 255; alpha += 5) {
        fadeShape.setFillColor(Color(0, 0, 0, alpha));
        window.clear();
        render(window, track);
        window.draw(fadeShape);
        window.display();
    }
}

void Fountain::handleInput(RenderWindow& window, View& view, Clock& track) {
    if (hasTransitioned) {
        Vector2f newViewCenter = character.getPosition();
        view.setCenter(newViewCenter);
        fade(window, view, track);
        stateManager.changeState(make_unique<City>(stateManager, view, numCoins, 1620.f, 2115.f));
        hasTransitioned = false;
    }
}

void Fountain::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) {
}


void Fountain::render(RenderWindow& window, Clock& track) {
    window.clear();
    if (track.getElapsedTime() >= interval) {
        track.restart();
        background.character.setTexture(backs[flag - 1]);
        if (flag < 6) {
            flag++;
        }
    }
    if (flag > 5 && !pressed) {
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            pressed = true;
            select.play();
            coinText.setPosition(130, 250);
            if (j) {
                coinText.setString(root->jokes.getRandomNode());
            }
            else if (f) {
                coinText.setString(root->facts.getRandomNode());
                f = false;
            }
        }
    }
    if (flag > 5 && pressed) {
        press.setString("Press S To Exit . . .");
        if (Keyboard::isKeyPressed(Keyboard::S)) {
            hasTransitioned = true;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        fact.setFillColor(Color::Red);
        joke.setFillColor(Color::Black);
        joke.setString("Joke");
        fact.setString("- Fact -");
        j = false;
        f = true;
    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        joke.setFillColor(Color::Red);
        fact.setFillColor(Color::Black);
        joke.setString("- Joke -");
        fact.setString("Fact");
        j = true;
        f = false;
    }
    View view = window.getView();
    window.setView(window.getDefaultView());
    background.draw(window);
    if (flag > 5) {
        if (!pressed) {
            window.draw(joke);
            window.draw(fact);
        }
        else {
            press.setPosition(650, 600);
        }
        window.draw(press);
        window.draw(coinText);
    }
    window.setView(view);

}

Character& Fountain::getCharacter() {
    return character;
}

Tiling& Fountain::getTile() {
    return tile;
}
