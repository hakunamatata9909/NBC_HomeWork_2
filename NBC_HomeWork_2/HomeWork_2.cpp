#include<iostream>
#include<cstdlib>
#include<ctime>


using namespace std;

class Animal {
public:
	virtual void makeSound() {};
	virtual ~Animal() {};
};

class Dog :public Animal {
public:
	void makeSound() override {
		cout << " ¸Û ";
	}
};

class Cat : public Animal {
public:
	void makeSound()override {
		cout << "³Ä¿Ë ";
	}
};

class Cow : public Animal {
public:
	void makeSound() override {
		cout << "À½¸Þ ";
	}
};

Animal* createRandomAnimal() {
	int n = rand() % 3;

	switch (n)
	{
	case 0:
		return new Dog();
	case 1:
		return new Cat();
	case 2:
		return new Cow();
	}

}

class Zoo {
private:
	Animal* animals[10];
	int n = 0;

public:
	void addAnimal(Animal* animal) {
		if (n < 10)
			animals[n] = animal;
		else
			delete animal;
		n++;
	}

	void performActions() {
		for (int i = 0; i < 10; i++) {
			animals[i]->makeSound();
		}
	}

	~Zoo() {
		for (int i = 0; i < 10; i++) {
			if (animals[i])
				delete animals[i];
		}
	}
};

int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	createRandomAnimal();

	Zoo* a = new Zoo();
	for (int i = 0; i < 10; i++)
		a->addAnimal(createRandomAnimal());
	a->performActions();
	delete a;

	return 0;
}