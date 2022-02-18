if(NOT DRIVER_FLEXCOMM_I2S_INCLUDED)

    set(DRIVER_FLEXCOMM_I2S_INCLUDED true CACHE BOOL "driver_flexcomm_i2s component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_i2s.c
    )

    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )

    #OR Logic component
    if(${MCUX_DEVICE} STREQUAL "LPC54114_cm4")
        include(driver_flexcomm)
    endif()
    if(${MCUX_DEVICE} STREQUAL "LPC54628")
        include(driver_flexcomm)
    endif()
    if(${MCUX_DEVICE} STREQUAL "LPC55S16")
        include(driver_flexcomm)
    endif()
    if(${MCUX_DEVICE} STREQUAL "LPC54S018")
        include(driver_flexcomm)
    endif()
    if(${MCUX_DEVICE} STREQUAL "LPC54S018M")
        include(driver_flexcomm)
    endif()
    if(${MCUX_DEVICE} STREQUAL "LPC51U68")
        include(driver_flexcomm)
    endif()
    if(${MCUX_DEVICE} STREQUAL "LPC55S69_cm33_core0")
        include(driver_flexcomm)
    endif()
    if(${MCUX_DEVICE} STREQUAL "LPC55S28")
        include(driver_flexcomm)
    endif()
    if(${MCUX_DEVICE} STREQUAL "MIMXRT685S_cm33")
        include(driver_flexcomm)
    endif()

    include(driver_common)

endif()