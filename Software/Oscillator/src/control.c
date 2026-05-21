/*
 * control.c
 *
 * Created: 13/02/2026 11:47:32
 *  Author: bb155134
 */ 

#include <inttypes.h>
#include "control.h"

void oc_set_target(oc_oscillator_t *oc, uint16_t target) {
    oc->state.f_target = target;
}

uint16_t clamp_for_digi(uint16_t val) {
    if (val > 0x3E6) return 0x3E6;
    return val;
}

uint16_t oc_model_lookup(const oc_band_model_t *model, uint16_t f_target) {
    const oc_lut_entry_t *lut = model->lut;

    for (uint8_t i = 0; i < model->lut_size - 1; i++) {
        if (f_target <= lut[i + 1].freq) {
            int32_t df = lut[i + 1].freq - lut[i].freq;
            int32_t dp = lut[i + 1].res - lut[i].res;
            int32_t dx = f_target - lut[i].freq;

            return lut[i].res + (dx * dp) / df;
        }
    }

    return lut[model->lut_size - 1].res;
}

oc_cap_mode_t oc_select_cap(const oc_oscillator_t *oc) {
    uint16_t f = oc->state.f_target;
    if (f >= oc->high_band->f_min) {
        return OC_CAP_HIGH;
    }
    return OC_CAP_LOW;
}

void oc_control_step(oc_oscillator_t *oc) {
    oc->state.f_meas = oc->get_freq();

    oc_cap_mode_t new_cap = oc_select_cap(oc);

    if (new_cap != oc->state.cap_mode) {

        const oc_band_model_t *band = (new_cap == OC_CAP_LOW) ? oc->low_band : oc->high_band;

        oc->state.D_cmd = clamp_for_digi(oc_model_lookup(band, oc->state.f_target));

        oc->set_freq_res(oc->state.D_cmd);
        oc->state.e_accum = 0;
        oc->state.cap_mode = new_cap;
        oc->set_cap(new_cap);
        return;
    }


    // int32_t error = (int32_t)oc->state.f_target - (int32_t)oc->state.f_meas;

    // if (error > (int32_t)-OC_DEADBAND_HZ && error < (int32_t)OC_DEADBAND_HZ) return;

    // oc->state.e_accum += error;

    // int32_t delta = (error / 2) + (oc->pid.Ki * oc->state.e_accum);

    // if ((int32_t)oc->state.D_cmd + delta < 0) return;
    // oc->state.D_cmd = clamp_for_digi(oc->state.D_cmd + delta);


    const oc_band_model_t *band = (oc->state.cap_mode == OC_CAP_LOW) ? oc->low_band : oc->high_band;
    uint16_t error = (oc->state.f_meas < oc->state.f_target) ? (oc->state.f_target - oc->state.f_meas) : (oc->state.f_meas - oc->state.f_target);
    // if (error > oc->state.f_target >> 3) {
    //     oc->state.D_cmd = clamp_for_digi(oc_model_lookup(band, oc->state.f_target));
    // } else if ((error >> 3) > 5) {
    //     oc->state.D_cmd = (oc->state.f_meas < oc->state.f_target) ? (oc->state.D_cmd + (error >> 3)) : (oc->state.D_cmd - (error >> 3));
    // } else if (error > 1) {
    //     oc->state.D_cmd = (oc->state.f_meas < oc->state.f_target) ? (oc->state.D_cmd + 1) : (oc->state.D_cmd - 1);
    // }

    if (error > 500) {
        oc->state.D_cmd = clamp_for_digi(oc_model_lookup(band, oc->state.f_target));
        oc->set_freq_res(oc->state.D_cmd);
        return;
    }
    
    oc->state.D_cmd = clamp_for_digi((oc->state.f_meas < oc->state.f_target) ? (oc->state.D_cmd + (error >> 1)) : (oc->state.D_cmd - (error >> 1)));
    oc->set_freq_res(oc->state.D_cmd);

    if (oc->type == OC_SIN) {
        oc->set_gain_res(220);
    }
}