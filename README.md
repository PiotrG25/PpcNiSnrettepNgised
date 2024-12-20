"# PpcNiSnrettepNgised" 

# Creational Design Patterns
## Singleton
In two versions one with a pointer as a static class field PointerSingleton 
and the other with static local instance variable, the MeyersSingleton.

Since C++11 local static variables are initialized in a thread safe way, 
making the MeyersSingleton the best option for people desperate enough to use anti patterns.

bazel test //creational/singleton:test_singleton

## Builder
Pizza is an object to be built

PizzaBuilder is an object builder, with many builder derivatives

and PizzaCook is a builder director

bazel test //creational/builder:test_builder

## Prototype
In C++ prototype design pattern is partialy present in the form of copy constructor and copy assignment operator

copy constructor is generated by default if the class doesn't define: copy constructor, move constructor, move assignment operator, or destructor

copy assignment operator is generated by default if the class doesn't define: copy assignment operator, move constructor, move assignment operator, or destructor

The object created by the default copy constructor and the default copy assignment operator is a shalow copy. In order to work with deep copy, the developer needs to define his own copy semantics

In order to use copy constructor or copy assignment oerators, the code needs to know type of object being copied.

This dependency can be removed by introducing Prototype class with virtual clone method, where each deriving class overrides it and provides a copy of itself as a result.

bazel test //creational/prototype:test_prototype

## Abstract Factory
CarPartsFactory as an Abstract Factory

bazel test //creational/abstract_factory:test_abstract_factory

## Factory method
CarFactory as a Factory Method using CarPartsFactory

bazel test //creational/factory_method:test_factory_method

# Structural Design Patterns
## Adapter
Two adapters adapting european plugs to american and vice versa

bazel test //structural/adapter:test_adapter


# All bazel tests
bazel test //creational/singleton:test_singleton

bazel test //creational/builder:test_builder

bazel test //creational/prototype:test_prototype

bazel test //creational/abstract_factory:test_abstract_factory

bazel test //creational/factory_method:test_factory_method

bazel test //structural/adapter:test_adapter
