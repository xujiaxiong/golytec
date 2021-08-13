/* libTSXA.h  - iTS driver extern interface head file for windows */

/* modification history
-----------------------
02a 2020/15/12 17:00:11   ����ע��
01a 2016/5/3 14:40:31    create by frank
*/



#ifndef TSXA_IF_H
#define TSXA_IF_H


#ifdef __cplusplus
extern "C" {
#endif


#include  "golytec.h"



// defines

// bit�����أ����㱣�ֺ�����λ����Ҫ���ֵ�ʱ��
#define         FPGA_SLEEP_TIME      3             // fpga��������ʱ�� 3ms
#define         NIOS_SLEEP_TIME      30            // nios��Ҫʱ�䳤�� 30ms


// errno defines
//#define     TSXA_BASE_ERROR                     0x54530000
#define     TSXA_BASE_ERROR                     0x0
#define     TSXA_SYSTEM_ERROR                   ( TSXA_BASE_ERROR + 0x01 )
#define     TSXA_ILLEGAL_CALL_ERROR             ( TSXA_BASE_ERROR + 0x02 )
#define     TSXA_TIMEOUT_ERROR                  ( TSXA_BASE_ERROR + 0x03 )
#define     TSXA_PARAMETER_ERROR                ( TSXA_BASE_ERROR + 0x04 )

#define     TSXA_BUFFER_ST_NO_MOVER_ERROR             20        // ���幤λû�ж���ͣ��

#define     TSXA_DN_TASK_NUM_INIT_EXCEED_ERROR            21        // DN�����ʼ��ע����̳߳�����     
#define     TSXA_ST_OP_RETRY_ERROR							22    // ��λop�����������Դ���


// INPUT  SYS
#define     SYS_CONTROL_ADDR                0X00

#define     SYS_G_VEL_ADDR                  0X22
#define     SYS_G_ACC_ADDR                  0X24
#define     SYS_G_JERK_ADDR                 0X26

#define     SYS_IN_MOVER_OFFSET_ADDR        0X40
#define     SYS_IN_STATION_PARA_ADDR        0X44

#define     STN_MOVE_NEXT_0_ADDR           0x80
#define     STN_MOVE_NEXT_32_ADDR          0x84
#define     STN_QSTOP_0_ADDR                0x88
#define     STN_QSTOP_32_ADDR                0x8c
#define     STN_EN_0_ADDR                0x90
#define     STN_EN_32_ADDR                0x94
#define     STN_MV_ENTR_ALLOW_0_ADDR           0x98
#define     STN_MV_ENTR_ALLOW_32_ADDR          0x9c
#define     STN_QSTOP_RESUME_0_ADDR      0xc0
#define     STN_QSTOP_RESUME_32_ADDR      0xc4


// INPUT MOVER 0
#define     MOVER_CONTROL_ADDR              0X100
#define     MOVER_TARGET_VEL_ADDR           0X102
#define     MOVER_TARGET_POS_ADDR           0X104
#define     MOVER_SET_ACC_ADDR              0X108
#define     MOVER_SET_DEC_ADDR              0X10A





// OUTPUT SYS
#define     SYS_STATUS_ADDR                 0X1000
#define     SYS_ERRNO_ADDR                  0X1004

#define     SYS_OUT_MOVER_OFFSET_ADDR       0x1040


// OUTPUT MOVER 0
#define     MOVER_STATUS_ADDR               0X1100
#define     MOVER_ACT_VEL_ADDR              0X1102
#define     MOVER_ACT_POS_ADDR              0X1104

// OUTPUT STATION 0
#define     STATION_STATUS_ADDR             0X1820


#define     ACTIVE_STATION_NUM         32



#pragma pack(1)

typedef struct
{
    UINT16 control;
    UINT16 target_vel;
    int    target_pos;
    UINT16 target_acc;
    UINT16 target_dec;
} TSXA_MOVER_INPUT_struct;


typedef struct
{
    UINT16 status;
    INT16 act_vel;
    int    act_pos;
} TSXA_MOVER_OUTPUT_struct;


typedef struct
{
    int  station_id;            // ��λid
    int  next_id;               // ָ�����һ����λid
    BOOL  station_en;           // ��λ�Ƿ�ʹ��
    BOOL  allow_in;             // �Ƿ������ȥ
    BOOL  independent;          // �Ƿ������λ
    BOOL  left_limit_en;        // ��λռ��ʱ����λ����
    BOOL  right_limit_en;       // ��λռ��ʱ����λ����
    BOOL  over_cycle_to_next;   // ����һ��λ��Ҫ����
    BOOL  stop_sim_delay;       // �Ƿ�ģ��ͣ��        ��ʱû��
    int   stop_sim_delay_time;  // ģ��ͣ��ʱ��   ms   ��ʱû��
    double base_pos;            // ��λλ��  ��λmm
    double vel;                 // �ٶ�     ��λ mm/s
    double acc;                 // ���ٶ�   ��λ  mm/s^2
    double dec;                 // ���ٶ�   ��λ  mm/s^2
    double left;                // ��߽�(ָ��λ��Χ����ֵС��һ�ߣ�һ���Ǹ�ֵ)
    double right;               // �ұ߽�(ָ��λ��Χ����ֵ���һ�ߣ�һ������ֵ)
} TSXA_SYS_STATION_para_struct;


typedef struct
{
    UINT16 station_en;          // ʹ��
    UINT8  station_op;          // �������ݣ�����д��0x54, 0x55
    UINT8  station_id;          // ��λid
    UINT16 allow_entering;      // �����ӽ���
    UINT16 independent;         // �Ƿ������λ�� 1-������λ  0-ͬ����λ
    INT32 base_pos;             // ��λλ��
    UINT32 over_cycle_to_next;   // ����һ��λ��Ҫ����
    UINT32 base_stop_sim_delay;  // ���漰ͣ����ʱ  ��ʱû��
    INT32 vel;                  // ��λmm/s
    INT32 acc;                  // ��λmm/s^2
    INT32 dec;                  // ��λmm/s^2
    UINT16 left_limit_enable;   // ����λʹ��
    UINT16 right_limit_enable;  // ����λʹ��
    INT16  left;                // ��λ��Χ��߽�ƫ����, mm
    INT16  right;               // ��λ��Χ�ұ߽�ƫ����, mm
    UINT32 next_station_id;     // ָ�����һ����λid
} TSXA_SYS_STATION_OP_struct;


#pragma pack()



// TSXA��������
#ifndef TS_C

    //// ͨ�ýӿ�   UDP�ռ���ʽӿ�

// ��ʼ������ͨ������ÿ���߳̿�ʼ������Ҫ�ȵ��ù�������������ܵ�������TS�ӿ�
extern int TSXA_init_network( void );


// ��ֹ����ͨ������ÿ���̵߳Ľ���ǰ����
extern int TSXA_term_network( void );


// ��һ���Ĵ���ֵ��32bit
extern int MIO_read_reg
            (
            IN int addr,                // ��ַ
            OUT UINT32 *value           // ��ȡ������ֵ
            );


// дһ���Ĵ�����32bit
extern int MIO_write_reg
            (
            IN int addr,                // ��ַ
            IN UINT32 value             // д���ֵ
            );


// ��ȡһƬ�Ĵ����ռ�����, 32bitΪ��λ
extern int MIO_read_reg_longs
            (
            IN int addr,                // ��ʼ��ַ
            OUT UINT32 *value,          // ��ȡ��Ż���
            IN int int32_size           // 32bit�����ݸ���
            );


// д��һƬ�Ĵ����ռ�����, 32bitΪ��λ
extern int MIO_write_reg_longs
            (
            IN int addr,                // ��ʼ��ַ
            IN UINT32 *value,           // ���д���������ݵĻ���
            IN int int32_size           // 32bit�����ݸ���
            );


//
/// ����Ӧ�÷�װ�ӿ�
//

// ����iTSϵͳ������sys_control(udp��ַ: 0x0)��ĳ��bitλΪ1
extern int TSXA_sys_control_set_bit
            (
            IN int bit_index            // Ҫ��1��bit  0-31
            );


// ��iTSϵͳ������sys_control(0x0)������bit����
extern int TSXA_sys_control_clr(void);


// ����mover_control(udp��ַ: 0x100 + 12 * id)��ĳ��λΪ1
extern int TSXA_mover_control_set_bit
            (
            IN int id,                  // ����id
            IN int bit_index           // Ҫ��1��bit  0-31
            );


// ��mover_control(udp��ַ: 0x100 + 12 * id)����λ����
extern int TSXA_mover_control_clr(IN int id);


// iTSϵͳ��ʼ��   ��Ӧsys_control��bit0
extern int TSXA_sys_initialize(void);


// iTSϵͳ��ֹ    ��Ӧsys_control��bit1
extern int TSXA_sys_terminate(void);


// iTSϵͳ������λ�Զ�����    ��Ӧsys_control��bit2
extern int TSXA_sys_start_work(void);


// ֹͣ��λ�Զ�����    ��Ӧsys_control��bit3
extern int TSXA_sys_stop_work(void);


// ��ͣ��λ�Զ�����   ��Ӧsys_control��bit4
extern int TSXA_sys_pause_work(void);


// �ָ���λ�Զ�����   ��Ӧsys_control��bit5
extern int TSXA_sys_resume_work( void );


// ֹͣ���ж��ӵ��˶�    ��Ӧsys_control��bit7
extern int TSXA_sys_stop(void);


// ϵͳ��ͣ     ��Ӧsys_control��bit8
extern int TSXA_sys_quick_stop(void);


// ��������ϵͳ���󣬻ָ�ϵͳ    ��Ӧsys_control��bit12
extern int TSXA_sys_reset_err(void);


// ��λ�ô����Զ��ָ�����(�˲�������ϵͳ�ķ���)   ��Ӧsys_control��bit14
extern int TSXA_sys_auto_pos_err_reset_on(void);


// �ر�λ�ô����Զ��ָ�����     ��Ӧsys_control��bit14
extern int TSXA_sys_auto_pos_err_reset_off(void);


// ���й�λ�ϵĶ��Ӷ�����һ����λ�˶�   ��Ӧsys_control��bit15
extern int TSXA_sys_move_to_next_station_all( void );


// ���ж����ŷ��ϵ�   ��Ӧsys_control��bit16(�ڹ�λ�Զ��رյ��������Ч)
extern int TSXA_sys_enable_axis_all( void );


// ���ж����ŷ��ϵ�  ��Ӧsys_control��bit17(�ڹ�λ�Զ��رյ��������Ч)
extern int TSXA_sys_disable_axis_all( void );


// ��ȡĬ�ϵĻ���������ϵͳ��  ��Ӧsys_control��bit20-23����(�ڹ�λ�Զ��رյ��������Ч)
extern int TSXA_sys_load_default_mc(void);


// ���޸Ĺ��Ļ����������ñ��浽ϵͳ��  ��Ӧsys_control��bit20-23����(�ڹ�λ�Զ��رյ��������Ч)
extern int TSXA_sys_save_mc_to_flash(void);


// ���ö��ӵ�ƫ��ֵ(����У������������˶������ϵ�ƫ��)
extern int TSXA_sys_set_mover_offset
                (
                IN int axis,
                IN double offset
                );


// ��ȡ���ӵ�ƫ��ֵ
extern int TSXA_sys_get_mover_offset
                (
                IN int axis,
                OUT double *offset
                );


// ��ȡϵͳ״ֵ̬��������   sys_status:0x1000  sys_errno: 0x1004
extern int TSXA_sys_get_status
                (
                OUT UINT32 *sys_status,             // ϵͳ״̬��
                OUT UINT32 *sys_errno,               // ϵͳ������
                OUT     UINT32 *sys_errinfo         // ϵͳ��Ϣ��
                );


// ��ȡʵ�ʶ��Ӹ���   mover_num: 0x101d  station_num: 0x101e
extern int TSXA_sys_get_mover_num
                (
                OUT int *mover_num,         // ���Ӹ���
                OUT int *station_num        // ��λ����
                );


// ��̬���ù�λ����   (udp��ַ: 0x44 - 0x6f)
extern int TSXA_st_set_station_para
                (
                IN int id,                            // ��λid
                IN TSXA_SYS_STATION_para_struct para  // ��λ����
                );


// ����λ�ϵĶ����ƶ�����һ����λ   (udp:0x80/0x84 �Ĵ�����Ӧ��bit)
extern int TSXA_st_move_next_station
            (
            IN int station_id                   // ��λid
            );


// ����λ�ϵĶ����ƶ�����һ����λ   (udp:0x80/0x84 �Ĵ�����Ӧ��bit)
extern int TSXA_st_move_next_station_multi
            (
            IN UINT32 station_list,              // 0-31��λid�б�ÿ��bit��Ӧһ����λ
            IN UINT32 station_list_32_63      // 32-63��λid�б�ÿ��bit��Ӧһ����λ
            );


// ��������λ��Χ�ڵĶ��Ӽ�ͣ   (udp:0x88/0x8c�Ĵ�����Ӧ��bit)
extern int TSXA_st_qstop
            (
            IN int station              // ��λid
            );


// ��������λ��Χ���Ѽ�ͣ�Ķ��ӻָ�����   (udp:0xc0/0xc4 �Ĵ�����Ӧ��bit)
extern int TSXA_st_qstop_resume(IN int station);


// ����ʹ��ĳ����λ
extern int TSXA_st_enable(IN int station_id);


// ����ͣ��ĳ����λ
extern int TSXA_st_disable(IN int station_id);



// ��ȡͣ���ڹ�λ�ϵĶ���id
extern int TSXA_st_get_mover_id
            (
            IN int st_id,               // ��λid
            OUT BOOL *reached,          // �Ƿ��ж��ӵ���  
            OUT int *mover_id           // ���صĶ���id
            );




// �����ŷ��ϵ�  (udp : 0x100+12*axis bit1)
extern int TSXA_axis_enable
            (
            IN int axis             // ����id
            );


// �����ŷ��ϵ�  (udp : 0x100+12*axis bit1)
extern int TSXA_axis_disable
            (
            IN int axis             // ����id
            );


// ���Ӿ����˶�  (udp : 0x100+12*axis bit3) 
extern int TSXA_axis_move_abs
            (
            IN      int     axis,        // ����id
            IN      double  pos,         // Ŀ��λ��
            IN      double  vel,         // �ٶ�
            IN      double  acc,         // ���ٶ�
            IN      double  dec          // ���ٶ�
            );


// ���Ӿ����˶��������˶���Χ����  (udp : 0x100+12*axis bit3) 
extern int TSXA_axis_limit_move_abs
            (
            IN      int     axis,           // ����id
            IN      double  pos,            // Ŀ��λ��
            IN      double  max_offset,     // ����ƫ�Ʒ�Χ
            IN      double  vel              // ����ٶȣ�0ʹ��Ĭ�ϲ���
            );


// ���Ӿ����˶��������˶���Χ����  (udp : 0x100+12*axis bit3) 
// ��acc dec����
extern int TSXA_axis_limit_move_abs_2
            (
            IN      int     axis,           // ����id
            IN      double  pos,            // Ŀ��λ��
            IN      double  max_offset,     // ����ƫ�Ʒ�Χ
            IN      double  vel,              // ����ٶȣ�0ʹ��Ĭ�ϲ���
            IN      double  acc,			// acc
            IN      double  dec				// dec
            );



// ��������˶�  (udp : 0x100+12*axis bit4) 
extern int TSXA_axis_move_rel
            (
            IN      int     axis,        // ����id
            IN      double  pos,         // ����˶�λ����
            IN      double  vel,         // �ٶ�
            IN      double  acc,         // ���ٶ�
            IN      double  dec          // ���ٶ�
            );


// ���Ӽ�ͣ (udp : 0x100+12*axis bit7)
extern int TSXA_axis_quick_stop
            (
            IN int axis                 // ����id
            );


// ��������ֹͣ�˶�  (udp : 0x100+12*axis bit8)
extern int TSXA_axis_stop
            (
            IN int axis                 // ����id
            );


// ����������󣬳��Իָ����� (udp : 0x100+12*axis bit9)
extern int TSXA_axis_reset
            (
            IN int axis                 // ����id
            );


// �����ٶ�ģʽ���У��ᰴ�ٶ�һֱ������ȥ��ֱ����ֹͣ (udp : 0x100+12*axis bit10)  (��λ�Զ����йر��������Ч)
extern int TSXA_axis_move_vel
                (
                IN int axis,                // ����id
                IN BOOL forward,            // �Ƿ�������
                IN double vel,              // �ٶ�
                IN double acc               // ���ٶ�
                );


// ��̬�޸Ķ��������ٶ�  (udp : 0x100+12*axis bit11)  (��λ�Զ����йر��������Ч)
extern int TSXA_axis_change_vel
                (
                IN int axis,                // ����id
                IN double vel               // �µ��ٶ�
                );


// ������Ӿ�������   (��λ�Զ����йر��������Ч)
extern int TSXA_axis_move_abs_g
            (
            IN      int     num,            // ��Ҫ�˶��Ķ��Ӹ���
            IN      int     *axis_list,     // �����б�
            IN      double  *pos_list,       // �������ӵ�Ŀ��λ��
            IN      double  *vel_list,       // �ٶ��б�, 0��ʾʹ��ԭ����ֵ
            IN      double  *acc_list,        // �����б�, 0��ʾʹ��ԭ����ֵ
            IN      double  *dec_list       // ���ٶ��б�, 0��ʾʹ��ԭ����ֵ
            );


// ��������������   (��λ�Զ����йر��������Ч)
extern int TSXA_axis_move_rel_g
            (
            IN      int     num,            // ��Ҫ�˶��Ķ��Ӹ���
            IN      int     *axis_list,     // �����б�
            IN      double  *pos_list,       // �������ӵ�����˶�ƫ��ֵ
            IN      double  *vel_list,       // �ٶ��б�, 0��ʾʹ��ԭ����ֵ
            IN      double  *acc_list,        // �����б�, 0��ʾʹ��ԭ����ֵ
            IN      double  *dec_list       // ���ٶ��б�, 0��ʾʹ��ԭ����ֵ
            );


// ���ж�������˶�
extern int TSXA_axis_move_rel_all
            (
            IN      int     num,            // ���ж��Ӹ���
            IN      double  pos_rel,       // ���ж��ӵ�����˶�ƫ��ֵ
            IN      double  vel,            // �ٶ�, 0��ʾʹ��ԭ����ֵ
            IN      double  acc,            // ���ٶ�, 0��ʾʹ��ԭ����ֵ
            IN      double  dec             // ���ٶ�, 0��ʾʹ��ԭ����ֵ
            );


// ��ȡ����״̬
extern int TSXA_axis_get_status
            (
            IN int axis,                    // ����id
            OUT UINT16 *mover_status,      // ����״̬��
            OUT double *act_pos,             // λ��
            OUT double *act_vel            // �ٶ�
            );


// ��ȡ�������״̬
extern int TSXA_axis_get_status_g
            (
            IN int mover_num,                   // ���Ӹ���
            IN int *axis_list,                  // �����б�
            OUT UINT16 *mover_status_list,     // ����״̬��
            OUT double *act_vel_list,           // �ٶ��б�
            OUT double *act_pos_list            // λ���б�
            );


// �ȴ������˶�ֹͣ, �����ᱻ����ס��ֱ������ֹͣ��ʱ
extern int TSXA_axis_wait_move_end
            (
            IN int axis,                    // ����id
            IN int timeout                  // ��ʱʱ�䣬msΪ��λ, -1Ϊ��Զ�ȴ�
            );


// �ȴ���������˶�ֹͣ
extern int TSXA_axis_wait_move_end_g
            (
            IN int num,                      // ���Ӹ���
            IN int *axis_list,              // ����id
            IN int timeout                  // ��ʱʱ�䣬msΪ��λ, -1Ϊ��Զ�ȴ�
            );




// ��ȡ����λ��
extern int TSXA_get_mover_pos
            (
            IN      int     axis,       // ����id
            OUT     double  *pos,        // λ��
            OUT     double  *vel        // �ٶ�
            );


// ��ȡ�������λ��
extern int TSXA_get_mover_pos_group
            (
            IN      int     num,            // ��Ҫ��ȡ�Ķ��Ӹ���
            IN      int     *axis_list,     // �����б�
            OUT     double  *pos_list       // λ���б�
            );


// ���ö����˶�����
extern int TSXA_set_motion_parameter
            (
            IN int axis,                // ����id
            IN double vel,              // �ٶ�
            IN double acc,              // ���ٶ�
            IN double dec               // ���ٶ�
            );


// ��ȡ�����˶�����
extern int TSXA_get_motion_parameter
            (
            IN int axis,                // ����id
            OUT double *vel,            // �ٶ�
            OUT double *acc,            // ���ٶ�
            OUT double *dec             // ���ٶ�
            );


// ����ȫ���˶�����
extern int TSXA_set_global_motion_parameter
            (
            IN double vel,              // ȫ���ٶ�
            IN double acc,              // ȫ�ּ��ٶ�
            IN double dec               // ȫ�ּ��ٶ�
            );


// ��ȡȫ���˶�����
extern int TSXA_get_global_motion_parameter
            (
            OUT double *vel,                 // �ٶ�
            OUT double *acc,                 // ���ٶ�
            OUT double *dec,                 // ���ٶ�
            OUT double *quick_stop_acc,     // ��ͣ���ٶ�
            OUT double *jerk                 // �Ӽ��ٶ�
            );


// ���ж����ŷ��ϵ�
extern int TSXA_axis_disable_all
            (
            IN int num                      // ���ж��Ӹ���
            );


// ���ж����ŷ��ϵ�
extern int TSXA_axis_enable_all
            (
            IN int num                  // ���ж��Ӹ���
            );



// ����0-31��λ�ĵ�λ���
extern int TSXA_st_get_all_mover_id
        (
            OUT int *st_reached_num,                 // ��λ���ж��ӵ���Ĺ�λ����
            OUT int st_reached_id_list[32],          // �ж��ӵ���Ĺ�λ����б�
            OUT int reaced_mover_id_list[32]        // ������Ӧ��λ�Ķ��ӱ��
        );


// ����32-63��λ�ĵ�λ���
extern int TSXA_st_get_all_mover_id_32
        (
            OUT int *st_reached_num,                 // ��λ���ж��ӵ���Ĺ�λ����
            OUT int st_reached_id_list[32],          // �ж��ӵ���Ĺ�λ����б�
            OUT int reaced_mover_id_list[32]        // ������Ӧ��λ�Ķ��ӱ��
        );


// ��ȡ��λ��Χ����û�ж���
extern int TSXA_st_get_occupy
		(
		IN int st_id,  			// ��λid
		OUT BOOL *has			// �Ƿ��ж����ڹ�λ��Χ��   1 - �ж����ڹ�λ��Χ��  0 - û��
		);


// ���ù�λ�Ƿ������ӽ���
extern int TSXA_st_set_allow_entering
		(
		IN int st_id,			// ��λid
		IN BOOL allow			// �Ƿ������ӽ��뱾��λ�� 1 - ����  0 - ��ֹ
		);


// ��ȡϵͳ�Ƿ��ʼ����Ϣ
extern int TSXA_get_sys_state
		( 
		OUT BOOL *inited, 		// iTSϵͳ�Ƿ��Ѿ���ʼ��   1 - �ѳ�ʼ��  0 - δ��ʼ��
		OUT BOOL *autoworked	// ��վ�Զ������Ƿ��Ѿ�����    1 - ����������   0 - δ����
		);


// ��ȡ��λλ��
extern int TSXA_st_get_pos
		(
		IN int st_id,  			// ��λid
		OUT double *pos			// ��λλ��
		);

// ����ʹ���Դﵽ�ù�λ��ǰ����λ�Ƿ����������station_opΪ1����ͨ����0������ͨ��
// ��ȡ����ʹ��TSXA_st_act_limit
extern int TSXA_st_limit
		(
		IN int station_id, 
		IN BOOL station_op		//0�Ͽ���λʹ��    1ʹ�ܹ�λ
		);
		
// ��ȡ�����Ƿ�ʹ��
extern int TSXA_mv_ison
		(
		IN int mover_id, 
		OUT int* yes
		);		    


// ���ø��¹�λ��λ�ü��ٶ���Ϣ
extern int TSXA_st_set_station_pv
                (
                IN int id,
                IN double pos,
                IN double vel,
                IN BOOL save_to_flash                   // �Ƿ񱣴浽flash���ñ���
                );

// ����ʹ���Դﵽ�ù�λ�Ƿ����������station_opΪ1����ͨ����0������ͨ��
extern int TSXA_st_act_limit
				(
				IN int station_id, 
				IN BOOL station_op		//0�Ͽ���λʹ��    1ʹ�ܹ�λ
				);


// ���ù�λ�����ұ߽���λ�����Ƿ��
extern int TSXA_st_set_station_limit
				(
				IN  int st_id,				// ��λid
				IN  BOOL  left_limit,		// ռ��ʱ��λ�����λ���أ�������ֵС��һ��
				IN  BOOL  right_limit		// ��λ�ұ���λ���أ�������ֵ���һ��
				);




////  YMDʹ��

// ���ڵ㽺��λ�Ĺ�λѡ�� 
        // ��������:
        // ǰ���м������幤λ���·��������ʱ��һ����黺�����ж��ӣ������·�����������н�ȥ��Ӧ�������ӣ�ֻ��Ҫ���ӿ��Է��У�����������0.
        //  �������û�ж��ӣ��ͷ��ش���ֵ;mes���ٹ�Լ150ms�ٷ������
        // ����: ��������������ռ䲻������һ���ܷ�3����λ
extern int  TSXA_st_dianjiao_set
        (
        IN int st_num,              // ��Ч�Ĺ�λ����
        IN int st_list[8]           // �㽺��Ч�Ĺ�λ�б�����û��ʹ�õ���0���
       );


// ������װ��λ�Ĺ�λѡ��
extern int  TSXA_st_zhuzhuang_set
        (
        IN int st_num,              // ��Ч�Ĺ�λ����
        IN int st_list[8]            // ��װ��Ч�Ĺ�λ�б�����û��ʹ�õ���0���
       );


// ��ȡĳ��λ�������ڵ��ж��ٸ�����
extern int TSXA_get_mover_num_in_pos(IN double pos1, IN double pos2, OUT int *num);



// ������õ㽺���칤λ�Ķ��ӵ��������������������������ƶ���ǰ�湤λ
extern int TSXA_emd_glue_check_st_movefront(void);


// ѡ��ӿڿ�ͨ��port��������0-3��ѡ
extern int TSXT_select_port_index
        (
        IN      int index
        );


// ��ȡ��λ�Ƿ�ʹ��״̬
extern int TSXA_st_get_status
            (
            IN int st_id,                   // ��λid
            OUT BOOL *enable                // �Ƿ�ʹ��״̬��1-enable 0-disable
            );

// ����tsma����
extern int TSXA_tsma_restart(void);



#endif // end of TS_C



#ifdef __cplusplus
}

#endif

#endif  // end of TSXA_IF_H



