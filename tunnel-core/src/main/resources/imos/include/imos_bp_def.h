/*******************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                             imos_bp_def.h
  Project Code: IMOS
  Module Name : OS
  Date Created: 2010-04-08
  Author      : wuxinmin/04253
  Description : OSģ����SDK�������ṩ�Ķ���ͷ�ļ�

  --------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
  --------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/

#ifndef _IMOS_BP_def_H_
#define _IMOS_BP_def_H_

/** ����License���ݵ����� */
enum BP_LICENSE_TYPE_E
{
    ETYPE_HOSTID        =  0, /**< ��hostid���� */
    ETYPE_LICENSE       =  1, /**< ��License���� */
    ETYPE_LICENSE_TRY   =  2, /**< �����ð�License���� */
    ETYPE_COMMON        =  3  /**< ��ͨ������ */
};

/** ���ݵ��������ͳ������� */
typedef enum tagBPBackupType
{
    EBACKUP_CONF        = 0x01, /**< ���������ļ� */

    EBACKUP_DB          = 0x02, /**< �������ݿ����� */

    EBACKUP_LOG         = 0x04, /**< ����������־�ļ� */

    EBACKUP_DBG         = 0x08, /**< ���ݵ�����Ϣ�ļ� */

    EBACKUP_SNAP        = 0x0A, /**< ��������ץ�������ļ� */

    EBACKUP_ALL         = 0x0C  /**< ������������ */

} BP_BACKUPTYPE_E;


#endif /* _IMOS_BP_def_H_ */
