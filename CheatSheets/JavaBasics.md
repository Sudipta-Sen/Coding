# Java Basics to Advance

## Table of Contents
1. [OOPS Concepts](#oops-concepts)
> a. [Overwiew Of OOPS](#overview-of-oops)<br>
> b. [Objects and Classes](#objects-and-classes)<br>
> c. [Pillar of OOPS](#pillars-of-oops)
>> i. [Abstraction](#abstraction)<br>
>> ii. [Encapsulation](#encapsulation)<br>
>> iii. [Inheritance](#inheritance)<br>
>> iv. [Polymorphism](#polymorphism)<br>

> d. [Types of inheritance](#types-of-inheritance)<br>
>> i. [Single Inheritance](#1-single-inheritance)<br>
>> ii. [Multilevel Inheritance](#2-multilevel-inheritance)<br>
>> iii. [Hierarchical Inheritance](#3-hierarchical-inheritance)<br>
>> iv. [Multiple Inheritance Through Interfaces](#4-multiple-inheritance-through-interfaces)<br>
>> v. [Diamond Problem](#diamond-problem)<br>

> e. [Types of polymorphism](#types-of-polymorphism)<br>
>> i. [Compile Time](#1-compile-time-polymorphism-static-binding--method-overloading)<br>
>> ii. [Runtime Polymorphism](#2-runtime-polymorphism-dynamic-binding--method-overriding)<br>

> f. [Is-a and has-a relationship](#is-a-and-has-a-relationship)<br>
>> i. [Is-a relationship](#is-a-relationship-inheritance)<br>
>> ii. [Has-a relationship](#has-a-relationship-composition)<br>
>>> -> [Weak has-a relationship](#weak-has-a-relationship-aggregation)<br>
>>> -> [Strong has-a relationship](#strong-has-a-relationship-composition)<br>
2. [Java & Its ecosystem](#java--its-ecosystem-wora-jvm-jre-jdk)<br>
>> a. [WORA](#wora-write-once-run-anywhere)<br>
>> b. [JVM](#jvm-java-virtual-machine)<br>
>> c. [JDK](#jdk-java-development-kit)<br>
>> d. [JRE](#jre-java-runtime-environment)<br>
>> e. [Analogy](#real-world-analogy)<br>
>> f. [Platform Independence](#how-java-achieves-platform-independence)<br>


## OOPS Concepts

### Overview Of OOPS
- OOPS mean Object-Oriented Programming
- Here Object means real world entity like Car, Bike etc. Every real world entity has two things 
    - Behaviour or Functionality 
    - Properties or State
- Procedural Programming vs OOPS

    | ***Aspect***  | ***Procedural Programming***   | OOPS          |
    |---------------------|--------------------|--------------------------|
    | Structure           | Program is structured and divided into parts as procedures (methods)       | Code is structured around classes and objects      |
    | Core Concept        | Functions and step-by-step instructions    | Objects and classes representing entities    |
    | Data                | Data is passed to functions                      | Data is encapsulated within objects    |
    | Reusability         | Difficult; requires duplicate or refactored code | Promotes reuse through inheritance and composition |
    | Abstraction         | Limited, Overloading, Inheritence, code reusability, data hiding not possible     | High; supports abstraction via interfaces/classes, Overloading, Inheritence, data hiding, code reusability is possible  |
    | Example             | C, Pascal, FORTRAN | Java, C++, Python | 

    - Procedural Style in Java (Not idiomatic Java, but to illustrate)
        ```java
        public class BankProcedural {
            static int balance = 0;

            public static void deposit(int amount) {
                balance += amount;
            }

            public static void withdraw(int amount) {
                if (amount <= balance) {
                    balance -= amount;
                } else {
                    System.out.println("Insufficient funds");
                }
            }

            public static void checkBalance() {
                System.out.println("Balance: " + balance);
            }

            public static void main(String[] args) {
                deposit(1000);
                withdraw(200);
                checkBalance();
            }
        }
        ```
    
    - Object-Oriented Style in Java (Preferred Java way)
        ```Java
        public class BankAccount {
            private int balance;

            public void deposit(int amount) {
                balance += amount;
            }

            public void withdraw(int amount) {
                if (amount <= balance) {
                    balance -= amount;
                } else {
                    System.out.println("Insufficient funds");
                }
            }

            public void checkBalance() {
                System.out.println("Balance: " + balance);
            }

            public static void main(String[] args) {
                BankAccount account = new BankAccount();
                account.deposit(1000);
                account.withdraw(200);
                account.checkBalance();
            }
        }
        ```

### Objects and Classes

What is a Class?

- A **class** is a blueprint/template for creating **objects**.
- It defines **fields (variables)** and **methods (functions)** that describe the behavior and state of the object.
    ```java
    class Student {
        // Fields (attributes, properties)
        int id;
        String name;

        // Methods (behavior)
        void display() {
            System.out.println(id + " " + name);
        }
    }
    ```

What is an Object?
- An object is an instance of a class.
- Object has 2 things:
    - Behaviour or Functionality (methods in class)
    - Properties or State (variables in class)
- It contains **actual values** and can access the class’s methods and fields.

Syntax to Create an Object
```Java
ClassName obj = new ClassName();
```

### Pillars Of OOPS

OOPS is based on four fundamental principles. We’ll understand these principles of OOPS  using a **single real-world example**: a `Vehicle` system with `Car` and `Bike`.

#### Encapsulation

Wrapping data (variables) and methods (functions) together in a single unit (class), and restricting direct access to some of the object's components.

```java
class Vehicle {
    private int speed;
    private int fuel;

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public int getSpeed() {
        return speed;
    }

    public void refuel(int liters) {
        this.fuel += liters;
    }
}
```

We protect `speed` and `fuel` fields using private, and provide `public` methods to access them safely.

#### Abstraction

Hiding complex internal details and showing only the essential features to the user.

```java
class Vehicle {
    void startEngine(){
        // process of starting a engine
    }
}
```

`Vehicle` gives a high-level method `startEngine()` to start the engine, hiding or abstracting the details of how vehicle starts.

#### Inheritance

Mechanism where one class (child) inherits fields and methods from another class (parent), promoting code reuse.

```Java
class Car extends Vehicle {
    void startEngine() {
        System.out.println("Car engine started with key.");
    }
}

class Bike extends Vehicle {
    void startEngine() {
        System.out.println("Bike engine started with kick.");
    }
}
```

`Car` and `Bike` share behavior from `Vehicle`, avoiding code duplication.

#### Polymorphism

The ability of a single method or object to take many forms — typically by method **overriding (runtime)** or **overloading (compile-time)**.

Poly means **Many** and Morphism means **Form**.

```Java
public class Main {
    public static void main(String[] args) {
        Vehicle v1 = new Car();
        Vehicle v2 = new Bike();

        v1.startEngine();  // Output: Car engine started with key.
        v2.startEngine();  // Output: Bike engine started with kick.
    }
}
```

The same method `startEngine()` behaves differently depending on the object’s runtime type.

### Types of Inheritance

Inheritance is one of the core concepts of OOPS. It allows one class to acquire the properties (fields) and behaviors (methods) of another class.

#### 1. Single Inheritance
A subclass inherits from a single superclass.


```java
class Animal {
    void eat() {
        System.out.println("This animal eats food.");
    }
}

class Dog extends Animal {
    void bark() {
        System.out.println("Dog barks.");
    }
}
```

```yaml
Animal
  |
  v
Dog
```

#### 2. Multilevel Inheritance
A class inherits from a class, which in turn inherits from another class.
```java
class Animal {
    void eat() {
        System.out.println("Eating...");
    }
}

class Dog extends Animal {
    void bark() {
        System.out.println("Barking...");
    }
}

class Puppy extends Dog {
    void weep() {
        System.out.println("Weeping...");
    }
}
```
```yaml
Animal
  |
  v
Dog
  |
  v
Puppy
```

#### 3. Hierarchical Inheritance

Multiple classes inherit from a single superclass.
```java
class Animal {
    void eat() {
        System.out.println("Eating...");
    }
}

class Dog extends Animal {
    void bark() {
        System.out.println("Barking...");
    }
}

class Cat extends Animal {
    void meow() {
        System.out.println("Meowing...");
    }
}
```
```markdown
      Animal
      /    \
     v      v
   Dog     Cat
```

#### 4. Multiple Inheritance (Through Interfaces)
Java does not support multiple inheritance with classes to avoid ambiguity (Diamond Problem). However, it can be achieved using interfaces as interfaces does not contains any implementation. 

```Java
interface Printable {
    void print();
}

interface Showable {
    void show();
}

class A implements Printable, Showable {
    public void print() {
        System.out.println("Printing...");
    }
    public void show() {
        System.out.println("Showing...");
    }
}
```
```markdown
Printable   Showable
     \         /
      v       v
         A
```

#### Diamond Problem

The **Diamond Problem** is a well-known issue in **multiple inheritance** when a class inherits from two classes that both inherit from a common base class. This can cause ambiguity in the inheritance hierarchy.

❗ Problem

Imagine this inheritance structure:
```plaintext
      A
     / \
    B   C
     \ /
      D
```
Now, class `D` has **two paths to inherit from** `A`, which creates **a diamond shape**.

If `A` has a method, and both `B` and `C` override it, when `D` calls that method, it is **ambiguous which version to use** — the one from `B`, `C`, or `A`?

⚠️ Java Avoids the Diamond Problem

Java does **not support multiple inheritance with classes** to prevent this ambiguity. You cannot extend more than one class in Java.

✅ Instead, Java allows multiple inheritance using interfaces, which **do not carry implementation logic** (until Java 8 added default methods)

```Java
interface A {
    default void greet() {
        System.out.println("Hello from A");
    }
}

interface B extends A {
    default void greet() {
        System.out.println("Hello from B");
    }
}

interface C extends A {
    default void greet() {
        System.out.println("Hello from C");
    }
}

class D implements B, C {
    public void greet() {
        // Must resolve the ambiguity
        B.super.greet();  // or C.super.greet();
    }
}
```
Output:
```java
Hello from B
```

📌 Key Point:
- If `D` doesn't override `greet()`, the compiler will throw an **error due** to ambiguity.
- Java forces you to **explicitly specify** which default method to use.

### Types Of Polymorphism

**Polymorphism** in Java means "**many forms**" — the ability of a single function, method, or object to behave differently based on context.

There are two main types of polymorphism in Java:

#### 1. Compile-Time Polymorphism (Static Binding / Method Overloading)

When the method to be executed is determined **at compile time**, it is called compile-time polymorphism.

-  Achieved By: **Method Overloading** — same method name with different parameters (type/number/order).

```Java
class Calculator {
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
}

public class Main {
    public static void main(String[] args) {
        Calculator calc = new Calculator();
        System.out.println(calc.add(2, 3));         // 5
        System.out.println(calc.add(2.5, 3.5));     // 6.0
        System.out.println(calc.add(1, 2, 3));      // 6
    }
}
```

Key Points:
- Resolved at compile time.
- Java does **not support operator overloading** (like C++), only method overloading.
- Methods cannot be overloaded solely based on different return types if their parameter types and count are the same.
    ```Java
    class Demo {
        int display(int x) {
            return x;
        }

        // ❌ Compilation error — only return type is different
        double display(int x) {
            return (double) x;
        }
    }
    ```

#### 2. Runtime Polymorphism (Dynamic Binding / Method Overriding)

When the method to be executed is determined **at runtime**, it is called runtime polymorphism.

- Achieved By: **Method Overriding** — subclass provides specific implementation of a method already defined in its parent class. Method signature should be same, number of arguments, type of arguments and return type. Only the internal implementation will differ.

```Java
class Animal {
    void sound() {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal {
    void sound() {
        System.out.println("Dog barks");
    }
}

class Cat extends Animal {
    void sound() {
        System.out.println("Cat meows");
    }
}

public class Main {
    public static void main(String[] args) {
        Animal a1 = new Dog();
        Animal a2 = new Cat();

        a1.sound();  // Dog barks
        a2.sound();  // Cat meows
    }
}
```

- Key Points:
    - Resolved at runtime using **dynamic method dispatch**.
    - Allows Java to support **late binding**.

- Execution Flow:
    - A method is called on an object.
    - The **JVM checks the actual object's class** (not the reference type).
    - If the method is overridden in the subclass, the subclass's version is executed.
    - Otherwise, the superclass’s version is executed.

### IS-A and HAS-A Relationship

####  IS-A Relationship (Inheritance)
- Represents **inheritance** or a **parent-child** relationship.
- If class B extends class A, then **B IS-A A**.
- Achieved using the `extends` or `implements` keyword.
- Used to promote code reuse and polymorphism.

    ```Java
    class Animal {
        void eat() {
            System.out.println("This animal eats food.");
        }
    }

    class Dog extends Animal {
        void bark() {
            System.out.println("Dog barks.");
        }
    }
    ```
- Here, `Dog IS-A Animal` because it inherits from `Animal`.

#### HAS-A Relationship (Composition)
- Represents composition or containment.
- One class contains a reference to another class.
- Achieved by creating an instance of one class inside another.
- Promotes flexibility and code reuse.
    ```Java
    class Engine {
        void start() {
            System.out.println("Engine starts.");
        }
    }

    class Car {
        Engine engine = new Engine(); // Car HAS-A Engine

        void drive() {
            engine.start();
            System.out.println("Car is driving.");
        }
    }
    ```
- Here, `Car HAS-A Engine` because it contains an instance of `Engine`.
- A **"has-a"** relationship (also called **Association**) means that **one class contains a reference to another class**. Depending on how tightly the objects are bound, "has-a" can be categorized into two.

##### Weak "Has-A" Relationship (Aggregation)
- Represents a **"whole-part"** relationship, but the **child object can exist independently** of the parent.
- **Loosely coupled:** Both objects have independent lifecycles.
    ```Java
    class Engine {
        void start() {
            System.out.println("Engine started");
        }
    }

    class Car {
        Engine engine;

        Car(Engine engine) {
            this.engine = engine;
        }

        void move() {
            engine.start();
            System.out.println("Car is moving");
        }
    }
    ```
- Here, `Car has-a Engine`, but the `Engine` can exist even without the `Car`.
- Use Aggregation when the contained object **should not be deleted** when the container is deleted.

##### Strong "Has-A" Relationship (Composition)
- Represents a **stronger whole-part** relationship.
- The **child object’s lifecycle is dependent on the parent**.
- Tightly coupled.
    ```Java
    class Heart {
        void beat() {
            System.out.println("Heart is beating");
        }
    }

    class Human {
        private final Heart heart = new Heart();  // tightly bound

        void live() {
            heart.beat();
            System.out.println("Human is alive");
        }
    }
    ```
- Here, `Human has-a Heart`, and the `Heart` cannot logically exist without the `Human`.
- Use Composition when the contained object **must not exist without the container**.

## Java & Its Ecosystem: WORA, JVM, JRE, JDK

### What is Java?
- Java is a high-level, object-oriented programming language developed by **Sun Microsystems** (now owned by Oracle). 
- Designed to be platform-independent and secure.

### WORA (Write Once, Run Anywhere)
- ORA is Java’s core philosophy. Write the code once, and run it on Windows, Mac, Linux, or any other OS with a JVM.
- Java programs are **compiled into bytecode** (not machine code).
- This bytecode can run **on any platform** that has a compatible **Java Virtual Machine (JVM)**.

###  JVM (Java Virtual Machine)
- **JVM** is a virtual engine that executes **Java bytecode**.
- It provides:
    - Platform Independence
    - Memory Management (GC)
    - Security
    - Multithreading Support
- Each OS has its own implementation of the JVM (platform dependent).
- JVM provides the portability (WORA).
- It is an abstract machine not a physical one. 

Flow
```ssh
Java Source Code (.java)
        ↓ compile
Bytecode (.class)
        ↓ run on
JVM → Executes Bytecode
        ↓ coverts to
Machine Code (Understandble by CPU)
```

### JRE (Java Runtime Environment)
- **JRE = JVM + Libraries + other components** to run Java programs.
- It is used by end-users who **only want to run Java applications, not develop them.**
-  Includes:
    - JVM
    - Core libraries (e.g., java.util, java.io)
    - Supporting files
- ❌ JRE **does not contain** the compiler or development tools.

###  JDK (Java Development Kit)
- JDK = JRE + development tools (compiler, debugger, etc.)
- It is used by developers to **write, compile, and debug Java programs**.
-  Includes:
    - JRE (JVM + libraries)
    - `javac` (Java compiler)
    - `javadoc`, `jdb` (documentation & debugger)
    - Development tools

### Real-World Analogy
- **Java Source Code** = Blueprint of a building
- **JDK** = Architect tools to draw, build, and test
- **JRE** = A furnished building ready to use
- **JVM** = The manager who ensures the building works the same on all lands (OS)

### How Java Achieves Platform Independence

Step-by-Step Flow
1. Write Java Code
2. Compile Java Code
    - The `javac` compiler (part of JDK) compiles the **source code to bytecode**.
    - Output: `.class` file (contains platform-independent bytecode).
    - The binary executable of `javac` **is specific to your OS and architecture** — so we can't run a Windows `javac.exe` on Linux or macOS directly.

3. Bytecode Generation
    - The `.class` file contains **intermediate bytecode**, not native machine code.
    - Bytecode is **universal** across all platforms.
4. Run Bytecode on JVM
    - Each operating system (Windows, Mac, Linux) has its own version of the JVM.
    - The JVM reads the bytecode and **converts it to machine code** for the host system **at runtime** (using an interpreter or JIT compiler).

So `JVM` is the main component which makes JAVA platform independent. 

```ssh
Your Code (.java)
        ↓ [javac]
Bytecode (.class)
        ↓ [JVM]
Native Code for OS
        ↓
Program Executes
```