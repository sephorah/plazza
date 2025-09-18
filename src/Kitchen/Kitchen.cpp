/*
** EPITECH PROJECT, 2024
** Kitchen
** File description:
** Plazza
*/

#include "Kitchen/Kitchen.hpp"

Kitchen::Kitchen::Kitchen(args_t& args) : 
    _cookPool(args.cooksNumber), /*, _running(true)*/ _args(args),
    _kitchenFridge(std::make_shared<Fridge>(args.cookingTimeMultiplier)) ,
    _refillThread(_kitchenFridge), _maxNbPizzas(args.cooksNumber * 2),
    _currentNbPizzas(0) {}

Kitchen::Kitchen::~Kitchen() {}

//bool Kitchen::Kitchen::isOrderReady(std::vector<std::shared_ptr<Pizza::IPizza>> orders)
//{
//    for (auto& pizza : orders) {
//        if (pizza->isPizzaDone() == false)
//            return (false);
//    }
//    std::cout << "This order is ready" << std::endl;
//    return (true);
//}

int Kitchen::Kitchen::addOrder(std::vector<std::shared_ptr<Pizza::IPizza>> orders) 
{
    for (long unsigned int i = 0; i < orders.size(); i++) {
        //if (isOrderReady(orders) == true)
        //    return SUCCESS;
        if (this->_currentNbPizzas == this->_maxNbPizzas) {
            //std::cout << "Full kitchen" << std::endl;
            std::vector<std::shared_ptr<Pizza::IPizza>> remainingOrders;

            Process newProcess;
            if (newProcess.getPid() == 0) {
                //std::cout << "CHILD PROCESS CREATED" << std::endl;
                Kitchen newKitchen(_args);
                for (long unsigned int i = _currentNbPizzas; i < orders.size(); i++) {
                    if (orders[i]->isPizzaDone() == false) {
                        //std::cout << "pizza type & size are " << orders[i]->getType() << " - " << orders[i]->getSize() << std::endl;
                        remainingOrders.push_back(orders[i]);
                    }
                }
                newKitchen.addOrder(remainingOrders);
                exit(0);
            }
        }
        //std::cout << "[CURRENT PIZZA TO PUSH: " << _types[orders[i]->getType()] << "]" << std::endl;

        ThreadPool::Task task = createTask(orders[i]);
        this->_cookPool.push(task);
        this->_currentNbPizzas += 1;
    }
    return SUCCESS;
}


ThreadPool::Task Kitchen::Kitchen::createTask(std::shared_ptr<Pizza::IPizza> pizza) 
{
    std::function<void()> taskFunction = [this, pizza]() {
        std::ostringstream readyStr;
        std::string orderIdStr = "[Order " + std::to_string(pizza->getOrderId()) + "] ";
        std::ostringstream registredOrder; 
        
        registredOrder << orderIdStr << pizza << std::endl;
        std::cout << registredOrder.str();
        writeToRecord(registredOrder.str());
        pizza->cook(this->_kitchenFridge);
        // _orderStatus[pizza->getOrderId()] -= (_orderStatus[pizza->getOrderId()] > 0);
        readyStr << orderIdStr << pizza << " is ready!\n";
        this->_currentNbPizzas -= 1;
        std::cout << readyStr.str();
        writeToRecord(readyStr.str());
    };
    return ThreadPool::Task(ThreadPool::TaskType::Execute, taskFunction);
}


int Kitchen::Kitchen::writeToRecord(const std::string& str)
{
    std::ofstream record("record.txt", std::ios::app); // open in append mode
    if (!record.is_open())
        throw KitchenException("Kitchen: failed to open record.txt.");
    record << str << std::endl;
    record.close();
    return SUCCESS;
}

void Kitchen::Kitchen::getState()
{
    //Displays the kitchens status, including the current occupancy of the cooks, as well as theirs
    //stocks of ingredients. using the status command.

    //boucler sur toutes les kicthens
    // std::string cooksOccupancy = std::to_string(this->_cookPool.getNbBusyCooks())
    // + " / " + std::to_string(this->_args.cooksNumber) + " cooks busy.\n" ;
    // std::string ingredientsStocks = this->_kitchenFridge->getStatusFridge();
    
    // this->_detailsMode = true;
    // std::cout << cooksOccupancy << ingredientsStocks;
    std::cout << "Status msg (to do)" << std::endl;
}

std::size_t& Kitchen::Kitchen::getMaxNbPizzas()
{
    return (_maxNbPizzas);
}

std::size_t& Kitchen::Kitchen::getCurrentNbPizzas()
{
    return (_currentNbPizzas);
}