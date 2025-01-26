#include "character.hpp"

struct Wizard : public BaseCharacter {
	Wizard(std::string_view playerName);
	virtual ~Wizard();
	
	void use() override;
	void heal(uint64_t hl) override;
	void takeDmg(uint64_t dmg) override;
	
	static uint64_t wizs;
};