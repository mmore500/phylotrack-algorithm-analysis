#include <iostream>

#include "Empirical/include/emp/base/vector.hpp"

#include "haa/config/Config.hpp"
#include "haa/config/setup_config_native.hpp"
#include "haa/example.hpp"

// This is the main function for the NATIVE version of Hereditary Stratigraphy Algorithm Analysis.

haa::Config cfg;

int main(int argc, char* argv[]) {
  // Set up a configuration panel for native application
  setup_config_native(cfg, argc, argv);
  cfg.Write(std::cout);

  std::cout << "Hello, world!" << "\n";

  return haa::example();
}
