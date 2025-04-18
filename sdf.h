/**
 * Created by LQQ on 2017/11/13.
 */
#ifndef _SDF_H_
#define _SDF_H_ 1

#ifdef __cplusplus
extern "C" {
#endif

#include "sdft.h"

#define __PASTE(x,y)      x##y


/* ==============================================================
 * Define the "extern" form of all the entry points.
 * ==============================================================
 */

#define SD_NEED_ARG_LIST  1
#define SDF_FUNCTION_INFO(name) \
  SD_DECLARE_FUNCTION(SGD_INT32, name)

#include "sdff.h"
#include "sdff_ex.h"

#undef SD_NEED_ARG_LIST
#undef SDF_FUNCTION_INFO

#define SD_NEED_ARG_LIST  1
#define SDF_FUNCTION_INFO(name) \
  typedef SD_DECLARE_FUNCTION_POINTER(SGD_INT32, __PASTE(CK_,name))

#include "sdff.h"
#include "sdff_ex.h"

#undef SD_NEED_ARG_LIST
#undef SDF_FUNCTION_INFO

#define SDF_FUNCTION_INFO(name) \
  __PASTE(CK_,name) name;

struct SDF_FUNCTION_LIST {
    //void * hHandle;
  #include "sdff.h"
  #include "sdff_ex.h"
};

#undef SDF_FUNCTION_INFO

#undef __PASTE


#ifdef __cplusplus
}
#endif

#endif
