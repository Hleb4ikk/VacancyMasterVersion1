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
    std::vector<ListElement> DBOfApplies = { ListElement("John Smith", "Eager Java Jr. Dev seeks intern role to grow skills."), ListElement("Emily Johnson", "Java Mid Dev keen on internship to advance career."),
                                                  ListElement("Michael Brown", "Experienced Java Sr. Dev desires intern role."), ListElement("Sarah Davis", "Passionate C++ Jr. Dev seeks hands-on intern role."),
                                                  ListElement("David Wilson", "C++ Mid Dev eager for intern role to excel."), ListElement("Jessica Miller", "Skilled C++ Sr. Dev looking for intern opportunity."),
                                                  ListElement("Daniel Anderson", "Python Jr. Dev seeks internship to develop skills."), ListElement("Laura Moore", "Mid Python Dev eager for an internship to grow."), 
                                                  ListElement("Christopher Taylor", "Seasoned Python Sr. Dev desires intern role."), ListElement("Megan White", "Aspiring Assembly Jr. Dev seeks intern experience."), 
                                                  ListElement("James Harris", "Assembly Mid Dev keen on internship for growth."), ListElement("Amanda Clark", "Senior Assembly Dev seeks intern role for impact.") };
    Statistics statistics;
    StreamBuffer VacancyBuf("VacancyList.bin");
    List VacancyList(VacancyBuf, font, width, height, width / 15.5, height / 4.5);
    statistics.countAllWithVacancies(VacancyBuf);

    StreamBuffer AppliesBuf("AppliesList.bin");
    List AppliesList(AppliesBuf, font, width, height, width / 15.5, height / 4.5);
    statistics.countAppliesCapacity(AppliesBuf);

    StreamBuffer EmployeesBuf("EmployeesList.bin");
    List EmployeesList(EmployeesBuf, font, width, height, width / 15.5, height / 4.5);
    statistics.countEmployeesCapacity(EmployeesBuf);

    StatisticsGraphical statisticsVisual(font, sf::Color(0,0,0), statistics, width / 64.8, width/2.5, height/3);

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

    Button deleteAllData("Delete All Data", font, sf::Color(147, 147, 147), sf::Color(0, 0, 0), width / 6, height / 10, width / 2, height / 2);
    deleteAllData.getTitle().setCharacterSize(width / 64.8);
    deleteAllData.setPosition(width / 2 - deleteAllData.getWidth()/3, height / 2);

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
    int indexOfElementToDelete = -1;
    int indexOfElementToCarry = -1;
    int StopTime = time(NULL);
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
                
                menu.hover(window);
                if (chooseButton == 0 && isInListArea(menu.getMenuBack(), footer)) {
                    VacancyList.hover(window);
                    PlusButton.hover(window);
                }
                if (chooseButton == 1 && isInListArea(menu.getMenuBack(), footer)) {

                    AppliesList.hover(window);
                }
                if (chooseButton == 3 && isInListArea(menu.getMenuBack(), footer)) {

                    EmployeesList.hover(window);

                }
                if (chooseButton == 4) deleteAllData.hover(window);
                break;
            case sf::Event::MouseWheelMoved:
                if (chooseButton == 0 && !VacancyList.getList().empty() && numberOfInput == 0) {
                    float moved = event.mouseWheel.delta*height/50;
                    VacancyList.ChangePosition(moved);
                }
                if (chooseButton == 1 && !AppliesList.getList().empty()) {
                    float moved = event.mouseWheel.delta * height / 50;
                    AppliesList.ChangePosition(moved);
                }
                if (chooseButton == 3 && !AppliesList.getList().empty()) {
                    float moved = event.mouseWheel.delta * height / 50;
                    EmployeesList.ChangePosition(moved);
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  для меню
        for (int i = 0; i < menu.getButtons().size(); i++) {                                                                                  

            if (menu.getButtons()[i].isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                menu.getButtons()[i].setBColor(sf::Color(112, 112, 112));
                
                chooseButton = i;
            }

            else if (menu.getButtons()[i].isMouseOver(window) && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                menu.getButtons()[i].setBColor(sf::Color(130, 130, 130));

            }


        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  для листа вакансий
        if (chooseButton == 0 && isInListArea(menu.getMenuBack(), footer)) {
            for (int i = 0; i < VacancyList.getList().size(); i++) {                                                        

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
                statistics.countAllWithVacancies(VacancyBuf);
                statisticsVisual.update(statistics);

                indexOfElementToDelete = -1;
            }
            else if (isSorted || searchField.getText() != "") {

                indexOfElementToDelete = -1;

            }
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  для листа заявок
        if (chooseButton == 1 && isInListArea(menu.getMenuBack(), footer)) {
            for (int i = 0; i < AppliesList.getList().size(); i++) {                                                       

                if (AppliesList.getList()[i].isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    AppliesList.getList()[i].setBColor(sf::Color(112, 112, 112));
                    indexOfElementToDelete = i;
                }
                else if (AppliesList.getList()[i].isMouseOver(window) && !sf::Mouse::isButtonPressed(sf::Mouse::Left) && indexOfElementToDelete != -1) {

                    AppliesList.getList()[i].setBColor(sf::Color(130, 130, 130));

                }

            }
            if (indexOfElementToDelete != -1 && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                AppliesBuf.deleteEl(indexOfElementToDelete);
                AppliesList.update(AppliesBuf, font, width, height);

                statistics.countAppliesCapacity(AppliesBuf);
                statisticsVisual.update(statistics);

                indexOfElementToDelete = -1;
            }
            for (int i = 0; i < AppliesList.getList().size(); i++) {
                if (AppliesList.getList()[i].isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    AppliesList.getList()[i].setBColor(sf::Color(112, 112, 112));
                    indexOfElementToCarry = i;
                }
                else if (AppliesList.getList()[i].isMouseOver(window) && !sf::Mouse::isButtonPressed(sf::Mouse::Right) && indexOfElementToCarry != -1) {

                    AppliesList.getList()[i].setBColor(sf::Color(130, 130, 130));

                }
            }
            if (indexOfElementToCarry != -1 && !sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

                EmployeesBuf.add(AppliesBuf.getStreamBufferList()[indexOfElementToCarry].getTitle(), AppliesBuf.getStreamBufferList()[indexOfElementToCarry].getDescription());
                AppliesBuf.deleteEl(indexOfElementToCarry);

                statistics.countAppliesCapacity(AppliesBuf);

                AppliesList.update(AppliesBuf, font, width, height);
                EmployeesList.update(EmployeesBuf, font, width, height);

                statistics.countEmployeesCapacity(EmployeesBuf);
                statisticsVisual.update(statistics);

                indexOfElementToCarry = -1;
            }
        }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  для листа вакансий рабочих
        if (chooseButton == 3 && isInListArea(menu.getMenuBack(), footer)) {
            for (int i = 0; i < EmployeesList.getList().size(); i++) {

                if (EmployeesList.getList()[i].isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    EmployeesList.getList()[i].setBColor(sf::Color(112, 112, 112));
                    indexOfElementToDelete = i;
                }
                else if (EmployeesList.getList()[i].isMouseOver(window) && !sf::Mouse::isButtonPressed(sf::Mouse::Left) && indexOfElementToDelete != -1) {

                    EmployeesList.getList()[i].setBColor(sf::Color(130, 130, 130));

                }

            }
            if (indexOfElementToDelete != -1 && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                EmployeesBuf.deleteEl(indexOfElementToDelete);
                EmployeesList.update(EmployeesBuf, font, width, height);

                statistics.countEmployeesCapacity(EmployeesBuf);
                statisticsVisual.update(statistics);

                indexOfElementToDelete = -1;
            }
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    для плюса
        if (chooseButton == 0) {
            if (PlusButton.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                PlusButton.setBColor(sf::Color(112, 112, 112));
                textTitleField.setText("");
                textDescriptionField.setText("");
                numberOfInput = 1;

            }
            else if (PlusButton.isMouseOver(window) && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                PlusButton.setBColor(sf::Color(130, 130, 130));

            }
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

            statistics.countAllWithVacancies(VacancyBuf);
            statisticsVisual.update(statistics);

            numberOfInput = 0;
            dataWasEntered = 0;
        }
        /////////////////////////////////////////////////////////////////////////////////////// настройки
        if (deleteAllData.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            deleteAllData.setBColor(sf::Color(112, 112, 112));
            int i = 0;
            while (!VacancyBuf.getStreamBufferList().empty()) {

                VacancyBuf.deleteEl(i);

            }
            i = 0;
            while (!AppliesBuf.getStreamBufferList().empty()) {

                AppliesBuf.deleteEl(i);

            }
            i = 0;
            while (!EmployeesBuf.getStreamBufferList().empty()) {

                EmployeesBuf.deleteEl(i);

            }
            VacancyBuf.update();
            AppliesBuf.update();
            EmployeesBuf.update();
            VacancyList.update(VacancyBuf, font, width, height);
            AppliesList.update(AppliesBuf, font, width, height);
            EmployeesList.update(EmployeesBuf, font, width, height);
            statistics.countAppliesCapacity(AppliesBuf);
            statistics.countEmployeesCapacity(EmployeesBuf);
            statistics.countAllWithVacancies(VacancyBuf);
            statisticsVisual.update(statistics);
        }
        else if (deleteAllData.isMouseOver(window) && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            deleteAllData.setBColor(sf::Color(130, 130, 130));

        }
        ///////////////////////////////////////////////////////////////////////////////////////
        if (time(NULL) != StopTime) {

            srand((unsigned)time(NULL));
            int randomized = rand() % 100;
            if (randomized < DBOfApplies.size()) {
                
                AppliesBuf.add(DBOfApplies[randomized].getTitle(), DBOfApplies[randomized].getDescription());
                AppliesList.update(AppliesBuf, font, width, height);

                statistics.countAppliesCapacity(AppliesBuf);
                statisticsVisual.update(statistics);

                StopTime = time(NULL);
            }
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
            AppliesList.draw(window);
            window.draw(footer);
            break;
        case 2:
            statisticsVisual.DrawTo(window);
            break;
        case 3:
            EmployeesList.draw(window);
            window.draw(footer);
            break;
        case 4:
            deleteAllData.drawButton(window);
            break;
        default:
            break;
        }
        
        menu.drawMenu(window);
        window.display();
    }

}

bool MainWindow::isInListArea(sf::RectangleShape& higher, sf::RectangleShape& lower)
{
    float mouseY = sf::Mouse::getPosition(window).y;

    float BottomHigherPosY = higher.getGlobalBounds().top + higher.getGlobalBounds().height;
    float TopLowerPosY = lower.getGlobalBounds().top;

    if (mouseY > BottomHigherPosY && mouseY < TopLowerPosY) {

        return true;

    }


    return false;
}
