add_library(radio_driver src/nrf_802154.c
                         src/nrf_802154_core.c
                         src/nrf_802154_core_hooks.c
                         src/nrf_802154_critical_section.c
                         src/nrf_802154_debug.c
                         src/nrf_802154_pib.c
                         src/nrf_802154_queue.c
                         src/nrf_802154_rssi.c
                         src/nrf_802154_rx_buffer.c
                         src/nrf_802154_stats.c
                         src/nrf_802154_trx.c
                         src/fal/nrf_802154_fal.c
                         src/mac_features/nrf_802154_csma_ca.c
                         src/mac_features/nrf_802154_delayed_trx.c
                         src/mac_features/nrf_802154_filter.c
                         src/mac_features/nrf_802154_frame_parser.c
                         src/mac_features/nrf_802154_ifs.c
                         src/mac_features/nrf_802154_precise_ack_timeout.c
                         src/mac_features/ack_generator/nrf_802154_ack_data.c
                         src/mac_features/ack_generator/nrf_802154_ack_generator.c
                         src/mac_features/ack_generator/nrf_802154_enh_ack_generator.c
                         src/mac_features/ack_generator/nrf_802154_imm_ack_generator.c
                         src/platform/random/nrf_802154_random_stdlib.c
                         src/platform/temperature/nrf_802154_temperature_none.c
                         src/nrf_802154_notification_direct.c
                         src/nrf_802154_request_direct.c
                         src/nrf_802154_swi.c)

add_subdirectory(external)
add_subdirectory(lib)

target_link_libraries(radio_driver nrfx)
target_link_libraries(radio_driver nrf_802154_sl)
target_link_libraries(radio_driver nrf_802154_sl_platform)

target_include_directories(radio_driver PUBLIC src)

target_compile_definitions(radio_driver
    PUBLIC 
        -DNRF_802154_INTERNAL_RADIO_IRQ_HANDLING=1
        -DNRF_802154_INTERNAL_SWI_IRQ_HANDLING=1
)
