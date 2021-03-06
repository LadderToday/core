#pragma once

#include <core/app/application.hpp>

#include <core/account_by_key/account_by_key_objects.hpp>

#include <fc/api.hpp>

namespace core { namespace account_by_key {

namespace detail
{
   class account_by_key_api_impl;
}

class account_by_key_api
{
   public:
      account_by_key_api( const app::api_context& ctx );

      void on_api_startup();

      vector< vector< account_name_type > > get_key_references( vector< public_key_type > keys )const;

   private:
      std::shared_ptr< detail::account_by_key_api_impl > my;
};

} } // core::account_by_key

FC_API( core::account_by_key::account_by_key_api, (get_key_references) )
