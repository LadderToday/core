#pragma once
#include <core/protocol/block_header.hpp>
#include <core/protocol/transaction.hpp>

namespace core { namespace protocol {

   struct signed_block : public signed_block_header
   {
      checksum_type calculate_merkle_root()const;
      vector<signed_transaction> transactions;
   };

} } // core::protocol

FC_REFLECT_DERIVED( core::protocol::signed_block, (core::protocol::signed_block_header), (transactions) )
