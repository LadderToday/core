#include <core/follow/follow_operations.hpp>

#include <core/protocol/operation_util_impl.hpp>

namespace core { namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } //core::follow

DEFINE_OPERATION_TYPE( core::follow::follow_plugin_operation )
