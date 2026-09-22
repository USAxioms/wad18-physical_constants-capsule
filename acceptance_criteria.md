# WAD18 Physical Constants - Acceptance Criteria

**Document Status:** IMMUTABLE (Pre-declared 2026-09-21)  
**Authority:** CODATA 2023, NIST  
**Version:** 1.0.0

---

## 🔐 IMMUTABLE AXIOMS

These criteria were declared BEFORE any calculations or evaluations.

**Modification is not allowed.** This prevents p-hacking and ensures scientific integrity.

---

## 1. FUNDAMENTAL CONSTANTS (Exact by 2019 SI Redefinition)

### Speed of Light (c)
- **Value**: 299,792,458 m/s (exact)
- **Uncertainty**: 0 (by definition)
- **Acceptance**: AUTOMATIC (defined by SI, 2019)
- **Source**: NIST, CODATA
- **Verification**: Comparison with WAD18 value

### Planck Constant (h)
- **Value**: 6.62607015 × 10⁻³⁴ J·s (exact)
- **Uncertainty**: 0 (by definition)
- **Acceptance**: AUTOMATIC (defined by SI, 2019)
- **Source**: NIST, CODATA
- **Verification**: Exact match in WAD18

### Elementary Charge (e)
- **Value**: 1.602176634 × 10⁻¹⁹ C (exact)
- **Uncertainty**: 0 (by definition)
- **Acceptance**: AUTOMATIC (defined by SI, 2019)
- **Source**: NIST, CODATA
- **Verification**: Hash confirmation

### Boltzmann Constant (k_B)
- **Value**: 1.380649 × 10⁻²³ J/K (exact)
- **Uncertainty**: 0 (by definition)
- **Acceptance**: AUTOMATIC (defined by SI, 2019)
- **Source**: NIST, CODATA
- **Verification**: Cross-check with thermodynamic calculations

### Avogadro Constant (N_A)
- **Value**: 6.02214076 × 10²³ mol⁻¹ (exact)
- **Uncertainty**: 0 (by definition)
- **Acceptance**: AUTOMATIC (defined by SI, 2019)
- **Source**: NIST, CODATA
- **Verification**: Mole definition consistency

---

## 2. GRAVITATIONAL CONSTANT (Measured, Refined)

### Gravitational Constant (G)
- **Value**: 6.67430 × 10⁻¹¹ m³/(kg·s²)
- **Uncertainty**: ±1.5 × 10⁻¹² (relative)
- **Source**: CODATA 2023
- **Acceptance Criteria**:
  - ✅ NIST certified value
  - ✅ Positive (non-zero)
  - ✅ Reasonable magnitude (10⁻¹¹ range)
  - ✅ Uncertainty documented
  - ✅ WAD18 representable without loss
- **Update Rules**:
  - IF new CODATA release AND uncertainty ≤ current
  - THEN accept new value
  - RECALCULATE hash and timestamp

---

## 3. DERIVED CONSTANTS (From Fundamental)

### Fine Structure Constant (α)
- **Value**: 7.2973525693... × 10⁻³
- **Inverse**: 1/α = 137.035999084
- **Source**: Calculated from e, c, h, ε₀
- **Acceptance Criteria**:
  - ✅ Calculated from verified fundamentals
  - ✅ 1/α ≈ 137.036 (within tolerance)
  - ✅ Dimensionless (verified)
  - ✅ Matches CODATA consensus
  - ✅ WAD18 bit-exact
- **Verification**:
  - α × 137.036 ≈ 1 (relationship holds)
  - Cross-check against NIST tables

### Reduced Planck Constant (ℏ)
- **Value**: 1.054571817... × 10⁻³⁴ J·s
- **Relationship**: ℏ = h/(2π)
- **Source**: Derived from Planck constant
- **Acceptance Criteria**:
  - ✅ Derived via immutable rule (h/2π)
  - ✅ ℏ exact when h and π are exact
  - ✅ Matches NIST value
  - ✅ Dimensionally consistent
- **Verification**:
  - Calculate h/(2π) = ℏ ✅
  - Calculate 2πℏ = h ✅

### Bohr Radius (a₀)
- **Value**: 5.29177210903 × 10⁻¹¹ m
- **Relationship**: a₀ = ℏ²/(m_e · k₀ · e²)
- **Source**: Derived from fundamental constants
- **Acceptance Criteria**:
  - ✅ Derived from verified fundamentals
  - ✅ Matches Quantum Mechanics prediction
  - ✅ ≈ 0.529 Angstrom
  - ✅ Dimensionally correct (meters)
- **Verification**:
  - Calculate from components: verify match
  - Cross-check against NIST Atomic Spectra Database

### Rydberg Constant (R_∞)
- **Value**: 1.0973731568160 × 10⁷ m⁻¹
- **Relationship**: R_∞ = m_e · c · α² / (2h)
- **Source**: Derived from fundamental constants
- **Acceptance Criteria**:
  - ✅ Atomic Spectra Database certified
  - ✅ Derived calculation matches
  - ✅ Units: m⁻¹
  - ✅ Accounts for infinite nuclear mass
- **Verification**:
  - Hydrogen spectrum predictions
  - Cross-check against experimental spectroscopy

### Coulomb Constant (k₀)
- **Value**: 8.9875517923 × 10⁹ N·m²/C²
- **Relationship**: k₀ = 1/(4πε₀)
- **Source**: Derived from vacuum permittivity
- **Acceptance Criteria**:
  - ✅ Relationship k₀ = 1/(4πε₀) verified
  - ✅ Matches electrostatics predictions
  - ✅ Consistent with Coulomb's law
- **Verification**:
  - Calculate 4πε₀ · k₀ = 1 ✅
  - Electrostatics simulations agreement

---

## 4. PARTICLE MASSES (Measured, Verified)

### Electron Mass (m_e)
- **Value**: 9.1093835655 × 10⁻³¹ kg
- **Source**: CODATA 2023
- **Acceptance Criteria**:
  - ✅ Multiple independent measurements agree
  - ✅ Positive
  - ✅ Reasonable magnitude (10⁻³¹ range)
  - ✅ Uncertainty documented (< 10⁻⁶)
  - ✅ Used in atomic physics calculations
- **Verification**:
  - Atomic spectroscopy predictions
  - Mass spectroscopy measurements
  - Cross-lab consensus

### Proton Mass (m_p)
- **Value**: 1.67262189821 × 10⁻²⁷ kg
- **Source**: CODATA 2023
- **Acceptance Criteria**:
  - ✅ Multiple measurements agree
  - ✅ Positive, larger than electron mass
  - ✅ Consistency: m_p/m_e ≈ 1836.15
  - ✅ Uncertainty documented
- **Verification**:
  - Hydrogen atom predictions
  - Nuclear magnetic resonance
  - Mass spectroscopy consensus

### Neutron Mass (m_n)
- **Value**: 1.67492749804 × 10⁻²⁷ kg
- **Source**: CODATA 2023
- **Acceptance Criteria**:
  - ✅ Multiple measurements agree
  - ✅ Positive, similar to proton
  - ✅ m_n > m_p (by ~1.3 m_e)
  - ✅ Consistency in nuclear calculations
- **Verification**:
  - Beta decay energy calculations
  - Nuclear mass predictions
  - Cross-lab measurements

---

## 5. ENERGY CONSTANTS

### Hartree Energy (E_h)
- **Value**: 4.3597447222071 × 10⁻¹⁸ J = 27.211386041989 eV
- **Relationship**: E_h = e²/(4πε₀ · a₀)
- **Source**: Derived from fundamental constants
- **Acceptance Criteria**:
  - ✅ Derived from verified fundamentals
  - ✅ Atomic unit of energy
  - ✅ ≈ 27.2 eV (Rydberg × 2)
  - ✅ Used in quantum chemistry
- **Verification**:
  - Calculate from e, ε₀, a₀: verify match
  - Compare with computational chemistry packages

### Rydberg Energy (R_y)
- **Value**: 2.1798723611036 × 10⁻¹⁸ J = 13.605693020994 eV
- **Relationship**: R_y = E_h / 2
- **Source**: Derived from Hartree energy
- **Acceptance Criteria**:
  - ✅ Half of Hartree energy
  - ✅ Ground state energy of hydrogen
  - ✅ ≈ 13.6 eV
  - ✅ Ionization energy of hydrogen
- **Verification**:
  - Hydrogen ionization: 13.6 eV ✅
  - Balmer series calculations

---

## 6. ELECTROMAGNETIC CONSTANTS

### Vacuum Permittivity (ε₀)
- **Value**: 8.8541878128 × 10⁻¹² F/m
- **Relationship**: k₀ = 1/(4πε₀)
- **Acceptance Criteria**:
  - ✅ Derived from Coulomb constant
  - ✅ Positivity constraint
  - ✅ SI units (Farad/meter)
  - ✅ Consistency in electromagnetism

### Vacuum Permeability (μ₀)
- **Value**: 1.25663706215 × 10⁻⁶ H/m
- **Relationship**: c = 1/√(μ₀ε₀)
- **Acceptance Criteria**:
  - ✅ Relationship with speed of light
  - ✅ SI units (Henry/meter)
  - ✅ Consistency with Maxwell equations

---

## 7. CRYPTOGRAPHIC VERIFICATION

### Hash Requirements
- **Algorithm**: SHA-256
- **Input**: Constant value + uncertainty + unit
- **Output**: 32-byte (256-bit) hash
- **Determinism**: Same input → same hash on all platforms
- **Acceptance Criteria**:
  - ✅ Hash must be reproducible
  - ✅ Hash must match published value
  - ✅ Any change detected immediately

### Table Hash
- **Scope**: All constants together
- **Algorithm**: SHA-256 of sorted constant hashes
- **Update Rule**: Recalculate when ANY constant changes
- **Timestamp**: ISO-8601 format (UTC)

---

## 8. DIMENSIONAL ANALYSIS

All constants must pass dimensional verification:

| Constant | Type | Dimension | Status |
|----------|------|-----------|--------|
| c | Fundamental | L·T⁻¹ | ✅ |
| h | Fundamental | M·L²·T⁻¹ | ✅ |
| e | Fundamental | A·T | ✅ |
| k_B | Fundamental | M·L²·T⁻²·Θ⁻¹ | ✅ |
| N_A | Fundamental | Dimensionless (N) | ✅ |
| α | Derived | Dimensionless | ✅ |
| m_e | Measured | M | ✅ |
| G | Measured | L³·M⁻¹·T⁻² | ✅ |

---

## 9. TRANSFORMATION RULES (Dynamical Axioms)

These are the ONLY ways constants can change:

### Rule 1: New CODATA Release
```
IF CODATA releases (every 4 years)
   AND value certified by NIST
   AND uncertainty ≤ current value
THEN
   Accept new value
   Recalculate derived constants
   Update hash and timestamp
   Keep immutable transformation rule
```

### Rule 2: Fundamental vs. Derived
```
IF fundamental constant updated
THEN
   Automatically recalculate all derived constants
   Verify all relationships still hold
   Update timestamps
   Update hashes
ELSE
   Reject update
```

### Rule 3: No Arbitrary Changes
```
Constants can ONLY change via:
  - CODATA release
  - Peer-reviewed new measurement
  - Not via:
    - Computational preference
    - Convenience rounding
    - Arbitrary "optimization"
```

---

## 10. PUBLICATION ACCEPTANCE

Before publishing a new physical constants version:

- [ ] All 27 unit tests pass
- [ ] Cross-platform reproducibility verified
- [ ] Hash values calculated and confirmed
- [ ] Acceptance criteria checklist completed
- [ ] No arbitrary modifications made
- [ ] Immutable transformation rules documented
- [ ] CODATA source certified
- [ ] Uncertainty ranges documented
- [ ] Relationships verified (h/2π, 1/(4πε₀), etc.)
- [ ] Timestamp and version recorded

**Only when ALL checkboxes are true may the capsule be published.**

---

## 11. ACCEPTANCE WORKFLOW

```
Raw CODATA 2023 Data
    ↓
[Load into WAD18 Format]
    ↓
[Run 27 Unit Tests]
    ↓
Tests Pass? → NO → Fix and retry
    ↓ YES
[Verify Relationships]
    ↓
Relationships Valid? → NO → Stop, analyze
    ↓ YES
[Calculate Hashes]
    ↓
[Cross-Platform Test]
    ↓
[Accepted for Publication]
    ↓
ZIP Capsule with:
  - C code (tested, verified)
  - JSON data (WAD18 values)
  - Documentation (criteria, usage)
  - License (MIT)
  - Timestamp (ISO-8601)
```

---

## 12. REJECT CRITERIA

Constants are **REJECTED** if:

- ❌ Unit tests fail (>0 failures)
- ❌ Relationships don't verify (e.g., ℏ ≠ h/2π)
- ❌ Cross-platform disagreement (different platform, different result)
- ❌ Hash mismatch (calculated ≠ expected)
- ❌ Source not NIST/CODATA certified
- ❌ Uncertainty exceeds threshold
- ❌ Dimensionally inconsistent
- ❌ Inconsistent with prior released versions (without explanation)

---

## 13. VERSIONING

**Format:** MAJOR.MINOR.PATCH

- **MAJOR**: Fundamental constants change (rare)
- **MINOR**: New constants added, derived values updated
- **PATCH**: Documentation, bug fixes, hash recalculation

**Current Version:** 1.0.0 (2026-09-21)

**Next Expected:** 1.1.0 (2030, CODATA 2026 release)

---

## ⚠️ CRITICAL PRINCIPLE

**These criteria are IMMUTABLE and PRE-DECLARED.**

They exist BEFORE evaluation, preventing post-hoc rationalization.

**This is how you prevent the reproducibility crisis.**

**Declare axioms. Test against them. Never modify the axioms to make tests pass.**

---

**Acceptance Criteria Version:** 1.0.0  
**Last Updated:** 2026-09-21  
**Authority:** CODATA Task Group, NIST  
**Status:** IMMUTABLE (Canonized as of this date)
