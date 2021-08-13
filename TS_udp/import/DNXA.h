/* DNXA.h  - Distributed Network(DN) extern head file for windows */

/* modification history
-----------------------

01a 2015/12/21 星期一 10:13:50   create by frank
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

// 获取DN版本信息
extern int DNXA_get_version( int *high, int *low, char info[32]);

// 任务DN初始化，注册DN SERVER地址
extern int DNXA_task_init( IN   DNXA_SERV_ADDR *serv_addrs );

// 任务DN终止
extern int DNXA_task_exit( void );

// 发送请求消息并等待回应消息 (client)
extern int DNXA_send_request_receive_reply
                        (
                        IN      const DNXA_SERV_ADDR serv_addr,         // server地址
                        IN      const void          *req_msg,           // 请求消息缓冲
                        IN      int                 req_len,            // 请求消息大小
                        OUT     void                *rep_msg,           // 返回消息缓冲
                        IN      int                 rep_len,            // 回应消息最大长度
                        OUT     int                 *act_len,           // 回应消息实际长度
                        IN      int                 retry_interval,     // 发送失败后重试间隔
                        IN      int                 timeout             // 等待的超时时间
                        );

// 发送请求消息 (client)
extern int DNXA_send_request
                    (
                    IN      const DNXA_SERV_ADDR  serv_addr,            // server地址
                    IN      const void          *msg,                   // 请求消息缓冲
                    IN      int                 len,                    // 请求消息大小
                    IN      int                 retry_interval          // 发送失败后重试间隔
                    );

// 接收回应消息 (client)
extern int DNXA_receive_reply
                    (
                    IN      const DNXA_SERV_ADDR  serv_addr,            // server地址
                    OUT     void                *msg,                   // 回应消息缓冲
                    IN      int                 len,                    // 回应消息最大长度
                    OUT     int                 *act_len,               // 回应消息实际长度
                    IN      int                 timeout                 // 等待的超时时间
                    );

// 接收请求消息 (server)
extern int DNXA_receive_request
                    (
                    IN      const DNXA_SERV_ADDR  serv_addr,            // server地址
                    OUT     void                *msg,                   // 接收请求消息的缓冲
                    IN      int                 len,                    // 允许请求消息的最大长度
                    OUT     int                 *act_len,               // 请求消息实际长度
                    OUT     DNXA_REPLY_ADDR      *repl_addr,            // client对应的回应地址
                    IN      int                 timeout                 // 等待的超时时间
                    );

// 发送回应消息 (server)
extern int DNXA_send_reply
                    (
                    IN      DNXA_REPLY_ADDR    repl_addr,               // client的回应地址
                    IN      const void      *msg,                       // 回应消息缓冲
                    IN      int             len                         // 回应消息长度
                    );

// select，阻塞在一组地址上(client/server)，等待返回激活的地址
extern int DNXA_select
                (
                IN      const DNXA_SELECT_ADDR_STRUCT *sel_addrs,       // 等待的地址列表
                IN      BOOL                round_robin,                // 激活的地址是否按轮询服务
                OUT     int                 *index,                     // 返回就绪的地址在地址组中的索引
                IN      int                 timeout                     // 等待的超时时间
                );



// 以下为多线程安全方式，每次线程都要注册以下，线程之间不影响
// 任务DN初始化，注册DN SERVER地址
extern int DNXA_task_init_t( IN  DNXA_SERV_ADDR *serv_addrs );

// 任务DN终止
extern int DNXA_task_exit_t( void );

// 发送请求消息并等待回应消息 (client)
extern int DNXA_send_request_receive_reply_t
                        (
                        IN      const DNXA_SERV_ADDR serv_addr,         // server地址
                        IN      const void          *req_msg,           // 请求消息缓冲
                        IN      int                 req_len,            // 请求消息大小
                        OUT     void                *rep_msg,           // 返回消息缓冲
                        IN      int                 rep_len,            // 回应消息最大长度
                        OUT     int                 *act_len,           // 回应消息实际长度
                        IN      int                 retry_interval,     // 发送失败后重试间隔
                        IN      int                 timeout             // 等待的超时时间
                        );

// 发送请求消息 (client)
extern int DNXA_send_request_t
                    (
                    IN      const DNXA_SERV_ADDR  serv_addr,            // server地址
                    IN      const void          *msg,                   // 请求消息缓冲
                    IN      int                 len,                    // 请求消息大小
                    IN      int                 retry_interval          // 发送失败后重试间隔
                    );

// 接收回应消息 (client)
extern int DNXA_receive_reply_t
                    (
                    IN      const DNXA_SERV_ADDR  serv_addr,            // server地址
                    OUT     void                *msg,                   // 回应消息缓冲
                    IN      int                 len,                    // 回应消息最大长度
                    OUT     int                 *act_len,               // 回应消息实际长度
                    IN      int                 timeout                 // 等待的超时时间
                    );

// 接收请求消息 (server)
extern int DNXA_receive_request_t
                    (
                    IN      const DNXA_SERV_ADDR  serv_addr,            // server地址
                    OUT     void                *msg,                   // 接收请求消息的缓冲
                    IN      int                 len,                    // 允许请求消息的最大长度
                    OUT     int                 *act_len,               // 请求消息实际长度
                    OUT     DNXA_REPLY_ADDR      *repl_addr,            // client对应的回应地址
                    IN      int                 timeout                 // 等待的超时时间
                    );

// 发送回应消息 (server)
extern int DNXA_send_reply_t
                    (
                    IN      DNXA_REPLY_ADDR    repl_addr,               // client的回应地址
                    IN      const void      *msg,                       // 回应消息缓冲
                    IN      int             len                         // 回应消息长度
                    );

// select，阻塞在一组地址上(client/server)，等待返回激活的地址
extern int DNXA_select_t
                (
                IN      const DNXA_SELECT_ADDR_STRUCT *sel_addrs,       // 等待的地址列表
                IN      BOOL                round_robin,                // 激活的地址是否按轮询服务
                OUT     int                 *index,                     // 返回就绪的地址在地址组中的索引
                IN      int                 timeout                     // 等待的超时时间
                );



#endif // end of DN_C


#ifdef __cplusplus
}
#endif

#endif  // end of DNXA_WIN_H

