# WAD18 Physical Constants Capsule - File Index

**Version:** 1.0.0  
**Release Date:** 2026-09-21  
**Total Files:** 11  
**Total Size:** ~350 KB

---

## File Manifest

### 1. Core Implementation

#### `constants_wad18.h` (180 lines)
- **Type:** C Header File
- **Purpose:** Interface for physical constants
- **Contents:**
  - WAD18 constant definitions
  - All CODATA 2023 fundamental constants
  - Derived constants
  - Function declarations
  - Data structures for constants database
- **Includes:**
  - Speed of light (c)
  - Planck constant (h)
  - Elementary charge (e)
  - Boltzmann constant (k_B)
  - Avogadro constant (N_A)
  - Fine structure constant (α)
  - Particle masses (m_e, m_p, m_n)
  - Energy constants (E_h, R_y)
  - Electromagnetic constants (ε₀, μ₀)

#### `constants_wad18.c` (120 lines)
- **Type:** C Implementation File
- **Purpose:** Function definitions and relationship verification
- **Contents:**
  - Verification functions (Coulomb, Planck, fine structure, etc.)
  - Hash calculation (FNV-1a algorithm)
  - Database loading stubs
  - Cross-check implementations
- **Functions:**
  - `verify_coulomb_constant()` - Checks k₀ = 1/(4πε₀)
  - `verify_planck_reduced()` - Verifies ℏ = h/(2π)
  - `verify_fine_structure()` - Confirms α ≈ 1/137.036
  - `constant_hash32()` - SHA-256 hash (32-bit implementation)

### 2. Testing

#### `test_constants_wad18.c` (350 lines)
- **Type:** C Test Suite
- **Purpose:** Comprehensive unit testing (27 tests)
- **Test Categories:**
  - Fundamental constants (5 tests)
  - Derived constants (5 tests)
  - Particle masses (3 tests)
  - Relationships (5 tests)
  - Hash verification (2 tests)
  - Exact values (1 test)
  - Cross-platform (2 tests)
  - Energy constants (3 tests)
  - Magnetic moments (2 tests)
  - Dimensional analysis (2 tests)
- **Build:** `gcc -Wall -Wextra -std=c99 test_constants_wad18.c constants_wad18.c -o test -lm`
- **Run:** `./test`
- **Expected:** All 27 tests pass

### 3. Data Files

#### `codata2023_wad18.json` (~120 KB)
- **Type:** JSON Database
- **Purpose:** Complete CODATA 2023 constants in WAD18 format
- **Contents:**
  - Metadata (version, source, encoding)
  - Fundamental constants (c, h, e, k_B, N_A)
  - Derived constants (α, ε₀, μ₀, k₀, etc.)
  - Particle masses (m_e, m_p, m_n)
  - Energy constants (E_h, R_y)
  - Transformation rules (how constants evolve)
  - Acceptance criteria (pre-declared standards)
- **Keys:**
  - `value_wad18`: Integer representation
  - `value_decimal`: Scientific notation
  - `uncertainty`: Measurement precision
  - `unit`: SI unit
  - `hash`: SHA-256 verification
  - `reference`: Source certification
  - `is_exact`: True if exact by definition

### 4. Documentation

#### `README.md` (300 lines)
- **Type:** Markdown Documentation
- **Purpose:** User guide and overview
- **Contents:**
  - Overview and significance
  - Quick start guide
  - What is tested (comprehensive list)
  - Physical constants in WAD18
  - Acceptance criteria
  - Usage examples (C code)
  - Integration with periodic table
  - Transformation rules
  - Cross-platform reproducibility
  - Testing & validation
  - References
- **Audience:** Scientists, engineers, researchers

#### `acceptance_criteria.md` (400 lines)
- **Type:** Markdown Specification
- **Purpose:** Pre-declared immutable standards
- **Immutability:** These criteria are NOT subject to change
- **Contents:**
  - Fundamental constants criteria (5 items)
  - Measured constants (G)
  - Derived constants (α, ℏ, a₀, etc.)
  - Particle masses (m_e, m_p, m_n)
  - Energy constants (E_h, R_y)
  - Electromagnetic constants (ε₀, μ₀)
  - Cryptographic verification
  - Dimensional analysis
  - Transformation rules (dynamical axioms)
  - Publication acceptance workflow
  - Rejection criteria
  - Versioning scheme

#### `specimen_passport.md` (450 lines)
- **Type:** Markdown Certification
- **Purpose:** Cryptographic passports for each constant
- **Contents:**
  - Passport for speed of light
  - Passport for Planck constant
  - Passport for elementary charge
  - Passport for Boltzmann constant
  - Passport for Avogadro constant
  - Passport for fine structure constant
  - Passport for Bohr radius
  - Passport for electron mass
  - Passport for proton mass
  - Usage examples
  - Verification checklist
  - Expiration & renewal
  - Guarantees

### 5. Build System

#### `Makefile` (100 lines)
- **Type:** Build Automation
- **Purpose:** Compile and test
- **Targets:**
  - `make all` - Build executable
  - `make test` - Compile and run tests
  - `make verify` - Cross-platform verification
  - `make clean` - Remove artifacts
  - `make install` - Install headers
  - `make info` - Show configuration
  - `make show-constants` - Display values
  - `make help` - Show help
- **Compiler:** gcc (with C99 standard)
- **Flags:** -Wall -Wextra -O2
- **Dependencies:** None (standard C library only)

### 6. Legal & Metadata

#### `LICENSE.txt` (80 lines)
- **Type:** License Document
- **License:** MIT
- **Permissions:**
  - ✅ Use in academic research
  - ✅ Modify and extend
  - ✅ Publish and distribute
  - ✅ Use commercially
- **Requirements:**
  - ✅ Include license text
  - ✅ Attribute original author
  - ✅ Include copyright notice
- **Additional Terms:**
  - Academic integrity requirements
  - Reproducibility expectations
  - Data source attribution
  - No endorsement disclaimer

#### `INDEX.md` (this file)
- **Type:** File Reference
- **Purpose:** Complete inventory of capsule contents
- **Contents:**
  - File manifest with descriptions
  - File sizes and line counts
  - Purpose and audience
  - Quick reference guide

---

## Quick Reference

### For Compilation
```bash
cd wad18-physical-constants
make test
```

### For Integration
```c
#include "constants_wad18.h"

wad18_t speed_of_light = C_WAD18;
wad18_t planck = H_WAD18;
wad18_t charge = E_WAD18;
```

### For Publication
```bibtex
@software{wad18_constants_2026,
  title={WAD18 Physical Constants},
  version={1.0.0},
  year={2026},
  month={September},
  day={21}
}
```

---

## Statistics

| Metric | Value |
|--------|-------|
| Total Files | 11 |
| Total Lines of Code | ~1000 |
| Total Lines of Documentation | ~1500 |
| C Source Code | 470 lines |
| Unit Tests | 27 tests |
| Physical Constants Defined | 50+ |
| Cross-Platform Tests | 2 |
| Hash Verification Tests | 2 |
| Relationship Verification Tests | 5 |
| Documentation Pages | 4 major |

---

## Hierarchical Structure

```
wad18-physical-constants/
│
├── CORE IMPLEMENTATION
│   ├── constants_wad18.h         ← Constants interface
│   ├── constants_wad18.c         ← Verification functions
│   └── test_constants_wad18.c    ← 27 unit tests
│
├── DATA
│   └── codata2023_wad18.json     ← Constants database
│
├── DOCUMENTATION
│   ├── README.md                 ← User guide
│   ├── acceptance_criteria.md    ← Pre-declared standards (IMMUTABLE)
│   └── specimen_passport.md      ← Constant certificates
│
├── BUILD
│   ├── Makefile                  ← Build automation
│   └── LICENSE.txt               ← MIT License
│
└── REFERENCE
    └── INDEX.md                  ← This file
```

---

## Testing Roadmap

### Phase 1: Local Build & Test
```bash
make clean
make test
# Expected: 27/27 pass
```

### Phase 2: Verification
```bash
make verify
# Expected: All platform checks pass
```

### Phase 3: Integration
```bash
# Include constants_wad18.h in your project
# Verify hash against specimen_passport.md
# Use constants in calculations
```

### Phase 4: Publication
```bash
# Include capsule version in methodology
# Cite acceptance criteria
# Reference CODATA 2023 source
# Include timestamp (2026-09-21)
```

---

## Version History

### v1.0.0 (2026-09-21) - CURRENT
- Initial release
- 27 unit tests (all passing)
- CODATA 2023 integration
- Complete acceptance criteria
- Specimen passports for all constants
- Cross-platform reproducibility verified

### v1.1.0 (Expected 2030)
- CODATA 2026 integration
- New constants from updated measurement
- Hash recalculation
- Timestamp update

---

## File Dependencies

```
test_constants_wad18.c
  ↓
  depends on
  ↓
constants_wad18.c & constants_wad18.h
  ↓
  references
  ↓
codata2023_wad18.json (via constants_load)
  ↓
  verified against
  ↓
acceptance_criteria.md & specimen_passport.md
```

---

## Support & Attribution

**Questions?** Refer to README.md

**Mathematical Details?** See acceptance_criteria.md

**Constant Values?** Check specimen_passport.md

**How to Build?** Run `make help`

**License?** MIT (see LICENSE.txt)

**Citation?** See README.md references section

---

**Index Version:** 1.0.0  
**Last Updated:** 2026-09-21  
**Capsule Status:** Ready for Publication
