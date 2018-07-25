#pragma once

#include <core/chain/util/asset.hpp>
#include <core/chain/steem_objects.hpp>

#include <core/protocol/asset.hpp>
#include <core/protocol/config.hpp>
#include <core/protocol/types.hpp>

#include <fc/reflect/reflect.hpp>

#include <fc/uint128.hpp>

namespace core { namespace chain { namespace util {

using core::protocol::asset;
using core::protocol::price;
using core::protocol::share_type;

using fc::uint128_t;

struct comment_reward_context
{
   share_type rshares;
   uint16_t   reward_weight = 0;
   asset      max_sbd; // sbd is disabled, value in STEEM_SYMBOL
   uint128_t  total_reward_shares2;
   asset      total_reward_fund_steem;
   price      current_steem_price;
   curve_id   reward_curve = quadratic;
   uint128_t  content_constant = CORE_CONTENT_CONSTANT_HF0;
};

uint64_t get_rshare_reward( const comment_reward_context& ctx, bool has_hardfork_0_20 );

inline uint128_t get_content_constant_s()
{
   return CORE_CONTENT_CONSTANT_HF0; // looking good for posters
}

uint128_t evaluate_reward_curve( const uint128_t& rshares, const curve_id& curve = quadratic, const uint128_t& content_constant = CORE_CONTENT_CONSTANT_HF0 );

inline bool is_comment_payout_dust( const price& p, uint64_t steem_payout )
{
   return to_sbd( p, asset( steem_payout, STEEM_SYMBOL ) ) < CORE_MIN_PAYOUT_SBD;
//   return steem_payout < uint64_t(CORE_MIN_PAYOUT_SBD.amount.value);
}

} } } // core::chain::util

FC_REFLECT( core::chain::util::comment_reward_context,
   (rshares)
   (reward_weight)
   (max_sbd)
   (total_reward_shares2)
   (total_reward_fund_steem)
   (current_steem_price)
   (reward_curve)
   (content_constant)
   )