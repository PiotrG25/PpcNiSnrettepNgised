"# PpcNiSnrettepNgised" 

# Creational Design Patterns
## Singleton
In two versions one with a unique_ptr as a static class field PointerSingleton 
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

bazel test //creational/prototype:test_prototype

## Abstract Factory
CarPartsFactory as an Abstract Factory

bazel test //creational/abstract_factory:test_abstract_factory

## Factory method
CarFactory

bazel test //creational/factory_method:test_factory_method

# Structural Design Patterns
## Adapter
Two adapters adapting european plugs to american and vice versa

bazel test //structural/adapter:test_adapter

## Bridge
Device and Remote relation allowing us to develop devices and remotes independently from each other

bazel test //structural/bridge:test_bridge

## Composite
A composite design pattern implemented with a simple text to printer formating Printable classes

bazel test //structural/composite:test_composite



# All bazel tests
bazel test //creational/singleton:test_singleton

bazel test //creational/builder:test_builder

bazel test //creational/prototype:test_prototype

bazel test //creational/abstract_factory:test_abstract_factory

bazel test //creational/factory_method:test_factory_method

bazel test //structural/adapter:test_adapter

bazel test //structural/bridge:test_bridge

bazel test //structural/composite:test_composite
