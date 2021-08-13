/* libTSXA.h  - iTS driver extern interface head file for windows */

/* modification history
-----------------------
02a 2020/15/12 17:00:11   整理注释
01a 2016/5/3 14:40:31    create by frank
*/



#ifndef TSXA_IF_H
#define TSXA_IF_H


#ifdef __cplusplus
extern "C" {
#endif


#include  "golytec.h"



// defines

// bit上升沿，清零保持后再置位，需要保持的时间
#define         FPGA_SLEEP_TIME      3             // fpga的上升沿时间 3ms
#define         NIOS_SLEEP_TIME      30            // nios的要时间长点 30ms


// errno defines
//#define     TSXA_BASE_ERROR                     0x54530000
#define     TSXA_BASE_ERROR                     0x0
#define     TSXA_SYSTEM_ERROR                   ( TSXA_BASE_ERROR + 0x01 )
#define     TSXA_ILLEGAL_CALL_ERROR             ( TSXA_BASE_ERROR + 0x02 )
#define     TSXA_TIMEOUT_ERROR                  ( TSXA_BASE_ERROR + 0x03 )
#define     TSXA_PARAMETER_ERROR                ( TSXA_BASE_ERROR + 0x04 )

#define     TSXA_BUFFER_ST_NO_MOVER_ERROR             20        // 缓冲工位没有动子停留

#define     TSXA_DN_TASK_NUM_INIT_EXCEED_ERROR            21        // DN网络初始化注册的线程超限了     
#define     TSXA_ST_OP_RETRY_ERROR							22    // 工位op操作超过重试次数


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
    int  station_id;            // 工位id
    int  next_id;               // 指向的下一个工位id
    BOOL  station_en;           // 工位是否使能
    BOOL  allow_in;             // 是否允许进去
    BOOL  independent;          // 是否独立工位
    BOOL  left_limit_en;        // 工位占用时左限位开关
    BOOL  right_limit_en;       // 工位占用时右限位开关
    BOOL  over_cycle_to_next;   // 到下一工位需要过零
    BOOL  stop_sim_delay;       // 是否模拟停留        暂时没用
    int   stop_sim_delay_time;  // 模拟停留时间   ms   暂时没用
    double base_pos;            // 工位位置  单位mm
    double vel;                 // 速度     单位 mm/s
    double acc;                 // 加速度   单位  mm/s^2
    double dec;                 // 减速度   单位  mm/s^2
    double left;                // 左边界(指工位范围的数值小的一边，一般是负值)
    double right;               // 右边界(指工位范围的数值大的一边，一般是正值)
} TSXA_SYS_STATION_para_struct;


typedef struct
{
    UINT16 station_en;          // 使能
    UINT8  station_op;          // 更新数据，依次写入0x54, 0x55
    UINT8  station_id;          // 工位id
    UINT16 allow_entering;      // 允许动子进入
    UINT16 independent;         // 是否独立工位， 1-独立工位  0-同步工位
    INT32 base_pos;             // 工位位置
    UINT32 over_cycle_to_next;   // 到下一工位需要过零
    UINT32 base_stop_sim_delay;  // 仿真及停留延时  暂时没用
    INT32 vel;                  // 单位mm/s
    INT32 acc;                  // 单位mm/s^2
    INT32 dec;                  // 单位mm/s^2
    UINT16 left_limit_enable;   // 左限位使能
    UINT16 right_limit_enable;  // 右限位使能
    INT16  left;                // 工位范围左边界偏移量, mm
    INT16  right;               // 工位范围右边界偏移量, mm
    UINT32 next_station_id;     // 指向的下一个工位id
} TSXA_SYS_STATION_OP_struct;


#pragma pack()



// TSXA函数定义
#ifndef TS_C

    //// 通用接口   UDP空间访问接口

// 初始化网络通道，在每个线程开始处必须要先调用过这个函数，才能调用其它TS接口
extern int TSXA_init_network( void );


// 终止网络通道，在每个线程的结束前调用
extern int TSXA_term_network( void );


// 读一个寄存器值，32bit
extern int MIO_read_reg
            (
            IN int addr,                // 地址
            OUT UINT32 *value           // 读取回来的值
            );


// 写一个寄存器，32bit
extern int MIO_write_reg
            (
            IN int addr,                // 地址
            IN UINT32 value             // 写入的值
            );


// 读取一片寄存器空间内容, 32bit为单位
extern int MIO_read_reg_longs
            (
            IN int addr,                // 开始地址
            OUT UINT32 *value,          // 读取存放缓存
            IN int int32_size           // 32bit的数据个数
            );


// 写入一片寄存器空间内容, 32bit为单位
extern int MIO_write_reg_longs
            (
            IN int addr,                // 开始地址
            IN UINT32 *value,           // 存放写入数据内容的缓存
            IN int int32_size           // 32bit的数据个数
            );


//
/// 常用应用封装接口
//

// 设置iTS系统控制字sys_control(udp地址: 0x0)的某个bit位为1
extern int TSXA_sys_control_set_bit
            (
            IN int bit_index            // 要置1的bit  0-31
            );


// 将iTS系统控制字sys_control(0x0)的所有bit清零
extern int TSXA_sys_control_clr(void);


// 设置mover_control(udp地址: 0x100 + 12 * id)的某个位为1
extern int TSXA_mover_control_set_bit
            (
            IN int id,                  // 动子id
            IN int bit_index           // 要置1的bit  0-31
            );


// 将mover_control(udp地址: 0x100 + 12 * id)所有位清零
extern int TSXA_mover_control_clr(IN int id);


// iTS系统初始化   对应sys_control的bit0
extern int TSXA_sys_initialize(void);


// iTS系统终止    对应sys_control的bit1
extern int TSXA_sys_terminate(void);


// iTS系统启动工位自动运行    对应sys_control的bit2
extern int TSXA_sys_start_work(void);


// 停止工位自动运行    对应sys_control的bit3
extern int TSXA_sys_stop_work(void);


// 暂停工位自动运行   对应sys_control的bit4
extern int TSXA_sys_pause_work(void);


// 恢复工位自动运行   对应sys_control的bit5
extern int TSXA_sys_resume_work( void );


// 停止所有动子的运动    对应sys_control的bit7
extern int TSXA_sys_stop(void);


// 系统急停     对应sys_control的bit8
extern int TSXA_sys_quick_stop(void);


// 尝试清理系统错误，恢复系统    对应sys_control的bit12
extern int TSXA_sys_reset_err(void);


// 打开位置错误自动恢复功能(此操作有损坏系统的风险)   对应sys_control的bit14
extern int TSXA_sys_auto_pos_err_reset_on(void);


// 关闭位置错误自动恢复功能     对应sys_control的bit14
extern int TSXA_sys_auto_pos_err_reset_off(void);


// 所有工位上的动子都往下一个工位运动   对应sys_control的bit15
extern int TSXA_sys_move_to_next_station_all( void );


// 所有动子伺服上电   对应sys_control的bit16(在工位自动关闭的情况下有效)
extern int TSXA_sys_enable_axis_all( void );


// 所有动子伺服断电  对应sys_control的bit17(在工位自动关闭的情况下有效)
extern int TSXA_sys_disable_axis_all( void );


// 读取默认的机器常数到系统中  对应sys_control的bit20-23操作(在工位自动关闭的情况下有效)
extern int TSXA_sys_load_default_mc(void);


// 将修改过的机器常数永久保存到系统中  对应sys_control的bit20-23操作(在工位自动关闭的情况下有效)
extern int TSXA_sys_save_mc_to_flash(void);


// 设置动子的偏置值(用于校正多个动子在运动方向上的偏差)
extern int TSXA_sys_set_mover_offset
                (
                IN int axis,
                IN double offset
                );


// 获取动子的偏置值
extern int TSXA_sys_get_mover_offset
                (
                IN int axis,
                OUT double *offset
                );


// 获取系统状态值及错误码   sys_status:0x1000  sys_errno: 0x1004
extern int TSXA_sys_get_status
                (
                OUT UINT32 *sys_status,             // 系统状态码
                OUT UINT32 *sys_errno,               // 系统错误码
                OUT     UINT32 *sys_errinfo         // 系统信息码
                );


// 获取实际动子个数   mover_num: 0x101d  station_num: 0x101e
extern int TSXA_sys_get_mover_num
                (
                OUT int *mover_num,         // 动子个数
                OUT int *station_num        // 工位个数
                );


// 动态设置工位参数   (udp地址: 0x44 - 0x6f)
extern int TSXA_st_set_station_para
                (
                IN int id,                            // 工位id
                IN TSXA_SYS_STATION_para_struct para  // 工位参数
                );


// 将工位上的动子移动到下一个工位   (udp:0x80/0x84 寄存器对应的bit)
extern int TSXA_st_move_next_station
            (
            IN int station_id                   // 工位id
            );


// 将工位上的动子移动到下一个工位   (udp:0x80/0x84 寄存器对应的bit)
extern int TSXA_st_move_next_station_multi
            (
            IN UINT32 station_list,              // 0-31工位id列表，每个bit对应一个工位
            IN UINT32 station_list_32_63      // 32-63工位id列表，每个bit对应一个工位
            );


// 单独将工位范围内的动子急停   (udp:0x88/0x8c寄存器对应的bit)
extern int TSXA_st_qstop
            (
            IN int station              // 工位id
            );


// 单独将工位范围内已急停的动子恢复正常   (udp:0xc0/0xc4 寄存器对应的bit)
extern int TSXA_st_qstop_resume(IN int station);


// 单独使能某个工位
extern int TSXA_st_enable(IN int station_id);


// 单独停用某个工位
extern int TSXA_st_disable(IN int station_id);



// 获取停留在工位上的动子id
extern int TSXA_st_get_mover_id
            (
            IN int st_id,               // 工位id
            OUT BOOL *reached,          // 是否有动子到达  
            OUT int *mover_id           // 返回的动子id
            );




// 动子伺服上电  (udp : 0x100+12*axis bit1)
extern int TSXA_axis_enable
            (
            IN int axis             // 动子id
            );


// 动子伺服断电  (udp : 0x100+12*axis bit1)
extern int TSXA_axis_disable
            (
            IN int axis             // 动子id
            );


// 动子绝对运动  (udp : 0x100+12*axis bit3) 
extern int TSXA_axis_move_abs
            (
            IN      int     axis,        // 动子id
            IN      double  pos,         // 目标位置
            IN      double  vel,         // 速度
            IN      double  acc,         // 加速度
            IN      double  dec          // 减速度
            );


// 动子绝对运动，加了运动范围限制  (udp : 0x100+12*axis bit3) 
extern int TSXA_axis_limit_move_abs
            (
            IN      int     axis,           // 动子id
            IN      double  pos,            // 目标位置
            IN      double  max_offset,     // 最大的偏移范围
            IN      double  vel              // 最大速度，0使用默认参数
            );


// 动子绝对运动，加了运动范围限制  (udp : 0x100+12*axis bit3) 
// 带acc dec参数
extern int TSXA_axis_limit_move_abs_2
            (
            IN      int     axis,           // 动子id
            IN      double  pos,            // 目标位置
            IN      double  max_offset,     // 最大的偏移范围
            IN      double  vel,              // 最大速度，0使用默认参数
            IN      double  acc,			// acc
            IN      double  dec				// dec
            );



// 动子相对运动  (udp : 0x100+12*axis bit4) 
extern int TSXA_axis_move_rel
            (
            IN      int     axis,        // 动子id
            IN      double  pos,         // 相对运动位置量
            IN      double  vel,         // 速度
            IN      double  acc,         // 加速度
            IN      double  dec          // 减速度
            );


// 动子急停 (udp : 0x100+12*axis bit7)
extern int TSXA_axis_quick_stop
            (
            IN int axis                 // 动子id
            );


// 动子正常停止运动  (udp : 0x100+12*axis bit8)
extern int TSXA_axis_stop
            (
            IN int axis                 // 动子id
            );


// 动子清除错误，尝试恢复正常 (udp : 0x100+12*axis bit9)
extern int TSXA_axis_reset
            (
            IN int axis                 // 动子id
            );


// 动子速度模式运行，会按速度一直运行下去，直到被停止 (udp : 0x100+12*axis bit10)  (工位自动运行关闭情况下有效)
extern int TSXA_axis_move_vel
                (
                IN int axis,                // 动子id
                IN BOOL forward,            // 是否正方向
                IN double vel,              // 速度
                IN double acc               // 加速度
                );


// 动态修改动子运行速度  (udp : 0x100+12*axis bit11)  (工位自动运行关闭情况下有效)
extern int TSXA_axis_change_vel
                (
                IN int axis,                // 动子id
                IN double vel               // 新的速度
                );


// 多个动子绝对运行   (工位自动运行关闭情况下有效)
extern int TSXA_axis_move_abs_g
            (
            IN      int     num,            // 需要运动的动子个数
            IN      int     *axis_list,     // 动子列表
            IN      double  *pos_list,       // 各个动子的目标位置
            IN      double  *vel_list,       // 速度列表, 0表示使用原来的值
            IN      double  *acc_list,        // 加速列表, 0表示使用原来的值
            IN      double  *dec_list       // 减速度列表, 0表示使用原来的值
            );


// 多个动子相对运行   (工位自动运行关闭情况下有效)
extern int TSXA_axis_move_rel_g
            (
            IN      int     num,            // 需要运动的动子个数
            IN      int     *axis_list,     // 动子列表
            IN      double  *pos_list,       // 各个动子的相对运动偏移值
            IN      double  *vel_list,       // 速度列表, 0表示使用原来的值
            IN      double  *acc_list,        // 加速列表, 0表示使用原来的值
            IN      double  *dec_list       // 减速度列表, 0表示使用原来的值
            );


// 所有动子相对运动
extern int TSXA_axis_move_rel_all
            (
            IN      int     num,            // 所有动子个数
            IN      double  pos_rel,       // 所有动子的相对运动偏移值
            IN      double  vel,            // 速度, 0表示使用原来的值
            IN      double  acc,            // 加速度, 0表示使用原来的值
            IN      double  dec             // 减速度, 0表示使用原来的值
            );


// 获取动子状态
extern int TSXA_axis_get_status
            (
            IN int axis,                    // 动子id
            OUT UINT16 *mover_status,      // 动子状态字
            OUT double *act_pos,             // 位置
            OUT double *act_vel            // 速度
            );


// 获取多个动子状态
extern int TSXA_axis_get_status_g
            (
            IN int mover_num,                   // 动子个数
            IN int *axis_list,                  // 动子列表
            OUT UINT16 *mover_status_list,     // 动子状态字
            OUT double *act_vel_list,           // 速度列表
            OUT double *act_pos_list            // 位置列表
            );


// 等待动子运动停止, 函数会被阻塞住，直到动子停止或超时
extern int TSXA_axis_wait_move_end
            (
            IN int axis,                    // 动子id
            IN int timeout                  // 超时时间，ms为单位, -1为永远等待
            );


// 等待多个动子运动停止
extern int TSXA_axis_wait_move_end_g
            (
            IN int num,                      // 动子个数
            IN int *axis_list,              // 动子id
            IN int timeout                  // 超时时间，ms为单位, -1为永远等待
            );




// 获取动子位置
extern int TSXA_get_mover_pos
            (
            IN      int     axis,       // 动子id
            OUT     double  *pos,        // 位置
            OUT     double  *vel        // 速度
            );


// 获取多个动子位置
extern int TSXA_get_mover_pos_group
            (
            IN      int     num,            // 需要获取的动子个数
            IN      int     *axis_list,     // 动子列表
            OUT     double  *pos_list       // 位置列表
            );


// 设置动子运动参数
extern int TSXA_set_motion_parameter
            (
            IN int axis,                // 动子id
            IN double vel,              // 速度
            IN double acc,              // 加速度
            IN double dec               // 减速度
            );


// 获取动子运动参数
extern int TSXA_get_motion_parameter
            (
            IN int axis,                // 动子id
            OUT double *vel,            // 速度
            OUT double *acc,            // 加速度
            OUT double *dec             // 减速度
            );


// 设置全局运动参数
extern int TSXA_set_global_motion_parameter
            (
            IN double vel,              // 全局速度
            IN double acc,              // 全局加速度
            IN double dec               // 全局减速度
            );


// 获取全局运动参数
extern int TSXA_get_global_motion_parameter
            (
            OUT double *vel,                 // 速度
            OUT double *acc,                 // 加速度
            OUT double *dec,                 // 减速度
            OUT double *quick_stop_acc,     // 急停减速度
            OUT double *jerk                 // 加加速度
            );


// 所有动子伺服断电
extern int TSXA_axis_disable_all
            (
            IN int num                      // 所有动子个数
            );


// 所有动子伺服上电
extern int TSXA_axis_enable_all
            (
            IN int num                  // 所有动子个数
            );



// 所有0-31工位的到位情况
extern int TSXA_st_get_all_mover_id
        (
            OUT int *st_reached_num,                 // 工位上有动子到达的工位个数
            OUT int st_reached_id_list[32],          // 有动子到达的工位编号列表
            OUT int reaced_mover_id_list[32]        // 到达相应工位的动子编号
        );


// 所有32-63工位的到位情况
extern int TSXA_st_get_all_mover_id_32
        (
            OUT int *st_reached_num,                 // 工位上有动子到达的工位个数
            OUT int st_reached_id_list[32],          // 有动子到达的工位编号列表
            OUT int reaced_mover_id_list[32]        // 到达相应工位的动子编号
        );


// 获取工位范围内有没有动子
extern int TSXA_st_get_occupy
		(
		IN int st_id,  			// 工位id
		OUT BOOL *has			// 是否有动子在工位范围内   1 - 有动子在工位范围内  0 - 没有
		);


// 设置工位是否允许动子进入
extern int TSXA_st_set_allow_entering
		(
		IN int st_id,			// 工位id
		IN BOOL allow			// 是否允许动子进入本工位， 1 - 允许  0 - 禁止
		);


// 获取系统是否初始化信息
extern int TSXA_get_sys_state
		( 
		OUT BOOL *inited, 		// iTS系统是否已经初始化   1 - 已初始化  0 - 未初始化
		OUT BOOL *autoworked	// 工站自动运行是否已经启动    1 - 已正常启动   0 - 未启动
		);


// 获取工位位置
extern int TSXA_st_get_pos
		(
		IN int st_id,  			// 工位id
		OUT double *pos			// 工位位置
		);

// 单独使能以达到该工位的前个工位是否允许进出，station_op为1允许通过，0不允许通过
// 已取消，使用TSXA_st_act_limit
extern int TSXA_st_limit
		(
		IN int station_id, 
		IN BOOL station_op		//0断开工位使能    1使能工位
		);
		
// 获取动子是否使能
extern int TSXA_mv_ison
		(
		IN int mover_id, 
		OUT int* yes
		);		    


// 设置更新工位的位置及速度信息
extern int TSXA_st_set_station_pv
                (
                IN int id,
                IN double pos,
                IN double vel,
                IN BOOL save_to_flash                   // 是否保存到flash永久保存
                );

// 单独使能以达到该工位是否允许进出，station_op为1允许通过，0不允许通过
extern int TSXA_st_act_limit
				(
				IN int station_id, 
				IN BOOL station_op		//0断开工位使能    1使能工位
				);


// 设置工位的左右边界限位功能是否打开
extern int TSXA_st_set_station_limit
				(
				IN  int st_id,				// 工位id
				IN  BOOL  left_limit,		// 占用时工位左边限位开关，坐标数值小的一边
				IN  BOOL  right_limit		// 工位右边限位开关，坐标数值大的一边
				);




////  YMD使用

// 用于点胶工位的工位选择 
        // 大致流程:
        // 前面有几个缓冲工位，下发这个命令时，一旦检查缓冲区有动子，根据下发允许个数放行进去相应数量动子；只有要动子可以放行，就正常返回0.
        //  缓冲如果没有动子，就返回错误值;mes会再过约150ms再发新命令；
        // 问题: 缓冲区可能物理空间不够，不一定能放3个工位
extern int  TSXA_st_dianjiao_set
        (
        IN int st_num,              // 有效的工位个数
        IN int st_list[8]           // 点胶有效的工位列表，后续没有使用的用0填充
       );


// 用于组装工位的工位选择
extern int  TSXA_st_zhuzhuang_set
        (
        IN int st_num,              // 有效的工位个数
        IN int st_list[8]            // 组装有效的工位列表，后续没有使用的用0填充
       );


// 获取某个位置区间内的有多少个动子
extern int TSXA_get_mover_num_in_pos(IN double pos1, IN double pos2, OUT int *num);



// 检查设置点胶复检工位的动子到达情况，根据情况尽量将动子移动到前面工位
extern int TSXA_emd_glue_check_st_movefront(void);


// 选择接口库通信port的索引，0-3可选
extern int TSXT_select_port_index
        (
        IN      int index
        );


// 获取工位是否使能状态
extern int TSXA_st_get_status
            (
            IN int st_id,                   // 工位id
            OUT BOOL *enable                // 是否使能状态，1-enable 0-disable
            );

// 重启tsma任务
extern int TSXA_tsma_restart(void);



#endif // end of TS_C



#ifdef __cplusplus
}

#endif

#endif  // end of TSXA_IF_H



