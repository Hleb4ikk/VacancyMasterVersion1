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
    List VacancyList("VacancyList.txt", font, width, height, width / 17, height / 4.5);
    Button PlusButton("+", font, sf::Color(147, 147, 147), sf::Color(0, 0, 0), height / 15, height / 15, width / 17 - (height/20 - height/30), height / 1.05);
    sf::RectangleShape footer;
    footer.setFillColor(sf::Color(204, 204, 204));
    footer.setSize(sf::Vector2f(width, height/7.5));
    footer.setPosition(sf::Vector2f(0, height / 1.1));
    int chooseButton = -1;
    sf::Vector2i MouseBlockPosition = sf::Mouse::getPosition();
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
                }
                for (int i = 0; i < VacancyList.getList().size(); i++) {

                    if (VacancyList.getList()[i].isMouseOver(window)) {

                        VacancyList.getList()[i].setBColor(sf::Color(130, 130, 130));

                    }
                    else {

                        VacancyList.getList()[i].setBColor(sf::Color(147, 147, 147));

                    }

                }
                if (PlusButton.isMouseOver(window)) {

                    PlusButton.setBColor(sf::Color(130, 130, 130));

                }
                else {

                    PlusButton.setBColor(sf::Color(147, 147, 147));

                }
                break;
            case sf::Event::MouseWheelMoved:
                if (chooseButton == 0) {
                    float moved = event.mouseWheel.delta*height/50;
                    VacancyList.ChangePosition(moved);
                }
                break;
            }
        }
        window.clear(sf::Color(204, 204, 204));

        for (int i = 0; i < 5; i++) {                                                                                  //для меню

            if (menu.getButtons()[i].isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                menu.getButtons()[i].setBColor(sf::Color(112, 112, 112));
                chooseButton = i;
            }

            else if (menu.getButtons()[i].isMouseOver(window) && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                menu.getButtons()[i].setBColor(sf::Color(130, 130, 130));

            }


        }
        
        for (int i = 0; i < VacancyList.getList().size(); i++) {                                                        //для листа

            if (VacancyList.getList()[i].isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && MouseBlockPosition != sf::Mouse::getPosition()) {
                MouseBlockPosition = sf::Mouse::getPosition();
                VacancyList.getList()[i].setBColor(sf::Color(112, 112, 112));
                VacancyList.deleteEl(i, font, width, height);

            }
            else if (VacancyList.getList()[i].isMouseOver(window) && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                VacancyList.getList()[i].setBColor(sf::Color(130, 130, 130));

            }
        }

        if (PlusButton.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {    //для плюса

            PlusButton.setBColor(sf::Color(112, 112, 112));
            chooseButton = 0;
        }

        else if (PlusButton.isMouseOver(window) && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            PlusButton.setBColor(sf::Color(130, 130, 130));

        }

        switch (chooseButton)
        {
        case 0:

            VacancyList.draw(window);
            window.draw(footer);
            PlusButton.drawButton(window);

            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            PlusButton.drawButton(window);

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
