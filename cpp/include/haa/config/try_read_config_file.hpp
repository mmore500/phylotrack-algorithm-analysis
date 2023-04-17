#pragma once
#ifndef HAA_CONFIG_TRY_READ_CONFIG_FILE_HPP_INCLUDE
#define HAA_CONFIG_TRY_READ_CONFIG_FILE_HPP_INCLUDE

#include <cstdlib>
#include <filesystem>
#include <iostream>

#include "Config.hpp"

namespace haa {

void try_read_config_file(haa::Config & config, emp::ArgManager & am) {
  if(std::filesystem::exists("haa.cfg")) {
    std::cout << "Configuration read from haa.cfg" << '\n';
    config.Read("haa.cfg");
  }
  am.UseCallbacks();
  if (am.HasUnused())
    std::exit(EXIT_FAILURE);
}

} // namespace haa

#endif // #ifndef HAA_CONFIG_TRY_READ_CONFIG_FILE_HPP_INCLUDE
