/*    - this file auto generated by tools */

/* modification history
-----------------------

01a 2016-05-05 11:00:17     auto create by autogen moban tool
*/

/*
<autogen moban tool>
  author: frank
  bug report: frank_zhou@163.com
*/


#ifndef TSXI_H
#define TSXI_H

#ifdef __cplusplus
extern "C" {
#endif


#define TSXA_DEFAULT_TIMEOUT    60
#define TSXA_MA_ADDR            "TS_main"
#define TSXA_MA_ADDR_2          "TS_main_2"
#define TSXA_MA_ADDR_3          "TS_main_3"
#define TSXA_MA_ADDR_4          "TS_main_4"
#define TSXI_NUM_CODE           0X54535453





typedef struct
{
    int addr;
    int filler2;
} TSXI_MIO_read_reg_req_struct;

typedef struct
{
    UINT32 value;
    int filler;
} TSXI_MIO_read_reg_rpl_struct;



typedef struct
{
    int addr;
    UINT32 value;
} TSXI_MIO_write_reg_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_MIO_write_reg_rpl_struct;


typedef struct
{
    int addr;
    int int32_size;
} TSXI_MIO_read_reg_longs_req_struct;

typedef struct
{
    UINT32 value[256];
} TSXI_MIO_read_reg_longs_rpl_struct;


typedef struct
{
    int addr;
    int int32_size;
    UINT32 value[256];
} TSXI_MIO_write_reg_longs_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_MIO_write_reg_longs_rpl_struct;


typedef struct
{
    int bit_index;
} TSXI_TSXA_sys_control_set_bit_req_struct;

typedef struct
{
    int filler;
} TSXI_TSXA_sys_control_set_bit_rpl_struct;

typedef struct
{
    int filler;
} TSXI_TSXA_sys_control_clr_req_struct;

typedef struct
{
    int filler;
} TSXI_TSXA_sys_control_clr_rpl_struct;

typedef struct
{
    int id;
    int bit_index;
} TSXI_TSXA_mover_control_set_bit_req_struct;

typedef struct
{
    int filler;
} TSXI_TSXA_mover_control_set_bit_rpl_struct;

typedef struct
{
    int id;
} TSXI_TSXA_mover_control_clr_req_struct;

typedef struct
{
    int filler;
} TSXI_TSXA_mover_control_clr_rpl_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_initialize_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_initialize_rpl_struct;


typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_terminate_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_terminate_rpl_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_start_work_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_start_work_rpl_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_stop_work_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_stop_work_rpl_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_pause_work_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_pause_work_rpl_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_resume_work_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_resume_work_rpl_struct;


typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_stop_req_struct;

typedef struct
{
    BOOL    paused;
    int filler;
} TSXI_TSXA_sys_stop_rpl_struct;


typedef struct
{
    int  filler;
    int  filler2;
} TSXI_TSXA_sys_quick_stop_req_struct;

typedef struct
{
    BOOL    paused;
    int   filler;
} TSXI_TSXA_sys_quick_stop_rpl_struct;


typedef struct
{
    int  filler;
    int  filler2;
} TSXI_TSXA_sys_reset_err_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_reset_err_rpl_struct;


typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_auto_pos_err_reset_on_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_auto_pos_err_reset_on_rpl_struct;


typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_auto_pos_err_reset_off_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_auto_pos_err_reset_off_rpl_struct;


typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_move_to_next_station_all_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_move_to_next_station_all_rpl_struct;




typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_enable_axis_all_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_enable_axis_all_rpl_struct;


typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_disable_axis_all_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_disable_axis_all_rpl_struct;


typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_load_default_mc_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_load_default_mc_rpl_struct;


typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_save_mc_to_flash_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_save_mc_to_flash_rpl_struct;


typedef struct
{
    int axis;
    int filler2;
    double offset;
} TSXI_TSXA_sys_set_mover_offset_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_set_mover_offset_rpl_struct;


typedef struct
{
    int axis;
    int filler2;
} TSXI_TSXA_sys_get_mover_offset_req_struct;

typedef struct
{
    double offset;
} TSXI_TSXA_sys_get_mover_offset_rpl_struct;


typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_get_status_req_struct;

typedef struct
{
    UINT32 sys_status;
    UINT32 sys_errno;
    UINT32 sys_errinfo;
    int  filler;
} TSXI_TSXA_sys_get_status_rpl_struct;


typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_sys_get_mover_num_req_struct;

typedef struct
{
    int mover_num;
    int station_num;
} TSXI_TSXA_sys_get_mover_num_rpl_struct;


typedef struct
{
    int id;
    int filler2;
    TSXA_SYS_STATION_para_struct  para;
} TSXI_TSXA_st_set_station_para_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_set_station_para_rpl_struct;


typedef struct
{
    int st_id;
    int filler2;
} TSXI_TSXA_st_move_next_station_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_move_next_station_rpl_struct;


typedef struct
{
    UINT32 station_list;
    UINT32 station_list_32_63;
} TSXI_TSXA_st_move_next_station_multi_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_move_next_station_multi_rpl_struct;


typedef struct
{
    int station_id;
    int filler2;
} TSXI_TSXA_st_qstop_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_qstop_rpl_struct;


typedef struct
{
    int station_id;
    int filler2;
} TSXI_TSXA_st_qstop_resume_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_qstop_resume_rpl_struct;


typedef struct
{
    int station_id;
    int filler2;
} TSXI_TSXA_st_enable_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_enable_rpl_struct;


typedef struct
{
    int station_id;
    int filler2;
} TSXI_TSXA_st_disable_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_disable_rpl_struct;


typedef struct
{
    int st_id;
    int filler2;
} TSXI_TSXA_st_get_mover_id_req_struct;

typedef struct
{
    BOOL reached;
    int mover_id;
} TSXI_TSXA_st_get_mover_id_rpl_struct;


typedef struct
{
    int axis;
    int filler2;
} TSXI_TSXA_axis_enable_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_enable_rpl_struct;


typedef struct
{
    int axis;
    int filler2;
} TSXI_TSXA_axis_disable_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_disable_rpl_struct;


typedef struct
{
    int axis;
    int filler2;
    double  pos;
    double  vel;
    double  acc;
    double  dec;
} TSXI_TSXA_axis_move_abs_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_move_abs_rpl_struct;


typedef struct
{
    int axis;
    int filler2;
    double pos;
    double max_offset;
    double vel;
} TSXI_TSXA_axis_limit_move_abs_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_limit_move_abs_rpl_struct;




typedef struct
{
    int axis;
    int filler2;
    double pos;
    double max_offset;
    double vel;
	double acc;
	double dec;
} TSXI_TSXA_axis_limit_move_abs_2_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_limit_move_abs_2_rpl_struct;





typedef struct
{
    int axis;
    int filler2;
    double  pos;
    double  vel;
    double  acc;
    double  dec;
} TSXI_TSXA_axis_move_rel_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_move_rel_rpl_struct;

typedef struct
{
    int axis;
    int filler2;
} TSXI_TSXA_axis_quick_stop_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_quick_stop_rpl_struct;

typedef struct
{
    int axis;
    int filler2;
} TSXI_TSXA_axis_stop_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_stop_rpl_struct;

typedef struct
{
    int axis;
    int filler2;
} TSXI_TSXA_axis_reset_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_reset_rpl_struct;

typedef struct
{
    int axis;
    BOOL forward;
    double vel;
    double acc;
} TSXI_TSXA_axis_move_vel_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_move_vel_rpl_struct;

typedef struct
{
    int axis;
    int filler2;
    double vel;
} TSXI_TSXA_axis_change_vel_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_change_vel_rpl_struct;




typedef struct
{
    int     num;
    int     filler;
    int     axis_list[32];
    double  pos_list[32];
    double  vel_list[32];
    double  acc_list[32];
    double  dec_list[32];
} TSXI_TSXA_axis_move_abs_g_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_move_abs_g_rpl_struct;

typedef struct
{
    int     num;
    int    filler;
    int     axis_list[32];
    double  pos_list[32];
    double  vel_list[32];
    double  acc_list[32];
    double  dec_list[32];
} TSXI_TSXA_axis_move_rel_g_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_move_rel_g_rpl_struct;

typedef struct
{
    int   num;
    int   filler;
    double  pos_rel;
    double  vel;
    double  acc;
    double  dec;
} TSXI_TSXA_axis_move_rel_all_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_move_rel_all_rpl_struct;

typedef struct
{
    int     axis;
    int   filler;
} TSXI_TSXA_axis_get_status_req_struct;

typedef struct
{
    UINT16  mover_status;
    UINT16   filler;
    int   filler2;
    double  act_pos;
    double  act_vel;
} TSXI_TSXA_axis_get_status_rpl_struct;

typedef struct
{
    int     mover_num;
    int   filler;
    int     axis_list[32];
} TSXI_TSXA_axis_get_status_g_req_struct;

typedef struct
{
    UINT16  mover_status_list[32];
    double  act_vel_list[32];
    double  act_pos_list[32];
} TSXI_TSXA_axis_get_status_g_rpl_struct;

typedef struct
{
    int axis;
    int timeout;
} TSXI_TSXA_axis_wait_move_end_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_wait_move_end_rpl_struct;

typedef struct
{
    int num;
    int timeout;
    int axis_list[32];
} TSXI_TSXA_axis_wait_move_end_g_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_wait_move_end_g_rpl_struct;

typedef struct
{
    int     axis;
    int   filler;
} TSXI_TSXA_get_mover_pos_req_struct;

typedef struct
{
    double  pos;
    double  vel;
} TSXI_TSXA_get_mover_pos_rpl_struct;

typedef struct
{
    int     num;
    int  filler;
    int     axis_list[32];
} TSXI_TSXA_get_mover_pos_group_req_struct;

typedef struct
{
    double  pos_list[32];
} TSXI_TSXA_get_mover_pos_group_rpl_struct;

typedef struct
{
    int     axis;
    int  filler;
    double  vel;
    double  acc;
    double  dec;
} TSXI_TSXA_set_motion_parameter_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_set_motion_parameter_rpl_struct;

typedef struct
{
    int     axis;
    int  filler;
} TSXI_TSXA_get_motion_parameter_req_struct;

typedef struct
{
    double  vel;
    double  acc;
    double  dec;
} TSXI_TSXA_get_motion_parameter_rpl_struct;

typedef struct
{
    double  vel;
    double  acc;
    double  dec;
} TSXI_TSXA_set_global_motion_parameter_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_set_global_motion_parameter_rpl_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_get_global_motion_parameter_req_struct;

typedef struct
{
    double  vel;
    double  acc;
    double  dec;
    double  quick_stop_acc;
    double  jerk;
} TSXI_TSXA_get_global_motion_parameter_rpl_struct;

typedef struct
{
    int num;
    int filler;
} TSXI_TSXA_axis_disable_all_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_disable_all_rpl_struct;

typedef struct
{
    int num;
    int filler;
} TSXI_TSXA_axis_enable_all_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_axis_enable_all_rpl_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_get_all_mover_id_req_struct;

typedef struct
{
    int st_reached_num;
    int filler;
    int st_reached_id_list[32];
    int reaced_mover_id_list[32];
} TSXI_TSXA_st_get_all_mover_id_rpl_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_get_all_mover_id_32_req_struct;

typedef struct
{
    int st_reached_num;
    int filler;
    int st_reached_id_list[32];
    int reaced_mover_id_list[32];
} TSXI_TSXA_st_get_all_mover_id_32_rpl_struct;

typedef struct
{
    int     st_id;
    int  filler;
} TSXI_TSXA_st_get_occupy_req_struct;

typedef struct
{
    BOOL    has;
    int  filler;
} TSXI_TSXA_st_get_occupy_rpl_struct;

typedef struct
{
    int     st_id;
    BOOL    allow;
} TSXI_TSXA_st_set_allow_entering_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_set_allow_entering_rpl_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_get_sys_state_req_struct;

typedef struct
{
    BOOL    inited;
    BOOL    autoworked;
} TSXI_TSXA_get_sys_state_rpl_struct;

typedef struct
{
    int     st_id;
    int  filler;
} TSXI_TSXA_st_get_pos_req_struct;

typedef struct
{
    double  pos;
} TSXI_TSXA_st_get_pos_rpl_struct;

typedef struct
{
    int station_id;
    BOOL station_op;
} TSXI_TSXA_st_limit_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_limit_rpl_struct;

typedef struct
{
    int     mover_id;
    int  filler;
} TSXI_TSXA_mv_ison_req_struct;

typedef struct
{
    int    yes;
    int  filler;
} TSXI_TSXA_mv_ison_rpl_struct;

typedef struct
{
    int id;
    BOOL save_to_flash;
    double pos;
    double vel;
} TSXI_TSXA_st_set_station_pv_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_set_station_pv_rpl_struct;

typedef struct
{
    int station_id;
    BOOL limit_en;
} TSXI_TSXA_st_act_limit_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_act_limit_rpl_struct;


typedef struct
{
    int st_num;
    int filler;
    int st_list[8];
} TSXI_TSXA_st_dianjiao_set_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_dianjiao_set_rpl_struct;


typedef struct
{
    int st_num;
    int filler;
    int st_list[8];
} TSXI_TSXA_st_zhuzhuang_set_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_zhuzhuang_set_rpl_struct;



typedef struct
{
    int st_id;
    BOOL left_limit;
    BOOL right_limit;
    int filler;
} TSXI_TSXA_st_set_station_limit_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_st_set_station_limit_rpl_struct;


typedef struct
{
    double pos1;
    double pos2;
} TSXI_TSXA_get_mover_num_in_pos_req_struct;

typedef struct
{
    int num;
    int filler2;
} TSXI_TSXA_get_mover_num_in_pos_rpl_struct;


typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_emd_glue_check_st_movefront_req_struct;

typedef struct
{
    int filler;
    int filler2;
} TSXI_TSXA_emd_glue_check_st_movefront_rpl_struct;


typedef struct
{
    int st_id;
    int filler2;
} TSXI_TSXA_st_get_status_req_struct;

typedef struct
{
    BOOL enable;
    int filler2;
} TSXI_TSXA_st_get_status_rpl_struct;



/* ???????????? */
typedef union
{
    TSXI_MIO_read_reg_req_struct    MIO_read_reg_in_arg;
    TSXI_MIO_write_reg_req_struct    MIO_write_reg_in_arg;
    TSXI_MIO_read_reg_longs_req_struct    MIO_read_reg_longs_in_arg;
    TSXI_MIO_write_reg_longs_req_struct    MIO_write_reg_longs_in_arg;
    TSXI_TSXA_sys_control_set_bit_req_struct    TSXA_sys_control_set_bit_in_arg;
    TSXI_TSXA_sys_control_clr_req_struct    TSXA_sys_control_clr_in_arg;
    TSXI_TSXA_mover_control_set_bit_req_struct    TSXA_mover_control_set_bit_in_arg;
    TSXI_TSXA_mover_control_clr_req_struct    TSXA_mover_control_clr_in_arg;
    TSXI_TSXA_sys_initialize_req_struct    TSXA_sys_initialize_in_arg;
    TSXI_TSXA_sys_terminate_req_struct    TSXA_sys_terminate_in_arg;
    TSXI_TSXA_sys_start_work_req_struct    TSXA_sys_start_work_in_arg;
    TSXI_TSXA_sys_stop_work_req_struct    TSXA_sys_stop_work_in_arg;
    TSXI_TSXA_sys_pause_work_req_struct    TSXA_sys_pause_work_in_arg;
    TSXI_TSXA_sys_resume_work_req_struct    TSXA_sys_resume_work_in_arg;
    TSXI_TSXA_sys_stop_req_struct    TSXA_sys_stop_in_arg;
    TSXI_TSXA_sys_quick_stop_req_struct    TSXA_sys_quick_stop_in_arg;
    TSXI_TSXA_sys_reset_err_req_struct    TSXA_sys_reset_err_in_arg;
    TSXI_TSXA_sys_auto_pos_err_reset_on_req_struct    TSXA_sys_auto_pos_err_reset_on_in_arg;
    TSXI_TSXA_sys_auto_pos_err_reset_off_req_struct    TSXA_sys_auto_pos_err_reset_off_in_arg;
    TSXI_TSXA_sys_move_to_next_station_all_req_struct    TSXA_sys_move_to_next_station_all_in_arg;
    TSXI_TSXA_sys_enable_axis_all_req_struct    TSXA_sys_enable_axis_all_in_arg;
    TSXI_TSXA_sys_disable_axis_all_req_struct    TSXA_sys_disable_axis_all_in_arg;
    TSXI_TSXA_sys_load_default_mc_req_struct    TSXA_sys_load_default_mc_in_arg;
    TSXI_TSXA_sys_save_mc_to_flash_req_struct    TSXA_sys_save_mc_to_flash_in_arg;
    TSXI_TSXA_sys_set_mover_offset_req_struct    TSXA_sys_set_mover_offset_in_arg;
    TSXI_TSXA_sys_get_mover_offset_req_struct    TSXA_sys_get_mover_offset_in_arg;
    TSXI_TSXA_sys_get_status_req_struct    TSXA_sys_get_status_in_arg;
    TSXI_TSXA_sys_get_mover_num_req_struct    TSXA_sys_get_mover_num_in_arg;
    TSXI_TSXA_st_set_station_para_req_struct    TSXA_st_set_station_para_in_arg;
    TSXI_TSXA_st_move_next_station_req_struct    TSXA_st_move_next_station_in_arg;
    TSXI_TSXA_st_move_next_station_multi_req_struct    TSXA_st_move_next_station_multi_in_arg;
    TSXI_TSXA_st_qstop_req_struct    TSXA_st_qstop_in_arg;
    TSXI_TSXA_st_qstop_resume_req_struct    TSXA_st_qstop_resume_in_arg;
    TSXI_TSXA_st_enable_req_struct    TSXA_st_enable_in_arg;
    TSXI_TSXA_st_disable_req_struct    TSXA_st_disable_in_arg;
    TSXI_TSXA_st_get_mover_id_req_struct    TSXA_st_get_mover_id_in_arg;
    TSXI_TSXA_axis_enable_req_struct    TSXA_axis_enable_in_arg;
    TSXI_TSXA_axis_disable_req_struct    TSXA_axis_disable_in_arg;
    TSXI_TSXA_axis_move_abs_req_struct    TSXA_axis_move_abs_in_arg;
    TSXI_TSXA_axis_limit_move_abs_req_struct    TSXA_axis_limit_move_abs_in_arg;
    TSXI_TSXA_axis_move_rel_req_struct    TSXA_axis_move_rel_in_arg;
    TSXI_TSXA_axis_quick_stop_req_struct    TSXA_axis_quick_stop_in_arg;
    TSXI_TSXA_axis_stop_req_struct    TSXA_axis_stop_in_arg;
    TSXI_TSXA_axis_reset_req_struct    TSXA_axis_reset_in_arg;
    TSXI_TSXA_axis_move_vel_req_struct    TSXA_axis_move_vel_in_arg;
    TSXI_TSXA_axis_change_vel_req_struct    TSXA_axis_change_vel_in_arg;
    TSXI_TSXA_axis_move_abs_g_req_struct    TSXA_axis_move_abs_g_in_arg;
    TSXI_TSXA_axis_move_rel_g_req_struct    TSXA_axis_move_rel_g_in_arg;
    TSXI_TSXA_axis_move_rel_all_req_struct    TSXA_axis_move_rel_all_in_arg;
    TSXI_TSXA_axis_get_status_req_struct    TSXA_axis_get_status_in_arg;
    TSXI_TSXA_axis_get_status_g_req_struct    TSXA_axis_get_status_g_in_arg;
    TSXI_TSXA_axis_wait_move_end_req_struct    TSXA_axis_wait_move_end_in_arg;
    TSXI_TSXA_axis_wait_move_end_g_req_struct    TSXA_axis_wait_move_end_g_in_arg;
    TSXI_TSXA_get_mover_pos_req_struct    TSXA_get_mover_pos_in_arg;
    TSXI_TSXA_get_mover_pos_group_req_struct    TSXA_get_mover_pos_group_in_arg;
    TSXI_TSXA_set_motion_parameter_req_struct    TSXA_set_motion_parameter_in_arg;
    TSXI_TSXA_get_motion_parameter_req_struct    TSXA_get_motion_parameter_in_arg;
    TSXI_TSXA_set_global_motion_parameter_req_struct    TSXA_set_global_motion_parameter_in_arg;
    TSXI_TSXA_get_global_motion_parameter_req_struct    TSXA_get_global_motion_parameter_in_arg;
    TSXI_TSXA_axis_disable_all_req_struct    TSXA_axis_disable_all_in_arg;
    TSXI_TSXA_axis_enable_all_req_struct    TSXA_axis_enable_all_in_arg;
    TSXI_TSXA_st_get_all_mover_id_req_struct    TSXA_st_get_all_mover_id_in_arg;
    TSXI_TSXA_st_get_all_mover_id_32_req_struct    TSXA_st_get_all_mover_id_32_in_arg;
    TSXI_TSXA_st_get_occupy_req_struct    TSXA_st_get_occupy_in_arg;
    TSXI_TSXA_st_set_allow_entering_req_struct    TSXA_st_set_allow_entering_in_arg;
    TSXI_TSXA_get_sys_state_req_struct    TSXA_get_sys_state_in_arg;
    TSXI_TSXA_st_get_pos_req_struct    TSXA_st_get_pos_in_arg;
    TSXI_TSXA_st_limit_req_struct    TSXA_st_limit_in_arg;
    TSXI_TSXA_mv_ison_req_struct    TSXA_mv_ison_in_arg;
    TSXI_TSXA_st_set_station_pv_req_struct    TSXA_st_set_station_pv_in_arg;
    TSXI_TSXA_st_act_limit_req_struct    TSXA_st_act_limit_in_arg;
    TSXI_TSXA_st_dianjiao_set_req_struct    TSXA_st_dianjiao_set_in_arg;
    TSXI_TSXA_st_zhuzhuang_set_req_struct    TSXA_st_zhuzhuang_set_in_arg;
	TSXI_TSXA_axis_limit_move_abs_2_req_struct  TSXA_axis_limit_move_abs_2_in_arg;
	TSXI_TSXA_st_set_station_limit_req_struct TSXA_st_set_station_limit_in_arg;

    TSXI_TSXA_get_mover_num_in_pos_req_struct TSXA_get_mover_num_in_pos_in_arg;
    TSXI_TSXA_emd_glue_check_st_movefront_req_struct TSXA_emd_glue_check_st_movefront_in_arg;

    TSXI_TSXA_st_get_status_req_struct TSXA_st_get_status_in_arg;

    
} TSXI_REQ_PAR_struct;


/* ???????????? */
typedef union
{
    TSXI_MIO_read_reg_rpl_struct    MIO_read_reg_out_arg;
    TSXI_MIO_write_reg_rpl_struct    MIO_write_reg_out_arg;
    TSXI_MIO_read_reg_longs_rpl_struct    MIO_read_reg_longs_out_arg;
    TSXI_MIO_write_reg_longs_rpl_struct    MIO_write_reg_longs_out_arg;
    TSXI_TSXA_sys_control_set_bit_rpl_struct    TSXA_sys_control_set_bit_out_arg;
    TSXI_TSXA_sys_control_clr_rpl_struct    TSXA_sys_control_clr_out_arg;
    TSXI_TSXA_mover_control_set_bit_rpl_struct    TSXA_mover_control_set_bit_out_arg;
    TSXI_TSXA_mover_control_clr_rpl_struct    TSXA_mover_control_clr_out_arg;
    TSXI_TSXA_sys_initialize_rpl_struct    TSXA_sys_initialize_out_arg;
    TSXI_TSXA_sys_terminate_rpl_struct    TSXA_sys_terminate_out_arg;
    TSXI_TSXA_sys_start_work_rpl_struct    TSXA_sys_start_work_out_arg;
    TSXI_TSXA_sys_stop_work_rpl_struct    TSXA_sys_stop_work_out_arg;
    TSXI_TSXA_sys_pause_work_rpl_struct    TSXA_sys_pause_work_out_arg;
    TSXI_TSXA_sys_resume_work_rpl_struct    TSXA_sys_resume_work_out_arg;
    TSXI_TSXA_sys_stop_rpl_struct    TSXA_sys_stop_out_arg;
    TSXI_TSXA_sys_quick_stop_rpl_struct    TSXA_sys_quick_stop_out_arg;
    TSXI_TSXA_sys_reset_err_rpl_struct    TSXA_sys_reset_err_out_arg;
    TSXI_TSXA_sys_auto_pos_err_reset_on_rpl_struct    TSXA_sys_auto_pos_err_reset_on_out_arg;
    TSXI_TSXA_sys_auto_pos_err_reset_off_rpl_struct    TSXA_sys_auto_pos_err_reset_off_out_arg;
    TSXI_TSXA_sys_move_to_next_station_all_rpl_struct    TSXA_sys_move_to_next_station_all_out_arg;
    TSXI_TSXA_sys_enable_axis_all_rpl_struct    TSXA_sys_enable_axis_all_out_arg;
    TSXI_TSXA_sys_disable_axis_all_rpl_struct    TSXA_sys_disable_axis_all_out_arg;
    TSXI_TSXA_sys_load_default_mc_rpl_struct    TSXA_sys_load_default_mc_out_arg;
    TSXI_TSXA_sys_save_mc_to_flash_rpl_struct    TSXA_sys_save_mc_to_flash_out_arg;
    TSXI_TSXA_sys_set_mover_offset_rpl_struct    TSXA_sys_set_mover_offset_out_arg;
    TSXI_TSXA_sys_get_mover_offset_rpl_struct    TSXA_sys_get_mover_offset_out_arg;
    TSXI_TSXA_sys_get_status_rpl_struct    TSXA_sys_get_status_out_arg;
    TSXI_TSXA_sys_get_mover_num_rpl_struct    TSXA_sys_get_mover_num_out_arg;
    TSXI_TSXA_st_set_station_para_rpl_struct    TSXA_st_set_station_para_out_arg;
    TSXI_TSXA_st_move_next_station_rpl_struct    TSXA_st_move_next_station_out_arg;
    TSXI_TSXA_st_move_next_station_multi_rpl_struct    TSXA_st_move_next_station_multi_out_arg;
    TSXI_TSXA_st_qstop_rpl_struct    TSXA_st_qstop_out_arg;
    TSXI_TSXA_st_qstop_resume_rpl_struct    TSXA_st_qstop_resume_out_arg;
    TSXI_TSXA_st_enable_rpl_struct    TSXA_st_enable_out_arg;
    TSXI_TSXA_st_disable_rpl_struct    TSXA_st_disable_out_arg;
    TSXI_TSXA_st_get_mover_id_rpl_struct    TSXA_st_get_mover_id_out_arg;
    TSXI_TSXA_axis_enable_rpl_struct    TSXA_axis_enable_out_arg;
    TSXI_TSXA_axis_disable_rpl_struct    TSXA_axis_disable_out_arg;
    TSXI_TSXA_axis_move_abs_rpl_struct    TSXA_axis_move_abs_out_arg;
    TSXI_TSXA_axis_limit_move_abs_rpl_struct    TSXA_axis_limit_move_abs_out_arg;
    TSXI_TSXA_axis_move_rel_rpl_struct    TSXA_axis_move_rel_out_arg;
    TSXI_TSXA_axis_quick_stop_rpl_struct    TSXA_axis_quick_stop_out_arg;
    TSXI_TSXA_axis_stop_rpl_struct    TSXA_axis_stop_out_arg;
    TSXI_TSXA_axis_reset_rpl_struct    TSXA_axis_reset_out_arg;
    TSXI_TSXA_axis_move_vel_rpl_struct    TSXA_axis_move_vel_out_arg;
    TSXI_TSXA_axis_change_vel_rpl_struct    TSXA_axis_change_vel_out_arg;
    TSXI_TSXA_axis_move_abs_g_rpl_struct    TSXA_axis_move_abs_g_out_arg;
    TSXI_TSXA_axis_move_rel_g_rpl_struct    TSXA_axis_move_rel_g_out_arg;
    TSXI_TSXA_axis_move_rel_all_rpl_struct    TSXA_axis_move_rel_all_out_arg;
    TSXI_TSXA_axis_get_status_rpl_struct    TSXA_axis_get_status_out_arg;
    TSXI_TSXA_axis_get_status_g_rpl_struct    TSXA_axis_get_status_g_out_arg;
    TSXI_TSXA_axis_wait_move_end_rpl_struct    TSXA_axis_wait_move_end_out_arg;
    TSXI_TSXA_axis_wait_move_end_g_rpl_struct    TSXA_axis_wait_move_end_g_out_arg;
    TSXI_TSXA_get_mover_pos_rpl_struct    TSXA_get_mover_pos_out_arg;
    TSXI_TSXA_get_mover_pos_group_rpl_struct    TSXA_get_mover_pos_group_out_arg;
    TSXI_TSXA_set_motion_parameter_rpl_struct    TSXA_set_motion_parameter_out_arg;
    TSXI_TSXA_get_motion_parameter_rpl_struct    TSXA_get_motion_parameter_out_arg;
    TSXI_TSXA_set_global_motion_parameter_rpl_struct    TSXA_set_global_motion_parameter_out_arg;
    TSXI_TSXA_get_global_motion_parameter_rpl_struct    TSXA_get_global_motion_parameter_out_arg;
    TSXI_TSXA_axis_disable_all_rpl_struct    TSXA_axis_disable_all_out_arg;
    TSXI_TSXA_axis_enable_all_rpl_struct    TSXA_axis_enable_all_out_arg;
    TSXI_TSXA_st_get_all_mover_id_rpl_struct    TSXA_st_get_all_mover_id_out_arg;
    TSXI_TSXA_st_get_all_mover_id_32_rpl_struct    TSXA_st_get_all_mover_id_32_out_arg;
    TSXI_TSXA_st_get_occupy_rpl_struct    TSXA_st_get_occupy_out_arg;
    TSXI_TSXA_st_set_allow_entering_rpl_struct    TSXA_st_set_allow_entering_out_arg;
    TSXI_TSXA_get_sys_state_rpl_struct    TSXA_get_sys_state_out_arg;
    TSXI_TSXA_st_get_pos_rpl_struct    TSXA_st_get_pos_out_arg;
    TSXI_TSXA_st_limit_rpl_struct    TSXA_st_limit_out_arg;
    TSXI_TSXA_mv_ison_rpl_struct    TSXA_mv_ison_out_arg;
    TSXI_TSXA_st_set_station_pv_rpl_struct    TSXA_st_set_station_pv_out_arg;
    TSXI_TSXA_st_act_limit_rpl_struct    TSXA_st_act_limit_out_arg;
    TSXI_TSXA_st_dianjiao_set_rpl_struct    TSXA_st_dianjiao_set_out_arg;   
    TSXI_TSXA_st_zhuzhuang_set_rpl_struct    TSXA_st_zhuzhuang_set_out_arg;   
	TSXI_TSXA_axis_limit_move_abs_2_rpl_struct TSXA_axis_limit_move_abs_2_out_arg;
	TSXI_TSXA_st_set_station_limit_rpl_struct TSXA_st_set_station_limit_out_arg;

    TSXI_TSXA_get_mover_num_in_pos_rpl_struct TSXA_get_mover_num_in_pos_out_arg;
    TSXI_TSXA_emd_glue_check_st_movefront_rpl_struct TSXA_emd_glue_check_st_movefront_out_arg;

    TSXI_TSXA_st_get_status_rpl_struct  TSXA_st_get_status_out_arg;

} TSXI_RPL_PAR_struct;



typedef enum
{
    TSMA_EXIT_func_code = -1, /* ????????????*/
    MIO_read_reg_func_code,
    MIO_write_reg_func_code,
    MIO_read_reg_longs_func_code,
    MIO_write_reg_longs_func_code,
    TSXA_sys_control_set_bit_func_code,
    TSXA_sys_control_clr_func_code,
    TSXA_mover_control_set_bit_func_code,
    TSXA_mover_control_clr_func_code,
    TSXA_sys_initialize_func_code,
    TSXA_sys_terminate_func_code,
    TSXA_sys_start_work_func_code,
    TSXA_sys_stop_work_func_code,
    TSXA_sys_pause_work_func_code,
    TSXA_sys_resume_work_func_code,
    TSXA_sys_stop_func_code,
    TSXA_sys_quick_stop_func_code,
    TSXA_sys_reset_err_func_code,
    TSXA_sys_auto_pos_err_reset_on_func_code,
    TSXA_sys_auto_pos_err_reset_off_func_code,
    TSXA_sys_move_to_next_station_all_func_code,
    TSXA_sys_enable_axis_all_func_code,
    TSXA_sys_disable_axis_all_func_code,
    TSXA_sys_load_default_mc_func_code,
    TSXA_sys_save_mc_to_flash_func_code,
    TSXA_sys_set_mover_offset_func_code,
    TSXA_sys_get_mover_offset_func_code,
    TSXA_sys_get_status_func_code,
    TSXA_sys_get_mover_num_func_code,
    TSXA_st_set_station_para_func_code,
    TSXA_st_move_next_station_func_code,
    TSXA_st_move_next_station_multi_func_code,
    TSXA_st_qstop_func_code,
    TSXA_st_qstop_resume_func_code,
    TSXA_st_enable_func_code,
    TSXA_st_disable_func_code,
    TSXA_st_get_mover_id_func_code,
    TSXA_axis_enable_func_code,
    TSXA_axis_disable_func_code,
    TSXA_axis_move_abs_func_code,
    TSXA_axis_limit_move_abs_func_code,
    TSXA_axis_move_rel_func_code,
    TSXA_axis_quick_stop_func_code,
    TSXA_axis_stop_func_code,
    TSXA_axis_reset_func_code,
    TSXA_axis_move_vel_func_code,
    TSXA_axis_change_vel_func_code,
    TSXA_axis_move_abs_g_func_code,
    TSXA_axis_move_rel_g_func_code,
    TSXA_axis_move_rel_all_func_code,
    TSXA_axis_get_status_func_code,
    TSXA_axis_get_status_g_func_code,
    TSXA_axis_wait_move_end_func_code,
    TSXA_axis_wait_move_end_g_func_code,
    TSXA_get_mover_pos_func_code,
    TSXA_get_mover_pos_group_func_code,
    TSXA_set_motion_parameter_func_code,
    TSXA_get_motion_parameter_func_code,
    TSXA_set_global_motion_parameter_func_code,
    TSXA_get_global_motion_parameter_func_code,
    TSXA_axis_disable_all_func_code,
    TSXA_axis_enable_all_func_code,
    TSXA_st_get_all_mover_id_func_code,
    TSXA_st_get_all_mover_id_32_func_code,
    TSXA_st_get_occupy_func_code,
    TSXA_st_set_allow_entering_func_code,
    TSXA_get_sys_state_func_code,
    TSXA_st_get_pos_func_code,
    TSXA_st_limit_func_code,
    TSXA_mv_ison_func_code,
    TSXA_st_set_station_pv_func_code,
    TSXA_st_act_limit_func_code,
    TSXA_st_dianjiao_set_func_code,
    TSXA_st_zhuzhuang_set_func_code,
    TSXA_axis_limit_move_abs_2_func_code,
    TSXA_st_set_station_limit_func_code,
    TSXA_get_mover_num_in_pos_func_code,
    TSXA_emd_glue_check_st_movefront_func_code,

    TSXA_st_get_status_func_code,
    
    TSXA_MAX_FUNC_NUM_func_code
} TSXI_FUNC_enum;




/* DN?????????? */
typedef struct
{
    TSXI_FUNC_enum      func_code;
    BOOL                 reply_wanted;
    int                 nc;
    int                 reply_addr;     // modify by frank
    TSXI_REQ_PAR_struct  req_par;
} TSXI_REQ_MSG_struct;

/* DN?????????? */
typedef struct
{
    TSXI_FUNC_enum      func_code;
    int                 error_code;
    TSXI_RPL_PAR_struct  rpl_par;
} TSXI_RPL_MSG_struct;


#ifdef __cplusplus
}
#endif

#endif

