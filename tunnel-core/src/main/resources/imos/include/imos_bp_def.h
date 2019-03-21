/*******************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                             imos_bp_def.h
  Project Code: IMOS
  Module Name : OS
  Date Created: 2010-04-08
  Author      : wuxinmin/04253
  Description : OS模块随SDK发布而提供的对外头文件

  --------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
  --------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/

#ifndef _IMOS_BP_def_H_
#define _IMOS_BP_def_H_

/** 定义License数据的类型 */
enum BP_LICENSE_TYPE_E
{
    ETYPE_HOSTID        =  0, /**< 是hostid数据 */
    ETYPE_LICENSE       =  1, /**< 是License数据 */
    ETYPE_LICENSE_TRY   =  2, /**< 是试用版License数据 */
    ETYPE_COMMON        =  3  /**< 是通用数据 */
};

/** 备份的数据类型常量定义 */
typedef enum tagBPBackupType
{
    EBACKUP_CONF        = 0x01, /**< 备份配置文件 */

    EBACKUP_DB          = 0x02, /**< 备份数据库数据 */

    EBACKUP_LOG         = 0x04, /**< 备份运行日志文件 */

    EBACKUP_DBG         = 0x08, /**< 备份调试信息文件 */

    EBACKUP_SNAP        = 0x0A, /**< 备份网络抓包数据文件 */

    EBACKUP_ALL         = 0x0C  /**< 备份所有数据 */

} BP_BACKUPTYPE_E;


#endif /* _IMOS_BP_def_H_ */
