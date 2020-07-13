# Get rid of '_xxAA' and other designators.
string(REPLACE "_" ";" PLATFORM_TMP ${PLATFORM})
list(GET PLATFORM_TMP 0 PLATFORM_SHORT)

add_library(nrfx nrfx/drivers/src/nrfx_clock.c)
target_include_directories(nrfx PUBLIC .
                                       nrfx/
                                       nrfx/hal/
                                       nrfx/mdk/
                                       nrfx/drivers/
                                       nrfx/drivers/include/
                                       nrfx/soc/)
target_link_libraries(nrfx cmsis)

add_library(app_startup nrfx/mdk/system_${PLATFORM_SHORT}.c
                        nrfx/mdk/gcc_startup_${PLATFORM_SHORT}.S)
target_link_libraries(app_startup nrfx)