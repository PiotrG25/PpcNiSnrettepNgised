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

## Decorator
A Decorator design pattern implemented as pizza wrappers of pizza

bazel test //structural/decorator:test_decorator

## Facade
Pizza Cook, which is a director in the builder design pattern.
It serves the same role as a facade, simplifying the use of other classes

## Flyweight
Flyweight is a design pattern that helps us save memory, when using multiple instances holding the same information.
In current implementation for every flyweight object we increase memory consumption by 24 bytes, while every heavyweight object increases it by 40 bytes.
With 88 bytes overhead it makes this design pattern useful, after breaking the 6 object barier (232 < 240)

bazel test //structural/flyweight:test_flyweight

# All bazel tests
bazel test //creational/singleton:test_singleton

bazel test //creational/builder:test_builder

bazel test //creational/prototype:test_prototype

bazel test //creational/abstract_factory:test_abstract_factory

bazel test //creational/factory_method:test_factory_method

bazel test //structural/adapter:test_adapter

bazel test //structural/bridge:test_bridge

bazel test //structural/composite:test_composite

bazel test //structural/decorator:test_decorator

bazel test //structural/flyweight:test_flyweight
