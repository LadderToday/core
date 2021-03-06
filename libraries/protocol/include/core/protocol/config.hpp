/*
 * Copyright (c) 2016 Steemit, Inc., and contributors.
 */
#pragma once

#define CORE_BLOCKCHAIN_VERSION              ( version(0, 20, 0) )
#define CORE_BLOCKCHAIN_HARDFORK_VERSION     ( hardfork_version( CORE_BLOCKCHAIN_VERSION ) )

#ifdef IS_TEST_NET
#define CORE_INIT_PRIVATE_KEY                (fc::ecc::private_key::regenerate(fc::sha256::hash(std::string("init_key"))))
#define CORE_INIT_PUBLIC_KEY_STR             (std::string( core::protocol::public_key_type(CORE_INIT_PRIVATE_KEY.get_public_key()) ))
#define CORE_CHAIN_ID                        (fc::sha256::hash("testnet"))

#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define STEEM_SYMBOL  (uint64_t(3) | (uint64_t('T') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< STEEM with 3 digits of precision
#define SBD_SYMBOL    (uint64_t(3) | (uint64_t('T') << 8) | (uint64_t('B') << 16) | (uint64_t('D') << 24) ) ///< Test Backed Dollars with 3 digits of precision
#define STMD_SYMBOL   (uint64_t(3) | (uint64_t('T') << 8) | (uint64_t('S') << 16) | (uint64_t('T') << 24) | (uint64_t('D') << 32) ) ///< Test Dollars with 3 digits of precision

#define CORE_SYMBOL                          "TEST"
#define CORE_ADDRESS_PREFIX                  "TST"

// 1451606400 ~ Sun Jan 18 1970 02:13:26 GMT+0700 (+08)
// 1515765200 ~ Fri Jan 12 2018 20:53:20 GMT+0700 (+08)
//#define CORE_GENESIS_TIME                    (fc::time_point_sec(1451606400))
#define CORE_GENESIS_TIME                    (fc::time_point_sec(1515765200))
//#define CORE_MINING_TIME                     (fc::time_point_sec(1451606400))
#define CORE_MINING_TIME                     (fc::time_point_sec(1515765200))
#define CORE_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define CORE_CASHOUT_WINDOW_SECONDS_PRE_HF12 (CORE_CASHOUT_WINDOW_SECONDS)
#define CORE_CASHOUT_WINDOW_SECONDS_PRE_HF17 (CORE_CASHOUT_WINDOW_SECONDS)
#define CORE_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define CORE_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define CORE_VOTE_CHANGE_LOCKOUT_PERIOD      (60*10) /// 10 minutes
#define CORE_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define CORE_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define CORE_ORIGINAL_MIN_ACCOUNT_CREATION_FEE 0
#define CORE_MIN_ACCOUNT_CREATION_FEE          0

#define CORE_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define CORE_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define CORE_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define CORE_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1
#else // IS LIVE STEEM NETWORK

#define CORE_INIT_PUBLIC_KEY_STR             "SMK6LLegbAgLAy28EHrffBVuANFWcFgmqRMW13wBmTExqFE9SCkg4"
#define CORE_CHAIN_ID                        (fc::sha256::hash("core")) // a66e00caa50e6817bbe24e927bf48c5d4ba1b33f36bdbb5fa262a04012c4e3ee
#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define STEEM_SYMBOL  (uint64_t(3) | (uint64_t('L') << 8) | (uint64_t('A') << 16) | (uint64_t('D') << 24) | (uint64_t('D') << 32) | (uint64_t('R') << 40)) ///< CORE with 3 digits of precision
#define SBD_SYMBOL    (uint64_t(3) | (uint64_t('L') << 8) | (uint64_t('T') << 16) | (uint64_t('D') << 24) ) ///< CORE Backed Dollars with 3 digits of precision
#define STMD_SYMBOL   (uint64_t(3) | (uint64_t('L') << 8) | (uint64_t('T') << 16) | (uint64_t('D') << 24) | (uint64_t('T') << 32) ) ///< CORE Dollars with 3 digits of precision
#define CORE_SYMBOL                          "LADDR"
#define CORE_ADDRESS_PREFIX                  "LTDT"

#define CORE_GENESIS_TIME_EPOCH              1518000000  // Wed Feb 07 2018 17:40:00 GMT+0700 (+07)
#define CORE_GENESIS_TIME                    (fc::time_point_sec(CORE_GENESIS_TIME_EPOCH))
#define CORE_MINING_TIME                     (fc::time_point_sec(CORE_GENESIS_TIME_EPOCH + 9000))
#define CORE_CASHOUT_WINDOW_SECONDS_PRE_HF12 (60*60*24)    /// 1 day
#define CORE_CASHOUT_WINDOW_SECONDS_PRE_HF17 (60*60*12)    /// 12 hours
#define CORE_CASHOUT_WINDOW_SECONDS          (60*60*24*7)  /// 7 days
#define CORE_SECOND_CASHOUT_WINDOW           (60*60*24*30) /// 30 days
#define CORE_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24*14) /// 2 weeks
#define CORE_VOTE_CHANGE_LOCKOUT_PERIOD      (60*60*2)     /// 2 hours
#define CORE_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define CORE_UPVOTE_LOCKOUT_HF17             (fc::hours(12))

#define CORE_ORIGINAL_MIN_ACCOUNT_CREATION_FEE  100000
#define CORE_MIN_ACCOUNT_CREATION_FEE           0 // 1

#define CORE_OWNER_AUTH_RECOVERY_PERIOD                  fc::days(30)
#define CORE_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::days(1)
#define CORE_OWNER_UPDATE_LIMIT                          fc::minutes(60)
#define CORE_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1 // 3186477

#endif

#define CORE_BLOCK_INTERVAL                  3
#define CORE_BLOCKS_PER_YEAR                 (365*24*60*60/CORE_BLOCK_INTERVAL)
#define CORE_BLOCKS_PER_DAY                  (24*60*60/CORE_BLOCK_INTERVAL)
#define CORE_START_VESTING_BLOCK             (CORE_BLOCKS_PER_DAY * 7)
//#define CORE_START_MINER_VOTING_BLOCK        (CORE_BLOCKS_PER_DAY * 30)
#define CORE_START_MINER_VOTING_BLOCK        (1 * 30)

#define CORE_INIT_MINER_NAME                 "initminer"
#define CORE_NUM_INIT_MINERS                 1
#define CORE_INIT_TIME                       (fc::time_point_sec());

#define CORE_MAX_WITNESSES                   5 // 21
#define CORE_MAX_VOTED_WITNESSES_HF0         3 // 19
#define CORE_MAX_MINER_WITNESSES_HF0         1
#define CORE_MAX_RUNNER_WITNESSES_HF0        1

#define CORE_MAX_VOTED_WITNESSES_HF17        4 // 20
#define CORE_MAX_MINER_WITNESSES_HF17        0
#define CORE_MAX_RUNNER_WITNESSES_HF17       1

#define CORE_HARDFORK_REQUIRED_WITNESSES     3 // 17 of the 21 dpos witnesses (20 elected and 1 virtual time) required for hardfork. This guarantees 75% participation on all subsequent rounds.
#define CORE_MAX_TIME_UNTIL_EXPIRATION       (60*60) // seconds,  aka: 1 hour
#define CORE_MAX_MEMO_SIZE                   2048
#define CORE_MAX_PROXY_RECURSION_DEPTH       4
#define CORE_VESTING_WITHDRAW_INTERVALS_PRE_HF_16 104
#define CORE_VESTING_WITHDRAW_INTERVALS      13
#define CORE_VESTING_WITHDRAW_INTERVAL_SECONDS (60*60*24*7) /// 1 week per interval

#define CORE_MAX_WITHDRAW_ROUTES             10
#define CORE_SAVINGS_WITHDRAW_TIME        	(fc::days(3))
#define CORE_SAVINGS_WITHDRAW_REQUEST_LIMIT  100
#define CORE_VOTE_REGENERATION_SECONDS       (5*60*60*24) // 5 day
#define CORE_MAX_VOTE_CHANGES                5
#define CORE_REVERSE_AUCTION_WINDOW_SECONDS  (60*30) /// 30 minutes
#define CORE_MIN_VOTE_INTERVAL_SEC           3
#define CORE_VOTE_DUST_THRESHOLD             (50000000)

#define CORE_MIN_ROOT_COMMENT_INTERVAL       (fc::seconds(60*5)) // 5 minutes
#define CORE_MIN_REPLY_INTERVAL              (fc::seconds(20)) // 20 seconds
#define CORE_POST_AVERAGE_WINDOW             (60*60*24u) // 1 day
#define CORE_POST_MAX_BANDWIDTH              (4*CORE_100_PERCENT) // 2 posts per 1 days, average 1 every 12 hours
#define CORE_POST_WEIGHT_CONSTANT            (uint64_t(CORE_POST_MAX_BANDWIDTH) * CORE_POST_MAX_BANDWIDTH)

#define CORE_MAX_ACCOUNT_WITNESS_VOTES       30

#define CORE_100_PERCENT                     10000
#define CORE_1_PERCENT                       (CORE_100_PERCENT/100)
#define CORE_1_TENTH_PERCENT                 (CORE_100_PERCENT/1000)
#define CORE_DEFAULT_SBD_INTEREST_RATE       (10*CORE_1_PERCENT) ///< 10% APR

//#define CORE_INFLATION_RATE_START_PERCENT    (978) // Fixes block 7,000,000 to 9.5%
#define CORE_INFLATION_RATE_START_PERCENT    (97) // reduce to ~ CORE_INFLATION_RATE_STOP_PERCENT
#define CORE_INFLATION_RATE_STOP_PERCENT     (95) // 0.95%
#define CORE_INFLATION_NARROWING_PERIOD      (250000) // Narrow 0.01% every 250k blocks
#define CORE_CONTENT_REWARD_PERCENT          (75*CORE_1_PERCENT) //75% of inflation, 7.125% inflation
#define CORE_VESTING_FUND_PERCENT            (15*CORE_1_PERCENT) //15% of inflation, 1.425% inflation

#define CORE_MINER_PAY_PERCENT               (CORE_1_PERCENT) // 1%
#define CORE_MIN_RATION                      100000
#define CORE_MAX_RATION_DECAY_RATE           (1000000)
#define CORE_FREE_TRANSACTIONS_WITH_NEW_ACCOUNT 100

#define CORE_BANDWIDTH_AVERAGE_WINDOW_SECONDS (60*60*24*7) ///< 1 week
#define CORE_BANDWIDTH_PRECISION             (uint64_t(1000000)) ///< 1 million
#define CORE_MAX_COMMENT_DEPTH_PRE_HF17      6
#define CORE_MAX_COMMENT_DEPTH               0xffff // 64k
#define CORE_SOFT_MAX_COMMENT_DEPTH          0xff // 255

#define CORE_MAX_RESERVE_RATIO               (20000)

#define CORE_CREATE_ACCOUNT_WITH_STEEM_MODIFIER 30
#define CORE_CREATE_ACCOUNT_DELEGATION_RATIO    5
#define CORE_CREATE_ACCOUNT_DELEGATION_TIME     fc::days(30)

#define CORE_MINING_REWARD                   asset( 1000, STEEM_SYMBOL )
#define CORE_EQUIHASH_N                      140
#define CORE_EQUIHASH_K                      6

#define CORE_LIQUIDITY_TIMEOUT_SEC           (fc::seconds(60*60*24*7)) // After one week volume is set to 0
#define CORE_MIN_LIQUIDITY_REWARD_PERIOD_SEC (fc::seconds(60)) // 1 minute required on books to receive volume
#define CORE_LIQUIDITY_REWARD_PERIOD_SEC     (60*60)
#define CORE_LIQUIDITY_REWARD_BLOCKS         (CORE_LIQUIDITY_REWARD_PERIOD_SEC/CORE_BLOCK_INTERVAL)
#define CORE_MIN_LIQUIDITY_REWARD            (asset( 1000*CORE_LIQUIDITY_REWARD_BLOCKS, STEEM_SYMBOL )) // Minumum reward to be paid out to liquidity providers
#define CORE_MIN_CONTENT_REWARD              CORE_MINING_REWARD
#define CORE_MIN_CURATE_REWARD               CORE_MINING_REWARD
#define CORE_MIN_PRODUCER_REWARD             CORE_MINING_REWARD
#define CORE_MIN_POW_REWARD                  CORE_MINING_REWARD

#define CORE_ACTIVE_CHALLENGE_FEE            asset( 2000, STEEM_SYMBOL )
#define CORE_OWNER_CHALLENGE_FEE             asset( 30000, STEEM_SYMBOL )
#define CORE_ACTIVE_CHALLENGE_COOLDOWN       fc::days(1)
#define CORE_OWNER_CHALLENGE_COOLDOWN        fc::days(1)

#define CORE_POST_REWARD_FUND_NAME           ("post")
#define CORE_COMMENT_REWARD_FUND_NAME        ("comment")
#define CORE_RECENT_RSHARES_DECAY_RATE_HF17  (fc::days(30))
#define CORE_RECENT_RSHARES_DECAY_RATE_HF19  (fc::days(15))
#define CORE_CONTENT_CONSTANT_HF0            (uint128_t(uint64_t(2000000000000ll)))
// note, if redefining these constants make sure calculate_claims doesn't overflow

// 5ccc e802 de5f
// int(expm1( log1p( 1 ) / BLOCKS_PER_YEAR ) * 2**CORE_APR_PERCENT_SHIFT_PER_BLOCK / 100000 + 0.5)
// we use 100000 here instead of 10000 because we end up creating an additional 9x for vesting
#define CORE_APR_PERCENT_MULTIPLY_PER_BLOCK          ( (uint64_t( 0x5ccc ) << 0x20) \
                                                        | (uint64_t( 0xe802 ) << 0x10) \
                                                        | (uint64_t( 0xde5f )        ) \
                                                        )
// chosen to be the maximal value such that CORE_APR_PERCENT_MULTIPLY_PER_BLOCK * 2**64 * 100000 < 2**128
#define CORE_APR_PERCENT_SHIFT_PER_BLOCK             87

#define CORE_APR_PERCENT_MULTIPLY_PER_ROUND          ( (uint64_t( 0x79cc ) << 0x20 ) \
                                                        | (uint64_t( 0xf5c7 ) << 0x10 ) \
                                                        | (uint64_t( 0x3480 )         ) \
                                                        )

#define CORE_APR_PERCENT_SHIFT_PER_ROUND             83

// We have different constants for hourly rewards
// i.e. hex(int(math.expm1( math.log1p( 1 ) / HOURS_PER_YEAR ) * 2**CORE_APR_PERCENT_SHIFT_PER_HOUR / 100000 + 0.5))
#define CORE_APR_PERCENT_MULTIPLY_PER_HOUR           ( (uint64_t( 0x6cc1 ) << 0x20) \
                                                        | (uint64_t( 0x39a1 ) << 0x10) \
                                                        | (uint64_t( 0x5cbd )        ) \
                                                        )

// chosen to be the maximal value such that CORE_APR_PERCENT_MULTIPLY_PER_HOUR * 2**64 * 100000 < 2**128
#define CORE_APR_PERCENT_SHIFT_PER_HOUR              77

// These constants add up to GRAPHENE_100_PERCENT.  Each GRAPHENE_1_PERCENT is equivalent to 1% per year APY
// *including the corresponding 9x vesting rewards*
#define CORE_CURATE_APR_PERCENT              3875
#define CORE_CONTENT_APR_PERCENT             3875
#define CORE_LIQUIDITY_APR_PERCENT            750
#define CORE_PRODUCER_APR_PERCENT             750
#define CORE_POW_APR_PERCENT                  750

#define CORE_MIN_PAYOUT_SBD                  (asset(20,SBD_SYMBOL))
#define CORE_MIN_PAYOUT_STEEM                20

#define CORE_SBD_STOP_PERCENT                (5*CORE_1_PERCENT ) // Stop printing SBD at 5% Market Cap
#define CORE_SBD_START_PERCENT               (2*CORE_1_PERCENT) // Start reducing printing of SBD at 2% Market Cap

#define CORE_MIN_ACCOUNT_NAME_LENGTH          3
#define CORE_MAX_ACCOUNT_NAME_LENGTH         16

#define CORE_MIN_PERMLINK_LENGTH             0
#define CORE_MAX_PERMLINK_LENGTH             256
#define CORE_MAX_WITNESS_URL_LENGTH          2048

#define CORE_INIT_SUPPLY                     int64_t(349379987000ll) // 50m = 50000000000ll, 349379987
#define CORE_MAX_SHARE_SUPPLY                int64_t(1000000000000000ll)
#define CORE_MAX_SIG_CHECK_DEPTH             2

#define CORE_INIT_SUPPLY_SBD                 int64_t(1000000000ll) // 1000000000ll = 1m tokens

#define CORE_MIN_TRANSACTION_SIZE_LIMIT      1024
#define CORE_SECONDS_PER_YEAR                (uint64_t(60*60*24*365ll))

#define CORE_SBD_INTEREST_COMPOUND_INTERVAL_SEC  (60*60*24*30)
#define CORE_MAX_TRANSACTION_SIZE            (1024*64)
#define CORE_MIN_BLOCK_SIZE_LIMIT            (CORE_MAX_TRANSACTION_SIZE)
#define CORE_MAX_BLOCK_SIZE                  (CORE_MAX_TRANSACTION_SIZE*CORE_BLOCK_INTERVAL*2000)
#define CORE_SOFT_MAX_BLOCK_SIZE             (2*1024*1024)
#define CORE_MIN_BLOCK_SIZE                  115
#define CORE_BLOCKS_PER_HOUR                 (60*60/CORE_BLOCK_INTERVAL)
#define CORE_FEED_INTERVAL_BLOCKS            (CORE_BLOCKS_PER_HOUR)
//#define CORE_FEED_INTERVAL_BLOCKS            (120)
#define CORE_FEED_HISTORY_WINDOW_PRE_HF_16   (24*7) /// 7 days * 24 hours per day
//#define CORE_FEED_HISTORY_WINDOW_PRE_HF_16   (1)
#define CORE_FEED_HISTORY_WINDOW             (12*7) // 3.5 days
//#define CORE_FEED_HISTORY_WINDOW             (1) // 1h
//#define CORE_MAX_FEED_AGE_SECONDS            (60*60*24*7) // 7 days
#define CORE_MAX_FEED_AGE_SECONDS            (60*60*24*365*10) // 10 years
#define CORE_MIN_FEEDS                       (CORE_MAX_WITNESSES/3) /// protects the network from conversions before price has been established
//#define CORE_MIN_FEEDS                       (1) /// protects the network from conversions before price has been established
#define CORE_CONVERSION_DELAY_PRE_HF_16      (fc::days(7))
#define CORE_CONVERSION_DELAY                (fc::hours(CORE_FEED_HISTORY_WINDOW)) //3.5 day conversion

#define CORE_MIN_UNDO_HISTORY                10
#define CORE_MAX_UNDO_HISTORY                10000

#define CORE_MIN_TRANSACTION_EXPIRATION_LIMIT (CORE_BLOCK_INTERVAL * 5) // 5 transactions per block
#define CORE_BLOCKCHAIN_PRECISION            uint64_t( 1000 )

#define CORE_BLOCKCHAIN_PRECISION_DIGITS     3
#define CORE_MAX_INSTANCE_ID                 (uint64_t(-1)>>16)
/** NOTE: making this a power of 2 (say 2^15) would greatly accelerate fee calcs */
#define CORE_MAX_AUTHORITY_MEMBERSHIP        10
#define CORE_MAX_ASSET_WHITELIST_AUTHORITIES 10
#define CORE_MAX_URL_LENGTH                  127

#define CORE_IRREVERSIBLE_THRESHOLD          (75 * CORE_1_PERCENT)

#define VIRTUAL_SCHEDULE_LAP_LENGTH  ( fc::uint128(uint64_t(-1)) )
#define VIRTUAL_SCHEDULE_LAP_LENGTH2 ( fc::uint128::max_value() )

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the current witnesses
#define CORE_MINER_ACCOUNT                   "miners"
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define CORE_NULL_ACCOUNT                    "null"
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define CORE_TEMP_ACCOUNT                    "temp"
/// Represents the canonical account for specifying you will vote for directly (as opposed to a proxy)
#define CORE_PROXY_TO_SELF_ACCOUNT           ""
/// Represents the canonical root post parent account
#define CORE_ROOT_POST_PARENT                (account_name_type())
///@}
