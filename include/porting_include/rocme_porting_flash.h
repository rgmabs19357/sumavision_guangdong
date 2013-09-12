/*******************************************************************************
Copyright (C) BeiJing SUMAVision, Inc., 2009-2011 .All rights reserved.

File name   : rocme_porting_flash.h

Author      : DSM

Description : The poriting interface & macro definition for flash module.

History     :
              2009.12.20          Created         Jason
              2010.01.08          Modified        DSM
*******************************************************************************/
#ifndef _ROCME_PORTING_FLASH_H_
#define _ROCME_PORTING_FLASH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "rocme_porting_typedef.h"


/*++++++++++++++++++++++++++++     DEFINES     ++++++++++++++++++++++++++++*/


/*++++++++++++++++++++++++++++    FUNCTIONS    ++++++++++++++++++++++++++++*/


/**************************************************************************
��������: 
            rocme_porting_flash_init
����˵��: 
            flash�洢�豸��ʼ�����м����������ʱ���ô˺��������������м��
        ֮ǰ�������Ѿ�������flash�豸�ĳ�ʼ�����˺�������ʵ��Ϊ�գ�ֱ�ӷ���0��
����˵����
    ���������
            void
    ���������
            ��
��    �أ� 
    �ɹ� : 0            ( ��ʼ���ɹ� )
    ʧ�� : -1 �� ������ ( ��ʼ��ʧ�� )
�޸ļ�¼��
**************************************************************************/
INT32_T rocme_porting_flash_init(void);

/**************************************************************************
��������: 
            rocme_porting_flash_info
����˵��: 
            ���flash�洢�ռ����ʼ��ַ��������ÿ��ĳ��ȣ������RocME�м��
        ���ֵ�flash memoryÿ����ʳߴ���32k/64k/128k/256kBytes����flash����С
        �ռ䲻��С��512k��
����˵����
    ���������
            ��
    ���������
            [ *addr       ] : ������м����flash����ʼ��ַͷָ��
            [ num_of_sect ] : ������м����flash���ܿ���
            [ sect_size   ] : ������м����flash��ÿ��Ĵ�С
��    �أ� 
    �ɹ� : 0            ( flash������Ϣ��ȡ�ɹ� )
    ʧ�� : -1 �� ������ ( flash������Ϣ��ȡʧ�� )
�޸ļ�¼��
**************************************************************************/
INT32_T rocme_porting_flash_info(UINT8_T **addr, INT32_T *num_of_sect,  INT32_T *sect_size);

/**************************************************************************
��������: 
            rocme_porting_flash_read
����˵��: 
            ��ָ����flash�洢�ռ��ָ����ַ��ȡ���ݵ�ָ�������ݻ������С�
����˵����
    ���������
            [ flash_addr  ] : �м����ȡflash��Ŀ���ַ
            [ *buff_addr  ] : ��ȡ���ݵĴ洢������ͷָ��
            [ nbytes      ] : ��Ҫ��ȡ�ĳ���
    ���������
            ��
��    �أ� 
    �ɹ� : >=0����ֵ    ( ʵ�ʶ�ȡ�����ݳ��� )
    ʧ�� : -1 �� ������ ( ��ȡflash����ʧ��  )
�޸ļ�¼��
**************************************************************************/
INT32_T rocme_porting_flash_read(UINT32_T flash_addr, UINT8_T *buff_addr, INT32_T nbytes);

/**************************************************************************
��������: 
            rocme_porting_flash_burn
����˵��: 
            ��ָ��������д�뵽ָ����flash�洢���У�ʵ��Ϊͬ����ʽд�롣
����˵����
    ���������
            [ flash_addr  ] : �м��д��flash��Ŀ���ַ
            [ *buff_addr  ] : д�����ݵĴ洢������ͷָ��
            [ nbytes      ] : ��Ҫд��ĳ���
    ���������
            ��
��    �أ� 
    �ɹ� : >=0����ֵ    ( ʵ��д������ݳ��� )
    ʧ�� : -1 �� ������ ( д��flash����ʧ��  )
�޸ļ�¼��
**************************************************************************/
INT32_T rocme_porting_flash_burn(UINT32_T flash_addr, const UINT8_T *buff_addr, INT32_T nbytes);

/**************************************************************************
��������: 
            rocme_porting_flash_status
����˵��: 
            �жϵ�ǰflash��д��״̬���˺���Ŀǰ����Ҫ�󣬿���ʵ��Ϊ�գ�ֱ�ӷ�
        ���Ѿ�д�ɹ�( 1 )���ɡ�
����˵����
    ���������
            [ flash_addr  ] : �м��д��flash��Ŀ���ַ
            [ nbytes      ] : д��ĳ���
    ���������
            ��
��    �أ� 
    ����д :  0
    д�ɹ� :  1
    дʧ�� : -1 
�޸ļ�¼��
**************************************************************************/
INT32_T rocme_porting_flash_status(UINT32_T flash_addr, INT32_T nbytes);

/**************************************************************************
��������: 
            rocme_porting_flash_erase
����˵��: 
            ����ָ��flash�洢�ռ��е����ݡ�
����˵����
    ���������
            [ flash_addr  ] : �м����Ҫ����flash��Ŀ���ַ
            [ nbytes      ] : �����ĳ���
    ���������
            ��
��    �أ� 
    �ɹ� : 0            ( flash�����ɹ� )
    ʧ�� : -1 �� ������ ( flash����ʧ�� )
�޸ļ�¼��
**************************************************************************/
INT32_T rocme_porting_flash_erase(UINT32_T flash_addr, INT32_T nbytes);

/**************************************************************************
��������: 
            rocme_porting_get_iframe_data
����˵��: 
            ȡ��ָ��ID��I֡���ݣ�Ŀǰ�м��Ҫ����2��Ĭ��I֡��Iframe_idΪ0ʱ��
        ��������Ĭ�ϱ���֡��Iframe_idΪ1ʱ��������Ƶ��Ŀ����֡��ÿ��I֡��С
        ���ɳ���64Kb��
����˵����
    ���������
            [ Iframe_id     ] : I֡���
            [ *pdata        ] : �洢I֡buff��ͷָ��
            [ container_len ] : �洢I֡buff����󳤶ȣ�ĿǰRocME�м��������
                            Ϊ65536�ֽ�(64Kb)��С��
    ���������
            ��
��    �أ� 
    �ɹ� : 0            ( ��ȡI֡���ݳɹ� )
    ʧ�� : -1 �� ������ ( ��ȡI֡����ʧ�� )
�޸ļ�¼��
**************************************************************************/
INT32_T rocme_porting_get_iframe_data(UINT32_T Iframe_id,const UINT8_T *pdata,const UINT32_T container_len);

/**************************************************************************
��������: 
            rocme_porting_save_Iframe
����˵��: 
            ����I֡����Ӧ��I֡�洢�ռ䡣
����˵����
    ���������
            [ Iframe_id     ] : I֡���
            [ *pdata        ] : �洢I֡buff��ͷָ��
            [ container_len ] : I֡buff�ĳ��ȣ�ĿǰRocME�м�����������Ϊ
                            65536�ֽ�(64Kb)��С��
    ���������
            ��
��    �أ� 
    �ɹ� : 0            ( ����I֡���ݳɹ� )
    ʧ�� : -1 �� ������ ( ����I֡����ʧ�� )
�޸ļ�¼��
**************************************************************************/
INT32_T rocme_porting_save_Iframe(UINT32_T Iframe_id,const UINT8_T *pdata,const UINT32_T len); 

/**************************************************************************
��������: 
            rocme_porting_flash_save_boot_pic
����˵��: 
            ���濪��ͼƬ����Ӧ��flash�ռ䡣
����˵����
    ���������
            [ type          ] : �ļ����淽����0Ϊ�ڴ淽ʽ��1Ϊ�ļ���ʽ��
            [ *data_ptr     ] : ͼƬ�ڴ��ַ���ߴ洢·��
            [ data_len      ] : ͼƬ��С
    ���������
            ��
��    �أ� 
    �ɹ� : 0            ( �������ݳɹ� )
    ʧ�� : -1 �� ������ ( ��������ʧ�� )
ע�⣺
    ������ͼƬ����Ҫ������Ϣ10602.
**************************************************************************/
INT32_T rocme_porting_flash_save_boot_pic(UINT8_T type, const CHAR_T *data_ptr, const UINT32_T data_len);

/**************************************************************************
��������: 
            rocme_porting_flash_set_boot_tag
����˵��: 
            ��һ����ʶд������С�
����˵����
    ���������
            [ index         ] : �ñ�ʶָ����ʱ��2������Ӧ�ã�1��A��Ӧ�ã�0��Ĭ��Ӧ��
    ���������
            ��
��    �أ� 
    �ɹ� : 0            ( ������óɹ� )
    ʧ�� : -1 �� ������ ( �������ʧ�� )
�޸ļ�¼��
**************************************************************************/
INT32_T rocme_porting_flash_set_boot_tag(UINT32_T index);

#ifdef __cplusplus
}
#endif

#endif