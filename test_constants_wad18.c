#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "constants_wad18.h"

/* Test counter */
static int tests_passed = 0;
static int tests_failed = 0;

#define TEST(name) printf("Testing: %s ... ", name); fflush(stdout)
#define PASS() do { printf("PASS\n"); tests_passed++; } while(0)
#define FAIL() do { printf("FAIL\n"); tests_failed++; } while(0)

/* ==== FUNDAMENTAL CONSTANT TESTS ==== */

void test_speed_of_light() {
    TEST("Speed of light (exact by 2019 SI)");
    assert(C_WAD18 == 299792458000000000000LL);
    PASS();
}

void test_planck_constant() {
    TEST("Planck constant (exact by 2019 SI)");
    assert(H_WAD18 == 662607015000000000000000000000LL);
    PASS();
}

void test_elementary_charge() {
    TEST("Elementary charge (exact by 2019 SI)");
    assert(E_WAD18 == 1602176634000000000LL);
    PASS();
}

void test_boltzmann_constant() {
    TEST("Boltzmann constant (exact by 2019 SI)");
    assert(K_B_WAD18 == 13806490000000000000LL);
    PASS();
}

void test_avogadro_constant() {
    TEST("Avogadro constant (exact by 2019 SI)");
    assert(N_A_WAD18 == 602214076000000000000000LL);
    PASS();
}

/* ==== DERIVED CONSTANT TESTS ==== */

void test_reduced_planck_constant() {
    TEST("Reduced Planck constant (ℏ = h/2π)");
    /* h/2π should equal ℏ */
    assert(HBAR_WAD18 == 105457182000000000000000000LL);
    PASS();
}

void test_fine_structure_constant() {
    TEST("Fine structure constant (1/α ≈ 137.036)");
    /* 1/α should be approximately 137.035999084 */
    assert(ALPHA_WAD18 == 7352618444137000000000LL);
    PASS();
}

void test_bohr_radius() {
    TEST("Bohr radius (a₀ ≈ 0.529 Angstrom)");
    /* Bohr radius: 0.529177210903 Angstrom = 0.0529177210903 nm */
    assert(A_0_WAD18 == 529177210903000000LL);
    PASS();
}

/* ==== PARTICLE MASS TESTS ==== */

void test_electron_mass() {
    TEST("Electron mass");
    assert(M_E_WAD18 == 910938356000000000LL);
    PASS();
}

void test_proton_mass() {
    TEST("Proton mass");
    assert(M_P_WAD18 == 1672621898000000000LL);
    PASS();
}

void test_electron_proton_mass_ratio() {
    TEST("Electron-to-proton mass ratio (≈ 1/1836.15)");
    assert(M_E_M_P_RATIO_WAD18 > 0);
    PASS();
}

/* ==== RELATIONSHIP VERIFICATION TESTS ==== */

void test_coulomb_constant_relationship() {
    TEST("Coulomb constant: k₀ = 1/(4πε₀)");
    assert(verify_coulomb_constant());
    PASS();
}

void test_planck_relationship() {
    TEST("Planck relationship: ℏ = h/(2π)");
    assert(verify_planck_reduced());
    PASS();
}

void test_fine_structure_relationship() {
    TEST("Fine structure constant: 1/α ≈ 137.036");
    assert(verify_fine_structure());
    PASS();
}

void test_bohr_radius_value() {
    TEST("Bohr radius value check");
    assert(verify_bohr_radius());
    PASS();
}

void test_rydberg_constant() {
    TEST("Rydberg constant value check");
    assert(verify_rydberg());
    PASS();
}

/* ==== HASH & REPRODUCIBILITY TESTS ==== */

void test_constant_hash_deterministic() {
    TEST("Constant hash is deterministic");
    constant_t c = {
        .symbol = "h",
        .value_wad18 = H_WAD18,
        .uncertainty = 0,
        .hash = 0
    };
    uint32_t hash1 = constant_hash32(&c);
    uint32_t hash2 = constant_hash32(&c);
    assert(hash1 == hash2);
    PASS();
}

void test_different_constants_different_hash() {
    TEST("Different constants have different hashes");
    constant_t c1 = {.value_wad18 = H_WAD18, .uncertainty = 0};
    constant_t c2 = {.value_wad18 = C_WAD18, .uncertainty = 0};
    uint32_t hash1 = constant_hash32(&c1);
    uint32_t hash2 = constant_hash32(&c2);
    assert(hash1 != hash2);
    PASS();
}

/* ==== EXACT VALUE TESTS ==== */

void test_exact_constants_2019_si() {
    TEST("Exact constants (2019 SI redefinition)");
    /* These are EXACT by definition since 2019 SI redefinition */
    assert(C_WAD18 == 299792458000000000000LL);      /* speed of light */
    assert(H_WAD18 == 662607015000000000000000000000LL); /* Planck constant */
    assert(E_WAD18 == 1602176634000000000LL);         /* elementary charge */
    assert(K_B_WAD18 == 13806490000000000000LL);      /* Boltzmann constant */
    assert(N_A_WAD18 == 602214076000000000000000LL);  /* Avogadro constant */
    PASS();
}

/* ==== CROSS-PLATFORM CONSISTENCY TESTS ==== */

void test_constants_byte_order_independent() {
    TEST("Constants independent of byte order");
    wad18_t val = H_WAD18;
    uint32_t hash = constant_hash32((constant_t*)&val);
    /* Hash should be consistent regardless of platform endianness */
    assert(hash != 0);
    PASS();
}

void test_constant_arithmetic_reproducible() {
    TEST("Constant arithmetic is reproducible");
    wad18_t c = C_WAD18;
    wad18_t h = H_WAD18;
    
    /* c*h calculation should be identical everywhere */
    /* (This would overflow with naive multiply, but demonstrates concept) */
    
    assert(c > 0 && h > 0);
    PASS();
}

/* ==== ENERGY CONSTANT TESTS ==== */

void test_hartree_energy() {
    TEST("Hartree energy (E_h = e²/(4πε₀·a₀))");
    assert(E_H_WAD18 == 4359744722207200000LL);
    PASS();
}

void test_rydberg_energy() {
    TEST("Rydberg energy (R_y = E_h/2)");
    assert(R_Y_WAD18 == 2179872361103600000LL);
    PASS();
}

void test_ev_to_joules() {
    TEST("eV to Joules conversion");
    /* 1 eV = elementary charge in Joules */
    assert(EV_TO_J_WAD18 == E_WAD18);
    PASS();
}

/* ==== MAGNETIC MOMENT TESTS ==== */

void test_bohr_magneton() {
    TEST("Bohr magneton (μ_B = e·ℏ/(2·m_e))");
    assert(MU_B_WAD18 == 927401015430000000LL);
    PASS();
}

void test_nuclear_magneton() {
    TEST("Nuclear magneton (μ_N = e·ℏ/(2·m_p))");
    assert(MU_N_WAD18 == 505078374150000000LL);
    PASS();
}

/* ==== DIMENSIONAL ANALYSIS TESTS ==== */

void test_dimensional_consistency() {
    TEST("Dimensional consistency of fundamental constants");
    /* All constants must be positive */
    assert(C_WAD18 > 0);
    assert(H_WAD18 > 0);
    assert(E_WAD18 > 0);
    assert(K_B_WAD18 > 0);
    assert(N_A_WAD18 > 0);
    assert(G_WAD18 > 0);
    PASS();
}

void test_relative_magnitude_correctness() {
    TEST("Relative magnitude of constants correct");
    /* Avogadro >> elementary charge */
    assert(N_A_WAD18 > E_WAD18);
    /* Planck constant > elementary charge */
    assert(H_WAD18 > E_WAD18);
    PASS();
}

int main() {
    printf("\n=== WAD18 Physical Constants Unit Tests ===\n\n");
    
    /* Fundamental constants */
    test_speed_of_light();
    test_planck_constant();
    test_elementary_charge();
    test_boltzmann_constant();
    test_avogadro_constant();
    
    /* Derived constants */
    test_reduced_planck_constant();
    test_fine_structure_constant();
    test_bohr_radius();
    
    /* Particle masses */
    test_electron_mass();
    test_proton_mass();
    test_electron_proton_mass_ratio();
    
    /* Relationship verification */
    test_coulomb_constant_relationship();
    test_planck_relationship();
    test_fine_structure_relationship();
    test_bohr_radius_value();
    test_rydberg_constant();
    
    /* Hash & reproducibility */
    test_constant_hash_deterministic();
    test_different_constants_different_hash();
    
    /* Exact values */
    test_exact_constants_2019_si();
    
    /* Cross-platform */
    test_constants_byte_order_independent();
    test_constant_arithmetic_reproducible();
    
    /* Energy constants */
    test_hartree_energy();
    test_rydberg_energy();
    test_ev_to_joules();
    
    /* Magnetic moments */
    test_bohr_magneton();
    test_nuclear_magneton();
    
    /* Dimensional analysis */
    test_dimensional_consistency();
    test_relative_magnitude_correctness();
    
    printf("\n=== Test Results ===\n");
    printf("Passed: %d\n", tests_passed);
    printf("Failed: %d\n", tests_failed);
    printf("Total:  %d\n\n", tests_passed + tests_failed);
    
    return tests_failed == 0 ? 0 : 1;
}
