/* GFXA.h  - General Function(GF) extern head file for windows */

/* modification history
-----------------------

01a 2016/1/5 ���ڶ� 13:40:30    create by frank
*/

#ifndef GFXA_WIN_H
#define GFXA_WIN_H


#ifdef __cplusplus
extern "C" {
#endif

#include "golytec.h"




typedef struct
{
    UINT32  year;                   // �� 1601 - 30827
    UINT32  month;                  // ��  1 - 12
    UINT32  dayofweek;              // ���ڼ��� 0 - �����գ� 1 - ����һ�� ... , 6 - ������
    UINT32  day;                    // �·ݵĵڼ��죬 1 - 31
    UINT32  hour;                   // Сʱ�� 0 - 23
    UINT32  minute;                 //  �֣�  0 - 59
    UINT32  second;                 // �룬 0 - 59
    UINT32  msec;                   // ����, 0  - 999
}GFXA_SYSTEM_TIME_STRUCT;



// �����ڽ��̼�ͨ�ŵ��ں˶�������
typedef enum
{
    GFXA_NAMED_PIPE,                // �ܵ���windows��named pipe��������Ϣ�Ĵ���
    GFXA_SEM_BIN,                   // �������ź�����windows��event
    GFXA_SEM_COUNT,                 // ����ʽ�ź�����windows��semaphore
    GFXA_SEM_MUTEX,                 // �����ź�����windows��mutex
    GFXA_SHARE_MEMORY               // �����ڴ棬windows��memory file mapping
}GFXA_SYSTEM_OBJECT_ENUM;




// errno number defines
#define     GFXA_SYSTEM_ERROR               0x47460000
#define     GFXA_TIMEOUT_ERROR              0x47460001
#define     GFXA_PARAMETER_ERROR            0x47460002
#define     GFXA_ILLEGAL_CALL_ERROR         0x47460003
#define     GFXA_MSG_TOO_LARGE              0x47460004

#ifndef GF_C

//
// < ���ڲ��� >
//

// �򿪴���
// ��Ĭ�ϲ�����һ�����ڣ�Ĭ�ϲ�����9600��8λ����λ������żУ�飬ֹͣλ1λ
extern int GFXA_open_COM
                (
                IN  const char *name,                   // ������
                OUT HANDLE *fd                          // ���ش��ڶ�Ӧ���
                );

// �ر��Ѵ򿪵Ĵ���
extern int GFXA_close_COM
                (
                IN  HANDLE fd                           // �Ѵ򿪵Ĵ��ھ��
                );


// ����������
// ��ȡ��ʱ��û�����ݽ���������ֱ����ȡ�����ݻ���timeoutʱ�䵽
extern int GFXA_read_COM
                (
                IN  HANDLE fd,                          // �Ѵ򿪵Ĵ��ھ��
                OUT char *buffer,                       // �������ݵĻ���
                IN  int maxbytes,                       // ��ȡ������ֽ���
                IN  int timeout                         // timeoutʱ�䣬��msΪ��λ
                );

// д��������
extern int GFXA_write_COM
                (
                IN  HANDLE fd,                          // �Ѵ򿪵Ĵ��ھ��
                IN  char *buffer,                       // Ҫ������д���������ڻ���
                IN  int bytes,                          // Ҫд���ֽ���
                IN  int timeout                         // timeoutʱ�䣬��msΪ��λ
                );

// ���ô��ڲ���
extern int GFXA_set_COM
                (
                IN  HANDLE fd,                          // �Ѵ򿪵Ĵ��ھ��
                IN  int baudRate,                       // �����ʣ�1200 2400 4800 9600 19200 38400 ...
                IN  int byteSize,                       // ����λ 5 - 8
                IN  int parity,                         // ��żУ��  0-4 �ֱ��Ӧ None,Odd,Even,Mark,Space
                IN  int stopBits                        // ֹͣλ 0,1,2 �ֱ��Ӧ 1, 1.5, 2λ
                );





//
// ���̡��߳�ͨ���࣬ʹ��windows�ں˶��󣬰�������sem��pipe��,  ����ͨ�����������н���֮���ͨ�ţ�
// ͬһ�����ڣ�XXX_create����ʱ���ص�id����ֱ�����ں����Ķ�д�Ȳ�����
// ��ͬ�����ڣ�����Ҫ��ʹ��GFXA_get_object_handle()ͨ�������Ȼ�ȡid��Ȼ����ܽ��ж�д�Ȳ���
//

// ��ȡ�ں˶����handle��������������XXX_create()����ͬһ���̵������
extern int GFXA_get_object_handle
                (
                IN  const char *name,                   // ���ƣ�����pipe��sem�ȵ�����
                IN  GFXA_SYSTEM_OBJECT_ENUM  type,      // �ں˶�������
                OUT  HANDLE *id                         // ���ص�id
                );


//    �ر��ں˶�����id��ϵͳ�������ں˶�����������
//    ���ں˶������������ر�ʱ���ں˶���Żᱻ��ϵͳɾ����
extern  int GFXA_close_object_handle
                (
                IN   HANDLE id                        // id
                );



//
// < semaphore >
//

// �����ź���(windows��mutex)�����ڽ��̻��߳�֮��Ļ��������������Ȩ����

// ���������ź���
extern int GFXA_semCreate_mutex
                (
                IN  const char *name,                   // ���֣������ڽ���֮�䴫��
                OUT   HANDLE *id                        // ���ص�id
                );

// �����ź����ȴ���ȡ��semTake
// waitforsingleobject()
extern int GFXA_semTake_mutex
                (
                IN  HANDLE  id,                          // id
                IN  int timeout                         // timeout
                );

// �����ź����ͷţ�semGive
// releaseMutex()
extern int GFXA_semGive_mutex
                (
                IN  HANDLE  id                          // id
                );


// ����ʽ�ź���(windows��semaphore),���ڽ��̻��߳�֮��Ļ������
// ��������ʽ�ź���
extern int GFXA_semCreate_count
                (
                IN  const char *name,                   // ���֣������ڽ���֮�䴫��
                IN  int  initCount,                     // ��ʼ����ֵ
                IN  int  maxCount,                      // ������ֵ
                OUT   HANDLE *id                        // ���ص�id
                );

// ����ʽ�ź����ȴ���ȡ��semTake
// waitforsingleobject()
extern int GFXA_semTake_count
                (
                IN  HANDLE  id,                          // id
                IN  int timeout                         // timeout
                );

// ����ʽ�ź����ͷţ����Ӽ�����semGive
// ReleaseSemaphore()
extern int GFXA_semGive_count
                (
                IN  HANDLE  id,                         // id
                IN  int  num                            // �ͷŵĸ�����Ĭ��Ϊ1
                );


// �������ź���(windows��event),���ڽ��̻��߳�֮���ͬ������

// �����������ź���
// createEvent()�����ó��Զ���
extern int GFXA_semCreate_bin
                (
                IN  const char *name,                   // ���֣������ڽ���֮�䴫��
                IN  BOOL init_state,                    // ��ʼ״̬�Ƿ�Ϊ��Ч
                OUT   HANDLE *id                        // ���ص�id
                );

// �������ź����ȴ���ȡ��semTake
// WaitForSingleObject()
extern int GFXA_semTake_bin
                (
                IN  HANDLE  id,                          // id
                IN  int timeout                         // timeout
                );

// �������ź����ͷţ�semGive
// SetEvent()���Զ�ģʽ
extern int GFXA_semGive_bin
                (
                IN  HANDLE  id                          // id
                );


//
// <�����ܵ�>
// (���ڽ���֮���ͨ�ţ������ṩ���ǻ�����Ϣ��ʽ����)
//

// ���������ܵ�
extern int GFXA_create_pipe
                (
                IN  const char *name,                   // ���ֱ������·�ʽ"\\.\pipe\pipename"
                IN  int size,                           // buffer��С
                IN  BOOL  block,                        // �ܵ��Ƿ�������ʽ
                IN  int  timeout,                       // Ĭ�ϳ�ʱʱ��
                OUT HANDLE *id                          // ����pipe id
                );

extern int GFXA_create_pipe_async
                (
                IN  const char *name,                   // ���ֱ������·�ʽ"\\.\pipe\pipename"
                IN  int size,                           // buffer��С
                IN  BOOL  block,                        // �ܵ��Ƿ�������ʽ
                IN  int  timeout,                       // Ĭ�ϳ�ʱʱ��
                OUT HANDLE *id                          // ����pipe id
                );


// client �ȴ�����pipe������ͬ��
extern int GFXA_client_wait_pipe_ready
                (
                IN  const char *name,                   // pipe name
                OUT HANDLE  *fd,                        // ����pipe��fd
                IN  int timeout                        // timeout
                );

// server�ȴ�client�����ӣ�����ͬ�����ᱻ����
extern int GFXA_server_wait_pipe
                (
                IN  HANDLE id                   // pipe fd
                );


// ��ȡpipe��һ����Ϣ
extern int GFXA_read_pipe
                (
                IN  HANDLE  id,                         // pipe id
                OUT char *buffer,                       // ��ȡ���ݴ�ŵĻ���
                IN  int size,                           // �����С
                OUT int *actLen                         // ʵ�ʶ�ȡ�Ĵ�С
                );

// ��pipe��дһ����Ϣ
extern int GFXA_write_pipe
                (
                IN  HANDLE id,                          // pipe id
                IN  char *buffer,                       // Ҫд�����ݻ���
                IN  int size,                           // д���ݴ�С
                OUT int *actLen                         // ʵ��д�Ĵ�С
                );

extern int GFXA_read_pipe_async
                (
                IN  HANDLE  id,                         // pipe id
                OUT char *buffer,                       // ��ȡ���ݴ�ŵĻ���
                IN  int size,                           // Ҫ��ȡ����Ϣ��С
                OUT int *actLen,                         // ʵ�ʶ�ȡ�Ĵ�С
                IN int timeout
                );


//
// <�����ڴ�>
// (���ڽ���֮���ͨ��)
//

// ���������ڴ�
extern int GFXA_create_SM
                (
                IN  const char *name,                   // ����
                IN  int size,                           // �����ڴ�Ĵ�С��4096Ϊ��λ
                OUT HANDLE *id                          // ����id
                );

// ��ȡ�����ڴ������
extern int GFXA_read_SM
                (
                IN  HANDLE  id,                         // id
                OUT char *buffer,                       // ��ȡ���ݴ�ŵĻ���
                IN  int size                            // ��Ҫ��ȡ�Ĵ�С��ҪС��buffer����Ĵ�С
                );

// �������ڴ���д����
extern int GFXA_write_SM
                (
                IN  HANDLE id,                          // id
                IN  char *buffer,                       // Ҫд�����ݻ���
                IN  int size                            // д���ݴ�С
                );



//
// < ʱ�䴦���ຯ�� >
//

// �߳���ʱ������taskDelay()
// (windows��Sleep()����ʱ����Լ10ms)
extern int GFXA_sleep
                (
                IN  UINT32 msec                         // ��ʱ��ʱ�䣬��λ����
                );

// ��ȡ��ǰϵͳ�������tick��, 1��tickΪ1����
// (windows��GetTickCount()����ʱ����Լ10ms)
extern int GFXA_get_tick
                (
                OUT UINT32  *tick                       // ��ȡwindowsϵͳ�������tick������λΪ����
                );

// ��ȡ��ǰ��ϵͳʱ�䣬�ꡢ�¡��ա�ʱ���֡��롢����
// windows��GetLocalTime()
// (ע�⣺���Ҫʹ�����ʱ�䣬��Ҫʹ��������������ϵͳʱ�������ʱ���޸ĵ�)
extern int GFXA_get_system_time
                (
                OUT GFXA_SYSTEM_TIME_STRUCT  *time      // ϵͳʱ��
                );

// ����ϵͳʱ��
// ���õ�ǰ��ϵͳʱ�䣬�ꡢ�¡��ա�ʱ���֡��롢����
// windows��SetLocalTime()
extern int GFXA_set_system_time
                (
                IN  GFXA_SYSTEM_TIME_STRUCT  time       // ϵͳʱ��
                );


#if 0
// ���Ź���ʱ��
// (windows��CreateTimerQueueTimer()���߳�ʹ��)

// �������������Ź���ʱ��
extern int GFXA_create_wd
                (
                OUT HANDLE *id,                         // ���ؿ��Ź�id
                IN  FUNCPTR ISR,                        // ��ʱ�ص�����
                IN  void *parameter,                    // ��������
                IN  UINT32  dueTime,                    // �״�����ʱ�䣬��λms
                IN  UINT32  period                      // ����ʱ�䣬��λms����Ϊ0���ʾֻ����һ��
                );

// ȡ����ɾ���������Ŀ��Ź���ʱ��
extern int GFXA_delete_wd
                (
                IN  HANDLE  id                          // wd id
                );
#endif // 0


//
// <�����߳���>
//

// ����һ���½���
extern int GFXA_create_process
                (
                IN  const char *name,               // ��ִ�о�����
                IN  const char *command,            // �����в���
                IN  const char *path,               // �趨���̵ĵ�ǰ·��,NULL��ʹ�õ�����һ�µ�Ŀ¼
                OUT HANDLE  *processId,             // ����handle
                OUT HANDLE  *threadId               // ���̵����߳�handle
                );

// ǿ����ֹһ������
// (�������ã�����֪ͨ�����õĽ��̣����ܶ�����)
extern int GFXA_terminate_process
                (
                IN  HANDLE  processId
                );

// ��ȡ��ǰ����id
extern int GFXA_get_current_process_id
                (
                OUT UINT32  *processId
                );


// ����һ���߳�
extern int GFXA_create_thread
                (
                IN  int  stackSize,                 // �̶߳�ջ��С��0��ʾĬ�ϴ�С
                IN  FUNCPTR  func,                  // �߳����������
                IN  void  *parameter,               // ��������
                OUT UINT32  *threadId               // �����߳�id
                );

// ǿ����ֹһ���߳�
// (�������ã�����֪ͨ�����õ��̣߳����ܶ�����))
extern int GFXA_terminate_thread
                (
                IN  HANDLE  threadId
                );

// ��ȡ��ǰ�߳�id
extern int GFXA_get_current_thread_id
                (
                OUT UINT32  *threadId
                );

//
// <����ϵͳ��errno���>
//

// ��ȡ�߳����Ĵ�������Ϣ
extern int GFXA_get_errno
                (
                OUT UINT32 *err               // ����ϵͳ������
                );

// �����̵߳Ĵ�����
extern int GFXA_set_errno
                (
                IN UINT32 err                 // ������
                );

// ��ϵͳ������ת��Ϊ�ַ���
extern int GFXA_errno_to_string
                (
                IN  UINT32 err,                 // ������
                OUT char *buffer,               // ���ת����ĸ�ʽ�ִ�����
                IN  int  size                   // �����С�� Ҫ�㹻��Ŀǰϵͳ���Ĵ�����Ϣ��57���ַ�������64�ֽ�
                );


// ���ַ������ݷָ����ָ�Ϊ�������ַ���
extern int GFXA_break_string_to_substr
                (
                IN char *buf,               // �����ַ���
                IN char *space,             // �ָ���
				OUT char *buf1,             // ��һ�����ַ���
				OUT char *buf2,             // �ڶ������ַ���
				OUT char *buf3,             // ���������ַ���
				OUT char *buf4              // ���ĸ����ַ���
				);


#endif // end of GF_C


#ifdef __cplusplus
}
#endif

#endif  // end of GFXA_WIN_H

