#include "Menu.hpp"
//dtor
Menu::~Menu(){
    for(int i = 0 ;i < 3;i++)
        delete allChainStores[i];
}
//Print Menu
void Menu::PrintMenu(){
    while (1)
    {
        fflush(stdin);
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "Welcome, What would you like to do?" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "[1] - Add Shop" << endl;
        cout << "[2] - Add Employee" << endl;
        cout << "[3] - Shopping" << endl;
        cout << "[4] - Return Item" << endl;
        cout << "[5] - Print Chain" << endl;
        cout << "[6] - Sum Salaries Chain" << endl;
        cout << "[7] - Sum Salaries Shop" << endl;
        cout << "[8] - Print Shop" << endl;
        cout << "[9] - Print Employee" << endl;
        cout << "[10] - Exit" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        
        int choice;
        cin>>choice;
        
        switch (choice)
        {
            case 1:
                addShope();
                break;
            case 2:
                addEmployee();
                break;
            case 3:
                shopping();
                break;
            case 4:
                returnItem();
                break;
            case 5:
                printChain();
                break;
            case 6:
                sumSalariesChain();
                break;
            case 7:
                sumSalariesShop();
                break;
            case 8:
                printShope();
                break;
            case 9:
                printEmployee();
                break;
            case 10:
                cout << "Thank you, Goodbye." << endl;
                return;
                break;
                default:
                cout << "No such option , sorry. Choose again please." << endl;
        }
    }
}
//default arrays
void Menu::defaultArr(){
    Stores* newStore = new Stores(65,"Golbary");
    
    Stores* newFoodStore = new Stores[2];
    newFoodStore[0] =  Stores(3,"SuperSal");
    newFoodStore[1] =  Stores(81,"SuperSal");
    
    Stores* newClothingStore = new Stores[1];
    newClothingStore[0] =  Stores(3,"TNT");
    
    allChainStores[0] = new ClothingChain("Golbary",newStore,1,"Moshe Gabay");
    allChainStores[1] =  new FoodChain("SuperSal",newFoodStore,2,4);
    allChainStores[2] =  new ClothingChain("TNT",newClothingStore,1,"Ruti Sulemani");
}
//adding shop
void Menu::addShope(){
    string chainName;
    int shopId;
    int j = 0;
    cout<<"Please Enter Chain Name And Shope Id: "<<endl;
    cin>>chainName>>shopId;
    Stores* newStore = new Stores(shopId,chainName);
    for (int i = 0 ; i<3; i++) {
        // find the chain for this store
        if(allChainStores[i]->getName() == chainName) {
            if (allChainStores[i]->checkUniqueness(*newStore)) {
                int numStores = allChainStores[i]->getAmountAllStores();
                // allocate array bigger by 1
                Stores* tempStoreArr = new Stores[numStores+ 1];
                Stores* temp =allChainStores[i]->getAllStores();
                for (j = 0; j<numStores ;  j++) {
                    tempStoreArr[j] = temp[j];
                }
                tempStoreArr[j] = *newStore;
                allChainStores[i]->setStores(tempStoreArr);
                cout<<"Shop Add!"<<endl;
                allChainStores[i]->incAmountAllStores();
                
                break;
            }
            
        }
    }
}
//adding employee
void Menu::addEmployee(){
    string employeeName = "none",chainName = "none";
    int id= 0,jobPercentage = 0,basicSalary = 0,shopId = 0,k = 0,j = 0 ;
    char type = 'Z';
    cout<<"Please Enter Employee's Name,Id,Type,Job Percentage,Basic Salary And Store's Chain Name, Stores id: "<<endl;
    cin>>employeeName>>id>>type>>jobPercentage>>basicSalary>>chainName>>shopId;
    for (int i = 0 ; i<3; i++) {
        // find the chain
        if(allChainStores[i]->getName() == chainName) {
            //if we got to this line than this is the chain in which the employee want to work
            if(!allChainStores[i]->workInOnlyOneStore(id)){
                cout<<"An Employee Can Not Work In Two Stores!"<<endl;
                return;
            }
            int totalNumStores =allChainStores[i]->getAmountAllStores();
            Stores* allStoresInChain = allChainStores[i]->getAllStores();
            for (j = 0; j<totalNumStores; j++) {
                Stores* currStore =&allStoresInChain[j];
                if((*currStore).getID() == shopId){
                    Employee* fresh = nullptr;
                    if (type == 'A') {
                        fresh = new Branch_Manager(employeeName,id,jobPercentage ,basicSalary);
                    }
                    if (type == 'B') {
                        fresh = new Senior_Seller(employeeName,id,jobPercentage ,basicSalary);
                    }
                    if (type == 'C') {
                        fresh = new Junior_seller(employeeName,id,jobPercentage ,basicSalary);
                    }
                    if (type == 'D') {
                        fresh = new Cashiers_Supervisor(employeeName,id,jobPercentage ,basicSalary);
                    }
                    // insert the new array into the store
                    currStore->setEmployee(fresh);
                    break;
                    
                }
            }
            
        }
    }
}

//adding to customers list the amount of purchase by shopping
void Menu::shopping(){
    int shopId,employeeId,value;
    string chainName;
    cout<<"Enter Shop Id,Chain Name,Value And Employee Id: "<<endl;
    cin>>shopId>>chainName>>value>>employeeId;
    for (int i = 0 ; i<3; i++) {
        if(allChainStores[i]->getName() == chainName) {
            int amountOfStores =allChainStores[i]->getAmountAllStores();
            Stores* allStoresInChain =allChainStores[i]->getAllStores();
            for (int j = 0; j<amountOfStores; j++) {
                if(allStoresInChain[j] == shopId){
                    int employeeTotal = allStoresInChain[j].getAmountOfWorkers();
                    Employee** allEmployessInStore =allStoresInChain[j].getEmployee();
                    for (int k = 0; k<employeeTotal; k++) {
                        if(allEmployessInStore[k]->getID() == employeeId){
                            Employee* emp =allChainStores[i]->getAllStores()[j].getEmployee()[k];
                            if(typeid(*emp) == typeid(Senior_Seller)){
                                Seller* sen = dynamic_cast<Seller*> (emp);
                                sen->addCustomer(value);
                            }
                            if (typeid(*emp) == typeid(Junior_seller)) {
                                Seller* sen = dynamic_cast<Seller*> (emp);
                                sen->addCustomer(value);
                            }
                        }
                    }
                    
                }
            }
        }
    }
}
//adding to the Canceled Transaction array
void Menu::returnItem(){
    int shopId,employeeId,value;
    string chainName;
    cout<<"Enter Shop Id,Chain Name,Value And Employee Id: "<<endl;
    cin>>shopId>>chainName>>value>>employeeId;
    for (int i = 0 ; i<3; i++) {
        if(allChainStores[i]->getName() == chainName) {
            int amountOfStores =allChainStores[i]->getAmountAllStores();
            Stores* allStoresInChain =allChainStores[i]->getAllStores();
            for (int j = 0; j<amountOfStores; j++) {
                
                if(allStoresInChain[j] == shopId){
                    int employeeTotal = allStoresInChain[j].getAmountOfWorkers();
                    Employee** allEmployessInStore =allStoresInChain[j].getEmployee();
                    for (int k = 0; k<employeeTotal; k++) {
                        if(allEmployessInStore[k]->getID() == employeeId){
                            Employee* emp = allEmployessInStore[k];
                            if(typeid(*emp) == typeid(Senior_Seller) ){
                                Senior_Seller* sen = dynamic_cast<Senior_Seller*> (emp);
                                sen->addCanceledTransaction(value);
                            }
                        }
                    }
                    
                }
            }
        }
    }
}
//print all of the chain
void Menu::printChain(){
    string chainName;
    cout<<"Enter Chain Name: "<<endl;
    cin>>chainName;
    for (int i = 0 ; i<3; i++) {
        if(allChainStores[i]->getName() == chainName) {
            allChainStores[i]->print();
        }
    }
}
//printing the total amount of salaries on the chain
void Menu::sumSalariesChain(){
    string chainName;
    int sum = 0;
    cout<<"Enter Chain Name: "<<endl;
    cin>>chainName;
    for (int i = 0 ; i<3; i++) {
        if(allChainStores[i]->getName() == chainName){
            for (int j = 0 ; j<allChainStores[i]->getAmountAllStores(); j++) {
                    for (int k = 0; k < allChainStores[i]->getAllStores()[j].getAmountOfWorkers(); k++){
                         sum = allChainStores[i]->getAllStores()[j].getEmployee()[k]->salaryCalculation()+ sum;
                    }
            }
        }
    }
    cout<<" The Sum of the Salaries in the Chain is:  "<<sum<<endl;
    
}
//printing the total amount of salaries in the store
void Menu::sumSalariesShop(){
    string chainName;
    int id,sum = 0;
    cout<<"Enter Chain Name and Shop's Id: "<<endl;
    cin>>chainName>>id;
    for (int i = 0 ; i<3; i++) {
        if(allChainStores[i]->getName() == chainName){
            for (int j = 0 ; j<allChainStores[i]->getAmountAllStores(); j++) {
                if(allChainStores[i]->getAllStores()[j].getID() == id) {
                    for (int k = 0; k < allChainStores[i]->getAllStores()[j].getAmountOfWorkers(); k++){
                         sum = allChainStores[i]->getAllStores()[j].getEmployee()[k]->salaryCalculation()+ sum;
                    }
                    cout<<" The Sum of the Salaries in the Shop is:  "<<sum<<endl;
                }
            }
        }
    }
}
//print all shop details
void Menu::printShope(){
    string chainName;
    int id;
    cout<<"Enter id of the store and the cahin name: "<<endl;
    cin>>id>>chainName;
    for (int i = 0 ; i<3; i++) {
        if(allChainStores[i]->getName() == chainName){
            for (int j = 0 ; j<allChainStores[i]->getAmountAllStores(); j++) {
                if(allChainStores[i]->getAllStores()[j].getID() == id) {
                        allChainStores[i]->getAllStores()[j].print();
                }
            }
        }
    }
}
//print the employees details
void Menu::printEmployee(){
    string chainName;
    int id;
    cout<<"Enter Employee id and Chain Name: "<<endl;
    cin>>id>>chainName;
    for (int i = 0 ; i<3; i++) {
        if(allChainStores[i]->getName() == chainName){
            for (int j = 0 ; j<allChainStores[i]->getAmountAllStores(); j++) {
                    for (int k = 0; k < allChainStores[i]->getAllStores()[j].getAmountOfWorkers(); k++){
                        if(allChainStores[i]->getAllStores()[j].getEmployee()[k]->getID() == id){
                            allChainStores[i]->getAllStores()[j].getEmployee()[k]->print();
                        }
                    }
            }
        }
    }
}
