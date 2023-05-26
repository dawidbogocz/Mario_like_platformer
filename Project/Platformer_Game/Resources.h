#ifndef RESOURCES_H
#define RESOURCES_H

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

template<typename Resource, typename Identifier>
class Resources
{
public:
    void load(Identifier id, const std::string& filename)
    {
        Resource tmp;
        tmp.loadFromFile(filename);
        resources.emplace(id, tmp);
    }

    template<typename Param>
    void load(Identifier id, const std::string& filename, const Param& param)
    {
        Resource tmp;
        tmp.loadFromFile(filename, param);
        resources.emplace(id, tmp);
    }

    Resource& get(Identifier id)
    {
        return resources[id];
    }

private:
    std::unordered_map<Identifier, Resource> resources;
};

#endif