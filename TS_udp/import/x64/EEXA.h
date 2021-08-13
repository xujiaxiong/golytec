/* EEXA.h  - Event and Error handler extern head file for windows */

/* modification history
-----------------------

01a 2015/12/21 星期一 10:31:00  create by frank
*/

#ifndef EEXA_WIN_H
#define EEXA_WIN_H


#ifdef __cplusplus
extern "C" {
#endif

#include  "golytec.h"

#define     EEXA_MAX_OPTION_NAME_LEN        32      // 用户操作选项名称最大长度
#define     EEXA_MAX_OPTION_NUM             4       // 用户操作选项最大个数

typedef char EEXA_OPTION[EEXA_MAX_OPTION_NAME_LEN];


typedef struct
{
    int num;                                        // 用户可选的操作选项个数
    int timeout;                                    // timeout，等待用户选择的时间
    int default_select;                             // 默认用户选项，即timeout时间到后用户如果没有选择将自动选此项
    int filler;
    EEXA_OPTION option[EEXA_MAX_OPTION_NUM];        // 选项提示信息，比如"STOP、RETRY、CANCEL、YES、NO"等
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

// 错误码转字符串
extern int EEXA_error_to_string
            (
            IN      int error_code,             // 错误码
            OUT     char *buffer,               // 字符串存放缓冲地址
            IN      int len                     // 缓冲大小
            );

// 字符串转错误码
extern int EEXA_string_to_error
            (
            IN      const char *buffer,         // 字符串缓冲
            OUT     int *error_code             // 错误码
            );

// 记录正常工作日志信息
extern int EEXA_log_info
            (
            IN      const char *format,         // 记录的信息，格式字符串
                                ...
            );

// 记录错误异常信息
// 如果link_error为NULL，异常信息会同时显示在界面上。
extern int EEXA_log_error
            (
            IN      int error_code,             // 错误码
            IN      int *link_error,            // 错误码链接，最多链接10个；如为NULL表示根错误
            IN      const char *file,           // 发生错误异常所在的文件名(推荐填写__FILE__)
            IN      int line,                   // 发生错误异常所在的文件行(推荐填写__LINE__)
            IN      const char *format,         // 记录的错误信息，格式字符串
                                ...             // 可变参数
            );

// 向用户报告异常信息，并等待用户选择后续操作选项，返回用户选择项。
// 异常信息及用户的选择会记录到异常日志里。
extern int EEXA_report_error_to_user
            (
            IN      int error_code,                         // 错误码
            IN      int *link_error,                        // 错误码链接，最多链接10个；如为NULL表示根错误
            IN      const char *file,                       // 发生错误异常所在的文件名(推荐填写__FILE__)
            IN      int line,                               // 发生错误异常所在的文件行(推荐填写__LINE__)
            IN      EEXA_USER_OPTIONS_STRUCT options,       // 用户选项参数
            OUT     int *user_select,                       // 最终用户选择的选项编号
            IN      const char *format,                     // 显示出来的错误信息，格式字符串
                                ...
            );


// 向用户报告一些信息(非异常)，比如运行结束后统计信息等
// UI在界面上弹出一个对话框显示信息，用户点确认即可。
extern int EEXA_report_info_to_user
            (
            IN  const char *format,
                            ...
            );


// 记录错误异常信息至用户错误日志
// 如果link_error为NULL，异常信息会同时显示在界面上。
extern int EEXA_log_user_error
            (
            IN      int error_code,             // 错误码
            IN      int *link_error,            // 错误码链接，最多链接10个；如为NULL表示根错误
            IN      const char *file,           // 发生错误异常所在的文件名(推荐填写__FILE__)
            IN      int line,                   // 发生错误异常所在的文件行(推荐填写__LINE__)
            IN      const char *format,         // 记录的错误信息，格式字符串
                                ...             // 可变参数
            );




#endif // end of EE_C


#ifdef __cplusplus
}
#endif

#endif  // end of EEXA_WIN_H


