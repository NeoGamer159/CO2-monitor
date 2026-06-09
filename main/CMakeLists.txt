
idf_component_register(
    SRCS
        "main.c"
        "../machine/mgr/mgr_main.c"
        "../machine/mgr/mgr_task.c"
        "../machine/app/app_msm.c"
        "../machine/app/app_hmi.c"
        "../machine/dev/dev_co2.c"
        "../machine/dev/dev_led.c"
        "../machine/drv/drv_led.c"
    INCLUDE_DIRS
        "."
        "../machine/mgr"
        "../machine/app"
        "../machine/dev"
        "../machine/drv"
)