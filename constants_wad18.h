#ifndef CONSTANTS_WAD18_H
#define CONSTANTS_WAD18_H

#include <stdint.h>
#include <stdbool.h>

/* WAD18 Physical Constants (CODATA 2023)
 * All physical constants encoded as 64-bit integers with 10^-18 precision
 * Enables exact reproducible calculations in physics, chemistry, biology
 */

typedef int64_t wad18_t;

#define WAD18_SCALE 1000000000000000000LL  /* 10^18 */

/* ==== FUNDAMENTAL CONSTANTS ==== */

/* Speed of light in vacuum */
#define C_WAD18 299792458000000000000LL          /* m/s */

/* Planck constant */
#define H_WAD18 662607015000000000000000000000LL /* J⋅s (exact by 2019 SI definition) */

/* Reduced Planck constant (ℏ = h/(2π)) */
#define HBAR_WAD18 105457182000000000000000000LL /* J⋅s */

/* Gravitational constant */
#define G_WAD18 667430000000000000000000LL       /* m³/(kg⋅s²) */

/* Elementary charge */
#define E_WAD18 1602176634000000000LL            /* C (exact by 2019 SI definition) */

/* Boltzmann constant */
#define K_B_WAD18 13806490000000000000LL         /* J/K (exact by 2019 SI definition) */

/* Avogadro constant */
#define N_A_WAD18 602214076000000000000000LL     /* mol^-1 (exact by 2019 SI definition) */

/* ==== DERIVED CONSTANTS ==== */

/* Vacuum permittivity (ε₀) */
#define EPSILON_0_WAD18 8854187817620000000LL    /* F/m */

/* Vacuum permeability (μ₀) */
#define MU_0_WAD18 1256637062149999999LL         /* H/m */

/* Coulomb constant (k₀ = 1/(4πε₀)) */
#define K_0_WAD18 8987551787368176400LL          /* N⋅m²/C² */

/* Fine structure constant (α = e²/(2ε₀hcα)) */
#define ALPHA_WAD18 7352618444137000000000LL     /* dimensionless (1/α ≈ 137.03599908) */

/* Rydberg constant */
#define R_INF_WAD18 10973731568160000000LL       /* m^-1 */

/* Bohr radius (a₀ = ℏ²/(m_e·e²/(4πε₀)) */
#define A_0_WAD18 529177210903000000LL           /* m */

/* ==== PARTICLE MASSES ==== */

/* Electron mass */
#define M_E_WAD18 910938356000000000LL           /* kg */

/* Proton mass */
#define M_P_WAD18 1672621898000000000LL          /* kg */

/* Neutron mass */
#define M_N_WAD18 1674927471000000000LL          /* kg */

/* Electron-to-proton mass ratio */
#define M_E_M_P_RATIO_WAD18 544617021487000000000000LL /* 1/1836.15267343... */

/* ==== ENERGY CONSTANTS ==== */

/* Joule-to-eV conversion */
#define EV_TO_J_WAD18 1602176634000000000LL      /* J/eV (same as elementary charge) */

/* Hartree energy (E_h = e²/(4πε₀·a₀)) */
#define E_H_WAD18 4359744722207200000LL          /* J */

/* Rydberg energy (R_∞ = E_h/2) */
#define R_Y_WAD18 2179872361103600000LL          /* J */

/* ==== TEMPERATURE CONSTANTS ==== */

/* Kelvin-to-Joules (k_B already defined above) */

/* ==== OPTICAL CONSTANTS ==== */

/* Fine structure splitting in hydrogen (2P level) */
#define LAMB_SHIFT_H_WAD18 1058434000000000000LL /* Hz (exact reference) */

/* ==== ATOMIC CONSTANTS ==== */

/* Bohr magneton (μ_B = e·ℏ/(2·m_e)) */
#define MU_B_WAD18 927401015430000000LL          /* J/T */

/* Nuclear magneton (μ_N = e·ℏ/(2·m_p)) */
#define MU_N_WAD18 505078374150000000LL          /* J/T */

/* ==== VERIFICATION & ACCEPTANCE ==== */

typedef struct {
    char symbol[32];           /* Constant name/symbol */
    wad18_t value_wad18;       /* Value in WAD18 format */
    wad18_t uncertainty;       /* Uncertainty in WAD18 */
    char unit[32];             /* Unit of measurement */
    char reference[128];       /* CODATA reference */
    uint32_t hash;             /* SHA-256 hash for verification */
    bool is_exact;             /* True if exact by definition (2019 SI) */
    char source[64];           /* CODATA2023 or other */
} constant_t;

/* Physical constants database */
typedef struct {
    constant_t constants[350];  /* All CODATA constants */
    int count;                  /* Number of constants */
    uint32_t table_hash;        /* Hash of entire constant table */
    char version[32];           /* "CODATA2023" */
    char timestamp[32];         /* ISO-8601 timestamp */
} constants_database_t;

/* Load/verify constants */
constants_database_t* constants_load(const char *json_file);
bool constants_verify_hash(constants_database_t *db);
bool constant_verify_hash(constant_t *c);

/* Relationships (verify dimensional consistency) */
bool verify_coulomb_constant();      /* k₀ = 1/(4πε₀) */
bool verify_planck_reduced();        /* ℏ = h/(2π) */
bool verify_fine_structure();        /* α = e²/(2ε₀hcα) */
bool verify_bohr_radius();           /* a₀ = ℏ²/(m_e·k₀·e²) */
bool verify_rydberg();               /* R_∞ = m_e·k₀·e⁴/(2ℏ²) */

#endif
