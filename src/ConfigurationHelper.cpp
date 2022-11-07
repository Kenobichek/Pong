#include "ConfigurationHelper.h"

ConfigurationHelper::ConfigurationHelper()
{
    std::ifstream fin("res/configuration.json");
    configuration = json::parse(fin);
    fin.close();
}

std::shared_ptr<ConfigurationHelper> ConfigurationHelper::getInstance()
{
    static std::shared_ptr<ConfigurationHelper> jsonHelper{ new ConfigurationHelper };
    return jsonHelper;
}

json ConfigurationHelper::get(const std::string& key) const
{
    return configuration.at(key);
}