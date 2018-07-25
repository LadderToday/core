#include <core/witness/witness_operations.hpp>

#include <core/protocol/operation_util_impl.hpp>

namespace core { namespace witness {

void enable_content_editing_operation::validate()const
{
   chain::validate_account_name( account );
}

} } // core::witness

DEFINE_OPERATION_TYPE( core::witness::witness_plugin_operation )
