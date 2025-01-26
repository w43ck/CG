#include "../inc/char_view_state.hpp"
#include "../inc/warrior.hpp"
#include "../inc/wizard.hpp"

CharViewState::CharViewState() {
	this->output = "=====ВЫБОР КЛАССА=====\n\nНажмите Escape для выхода\n";
	this->type = 0;
}

CharViewState::CharViewState(uint8_t type, State * stt) {
	this->type = type;
	this->stt = stt;
	this->output =
	(type == 1) ? "=====ВЫБОР КЛАССА=====\n\nВоин - боец ближнего боя, специализирующийся на одноручном или двуручном оружии, также может использовать щиты и любое другое, наносящее непосредственные удары по противнику. Имеет высокие показатели силы и брони, навыки, направленные на нанесение физического урона и выдерживания большие объемы получаемого урона.\nОсновная характеристика - сила. Бонус класса - +1 к силе, +5 к здоровью за уровень.\n\nНажмите Escape для выхода\nНажмите Enter для подтверждения выбора персонажа\n"
	: (type == 2) ? "=====ВЫБОР КЛАССА=====\n\nМаг - повелитель стихий, использующий жезлы для создания могущественных заклинаний. Не носит броню, но способен атаковать противника на расстоянии, нанося огромное количества урона по площади.\nОсновная характеристика - интеллект. Бонус класса - +1 к интеллекту, +5 к мане за уровень.\n\nНажмите Escape для выхода\nНажмите Enter для подтверждения выбора персонажа\n"
	: "Неправильный тип персонажа";
}

CharViewState::~CharViewState() {
	
}

void CharViewState::update(Game * game) {
	this->input = _getch();
	switch (this->input) {
		case 27: {
			this->st = 1;
			break;
		}
		case 13: {
			if(!this->isOff) {
				if(game->characters.size() < 5) {
					fmt::print("Введите имя для персонажа (не более 13 символов, для подтверждения ввода нажмите Enter):\n");
					std::string temp;
					std::cin >> temp;
					if(temp.length() > 13) {
						temp = temp.substr(0, 13);
					}
					switch (this->type) {
						case 1: {
							game->characters.push_back(std::make_shared<Warrior>(temp));
							this->output = "=====ВЫБОР КЛАССА=====\n\nПерсонаж класса Воин успешно создан! Нажмите Escape для выхода\n";
							this->stt->st = 1;
							this->isOff = 1;
							break;
						}
						case 2: {
							game->characters.push_back(std::make_shared<Wizard>(temp));
							this->output = "=====ВЫБОР КЛАССА=====\n\nПерсонаж класса Маг успешно создан! Нажмите Escape для выхода\n";
							this->stt->st = 1;
							this->isOff = 1;
							break;
						}
					}
				} else {
					this->output = "=====ВЫБОР КЛАССА=====\n\nНельзя создать нового персонажа. Максимум созданных персонажей для каждого игрока - 5.\nНажмите Escape для выхода в меню";
				}
			}
		}
		default:
		break;
	}
}

void CharViewState::render() {
	system("cls");
	fmt::print("{}", this->output.data());
}

void CharViewState::endState() {
	
}