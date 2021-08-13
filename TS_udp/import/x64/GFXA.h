/* GFXA.h  - General Function(GF) extern head file for windows */

/* modification history
-----------------------

01a 2016/1/5 星期二 13:40:30    create by frank
*/

#ifndef GFXA_WIN_H
#define GFXA_WIN_H


#ifdef __cplusplus
extern "C" {
#endif

#include "golytec.h"




typedef struct
{
    UINT32  year;                   // 年 1601 - 30827
    UINT32  month;                  // 月  1 - 12
    UINT32  dayofweek;              // 星期几， 0 - 星期日， 1 - 星期一， ... , 6 - 星期六
    UINT32  day;                    // 月份的第几天， 1 - 31
    UINT32  hour;                   // 小时， 0 - 23
    UINT32  minute;                 //  分，  0 - 59
    UINT32  second;                 // 秒， 0 - 59
    UINT32  msec;                   // 毫秒, 0  - 999
}GFXA_SYSTEM_TIME_STRUCT;



// 可用于进程间通信的内核对象类型
typedef enum
{
    GFXA_NAMED_PIPE,                // 管道，windows的named pipe，用于消息的传递
    GFXA_SEM_BIN,                   // 二进制信号量，windows的event
    GFXA_SEM_COUNT,                 // 计数式信号量，windows的semaphore
    GFXA_SEM_MUTEX,                 // 互斥信号量，windows的mutex
    GFXA_SHARE_MEMORY               // 共享内存，windows的memory file mapping
}GFXA_SYSTEM_OBJECT_ENUM;




// errno number defines
#define     GFXA_SYSTEM_ERROR               0x47460000
#define     GFXA_TIMEOUT_ERROR              0x47460001
#define     GFXA_PARAMETER_ERROR            0x47460002
#define     GFXA_ILLEGAL_CALL_ERROR         0x47460003
#define     GFXA_MSG_TOO_LARGE              0x47460004

#ifndef GF_C

//
// < 串口操作 >
//

// 打开串口
// 以默认参数打开一个串口，默认波特率9600，8位数据位，无奇偶校验，停止位1位
extern int GFXA_open_COM
                (
                IN  const char *name,                   // 串口名
                OUT HANDLE *fd                          // 返回串口对应句柄
                );

// 关闭已打开的串口
extern int GFXA_close_COM
                (
                IN  HANDLE fd                           // 已打开的串口句柄
                );


// 读串口数据
// 读取的时候没有数据将被阻塞，直到读取到数据或者timeout时间到
extern int GFXA_read_COM
                (
                IN  HANDLE fd,                          // 已打开的串口句柄
                OUT char *buffer,                       // 接收数据的缓冲
                IN  int maxbytes,                       // 读取的最大字节数
                IN  int timeout                         // timeout时间，以ms为单位
                );

// 写串口数据
extern int GFXA_write_COM
                (
                IN  HANDLE fd,                          // 已打开的串口句柄
                IN  char *buffer,                       // 要往串口写的数据所在缓冲
                IN  int bytes,                          // 要写的字节数
                IN  int timeout                         // timeout时间，以ms为单位
                );

// 设置串口参数
extern int GFXA_set_COM
                (
                IN  HANDLE fd,                          // 已打开的串口句柄
                IN  int baudRate,                       // 波特率，1200 2400 4800 9600 19200 38400 ...
                IN  int byteSize,                       // 数据位 5 - 8
                IN  int parity,                         // 奇偶校验  0-4 分别对应 None,Odd,Even,Mark,Space
                IN  int stopBits                        // 停止位 0,1,2 分别对应 1, 1.5, 2位
                );





//
// 进程、线程通信类，使用windows内核对象，包括各种sem、pipe等,  可以通过名字来进行进程之间的通信；
// 同一进程内，XXX_create建立时返回的id可以直接用于后续的读写等操作；
// 不同进程内，则需要先使用GFXA_get_object_handle()通过名字先获取id，然后才能进行读写等操作
//

// 获取内核对象的handle句柄，用于与调用XXX_create()不在同一进程的情况。
extern int GFXA_get_object_handle
                (
                IN  const char *name,                   // 名称，比如pipe、sem等的名称
                IN  GFXA_SYSTEM_OBJECT_ENUM  type,      // 内核对象类型
                OUT  HANDLE *id                         // 返回的id
                );


//    关闭内核对象句柄id。系统将减少内核对象句柄计数。
//    当内核对象的最后句柄被关闭时，内核对象才会被从系统删除。
extern  int GFXA_close_object_handle
                (
                IN   HANDLE id                        // id
                );



//
// < semaphore >
//

// 互斥信号量(windows的mutex)，用于进程或线程之间的互斥操作，有所有权概念

// 建立互斥信号量
extern int GFXA_semCreate_mutex
                (
                IN  const char *name,                   // 名字，可以在进程之间传递
                OUT   HANDLE *id                        // 返回的id
                );

// 互斥信号量等待获取，semTake
// waitforsingleobject()
extern int GFXA_semTake_mutex
                (
                IN  HANDLE  id,                          // id
                IN  int timeout                         // timeout
                );

// 互斥信号量释放，semGive
// releaseMutex()
extern int GFXA_semGive_mutex
                (
                IN  HANDLE  id                          // id
                );


// 计数式信号量(windows的semaphore),用于进程或线程之间的互斥操作
// 建立计数式信号量
extern int GFXA_semCreate_count
                (
                IN  const char *name,                   // 名字，可以在进程之间传递
                IN  int  initCount,                     // 初始计数值
                IN  int  maxCount,                      // 最大计数值
                OUT   HANDLE *id                        // 返回的id
                );

// 计数式信号量等待获取，semTake
// waitforsingleobject()
extern int GFXA_semTake_count
                (
                IN  HANDLE  id,                          // id
                IN  int timeout                         // timeout
                );

// 计数式信号量释放，增加计数，semGive
// ReleaseSemaphore()
extern int GFXA_semGive_count
                (
                IN  HANDLE  id,                         // id
                IN  int  num                            // 释放的个数，默认为1
                );


// 二进制信号量(windows的event),用于进程或线程之间的同步操作

// 建立二进制信号量
// createEvent()，设置成自动的
extern int GFXA_semCreate_bin
                (
                IN  const char *name,                   // 名字，可以在进程之间传递
                IN  BOOL init_state,                    // 初始状态是否为有效
                OUT   HANDLE *id                        // 返回的id
                );

// 二进制信号量等待获取，semTake
// WaitForSingleObject()
extern int GFXA_semTake_bin
                (
                IN  HANDLE  id,                          // id
                IN  int timeout                         // timeout
                );

// 二进制信号量释放，semGive
// SetEvent()，自动模式
extern int GFXA_semGive_bin
                (
                IN  HANDLE  id                          // id
                );


//
// <命名管道>
// (用于进程之间的通信，这里提供的是基于消息方式传递)
//

// 建立命名管道
extern int GFXA_create_pipe
                (
                IN  const char *name,                   // 名字必须如下方式"\\.\pipe\pipename"
                IN  int size,                           // buffer大小
                IN  BOOL  block,                        // 管道是否阻塞方式
                IN  int  timeout,                       // 默认超时时间
                OUT HANDLE *id                          // 返回pipe id
                );

extern int GFXA_create_pipe_async
                (
                IN  const char *name,                   // 名字必须如下方式"\\.\pipe\pipename"
                IN  int size,                           // buffer大小
                IN  BOOL  block,                        // 管道是否阻塞方式
                IN  int  timeout,                       // 默认超时时间
                OUT HANDLE *id                          // 返回pipe id
                );


// client 等待连接pipe，用于同步
extern int GFXA_client_wait_pipe_ready
                (
                IN  const char *name,                   // pipe name
                OUT HANDLE  *fd,                        // 返回pipe的fd
                IN  int timeout                        // timeout
                );

// server等待client的连接，用于同步，会被阻塞
extern int GFXA_server_wait_pipe
                (
                IN  HANDLE id                   // pipe fd
                );


// 读取pipe的一条消息
extern int GFXA_read_pipe
                (
                IN  HANDLE  id,                         // pipe id
                OUT char *buffer,                       // 读取内容存放的缓冲
                IN  int size,                           // 缓冲大小
                OUT int *actLen                         // 实际读取的大小
                );

// 往pipe里写一条消息
extern int GFXA_write_pipe
                (
                IN  HANDLE id,                          // pipe id
                IN  char *buffer,                       // 要写的内容缓冲
                IN  int size,                           // 写内容大小
                OUT int *actLen                         // 实际写的大小
                );

extern int GFXA_read_pipe_async
                (
                IN  HANDLE  id,                         // pipe id
                OUT char *buffer,                       // 读取内容存放的缓冲
                IN  int size,                           // 要读取的消息大小
                OUT int *actLen,                         // 实际读取的大小
                IN int timeout
                );


//
// <共享内存>
// (用于进程之间的通信)
//

// 建立共享内存
extern int GFXA_create_SM
                (
                IN  const char *name,                   // 名字
                IN  int size,                           // 共享内存的大小，4096为单位
                OUT HANDLE *id                          // 返回id
                );

// 读取共享内存的数据
extern int GFXA_read_SM
                (
                IN  HANDLE  id,                         // id
                OUT char *buffer,                       // 读取内容存放的缓冲
                IN  int size                            // 需要读取的大小，要小于buffer本身的大小
                );

// 往共享内存里写数据
extern int GFXA_write_SM
                (
                IN  HANDLE id,                          // id
                IN  char *buffer,                       // 要写的内容缓冲
                IN  int size                            // 写内容大小
                );



//
// < 时间处理类函数 >
//

// 线程延时，类似taskDelay()
// (windows的Sleep()，定时精度约10ms)
extern int GFXA_sleep
                (
                IN  UINT32 msec                         // 延时的时间，单位毫秒
                );

// 获取当前系统启动后的tick数, 1个tick为1毫秒
// (windows的GetTickCount()，定时精度约10ms)
extern int GFXA_get_tick
                (
                OUT UINT32  *tick                       // 获取windows系统启动后的tick数，单位为毫秒
                );

// 获取当前的系统时间，年、月、日、时、分、秒、毫秒
// windows的GetLocalTime()
// (注意：如果要使用相对时间，不要使用这个函数，这个系统时间可能随时被修改的)
extern int GFXA_get_system_time
                (
                OUT GFXA_SYSTEM_TIME_STRUCT  *time      // 系统时间
                );

// 设置系统时间
// 设置当前的系统时间，年、月、日、时、分、秒、毫秒
// windows的SetLocalTime()
extern int GFXA_set_system_time
                (
                IN  GFXA_SYSTEM_TIME_STRUCT  time       // 系统时间
                );


#if 0
// 看门狗定时器
// (windows的CreateTimerQueueTimer()，线程使用)

// 建立并启动看门狗定时器
extern int GFXA_create_wd
                (
                OUT HANDLE *id,                         // 返回看门狗id
                IN  FUNCPTR ISR,                        // 定时回调函数
                IN  void *parameter,                    // 函数参数
                IN  UINT32  dueTime,                    // 首次启动时间，单位ms
                IN  UINT32  period                      // 周期时间，单位ms，如为0则表示只启动一次
                );

// 取消并删除已启动的看门狗定时器
extern int GFXA_delete_wd
                (
                IN  HANDLE  id                          // wd id
                );
#endif // 0


//
// <进程线程类>
//

// 建立一个新进程
extern int GFXA_create_process
                (
                IN  const char *name,               // 可执行镜像名
                IN  const char *command,            // 命令行参数
                IN  const char *path,               // 设定进程的当前路径,NULL将使用调用者一致的目录
                OUT HANDLE  *processId,             // 进程handle
                OUT HANDLE  *threadId               // 进程的主线程handle
                );

// 强制终止一个进程
// (尽量少用，不会通知被调用的进程，可能丢数据)
extern int GFXA_terminate_process
                (
                IN  HANDLE  processId
                );

// 获取当前进程id
extern int GFXA_get_current_process_id
                (
                OUT UINT32  *processId
                );


// 建立一个线程
extern int GFXA_create_thread
                (
                IN  int  stackSize,                 // 线程堆栈大小，0表示默认大小
                IN  FUNCPTR  func,                  // 线程主函数入口
                IN  void  *parameter,               // 函数参数
                OUT UINT32  *threadId               // 返回线程id
                );

// 强制终止一个线程
// (尽量少用，不会通知被调用的线程，可能丢数据))
extern int GFXA_terminate_thread
                (
                IN  HANDLE  threadId
                );

// 获取当前线程id
extern int GFXA_get_current_thread_id
                (
                OUT UINT32  *threadId
                );

//
// <操作系统的errno相关>
//

// 获取线程最后的错误码信息
extern int GFXA_get_errno
                (
                OUT UINT32 *err               // 返回系统错误码
                );

// 设置线程的错误码
extern int GFXA_set_errno
                (
                IN UINT32 err                 // 错误码
                );

// 将系统错误码转换为字符串
extern int GFXA_errno_to_string
                (
                IN  UINT32 err,                 // 错误码
                OUT char *buffer,               // 存放转换后的格式字串缓冲
                IN  int  size                   // 缓冲大小， 要足够大，目前系统最大的错误信息是57个字符，建议64字节
                );


// 将字符串根据分隔符分割为几个子字符串
extern int GFXA_break_string_to_substr
                (
                IN char *buf,               // 输入字符串
                IN char *space,             // 分隔符
				OUT char *buf1,             // 第一个子字符串
				OUT char *buf2,             // 第二个子字符串
				OUT char *buf3,             // 第三个子字符串
				OUT char *buf4              // 第四个子字符串
				);


#endif // end of GF_C


#ifdef __cplusplus
}
#endif

#endif  // end of GFXA_WIN_H

