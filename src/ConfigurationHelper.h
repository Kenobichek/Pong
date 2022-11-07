#pragma once
#include <string>
#include <fstream>
#include <memory>
#include "json.h"

class ConfigurationHelper
{
public:
	static std::shared_ptr<ConfigurationHelper> getInstance();
	json get(const std::string& key) const;
	
	ConfigurationHelper(ConfigurationHelper const&) = delete;
	ConfigurationHelper& operator=(ConfigurationHelper const&) = delete;

private:
	ConfigurationHelper();
	json configuration;
};