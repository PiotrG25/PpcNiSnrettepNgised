
#include <gtest/gtest.h>
#include "client.hpp"
#include "restaurant_waiters.hpp"
#include "waiter.hpp"
#include "restaurant_kitchen.hpp"
#include "cook.hpp"
#include "margherita_pizza.hpp"
#include "pepperoni_pizza.hpp"

namespace{
    void ExpectEqualPizzas(const Pizza& expected_pizza, const Pizza& pizza){
        const auto expected_toppings = expected_pizza.GetToppings();
        const auto toppings = pizza.GetToppings();
        EXPECT_EQ(expected_toppings.size(), toppings.size());
        for(const auto& topping : expected_toppings){
            EXPECT_TRUE(std::find(toppings.cbegin(), toppings.cend(), topping) != toppings.cend());
        }
    }
} // namespace

#include <iostream>

TEST(TestCommand, ExpectClientsReceiveRequestedPizzas){
    RestaurantWaiters waiters;
    RestaurantKitchen kitchen;

    std::shared_ptr<Cook> cook = std::make_shared<Cook>(kitchen);
    std::shared_ptr<Waiter> waiter = std::make_shared<Waiter>(kitchen);
    waiters.RegisterWaiter(waiter);

    std::shared_ptr<Client> client_1 = std::make_shared<Client>(waiters);
    client_1->OrderMargherita();
    waiter->PassOrderToKitchen();
    
    std::cout << "test command: " << std::endl;
    std::cout << "has orders: " << kitchen.HasOrders() << std::endl;
    std::cout << "has pizzas: " << kitchen.HasPizzas() << std::endl;
    std::cout << "orders: " << kitchen.orders_.size() << std::endl;
    std::cout << "pizzas: " << kitchen.pizzas_.size() << std::endl;
    
    cook->MakeNext();

    client_1->ExpectPizza();
    auto pizza_1 = client_1->GetPizza();
    ExpectEqualPizzas(MargheritaPizza(), *pizza_1);


    std::shared_ptr<Client> client_2 = std::make_shared<Client>(waiters);
}
