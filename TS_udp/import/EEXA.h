/* EEXA.h  - Event and Error handler extern head file for windows */

/* modification history
-----------------------

01a 2015/12/21 ����һ 10:31:00  create by frank
*/

#ifndef EEXA_WIN_H
#define EEXA_WIN_H


#ifdef __cplusplus
extern "C" {
#endif

#include  "golytec.h"

#define     EEXA_MAX_OPTION_NAME_LEN        32      // �û�����ѡ��������󳤶�
#define     EEXA_MAX_OPTION_NUM             4       // �û�����ѡ��������

typedef char EEXA_OPTION[EEXA_MAX_OPTION_NAME_LEN];


typedef struct
{
    int num;                                        // �û���ѡ�Ĳ���ѡ�����
    int timeout;                                    // timeout���ȴ��û�ѡ���ʱ��
    int default_select;                             // Ĭ���û�ѡ���timeoutʱ�䵽���û����û��ѡ���Զ�ѡ����
    int filler;
    EEXA_OPTION option[EEXA_MAX_OPTION_NUM];        // ѡ����ʾ��Ϣ������"STOP��RETRY��CANCEL��YES��NO"��
} EEXA_USER_OPTIONS_STRUCT;



// errno number define
#define     EEXA_SYSTEM_ERROR                   0x45450000
#define     EEXA_TIMEOUT_ERROR                  0x45450001
#define     EEXA_PARAMETER_ERROR                0x45450002
#define     EEXA_ILLEGAL_CALL_ERROR             0x45450003
#define     EEXA_INVALID_ERROR_CODE             0x45450004
#define     EEXA_SERVER_NOT_LISTENING_ERROR     0x45450005

#define     EEXA_MSG_TOO_LARGE_ERROR            0x45450010
#define     EEXA_SAVE_FILE_ERROR                0x45450011


#ifndef EE_C

// ������ת�ַ���
extern int EEXA_error_to_string
            (
            IN      int error_code,             // ������
            OUT     char *buffer,               // �ַ�����Ż����ַ
            IN      int len                     // �����С
            );

// �ַ���ת������
extern int EEXA_string_to_error
            (
            IN      const char *buffer,         // �ַ�������
            OUT     int *error_code             // ������
            );

// ��¼����������־��Ϣ
extern int EEXA_log_info
            (
            IN      const char *format,         // ��¼����Ϣ����ʽ�ַ���
                                ...
            );

// ��¼�����쳣��Ϣ
// ���link_errorΪNULL���쳣��Ϣ��ͬʱ��ʾ�ڽ����ϡ�
extern int EEXA_log_error
            (
            IN      int error_code,             // ������
            IN      int *link_error,            // ���������ӣ��������10������ΪNULL��ʾ������
            IN      const char *file,           // ���������쳣���ڵ��ļ���(�Ƽ���д__FILE__)
            IN      int line,                   // ���������쳣���ڵ��ļ���(�Ƽ���д__LINE__)
            IN      const char *format,         // ��¼�Ĵ�����Ϣ����ʽ�ַ���
                                ...             // �ɱ����
            );

// ���û������쳣��Ϣ�����ȴ��û�ѡ���������ѡ������û�ѡ���
// �쳣��Ϣ���û���ѡ����¼���쳣��־�
extern int EEXA_report_error_to_user
            (
            IN      int error_code,                         // ������
            IN      int *link_error,                        // ���������ӣ��������10������ΪNULL��ʾ������
            IN      const char *file,                       // ���������쳣���ڵ��ļ���(�Ƽ���д__FILE__)
            IN      int line,                               // ���������쳣���ڵ��ļ���(�Ƽ���д__LINE__)
            IN      EEXA_USER_OPTIONS_STRUCT options,       // �û�ѡ�����
            OUT     int *user_select,                       // �����û�ѡ���ѡ����
            IN      const char *format,                     // ��ʾ�����Ĵ�����Ϣ����ʽ�ַ���
                                ...
            );


// ���û�����һЩ��Ϣ(���쳣)���������н�����ͳ����Ϣ��
// UI�ڽ����ϵ���һ���Ի�����ʾ��Ϣ���û���ȷ�ϼ��ɡ�
extern int EEXA_report_info_to_user
            (
            IN  const char *format,
                            ...
            );


// ��¼�����쳣��Ϣ���û�������־
// ���link_errorΪNULL���쳣��Ϣ��ͬʱ��ʾ�ڽ����ϡ�
extern int EEXA_log_user_error
            (
            IN      int error_code,             // ������
            IN      int *link_error,            // ���������ӣ��������10������ΪNULL��ʾ������
            IN      const char *file,           // ���������쳣���ڵ��ļ���(�Ƽ���д__FILE__)
            IN      int line,                   // ���������쳣���ڵ��ļ���(�Ƽ���д__LINE__)
            IN      const char *format,         // ��¼�Ĵ�����Ϣ����ʽ�ַ���
                                ...             // �ɱ����
            );




#endif // end of EE_C


#ifdef __cplusplus
}
#endif

#endif  // end of EEXA_WIN_H


