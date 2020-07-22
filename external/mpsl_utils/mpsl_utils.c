#include "mpsl_utils.h"

#include <assert.h>
#include "mpsl.h"
#include "mpsl_clock.h"

#define MPSL_LOW_PRIO_IRQp (4)

static void mpsl_assert_handler(const char * const file, const uint32_t line)
{
    assert(false);
}

void mpsl_event_handler(uint32_t evt_id)
{
    assert(false);
}

void mpsl_utils_init(void)
{
#if ENABLE_LFRC
    mpsl_clock_lfclk_cfg_t clock_config =
    {
        .source        = MPSL_CLOCK_LF_SRC_RC,
        .rc_ctiv       = 16,
        .rc_temp_ctiv  = 2,
    };
#else
    mpsl_clock_lfclk_cfg_t clock_config =
    {
        .source        = MPSL_CLOCK_LF_SRC_XTAL,
        .rc_ctiv       = 0,
        .rc_temp_ctiv  = 0
    };
#endif

    NVIC_SetPriority(SWI5_IRQn, MPSL_LOW_PRIO_IRQp);
    NVIC_EnableIRQ(SWI5_IRQn);

    mpsl_init(&clock_config, SWI5_IRQn, mpsl_assert_handler);

    NVIC_SetPriority(POWER_CLOCK_IRQn, MPSL_LOW_PRIO_IRQp);
    NVIC_EnableIRQ(POWER_CLOCK_IRQn);
}

void mpsl_utils_uninit(void)
{
    mpsl_uninit();

    NVIC_DisableIRQ(POWER_CLOCK_IRQn);
}

void RTC0_IRQHandler(void)
{
    MPSL_IRQ_RTC0_Handler();
}

void TIMER0_IRQHandler(void)
{
    MPSL_IRQ_TIMER0_Handler();
}

void SWI5_IRQHandler(void)
{
    mpsl_low_priority_process();
}

void RADIO_IRQHandler(void)
{
    MPSL_IRQ_RADIO_Handler();
}

void POWER_CLOCK_IRQHandler(void)
{
    MPSL_IRQ_CLOCK_Handler();
}
