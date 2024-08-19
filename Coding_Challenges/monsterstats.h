#ifndef MONSTERSTATS_H
#define MONSTERSTATS_H

#include <iostream>
#include <string>
enum class MonsterType
{
	ogre,
	dragon,
	orc,
	giantSpider,
	slime,
};
struct Monster
{
	MonsterType type{};
	std::string_view name{};
	int hp{};
};
constexpr std::string_view getMonsterName(MonsterType& monster)
{
	switch (monster)
	{
	case MonsterType::ogre: return "Ogre";
	case MonsterType::dragon: return "Dragon";
	case MonsterType::orc: return "Orc";
	case MonsterType::giantSpider: return "Giant Spider";
	case MonsterType::slime: return "Slime";
	}
	return "Unknown";
}
void printMonster(MonsterType& monster)
{
	std::cout << "This " << getMonsterName(monster.type) << "'s name is " << monster.name << " and he has " << monster.hp << "hp.\n";
}
//int main()
//{
//	Monster ogre{ MonsterType::ogre, "Bucky", 788 };
//	Monster dragon{ MonsterType::dragon, "Tiny", 988 };
//	Monster orc{ MonsterType::orc, "Sushi", 999 };
//	Monster giantSpider{ MonsterType::giantSpider, "Leggies", 23 };
//	Monster slime{ MonsterType::slime, "Sticky", 23423 };
//
//	printMonster(ogre);
//	printMonster(dragon);
//	printMonster(orc);
//	printMonster(giantSpider);
//	printMonster(slime);
//
//	return 0;
//}



#endif
