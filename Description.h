#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>

class Description
{
public:
	// вывод сообщений
	void outputGreeting() const;
	void outputHeadDescription() const;
	void outputGeneralHint() const;
	void outputValediction() const;
	void outputBuffer() const;
	// инициализируем данные посредством установщиков, несколько затратнее по ресурсам, но оптимальнее по сопровождению
	explicit Description()
	{
		//std::cout << "экземпл€р начал создание";
		setGreeting();
		setHeadDescription();
		setGeneralHint();
		setValediction();
		setBuffer();
		//std::cout << "экземпл€р создан";
	}

private:
	std::vector<std::string> greeting;			// приветствие
	std::vector<std::string> headDescription;	// обща€ важна€ информаци€ при старте игры
	std::vector<std::string> generalHint;		// подсказки по управл€ющим командам
	std::vector<std::string> valediction;		// прощальное сообщение при завершении программы
	std::vector<std::string> buffer;			// прослойка дл€ изобразительных нужд

	// установщики сообщений
	void setGreeting();
	void setHeadDescription();
	void setGeneralHint();
	void setValediction();
	void setBuffer();

	// убираем опции копировани€ конструктором и присваиванием
	Description(const Description&) {}
	const Description& operator= (const Description&) {}
};

