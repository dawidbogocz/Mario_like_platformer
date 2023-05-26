#include "world.h"
#include "block.h"
#include <fstream>
#include <iostream>
#include <filesystem>

void World::loadMap(int lvl){
    std::filesystem::path level{ std::filesystem::current_path() / "Levels" };
    std::ifstream mapFile;
    
    if (lvl == 1) {
        mapFile.open(level / "Level-1.txt");
    }
    else if(lvl == 2){
        mapFile.open(level / "Level-2.txt");
    }
    
    if(!mapFile.is_open()){
        std::cerr << "Couldn't find the mapFile" << std::endl;
        return;
    }
    for(int i = 0; !mapFile.eof(); i++){   
        std::string str;
        mapFile >> str;

        std::vector< std::unique_ptr<Block>> row;

        for(int j = 0; j < str.length(); j++){
            Block::Type type;

            switch (str[j])
            {
            case 'W':   fin = j;
            case '-':   row.push_back(nullptr);
                continue;
            case '1':   type = Block::Type::Crate;
                break;
            case '2':   type = Block::Type::Gold;
                break;
            case '3':   type = Block::Type::Empty;
                break;
            case '4':   type = Block::Type::Grass;
                break;
            case '5':   type = Block::Type::Grass_L_Corner;
                break;
            case '6':   type = Block::Type::Grass_L;
                break;
            case '7':   type = Block::Type::Dirt;
                break;
            case '8':   type = Block::Type::Grass_R;
                break;
            case '9':   type = Block::Type::Grass_R_Corner;
                break;
            case 'A':   type = Block::Type::Pilar_L_Top;
                break;
            case 'B':   type = Block::Type::Pilar_R_Top;
                break;
            case 'C':   type = Block::Type::Pilar_L;
                break;
            case 'D':   type = Block::Type::Pilar_R;
                break;
            default:    break;
            }
            row.emplace_back(std::make_unique <Block>(type, j, i));
        }
        map.push_back(std::move(row));
    }

    mapFile.close();
}

bool World::finish(const int x) const
{
    return x > fin;
}

void World::draw(sf::RenderWindow& window){
    std::for_each(map.begin(), map.end(), [&window](const std::vector<std::unique_ptr<Block>>& row)
    {
        std::for_each(row.begin(), row.end(), [&window](const std::unique_ptr<Block>& block)
        {
            if (block)   block->draw(window);
        });
    });
}

int World::worldEnd() const{
    return map[0].size();
} 

int World::worldBottom() const {
    return map.size();
}

bool World::Solid(const int x, const int y) const{
    return map[x][y] != nullptr;
}

float World::getGravity() const{
    return gravity;
}