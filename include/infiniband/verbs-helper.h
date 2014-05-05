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

END_C_DECLS

#  undef __attribute_const


#endif /* INFINIBAND_VERBS_HELPER_H */
