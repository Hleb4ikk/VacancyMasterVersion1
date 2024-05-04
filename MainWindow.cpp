#include "MainWindow.h"

MainWindow::MainWindow()
{

	width = sf::VideoMode::getDesktopMode().width/1.5;
	height = sf::VideoMode::getDesktopMode().height/1.5;
	window.create(sf::VideoMode(width, height), L"VacancyMaster", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
}

void MainWindow::run()
{
    sf::Font font;
    font.loadFromFile("Montserrat-Regular.ttf");
    Menu menu(font, width,  height,  width / 17,  height / 10.8, width / 43);
    Button PlusButton("+", font, sf::Color(147, 147, 147), sf::Color(0, 0, 0), height / 15, height / 15, width / 17 - (height/20 - height/30), height / 1.05);
    //Button MinusButton("-", font, sf::Color(147, 147, 147), sf::Color(0, 0, 0), width / 10, height / 17.5, 2 * width / 17 + 8, height / 1.5);
    int chooseButton = -1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {

            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                window.setSize(sf::Vector2u(width, height));
                break;
            case sf::Event::MouseMoved:
                
                for (int i = 0; i < 5; i++) {

                    if (menu.getButtons()[i].isMouseOver(window)) {

                        menu.getButtons()[i].setBColor(sf::Color(130, 130, 130));

                    }
                    else {

                        menu.getButtons()[i].setBColor(sf::Color(147, 147, 147));

                    }
                    if (PlusButton.isMouseOver(window)) {

                        PlusButton.setBColor(sf::Color(130, 130, 130));

                    }
                    else {

                        PlusButton.setBColor(sf::Color(147, 147, 147));

                    }
                }
                break;

            }
        }
        window.clear(sf::Color(204, 204, 204));

        

        for (int i = 0; i < 5; i++) {

            if (menu.getButtons()[i].isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                menu.getButtons()[i].setBColor(sf::Color(112, 112, 112));
                chooseButton = i;
            }

            else if (menu.getButtons()[i].isMouseOver(window) && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                menu.getButtons()[i].setBColor(sf::Color(130, 130, 130));

            }


        }

        //list

        switch (chooseButton)
        {
        case 0:
            PlusButton.drawButton(window);

            if (PlusButton.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                PlusButton.setBColor(sf::Color(112, 112, 112));
                chooseButton = 0;
            }

            else if (PlusButton.isMouseOver(window) && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                PlusButton.setBColor(sf::Color(130, 130, 130));

            }
            break;
        case 1:
            break;
        case 2:
            //window.draw(data.getShape());
            break;
        case 3:
            PlusButton.drawButton(window);

            if (PlusButton.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                PlusButton.setBColor(sf::Color(112, 112, 112));
                chooseButton = 3;
            }

            else if (PlusButton.isMouseOver(window) && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                PlusButton.setBColor(sf::Color(130, 130, 130));

            }
            break;
        case 4:

            break;
        default:
            break;
        }
        menu.drawMenu(window);
        window.display();
    }

}
