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
    Menu menu(font, width,  height,  width / 15.5,  height / 10.8, width / 43);

    StreamBuffer VacancyBuf("VacancyList.bin");
    List VacancyList(VacancyBuf, font, width, height, width / 15.5, height / 4.5);
    float StartYPosition = VacancyList.getPosition();

    /*StreamBuffer AppliesBuf("AppliesList.txt");
    List AppliesList(AppliesBuf, font, width, height, width / 15.5, height / 4.5);

    StreamBuffer EmployeesBuf("EmployeesList.txt");
    List EmployeesList(EmployeesBuf, font, width, height, width / 15.5, height / 4.5);
    */
    Button PlusButton("+", font, sf::Color(147, 147, 147), sf::Color(0, 0, 0), height / 15, height / 15, width / 15.5 - (height/20 - height/30), height / 1.05);

    TextField searchField("", width / 64.8, sf::Color(0, 0, 0), sf::Color(147, 147, 147), false, width / 3.857, height / 15);
    searchField.setFont(font);
    searchField.setPosition(sf::Vector2f(width / 1.2, height / 1.095));

    TextField textTitleField("Vacancy title input", width / 64.8, sf::Color(0, 0, 0), sf::Color(147, 147, 147), false, width / 3.857, height / 10);
    textTitleField.setFont(font);
    textTitleField.setPosition(sf::Vector2f(width / 2, height / 2.3));

    TextField textDescriptionField("Vacancy description input", width / 64.8, sf::Color(0, 0, 0), sf::Color(147, 147, 147), false, width / 1.61, height / 10);
    textDescriptionField.setFont(font);
    textDescriptionField.setPosition(sf::Vector2f(width / 2, height / 2.3));

    sf::RectangleShape footer;
    footer.setFillColor(sf::Color(204, 204, 204));
    footer.setSize(sf::Vector2f(width, height/7.5));
    footer.setPosition(sf::Vector2f(0, height / 1.1));

    bool searchFieldisSelected = 0;
    int chooseButton = -1;
    int numberOfInput = 0;
    bool dataWasEntered = 0;
    bool wasSelected = 0;
    bool isSorted = 0;
    bool StepOfSearchEnter = 0;
    int StepOfDeleting = 0;
    int indexOfElementToDelete = -1;
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
                
                for (int i = 0; i < menu.getButtons().size(); i++) {

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
                if (chooseButton == 0 && !VacancyList.getList().empty() && numberOfInput == 0) {
                    float moved = event.mouseWheel.delta*height/50;
                    VacancyList.ChangePosition(moved);
                }
                break;
            case sf::Event::TextEntered:
                if (searchField.isSelect()) searchField.typedOn(event);
                if (textTitleField.isSelect()) textTitleField.typedOn(event);
                if (textDescriptionField.isSelect()) textDescriptionField.typedOn(event);
                if (chooseButton == 0 && numberOfInput == 0 && (event.text.unicode == 83 || event.text.unicode == 115) && !searchField.isSelect() && searchField.getText() == "") {

                    VacancyBuf.sortByTitle();
                    VacancyList.update(VacancyBuf, font, width, height);
                    isSorted = 1;
                    
                }
                if (chooseButton == 0 && numberOfInput == 0 && (event.text.unicode == 85 || event.text.unicode == 117) && !searchField.isSelect() && searchField.getText() == "") {
                    VacancyBuf.update();
                    VacancyList.update(VacancyBuf, font, width, height);
                    isSorted = 0;
                }
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
        
        for (int i = 0; i < VacancyList.getList().size(); i++) {                                                        //для листа вакансий

            if (VacancyList.getList()[i].isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                VacancyList.getList()[i].setBColor(sf::Color(112, 112, 112));
                indexOfElementToDelete = i;
            }
            else if (VacancyList.getList()[i].isMouseOver(window) && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                VacancyList.getList()[i].setBColor(sf::Color(130, 130, 130));

            }
        }
        if (indexOfElementToDelete != -1 && !sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isSorted && searchField.getText() == "") {

            VacancyBuf.deleteEl(indexOfElementToDelete);
            VacancyList.update(VacancyBuf, font, width, height);
            indexOfElementToDelete = -1;
        }
        else if (isSorted && searchField.getText() != "") {

            indexOfElementToDelete = -1;

        }
        if (PlusButton.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {    //для плюса

            PlusButton.setBColor(sf::Color(112, 112, 112));
            textTitleField.setText("");
            textDescriptionField.setText("");
            numberOfInput = 1;

        }
        else if (PlusButton.isMouseOver(window) && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            PlusButton.setBColor(sf::Color(130, 130, 130));

        }
        if (searchField.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) searchFieldisSelected = 1;
        if (searchFieldisSelected) { 
            searchField.setSelected(true);
            searchFieldisSelected = 0;
        }
        if (!searchField.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) { 
        
            searchField.setSelected(false); 
            
        }
        if (searchField.isSelect() && StepOfSearchEnter != 1) {
            StepOfSearchEnter = 1;
        }
        if (!searchField.isSelect() && StepOfSearchEnter == 1) {
            StepOfSearchEnter = 0;
            VacancyBuf.update();
            VacancyBuf.Search(searchField.getText());
            VacancyList.update(VacancyBuf, font, width, height);
        }
        if (numberOfInput == 1 && !wasSelected) {

            textTitleField.setSelected(true);
            wasSelected = 1;
        }
        if (numberOfInput == 1 && !textTitleField.isSelect()) {
            if (textTitleField.getText() == "") {

                numberOfInput = 0;

            }
            else {
                numberOfInput = 2;
                
            }
            wasSelected = 0;
        } 

        if (numberOfInput == 2 && !wasSelected) {

            textDescriptionField.setSelected(true);
            wasSelected = 1;
        }

        if (numberOfInput == 2 && !textDescriptionField.isSelect()) {
            numberOfInput = 0;
            wasSelected = 0;
            dataWasEntered = 1;
        }

        if (!(chooseButton == 0)) numberOfInput = 0;

        if (dataWasEntered) { //Когда все данные введены добавляет их в файл и лист считывает файл добавляя элементы в графический список 

            VacancyBuf.add(textTitleField.getText(), textDescriptionField.getText());
            VacancyList.update(VacancyBuf, font, width, height);

            numberOfInput = 0;
            dataWasEntered = 0;
        }

        switch (chooseButton)
        {
        case 0:
            

            if (numberOfInput == 1) {

                textTitleField.drawTo(window); //Рисует поле ввода названия вакансии

            } else if (numberOfInput == 2) {

                textDescriptionField.drawTo(window); //Рисует поле ввода описания вакансии

            }
            else {

                VacancyList.draw(window); //Рисует лист с вакансиями
                
                window.draw(footer); //рисует нижний барьер
                searchField.drawTo(window); //рисует поле для поиска
                PlusButton.drawButton(window); //Рисует плюс

            }

            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
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
