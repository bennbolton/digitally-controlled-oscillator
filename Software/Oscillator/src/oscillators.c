
#ifndef OSCILLATORS_C
#define OSCILLATORS_C

#include "oscillators.h"
#include "control.h"

/* Lookup tables*/
// D_CMD : FREQ

static const oc_lut_entry_t tri_low_lut[] = {
    { 0,     23 },
    { 100,   26 },
    { 200,   29 },
    { 300,   33 },
    { 400,   38 },
    { 500,   44 },
    { 600,   54 },
    { 700,   69 },
    { 800,   95 },
    { 900,   151},
    { 998,   362},
};

static const oc_lut_entry_t tri_high_lut[] = {
    { 0,     263  },
    { 100,   290  },
    { 200,   323  },
    { 300,   365  },
    { 400,   419  },
    { 500,   492  },
    { 600,   597  },
    { 700,   757  },
    { 800,   1036 },
    { 900,   1641 },
    { 1000,  3827 },
};

static const oc_lut_entry_t sin_low_lut[] = {
    { 0,     14  },
    { 100,   15  },
    { 200,   17  },
    { 300,   20  },
    { 400,   23  },
    { 500,   27  },
    { 600,   33  },
    { 700,   44  },
    { 800,   62  },
    { 900,   108  },
    { 1000,  386 },
};

static const oc_lut_entry_t sin_high_lut[] = {
    { 0,     155  },
    { 100,   171  },
    { 200,   192  },
    { 300,   218  },
    { 400,   252  },
    { 500,   299  },
    { 600,   369  },
    { 700,   478  },
    { 800,   682  },
    { 900,   1185 },
    { 1000,  4301 },
};

/* Band models */

const oc_band_model_t tri_low_band = {
    .lut = tri_low_lut,
    .lut_size = sizeof(tri_low_lut)/sizeof(tri_low_lut[0]),
    .f_min = 25,
    .f_max = 250
};

const oc_band_model_t tri_high_band = {
    .lut = tri_high_lut,
    .lut_size = sizeof(tri_high_lut)/sizeof(tri_high_lut[0]),
    .f_min = 250,
    .f_max = 2800
};

const oc_band_model_t sin_low_band = {
    .lut = sin_low_lut,
    .lut_size = sizeof(sin_low_lut)/sizeof(sin_low_lut[0]),
    .f_min = 15,
    .f_max = 210
};

const oc_band_model_t sin_high_band = {
    .lut = sin_high_lut,
    .lut_size = sizeof(sin_high_lut)/sizeof(sin_high_lut[0]),
    .f_min = 160,
    .f_max = 2050
};




#endif /* OSCILLATORS_C */