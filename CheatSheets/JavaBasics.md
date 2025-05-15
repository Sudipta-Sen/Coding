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
> a. [WORA](#wora-write-once-run-anywhere)<br>
> b. [JVM](#jvm-java-virtual-machine)<br>
> c. [JDK](#jdk-java-development-kit)<br>
> d. [JRE](#jre-java-runtime-environment)<br>
> e. [Analogy](#real-world-analogy)<br>
> f. [Platform Independence](#how-java-achieves-platform-independence)<br>
> g. [Explanation public-static-void-mains](#explanation-public-static-void-mainstring-args)<br>
> h. [File and public class](#single-file-can-have-only-1-public-class)<br>
3. [Java Variables](#java-variables)<br>
> a. [IEEE 754 format](#ieee-754-floating-point-representation-single-precision---32-bit)<br>
>> i. [Decimal to IEEE754](#step-by-step-conversion-of-4125-to-ieee-754-float)<br>
>> ii. [IEEE754 to Decimal](#ieee-754-to-decimal-conversion)<br>
>> iii. [Why bias is needed](#why-bias-is-needed)<br>
>> iv. [0.7f representation](#why-07f-cannot-be-represented-exactly)<br>
>> v. [IEE754 and 2s-complement](#ieee754-and-2s-complement)<br>

> b. [Static Type & Strong Type Language](#static-type--strong-type-language)<br>
> c. [Type Conversion](#type-conversion)<br>
>> i. [Implicit Type Conversion](#implicit-type-conversion-wideningautometic-conversion--type-promotion)<br>
>> ii. [Explicit Type Conversion](#explicit-type-conversion-narrowing-conversion--type-casting)<br>
>> iii. [Type Promotion](#type-promotion-in-expressions)<br>

> d. [Data Types](#data-types)<br>
>> i. [Primitive Types](#primitive-data-types)<br>
>> ii. [Reference Types](#non-primitive-data-types-reference-types)<br>

> e. [Strings](#strings)<br>
>> i. [String Immutability](#string-immutability)<br>
>> ii. [String literal and Constant Pool](#string-literal--string-constant-pool)<br>

> f. [Wrapper Class](#wrapper-class)
## OOPS Concepts

### Overview Of OOPS
- OOPS mean Object-Oriented Programming
- Here Object means real world entity like Car, Bike etc. Every real world entity has two things 
    - Behaviour or Functionality 
    - Properties or State
- Procedural Programming vs OOPS

    | ***Aspect***  | ***Procedural Programming***   | OOPS          |
    |---------------------|--------------------|--------------------------|
    | Structure           | Program is structured and divided into parts as procedures c(methods)       | Code is structured around classes and objects      |
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
- Designed to be platform-independent, secure and portable.

### WORA (Write Once, Run Anywhere)
- WORA is Java’s core philosophy. Write the code once, and run it on Windows, Mac, Linux, or any other OS with a JVM.
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
- JVM is not a physical machine, an abstract machine. 
- JVM provides the portability (WORA).
- It is an abstract machine not a physical one. 

Flow
```ssh
Java Source Code written in any machine(.java)
        ↓ javac/compile
Bytecode (.class)
        ↓ JVM converts
Machine Code (Understandble by CPU)
```

### JRE (Java Runtime Environment)
- **JRE = JVM + Libraries + other components** to run Java programs.
- It is used by end-users who **only want to run Java applications, not develop them.**
- It can only run the **bytecode** i.e **.class** file not a **.java** file as it does not have **javac**
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
    - `javac` (Java compiler), `input`: **platform independent code**  `output:` **independent bytecode** 
    - `javadoc`, `jdb` (documentation & debugger)
    - Development tools

### Real-World Analogy
- **Java Source Code** = Blueprint of a building, **platform independent**
- **JVM** = The manager who ensures the building works the same on all lands (OS), **platform dependent**
- **JRE** = A furnished building ready to use, **platform dependent**
- **JDK** = Architect tools to draw, build, and test, **platform dependent**

### How Java Achieves Platform Independence

Step-by-Step Flow
1. Write Java Code
2. Compile Java Code
    - The `javac` compiler (part of JDK) compiles the **source code to bytecode**.
    - Output: `.class` file (contains **platform-independent** bytecode).
    - The binary executable of `javac` **is specific to your OS and architecture** — so we can't run a Windows `javac.exe` on Linux or macOS directly.

3. Bytecode Generation
    - The `.class` file contains **intermediate bytecode**, not native machine code.
    - Bytecode is **universal** across all platforms i.e **platform independent**
4. Run Bytecode on JVM
    - Each operating system (Windows, Mac, Linux) has its own version of the JVM.
    - The JVM reads the **bytecode** and **converts it to machine code** for the host system **at runtime** (using an interpreter or Just In Time (JIT) compiler).

So `JVM` is the main component which makes JAVA platform independent. 

```ssh
Your Code (.java)
        ↓ [javac]
Bytecode (.class)
        ↓ [JVM]
Native/Machine Code for OS
        ↓ [JRE]
Program Executes
```

### Some extra terms
- JSE ---> Java Standard Edition, Core Java
- JEE ---> Java Enterprose Edition, JSE + Certain API (Transaction API(Rollback, commit), Servlet, JSP)
- JME ---> Java Mobile/Micro Edition, API for mobile app development 

### Explanation public static void main(String[] args)

1. Why is it needed?
    - The **main() method is the entry point** of any standalone Java application.
    - The **JVM** looks for this method to start program execution.

2. Breakdown of public static void main(String[] args)

    | Keyword            | Meaning                                                                                          |
    | ------------------ | ------------------------------------------------------------------------------------------------ |
    | **public** | Access modifier: JVM needs to access this method from outside the class. So it must be `public`. |
    | **static** | It belongs to the class, not to an instance. JVM can call it **without creating an object**.     |
    | **void**  | The method returns **no value**.    |
    | **main**  | Special method name recognized by JVM as the **starting point**. JVM calls main method.                                 |
    | **String\[] args** | **Command-line arguments**. Allows users to pass inputs when the program runs.   |

3. Why static?
    - JVM should not be forced to create an object of the class just to start execution.
    - Hence, `main` is made `static` so it can be invoked **without object creation.**

4. Why String[] args?
    - Used to accept command-line arguments.
    - Example:
        ```java
        java HelloWorld Hello ChatGPT
        ```
        - Here, `args[0] = "Hello"`, `args[1] = "ChatGPT"`

5. Important Points
    - If we change the signature (remove `public` or `static`), JVM will not recognize it and throw a **runtime error**:
        ```pgsql
        Error: Main method not found in class HelloWorld.
        ```
6. Alternative valid signatures:
    - The following are valid too:
        ```java
        public static void main(String args[])
        public static void main(String... args)  // varargs form
        ```

### One java file can have only 1 public class

1. **Java File Structure Rule**
    - Public class must be saved in a file with the same name as the class.
    - Example:
        - If we have:
            ```java
            public class HelloWorld { }
            ```
            - The file must be named: `HelloWorld.java`

2. **What happens if you have multiple public classes?**
    - Suppose:
        ```java
        public class A { }
        public class B { }
        ```
    - This would require the file to be named both `A.java` and `B.java` simultaneously, which is **impossible**.
    - Hence, Java restricts **only one public class per file**.

3. **Can a file have multiple classes?**

    Yes, but:
    - Only **one class can be public**.
    - The other classes must have **default (package-private) access modifier.**
    - Example:
        ```java
        public class MainClass {
            public static void main(String[] args) {
                HelperClass.help();
            }
        }

        class HelperClass {
            static void help() {
                System.out.println("Helper class method.");
            }
        }
        ```
    - For the above example, **two .class** files will be created:
        
        | **.class File Name** | **Reason** |
        | -------------------- | ---------- |
        | `MainClass.class`    | For the **public class MainClass** |
        | `HelperClass.class`  | For the **package-private class HelperClass** |
    
    - **Explanation:**
        - The Java compiler (`javac`) compiles each class separately into its own `.class` file.
        - Even though `HelperClass` is package-private (no `public` modifier), it still gets compiled into its own bytecode file.
        - Both classes are loaded by the JVM when needed.
        - Command to Compile:
            ```java
            javac MainClass.java
            ```
        - Output Files:
            ```java
            MainClass.class
            HelperClass.class
            ```
4.  **Why this restriction? (Design Reasons)**
    
    | Reason | Explanation    |
    | ------ | ---- |
    | **Maintainability** | Easier to locate a class by matching file name and class name. |
    | **Compilation Process** | JVM & compiler use the file name to find the bytecode for a public class. |
    | **Avoids Ambiguity** | Prevents confusion during class loading & package management. |
    | **Best Practice** | Promotes clean project structure with one main class per file. |

5. **Java Compilation Rule: File Name vs Public Class Name**
    - If the file name is `Employee.java` but inside the file we write:
        ```java
        public class Student {
            public static void main(String[] args) {
                System.out.println("Hello from Student class.");
            }
        }
        ```
    
        We will get this compile-time error:
        ```kotlin
        Employee.java:1: error: class Student is public, should be declared in a file named Student.java
        public class Student {
            ^
        1 error
        ```
## Java Variables

### IEEE 754 Floating Point Representation (Single Precision - 32-bit)

| Part                    | Bits    | Description                           |
| ----------------------- | ------- | ------------------------------------- |
| **Sign**                | 1 bit   | 0 for positive, 1 for negative        |
| **Exponent**            | 8 bits  | Biased exponent (bias = 127)          |
| **Mantissa (Fraction)** | 23 bits | Fractional part (after normalization) |

#### Step-by-Step Conversion of 4.125 to IEEE 754 (float)

1. **Convert 4.125 to Binary**
    - Whole Part (4):
        - 4 in binary = `100`
    - **Fractional Part (0.125):**
        - 0.125 × 2 = 0.25 → 0
        - 0.25 × 2 = 0.5 → 0
        - 0.5 × 2 = 1.0 → 1
    So, 0.125 in binary = `0.001`
    - **Final Binary Representation:**
        ```ini
        4.125 = 100.001 (binary)
        ```
2. **Normalize the Binary Number**
    - IEEE 754 needs normalized form: `1.xxxxx × 2^E`
    - For `100.001:` Move decimal point 2 places left: `1.00001 × 2^2`
3.  **Find the Exponent with Bias**
    - Exponent (E) = 2
    - Bias = 127 (for 32-bit float)

    Stored exponent = E + Bias = 2 + 127 = 129
    - 129 in binary = `10000001`
4. **Mantissa (Fraction Part)**
    - From normalized `1.00001`:
        
        Mantissa = `00001` (remaining after `1.`)
    - Fill remaining with 0s to make 23 bits: `00001000000000000000000`
5. **Sign Bit**
    - 4.125 is positive → **sign bit = 0**
6. **Final IEEE 754 Representation of 4.125**
    - `0 10000001 00001000000000000000000`

#### IEEE 754 to Decimal Conversion

Formula: 
```markdown
Value=(−1)^sign × 2^(exponent−bias) * (1.mantissa bits)
```
Example Calculation

For IEEE 754 binary:
`0 10000001 00001000000000000000000`

1. Sign: 0 → positive number
2. Exponent:
    - Binary: 10000001 = 129
    - Bias: 127
    - True exponent: 129 - 127 = 2
3. Mantissa:
    - With implicit 1: 1.00001
    - Decimal: 1 + 0.03125 = 1.03125
4. Final Value:
    ```markdown
    Value = (-1)^0 × 2^2 × 1.03125 = 1 × 4 × 1.03125 = 4.125
    ```
#### Why Bias is Needed?

- Exponent values can be **positive or negative** (for large & small numbers).
- But bits can only store **unsigned binary values** (positive integers).
- To store negative exponents, **biasing is used**.
- **Bias Mechanism:**
    - True Exponent = Stored Exponent - Bias
    - For single-precision float: **bias = 127**
    
        | True Exponent | Stored Exponent |
        | ------------- | --------------- |
        | -2            | 125             |
        | 0             | 127             |
        | +2            | 129             |

#### Why 0.7f Cannot Be Represented Exactly
- 0.7f in binary is a recurring fraction: `0.1011001100110011... (repeats infinitely)`
- But `float` has only **23 bits of precision** for the mantissa.
- So it stores the **closest possible approximation**.
- Approximate value stored: `0.699999988079071044921875`
- Printed value (rounded): `0.6999998`
- This is just like `1/3` cannot be exactly represented in decimal.
- We can use **BigInteger** to solve this problem.

#### IEEE754 and 2's complement

| **Data Type**       | **Storage Format in Java**        | **Why?** |
| ------------------- | --------------------------------- | ------   |
| **float, double**          | Stored using **IEEE 754 Floating-Point Standard**   | Efficient for integers, simple arithmetic |
| **byte, short, int, long** | Stored using **2's Complement Binary Representation** | Needed for fractions, exponents, and precision |


### Static Type & Strong Type Language

1. **Static Typing**
    - **Definition:**
        Java is a statically typed language, meaning **variable types are checked at compile time**.
    - **Key Points:**
        - We must declare the type of every variable.
        - Type errors (like assigning a String to an int) are caught **before the program runs.**
    - **Example:**
        ```java
        int number = 10;   // Correct
        number = "text";   // Compile-time error (type mismatch)
        ```

2. **Strong Typing**
    - **Definition:** Java is also a strongly typed language, meaning it **strictly enforces type rules** and **does not allow implicit type conversions** that can lead to errors.
    - Key Points:
        - We **cannot mix incompatible types** without explicit casting.
        - Prevents unintended behaviors due to loose conversions.
        - Static type means Java checks variable types at compile time. Strong type means Java does not allow mixing different types without clear conversion.
    - **Example:**
        ```java
        int num = 10;
        double val = num;   // Allowed (widening conversion)

        String text = "123";
        int invalid = text; // Compile-time error: incompatible types
        ```
    - To convert String to int, we must do:
        ```java
        int valid = Integer.parseInt(text);
        ```

3. **Difference Between Static Type & Strong Type**
    | Feature                 | Static Typing                 | Strong Typing                          |
    | ----------------------- | ----------------------------- | -------------------------------------- |
    | **When Checked**        | Compile Time                  | Runtime (enforces strict type usage)   |
    | **Type Declaration**    | Required                      | Type safety is strictly maintained     |
    | **Implicit Conversion** | Limited automatic conversions | No unsafe implicit conversions allowed |
    | **Examples**            | Java, C, C++                  | Java, Python, Ruby                     |

3. **Java vs Python: Static Typing vs Dynamic Typing**
    | Feature | **Java** | **Python**  |
    | ---------------- | ----------- | -------------- |
    | **Typing Discipline**    | Static Typed, Strongly Typed | Dynamic Typed, Strongly Typed |
    | **Type Checking**        | Compile-time    | Runtime      |
    | **Variable Declaration** | Type must be declared explicitly  | Type is inferred dynamically at runtime  |
    | **Type Safety**          | Strongly enforces types  | Strongly enforces types but at runtime       |
    | **Type Inference**       | Limited (Java 10+ with `var` keyword) | Fully dynamic type inference  |
    | **Code Example**         | `java<br>int x = 10;<br>x = "hello"; // Error` | `python<br>x = 10<br>x = "hello"  # Allowed` |
    | **Advantages**           | Early error detection, better performance  | Faster prototyping, flexible coding |
    | **Disadvantages**        | More verbose, less flexible                    | Errors can show up late (runtime errors)     |
    | **Use Case Suitability** | Large-scale, performance-critical systems | Scripting, rapid development, data science   |

### Type Conversion

Type conversion refers to converting a variable of one data type into another. It can happen implicitly (automatically) or explicitly (manually).

#### Implicit Type Conversion (Widening/Autometic Conversion / Type Promotion)
- Done automatically by Java.
- Converts smaller data types to larger data types (no data loss).
- Example: `byte → short → int → long → float → double`
- Example:
    ```java
    int a = 10;
    double b = a;  // Implicit conversion (int to double)
    System.out.println(b);  // Output: 10.0
    ```

#### Explicit Type Conversion (Narrowing Conversion / Type Casting)
- Done **manually** by the programmer.
- Converts **larger data types to smaller data types** (possible data loss).
- Syntax: `(targetType) value`
    ```java
    double a = 10.75;
    int b = (int) a;  // Explicit conversion (double to int)
    System.out.println(b);  // Output: 10 (fractional part lost)
    ```

#### Type Promotion in Expressions
- During expressions, smaller types are promoted automatically.
- Example: `byte`, `short`, and `char` are promoted to `int` in expressions.
- Example:
    ```java
    byte a = 120;
    byte b = 20;
    int c = a + b;  // 'a' and 'b' promoted to int, Output: 140
    byte d = (byte) (a+b); //Outpput: -116
    ```
    - Since byte range is -128 to 127, and here `a+b=130` which is crossing the byte range, `a` and `b` are autometically promoted to int.
    - Since `a` and `b` are autometically promoted to int, if we want to store the result in byte variable `d` then we need to explicitly downcast it which results in lossy conversion. 

### Data Types

Java is a strongly typed language, which means every variable must be declared with a data type. Data types specify the size and type of values that can be stored.

#### Primitive Data Types

Primitive data types are the basic building blocks of data manipulation in Java. They are predefined by the language and are not objects.


| Type      | Size (bits) | Range                                      | Default Value |
|-----------|-------------|---------------------------------------------|---------------|
| byte      | 8           | -128 to 127                                 | 0             |
| short     | 16          | -32,768 to 32,767                           | 0             |
| int       | 32          | -2,147,483,648 to 2,147,483,647             | 0             |
| long      | 64          | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 | 0L            |
| float     | 32          | ~±3.40282347E+38F (approx 7 decimal digits) | 0.0f          |
| double    | 64          | ~±1.79769313486231570E+308 (approx 15 digits)| 0.0d         |
| char      | 16          | 0 to 65,535 (Unicode values)                | '\u0000'      |
| boolean   | 1           | true / false                               | false         |

#### Non-Primitive Data Types (Reference Types)

Non-primitive types are created by the programmer or provided by Java libraries. They are **references to objects stored in the heap memory**.

Types of Non-Primitive Data Types: `String`, `Arrays`, `Classes`, `Interfaces`, `Enums`

### Strings

#### String Immutability 
- In Java, String is **immutable**, meaning **once created, its value cannot be changed**.
- When you try to modify a String, **a new String object is created**, the original remains unchanged.
- Example
    ```java
    String str = "Hello";
    str = str + " World";  // Creates a new String object "Hello World"
    ```
    `"Hello"` remains **unchanged**, and a new `"Hello World"` String object is **created**.

#### String Literal & String Constant Pool
- A **String literal** is a sequence of characters enclosed in double quotes (" ").
- **String Pool** (also called **String Constant Pool**) **is a special memory area** inside the Java **Heap Memory** where **String literals** are stored
- **Example:**
    ```Java
    String s1 = "Java"; //"Java" is String literal
    String s2 = "Java";
    String s3 = new String("Java"); //"Java" is String literal
    ```
-  **Behavior:**
    - `s1` and `s2` refer to the **same object** in the String Pool.
    - `s3` creates **a new object in heap memory**, even if the value is same.
- **Comparison:**
    ```java
    System.out.println(s1 == s2); // true (same reference from String Pool)
    System.out.println(s1 == s3); // false (different objects)
    System.out.println(s1.equals(s3)); // true (value comparison)
    ```
    - Memory address stored in `s1` and `s2` are same but memory address in `s1` and `s3` are different.
    - Both `s1` and `s2` will point to the **same object** in the **String Pool**.
    - **'new' keyword**	Forces creation of **new String object in heap, bypassing pool**.
    - `==` compares references, .`equals()` compares values.

- **Why String Pool?**
    - Memory Optimization: Avoids creating duplicate String objects.
    - Performance: Reusing same object reduces memory overhead.
    - Immutable Strings: Safe to share across references.

### Wrapper Class

- Wrapper classes provide a way to use **primitive data types as objects**.
- Every primitive type in Java has a corresponding wrapper class in the `java.lang` package.
- Wrapper classes are immutable.
- Benefit
    - Enable **autoboxing/unboxing** (automatic conversion between primitive & object).
        - Autoboxing: Primitive → Wrapper Object
        - Unboxing: Wrapper Object → Primitive
    - Provide many utility methods. Such as: `parseInt()`, `valueOf()`, `toString()`
    - Enable **pass by reference** in primitive data types