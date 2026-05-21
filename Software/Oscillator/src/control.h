/*
 * control.h
 *
 * Created: 13/02/2026 11:47:20
 *  Author: bb155134
 */ 


#ifndef CONTROL_H_
#define CONTROL_H_

#include <inttypes.h>
#include "ioPin.h"

#define OC_DEADBAND_HZ 1

typedef struct {
    float Kp;
    float Ki;
    float Kd;
} pid_t;

typedef enum {
    OC_CAP_HIGH = 0,
    OC_CAP_LOW = 1
} oc_cap_mode_t;

typedef struct {
    uint16_t res;
    uint16_t freq;
} oc_lut_entry_t;

typedef struct {
    const oc_lut_entry_t *lut;
    uint8_t lut_size;
    uint16_t f_min;
    uint16_t f_max;
} oc_band_model_t;

typedef enum {
    OC_TRI = 0,
    OC_PWM = 0,
    OC_SIN = 1
} oc_type_t;

typedef struct {
    oc_cap_mode_t cap_mode;
    uint16_t f_target;
    uint16_t f_meas;

    int32_t e_accum;
    uint16_t D_cmd;
    uint8_t settle_count;
} oc_state_t;

typedef struct {
    oc_type_t type;
    oc_state_t state;
    pid_t pid;

    const oc_band_model_t *high_band;
    const oc_band_model_t *low_band;

    uint16_t (*get_freq)(void);
    void (*set_freq_res)(uint16_t);
    void (*set_gain_res)(uint16_t);
    void (*set_cap)(oc_cap_mode_t);
} oc_oscillator_t;



void oc_set_target(oc_oscillator_t *oc, uint16_t target);

void oc_control_step(oc_oscillator_t *oc);



#endif /* CONTROL_H_ */