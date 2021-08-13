/* DNXA.h  - Distributed Network(DN) extern head file for windows */

/* modification history
-----------------------

01a 2015/12/21 ����һ 10:13:50   create by frank
*/

#ifndef DNXA_WIN_H
#define DNXA_WIN_H


#ifdef __cplusplus
extern "C" {
#endif

#include "golytec.h"


typedef char DNXA_SERV_ADDR[16];
typedef int DNXA_REPLY_ADDR;

#define DNXA_SERVER_END     0


typedef struct
{
    DNXA_SERV_ADDR sl_serv_addr;    // The server address on which to wait
    BOOL sl_is_server;              // Waiting as a server (TRUE) or as a client (FALSE) on the address
} DNXA_SELECT_ADDR_STRUCT;



// errno number defines
#define     DNXA_SYSTEM_ERROR               0x444E0000
#define     DNXA_TIMEOUT_ERROR              0x444E0001
#define     DNXA_PARAMETER_ERROR            0x444E0002
#define     DNXA_ILLEGAL_CALL_ERROR         0x444E0003
#define     DNXA_SERVER_NOT_LISTENING       0x444E0004
#define     DNXA_NOT_INITIALIZED            0x444E0005
#define     DNXA_MSG_TOO_LARGE              0x444E0006

#define     DNXA_CONNECTION_RESET_ERROR     0x444E0066



#ifndef DN_C

// ��ȡDN�汾��Ϣ
extern int DNXA_get_version( int *high, int *low, char info[32]);

// ����DN��ʼ����ע��DN SERVER��ַ
extern int DNXA_task_init( IN   DNXA_SERV_ADDR *serv_addrs );

// ����DN��ֹ
extern int DNXA_task_exit( void );

// ����������Ϣ���ȴ���Ӧ��Ϣ (client)
extern int DNXA_send_request_receive_reply
                        (
                        IN      const DNXA_SERV_ADDR serv_addr,         // server��ַ
                        IN      const void          *req_msg,           // ������Ϣ����
                        IN      int                 req_len,            // ������Ϣ��С
                        OUT     void                *rep_msg,           // ������Ϣ����
                        IN      int                 rep_len,            // ��Ӧ��Ϣ��󳤶�
                        OUT     int                 *act_len,           // ��Ӧ��Ϣʵ�ʳ���
                        IN      int                 retry_interval,     // ����ʧ�ܺ����Լ��
                        IN      int                 timeout             // �ȴ��ĳ�ʱʱ��
                        );

// ����������Ϣ (client)
extern int DNXA_send_request
                    (
                    IN      const DNXA_SERV_ADDR  serv_addr,            // server��ַ
                    IN      const void          *msg,                   // ������Ϣ����
                    IN      int                 len,                    // ������Ϣ��С
                    IN      int                 retry_interval          // ����ʧ�ܺ����Լ��
                    );

// ���ջ�Ӧ��Ϣ (client)
extern int DNXA_receive_reply
                    (
                    IN      const DNXA_SERV_ADDR  serv_addr,            // server��ַ
                    OUT     void                *msg,                   // ��Ӧ��Ϣ����
                    IN      int                 len,                    // ��Ӧ��Ϣ��󳤶�
                    OUT     int                 *act_len,               // ��Ӧ��Ϣʵ�ʳ���
                    IN      int                 timeout                 // �ȴ��ĳ�ʱʱ��
                    );

// ����������Ϣ (server)
extern int DNXA_receive_request
                    (
                    IN      const DNXA_SERV_ADDR  serv_addr,            // server��ַ
                    OUT     void                *msg,                   // ����������Ϣ�Ļ���
                    IN      int                 len,                    // ����������Ϣ����󳤶�
                    OUT     int                 *act_len,               // ������Ϣʵ�ʳ���
                    OUT     DNXA_REPLY_ADDR      *repl_addr,            // client��Ӧ�Ļ�Ӧ��ַ
                    IN      int                 timeout                 // �ȴ��ĳ�ʱʱ��
                    );

// ���ͻ�Ӧ��Ϣ (server)
extern int DNXA_send_reply
                    (
                    IN      DNXA_REPLY_ADDR    repl_addr,               // client�Ļ�Ӧ��ַ
                    IN      const void      *msg,                       // ��Ӧ��Ϣ����
                    IN      int             len                         // ��Ӧ��Ϣ����
                    );

// select��������һ���ַ��(client/server)���ȴ����ؼ���ĵ�ַ
extern int DNXA_select
                (
                IN      const DNXA_SELECT_ADDR_STRUCT *sel_addrs,       // �ȴ��ĵ�ַ�б�
                IN      BOOL                round_robin,                // ����ĵ�ַ�Ƿ���ѯ����
                OUT     int                 *index,                     // ���ؾ����ĵ�ַ�ڵ�ַ���е�����
                IN      int                 timeout                     // �ȴ��ĳ�ʱʱ��
                );



// ����Ϊ���̰߳�ȫ��ʽ��ÿ���̶߳�Ҫע�����£��߳�֮�䲻Ӱ��
// ����DN��ʼ����ע��DN SERVER��ַ
extern int DNXA_task_init_t( IN  DNXA_SERV_ADDR *serv_addrs );

// ����DN��ֹ
extern int DNXA_task_exit_t( void );

// ����������Ϣ���ȴ���Ӧ��Ϣ (client)
extern int DNXA_send_request_receive_reply_t
                        (
                        IN      const DNXA_SERV_ADDR serv_addr,         // server��ַ
                        IN      const void          *req_msg,           // ������Ϣ����
                        IN      int                 req_len,            // ������Ϣ��С
                        OUT     void                *rep_msg,           // ������Ϣ����
                        IN      int                 rep_len,            // ��Ӧ��Ϣ��󳤶�
                        OUT     int                 *act_len,           // ��Ӧ��Ϣʵ�ʳ���
                        IN      int                 retry_interval,     // ����ʧ�ܺ����Լ��
                        IN      int                 timeout             // �ȴ��ĳ�ʱʱ��
                        );

// ����������Ϣ (client)
extern int DNXA_send_request_t
                    (
                    IN      const DNXA_SERV_ADDR  serv_addr,            // server��ַ
                    IN      const void          *msg,                   // ������Ϣ����
                    IN      int                 len,                    // ������Ϣ��С
                    IN      int                 retry_interval          // ����ʧ�ܺ����Լ��
                    );

// ���ջ�Ӧ��Ϣ (client)
extern int DNXA_receive_reply_t
                    (
                    IN      const DNXA_SERV_ADDR  serv_addr,            // server��ַ
                    OUT     void                *msg,                   // ��Ӧ��Ϣ����
                    IN      int                 len,                    // ��Ӧ��Ϣ��󳤶�
                    OUT     int                 *act_len,               // ��Ӧ��Ϣʵ�ʳ���
                    IN      int                 timeout                 // �ȴ��ĳ�ʱʱ��
                    );

// ����������Ϣ (server)
extern int DNXA_receive_request_t
                    (
                    IN      const DNXA_SERV_ADDR  serv_addr,            // server��ַ
                    OUT     void                *msg,                   // ����������Ϣ�Ļ���
                    IN      int                 len,                    // ����������Ϣ����󳤶�
                    OUT     int                 *act_len,               // ������Ϣʵ�ʳ���
                    OUT     DNXA_REPLY_ADDR      *repl_addr,            // client��Ӧ�Ļ�Ӧ��ַ
                    IN      int                 timeout                 // �ȴ��ĳ�ʱʱ��
                    );

// ���ͻ�Ӧ��Ϣ (server)
extern int DNXA_send_reply_t
                    (
                    IN      DNXA_REPLY_ADDR    repl_addr,               // client�Ļ�Ӧ��ַ
                    IN      const void      *msg,                       // ��Ӧ��Ϣ����
                    IN      int             len                         // ��Ӧ��Ϣ����
                    );

// select��������һ���ַ��(client/server)���ȴ����ؼ���ĵ�ַ
extern int DNXA_select_t
                (
                IN      const DNXA_SELECT_ADDR_STRUCT *sel_addrs,       // �ȴ��ĵ�ַ�б�
                IN      BOOL                round_robin,                // ����ĵ�ַ�Ƿ���ѯ����
                OUT     int                 *index,                     // ���ؾ����ĵ�ַ�ڵ�ַ���е�����
                IN      int                 timeout                     // �ȴ��ĳ�ʱʱ��
                );



#endif // end of DN_C


#ifdef __cplusplus
}
#endif

#endif  // end of DNXA_WIN_H

