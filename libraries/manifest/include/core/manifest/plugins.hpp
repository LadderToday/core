
#pragma once

#include <memory>
#include <string>
#include <vector>

namespace core { namespace app {

class abstract_plugin;
class application;

} }

namespace core { namespace plugin {

void initialize_plugin_factories();
std::shared_ptr< core::app::abstract_plugin > create_plugin( const std::string& name, core::app::application* app );
std::vector< std::string > get_available_plugins();

} }
