#include "Description.h"

// реализация установщиков

void Description::setGreeting()
{
	this->greeting.clear();
	this->greeting.push_back("Добро пожаловать в игру TestRPGConsoleGame, или Тестовая Ролевая Консольная Игра!"); 
	// уточнить, как можно вытащить название проекта в виде string переменной и засунуть сюда, если не сильно нагружает.		???
	this->greeting.push_back("Удачного времяпровождения!");
}

void Description::setHeadDescription()
{
	this->headDescription.clear();
	this->headDescription.push_back("Цель игры - пройти подземелье выбранным персонажем до конца, одолеть главного гада и прославить свое имя в веках! *");
	this->headDescription.push_back("\n");
	this->headDescription.push_back("\tОбозначения объектов на карте: ");
	this->headDescription.push_back(" P - местоположение игрока (Player)");
	this->headDescription.push_back("\"  \" - свободная для прохода, пустая клетка поля");
	this->headDescription.push_back("@@ - непроходимая стена");
	this->headDescription.push_back("[\\ - вход на уровень");
	this->headDescription.push_back("/] - выход с уровня");
	this->headDescription.push_back(" O - неизвестный объект");
	this->headDescription.push_back("SL - источник жизни, восстанавливает здоровье до максимума. Снимает одну травму.");
	this->headDescription.push_back("CH - сундук");
	this->headDescription.push_back(" K - ключ");
	this->headDescription.push_back("PL - портал на случайную свободную клетку уровня");

	// символы монстров
	this->headDescription.push_back(" M - монстр, неопознанного типа");
	this->headDescription.push_back("MM - монстр, тип - минотавр"); // класс опасности (КО) 3. Противник КО, равного уровню игрока, является средним по сложности,
	// +1 - неприятным, +2 - серьезным, +3 - опасным, выше - смертельно опасным
	this->headDescription.push_back("GW - монстр, тип - гоблин-воин"); // КО 1
	this->headDescription.push_back("GS - монстр, тип - гоблин-шаман"); // КО 2
	this->headDescription.push_back("GB - монстр, тип - гоблин-босс"); // КО 3
	this->headDescription.push_back(" S - монстр, тип - скелет"); // КО 1
	this->headDescription.push_back("SA - монстр, тип - скелет - лучник "); // КО 2
	this->headDescription.push_back("SL - монстр, тип - скелет-лич"); // КО 7
	this->headDescription.push_back("CP - монстр, циклоп"); // КО 10
	this->headDescription.push_back("DN - монстр, дракон"); // КО 13
	this->headDescription.push_back("\n");
	this->headDescription.push_back("*или, по крайней мере, до конца игровой сессии.");
}

void Description::setBuffer()
{
	this->buffer.clear();
	this->buffer.push_back("/////////////////////////////////////////////////////////");
	this->buffer.push_back("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	this->buffer.push_back("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
}

void Description::setGeneralHint()
{
	this->generalHint.clear();
	//интерфейсы управления
	this->generalHint.push_back("Игра обрабатывает все действия игрока и монстра пошагово. Вне прямой угрозы шаги игрока идут непрерывно.");
	this->generalHint.push_back("В бою шаги игрока и монстра визуально чередуются. Очередность хода зависит от разницы параметров Инициатива.");
	this->generalHint.push_back("Один шаг, по умолчанию, 3 действия. Команды, не требующие действия, содержат это в своем опицании.");
	this->generalHint.push_back("\"статус\" - отображает текущие характеристики персонажа (не инвентарь). Не требует действий.");
	this->generalHint.push_back("\"инвентарь\" - отображает инвентарь персонажа. Не требует действий.");
	this->generalHint.push_back("\"вправо\" - передвигается на клетку справа, если это возможно.");
	this->generalHint.push_back("\"влево\" - передвигается на клетку слева, если это возможно.");
	this->generalHint.push_back("\"вверх\" - передвигается на клетку вверх, если это возможно.");
	this->generalHint.push_back("\"вниз\" - передвигается на клетку вниз, если это возможно.");
	this->generalHint.push_back("\"атака\" - атакует противника активным оружием. Если дистанции оружия недостаточно, тратит оставшиеся действия шага на движение к врагу, \
пока не сможет атаковать.");
	this->generalHint.push_back("\"*название заклинания*\" - использует заклинание на себя, если полезно, на противника, если нет. Каждое заклинание тратит индивидуальное \
количество действий.");
	this->generalHint.push_back("\"заново\" - начинает новую игру, заново генерирует уровень");
	this->generalHint.push_back("\"выход\" - выход из игры");
	this->generalHint.push_back("\"навыки?\" - вывод информации о всех навыках персонажей. Не требует действий.");
	this->generalHint.push_back("\"черты?\" - вывод информации о существующих чертах. Не требует действий. Для информации о имеющихся чертах персонажа используйте \
\"статус\".");
	this->generalHint.push_back("\"*название черты?*\" - вывод информации о конкретной черте. Не требует действий.");
	this->generalHint.push_back("\"эрудиция\" - использование указанного навыка для получения информации о неопознанных объектах или существах. Не требует действий.");
	this->generalHint.push_back("\"заклинания?\" - подробная информация о существующих заклинаниях. Не требует действий.");
	this->generalHint.push_back("\"использовать *№ предмета*\" - использовать определенный предмет из инвенторя. Индивидуальное количество действий для каждого предмета.");
	this->generalHint.push_back("\"активировать\" - активировать объект.");
}

void Description::setValediction()
{
	this->valediction.clear();
	this->valediction.push_back("Спасибо за уделенное время! Надеюсь, путешествие выдалось занятным! Удачи и до новых встреч!");
}

void Description::outputGreeting() const
{
	for (auto element : this->greeting)
	{
		std::cout << element << '\n';
	}
}

void Description::outputBuffer() const
{
	for (auto element : this->buffer)
	{
		std::cout << element << '\n';
	}
}

void Description::outputGeneralHint() const
{
	for (auto element : this->generalHint)
	{
		std::cout << element << '\n';
	}
}

void Description::outputHeadDescription() const
{
	for (auto element : this->headDescription)
	{
		std::cout << element << '\n';
	}
}

void Description::outputValediction() const
{
	for (auto element : this->valediction)
	{
		std::cout << element << '\n';
	}
}