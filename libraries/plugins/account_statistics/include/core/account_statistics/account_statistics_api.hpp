#pragma once

#include <core/account_statistics/account_statistics_plugin.hpp>

#include <fc/api.hpp>

namespace core{ namespace app {
   struct api_context;
} }

namespace core { namespace account_statistics {

namespace detail
{
   class account_statistics_api_impl;
}

class account_statistics_api
{
   public:
      account_statistics_api( const core::app::api_context& ctx );

      void on_api_startup();

   private:
      std::shared_ptr< detail::account_statistics_api_impl > _my;
};

} } // core::account_statistics

FC_API( core::account_statistics::account_statistics_api, )