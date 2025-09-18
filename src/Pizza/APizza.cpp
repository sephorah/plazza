/*
** EPITECH PROJECT, 2024
** APizza
** File description:
** Plazza
*/

#include "Pizza/APizza.hpp"
#include <iostream>

Pizza::APizza::APizza(PizzaSize size, int orderId) : _size(size), _isDone(false), _orderId(orderId)
    // _quantity(quantity)
{}


void Pizza::APizza::cook(std::shared_ptr<Kitchen::Fridge> fridge)
{
    //  std::unordered_map<PizzaSize, std::string> sizes = {
    //             {PizzaSize::S, "S"}, {PizzaSize::M, "M"}, {PizzaSize::L, "L"},
    //             {PizzaSize::XL, "XL"}, {PizzaSize::XXL, "XXL"},
    //     };
    //     std::unordered_map<PizzaType, std::string> types = {
    //             {PizzaType::Regina, "Regina"}, {PizzaType::Margarita, "Margarita"},
    //             {PizzaType::Americana, "Americana"}, {PizzaType::Fantasia, "Fantasia"}
    //     };
    // std::unordered_map<Pizza::IngredientType, std::string> ingredients = {
    //             {Pizza::Dough, "Dough"},
    //             {Pizza::Tomato, "Tomato"},
    //             {Pizza::Gruyere, "Gruyere"},
    //             {Pizza::Ham, "Ham"},
    //             {Pizza::Mushrooms, "Mushrooms"},
    //             {Pizza::Steak, "Steak"},
    //             {Pizza::Eggplant, "Eggplant"},
    //             {Pizza::GoatCheese, "Goat cheese"},
    //             {Pizza::ChiefLove, "Chief love"}
    //         };

    
    // std::cout << "Before cooking " << types[this->getType()] << " " <<
    // sizes[this->getSize()] <<  std::endl;


    // for (int i = 0; i < this->_quantity; i++) {
        for (const auto &ingredient : this->_listIngredients) {
    //         std::cout << "Taking " << ingredients[ingredient] << " for ..." << types[this->getType()] << " " <<
    // sizes[this->getSize()] <<  std::endl;
            fridge->takeIngredient(ingredient);
    //         std::cout << "Took " << ingredients[ingredient] << "..." << types[this->getType()] << " " <<
    // sizes[this->getSize()] <<  std::endl;
        }
    // std::cout << "Took all ingredients for " << types[this->getType()] << " " <<
    // sizes[this->getSize()] << std::endl;
    std::this_thread::sleep_for(this->_cookingTime);
    // std::cout << "Cooking time done for " << types[this->getType()] << " " <<
    // sizes[this->getSize()] <<  std::endl;
    // }
    // this->_isDone = true;
    // std::cout << "After cooking Pizza " << this->getType() << " " << this->getSize() << std::endl;
}

PizzaSize Pizza::APizza::getSize()
{
    return this->_size;
}

std::chrono::milliseconds Pizza::APizza::getCookingTime()
{
    return this->_cookingTime;
}

int Pizza::APizza::getOrderId()
{
    return this->_orderId;
}

bool Pizza::APizza::isPizzaDone()
{
    return this->_isDone;
}

std::istream& Pizza::operator>>(std::istream& is, Pizza::PizzaArgs& args) 
{
    std::string typeStr;
    std::string sizeStr;

    static std::unordered_map<std::string, PizzaType> types = {
        {"regina", PizzaType::Regina}, 
        {"margarita", PizzaType::Margarita},
        {"americana", PizzaType::Americana}, 
        {"fantasia", PizzaType::Fantasia},
        {"monza", PizzaType::Monza}
    };

    static std::unordered_map<std::string, PizzaSize> sizes = {
        {"s", PizzaSize::S}, 
        {"m", PizzaSize::M}, 
        {"l", PizzaSize::L}, 
        {"xl", PizzaSize::XL}, 
        {"xxl", PizzaSize::XXL}
    };
    is >> typeStr >> sizeStr;
    auto typeIt = types.find(typeStr);
    if (typeIt == types.end()) {
        throw std::invalid_argument("Invalid PizzaType: " + typeStr);
    }
    args._type = typeIt->second;

    auto sizeIt = sizes.find(sizeStr);
    if (sizeIt == sizes.end()) {
        throw std::invalid_argument("Invalid PizzaSize: " + sizeStr);
    }
    args._size = sizeIt->second;
    return is;
}

// int Pizza::APizza::getQuantity()
// {
//     return this->_quantity;
// }