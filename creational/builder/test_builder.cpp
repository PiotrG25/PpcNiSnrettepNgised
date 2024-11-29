
#include <gtest/gtest.h>
#include <algorithm>
#include "creational/builder/pizza_cook.hpp"
#include "creational/builder/margherita_builder.hpp"
#include "creational/builder/diavola_builder.hpp"
#include "creational/builder/napoli_builder.hpp"
#include "creational/builder/vege_builder.hpp"

namespace{
	enum class BuilderType{Margherita, Diavola, Napoli, Vege};
	
	std::unique_ptr<PizzaBuilder> MakePizzaBuilder(BuilderType type){
		switch(type){
			case BuilderType::Margherita:
				return std::make_unique<MargheritaBuilder>();
			case BuilderType::Diavola:
				return std::make_unique<DiavolaBuilder>();
			case BuilderType::Napoli:
				return std::make_unique<NapoliBuilder>();
			case BuilderType::Vege:
				return std::make_unique<VegeBuilder>();
			default:
				return nullptr;
		}
	}
	
	using IsGlutenFree = bool;
	using IsVegan = bool;
	using PizzaTestParamType = std::tuple<
		BuilderType,
		Pizza::Sauce,
		std::vector<Pizza::Cheese>,
		std::vector<Pizza::Topping>,
		IsGlutenFree,
		IsVegan
	>;

	std::vector<PizzaTestParamType> MakeTestParameters(bool double_cheese, bool double_toppings){
		std::vector<PizzaTestParamType> params{
			{
				BuilderType::Margherita,
				Pizza::Sauce::Tomato,
				(double_cheese ? std::vector<Pizza::Cheese>{Pizza::Cheese::Mozzarella, Pizza::Cheese::Mozzarella} :
				 std::vector<Pizza::Cheese>{Pizza::Cheese::Mozzarella}),
				(double_toppings ? std::vector<Pizza::Topping>{Pizza::Topping::Basil, Pizza::Topping::OliveOil,
				 Pizza::Topping::Basil, Pizza::Topping::OliveOil} :
				 std::vector<Pizza::Topping>{Pizza::Topping::Basil, Pizza::Topping::OliveOil}),
				false,
				false
			},
			{
				BuilderType::Diavola,
				Pizza::Sauce::Tomato,
				(double_cheese ? std::vector<Pizza::Cheese>{Pizza::Cheese::Mozzarella, Pizza::Cheese::Mozzarella} :
				 std::vector<Pizza::Cheese>{Pizza::Cheese::Mozzarella}),
				(double_toppings ? std::vector<Pizza::Topping>{Pizza::Topping::SpicySalami, Pizza::Topping::RedChiliFlakes, Pizza::Topping::BlackOlives,
				 Pizza::Topping::SpicySalami, Pizza::Topping::RedChiliFlakes, Pizza::Topping::BlackOlives} :
				 std::vector<Pizza::Topping>{Pizza::Topping::SpicySalami, Pizza::Topping::RedChiliFlakes, Pizza::Topping::BlackOlives}),
				false,
				false
			},
			{
				BuilderType::Napoli,
				Pizza::Sauce::Tomato,
				(double_cheese ? std::vector<Pizza::Cheese>{Pizza::Cheese::Mozzarella, Pizza::Cheese::Mozzarella} :
				 std::vector<Pizza::Cheese>{Pizza::Cheese::Mozzarella}),
				(double_toppings ? std::vector<Pizza::Topping>{Pizza::Topping::Anchovies, Pizza::Topping::Capers,
				 Pizza::Topping::BlackOlives, Pizza::Topping::Oregano,
				 Pizza::Topping::Anchovies, Pizza::Topping::Capers,
				  Pizza::Topping::BlackOlives, Pizza::Topping::Oregano} :
				 std::vector<Pizza::Topping>{Pizza::Topping::Anchovies, Pizza::Topping::Capers,
				  Pizza::Topping::BlackOlives, Pizza::Topping::Oregano}),
				false,
				false
			},
			{
				BuilderType::Vege,
				Pizza::Sauce::SpicyArrabbiataSauce,
				(double_cheese ? std::vector<Pizza::Cheese>{Pizza::Cheese::VeganCheese, Pizza::Cheese::VeganCheese} :
				 std::vector<Pizza::Cheese>{Pizza::Cheese::VeganCheese}),
				(double_toppings ? std::vector<Pizza::Topping>{Pizza::Topping::Jalapenos, Pizza::Topping::RedOnion,
				 Pizza::Topping::BlackOlives, Pizza::Topping::RoastedGarlic,
				 Pizza::Topping::Jalapenos, Pizza::Topping::RedOnion,
				 Pizza::Topping::BlackOlives, Pizza::Topping::RoastedGarlic} :
				 std::vector<Pizza::Topping>{Pizza::Topping::Jalapenos, Pizza::Topping::RedOnion,
				 Pizza::Topping::BlackOlives, Pizza::Topping::RoastedGarlic}),
				true,
				true
			}
		};
		return params;
	}
} // namespace

class PizzaTest : public ::testing::TestWithParam<PizzaTestParamType>{};

TEST_P(PizzaTest, ExpectPizzaIngredientsInPizza){
	auto param = GetParam();
	auto pizza_builder = MakePizzaBuilder(std::get<0>(param));
	PizzaCook pc(std::move(pizza_builder));
	std::unique_ptr<Pizza> pizza = pc.MakePizza(Pizza::Size::Large, Pizza::Dough::Thin);
	
	auto expected_sauce = std::get<1>(param);
	EXPECT_EQ(expected_sauce, pizza->GetSauce());
	
	auto expected_cheeses = std::get<2>(param);
	auto cheeses = pizza->GetCheeses();
	for(const auto& expected_cheese : expected_cheeses){
		EXPECT_EQ(std::count(expected_cheeses.cbegin(), expected_cheeses.cend(), expected_cheese),
				  std::count(cheeses.cbegin(), cheeses.cend(), expected_cheese));
	}
	
	auto expected_toppings = std::get<3>(param);
	auto toppings = pizza->GetToppings();
	for(const auto& expected_topping : expected_toppings){
		EXPECT_EQ(std::count(expected_toppings.cbegin(), expected_toppings.cend(), expected_topping),
				  std::count(toppings.cbegin(), toppings.cend(), expected_topping));
	}
	
	auto expected_is_gluten_free = std::get<4>(param);
	auto is_gluten_free = pizza->IsGlutenFree();
	EXPECT_EQ(expected_is_gluten_free, is_gluten_free);
	
	auto expected_is_vegan = std::get<5>(param);
	auto is_vegan = pizza->IsVegan();
	EXPECT_EQ(expected_is_vegan, is_vegan);
}

INSTANTIATE_TEST_SUITE_P(TestIngredientsOfManyPizzas, PizzaTest, testing::ValuesIn(MakeTestParameters(false, false)));


class DoubleCheesePizzaTest : public ::testing::TestWithParam<PizzaTestParamType>{};

TEST_P(DoubleCheesePizzaTest, ExpectPizzaIngredientsInPizza){
	auto param = GetParam();
	auto pizza_builder = MakePizzaBuilder(std::get<0>(param));
	PizzaCook pc(std::move(pizza_builder));
	std::unique_ptr<Pizza> pizza = pc.MakeDoubleCheesePizza(Pizza::Size::Large, Pizza::Dough::Thin);
	
	auto expected_sauce = std::get<1>(param);
	EXPECT_EQ(expected_sauce, pizza->GetSauce());
	
	auto expected_cheeses = std::get<2>(param);
	auto cheeses = pizza->GetCheeses();
	for(const auto& expected_cheese : expected_cheeses){
		EXPECT_EQ(std::count(expected_cheeses.cbegin(), expected_cheeses.cend(), expected_cheese),
				  std::count(cheeses.cbegin(), cheeses.cend(), expected_cheese));
	}
	
	auto expected_toppings = std::get<3>(param);
	auto toppings = pizza->GetToppings();
	for(const auto& expected_topping : expected_toppings){
		EXPECT_EQ(std::count(expected_toppings.cbegin(), expected_toppings.cend(), expected_topping),
				  std::count(toppings.cbegin(), toppings.cend(), expected_topping));
	}
	
	auto expected_is_gluten_free = std::get<4>(param);
	auto is_gluten_free = pizza->IsGlutenFree();
	EXPECT_EQ(expected_is_gluten_free, is_gluten_free);
	
	auto expected_is_vegan = std::get<5>(param);
	auto is_vegan = pizza->IsVegan();
	EXPECT_EQ(expected_is_vegan, is_vegan);
}

INSTANTIATE_TEST_SUITE_P(TestIngredientsOfManyPizzas, DoubleCheesePizzaTest, testing::ValuesIn(MakeTestParameters(true, false)));


class DoubleToppingsPizzaTest : public ::testing::TestWithParam<PizzaTestParamType>{};

TEST_P(DoubleToppingsPizzaTest, ExpectPizzaIngredientsInPizza){
	auto param = GetParam();
	auto pizza_builder = MakePizzaBuilder(std::get<0>(param));
	PizzaCook pc(std::move(pizza_builder));
	std::unique_ptr<Pizza> pizza = pc.MakeDoubleToppingsPizza(Pizza::Size::Large, Pizza::Dough::Thin);
	
	auto expected_sauce = std::get<1>(param);
	EXPECT_EQ(expected_sauce, pizza->GetSauce());
	
	auto expected_cheeses = std::get<2>(param);
	auto cheeses = pizza->GetCheeses();
	for(const auto& expected_cheese : expected_cheeses){
		EXPECT_EQ(std::count(expected_cheeses.cbegin(), expected_cheeses.cend(), expected_cheese),
				  std::count(cheeses.cbegin(), cheeses.cend(), expected_cheese));
	}
	
	auto expected_toppings = std::get<3>(param);
	auto toppings = pizza->GetToppings();
	for(const auto& expected_topping : expected_toppings){
		EXPECT_EQ(std::count(expected_toppings.cbegin(), expected_toppings.cend(), expected_topping),
				  std::count(toppings.cbegin(), toppings.cend(), expected_topping));
	}
	
	auto expected_is_gluten_free = std::get<4>(param);
	auto is_gluten_free = pizza->IsGlutenFree();
	EXPECT_EQ(expected_is_gluten_free, is_gluten_free);
	
	auto expected_is_vegan = std::get<5>(param);
	auto is_vegan = pizza->IsVegan();
	EXPECT_EQ(expected_is_vegan, is_vegan);
}

INSTANTIATE_TEST_SUITE_P(TestIngredientsOfManyPizzas, DoubleToppingsPizzaTest, testing::ValuesIn(MakeTestParameters(false, true)));
