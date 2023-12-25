#include <iostream>

// Library 1
class Library1 {
public:
    virtual void openBook() const = 0;
    virtual void turnPage() const = 0;
    virtual ~Library1() = default; // Додано віртуальний деструктор
};

// Concrete implementation of Library1
class ConcreteLibrary1 : public Library1 {
public:
    virtual void openBook() const override {
        std::cout << "Opening book in ConcreteLibrary1" << std::endl;
    }

    virtual void turnPage() const override {
        std::cout << "Turning page in ConcreteLibrary1" << std::endl;
    }
};

// Library 2
class Library2 {
public:
    virtual void unlock() const = 0;
    virtual void readContent() const = 0;
    virtual ~Library2() = default; // Додано віртуальний деструктор
};

// Concrete implementation of Library2
class ConcreteLibrary2 : public Library2 {
public:
    virtual void unlock() const override {
        std::cout << "Unlocking in ConcreteLibrary2" << std::endl;
    }

    virtual void readContent() const override {
        std::cout << "Reading content in ConcreteLibrary2" << std::endl;
    }
};

// Target Book interface
class Book {
public:
    virtual void open() const = 0;
    virtual void turnPage() const = 0;
    virtual ~Book() = default; // Додано віртуальний деструктор
};

// Adapter for Library1
class Adapter1 : public Book {
private:
    ConcreteLibrary1 concreteLibrary1;

public:
    virtual void open() const override {
        concreteLibrary1.openBook();
    }

    virtual void turnPage() const override {
        concreteLibrary1.turnPage();
    }
};

// Adapter for Library2
class Adapter2 : public Book {
private:
    ConcreteLibrary2 concreteLibrary2;

public:
    virtual void open() const override {
        concreteLibrary2.unlock();
        concreteLibrary2.readContent();
    }

    virtual void turnPage() const override {
        // Implementation for turning page in ConcreteLibrary2 (if applicable)
    }
};

int main() {
    Book* book1 = new Adapter1();
    book1->open();
    book1->turnPage();

    Book* book2 = new Adapter2();
    book2->open();
    book2->turnPage();

    delete book1;
    delete book2;

    return 0;
}
