/*******************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_mp_def.h
  Project Code: IMOS
   Module Name: MP
  Date Created: 2010-04-09
        Author: yanaijie06242
   Description: MP的公共头文件

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef __IMOS_MP_DEF_H__
#define __IMOS_MP_DEF_H__

/** 存储资源运行状态 */
enum
{
    ISM_RES_FAILURE                = 0UL,           /**< 资源无法访问 */
    ISM_RES_NORMAL                 = 1UL,           /**< 资源访问正常 */
    ISM_RES_UNKNOW                 = 2UL            /**< 未知 */
};


#endif /* __IMOS_MP_DEF_H__ */


