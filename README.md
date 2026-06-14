# Ember
Restores the system after crash or unexpected shutdown.

# Expected Project Structure

    ember/
    ├── daemon/
    │   ├── src/
    │   │   ├── main.c
    │   │   ├── proc_scraper.c / .h
    │   │   ├── snapshot.c / .h
    │   │   ├── signal_handler.c / .h
    │   │   ├── battery.c / .h
    │   │   ├── checkpoint.c / .h
    │   │   ├── ipc_dag.c / .h
    │   │   └── ipc_client.c / .h
    │   ├── include/ember.h
    │   ├── tests/
    │   └── CMakeLists.txt
    ├── restorer/
    │   ├── main.go
    │   ├── snapshot_reader.go
    │   ├── launcher.go
    │   ├── compositor.go
    │   ├── editor.go
    │   ├── browser.go
    │   ├── dag.go
    │   ├── config.go
    │   ├── api.go
    │   └── go.mod
    ├── dashboard/
    ├── systemd/
    ├── config/ember.toml.example
    ├── scripts/
    └── docs/
