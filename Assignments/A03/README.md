* Class

```
A class can be defined as a template/blueprint  
A Class is a user defined data-type which has data members and member functions.  
that describes the behavior that the object of its type support.
```

* Object

```
An object is an instance of a class.  
When a class is defined,  
no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated.
Objects have states and behaviors.  
Example: A dog has - color, name, breed as well as behaviors – wagging the tail, barking, eating.
```

* Method

```
A method is a member function of a class,  
however they are commonly referred to as member functions rather than methods.
```

* Abstraction

```
Abstraction means displaying only essential information and hiding the details.  
Data abstraction refers to providing only essential information about the data to the outside world,  
hiding the background details or implementation.
```

* Encapsulation

```
Encapsulation is wrapping the variables and code acting on the data (methods) together as a single unit.  
In encapsulation, the variables of a class will be hidden from other classes,  
and can be accessed only through the methods of their current class.  
Therefore, it is also known as data hiding.
```

* Polymorphism

```
Polymorphism is the ability of an object to take on many forms.  
Polymorphism occurs when a parent class reference is used to refer to a child class object.
```

* Overloading

```
Makes operators work for user defined classes. For example,  
an operator ‘+’ in a class like String can concatenate two strings by just using +.  
Other example classes where arithmetic operators may be overloaded are:  
1. Complex Number,  
2. Fractional Number,  
3. Big Integer...
```

* Attributes / Properties

```

```

* Class Variable

```
Static variables in a Function: When a variable is declared as static,  
space for it gets allocated for the lifetime of the program. Even if the function is called multiple times,  
space for the static variable is allocated only once,  
and the value of variable in the previous call gets carried through the next function call.    

Static variables in a class:  
The variables declared as static are initialized only once,  
as they are allocated space in separate static storage so,  
the static variables in a class are shared by the objects.  
There can not be multiple copies of same static variables for different objects.  
Also because of this reason static variables can not be initialized using constructors.
```

* Instance Variable

```
Instance variable is used by Objects to store their states.  
Variables which are defined without the STATIC keyword,  
and are Outside any method declaration are Object specific and are known as instance variables.  
They are called so because their values are instance specific.
```

* Member Variable

```

```

* Inheritance

```
Inheritance can be defined as the process where one class acquires the properties (methods and fields) of another.  
The class which inherits the properties of other is known as subclass (derived class, child class),  
and the class whose properties are inherited is known as superclass (base class, parent class).
```

* Multiple Inheritance

```
Multiple Inheritance is a feature of where a class can inherit from more than one classes.  
The constructors of inherited classes are called in the same order in which they are inherited.  
For example, in the following program, B’s constructor is called before A’s constructor.
```

* Composition

```

```
