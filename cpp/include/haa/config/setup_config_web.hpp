#pragma once
#ifndef HAA_CONFIG_SETUP_CONFIG_WEB_HPP_INCLUDE
#define HAA_CONFIG_SETUP_CONFIG_WEB_HPP_INCLUDE

#include "Empirical/include/emp/config/ArgManager.hpp"
#include "Empirical/include/emp/web/UrlParams.hpp"
#include "Empirical/include/emp/web/web.hpp"

#include "Config.hpp"
#include "try_read_config_file.hpp"

namespace haa {

void setup_config_web(haa::Config & config)  {
  auto specs = emp::ArgManager::make_builtin_specs(&config);
  emp::ArgManager am(emp::web::GetUrlParams(), specs);
  haa::try_read_config_file(config, am);
}

} // namespace haa

#endif // #ifndef HAA_CONFIG_SETUP_CONFIG_WEB_HPP_INCLUDE
