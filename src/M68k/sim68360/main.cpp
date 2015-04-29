// Instantiates all of the objects and starts the user interface command parser.

#include "Framework/Interface.hpp"
#include "M68k/sim68360/cpu32.hpp"
#include "M68k/devices/DeviceRegistry.hpp"
#include "M68k/loader/Loader.hpp"

int main() {
  BasicCPU &processor = *(new cpu32);
  BasicLoader &loader = *(new Loader(processor));
  BasicDeviceRegistry &registry = *(new DeviceRegistry);

  Interface interface(processor, registry, loader);
  interface.CommandLoop();

  delete &registry;
  delete &loader;
  delete &processor;

  return 0;
}
