#pragma once

#include <core/chain/evaluator.hpp>

#include <core/private_message/private_message_operations.hpp>
#include <core/private_message/private_message_plugin.hpp>

namespace core { namespace private_message {

DEFINE_PLUGIN_EVALUATOR( private_message_plugin, core::private_message::private_message_plugin_operation, private_message )

} }
