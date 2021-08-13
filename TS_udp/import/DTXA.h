/* DTXA.h  - Data Trace handler(DT) extern head file for windows */

/* modification history
-----------------------

01a 2015/12/21 ����һ 10:24:02  create by frank
*/

#ifndef DTXA_H
#define DTXA_H


#ifdef __cplusplus
extern "C" {
#endif

#include "golytec.h"


typedef enum
{
    DTXA_SIM_DISABLED,
    DTXA_SIM_MODE_1,
    DTXA_SIM_MODE_2
} DTXA_SIM_MODE_ENUM;


typedef enum
{
    DTXA_TRACE_DISABLED,
    DTXA_TRACE_INT,
    DTXA_TRACE_EXT,
    DTXA_TRACE_INT_EXT,
    DTXA_TRACE_DEBUG,
    DTXA_TRACE_INT_DEBUG,
    DTXA_TRACE_ALL
} DTXA_TRACE_MODE_ENUM;


typedef enum
{
    DTXA_REQ_DISABLED,          // 0
    DTXA_REQ_INT_INPUT,         // 1
    DTXA_REQ_INT_OUTPUT,        // 2
    DTXA_REQ_INT_INOUT,         // 3
    DTXA_REQ_EXT_INPUT,         // 4
    DTXA_REQ_EXT_OUTPUT,        // 5
    DTXA_REQ_EXT_INOUT,         // 6
    DTXA_REQ_INT_EXT_INPUT,     // 7
    DTXA_REQ_INT_EXT_OUTPUT,    // 8
    DTXA_REQ_INT_EXT_INOUT      // 9
} DTXA_REQ_MODE_ENUM;



// errno number define
#define   DTXA_SYSTEM_ERROR               0x44540000
#define   DTXA_TIMEOUT_ERROR              0x44540001
#define   DTXA_PARAMETER_ERROR            0x44540002
#define   DTXA_ILLEGAL_CALL_ERROR         0x44540003
#define   DTXA_NOT_INITIALIZED_ERROR      0x44540004
#define   DTXA_NOT_TERMINATED_ERROR       0x44540005
#define   DTXA_SERVER_NOT_LISTENING_ERROR  0x44540006
#define   DTXA_BUFF_ERROR                 0x44540007
#define   DTXA_INVALID_FORMAT_ERROR       0x44540008



#ifndef DT_C

// ���������ģʽ����������ģʽ������ģʽ�������޸�ģʽ
extern int DTXA_set_mode
                    (
                    IN      const char *comp_id,                    // ������� ��"TA"
                    IN      DTXA_SIM_MODE_ENUM sim_mode,            // ����ģʽ
                    IN      DTXA_TRACE_MODE_ENUM trace_mode,        // ����ģʽ
                    IN      DTXA_REQ_MODE_ENUM data_mode            // �����޸�ģʽ
                    );

// ��ȡ�����ǰ��ģʽ����
extern int DTXA_get_mode
                    (
                    IN      const char *comp_id,                    // �����
                    OUT     DTXA_SIM_MODE_ENUM *sim_mode,           // ����ģʽ
                    OUT     DTXA_TRACE_MODE_ENUM *trace_mode,       // ����ģʽ
                    OUT     DTXA_REQ_MODE_ENUM *data_mode           // �����޸�ģʽ
                    );

// ���ݸ��ټ�¼
extern void DTXA_trace
                    (
                    IN      const char *comp_id,                    // �����
                    IN      DTXA_TRACE_MODE_ENUM from_where,        // ����ģʽ
                    IN      const char *func_name,                  // ��ǰ��������(�Ƽ���д__FUNCTION__)
                    IN      const char *format_spec,                // ��ʾ�����ݸ�ʽ�ַ���
                                        ...                         // �ɱ����
                    );

// ���ݸ��ټ�¼��va_list��ʽ�ӿ�
extern void DTXA_trace_v
                    (
                    IN      const char *comp_id,                    // �����
                    IN      DTXA_TRACE_MODE_ENUM from_where,        // ����ģʽ
                    IN      const char *func_name,                  // ��ǰ��������(�Ƽ���д__FUNCTION__)
                    IN      const char *format_spec,                // ��ʾ�����ݸ�ʽ�ַ���
                    IN      va_list arg                             // �ɱ�����б�
                    );

 // �����޸�
extern int DTXA_data_request
                    (
                    IN      const char *comp_id,                    // �����
                    IN      DTXA_REQ_MODE_ENUM from_where,          // �����޸�ģʽ
                    IN      const char *func_name,                  // ��ǰ��������(�Ƽ���д__FUNCTION__)
                    IN      const char *input_format,               // �������ݸ�ʽ�ַ���
                    IN      const char *output_format,              // ������ݸ�ʽ�ַ���
                                       ...                          // �ɱ����
                    );

// ��������ǰ�Ƿ�Ϊĳ�ַ���ģʽ
extern BOOL DTXA_check_sim_mode
                    (
                    IN      const char *comp_id,                    // �����
                    IN      DTXA_SIM_MODE_ENUM sim_mode             // ����ģʽ
                    );

extern int DTXA_set_trace_dest(BOOL screen_enabled,
                BOOL printer_enabled, BOOL file_enabled, char *filename);


//
// ����Ϊ���̰߳�ȫģʽ��ʹ��DN�Ķ��̰߳�ȫ�ӿ�
//

// ���������ģʽ����������ģʽ������ģʽ�������޸�ģʽ
extern int DTXA_set_mode_t
                    (
                    IN      const char *comp_id,                    // ������� ��"TA"
                    IN      DTXA_SIM_MODE_ENUM sim_mode,            // ����ģʽ
                    IN      DTXA_TRACE_MODE_ENUM trace_mode,        // ����ģʽ
                    IN      DTXA_REQ_MODE_ENUM data_mode            // �����޸�ģʽ
                    );

// ��ȡ�����ǰ��ģʽ����
extern int DTXA_get_mode_t
                    (
                    IN      const char *comp_id,                    // �����
                    OUT     DTXA_SIM_MODE_ENUM *sim_mode,           // ����ģʽ
                    OUT     DTXA_TRACE_MODE_ENUM *trace_mode,       // ����ģʽ
                    OUT     DTXA_REQ_MODE_ENUM *data_mode           // �����޸�ģʽ
                    );

// ���ݸ��ټ�¼
extern void DTXA_trace_t
                    (
                    IN      const char *comp_id,                    // �����
                    IN      DTXA_TRACE_MODE_ENUM from_where,        // ����ģʽ
                    IN      const char *func_name,                  // ��ǰ��������(�Ƽ���д__FUNCTION__)
                    IN      const char *format_spec,                // ��ʾ�����ݸ�ʽ�ַ���
                                        ...                         // �ɱ����
                    );

// ���ݸ��ټ�¼��va_list��ʽ�ӿ�
extern void DTXA_trace_v_t
                    (
                    IN      const char *comp_id,                    // �����
                    IN      DTXA_TRACE_MODE_ENUM from_where,        // ����ģʽ
                    IN      const char *func_name,                  // ��ǰ��������(�Ƽ���д__FUNCTION__)
                    IN      const char *format_spec,                // ��ʾ�����ݸ�ʽ�ַ���
                    IN      va_list arg                             // �ɱ�����б�
                    );

 // �����޸�
extern int DTXA_data_request_t
                    (
                    IN      const char *comp_id,                    // �����
                    IN      DTXA_REQ_MODE_ENUM from_where,          // �����޸�ģʽ
                    IN      const char *func_name,                  // ��ǰ��������(�Ƽ���д__FUNCTION__)
                    IN      const char *input_format,               // �������ݸ�ʽ�ַ���
                    IN      const char *output_format,              // ������ݸ�ʽ�ַ���
                                       ...                          // �ɱ����
                    );

// ��������ǰ�Ƿ�Ϊĳ�ַ���ģʽ
extern BOOL DTXA_check_sim_mode_t
                    (
                    IN      const char *comp_id,                    // �����
                    IN      DTXA_SIM_MODE_ENUM sim_mode             // ����ģʽ
                    );

extern int DTXA_set_trace_dest_t(BOOL screen_enabled,
                BOOL printer_enabled, BOOL file_enabled, char *filename);



#endif  // DT_C


#ifdef __cplusplus
}
#endif

#endif  // end of DTXA_H
