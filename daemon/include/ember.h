// it is a header file. It will contain all libraries we are gonna use in this project.

#ifndef EMBER_H
#define EMBER_H

#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>

#define EMBER_MAX_PATH     4096
#define EMBER_MAX_JSON     8192
#define EMBER_MAX_PROCS    512

typedef struct {
    pid_t   pid;
    pid_t   ppid;
    char    name[256];
    char    exe[EMBER_MAX_PATH];
    char    cwd[EMBER_MAX_PATH];
    char    cmdline_json[EMBER_MAX_JSON];    // JSON array
    char    environ_json[EMBER_MAX_JSON];    // JSON object (filtered)
    char    open_files_json[EMBER_MAX_JSON]; // JSON array
    int32_t vm_rss_kb;
    int32_t dirty_pages_kb;
} ProcessRecord;

typedef struct {
    int  pid;
    char title[512];
    float  x, y, width, height;
    int  desktop_num;
    int  focused;
} WindowRecord;

typedef struct {
    int64_t session_id;
    int64_t captured_at;
    int     battery_pct;  // -1 if no battery
    int     on_ac;
    char    hostname[256];
} SessionRecord;

typedef struct {
    int  from_pid;
    int  to_pid;
    char dep_type[16];   // "pipe" | "socket" | "parent"
} DepEdge;

typedef struct {
    // [daemon] section
    int    poll_interval_ac;
    int    poll_interval_battery;
    int    poll_interval_critical;
    int    critical_battery_pct;
    char   ignore_list[64][EMBER_MAX_PATH];
    int    ignore_list_len;

    // [snapshot] section
    char   tmpfs_path[EMBER_MAX_PATH];
    char   db_path[EMBER_MAX_PATH];
    int    fsync_interval;
    int    max_snapshots;
    
    // [criu] section
    bool   criu_enabled;
    char   criu_image_dir[EMBER_MAX_PATH];
    int    criu_retention_days;
    char   criu_checkpoint_list[64][EMBER_MAX_PATH];
    int    criu_checkpoint_list_len;
    int    criu_active_window_secs;
    int    criu_dirty_threshold_kb;
} Config;

#endif