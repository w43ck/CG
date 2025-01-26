#include "character.hpp"

struct Warrior : public BaseCharacter {
	Warrior(std::string_view playerName);
	virtual ~Warrior();
	
	void use() override;
	void heal(uint64_t hl) override;
	void takeDmg(uint64_t dmg) override;
	
	static uint64_t wars;
};