#pragma once
#ifndef HAA_CONFIG_SETUP_CONFIG_NATIVE_HPP_INCLUDE
#define HAA_CONFIG_SETUP_CONFIG_NATIVE_HPP_INCLUDE

#include "Empirical/include/emp/config/ArgManager.hpp"

#include "try_read_config_file.hpp"

namespace haa {

void setup_config_native(haa::Config & config, int argc, char* argv[]) {
  auto specs = emp::ArgManager::make_builtin_specs(&config);
  emp::ArgManager am(argc, argv, specs);
  haa::try_read_config_file(config, am);
}

} // namespace haa

#endif // #ifndef HAA_CONFIG_SETUP_CONFIG_NATIVE_HPP_INCLUDE
