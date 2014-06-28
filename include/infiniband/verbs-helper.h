#ifndef INFINIBAND_VERBS_HELPER_H
#define INFINIBAND_VERBS_HELPER_H

#include <infiniband/verbs.h>

#ifdef __cplusplus
#  define BEGIN_C_DECLS extern "C" {
#  define END_C_DECLS   }
#else /* !__cplusplus */
#  define BEGIN_C_DECLS
#  define END_C_DECLS
#endif /* __cplusplus */

#if __GNUC__ >= 3
#  define __attribute_const __attribute__((const))
#else
#  define __attribute_const
#endif

BEGIN_C_DECLS

/* The endoding for he RNR NAK Timer field.
   The delay is specified in milliseconds.

   For example:
	IBV_HELPER_RNR_TIMER_655_36 encodes delay of 655.36 milliseconds
	IBV_HELPER_RNR_TIMER_000_01 encodes delay of 0.01 milliseconds
*/
enum ibv_helper_rnr_timeout {
	IBV_HELPER_RNR_TIMER_655_36 =  0,
	IBV_HELPER_RNR_TIMER_000_01 =  1,
	IBV_HELPER_RNR_TIMER_000_02 =  2,
	IBV_HELPER_RNR_TIMER_000_03 =  3,
	IBV_HELPER_RNR_TIMER_000_04 =  4,
	IBV_HELPER_RNR_TIMER_000_06 =  5,
	IBV_HELPER_RNR_TIMER_000_08 =  6,
	IBV_HELPER_RNR_TIMER_000_12 =  7,
	IBV_HELPER_RNR_TIMER_000_16 =  8,
	IBV_HELPER_RNR_TIMER_000_24 =  9,
	IBV_HELPER_RNR_TIMER_000_32 = 10,
	IBV_HELPER_RNR_TIMER_000_48 = 11,
	IBV_HELPER_RNR_TIMER_000_64 = 12,
	IBV_HELPER_RNR_TIMER_000_96 = 13,
	IBV_HELPER_RNR_TIMER_001_28 = 14,
	IBV_HELPER_RNR_TIMER_001_92 = 15,
	IBV_HELPER_RNR_TIMER_002_56 = 16,
	IBV_HELPER_RNR_TIMER_003_84 = 17,
	IBV_HELPER_RNR_TIMER_005_12 = 18,
	IBV_HELPER_RNR_TIMER_007_68 = 19,
	IBV_HELPER_RNR_TIMER_010_24 = 20,
	IBV_HELPER_RNR_TIMER_015_36 = 21,
	IBV_HELPER_RNR_TIMER_020_48 = 22,
	IBV_HELPER_RNR_TIMER_030_72 = 23,
	IBV_HELPER_RNR_TIMER_040_96 = 24,
	IBV_HELPER_RNR_TIMER_061_44 = 25,
	IBV_HELPER_RNR_TIMER_081_92 = 26,
	IBV_HELPER_RNR_TIMER_122_88 = 27,
	IBV_HELPER_RNR_TIMER_163_84 = 28,
	IBV_HELPER_RNR_TIMER_245_76 = 29,
	IBV_HELPER_RNR_TIMER_327_68 = 30,
	IBV_HELPER_RNR_TIMER_491_52 = 31
};

enum ibv_helper_phys_port_state {
	IBV_HELPER_PHYS_PORT_SLEEP			  = 1,
	IBV_HELPER_PHYS_PORT_POLLING			  = 2,
	IBV_HELPER_PHYS_PORT_DISABLED			  = 3,
	IBV_HELPER_PHYS_PORT_PORT_CONFIGURATION_TRAINNING = 4,
	IBV_HELPER_PHYS_PORT_LINK_UP			  = 5,
	IBV_HELPER_PHYS_PORT_LINK_ERROR_RECOVERY	  = 6,
	IBV_HELPER_PHYS_PORT_PHY_TEST			  = 7,
};

enum ibv_helper_max_vl {
	IBV_HELPER_MAX_VL_1  = 1,
	IBV_HELPER_MAX_VL_2  = 2,
	IBV_HELPER_MAX_VL_4  = 3,
	IBV_HELPER_MAX_VL_8  = 4,
	IBV_HELPER_MAX_VL_15 = 5,
};

END_C_DECLS


/**
 * ibv_helper_modify_block_mode_comp_channel - Modifies the blocking mode of a
 *                                             specified completion event channel.
 * @channel:    Completion channel to modify.
 * @use_block:  if non-zero, modify the Completion channel to work in blocking
 *              mode. If zero, modify the Completion channel to work in
 *              non-blocking mode.
 *
 * This function returns 0 on success and returns -1 on failure
 * (errno indicates the failure reason).
 */
int ibv_helper_modify_block_mode_comp_channel(struct ibv_comp_channel *channel,
					      int use_block);


#  undef __attribute_const


#endif /* INFINIBAND_VERBS_HELPER_H */
